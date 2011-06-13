Pixy.Spells.Earth.Matter["Summon: Fetish Zij"] = {}
local lSpell = Pixy.Spells.Earth.Matter["Summon: Fetish Zij"]
lSpell.Name = "Summon: Fetish Zij"
lSpell.Cost = 5
lSpell.Dispellable = false
lSpell.Phase = "Casting"
lSpell.Alignment = "Lawful"
lSpell.Effects = {}
lSpell.Interface = {
  Tooltip = "Summons a Fetish:Zij with 4/1",
  Imageset = "Spells-Fire",
  Image = "Imp"
}

--[[
<Spell id="0" Name="Summon Earth Elemental">
    <Property Name="Alignment"      Value="Lawful" />
    <Property Name="Aspect"         Value="Matter" />
    <Property Name="Requires-Target"Value="No" />
    <Property Name="Cost"           Value="5" />
    <Property Name="Dispellable"    Value="No" />
    <Property Name="Phase"          Value="Passive" />
    <Effects>
        <Effect Name="Summoning">
            <Property Name="Unit-Name" Value="Earth Elemental" />
        </Effect>
    </Effects>
    <Interface>
        <Property Name="Imageset" Value="Spells-Earth" />
        <Property Name="Image" Value="Earth-Elemental" />
        <Property Name="Tooltip" Value="Summons an Ele with 2/2" />
    </Interface>
</Spell>

]]
