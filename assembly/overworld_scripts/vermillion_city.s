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
