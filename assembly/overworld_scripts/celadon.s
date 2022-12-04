.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_FossilRevieveIntro:
	lock
	faceplayer
	msgbox gText_CeladonFossilReviveIntro MSG_KEEPOPEN
	checkItem ITEM_ROOT_FOSSIL 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_Fossil_Root
	checkItem ITEM_SAIL_FOSSIL 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_Fossil_Sail
	checkItem ITEM_ODD_KEYSTONE 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_Fossil_Keystone
	msgbox gText_CeladonFossilReviveGoodbye MSG_KEEPOPEN
	release
	end

EventScript_Fossil_Root:
	msgbox gText_CeladonFossilReviveRootFossil MSG_KEEPOPEN
	msgbox gText_CeladonFossilReviveQuestion MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_Root_Revieve
	msgbox gText_CeladonFossilReviveNoResponse MSG_KEEPOPEN
	release
	end

EventScript_Fossil_Sail:
	msgbox gText_CeladonFossilReviveSailFossil MSG_KEEPOPEN
	msgbox gText_CeladonFossilReviveQuestion MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_Sail_Revieve
	msgbox gText_CeladonFossilReviveNoResponse MSG_KEEPOPEN
	release
	end

EventScript_Fossil_Keystone:
	msgbox gText_CeladonFossilReviveOddKeystone MSG_KEEPOPEN
	msgbox gText_CeladonFossilReviveQuestion MSG_YESNO
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_OddKeystone_Revieve
	msgbox gText_CeladonFossilReviveNoResponse MSG_KEEPOPEN
	release
	end

EventScript_Root_Revieve:
	msgbox gText_CeladonFossilReviveYesResponse MSG_KEEPOPEN
	removeitem ITEM_ROOT_FOSSIL
	givepokemon SPECIES_LILEEP 0x19 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_CeladonFossilLileepAquire 0x4
	goto EventScript_FossilOutro

EventScript_Sail_Revieve:
	msgbox gText_CeladonFossilReviveYesResponse MSG_KEEPOPEN
	removeitem ITEM_SAIL_FOSSIL
	givepokemon SPECIES_AMAURA 0x19 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_CeladonFossilAmauraAquire 0x4
	goto EventScript_FossilOutro

EventScript_OddKeystone_Revieve:
	msgbox gText_CeladonFossilReviveYesResponse MSG_KEEPOPEN
	removeitem ITEM_ODD_KEYSTONE
	givepokemon SPECIES_SPIRITOMB 0x19 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_CeladonFossilSpiritombAquire 0x4
	goto EventScript_FossilOutro

EventScript_FossilOutro:
	msgbox gText_CeladonFossilReviveMoreFossiles MSG_KEEPOPEN
	release
	end

EventScript_ChefShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_CeladonChefHello
	waitmsg
	pokemart EventScript_Food_Values
	msgbox gText_CeladonChefGoodbye MSG_KEEPOPEN
	release
	end

EventScript_Food_Values:
	.hword ITEM_TART_APPLE
	.hword ITEM_SWEET_APPLE
	.hword ITEM_WHIPPED_DREAM
	.hword ITEM_CRACKED_POT
	.hword ITEM_STRAWBERRY_SWEET
	.hword ITEM_BERRY_SWEET
	.hword ITEM_LOVE_SWEET
	.hword ITEM_CLOVER_SWEET
	.hword ITEM_FLOWER_SWEET
	.hword ITEM_RIBBON_SWEET
	.hword ITEM_STAR_SWEET
	.hword 0x0

EventScript_BerryShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_CeladonWaitress
	waitmsg
	pokemart EventScript_Berry_Values
	msgbox gText_CeladonChefGoodbye MSG_KEEPOPEN
	release
	end

EventScript_Berry_Values:
	.hword ITEM_ORAN_BERRY
	.hword ITEM_SITRUS_BERRY
	.hword ITEM_CHERI_BERRY
	.hword ITEM_CHESTO_BERRY
	.hword ITEM_PECHA_BERRY
	.hword ITEM_RAWST_BERRY
	.hword ITEM_ASPEAR_BERRY
	.hword ITEM_PERSIM_BERRY
	.hword ITEM_LUM_BERRY
	.hword ITEM_POMEG_BERRY
	.hword ITEM_KELPSY_BERRY
	.hword ITEM_QUALOT_BERRY
	.hword ITEM_HONDEW_BERRY
	.hword ITEM_GREPA_BERRY
	.hword ITEM_TAMATO_BERRY
	.hword ITEM_LIECHI_BERRY
	.hword ITEM_GANLON_BERRY
	.hword ITEM_SALAC_BERRY
	.hword ITEM_PETAYA_BERRY
	.hword ITEM_APICOT_BERRY 
	.hword 0x0




EventScript_BallShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_ShopHello
	waitmsg
	pokemart EventScript_Ball_Values
	msgbox gText_ShopGoodbye MSG_KEEPOPEN
	release
	end

EventScript_Ball_Values:
	.hword ITEM_HEAL_BALL
	.hword ITEM_NET_BALL
	.hword ITEM_DIVE_BALL
	.hword ITEM_NEST_BALL
	.hword ITEM_REPEAT_BALL
	.hword ITEM_TIMER_BALL 
	.hword ITEM_LUXURY_BALL 
	@.hword ITEM_CHERISH_BALL
	.hword ITEM_DUSK_BALL
	.hword ITEM_QUICK_BALL
	.hword ITEM_FAST_BALL
	.hword ITEM_LEVEL_BALL
	.hword ITEM_LURE_BALL
	.hword ITEM_HEAVY_BALL
	.hword ITEM_LOVE_BALL
	.hword ITEM_FRIEND_BALL
	.hword ITEM_MOON_BALL
	@.hword ITEM_SPORT_BALL
	@.hword ITEM_PARK_BALL
	.hword 0x0

EventScript_EvoItemShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_ShopHello
	waitmsg
	pokemart EventScript_EvoItem_Values
	msgbox gText_ShopGoodbye MSG_KEEPOPEN
	release
	end

EventScript_EvoItem_Values:
	.hword ITEM_LINK_CABLE
	.hword ITEM_UPGRADE
	.hword ITEM_DUBIOUS_DISC
	.hword ITEM_DRAGON_SCALE
	.hword ITEM_RAZOR_CLAW
	.hword 0x0

EventScript_EvoStoneShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_ShopHello
	waitmsg
	pokemart EventScript_EvoStone_Values
	msgbox gText_ShopGoodbye MSG_KEEPOPEN
	release
	end

EventScript_EvoStone_Values:
	.hword ITEM_FIRE_STONE
	.hword ITEM_THUNDER_STONE
	.hword ITEM_WATER_STONE
	.hword ITEM_LEAF_STONE
	.hword ITEM_SHINY_STONE
	.hword ITEM_DUSK_STONE
	.hword ITEM_DAWN_STONE
	.hword ITEM_ICE_STONE
	.hword ITEM_SUN_STONE 
	.hword ITEM_MOON_STONE 
	.hword 0x0

EventScript_IncenseShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_ShopHello
	waitmsg
	pokemart EventScript_Incense_Values
	msgbox gText_ShopGoodbye MSG_KEEPOPEN
	release
	end

EventScript_Incense_Values:
	.hword ITEM_SEA_INCENSE
	.hword ITEM_LAX_INCENSE
	@.hword ITEM_LUCK_INCENSE
	@.hword ITEM_FULL_INCENSE
	@.hword ITEM_ODD_INCENSE
	@.hword ITEM_PURE_INCENSE
	@.hword ITEM_ROCK_INCENSE
	@.hword ITEM_ROSE_INCENSE
	@.hword ITEM_WAVE_INCENSE
	.hword 0x0

EventScript_GameCornerItemShop:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_shop_End
	lock
	faceplayer
	preparemsg gText_ShopHello
	waitmsg
	pokemart EventScript_GameCornerItem_Values
	msgbox gText_ShopGoodbye MSG_KEEPOPEN
	release
	end

EventScript_GameCornerItem_Values:
	.hword ITEM_SMOKE_BALL
	.hword ITEM_MIRACLE_SEED
	.hword ITEM_CHARCOAL
	.hword ITEM_MYSTIC_WATER
	.hword ITEM_YELLOW_FLUTE
	.hword 0x0


EventScript_GameCornerMonsShop:
	lockall
	faceplayer
	msgbox gText_GameCornerMons MSG_KEEPOPEN
	showmoney 0x35 0x00 0x00

	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_GameCornerMaractus
	special 0x25

	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_GameCornerPorygon
	special 0x25

	setvar 0x8006 0x2 @3rd item
	loadpointer 0x0 gText_GameCornerBeldum
	special 0x25

	setvar 0x8006 0x3 @3rd item
	loadpointer 0x0 gText_GameCornerExit @Exit 
	special 0x25

	preparemsg gText_gamecornermons_Whichpkmn
	waitmsg
	multichoice 0x0 0x0 0x22 0x0 @0x22 is 3 options

	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_GameCornerMaractus
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_GameCornerPorygon
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_GameCornerBeldum
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_GameCornerEnd
	release
	end

EventScript_GameCornerMaractus:
	msgbox gText_GameCornerBuyMaractus MSG_YESNO
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_GameCornerEnd
	call EventScript_GameCornerCheckPaymentMaractus
	givepokemon SPECIES_MARACTUS 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_GameCornerGotMaractus MSG_KEEPOPEN
	goto EventScript_GameCornerEnd

EventScript_GameCornerPorygon:
	msgbox gText_GameCornerBuyPorygon MSG_YESNO
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_GameCornerEnd
	call EventScript_GameCornerCheckPaymentPorygon
	givepokemon SPECIES_PORYGON 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_GameCornerGotPorygon MSG_KEEPOPEN
	goto EventScript_GameCornerEnd

EventScript_GameCornerBeldum:
	msgbox gText_GameCornerBuyBeldum MSG_YESNO
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_GameCornerEnd
	call EventScript_GameCornerCheckPaymentBeldum
	givepokemon SPECIES_BELDUM 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_GameCornerGotBeldum MSG_KEEPOPEN
	goto EventScript_GameCornerEnd

EventScript_GameCornerEnd:
	hidemoney 0x35 0x00
	release
	end

EventScript_GameCornerCheckPaymentMaractus:
	checkmoney 0x2710 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_GameCornerNotEnoughMoney
	msgbox gText_GameCornerWait MSG_KEEPOPEN
	removemoney 0x2710 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_GameCornerThanks MSG_KEEPOPEN
	checksound
	return

EventScript_GameCornerCheckPaymentPorygon:
	checkmoney 0x3A98 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_GameCornerNotEnoughMoney
	msgbox gText_GameCornerWait MSG_KEEPOPEN
	removemoney 0x3A98 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_GameCornerThanks MSG_KEEPOPEN
	checksound
	return

EventScript_GameCornerCheckPaymentBeldum:
	checkmoney 0x4E20 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_GameCornerNotEnoughMoney
	msgbox gText_GameCornerWait MSG_KEEPOPEN
	removemoney 0x4E20 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_GameCornerThanks MSG_KEEPOPEN
	checksound
	return


EventScript_GameCornerNotEnoughMoney:
	msgbox gText_GameCornerNotEnoughMoney MSG_KEEPOPEN
	hidemoney 0x35 0x00
	release
	end