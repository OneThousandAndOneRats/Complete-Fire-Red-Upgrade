.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_HonedgeGift:
	lock
	faceplayer
	checkflag 0x276
	if 0x1 _goto EventScript_HonedgeGiftRepeat
	msgbox gText_HonedgeOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_HonedgeAccept
	msgbox gText_HonedgeReject 0x6
	release
	end

EventScript_HonedgeGiftRepeat:
	msgbox gText_HonedgeRepeat 0x6
	release
	end

EventScript_HonedgeAccept:
	msgbox gText_HonedgeAccept 0x6
	givepokemon SPECIES_HONEDGE 0x28 0x0 0x0 0x0 0x0
	setflag 0x276
	fanfare 0x13E
	msgbox gText_HonedgeGot MSG_KEEPOPEN
	release
	end


EventScript_RootFossilOldManStart:
	lock
	faceplayer
	checkflag 0x274
	if 0x1 _goto EventScript_RootFossilOldManRepeat
	checkItem ITEM_ROOT_FOSSIL 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_OldManHaveRootFossil
	msgbox gText_RootFossilOldManIntro MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_RootFossilOldManAgree
	msgbox gText_RootFossilOldManNo 0x6
	release
	end

EventScript_OldManHaveRootFossil:
	msgbox gText_RootFossilOldManAlreadyHave 0x6
	release
	end

EventScript_RootFossilOldManAgree:
	msgbox gText_RootFossilOldManYes 0x6
	setflag 0x274
	giveitem ITEM_ROOT_FOSSIL 0x1 MSG_OBTAIN
	release
	end

EventScript_RootFossilOldManRepeat:
	msgbox gText_RootFossilOldManRepeat 0x6
	release
	end


EventScript_SailFossilWomenStart:
	lock
	faceplayer
	checkflag 0x275
	if 0x1 _goto EventScript_SailFossilWomenRepeat
	checkItem ITEM_SAIL_FOSSIL 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_WomenHaveSailFossil
	msgbox gText_SailFossilWomenIntro MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_SailFossilWomanAgree
	msgbox gText_SailFossilWomenNo 0x6
	release
	end

EventScript_SailFossilWomenRepeat:
	msgbox gText_SailFossilWomenRepeat 0x6
	release
	end

EventScript_WomenHaveSailFossil:
	msgbox gText_SailFossilWomenAlreadyHave 0x6
	release
	end

EventScript_SailFossilWomanAgree:
	msgbox gText_SailFossilWomenYes 0x6
	setflag 0x275
	giveitem ITEM_SAIL_FOSSIL 0x1 MSG_OBTAIN
	release
	end
