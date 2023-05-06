.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_Vermillion_VsSeeker:
	lock
	faceplayer
	checkflag 0x292
	if 0x1 _goto EventScript_Vermillion_VsSeeker_Repeat
	msgbox gText_VermillionVsSeeker MSG_FACE
	msgbox gText_VermillionLinkCableGet MSG_KEEPOPEN
	additem ITEM_LINK_CABLE 0x1
	setflag 0x292
	release
	end

EventScript_Vermillion_VsSeeker_Repeat:
	msgbox gText_VermillionVsSeeker_Repeat MSG_FACE
	release
	end


EventScript_ChatotGift:
	lock
	faceplayer
	checkflag 0x24D
	if 0x1 _goto EventScript_ChatotGiftRepeat
	msgbox gText_ChatotOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ChatotAccept
	msgbox gText_ChatotReject 0x6
	release
	end

EventScript_ChatotGiftRepeat:
	msgbox gText_ChatotRepeat 0x6
	release
	end

EventScript_ChatotAccept:
	msgbox gText_ChatotAccept 0x6
	givepokemon SPECIES_CHATOT 0x14 0x0 0x0 0x0 0x0
	setflag 0x24D
	fanfare 0x13E
	msgbox gText_ChatotGot MSG_KEEPOPEN
	release
	end

EventScript_Vermillion_Fisher:
	lock
	faceplayer
	checkflag 0x959
	if 0x1 _goto EventScript_Vermillion_FisherRepeat
	msgbox gText_VermillionFisherGift 0x6
	giveitem ITEM_SUN_STONE 0x1 MSG_OBTAIN
	setflag 0x959
	release
	end

EventScript_Vermillion_FisherRepeat:
	msgbox gText_VermillionFisherRepeat 0x6
	release
	end


@00 = top left corner
@24 = bottom right corner
EventScript_LtSurgePuzzle00:
	lockall
	setvar 0x8008 0x1
	goto 0x816B843

EventScript_LtSurgePuzzle01:
	lockall
	setvar 0x8008 0x2
	goto 0x816B843

EventScript_LtSurgePuzzle02:
	lockall
	setvar 0x8008 0x3
	goto 0x816B843

EventScript_LtSurgePuzzle03:
	lockall
	setvar 0x8008 0x4
	goto 0x816B843

EventScript_LtSurgePuzzle04:
	lockall
	setvar 0x8008 0x5
	goto 0x816B843


EventScript_LtSurgePuzzle10:
	lockall
	setvar 0x8008 0x6
	goto 0x816B843

EventScript_LtSurgePuzzle11:
	lockall
	setvar 0x8008 0x7
	goto 0x816B843

EventScript_LtSurgePuzzle12:
	lockall
	setvar 0x8008 0x8
	goto 0x816B843

EventScript_LtSurgePuzzle13:
	lockall
	setvar 0x8008 0x9
	goto 0x816B843

EventScript_LtSurgePuzzle14:
	lockall
	setvar 0x8008 0xA
	goto 0x816B843

EventScript_LtSurgePuzzle20:
	lockall
	setvar 0x8008 0xB
	goto 0x816B843

EventScript_LtSurgePuzzle21:
	lockall
	setvar 0x8008 0xC
	goto 0x816B843

EventScript_LtSurgePuzzle22:
	lockall
	setvar 0x8008 0xD
	goto 0x816B843

EventScript_LtSurgePuzzle23:
	lockall
	setvar 0x8008 0xE
	goto 0x816B843

EventScript_LtSurgePuzzle24:
	lockall
	setvar 0x8008 0xF
	goto 0x816B843