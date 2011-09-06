Selected = nil
local HSS = 6 -- Hero Selection Scale
local OriginalDim = { Width = 1, Height = 1 }
local HeroDim = {
  Width = OriginalDim.Width * HSS,
  Height = OriginalDim.Height * HSS
}

Pixy.Combat.onEntitySelected = function(inEvt)
  local entity = inEvt.Any
  entity = tolua.cast(entity, "Pixy::Renderable")
  print("Entity selected, UID: " .. entity:getEntity():getUID())

  if (Selected) then
    --~ Selected:getSceneNode():detachObject(BBSet)
    Selected:getSceneNode():removeChild(BBNode)
  end

  --~ entity:getSceneNode():attachObject(BBNode)
  entity:getSceneNode():addChild(BBNode)
  if (entity:getEntity():getRank() == Pixy.PUPPET) then
    BBSet:setDefaultDimensions(HeroDim.Width, HeroDim.Height)
  else
    BBSet:setDefaultDimensions(OriginalDim.Width, OriginalDim.Height)
  end
  --~ BBNode:setPosition(entity:getSceneNode():getPosition())
  --~ BBNode:setScale(entity:getSceneNode():getScale())

  if (entity:getEntity():getOwner():getUID() == SelfPuppet:getUID()) then
    BBSet:setMaterialName("Elementum/Billboards/EntitySelection")
  else
    BBSet:setMaterialName("Elementum/Billboards/EnemyEntitySelection")
  end
  Selected = entity
end

Pixy.Combat.onEntityDeselected = function()
  Pixy.Log("Deselecting entity")
  if (Selected) then
    Selected:getSceneNode():removeChild(BBNode)
  end
  Selected = nil
end

updateCombat = function(dt)
  if (Selected) then
    --Selected:getSceneNode():yaw(Ogre.Degree(1))
    BBNode:yaw(Ogre.Degree(0.1 * dt))
  end
end
