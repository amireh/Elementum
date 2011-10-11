Animatable = {}

function Animatable:new(cegui_window, o)
  local o = o or {}

  setmetatable(o, {__index = self})
  self.__index = self

  o.__Window = cegui_window
  o.__Instances = {}

  return o
end

function Animatable:destroy()
  for anim in list_iter(self.__Instances) do
    self:__stopAnime(anim)
    CEAnimMgr:destroyAnimationInstance(in_anim)
  end

  self.__Instances = {}
  self.__Window = nil
  self = nil

  return nil
end

-- loads the instance of the given animation and returns it
-- note: ALL animations must be registered before attempting to start or stop them!
function Animatable:registerAnime(anim_name)
  local instance = CEAnimMgr:instantiateAnimation(anim_name)
  instance:setTargetWindow(self.__Window)
  table.insert(self.__Instances, instance)

  return instance
end

function Animatable:isAnimeRegistered(anim_name)
  return true and find_by_condition(self.__Instances, function(anim)
    if anim:getDefinition():getName() == anim_name then return true end
  end)
end

-- plays the animation with the given name, and resets its position unless indicated
-- otherwise by the dont_reset flag
function Animatable:startAnime(anim_name, dont_reset)
  local instance = self:__getAnime(anim_name)

  instance:setTargetWindow(self.__Window)
  if not dont_reset then instance:setPosition(0) end
  instance:start()

  return self
end

-- stops the instance of the given animation
function Animatable:stopAnime(anim_name)
  local instance = self:__getAnime(anim_name)
  self:__stopAnime(instance)

  return self
end

-- stops all registered animation instances
function Animatable:stopAllAnimes()
  for anim in list_iter(self.__Instances) do
    self:__stopAnime(anim)
  end

  return self
end

function Animatable:resetAnime(anim_name)
  self:__getAnime(anim_name):setPosition(0)

  return self
end

-- returns true if any animation instance for this Animatable is currently running
function Animatable:isAnimating()
  for anim in list_iter(self.__Instances) do
    if anim:isRunning() then return true end
  end
  return false
end

function Animatable:isAnimeRunning(anim_name)
  return self:isAnimeRegistered(anim_name) and self:__getAnime(anim_name):isRunning()
end

-- internal helper for getting an animation instance based on a name
function Animatable:__getAnime(anim_name)
  for anim in list_iter(self.__Instances) do
    if anim:getDefinition():getName() == anim_name then return anim end
  end

  return error("attempting to retrieve a non-existing animation instance! name: " .. anim_name)
end

-- internal helper for stopping an _instance_ of an animation, should not be
-- used directly, use Animatable:stopAnime(name) instead
function Animatable:__stopAnime(instance)
  if instance:isRunning() then instance:stop() end
  return self
end
