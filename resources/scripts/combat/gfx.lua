Selected = nil
local HSS = 6 -- Hero Selection Scale
local OriginalDim = { Width = 1, Height = 1 }
local HeroDim = {
  Width = OriginalDim.Width * HSS,
  Height = OriginalDim.Height * HSS
}

local rotateBillboard = function(dt)
  BBNode:yaw(Ogre.Degree(0.1 * dt))
end
local doNothing = function(dt) end
local updater = doNothing

Combat.onEntitySelected = function(inEvt)
  local entity = inEvt.Any
  entity = tolua.cast(entity, "Pixy::Renderable")
  --~ print("Entity selected, UID: " .. entity:getEntity():getUID())

  if (Selected) then
    --~ Selected:getSceneNode():detachObject(BBSet)
    Selected:getSceneNode():removeChild(BBNode)
  end

  --~ entity:getSceneNode():attachObject(BBNode)
  entity:getSceneNode():addChild(BBNode)
  if (entity:getEntity():getRank() == Pixy.PUPPET) then
    BBSet:setDefaultDimensions(HeroDim.Width, HeroDim.Height)
  else
    BBSet:setDefaultDimensions(
      OriginalDim.Width * entity:getSceneNode():getScale().x,
      OriginalDim.Height * entity:getSceneNode():getScale().y)
    --~ BBNode:setScale(entity:getSceneNode():getScale())
  end
  --~ BBNode:setPosition(entity:getSceneNode():getPosition())
  --~ BBNode:setScale(entity:getSceneNode():getScale())

  if (entity:getEntity():getOwner():getUID() == SelfPuppet:getUID()) then
    BBSet:setMaterialName("Elementum/Billboards/EntitySelection")
  else
    BBSet:setMaterialName("Elementum/Billboards/EnemyEntitySelection")
  end

  Selected = entity
  updater = rotateBillboard
end

Combat.onEntityDeselected = function()
  --~ Pixy.Log("Deselecting entity")
  if (Selected) then
    Selected:getSceneNode():removeChild(BBNode)
  end

  Selected = nil
  updater = doNothing
end

updateCombat = function(dt)
  updater(dt)
end

Pixy.Log("I'm REGISTERED")
