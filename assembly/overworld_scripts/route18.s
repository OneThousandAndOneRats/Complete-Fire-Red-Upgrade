.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_DittoGift:
	lock
	faceplayer
	checkflag 0x251
	if 0x1 _goto EventScript_DittoGiftRepeat
	msgbox gText_DittoOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_DittoAccept
	msgbox gText_DittoReject 0x6
	release
	end

EventScript_DittoGiftRepeat:
	msgbox gText_DittoRepeat 0x6
	release
	end

EventScript_DittoAccept:
	msgbox gText_DittoAccept 0x6
	givepokemon SPECIES_DITTO 0x23 0x0 0x0 0x0 0x0
	setflag 0x251
	fanfare 0x13E
	msgbox gText_DittoGot MSG_KEEPOPEN
	release
	end
