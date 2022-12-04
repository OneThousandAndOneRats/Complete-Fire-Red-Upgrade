.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_Route2Aide:
	lock
	faceplayer
	checkflag 0x23B
	if 0x1 _goto EventScript_Route2AideRepeat
	msgbox gText_R2AideIntro MSG_KEEPOPEN
	fanfare 0x13E
	lockall
	msgbox gText_FlashGet 0x6
	additem ITEM_TM70 0x1
	lockall
	waitfanfare
	setflag 0x23B
	msgbox gText_FlashExplination MSG_KEEPOPEN
	release
	end

EventScript_Route2AideRepeat:
	msgbox gText_FlashExplination MSG_KEEPOPEN
	release
	end


EventScript_MimeJrGift:
	lock
	faceplayer
	checkflag 0x248
	if 0x1 _goto EventScript_MimeJrGiftRepeat
	msgbox gText_MimeJrOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_MimeJrAccept
	msgbox gText_MimeJrReject 0x6
	release
	end

EventScript_MimeJrGiftRepeat:
	msgbox gText_MimeJrRepeat 0x6
	release
	end

EventScript_MimeJrAccept:
	msgbox gText_MimeJrAccept 0x6
	givepokemon SPECIES_MIME_JR 0x14 0x0 0x0 0x0 0x0
	setflag 0x248
	fanfare 0x13E
	msgbox gText_MimeJrGot MSG_KEEPOPEN
	release
	end
