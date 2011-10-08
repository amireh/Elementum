Input = {}

local last_effect = 1
local _effects = {}
table.insert(_effects, "BoneHarvest")
table.insert(_effects, "BoneArmor")
table.insert(_effects, "LocustSwarm")
table.insert(_effects, "Aftermath")
table.insert(_effects, "Anger")
table.insert(_effects, "BloodForBlood")
table.insert(_effects, "BurnOut")
table.insert(_effects, "CrownOfDestruction")
table.insert(_effects, "DestructivePassion")
table.insert(_effects, "FireSummoning")
table.insert(_effects, "FlameShield")
table.insert(_effects, "Immolation")
table.insert(_effects, "Insanity")
table.insert(_effects, "RagingFury")
table.insert(_effects, "SmokeScreen")
table.insert(_effects, "SuddenCraven")
table.insert(_effects, "Redirect")
table.insert(_effects, "Negate")
table.insert(_effects, "Gloom")
table.insert(_effects, "GladeBlessing")
table.insert(_effects, "EarthSummoning")

local key_map = {
}

key_map[OIS.KC_NUMPAD0] = "BoneArmor"
key_map[OIS.KC_NUMPAD1] = "LocustSwarm"
key_map[OIS.KC_NUMPAD2] = "Aftermath"
key_map[OIS.KC_NUMPAD3] = "Anger"
key_map[OIS.KC_NUMPAD4] = "BloodForBlood"
key_map[OIS.KC_NUMPAD5] = "BurnOut"
key_map[OIS.KC_NUMPAD6] = "CrownOfDestruction"
key_map[OIS.KC_NUMPAD7] = "DestructivePassion"
key_map[OIS.KC_NUMPAD8] = "BoneHarvest"
key_map[OIS.KC_NUMPAD9] = "FlameShield"
key_map[OIS.KC_1] = "Immolation"
key_map[OIS.KC_2] = "Insanity"
key_map[OIS.KC_3] = "RagingFury"
key_map[OIS.KC_4] = "SmokeScreen"
key_map[OIS.KC_5] = "SuddenCraven"
key_map[OIS.KC_6] = "Redirect"
key_map[OIS.KC_7] = "Negate"
key_map[OIS.KC_8] = "Gloom"
key_map[OIS.KC_9] = "GladeBlessing"

Input.bindToKeyReleased = function(key, handler)
  if not Keybindings[key] then Keybindings[key] = {} end
  table.insert(Keybindings[key], handler)
end
Combat.onKeyReleased = function(e)
  if (Selected) then
    if key_map[e.key] then FxEngine:playEffect(key_map[e.key], Selected) end
  end

  if Keybindings[e.key] then
    for handler in list_iter(Keybindings[e.key]) do
      handler()
    end
  end

  return true
end
