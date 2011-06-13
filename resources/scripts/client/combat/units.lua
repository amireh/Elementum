Pixy.Combat.createUnit = function(inEvt)
  tolua.cast(inEvt, "Pixy::EntityEvent")
  Pixy.Log("Creating a unit named " .. inEvt:getProperty("UnitName") .. "#" .. inEvt:getObjectId() .. " belonging to " .. inEvt:getOwner())

	local lUnit =
	UnitFactory:createEntity(
			inEvt:getObjectId(),
			inEvt:getProperty("UnitName"),
			inEvt:getOwner(),
			Puppets[inEvt:getOwner()]:getRace()
	)
	lUnit:setMesh("sinbad.mesh")
	Puppets[lUnit:getOwner()]:attachUnit(lUnit)

	GfxEngine:attachToScene(lUnit:getRenderable())

  return true
end
