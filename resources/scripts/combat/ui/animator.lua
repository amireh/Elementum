UI.Animations = {}
UI.Win2Animations = {}

Animator = {}
Animator.cleanup = function()
  local count = 0
  while #UI.Win2Animations > 0 do
    UI.ClearAnimations(UI.Win2Animations[1])
    count = count + 1
  end
  print("\tUI: destroyed " .. count .. " animation instances!")
  UI.Win2Animations = {}
  UI.Animations = {}
end

UI.Animate = function(win, anim)

  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  instance:setTargetWindow(win)
  instance:start()
  --[[
  if not UI.Animations[win] then UI.Animations[win] = { } end
  table.insert(UI.Animations[win], instance)

  if not find_by_value(UI.Win2Animations, win) then
    table.insert(UI.Win2Animations, win)
  end
  ]]

  return instance
  --end
end
UI.RemoveAnimation = function(win, in_anim)
  if true then return true end
  assert(UI.Animations[win])

  local idx = 1
  for anim in list_iter(UI.Animations[win]) do
    if anim == in_anim then
      table.remove(UI.Animations[win], idx)
    end
    idx = idx + 1
  end

  in_anim:stop()
  in_anim:setTargetWindow(nil)
  CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(in_anim)

  if #UI.Animations[win] == 0 then
    remove_by_value(UI.Win2Animations, win)
  end

end
UI.ClearAnimations = function(win)
  if true then return true end

  assert(UI.Animations[win])
  local count = 0
  for anim in list_iter(UI.Animations[win]) do
    anim:stop()
    anim:setTargetWindow(nil)
    CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(anim)
    count = count + 1
  end
  print("\t--destroyed " .. count .. " animation instances for window: " .. win:getName())
  UI.Animations[win] = {}
  remove_by_value(UI.Win2Animations, win)
end
UI.isAnimating = function(win, anim_name)
  if true then return true end
  for anim in list_iter(UI.Animations[win]) do
    if anim:getDefinition():getName() == anim_name then
      return anim:isRunning()
    end
  end

  return false
end
UI.StopAnimating = function(anim)
  --~ local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  --~ instance:stop()
end
