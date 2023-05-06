.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_FatGuy
EventScript_PalletTown_FatGuy:
	lock
	faceplayer
	msgbox gText_PalletTown_FatGuy MSG_FACE
	@msgbox gText_GymGuyPewter MSG_FACE
	giveitem ITEM_RARE_CANDY 0xFF MSG_OBTAIN
	givepokemon SPECIES_SOLROCK 0x32 0x0 0x0 0x0 0x0
	givepokemon SPECIES_TOXEL 0x32 0x0 0x0 0x0 0x0
	givepokemon SPECIES_TOXEL 0x32 0x0 0x0 0x0 0x0
	givepokemon SPECIES_TOXEL 0x32 0x0 0x0 0x0 0x0
	givepokemon SPECIES_TOXEL 0x32 0x0 0x0 0x0 0x0
	@givepokemon SPECIES_BRELOOM 0x32 0x0 0x0 0x0 0x0
	@givepokemon SPECIES_TANGROWTH 0x32 0x0 0x0 0x0 0x0
	@givepokemon SPECIES_SHIINOTIC 0x1E 0x0 0x0 0x0 0x0
	@givepokemon SPECIES_SHUCKLE 0x32 0x0 0x0 0x0 0x0
	@givepokemon SPECIES_AMOONGUSS 0x1E 0x0 0x0 0x0 0x0
	release
	end

EventScript_PalletTown_NES:
	lock
	faceplayer
	checkflag 0x958
	if 0x1 _goto EventScript_already_got
	msgbox gText_PalletTown_NES_first MSG_FACE
	giveitem ITEM_SHINY_CHARM 0x1 MSG_OBTAIN
	setflag 0x958
	release
	end

EventScript_already_got:
	msgbox gText_PalletTown_NES_second 0x6
	release
	end


	@---------------
EventScript_bulbasaur_start:
	lock
	faceplayer
	setvar 0x4001 0x0
	setvar 0x4002 0x1
	setvar 0x4003 0x4
	setvar 0x4004 0x7
	compare 0x4055 0x3
	if 0x4 _goto EventScript_bulbasaur_last
	compare 0x4055 0x2
	if 0x1 _goto EventScript_bulbasaur_display
	msgbox gText_bulbasaur_containPkm MSG_KEEPOPEN @"Those are POKé BALLS.\nThey contai..."
	release
	end

	@---------------
EventScript_bulbasaur_last:
	msgbox gText_bulbasaur_lastPkm MSG_KEEPOPEN @"That@s PROF. OAK@s last POKéMON."
	release
	end

	@---------------
EventScript_bulbasaur_display:
	applymovement 0x4 0x81A75EF
	waitmovement 0x0
	showpokepic SPECIES_GROOKEY 0xA 0x3
	textcolor 0x0
	compare 0x4001 0x0
	if 0x1 _goto EventScript_bulbasaur_yesno
	compare 0x4001 0x1
	if 0x1 _goto EventScript_bulbasaur_yesno
	compare 0x4001 0x2
	if 0x1 _goto EventScript_bulbasaur_yesno
	end

	@---------------
EventScript_bulbasaur_yesno:
	msgbox gText_bulbasaur_GrassChoice MSG_YESNO @"I see! BULBASAUR is your choice.\n..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_bulbasaur_pickup
	compare LASTRESULT 0x0
	if 0x1 _goto 0x8169C71
	end

	@---------------
EventScript_squirtle_yesno:
	msgbox gText_bulbasaur_WaterChoice MSG_YESNO @"Hm! SQUIRTLE is your choice.\nIt@s..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_squirtle_pickup
	compare LASTRESULT 0x0
	if 0x1 _goto 0x8169C71
	end

	@---------------
EventScript_charmander_yesno:
	msgbox gText_bulbasaur_FireChoice MSG_YESNO @"Ah! CHARMANDER is your choice.\nYo..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_charmander_pickup
	compare LASTRESULT 0x0
	if 0x1 _goto 0x8169C71
	end

	@---------------
EventScript_bulbasaur_pickup:
	hidepokepic
	hidesprite LASTTALKED
	msgbox gText_bulbasaur_energetic MSG_KEEPOPEN @"This POKéMON is really quite\nener..."
	call 0x81A6675
	setflag 0x828
	setflag 0x291
	givepokemon SPECIES_GROOKEY 0x5 0x0 0x0 0x0 0x0
	setflag 0x906
	@givepokemon SPECIES_BULBASAUR 0x5 0x0 0x0 0x0 0x0
	copyvar 0x4031 0x4001
	bufferpokemon 0x0 SPECIES_GROOKEY
	@bufferpokemon 0x0 SPECIES_BULBASAUR
	preparemsg 0x818E30D @"[player] received the [buffer1]\nf..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	msgbox 0x81A56A7 MSG_YESNO @"Do you want to give a nickname to\..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_bulbasaur_Nickname
	compare LASTRESULT 0x0
	@if 0x1 _goto EventScript_bulbasaur_rivalmove
	if 0x1 _goto EventScript_bulbasaur_cleartext
	end

	@---------------
EventScript_bulbasaur_0X169C71:
	hidepokepic
	release
	end

	@---------------
EventScript_bulbasaur_0X1A6675:
	copyvar 0x8012 0x8013
	return

	@---------------
@EventScript_bulbasaur_0X169CCC:
EventScript_bulbasaur_Nickname:
	setvar 0x8004 0x0
	call 0x81A74EB
	goto EventScript_bulbasaur_rivalmove
	@goto 0x8169CDC

	@---------------
EventScript_bulbasaur_cleartext:
	closeonkeypress
	compare 0x4001 0x0
	if 0x1 _goto EventScript_bulbasaur_rivalmove
	compare 0x4001 0x1
	if 0x1 _goto EventScript_bulbasaur_rivalmove
	compare 0x4001 0x2
	if 0x1 _goto EventScript_bulbasaur_rivalmove
	end

	@---------------
EventScript_bulbasaur_0X1A74EB:
	fadescreen 0x1
	special 0x9E
	waitstate
	return

	@---------------
EventScript_bulbasaur_rivalmove:
	applymovement 0x8 0x8169D62
	waitmovement 0x0
	goto EventScript_bulbasaur_rivalTake

	@---------------
EventScript_squirtle_rivalmove:
	applymovement 0x8 0x8169D72
	waitmovement 0x0
	goto EventScript_squirtle_rivalTake

	@---------------
EventScript_charmander_rivalmove:
	applymovement 0x8 0x8169D6B
	waitmovement 0x0
	goto EventScript_charmander_rivalTake

	@---------------
EventScript_bulbasaur_rivalTake:
	textcolor 0x0
	msgbox 0x818DD34 MSG_KEEPOPEN @"[rival]: I@ll take this one, then!"
	hidesprite 0x4004
	textcolor 0x3
	bufferpokemon 0x0 SPECIES_FENNEKIN
	preparemsg 0x818DD52 @"[rival] received the [buffer1]\nfr..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	setvar 0x4055 0x3
	checkflag 0x83E
	if 0x1 _call 0x8169D5C
	msgbox gText_OakExpShareGive 0x6
	additem ITEM_EXP_SHARE 0x1
	release
	end

	@---------------
EventScript_bulbasaur_0X169D5C:
	setvar 0x4070 0x1
	return


	@---------
	@ Strings
	@---------











	@-----------
	@ Movements
	@-----------
EventScript_bulbasaur_0X1A75EF:
.byte 0x3
.byte 0xFE

EventScript_bulbasaur_0X169D62:
.byte 0x10
.byte 0x10
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x11
.byte 0xFE

EventScript_bulbasaur_0X169D72:
.byte 0x10
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x2E
.byte 0xFE

EventScript_bulbasaur_0X169D6B:
.byte 0x10
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x2E
.byte 0xFE


	@---------------
EventScript_squirtle_start:
	lock
	faceplayer
	setvar 0x4001 0x1
	setvar 0x4002 0x7
	setvar 0x4003 0x1
	setvar 0x4004 0x5
	compare 0x4055 0x3
	if 0x4 _goto EventScript_bulbasaur_last
	compare 0x4055 0x2
	if 0x1 _goto EventScript_squirtle_display
	msgbox gText_bulbasaur_containPkm MSG_KEEPOPEN @"Those are POKé BALLS.\nThey contai..."
	release
	end

EventScript_squirtle_display:
	applymovement 0x4 0x81A75EF
	waitmovement 0x0
	showpokepic SPECIES_TOTODILE 0xA 0x3
	textcolor 0x0
	compare 0x4001 0x0
	if 0x1 _goto EventScript_squirtle_yesno
	compare 0x4001 0x1
	if 0x1 _goto EventScript_squirtle_yesno
	compare 0x4001 0x2
	if 0x1 _goto EventScript_squirtle_yesno
	end


EventScript_squirtle_pickup:
	hidepokepic
	hidesprite LASTTALKED
	msgbox gText_bulbasaur_energetic MSG_KEEPOPEN @"This POKéMON is really quite\nener..."
	call 0x81A6675
	setflag 0x828
	setflag 0x291
	givepokemon SPECIES_TOTODILE 0x5 0x0 0x0 0x0 0x0
	setflag 0x906
	copyvar 0x4031 0x4001
	bufferpokemon 0x0 SPECIES_TOTODILE
	preparemsg 0x818E30D @"[player] received the [buffer1]\nf..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	msgbox 0x81A56A7 MSG_YESNO @"Do you want to give a nickname to\..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_squirtle_Nickname
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_squirtle_cleartext
	end

EventScript_squirtle_Nickname:
	setvar 0x8004 0x0
	call 0x81A74EB
	goto EventScript_squirtle_rivalmove

EventScript_squirtle_cleartext:
	closeonkeypress
	compare 0x4001 0x0
	if 0x1 _goto EventScript_squirtle_rivalmove
	compare 0x4001 0x1
	if 0x1 _goto EventScript_squirtle_rivalmove
	compare 0x4001 0x2
	if 0x1 _goto EventScript_squirtle_rivalmove
	end


EventScript_squirtle_rivalTake:
	textcolor 0x0
	msgbox 0x818DD34 MSG_KEEPOPEN @"[rival]: I@ll take this one, then!"
	hidesprite 0x4004
	textcolor 0x3
	bufferpokemon 0x0 SPECIES_GROOKEY
	preparemsg 0x818DD52 @"[rival] received the [buffer1]\nfr..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	setvar 0x4055 0x3
	checkflag 0x83E
	if 0x1 _call 0x8169D5C
	msgbox gText_OakExpShareGive 0x6
	additem ITEM_EXP_SHARE 0x1
	release
	end















	EventScript_charmander_start:
	lock
	faceplayer
	setvar 0x4001 0x2
	setvar 0x4002 0x4
	setvar 0x4003 0x7
	setvar 0x4004 0x6
	compare 0x4055 0x3
	if 0x4 _goto EventScript_bulbasaur_last
	compare 0x4055 0x2
	if 0x1 _goto EventScript_charmander_display
	msgbox gText_bulbasaur_containPkm MSG_KEEPOPEN @"Those are POKé BALLS.\nThey contai..."
	release
	end

	EventScript_charmander_display:
	applymovement 0x4 0x81A75EF
	waitmovement 0x0
	showpokepic SPECIES_FENNEKIN 0xA 0x3
	textcolor 0x0
	compare 0x4001 0x0
	if 0x1 _goto EventScript_charmander_yesno
	compare 0x4001 0x1
	if 0x1 _goto EventScript_charmander_yesno
	compare 0x4001 0x2
	if 0x1 _goto EventScript_charmander_yesno
	end


EventScript_charmander_pickup:
	hidepokepic
	hidesprite LASTTALKED
	msgbox gText_bulbasaur_energetic MSG_KEEPOPEN @"This POKéMON is really quite\nener..."
	call 0x81A6675
	setflag 0x828
	setflag 0x291
	givepokemon SPECIES_FENNEKIN 0x5 0x0 0x0 0x0 0x0
	setflag 0x906
	copyvar 0x4031 0x4001
	bufferpokemon 0x0 SPECIES_FENNEKIN
	preparemsg 0x818E30D @"[player] received the [buffer1]\nf..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	msgbox 0x81A56A7 MSG_YESNO @"Do you want to give a nickname to\..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_charmander_Nickname
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_charmander_cleartext
	end

EventScript_charmander_cleartext:
	closeonkeypress
	compare 0x4001 0x0
	if 0x1 _goto EventScript_charmander_rivalmove
	compare 0x4001 0x1
	if 0x1 _goto EventScript_charmander_rivalmove
	compare 0x4001 0x2
	if 0x1 _goto EventScript_charmander_rivalmove
	end



EventScript_charmander_Nickname:
	setvar 0x8004 0x0
	call 0x81A74EB
	goto EventScript_charmander_rivalmove


EventScript_charmander_rivalTake:
	textcolor 0x0
	msgbox 0x818DD34 MSG_KEEPOPEN @"[rival]: I@ll take this one, then!"
	hidesprite 0x4004
	textcolor 0x3
	bufferpokemon 0x0 SPECIES_TOTODILE
	preparemsg 0x818DD52 @"[rival] received the [buffer1]\nfr..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	setvar 0x4055 0x3
	checkflag 0x83E
	if 0x1 _call 0x8169D5C
	msgbox gText_OakExpShareGive 0x6
	additem ITEM_EXP_SHARE 0x1
	release
	end




EventScript_RoamerStart:
	checkflag 0x95A
	if 0x1 _goto EventScript_TVshow
	checkflag 0x4BC
	if 0x0 _goto EventScript_TVshow
	lock
	setvar 0x8000 SPECIES_VICTINI 
	setvar 0x8001 40
	setvar 0x8002 0x1
	setvar 0x8003 0x1
	special 0x129
	setvar 0x8000 SPECIES_MELOETTA 
	setvar 0x8001 40
	setvar 0x8002 0x1
	setvar 0x8003 0x1
	special 0x129
	setvar 0x8000 SPECIES_DEOXYS 
	setvar 0x8001 40
	setvar 0x8002 0x1
	setvar 0x8003 0x1
	special 0x129
	msgbox gText_RoamerSpotted 0x6
	setflag 0x95A
	releaseall
	end



EventScript_TVshow:
	checkgender
	compare LASTRESULT 0x0
	if 0x1 _goto BoyTvShow
	compare LASTRESULT 0x1
	if 0x1 _goto GirlTvShow
	releaseall
	end


BoyTvShow:
	msgbox gText_BoyTv 0x6
	releaseall
	end
GirlTvShow:
	msgbox gText_GirlTv 0x6
	releaseall
	end

