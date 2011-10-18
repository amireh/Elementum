UI.ShowTooltip = function(e)

  local win = CEGUI.toWindowEventArgs(e).window

  local item = HandItem.FindByWindow(win)
  if item then
    item:Validate()
  else
    UI.setValidationMsg("")
  end

  local lbl = UI.Labels["Tooltip"]
  local validation_msg = ""
  if ValidationMsg:len() > 0 then
    print("assigning validation msg: " .. ValidationMsg)
    validation_msg = "\n \n[colour='FFFF0000']" .. ValidationMsg
  end

  UI.Labels["Tooltip"]:show()
  UI.Labels["Tooltip"]:setText(win:getUserString("Tooltip") .. validation_msg)

  UI.Animate(UI.Labels["Tooltip"], "ShowTooltip")

  -- adjust height and position of the tooltip
  height = tonumber(lbl:getProperty("VertExtent"))
  lbl:setHeight(CEGUI.UDim(0, height + 20))
  lbl:setPosition(CEGUI.UVector2(lbl:getPosition().x, CEGUI.UDim(0.9, -lbl:getHeight().offset)))

  --~ UI.Animes.HideTooltip:stop()
  --~ if not UI.Animes.ShowTooltip:isRunning() then
    --~ UI.Animes.ShowTooltip:setTargetWindow(lbl)
    --~ UI.Animes.ShowTooltip:start()
  --~ end
  --~ UI.StopAnimating("ShowTooltip")
  --~ if not UI.isAnimating("ShowTooltip") then
    --~ UI.Animate(lbl, "ShowTooltip")
    --~ --UI.Animes.ShowTooltip:setTargetWindow(lbl)
    --~ --UI.Animes.ShowTooltip:start()
  --~ end

  --print("Tooltip size = " .. lbl:getProperty("HorzExtent") .. "x" .. lbl:getProperty("VertExtent") .. "height : " .. height)
end
UI.HideTooltip = function(e)
  --~ UI.Animate(UI.Labels["Tooltip"], "HideTooltip")
  --~ if not show_anim:isRunning() then
    --~ UI.Animes.HideTooltip:setTargetWindow(UI.Labels["Tooltip"])
    --~ UI.Animes.HideTooltip:start()
  --~ end

  UI.Labels["Tooltip"]:hide()
  --~ UI.Labels["Tooltip"]:setText("")
end
