Selected = nil
SelectedIsFriendly = nil

Gfx = { RTT = { Player = nil, Enemy = nil } }

local PSS = 6 -- Puppet selection billboard scale
local OriginalDim = { Width = 1, Height = 1 }
local PuppetDim = {
  Width = OriginalDim.Width * PSS,
  Height = OriginalDim.Height * PSS
}

local rotateBillboard = function(dt)
  BBNode:yaw(Ogre.Degree(0.1 * dt))
end
local doNothing = function(dt) end
local updater = doNothing

-- RTT Portraits
Gfx.ShowPortrait = function(rnd, is_friendly)

  -- Puppet sizes are much bigger than units, so we position the camera accordingly on Y/Z axes
  local is_puppet = rnd:getEntity() == SelfPuppet or rnd:getEntity() == EnemyPuppet
  local zpad, ypad = nil
  if is_puppet then
    ypad = function(pos, size) return pos.y + size.y * 0.75 end
    zpad = function(pos, size, sign) return pos.z + 10 * sign end
  else
    ypad = function(pos, size) return pos.y + size.y * 0.5 end
    zpad = function(pos, size, sign) return pos.z + ( (size.z + 5) * sign ) end
  end

  -- we will use both the node's position and the entity's AABB to calculate
  -- the camera's position
  local pos = rnd:getSceneNode():getPosition()
  local size = rnd:getSceneObject():getWorldBoundingBox(true):getSize()
  -- DEBUG
  do
    --print("\tSelected Size: " .. size.x .. "," .. size.y .. "," .. size.z)
    --print("\tSelected Position: " .. pos.x .. "," .. pos.y .. "," .. pos.z)
  end

  -- should we position the camera in the negative or positive Z?
  local _sign = 1; if pos.z > 0 then _sign = -1 end

  -- finally, do position the camera
  local selector = nil; if is_friendly then selector = "Player" else selector = "Enemy" end
  RTT[selector].Camera:setPosition(Ogre.Vector3(pos.x, ypad(pos,size), zpad(pos,size,_sign)))
  RTT[selector].Camera:lookAt(pos.x, ypad(pos,size), pos.z  + _sign)
end

Gfx.ShowSelection = function(rnd, is_friendly)
  Gfx.HideSelection()

  --~ entity:getSceneNode():attachObject(BBNode)
  rnd:getSceneNode():addChild(BBNode)
  if (rnd:getEntity():getRank() == Pixy.PUPPET) then
    BBSet:setDefaultDimensions(PuppetDim.Width, PuppetDim.Height)
  else
    BBSet:setDefaultDimensions(
      OriginalDim.Width,
      OriginalDim.Height)
    --~ BBNode:setScale(entity:getSceneNode():getScale())
  end
  --~ BBNode:setPosition(entity:getSceneNode():getPosition())
  --~ BBNode:setScale(entity:getSceneNode():getScale())

  if is_friendly then
    BBSet:setMaterialName("Elementum/Billboards/EntitySelection")
  else
    BBSet:setMaterialName("Elementum/Billboards/EnemyEntitySelection")
  end

  updater = rotateBillboard
end

Gfx.HideSelection = function(rnd)
  if BBNode:getParentSceneNode() then
    BBNode:getParentSceneNode():removeChild(BBNode)
  end
  updater = doNothing -- stop rotating the billboard
end

Combat.Highlight = function(rnd)
  Selected = rnd

  -- is the entity owned by the player or the enemy?
  SelectedIsFriendly = Selected:getEntity():getOwner():getUID() == SelfPuppet:getUID()

  Gfx.ShowSelection(Selected, SelectedIsFriendly)
  Gfx.ShowPortrait(Selected, SelectedIsFriendly)
  UI.Highlight(Selected:getEntity(), SelectedIsFriendly)
  Buffs.Show(Selected, SelectedIsFriendly)
end

Combat.Dehighlight = function()
  --~ Pixy.Log("Deselecting entity")
  if not Selected then return true end
  --if (Selected) then
    Gfx.HideSelection(Selected)
    Gfx.ShowPortrait(Selected:getEntity():getOwner():getRenderable(), SelectedIsFriendly)
    UI.Highlight(Selected:getEntity():getOwner(), SelectedIsFriendly)
    if SelectedIsFriendly then
      Buffs.Show(SelfPuppet:getRenderable(), true)
    else
      Buffs.Show(EnemyPuppet:getRenderable(), false)
    end

  --end

  Selected = nil
  SelectedIsFriendly = nil
end

Combat.onEntitySelected = function(inEvt)
  local rnd = inEvt.Any
  rnd = tolua.cast(rnd, "Pixy::Renderable")

  Combat.Highlight(rnd)
  return true
end

Combat.onEntityDeselected = function()
  Combat.Dehighlight()
  return true
end

updateCombat = function(dt)
  updater(dt)
end

Pixy.Log("I'm REGISTERED")
