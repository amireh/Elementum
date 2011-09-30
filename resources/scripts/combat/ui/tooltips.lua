UI.ShowTooltip = function(e)
  local win = CEGUI.toWindowEventArgs(e).window

  UI.Containers["Tooltip"]:show()
  UI.Labels["Tooltip"]:setText(win:getUserString("Tooltip"))
end
UI.HideTooltip = function(e)
  UI.Containers["Tooltip"]:hide()
  UI.Labels["Tooltip"]:setText("")
end
