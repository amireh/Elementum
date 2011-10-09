local Handlers = {}
Puppets = {}
-- type: incoming event handler
-- job: stores the names of the player's puppet and his opponent
-- and tells the graphics engine about them
Puppets.onAddPuppet = function(inPuppet)
  table.insert(Combat.Puppets, inPuppet)
  Pixy.Log("Registering a new Puppet to the instance, named: " .. inPuppet:getName())
end

Puppets.onAssignSelfPuppet = function(inPuppet)
  SelfPuppet = inPuppet
  Pixy.Log("I'm playing with a puppet named " .. SelfPuppet:getName())
end
Puppets.onAssignEnemyPuppet = function(inPuppet)
  EnemyPuppet = inPuppet
end
Puppets.onAssignActivePuppet = function(puppet)
  Waiting = Active
  Active = puppet
  Pixy.Log("Current turn is for puppet: " .. Active:getName())
end

Puppets.onUpdatePuppet = function(puppet)
  UI.UpdatePuppet(puppet)
end

Puppets.onCreatePuppet = function(puppet)
  Pixy.Log("Creating puppet")
  Handlers[puppet:getRace()](puppet)
  UI.UpdatePuppet(puppet)
  Pixy.Log("Created!")
end

Puppets.cleanup = function()
  Combat.Puppets = {}
  EnemyPuppet = nil
  SelfPuppet = nil
  Waiting = nil
  Active = nil
end

function subscribe_puppet(inRace, inMethod)
	Pixy.Log("subscribing to " .. inRace .. " puppets")
	Handlers[inRace] = inMethod
end

path_to_handlers = ScriptPrefix .. "/combat/puppet_handlers"
races = {"earth", "air", "fire", "water"}
package.path = path_to_handlers .. "/?.lua;" .. package.path
for race in list_iter(races) do
  require(race .. "_puppets")
end
