.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_Route10Aide:
	lock
	faceplayer
	checkflag 0x2FA
	if 0x1 _goto EventScript_Route10Aide_Repeat
	msgbox gText_R10AideIntro MSG_KEEPOPEN
	fanfare 0x13E
	lockall
	msgbox gText_EverstoneGet 0x6
	additem ITEM_EVERSTONE 0x1
	lockall
	waitfanfare
	setflag 0x2FA
	msgbox gText_EverstoneExplination MSG_KEEPOPEN
	release
	end

EventScript_Route10Aide_Repeat:
	msgbox gText_EverstoneExplination MSG_KEEPOPEN
	release
	end