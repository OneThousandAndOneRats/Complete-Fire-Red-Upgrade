.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_Route16Aide:
	lock
	faceplayer
	checkflag 0x2FD
	if 0x1 _goto EventScript_Route16Aide_Repeat
	msgbox gText_R16AideIntro MSG_KEEPOPEN
	fanfare 0x13E
	lockall
	msgbox gText_AmuletCoinGet 0x6
	additem ITEM_AMULET_COIN 0x1
	lockall
	waitfanfare
	setflag 0x2FD
	msgbox gText_AmuletCoinExplination MSG_KEEPOPEN
	release
	end

EventScript_Route16Aide_Repeat:
	msgbox gText_AmuletCoinExplination MSG_KEEPOPEN
	release
	end