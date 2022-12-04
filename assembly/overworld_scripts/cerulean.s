.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_EspurrGift:
	lock
	faceplayer
	checkflag 0x24A
	if 0x1 _goto EventScript_EspurrGiftRepeat
	msgbox gText_EspurrOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EspurrAccept
	msgbox gText_EspurrReject 0x6
	release
	end

EventScript_EspurrGiftRepeat:
	msgbox gText_EspurrRepeat 0x6
	release
	end

EventScript_EspurrAccept:
	msgbox gText_EspurrAccept 0x6
	givepokemon SPECIES_ESPURR 0xA 0x0 0x0 0x0 0x0
	setflag 0x24A
	fanfare 0x13E
	msgbox gText_EspurrGot MSG_KEEPOPEN
	release
	end


EventScript_EspurrOldLady:
	lock
	faceplayer
	checkflag 0x24A
	if 0x1 _goto EventScriptEspurrOldLadyAccepted
	msgbox gTextbox_EspurrOldLady 0x6
	release
	end

EventScriptEspurrOldLadyAccepted:
	msgbox gTextbox_EspurrOldLadyAccepted 0x6
	release
	end