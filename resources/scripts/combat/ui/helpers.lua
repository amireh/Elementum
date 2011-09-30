UI.Helpers = { }

UI.Helpers.DestroyAfterFade = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  if (win and tonumber(win:getProperty("Alpha")) <= 0) then
    CEWindowMgr:destroyWindow(win)
  end
end
