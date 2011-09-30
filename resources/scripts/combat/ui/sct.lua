SCT = {}

local last_msg_idx = 0 -- used to avoid name collisions with messages
local Colors = {
  Green = "tl:FF6bcf00 tr:FF6bcf00 bl:FF6bcf00 br:FF6bcf00",
  Red = "tl:FFFF0000 tr:FF8f0000 bl:FF8f0000 br:FF8f1e00"
}

SCT.ShowScrollingMessage = function(txt, good, rnd)

  -- determine the position: if no Renderable is given, the message spawns
  -- from the screen centre, otherwise from atop of the model
  local pos = nil
  if rnd == nil then
    pos = { x = "0.5", y = "0.5" }
  else
    pos = GfxEngine:getScreenCoords(rnd:getSceneObject())
  end

  local win = CEWindowMgr:createWindow("TaharezLook/StaticText", "SCT" .. last_msg_idx)
  UI.Root:addChildWindow(win)
  win:setProperty("UnifiedXPosition", "{" .. pos.x .. ",0}")
  win:setProperty("UnifiedYPosition", "{" .. pos.y .. ",0}")
  win:setProperty("UnifiedHeight", "{0,50}")
  win:setProperty("Font", "Scrolling_Text")

  -- color the message
  local color = nil
  if good then color = Colors.Green else color = Colors.Red end
  win:setProperty("TextColours", color)

  -- set the text
  win:setProperty("Text", txt)

  --~ win:setProperty("UnifiedWidth", "{1,0}")
  --~ win:setProperty("HorzFormatting", "WordWrapLeftAligned")
  --~ win:setProperty("VertFormatting", "TopAligned")
  --~ win:setProperty("VerticalAlignment", "Centre")
  --~ win:setProperty("HorizontalAlignment", "Centre")

  -- SCT messages scroll upwards either to the left or to the right
  last_msg_idx = last_msg_idx + 1
  local anim = nil
  if (last_msg_idx % 2 == 0) then anim = "ScrollUpLeft" else anim = "ScrollUpRight" end
  UI.Animate(win, anim)

  -- destroy the message when it fades out
  win:subscribeEvent("AlphaChanged", UI.Helpers.DestroyAfterFade)
end

--~ Combat.onKeyReleased = function()
  --~ --ShowScrollingMessage("foobar")
  --~ if (Selected) then
    --~ local pos = GfxEngine:getScreenCoords(Selected:getSceneObject())
    --~ Pixy.Log(pos.x)
    --~ ShowScrollingMessage("foobar this is a very long scrolling combat message", true, Selected)
  --~ end
--~ end
