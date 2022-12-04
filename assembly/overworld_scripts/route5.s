.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_KlinkGift:
	lock
	faceplayer
	checkflag 0x24B
	if 0x1 _goto EventScript_KlinkGiftRepeat
	msgbox gText_KlinkOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_KlinkAccept
	msgbox gText_KlinkReject 0x6
	release
	end

EventScript_KlinkGiftRepeat:
	msgbox gText_KlinkRepeat 0x6
	release
	end

EventScript_KlinkAccept:
	msgbox gText_KlinkAccept 0x6
	givepokemon SPECIES_KLINK 0xF 0x0 0x0 0x0 0x0
	setflag 0x24B
	fanfare 0x13E
	msgbox gText_KlinkGot MSG_KEEPOPEN
	release
	end
