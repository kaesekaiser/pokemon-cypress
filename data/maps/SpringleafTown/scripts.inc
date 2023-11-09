SpringleafTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SpringleafTown_EventScript_OnTransition
	.byte 0

SpringleafTown_EventScript_OnTransition::
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKENAV_GET
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setrespawn HEAL_LOCATION_SPRINGLEAF_TOWN
	end

SpringleafTown_EventScript_GetStarter::
	finditem ITEM_HM_SURF
	msgbox SpringleafTown_Text_AlsoYouGotAPopplio, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEMON_GET
	givemon SPECIES_POPPLIO, 5
	giveitem ITEM_INFINITE_CANDY
	msgbox SpringleafTown_Text_ThatShouldHelp, MSGBOX_DEFAULT
	closemessage
	end
	
SpringleafTown_Text_AlsoYouGotAPopplio::
	.string "Also, here's a Popplio!\n"
	.string "And an Infinicandy to go with it.$"

SpringleafTown_Text_ThatShouldHelp::
	.string "That should help get you started\n"
	.string "on your journey. Have fun!$"
