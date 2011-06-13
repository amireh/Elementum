package.path = package.path .. ";../resources/scripts/shared/units/?.lua;"

Pixy.Units = { Earth = {}, Air = {}, Fire = {}, Water = {} }
require("earth/units")
