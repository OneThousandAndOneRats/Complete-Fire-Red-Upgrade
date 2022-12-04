.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_ViridianCity_LittleGirl:
	lock
	faceplayer
	msgbox gText_ViridianCityLittleGirl MSG_FACE
	giveitem ITEM_SEA_INCENSE 0x1 MSG_OBTAIN
	giveitem ITEM_LAX_INCENSE 0x1 MSG_OBTAIN 
	giveitem ITEM_LUCK_INCENSE 0x1 MSG_OBTAIN
	giveitem ITEM_FULL_INCENSE 0x1 MSG_OBTAIN
	giveitem ITEM_ODD_INCENSE 0x1 MSG_OBTAIN 
	giveitem ITEM_PURE_INCENSE 0x1 MSG_OBTAIN
	giveitem ITEM_ROCK_INCENSE 0x1 MSG_OBTAIN
	giveitem ITEM_ROSE_INCENSE 0x1 MSG_OBTAIN 
	giveitem ITEM_WAVE_INCENSE 0x1 MSG_OBTAIN
	release
	end


	@---------------
EventScript_fishingrod_start:
	lock
	faceplayer
	checkflag 0x240
	if 0x1 _goto EventScript_fishingrod_alreadyHave
	msgbox gText_fishingrod_intro MSG_YESNO @"I@m the Fishing Guru!\pI simply lo..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_fishingrod_giveRod
	msgbox gText_fishingrod_turndown MSG_KEEPOPEN @"Oh[.]\nThat@s so disappointing[.]"
	release
	end

	@---------------
EventScript_fishingrod_alreadyHave:
	msgbox gText_fishingrod_followup MSG_KEEPOPEN @"Hello there, [player]!\pHow are th..."
	release
	end

	@---------------
EventScript_fishingrod_giveRod:
	@checkitemroom ITEM_OLD_ROD 0x1
	@compare LASTRESULT 0x0
	@if 0x1 _goto EventScript_fishingrod_decline
	@additem ITEM_OLD_ROD 0x1
	msgbox 0x8193F2A MSG_KEEPOPEN @"Grand! I like your style.\nI think..."
	@msgbox gText_fishingrod_recieve MSG_KEEPOPEN@"[player] received an Old Rod from\..."
	giveitem ITEM_OLD_ROD 0x1 MSG_OBTAIN
	setflag 0x240
	msgbox gText_fishingrod_after MSG_KEEPOPEN @"Fishing is a way of life!\nIt is l..."
	release
	end

	@---------------
EventScript_fishingrod_decline:
	msgbox gText_fishingrod_noroom MSG_KEEPOPEN @"Oh, no!\pI had a nice gift for you..."
	release
	end




EventScript_oldManCatchingLeft:
	lockall
	textcolor 0x0
	applymovement 0x4 0x81A75E7
	waitmovement 0x0
	applymovement 0xFF 0x81A75EB
	waitmovement 0x0
	call EventScript_oldManGiveDexnav
	release
	end
	
EventScript_oldManCatchingRight:
	lockall
	textcolor 0x0
	applymovement 0x4 0x81A75EB
	waitmovement 0x0
	applymovement 0xFF 0x81A75E7
	waitmovement 0x0
	call EventScript_oldManGiveDexnav
	release
	end

EventScript_oldManGiveDexnav:
	msgbox gText_OldManCoffe 0x6
	fanfare 0x13E
	lockall
	msgbox gText_RecievedDexNav 0x6
	lockall
	waitfanfare
	setflag 0x91E
	msgbox gText_DexNav_Explination 0x6
	setvar 0x4051 0x2
	return