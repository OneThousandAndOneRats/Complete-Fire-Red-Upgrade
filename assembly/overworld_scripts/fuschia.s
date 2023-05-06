.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_FuschiaWarden:
	lock
	faceplayer
	checkflag 0x23A
	if 0x1 _goto EventScript_FuschiaWardenRepeat
	checkItem ITEM_GOLD_TEETH 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_WardenGiveBackTeeth
	msgbox gText_WardenNoTeeth MSG_YESNO
	if 0x1 _goto EventScript_WardenYes
	msgbox gTextWardenNoText 0x6 
	release
	end

EventScript_FuschiaWardenRepeat:
	msgbox gText_WardenRepeat 0x6
	release
	end

EventScript_WardenGiveBackTeeth:
	fanfare 0x105
	preparemsg gText_WardenTeethReturn
	waitmsg
	waitfanfare
	msgbox gText_WardenPutsTeethIn 0x6
	removeitem ITEM_GOLD_TEETH
	msgbox gText_WardenThanks 0x6
	additem ITEM_HM04 0x1
	msgbox gText_Hm04Get 0x6
	setflag 0x23A
	msgbox gText_WardenRepeat 0x6
	release
	end

EventScript_WardenYes:
	msgbox gTextWardenYesText 0x6
	release
	end


.global EventScript_Fuschia_EggTutor
EventScript_Fuschia_EggTutor:
    lock
    faceplayer
    textcolor 0x0
    msgbox gText_EggMoveTutorIntro MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto Cancel1
    msgbox gText_EggMoveAskWho MSG_NORMAL
    call Teach
    msgbox gText_EggMoveAskWhat MSG_NORMAL
    call TeachMoves
    textcolor 0x3
    msgbox gText_EggMoveEnjoy MSG_NORMAL
    clearflag 0x917
    release
    end



Teach:
    setflag 0x917
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto Cancel1
    special 0x148 @check if its an egg
    compare LASTRESULT 0x1
    if 0x1 _goto CancelNo3
    compare 0x8005 0x0
    if 0x1 _goto CancelNo
    return

TeachMoves:
    special 0xE0
    waitstate
    compare 0x8004 0x0
    if 0x1 _goto Cancel1
    return

Cancel1:
    clearflag 0x917
    msgbox gText_EggMoveTutorNo MSG_NORMAL
    release
    end

CancelNo:
    clearflag 0x917
    msgbox gText_LearnEggMove MSG_NORMAL
    release
    end

CancelNo3:
    clearflag 0x917
    msgbox gText_Fuschia_EggNo3 MSG_NORMAL
    release
    end

EventScript_FuschiaGymChefCounter:
    lock
    faceplayer
    msgbox gText_FushiaGymChefCounter MSG_NORMAL
    release
    end