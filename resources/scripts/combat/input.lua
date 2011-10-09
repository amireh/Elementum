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

Debug = {}
Debug.playSpellEffect = function(e)
  if (Selected) then
    if key_map[e.key] then FxEngine:playEffect(key_map[e.key], Selected) end
  end

  return true
end
