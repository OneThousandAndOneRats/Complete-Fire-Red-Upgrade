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
