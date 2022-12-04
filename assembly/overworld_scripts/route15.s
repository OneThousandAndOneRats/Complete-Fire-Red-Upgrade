.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_Route15Aide:
	lock
	faceplayer
	checkflag 0x256
	if 0x1 _goto EventScript_Route15Aide_Repeat
	msgbox gText_R15AideIntro MSG_KEEPOPEN
	fanfare 0x13E
	lockall
	msgbox gText_LuckyEggGet 0x6
	additem ITEM_LUCKY_EGG 0x1
	lockall
	waitfanfare
	setflag 0x256
	msgbox gText_LuckyEggExplination MSG_KEEPOPEN
	release
	end

EventScript_Route15Aide_Repeat:
	msgbox gText_LuckyEggExplination MSG_KEEPOPEN
	release
	end