.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_Amber_start:
	lock
	faceplayer
	checkflag 0x25E
	if 0x1 _goto EventScript_Amber_repeat
	msgbox gText_Amber_intro MSG_KEEPOPEN @"Ssh! Listen, I need to share a\nse..."
	@checkitemroom 0x162 0x1
	@compare LASTRESULT 0x0
	@if 0x1 _goto 0x816A4F5
	setflag 0x25E
	hidesprite 0x4
	@additem 0x162 0x1
	loadpointer 0x0 gText_Amber_get @"[player] received the Old Amber\nf..."
	giveitem ITEM_ODD_KEYSTONE 0x1 MSG_OBTAIN
	release
	end

	@---------------
EventScript_Amber_repeat:
	msgbox gText_Amber_repeat MSG_KEEPOPEN @"Ssh!\nGet the Old Amber checked!"
	release
	end

EventScript_Amber_display:
	lock
	faceplayer
	checkflag 0x25E
	if 0x1 _goto EventScript_Amber_display_empty
	msgbox gText_Amber_display MSG_FACE
	release
	end

EventScript_Amber_display_empty:
	msgbox gText_Amber_display_empty MSG_FACE
	release
	end

EventScript_runningshoes4:
	lockall
	setvar 0x4001 0x1
	call EventScript_runningshoes_main
	releaseall
	end

EventScript_runningshoes5:
	lockall
	setvar 0x4001 0x2
	call EventScript_runningshoes_main
	releaseall
	end

EventScript_runningshoes6:
	lockall
	setvar 0x4001 0x3
	call EventScript_runningshoes_main
	releaseall
	end

EventScript_runningshoesTalk:
	lock
	faceplayer
	setvar 0x4001 0x0
	call EventScript_runningshoes_main
	release
	end

EventScript_runningshoes_main:
	textcolor 0x0
	compare 0x4001 0x1
	if 0x1 _call 0x81663CA
	compare 0x4001 0x2
	if 0x1 _call 0x81663CA
	compare 0x4001 0x3
	if 0x1 _call 0x81663CA
	checksound
	sound 0x15
	applymovement 0x7 0x81A75DB
	waitmovement 0x0
	applymovement 0x7 0x81A75DD
	waitmovement 0x0
	msgbox gText_runningshoes_intro MSG_KEEPOPEN @"Oh, [player]\v\h05!"
	compare 0x4001 0x0
	if 0x1 _call 0x81663D5
	compare 0x4001 0x1
	if 0x1 _call 0x81663DA
	compare 0x4001 0x2
	if 0x1 _call 0x81663E6
	compare 0x4001 0x3
	if 0x1 _call 0x81663FC
	msgbox gText_runningshoes_greet MSG_KEEPOPEN @"I@m glad I caught up to you.\nI@m ..."
	textcolor 0x3
	fanfare 0x13E
	preparemsg gText_runningshoes_get @"[player] received the\nRUNNING SHO..."
	waitmsg
	waitfanfare
	additem ITEM_EXP_SHARE 0x1
	@setflag 0x906  @REENABLE THIS ONE ITS FIGURED OUT HOW TO MAKE ITEM TOGGLE IT
	@msgbox 0x817E99D MSG_KEEPOPEN @"[player] switched shoes with the\n..."
	@special 0x171
	@signmsg
	@msgbox 0x817E9C7 MSG_KEEPOPEN @"Press the B Button to run.\nBut on..."
	@normalmsg
	call 0x81A6675
	msgbox gText_runningshoes_ MSG_KEEPOPEN @"Well, I must be going back to\nthe..."
	closeonkeypress
	compare 0x4001 0x0
	if 0x1 _call 0x8166412
	compare 0x4001 0x1
	if 0x1 _call 0x816641D
	compare 0x4001 0x2
	if 0x1 _call 0x8166428
	compare 0x4001 0x3
	if 0x1 _call 0x8166433
	pause 0x1E
	textcolor 0x3
	@msgbox 0x817EA36 MSG_KEEPOPEN @"There@s a letter attached[.]\pDear..."
	closeonkeypress
	hidesprite 0x7
	setflag 0x82F
	setvar 0x406C 0x2
	return


EventScript_EntranceGuy:
	lock
	faceplayer
	compare PLAYERFACING 0x3
	if 0x1 _goto EventScript_EntranceGuyfromBack
	compare PLAYERFACING 0x1
	if 0x1 _goto EventScript_EntranceGuyfromBack
	compare PLAYERFACING 0x2
	if 0x1 _goto EventScript_EntranceGuyfromBack
	msgbox gText_EnjoyYourself MSG_KEEPOPEN 
	release
	end

EventScript_EntranceGuyfromBack:
	msgbox gText_SneakIn MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EntranceGuyYes
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_EntranceGuyNo
	end

EventScript_EntranceGuyYes:
	msgbox gText_SneakInYes MSG_KEEPOPEN
	applymovement LASTTALKED EventScript_EntranceMovement
	waitmovement 0x0
	release
	end

EventScript_EntranceGuyNo:
	msgbox gText_SneakInNo MSG_KEEPOPEN
	applymovement LASTTALKED EventScript_EntranceMovement
	waitmovement 0x0
	release
	end

EventScript_EntranceMovement:
	.byte 0x5A
	.byte 0xFE