.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_LickitoungeGift:
	lock
	faceplayer
	checkflag 0x257
	if 0x1 _goto EventScript_LickitoungeGiftRepeat
	msgbox gText_LickitoungeOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_LickitoungeAccept
	msgbox gText_LickitoungeReject 0x6
	release
	end

EventScript_LickitoungeGiftRepeat:
	msgbox gText_LickitoungeRepeat 0x6
	release
	end

EventScript_LickitoungeAccept:
	msgbox gText_LickitoungeAccept 0x6
	givepokemon SPECIES_LICKITUNG 0x19 0x0 0x0 0x0 0x0
	setflag 0x257
	fanfare 0x13E
	msgbox gText_LickitoungeGot MSG_KEEPOPEN
	release
	end


EventScript_Route11Aide:
	lock
	faceplayer
	checkflag 0x252
	if 0x1 _goto EventScript_Route11Aide_Repeat
	msgbox gText_R11AideIntro MSG_KEEPOPEN
	fanfare 0x13E
	lockall
	msgbox gText_ItemFinderGet 0x6
	additem ITEM_ITEMFINDER 0x1
	lockall
	waitfanfare
	setflag 0x252
	msgbox gText_ItemfinderExplination MSG_KEEPOPEN
	release
	end

EventScript_Route11Aide_Repeat:
	msgbox gText_ItemfinderExplination MSG_KEEPOPEN
	release
	end