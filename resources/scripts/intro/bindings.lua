bind(Pixy.EventUID.Login, MainMenu.onLogin)
bind(Pixy.EventUID.Connected, MainMenu.onConnected)
bind(Pixy.EventUID.EntityDied, MainMenu.onEntityDied)
bind(Pixy.EventUID.EntitySelected, Profiles.onEntitySelected)
bind(Pixy.EventUID.EntityDeselected, Profiles.onEntityDeselected)
bind(Pixy.EventUID.ShuttingDown, MainMenu.cleanup)

--Pixy.Log("I'm BEING CALLED")
