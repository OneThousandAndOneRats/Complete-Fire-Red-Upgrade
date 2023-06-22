.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_CutTree:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_EndCut
	lockall
	checkflag 0x821
	if 0x0 _goto EventScript_CanbeCut
	special 0x10a
	setanimation 0x0 0x8004
	bufferattack 0x1 0xF
	msgbox gText_CutTreeQuestion MSG_YESNO
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_EndCutChoice
	closeonkeypress
	doanimation 0x2
	waitstate
	goto EventScript_CutDownTree


EventScript_EndCut:
	release
	end

EventScript_CanbeCut:
	msgbox gText_TreeCanBeCut MSG_SIGN
	releaseall
	end

EventScript_EndCutChoice:
	closeonkeypress
	releaseall
	end

EventScript_CutDownTree:
	sound 0x79
	applymovement LASTTALKED EventScript_newcut_Movement
	waitmovement 0x0
	checksound
	hidesprite LASTTALKED
	releaseall
	end

EventScript_newcut_Movement:
	.byte 0x69
	.byte 0xFE

.global EventScript_shop_End
EventScript_shop_End:
	release
	end

.global EventScript_newstrength_Start
EventScript_newstrength_Start:
	lockall
	checkflag 0x23A
	if 0x0 _goto EventScript_newstrength_Cantpoosh
	checkflag 0x805
	if 0x1 _goto EventScript_newstrength_Pushed
	special 0x10C
	checkitem ITEM_HM04 0x1 
	compare 0x800D 0x1
	if lessthan _goto EventScript_newstrength_Cantpoosh
	goto EventScript_newstrength_Usestrength

EventScript_newstrength_Cantpoosh:
	msgbox gText_LargeBoulder MSG_SIGN @"It@s a big boulder, but a POK�MON\..."
	end

	@---------------
EventScript_newstrength_Pushed:
	msgbox gText_PossibleToPushBoulder MSG_SIGN @"STRENGTH made it possible to move\..."
	end


	@---------------
EventScript_newstrength_Usestrength:
	setflag 0x805
	msgbox gText_PossibleToPushBoulder MSG_SIGN @"[buffer1] used STRENGTH!\p[buffer1..."
	end


.global EventScript_RockSmash 
EventScript_RockSmash:
	checkflag 0x825
	if 0x0 _goto EventScript_newcut_CantSmash
	checkitem ITEM_HM06 0x1 
    compare 0x800D 0x1
	if lessthan _goto EventScript_newcut_CantSmash
	goto EventScript_newSmash_Hideshit
	
EventScript_newcut_CantSmash:
	textcolor 0x2
	msgbox gText_newrocksmash_Nosmash 0x6
	releaseall
	end

EventScript_newSmash_Hideshit:
	sound 0x7C
	applymovement LASTTALKED EventScript_newrocksmash_Delete
	waitmovement 0x0
	checksound 
	hidesprite LASTTALKED
	special 0xAB
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_newrocksmash_Endall
	waitstate
	releaseall
	end

EventScript_newrocksmash_Endall:
	releaseall
	end
	
EventScript_newrocksmash_Delete:
	.byte 0x68
	.byte 0xFE


.global EventScript_GimmighoulEncounter 
EventScript_GimmighoulEncounter:
	lockall
	msgbox gText_Gimmighoul_Found 0x6
	wildbattle SPECIES_GIMMIGHOUL 0xA 0x00
	showcoins 0x0 0x0
	msgbox gText_Gimmighoul_Coins 0x6
	callasm GiveRandomCoins
	updatecoins 0x0 0x0
	sound 0xF8
	msgbox gText_Gimmighoul_CoinsTaken 0x6
	hidecoins 0x0 0x0
	releaseall
	end
