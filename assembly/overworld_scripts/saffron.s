.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_ChooseLeftDojoPkm:
	lock
	faceplayer
	checkflag 0x279
	if 0x1 _goto EventScript_AlreadyGotDojoPkm
	showpokepic SPECIES_DWEBBLE 0xA 0x3
	msgbox gText_DwebbleOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScriptGiveDwebble
	hidepokepic
	release
	end

EventScriptGiveDwebble:
	givepokemon SPECIES_DWEBBLE 0x1E 0x0 0x0 0x0 0x0
	setflag 0x279
	fanfare 0x13E
	hidepokepic
	hidesprite LASTTALKED
	msgbox gText_DwebbleGot MSG_KEEPOPEN
	release
	end

EventScript_ChooseRightDojoPkm:
	lock
	faceplayer
	checkflag 0x279
	if 0x1 _goto EventScript_AlreadyGotDojoPkm
	showpokepic SPECIES_JOLTIK 0xA 0x3
	msgbox gText_JoltikOffer MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScriptGiveJoltik
	hidepokepic
	release
	end

EventScriptGiveJoltik:
	givepokemon SPECIES_JOLTIK 0x1E 0x0 0x0 0x0 0x0
	setflag 0x279
	fanfare 0x13E
	hidepokepic
	hidesprite LASTTALKED
	msgbox gText_JoltikGot MSG_KEEPOPEN
	release
	end

EventScript_AlreadyGotDojoPkm:
	msgbox gText_AlreadyGotDojoMon MSG_KEEPOPEN
	release
	end


EventScript_BattleItemShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_BattleItemIntro
	waitmsg
	pokemart EventScript_BattleItems_Values
	msgbox gText_BattleItemOutro MSG_KEEPOPEN
	release
	end

.align 1
EventScript_BattleItems_Values:
	@.hword ITEM_ABILITY_CAPSULE
	.hword ITEM_CHOICE_BAND
	.hword ITEM_CHOICE_SCARF
	.hword ITEM_CHOICE_SPECS
	.hword ITEM_ASSAULT_VEST
	.hword ITEM_LIFE_ORB
	.hword ITEM_TOXIC_ORB
	.hword ITEM_FLAME_ORB
	.hword ITEM_FOCUS_SASH
	.hword ITEM_EVIOLITE
	.hword ITEM_HEAVY_DUTY_BOOTS
	.hword 0x0



EventScript_TropiousGuy:
	lock
	faceplayer
	checkflag 0x246
	if 0x1 _goto EventScript_TropiousGuyRepeat
	msgbox gText_TropiousGuyIntro MSG_KEEPOPEN
	givepokemon SPECIES_TROPIUS 0x28 0x0 0x0 0x0 0x0
	setflag 0x246
	fanfare 0x13E
	msgbox gText_TropiusGot MSG_KEEPOPEN
	msgbox gText_TropiusDescription MSG_KEEPOPEN
	release
	end

EventScript_TropiousGuyRepeat:
	msgbox gText_TropiousGuyRepeat MSG_KEEPOPEN
	release
	end