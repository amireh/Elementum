package.path = "./?.lua;../resources/scripts/client/?.lua;../resources/scripts/shared/?.lua"

require("pixy")

Pixy.registerGlobals()

require("combat/bootstrap")
require("combat/debug")
require("combat/ui")
require("combat/turns")
require("combat/spells")
require("combat/bindings")

-- and attach UI layout!
Pixy.UI.attach(Pixy.UI.Combat.Config.LayoutPath)
Pixy.UI.Combat.registerGlobals()
