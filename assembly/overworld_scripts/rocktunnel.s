.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_Crystal_Rocket:
	@textcolor 0x0
	lock
	msgbox gText_CrystalRocketIntro 0x6
	sound 0x15 
	applymovement 0x1 Surprised
	applymovement 0x2 Surprised
	@msgbox gText_CrystalRocketSurprised MSG_KEEPOPEN
	trainerbattle1 0x1 0xAE 0x0 gText_CrystalRocketSurprised gText_CrystalRocketABeaten EventScript_CrystalFirstGruntBeaten
	release
	end

EventScript_CrystalFirstGruntBeaten:
	@msgbox gText_CrystalRocketSecondMatch MSG_KEEPOPEN
	trainerbattle1 0x1 0xAF 0x0 gText_CrystalRocketSecondMatch gText_CrystalRocketBBeaten EventScript_CrystalSecondGruntBeaten
	release
	end

EventScript_CrystalSecondGruntBeaten:
	msgbox gText_CrystalRocketBeaten MSG_KEEPOPEN
	setvar 0x8004 0x5 @This controls how far the screen shakes vertically
	setvar 0x8005 0x0 @This controls how far the screen shakes horizontally
	setvar 0x8006 0x8 @This controls how long the overall animation lasts
	setvar 0x8007 0x3 @This controls how long one screen shake lasts
	special 0x136 @SPECIAL_SHAKE_SCREEN
	waitstate
	applymovement 0x1 Confused_A
	applymovement 0x2 Confused_B
	msgbox gText_CrystalRocketSomethingsComing MSG_KEEPOPEN
	special 0x136 @SPECIAL_SHAKE_SCREEN
	waitstate
	applymovement 0x1 Surprised
	applymovement 0x2 Surprised
	special 0x136 @SPECIAL_SHAKE_SCREEN
	waitstate
	cry SPECIES_ONIX 0x2
	textcolor 0x3
    preparemsg gText_CrystalRocketRoar 
    waitmsg
    textcolor 0x0
    waitcry
    special 0x136 @SPECIAL_SHAKE_SCREEN
	waitstate
	msgbox gText_CrystalRocketFlee MSG_NORMAL
	waitmsg
	applymovement 0x1 FleeA
	applymovement 0x2 FleeB
	special 0x136 @SPECIAL_SHAKE_SCREEN
	waitstate
	cry SPECIES_ONIX 0x2
	waitcry
	special 0x136 @SPECIAL_SHAKE_SCREEN
	waitstate
    wildbattle SPECIES_CRYSONIX 0x2D 0x00
    hidesprite 0x1
    hidesprite 0x2
    setflag 0x202
	release
	end


Surprised:
	.byte look_up 
	.byte exclaim
	.byte end_m

Confused_A:
	.byte say_question
	.byte look_down
	.byte pause_long
	.byte look_left 
	.byte pause_long
	.byte look_right
	.byte pause_long
	.byte look_up
	.byte end_m

Confused_B:
	.byte say_question
	.byte look_right
	.byte pause_long
	.byte look_left 
	.byte pause_long
	.byte look_down
	.byte pause_long
	.byte look_up
	.byte end_m

FleeA:
	.byte run_left
	.byte run_up
	.byte run_up
	.byte run_right
	.byte run_up
	.byte run_up
	.byte run_up
	.byte run_up
	.byte run_up
	.byte end_m
FleeB:
	.byte run_right
	.byte run_up
	.byte run_up
	.byte run_left
	.byte run_up
	.byte run_up
	.byte run_up
	.byte run_up
	.byte run_up
	.byte end_m
