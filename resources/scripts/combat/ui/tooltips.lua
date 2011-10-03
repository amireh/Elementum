UI.ShowTooltip = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  local lbl = UI.Labels["Tooltip"]

  UI.Labels["Tooltip"]:show()
  UI.Labels["Tooltip"]:setText(win:getUserString("Tooltip"))

  -- adjust height and position of the tooltip
  height = tonumber(lbl:getProperty("VertExtent"))
  lbl:setHeight(CEGUI.UDim(0, height + 20))
  lbl:setPosition(CEGUI.UVector2(lbl:getPosition().x, CEGUI.UDim(0.85, -height)))

  --print("Tooltip size = " .. lbl:getProperty("HorzExtent") .. "x" .. lbl:getProperty("VertExtent") .. "height : " .. height)
end
UI.HideTooltip = function(e)
  UI.Labels["Tooltip"]:hide()
  UI.Labels["Tooltip"]:setText("")
end
