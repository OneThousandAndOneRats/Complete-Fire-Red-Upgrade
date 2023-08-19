.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_fossilLeft_start:
	lock
	faceplayer
	msgbox gText_fossilLeft_prompt MSG_YESNO @"Do you want the Root Fossil?"
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_fossil_decline
	hidesprite 0x1
	@additem ITEM_ROOT_FOSSIL 0x1
	loadpointer 0x0 gText_fossilLeft_get @"Obtained the Root Fossil!"
	giveitem ITEM_ROOT_FOSSIL 0x1 MSG_OBTAIN
	closeonkeypress
	special 0x188
	pause 0xA
	applymovement 0x3 0x816077A
	waitmovement 0x0
	moveoffscreen 0x3
	textcolor 0x0
	fanfare 0x13E
	preparemsg 0x8172BD6 @"All right.\nThen this fossil is mi..."
	waitmsg
	waitfanfare
	hidesprite 0x2
	setflag 0x272
	setflag 0x232
	release
	end


EventScript_fossilRight_start:
	lock
	faceplayer
	msgbox gText_fossilRight_prompt MSG_YESNO @"Do you want the Sail Fossil?"
	compare LASTRESULT 0x0
	if 0x1 _goto 0x81607DE
	hidesprite 0x2
	@additem ITEM_SAIL_FOSSIL 0x1
	loadpointer 0x0 gText_fossilRight_get @"Obtained the Sail Fossil!"
	giveitem ITEM_SAIL_FOSSIL 0x1 MSG_OBTAIN
	closeonkeypress
	special 0x188
	pause 0xA
	applymovement 0x3 0x81607E0
	waitmovement 0x0
	moveoffscreen 0x3
	textcolor 0x0
	fanfare 0x13E
	preparemsg 0x8172BD6 @"All right.\nThen this fossil is mi..."
	waitmsg
	waitfanfare
	hidesprite 0x1
	setflag 0x273
	setflag 0x232
	release
	end

	@---------------
EventScript_fossil_decline:
	release
	end

	@-----------
	@ Movements
	@-----------
EventScript_fossilLeft_move:
.byte 0x13
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE

EventScript_fossilRight_move:
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE


EventScript_TempOldManMtMoon_start:
	lock
	faceplayer
	msgbox gText_MeteoriteMan MSG_FACE
	release
	end

EventScript_MtMoonSummitMusicControlStop:
	checkflag 0x09A
	if 0x0 _goto EventScript_MtMoonSummitMusicControlStopStop
	end

EventScript_MtMoonSummitMusicControlStopStop:
	setflag 0x01F
	fadeoutbgm 0x0 
	end

EventScript_MtMoonSummitMusicControlStart:
	checkflag 0x01F
	if 0x1 _goto EventScript_MtMoonSummitMusicControlStartStart
	end

EventScript_MtMoonSummitMusicControlStartStart:
	clearflag 0x01F
	fadeinbgm 0x2 
	end

EventScript_MtMoonDeoxysFight:
	lock
	cry SPECIES_DEOXYS 0x2
	waitcry
	playsong 0x157
	wildbattle SPECIES_DEOXYS 0x2D 0x00
	setflag 0x09A
	clearflag 0x01F
	hidesprite 0x4
	release
	end

EventScript_MtMoonMetoriteNormal:
	lock
	msgbox gText_NormalMeteorite 0x6
    special 0x9F
    waitstate
    callasm SetDeoxysFormNormal
    release
    end

EventScript_MtMoonMetoriteDefense:
	lock
	msgbox gText_DefenseMeteorite 0x6
    special 0x9F
    waitstate
    callasm SetDeoxysFormDefense
    release
    end

EventScript_MtMoonMetoriteAttack:
	lock
	msgbox gText_AttackMeteorite 0x6
    special 0x9F
    waitstate
    callasm SetDeoxysFormAttack
    release
    end

EventScript_MtMoonMetoriteSpeed:
	lock
	msgbox gText_SpeedMeteorite 0x6
    special 0x9F
    waitstate
    callasm SetDeoxysFormSpeed
    release
    end


EventScript_MtMoonTopHikerDon:
	trainerbattle1 0x0 0x65 0x0 gText_CrystalRocketSurprised gText_CrystalRocketABeaten EventScript_MtMoonHikerEnd
	msgbox gText_SpeedMeteorite 0x6
    end

EventScript_MtMoonTopHikerRon:
	trainerbattle1 0x0 0x71 0x0 gText_CrystalRocketSurprised gText_CrystalRocketABeaten EventScript_MtMoonHikerEnd
	msgbox gText_SpeedMeteorite 0x6
    end

EventScript_MtMoonTopHikerJon:
	trainerbattle1 0x0 0x1EC 0x0 gText_CrystalRocketSurprised gText_CrystalRocketABeaten EventScript_MtMoonHikerEnd
	msgbox gText_SpeedMeteorite 0x6
    end

EventScript_MtMoonHikerEnd:
	end
