#include "../config.h"
#include "../../include/global.h"
#include "../../include/constants/maps.h"
#include "../../include/wild_encounter.h"
#include "../../include/constants/region_map_sections.h"
#include "../../include/constants/species.h"

/*
wild_encounter_tables.c
	day/night and/or regular map wild encounter species

tables to edit:
	gWildMonMorningHeaders
	gWildMonEveningHeaders
	gWildMonNightHeaders
	gSwarmTable

*/

#ifndef UNBOUND //Modify this section

static const struct WildPokemon gPalletTown_SurfMons[] = 
{
  {36, 58, SPECIES_TENTACOOL},
  {36, 58, SPECIES_TENTACOOL},
  {46, 58, SPECIES_TENTACRUEL},
  {46, 58, SPECIES_TENTACRUEL},
  {46, 58, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gPalletTown_SurfMonsInfo = {5, gPalletTown_SurfMons};


static const struct WildPokemon gPalletTown_FishingMons[] = 
{
  {2, 4, SPECIES_MAGIKARP},
  {2, 4, SPECIES_CHINCHOU},
  {15, 29, SPECIES_MAGIKARP},
  {15, 29, SPECIES_CHINCHOU},
  {15, 29, SPECIES_CHINCHOU},
  {35, 55, SPECIES_LANTURN},
  {35, 55, SPECIES_LANTURN},
  {35, 55, SPECIES_LANTURN},
  {35, 55, SPECIES_GYARADOS},
  {35, 55, SPECIES_GYARADOS},
};
static const struct WildPokemonInfo gPalletTown_FishingMonsInfo = {5, gPalletTown_FishingMons};


static const struct WildPokemon gRoute1_LandMons[] = 
{
  {2, 4, SPECIES_PIDGEY},		//Chance: 20%
  {2, 4, SPECIES_BIDOOF},		//Chance: 20%
  {2, 4, SPECIES_PIDGEY},		//Chance: 10%
  {2, 4, SPECIES_BIDOOF},		//Chance: 10%
  {2, 4, SPECIES_PIDGEY},		//Chance: 10%
  {2, 4, SPECIES_BIDOOF},		//Chance: 10%
  {3, 5, SPECIES_SUNKERN},		//Chance: 5%
  {3, 5, SPECIES_ODDISH},		//Chance: 5%
  {2, 4, SPECIES_PIDGEY},		//Chance: 4%
  {2, 4, SPECIES_BIDOOF},		//Chance: 4%
  {2, 4, SPECIES_SUNKERN},		//Chance: 1%
  {2, 4, SPECIES_ODDISH},		//Chance: 1%
};
static const struct WildPokemonInfo gRoute1_LandMonsInfo = {20, gRoute1_LandMons};



static const struct WildPokemon gViridianCity_SurfMons[] = 
{
  {30, 45, SPECIES_MAGIKARP},
  {32, 45, SPECIES_LUMINEON},
  {30, 45, SPECIES_MAGIKARP},
  {32, 50, SPECIES_LUMINEON},
  {30, 50, SPECIES_QUAGSIRE},
};
static const struct WildPokemonInfo gViridianCity_SurfMonsInfo = {5, gViridianCity_SurfMons};


static const struct WildPokemon gViridianCity_FishingMons[] = 
{
  {2, 4, SPECIES_MAGIKARP},
  {2, 4, SPECIES_FINNEON},
  {15, 25, SPECIES_MAGIKARP},
  {15, 25, SPECIES_FINNEON},
  {15, 25, SPECIES_WOOPER},
  {35, 55, SPECIES_LUMINEON},
  {35, 55, SPECIES_MAGIKARP},
  {35, 55, SPECIES_LUMINEON},
  {35, 55, SPECIES_QUAGSIRE},
  {35, 55, SPECIES_QUAGSIRE},
};
static const struct WildPokemonInfo gViridianCity_FishingMonsInfo = {5, gViridianCity_FishingMons};



static const struct WildPokemon gRoute22_LandMons[] = 
{
  {3, 5, SPECIES_BUNNELBY},		//Chance: 20%
  {3, 5, SPECIES_WOOLOO},		//Chance: 20%
  {3, 5, SPECIES_BUNNELBY},		//Chance: 10%
  {3, 5, SPECIES_MANKEY},		//Chance: 10%
  {3, 5, SPECIES_HOOTHOOT},		//Chance: 10%
  {3, 5, SPECIES_MANKEY},		//Chance: 10%
  {3, 5, SPECIES_WOOLOO},		//Chance: 5%
  {3, 5, SPECIES_WOOLOO},		//Chance: 5%
  {3, 5, SPECIES_HOOTHOOT},		//Chance: 4%
  {3, 5, SPECIES_NICKIT},		//Chance: 4%
  {3, 5, SPECIES_NICKIT},		//Chance: 1%
  {3, 5, SPECIES_NICKIT},		//Chance: 1%
};
static const struct WildPokemonInfo gRoute22_LandMonsInfo = {20, gRoute22_LandMons};



static const struct WildPokemon gRoute22_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_TENTACRUEL},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute22_SurfMonsInfo = {5, gRoute22_SurfMons};


static const struct WildPokemon gRoute22_FishingMons[] = 
{
  {2, 4, SPECIES_MAGIKARP},
  {2, 4, SPECIES_FINNEON},
  {27, 29, SPECIES_MAGIKARP},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute22_FishingMonsInfo = {5, gRoute22_FishingMons};


static const struct WildPokemon gRoute2_LandMons[] = 
{
  {4, 6, SPECIES_POOCHYENA},   //Chance: 20%
  {4, 6, SPECIES_TAILLOW},   //Chance: 20%
  {4, 6, SPECIES_NIDORAN_M},   //Chance: 10%
  {4, 6, SPECIES_NIDORAN_F},   //Chance: 10%
  {3, 6, SPECIES_POOCHYENA},   //Chance: 10%
  {3, 6, SPECIES_TAILLOW},   //Chance: 10%
  {3, 5, SPECIES_HOOTHOOT},   //Chance: 5%
  {3, 5, SPECIES_AZURILL},   //Chance: 5%
  {3, 5, SPECIES_NIDORAN_M},   //Chance: 4%
  {3, 5, SPECIES_NIDORAN_F},   //Chance: 4%
  {3, 5, SPECIES_HOOTHOOT},   //Chance: 1%
  {3, 5, SPECIES_AZURILL},   //Chance: 1%
};
static const struct WildPokemonInfo gRoute2_LandMonsInfo= {20, gRoute2_LandMons};


static const struct WildPokemon gViridianForest_LandMons[] = 
{
  {4, 6, SPECIES_KRICKETOT},   //Chance: 20%
  {4, 6, SPECIES_BLIPBUG},   //Chance: 20%
  {4, 6, SPECIES_COMBEE},   //Chance: 10%
  {4, 6, SPECIES_SEWADDLE},   //Chance: 10%
  {4, 6, SPECIES_SHROOMISH},   //Chance: 10%
  {4, 6, SPECIES_SHROOMISH},   //Chance: 10%
  {4, 6, SPECIES_COMBEE},   //Chance: 5%
  {4, 6, SPECIES_SEWADDLE},   //Chance: 5%
  {5, 9, SPECIES_DOTTLER},   //Chance: 4%
  {5, 7, SPECIES_PHANTUMP},   //Chance: 4%
  {5, 9, SPECIES_DOTTLER},   //Chance: 1%
  {5, 7, SPECIES_PHANTUMP},   //Chance: 1%
};
static const struct WildPokemonInfo gViridianForest_LandMonsInfo= {20, gViridianForest_LandMons};

static const struct WildPokemon gRoute3_LandMons[] = 
{
  {8, 12, SPECIES_WHISMUR},   //Chance: 20%
  {8, 12, SPECIES_MAREEP},   //Chance: 20% 
  {8, 12, SPECIES_GLAMEOW},   //Chance: 10% 
  {8, 12, SPECIES_JIGGLYPUFF},   //Chance: 10% 
  {8, 12, SPECIES_GLAMEOW},   //Chance: 10% 
  {8, 12, SPECIES_JIGGLYPUFF},   //Chance: 10% 
  {8, 12, SPECIES_AIPOM},   //Chance: 5%
  {8, 12, SPECIES_AIPOM},   //Chance: 5%
  {8, 12, SPECIES_MURKROW},   //Chance: 4%
  {8, 12, SPECIES_MURKROW},   //Chance: 4%
  {8, 12, SPECIES_MURKROW},   //Chance: 1%
  {8, 12, SPECIES_MURKROW},   //Chance: 1%
};
static const struct WildPokemonInfo gRoute3_LandMonsInfo= {20, gRoute3_LandMons};

static const struct WildPokemon gMTMoon1F_LandMons[] = 
{
  {10, 14, SPECIES_GEODUDE},   //Chance: 20% 
  {10, 14, SPECIES_ZUBAT},   //Chance: 20% 
  {10, 14, SPECIES_SANDSHREW},   //Chance: 10% 
  {10, 14, SPECIES_ARON},   //Chance: 10% 
  {10, 14, SPECIES_GEODUDE},   //Chance: 10% 
  {10, 14, SPECIES_ZUBAT},   //Chance: 10% 
  {10, 14, SPECIES_SANDSHREW},   //Chance: 5%
  {10, 14, SPECIES_ARON},   //Chance: 5%
  {10, 14, SPECIES_GEODUDE},   //Chance: 4%
  {10, 14, SPECIES_ZUBAT},   //Chance: 4%
  {10, 14, SPECIES_SANDSHREW},   //Chance: 1%
  {10, 14, SPECIES_ARON},   //Chance: 1%
};
static const struct WildPokemonInfo gMTMoon1F_LandMonsInfo= {4, gMTMoon1F_LandMons};

static const struct WildPokemon gMTMoonB1F_LandMons[] = 
{
  {10, 14, SPECIES_WOOBAT},   //Chance: 20% Woobat
  {10, 14, SPECIES_PARAS},   //Chance: 20% 
  {10, 14, SPECIES_WOOBAT},   //Chance: 10% 
  {10, 14, SPECIES_PARAS},   //Chance: 10% 
  {10, 14, SPECIES_WOOBAT},   //Chance: 10% 
  {10, 14, SPECIES_PARAS},   //Chance: 10% 
  {10, 14, SPECIES_WOOBAT},   //Chance: 5%
  {10, 14, SPECIES_PARAS},   //Chance: 5%
  {10, 14, SPECIES_WOOBAT},   //Chance: 4%
  {10, 14, SPECIES_PARAS},   //Chance: 4%
  {10, 14, SPECIES_WOOBAT},   //Chance: 1%
  {10, 14, SPECIES_PARAS},   //Chance: 1%
};
static const struct WildPokemonInfo gMTMoonB1F_LandMonsInfo= {4, gMTMoonB1F_LandMons};

static const struct WildPokemon gMTMoonB2F_LandMons[] = 
{
  {10, 14, SPECIES_ROGGENROLA},   //Chance: 20% Roggenrola
  {10, 14, SPECIES_NOIBAT},   //Chance: 20% noibat
  {10, 14, SPECIES_ROGGENROLA},   //Chance: 10% clefairy
  {10, 14, SPECIES_NOIBAT},   //Chance: 10% elgyem
  {10, 14, SPECIES_CLEFAIRY},   //Chance: 10% 
  {10, 14, SPECIES_ELGYEM},   //Chance: 10% 
  {10, 14, SPECIES_ROGGENROLA},   //Chance: 5%
  {10, 14, SPECIES_NOIBAT},   //Chance: 5%
  {10, 14, SPECIES_CLEFAIRY},   //Chance: 4%
  {10, 14, SPECIES_ELGYEM},   //Chance: 4%
  {10, 14, SPECIES_CLEFAIRY},   //Chance: 1%
  {10, 14, SPECIES_ELGYEM},   //Chance: 1%
};
static const struct WildPokemonInfo gMTMoonB2F_LandMonsInfo= {4, gMTMoonB2F_LandMons};

static const struct WildPokemon gRoute4_LandMons[] = 
{
  {12, 16, SPECIES_LITLEO},   //Chance: 20% 
  {12, 16, SPECIES_SPOINK},   //Chance: 20% 
  {12, 16, SPECIES_LITLEO},   //Chance: 10% 
  {12, 16, SPECIES_SPOINK},   //Chance: 10% 
  {12, 16, SPECIES_NATU},   //Chance: 10% 
  {12, 16, SPECIES_WOOPER},   //Chance: 10% 
  {12, 16, SPECIES_NATU},   //Chance: 5%
  {12, 16, SPECIES_WOOPER},   //Chance: 5%
  {12, 16, SPECIES_NATU},   //Chance: 4%
  {12, 16, SPECIES_SHINX},   //Chance: 4%
  {12, 16, SPECIES_NATU},   //Chance: 1%
  {12, 16, SPECIES_SHINX},   //Chance: 1%
};
static const struct WildPokemonInfo gRoute4_LandMonsInfo= {20, gRoute4_LandMons};

static const struct WildPokemon gRoute4_SurfMons[] = 
{
  {35, 58, SPECIES_STARYU},
  {35, 58, SPECIES_WOOPER},
  {35, 58, SPECIES_STARYU},
  {45, 58, SPECIES_STARMIE},
  {56, 58, SPECIES_QUAGSIRE},
};
static const struct WildPokemonInfo gRoute4_SurfMonsInfo = {5, gRoute4_SurfMons};


static const struct WildPokemon gRoute4_FishingMons[] = 
{
  {5, 15, SPECIES_STARYU},
  {5, 15, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {27, 29, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gRoute4_FishingMonsInfo = {5, gRoute4_FishingMons};

static const struct WildPokemon gCeruleanCity_SurfMons[] = 
{
  {35, 58, SPECIES_STARYU},
  {35, 58, SPECIES_WOOPER},
  {35, 58, SPECIES_STARYU},
  {45, 58, SPECIES_STARMIE},
  {56, 58, SPECIES_QUAGSIRE},
};
static const struct WildPokemonInfo gCeruleanCity_SurfMonsInfo = {5, gCeruleanCity_SurfMons};


static const struct WildPokemon gCeruleanCity_FishingMons[] = 
{
  {5, 15, SPECIES_HORSEA},
  {5, 15, SPECIES_REMORAID},
  {27, 29, SPECIES_HORSEA},
  {27, 29, SPECIES_REMORAID},
  {27, 29, SPECIES_HORSEA},
  {33, 55, SPECIES_SEADRA},
  {33, 55, SPECIES_OCTILLERY},
  {33, 55, SPECIES_OCTILLERY},
  {33, 55, SPECIES_SEADRA},
  {33, 55, SPECIES_SEADRA},
};
static const struct WildPokemonInfo gCeruleanCity_FishingMonsInfo = {5, gCeruleanCity_FishingMons};


static const struct WildPokemon gRoute24_LandMons[] = 
{
  {13, 17, SPECIES_PETILIL},         //Chance: 20% 
  {13, 17, SPECIES_FLABEBE},         //Chance: 20% 
  {13, 17, SPECIES_PETILIL},         //Chance: 10% 
  {13, 17, SPECIES_FLABEBE},         //Chance: 10% 
  {13, 17, SPECIES_CUTIEFLY},         //Chance: 10% 
  {13, 17, SPECIES_ABRA},             //Chance: 10% 
  {13, 17, SPECIES_CUTIEFLY},         //Chance: 5%
  {13, 17, SPECIES_ABRA},         //Chance: 5%
  {13, 17, SPECIES_GOOMY},         //Chance: 4%
  {13, 17, SPECIES_CUTIEFLY},         //Chance: 4%
  {13, 17, SPECIES_CUTIEFLY},         //Chance: 1%
  {13, 17, SPECIES_ABRA},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute24_LandMonsInfo= {20, gRoute24_LandMons};

static const struct WildPokemon gRoute24_SurfMons[] = 
{
  {35, 58, SPECIES_STARYU},
  {35, 58, SPECIES_WOOPER},
  {35, 58, SPECIES_STARYU},
  {45, 58, SPECIES_STARMIE},
  {56, 58, SPECIES_QUAGSIRE},
};
static const struct WildPokemonInfo gRoute24_SurfMonsInfo = {5, gRoute24_SurfMons};


static const struct WildPokemon gRoute24_FishingMons[] = 
{
  {5, 15, SPECIES_STARYU},
  {5, 15, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {27, 29, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gRoute24_FishingMonsInfo = {5, gRoute24_FishingMons};


static const struct WildPokemon gRoute25_LandMons[] = 
{
  {14, 18, SPECIES_HOUNDOUR},         //Chance: 20% Inkay
  {14, 18, SPECIES_GOTHITA},         //Chance: 20% Applin
  {14, 18, SPECIES_HOUNDOUR},         //Chance: 10% Houndoor
  {14, 18, SPECIES_GOTHITA},         //Chance: 10% Numel
  {14, 18, SPECIES_NUMEL},         //Chance: 10% Gothita
  {14, 18, SPECIES_NUMEL},             //Chance: 10% 
  {14, 18, SPECIES_INKAY},         //Chance: 5%
  {14, 18, SPECIES_GOTHITA},         //Chance: 5%
  {14, 18, SPECIES_NUMEL},         //Chance: 4%
  {14, 18, SPECIES_APPLIN},         //Chance: 4%
  {14, 18, SPECIES_NUMEL},         //Chance: 1%
  {14, 18, SPECIES_APPLIN},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute25_LandMonsInfo= {20, gRoute25_LandMons};

static const struct WildPokemon gRoute25_SurfMons[] = 
{
  {35, 58, SPECIES_STARYU},
  {35, 58, SPECIES_WOOPER},
  {35, 58, SPECIES_STARYU},
  {45, 58, SPECIES_STARMIE},
  {56, 58, SPECIES_QUAGSIRE},
};
static const struct WildPokemonInfo gRoute25_SurfMonsInfo = {5, gRoute25_SurfMons};


static const struct WildPokemon gRoute25_FishingMons[] = 
{
  {5, 15, SPECIES_STARYU},
  {5, 15, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {27, 29, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gRoute25_FishingMonsInfo = {5, gRoute25_FishingMons};


static const struct WildPokemon gRoute5_LandMons[] = 
{
  {17, 20, SPECIES_MEOWTH},         //Chance: 20% Meowth
  {17, 20, SPECIES_STUFFUL},         //Chance: 20% Stufful
  {17, 20, SPECIES_MEOWTH},         //Chance: 10% Salandit
  {17, 20, SPECIES_STUFFUL},         //Chance: 10% Tyrogue
  {17, 20, SPECIES_SALANDIT},         //Chance: 10% Milcery
  {17, 20, SPECIES_TYROGUE},         //Chance: 10% Teddiursa
  {17, 20, SPECIES_SALANDIT},         //Chance: 5%
  {17, 20, SPECIES_TYROGUE},         //Chance: 5%
  {17, 20, SPECIES_TEDDIURSA},         //Chance: 4%
  {17, 20, SPECIES_MILCERY},         //Chance: 4%
  {17, 20, SPECIES_TEDDIURSA},         //Chance: 1%
  {17, 20, SPECIES_MILCERY},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute5_LandMonsInfo= {20, gRoute5_LandMons};



static const struct WildPokemon gRoute6_LandMons[] = 
{
  {17, 20, SPECIES_MARILL},         //Chance: 20% helioptile
  {17, 20, SPECIES_MEDITITE},         //Chance: 20% meditite
  {17, 20, SPECIES_MARILL},         //Chance: 10% croagunk
  {17, 20, SPECIES_MEDITITE},         //Chance: 10% sandygast
  {17, 20, SPECIES_CROAGUNK},         //Chance: 10% Maril
  {17, 20, SPECIES_HELIOPTILE},         //Chance: 10% 
  {17, 20, SPECIES_CROAGUNK},         //Chance: 5%
  {17, 20, SPECIES_HELIOPTILE},         //Chance: 5%
  {17, 20, SPECIES_CROAGUNK},         //Chance: 4%
  {17, 20, SPECIES_SANDYGAST},         //Chance: 4%
  {17, 20, SPECIES_SANDYGAST},         //Chance: 1%
  {17, 20, SPECIES_SANDYGAST},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute6_LandMonsInfo= {20, gRoute6_LandMons};

static const struct WildPokemon gRoute6_SurfMons[] = 
{
  {35, 58, SPECIES_MARILL},
  {35, 58, SPECIES_AZUMARILL},
  {35, 58, SPECIES_LUMINEON},
  {45, 58, SPECIES_AZUMARILL},
  {56, 58, SPECIES_LUMINEON},
};
static const struct WildPokemonInfo gRoute6_SurfMonsInfo = {5, gRoute6_SurfMons};


static const struct WildPokemon gRoute6_FishingMons[] = 
{
  {10, 15, SPECIES_FINNEON},
  {10, 15, SPECIES_MARILL},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_MARILL},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_AZUMARILL},
  {33, 55, SPECIES_AZUMARILL},
};
static const struct WildPokemonInfo gRoute6_FishingMonsInfo = {5, gRoute6_FishingMons};


static const struct WildPokemon gVermillionCity_SurfMons[] = 
{
  {35, 58, SPECIES_SKRELP},
  {35, 58, SPECIES_DRAGALGE},
  {35, 58, SPECIES_TENTACOOL},
  {45, 58, SPECIES_TENTACOOL},
  {56, 58, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gVermillionCity_SurfMonsInfo = {5, gVermillionCity_SurfMons};


static const struct WildPokemon gVermillionCity_FishingMons[] = 
{
  {10, 15, SPECIES_SKRELP},
  {10, 15, SPECIES_BINACLE},
  {27, 29, SPECIES_SKRELP},
  {27, 29, SPECIES_BINACLE},
  {27, 29, SPECIES_BINACLE},
  {33, 55, SPECIES_DRAGALGE},
  {33, 55, SPECIES_DHELMISE},
  {33, 55, SPECIES_BARBARACLE},
  {33, 55, SPECIES_DHELMISE},
  {33, 55, SPECIES_BARBARACLE},
};
static const struct WildPokemonInfo gVermillionCity_FishingMonsInfo = {5, gVermillionCity_FishingMons};


static const struct WildPokemon gRoute11_LandMons[] = 
{
  {17, 20, SPECIES_PANCHAM},         //Chance: 20% Miltank
  {17, 20, SPECIES_DROWZEE},         //Chance: 20% Mawile
  {17, 20, SPECIES_PANCHAM},         //Chance: 10% Pancham
  {17, 20, SPECIES_DROWZEE},         //Chance: 10% Espurr
  {17, 20, SPECIES_MILTANK},         //Chance: 10% Hawlucha
  {17, 20, SPECIES_MAWILE},         //Chance: 10% 
  {17, 20, SPECIES_PANCHAM},         //Chance: 5%
  {17, 20, SPECIES_DROWZEE},         //Chance: 5%
  {17, 20, SPECIES_HAWLUCHA},         //Chance: 4%
  {17, 20, SPECIES_HAWLUCHA},         //Chance: 4%
  {17, 20, SPECIES_MILTANK},         //Chance: 1%
  {17, 20, SPECIES_MAWILE},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute11_LandMonsInfo= {20, gRoute11_LandMons};


static const struct WildPokemon gDiglettsCaveEntrance_LandMons[] = 
{
  {17, 20, SPECIES_DIGLETT},         //Chance: 20% Diglet
  {17, 20, SPECIES_DIGLETT},         //Chance: 20% Dugtrio
  {17, 20, SPECIES_DIGLETT},         //Chance: 10% Stunfisk
  {17, 20, SPECIES_DIGLETT},         //Chance: 10% Hippopatas
  {17, 20, SPECIES_DIGLETT},         //Chance: 10% Silcobra
  {17, 20, SPECIES_DIGLETT},         //Chance: 10% 
  {17, 20, SPECIES_DIGLETT},         //Chance: 5%
  {17, 20, SPECIES_DIGLETT},         //Chance: 5%
  {17, 20, SPECIES_DIGLETT},         //Chance: 4%
  {17, 20, SPECIES_DUGTRIO},         //Chance: 4%
  {17, 20, SPECIES_DUGTRIO},         //Chance: 1%
  {17, 20, SPECIES_DUGTRIO},         //Chance: 1%
};

static const struct WildPokemonInfo gDiglettsCaveEntrance_LandMonsInfo = {4, gDiglettsCaveEntrance_LandMons};


static const struct WildPokemon gDiglettsCaveB1F_LandMons[] = 
{
  {17, 20, SPECIES_DIGLETT},         //Chance: 20% 
  {17, 20, SPECIES_SILICOBRA},         //Chance: 20% 
  {17, 20, SPECIES_DIGLETT},         //Chance: 10% 
  {17, 20, SPECIES_SILICOBRA},         //Chance: 10% 
  {17, 20, SPECIES_HIPPOPOTAS},         //Chance: 10% 
  {17, 20, SPECIES_HIPPOPOTAS},         //Chance: 10% 
  {17, 20, SPECIES_DIGLETT},         //Chance: 5%
  {17, 20, SPECIES_DUGTRIO},         //Chance: 5%
  {17, 20, SPECIES_SILICOBRA},         //Chance: 4%
  {17, 20, SPECIES_STUNFISK},         //Chance: 4%
  {17, 20, SPECIES_STUNFISK},         //Chance: 1%
  {17, 20, SPECIES_STUNFISK},         //Chance: 1%
};

static const struct WildPokemonInfo gDiglettsCaveB1F_LandMonsInfo = {4, gDiglettsCaveB1F_LandMons};


static const struct WildPokemon gRoute9_LandMons[] = 
{
  {20, 25, SPECIES_VENIPEDE},         //Chance: 20% Durant
  {20, 25, SPECIES_DURANT},         //Chance: 20% Volbeat
  {20, 25, SPECIES_VENIPEDE},         //Chance: 10% Illumise
  {20, 25, SPECIES_DURANT},         //Chance: 10% 
  {20, 25, SPECIES_VOLBEAT},         //Chance: 10% Venipede
  {20, 25, SPECIES_ILLUMISE},         //Chance: 10% Heatmore
  {20, 25, SPECIES_VOLBEAT},         //Chance: 5%
  {20, 25, SPECIES_ILLUMISE},         //Chance: 5%
  {20, 25, SPECIES_HEATMOR},         //Chance: 4%
  {20, 25, SPECIES_HEATMOR},         //Chance: 4%
  {22, 27, SPECIES_WHIRLIPEDE},         //Chance: 1%
  {22, 27, SPECIES_WHIRLIPEDE},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute9_LandMonsInfo= {20, gRoute9_LandMons};


static const struct WildPokemon gRoute10_LandMons[] = 
{
  {20, 25, SPECIES_MAGNEMITE},         //Chance: 20% Tynamo
  {20, 25, SPECIES_YAMPER},         //Chance: 20% Magnemite
  {20, 25, SPECIES_MAGNEMITE},         //Chance: 10% 
  {20, 25, SPECIES_YAMPER},         //Chance: 10% Yamper
  {20, 25, SPECIES_TYNAMO},         //Chance: 10% 
  {20, 25, SPECIES_YAMPER},         //Chance: 10% 
  {20, 25, SPECIES_MAGNEMITE},         //Chance: 5%
  {20, 25, SPECIES_BRONZOR},         //Chance: 5%
  {20, 25, SPECIES_TYNAMO},         //Chance: 4%
  {20, 25, SPECIES_TYNAMO},         //Chance: 4%
  {22, 27, SPECIES_BRONZOR},         //Chance: 1%
  {22, 27, SPECIES_BRONZOR},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute10_LandMonsInfo= {20, gRoute10_LandMons};

static const struct WildPokemon gRoute10_SurfMons[] = 
{
  {35, 58, SPECIES_ALOMOMOLA},
  {35, 58, SPECIES_ALOMOMOLA},
  {35, 58, SPECIES_GYARADOS},
  {45, 58, SPECIES_GYARADOS},
  {56, 58, SPECIES_GYARADOS},
};
static const struct WildPokemonInfo gRoute10_SurfMonsInfo = {5, gRoute10_SurfMons};


static const struct WildPokemon gRoute10_FishingMons[] = 
{
  {15, 20, SPECIES_ALOMOMOLA},
  {15, 20, SPECIES_MAGIKARP},
  {27, 29, SPECIES_ALOMOMOLA},
  {27, 29, SPECIES_MAGIKARP},
  {27, 29, SPECIES_GYARADOS},
  {33, 55, SPECIES_ALOMOMOLA},
  {33, 55, SPECIES_ALOMOMOLA},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
};
static const struct WildPokemonInfo gRoute10_FishingMonsInfo = {5, gRoute10_FishingMons};



static const struct WildPokemon gRockTunnel1F_LandMons[] = 
{
  {22, 27, SPECIES_GRAVELER},         //Chance: 20% Sneasel
  {22, 27, SPECIES_LOUDRED},         //Chance: 20% Druddigon
  {22, 27, SPECIES_GRAVELER},         //Chance: 10% Loudred
  {22, 27, SPECIES_LOUDRED},         //Chance: 10% Gravler
  {22, 27, SPECIES_SNEASEL},         //Chance: 10% Solrock
  {22, 27, SPECIES_SNEASEL},         //Chance: 10% 
  {22, 27, SPECIES_GRAVELER},         //Chance: 5%
  {22, 27, SPECIES_SOLROCK},         //Chance: 5%
  {22, 27, SPECIES_DRUDDIGON},         //Chance: 4%
  {22, 27, SPECIES_DRUDDIGON},         //Chance: 4%
  {22, 27, SPECIES_MINIOR_SHIELD},         //Chance: 1%
  {22, 27, SPECIES_MINIOR_SHIELD},         //Chance: 1%
};
static const struct WildPokemonInfo gRockTunnel1F_LandMonsInfo = {4, gRockTunnel1F_LandMons};

static const struct WildPokemon gRockTunnelB1F_LandMons[] = 
{
  {22, 27, SPECIES_BOLDORE},         //Chance: 20% Deino
  {22, 27, SPECIES_DIGGERSBY},         //Chance: 20% Golett
  {22, 27, SPECIES_BOLDORE},         //Chance: 10% Diggersby
  {22, 27, SPECIES_DIGGERSBY},         //Chance: 10% Boldore
  {22, 27, SPECIES_GOLETT},         //Chance: 10% Lunatone
  {22, 27, SPECIES_GOLETT},         //Chance: 10% 
  {22, 27, SPECIES_BOLDORE},         //Chance: 5%
  {22, 27, SPECIES_LUNATONE},         //Chance: 5%
  {22, 27, SPECIES_DEINO},         //Chance: 4%
  {22, 27, SPECIES_DEINO},         //Chance: 4%
  {22, 27, SPECIES_MINIOR_SHIELD},         //Chance: 1%
  {22, 27, SPECIES_MINIOR_SHIELD},         //Chance: 1%
};
static const struct WildPokemonInfo gRockTunnelB1F_LandMonsInfo = {4, gRockTunnelB1F_LandMons};



static const struct WildPokemon gPokemonTower3F_LandMons[] = 
{
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Ghastly
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Haunter
  {24, 29, SPECIES_GASTLY},         //Chance: 10% Litwick
  {24, 29, SPECIES_GASTLY},         //Chance: 10% Shuppet
  {24, 29, SPECIES_GASTLY},         //Chance: 10% Misdreavus
  {24, 29, SPECIES_SHUPPET},         //Chance: 10% Yamask
  {24, 29, SPECIES_GASTLY},         //Chance: 5%
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 5%
  {24, 29, SPECIES_SHUPPET},         //Chance: 4%
  {24, 29, SPECIES_LITWICK},         //Chance: 4%
  {24, 29, SPECIES_YAMASK},         //Chance: 1%
  {24, 29, SPECIES_YAMASK},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonTower3F_LandMonsInfo = {2, gPokemonTower3F_LandMons};

static const struct WildPokemon gPokemonTower4F_LandMons[] = 
{
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Ghastly
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Haunter
  {24, 29, SPECIES_GASTLY},         //Chance: 10% Litwick
  {24, 29, SPECIES_SHUPPET},         //Chance: 10% Shuppet
  {24, 29, SPECIES_SHUPPET},         //Chance: 10% Misdreavus
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Yamask
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 5%
  {24, 29, SPECIES_LITWICK},         //Chance: 5%
  {24, 29, SPECIES_LITWICK},         //Chance: 4%
  {24, 29, SPECIES_YAMASK},         //Chance: 4%
  {24, 29, SPECIES_YAMASK},         //Chance: 1%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonTower4F_LandMonsInfo = {4, gPokemonTower4F_LandMons};

static const struct WildPokemon gPokemonTower5F_LandMons[] = 
{
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Ghastly
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Haunter
  {24, 29, SPECIES_SHUPPET},         //Chance: 10% Litwick
  {24, 29, SPECIES_SHUPPET},         //Chance: 10% Shuppet
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Misdreavus
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Yamask
  {24, 29, SPECIES_LITWICK},         //Chance: 5%
  {24, 29, SPECIES_LITWICK},         //Chance: 5%
  {24, 29, SPECIES_YAMASK},         //Chance: 4%
  {24, 29, SPECIES_YAMASK},         //Chance: 4%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonTower5F_LandMonsInfo = {6, gPokemonTower5F_LandMons};

static const struct WildPokemon gPokemonTower6F_LandMons[] = 
{
  {24, 29, SPECIES_GASTLY},         //Chance: 20% Ghastly
  {24, 29, SPECIES_SHUPPET},         //Chance: 20% Haunter
  {24, 29, SPECIES_SHUPPET},         //Chance: 10% Litwick
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Shuppet
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Misdreavus
  {24, 29, SPECIES_LITWICK},         //Chance: 10% Yamask
  {24, 29, SPECIES_LITWICK},         //Chance: 5%
  {24, 29, SPECIES_YAMASK},         //Chance: 5%
  {24, 29, SPECIES_YAMASK},         //Chance: 4%
  {24, 29, SPECIES_HAUNTER},         //Chance: 4%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonTower6F_LandMonsInfo = {8, gPokemonTower6F_LandMons};


static const struct WildPokemon gPokemonTower7F_LandMons[] = 
{
  {24, 29, SPECIES_SHUPPET},         //Chance: 20% Ghastly
  {24, 29, SPECIES_SHUPPET},         //Chance: 20% Haunter
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Litwick
  {24, 29, SPECIES_MISDREAVUS},         //Chance: 10% Shuppet
  {24, 29, SPECIES_LITWICK},         //Chance: 10% Misdreavus
  {24, 29, SPECIES_LITWICK},         //Chance: 10% Yamask
  {24, 29, SPECIES_YAMASK},         //Chance: 5%
  {24, 29, SPECIES_YAMASK},         //Chance: 5%
  {24, 29, SPECIES_HAUNTER},         //Chance: 4%
  {24, 29, SPECIES_HAUNTER},         //Chance: 4%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
  {24, 29, SPECIES_HAUNTER},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonTower7F_LandMonsInfo = {10, gPokemonTower7F_LandMons};



static const struct WildPokemon gRoute8_LandMons[] = 
{
  {23, 28, SPECIES_PIDGEOTTO},         //Chance: 20% Audino
  {23, 28, SPECIES_FLOETTE},         //Chance: 20% Chingling
  {23, 28, SPECIES_AUDINO},         //Chance: 10% Baltoy
  {23, 28, SPECIES_AUDINO},         //Chance: 10% Pideotto
  {23, 28, SPECIES_CHINGLING},         //Chance: 10% Floette
  {23, 28, SPECIES_CHINGLING},         //Chance: 10% 
  {23, 28, SPECIES_PIDGEOTTO},         //Chance: 5%
  {23, 28, SPECIES_FLOETTE},         //Chance: 5%
  {23, 28, SPECIES_BALTOY},         //Chance: 4%
  {23, 28, SPECIES_BALTOY},         //Chance: 4%
  {23, 28, SPECIES_BALTOY},         //Chance: 1%
  {23, 28, SPECIES_BALTOY},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute8_LandMonsInfo= {20, gRoute8_LandMons};

static const struct WildPokemon gRoute7_LandMons[] = 
{
  {23, 28, SPECIES_ORANGURU},         //Chance: 20% Zangoose
  {23, 28, SPECIES_PASSIMIAN},         //Chance: 20% Seviper
  {23, 28, SPECIES_ORANGURU},         //Chance: 10% Oranguru
  {23, 28, SPECIES_PASSIMIAN},         //Chance: 10% Swirlix
  {23, 28, SPECIES_SEVIPER},         //Chance: 10% Applin
  {23, 28, SPECIES_ZANGOOSE},         //Chance: 10% 
  {23, 28, SPECIES_SEVIPER},         //Chance: 5%
  {23, 28, SPECIES_ZANGOOSE},         //Chance: 5%
  {23, 28, SPECIES_SWIRLIX},         //Chance: 4%
  {23, 28, SPECIES_APPLIN},         //Chance: 4%
  {23, 28, SPECIES_SWIRLIX},         //Chance: 1%
  {23, 28, SPECIES_APPLIN},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute7_LandMonsInfo= {20, gRoute7_LandMons};

static const struct WildPokemon gCeladonCity_SurfMons[] = 
{
  {35, 58, SPECIES_LUMINEON},
  {35, 58, SPECIES_LUMINEON},
  {35, 58, SPECIES_STARYU},
  {45, 58, SPECIES_STARYU},
  {56, 58, SPECIES_STARYU},
};
static const struct WildPokemonInfo gCeladonCity_SurfMonsInfo = {5, gCeladonCity_SurfMons};


static const struct WildPokemon gCeladonCity_FishingMons[] = 
{
  {15, 20, SPECIES_FINNEON},
  {15, 20, SPECIES_STARYU},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_STARYU},
  {27, 29, SPECIES_FINNEON},
  {33, 55, SPECIES_FINNEON},
  {33, 55, SPECIES_STARYU},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gCeladonCity_FishingMonsInfo = {5, gCeladonCity_FishingMons};


static const struct WildPokemon gRoute16_LandMons[] = 
{
  {25, 30, SPECIES_NIDORINA},         //Chance: 20% 
  {25, 30, SPECIES_NIDORINO},         //Chance: 20% 
  {25, 30, SPECIES_GLOOM},         //Chance: 10% 
  {25, 30, SPECIES_BIBAREL},         //Chance: 10% 
  {25, 30, SPECIES_NIDORINA},         //Chance: 10% 
  {25, 30, SPECIES_NIDORINO},         //Chance: 10% 
  {25, 30, SPECIES_VULPIX},         //Chance: 5%
  {25, 30, SPECIES_GLOOM},         //Chance: 5%
  {25, 30, SPECIES_VULPIX},         //Chance: 4%
  {25, 30, SPECIES_BIBAREL},         //Chance: 4%
  {25, 30, SPECIES_BIBAREL},         //Chance: 1%
  {25, 30, SPECIES_GLOOM},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute16_LandMonsInfo= {20, gRoute16_LandMons};

static const struct WildPokemon gRoute17_LandMons[] = 
{
  {27, 32, SPECIES_SWELLOW},         //Chance: 20% 
  {27, 32, SPECIES_THIEVUL},         //Chance: 20% Swello
  {27, 32, SPECIES_SWELLOW},         //Chance: 10% Thievul
  {27, 32, SPECIES_THIEVUL},         //Chance: 10% Flaffy
  {27, 32, SPECIES_FLAAFFY},         //Chance: 10% Mightyena
  {27, 32, SPECIES_MIGHTYENA},         //Chance: 10% Sliggu
  {27, 32, SPECIES_FLAAFFY},         //Chance: 5%
  {27, 32, SPECIES_MIGHTYENA},         //Chance: 5%
  {27, 32, SPECIES_FLAAFFY},         //Chance: 4%
  {27, 32, SPECIES_GOOMY},         //Chance: 4%
  {27, 32, SPECIES_GOOMY},         //Chance: 1%
  {27, 32, SPECIES_GOOMY},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute17_LandMonsInfo= {20, gRoute17_LandMons};


static const struct WildPokemon gRoute18_LandMons[] = 
{
  {28, 33, SPECIES_PIDGEOTTO},         //Chance: 20% Doduo
  {28, 33, SPECIES_NOCTOWL},         //Chance: 20% Skarmory
  {28, 33, SPECIES_PIDGEOTTO},         //Chance: 10% Pidgeotto
  {28, 33, SPECIES_NOCTOWL},         //Chance: 10% Noctowl
  {28, 33, SPECIES_DODUO},         //Chance: 10% Sigilyph
  {28, 33, SPECIES_SKARMORY},         //Chance: 10% 
  {28, 33, SPECIES_DODUO},         //Chance: 5%
  {28, 33, SPECIES_SKARMORY},         //Chance: 5%
  {28, 33, SPECIES_DODUO},         //Chance: 4%
  {28, 33, SPECIES_SIGILYPH},         //Chance: 4%
  {28, 33, SPECIES_SIGILYPH},         //Chance: 1%
  {28, 33, SPECIES_SIGILYPH},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute18_LandMonsInfo= {20, gRoute18_LandMons};





static const struct WildPokemon gRoute12_LandMons[] = 
{
  {27, 32, SPECIES_WHIRLIPEDE},         //Chance: 20% Kadabra
  {27, 32, SPECIES_SNUBBULL},         //Chance: 20% Snubbull
  {27, 32, SPECIES_WHIRLIPEDE},         //Chance: 10% Granbull
  {27, 32, SPECIES_SNUBBULL},         //Chance: 10% Gothorita
  {27, 32, SPECIES_KADABRA},         //Chance: 10% Whirlipede
  {27, 32, SPECIES_GOTHORITA},         //Chance: 10% 
  {27, 32, SPECIES_KADABRA},         //Chance: 5%
  {27, 32, SPECIES_GOTHORITA},         //Chance: 5%
  {27, 32, SPECIES_KADABRA},         //Chance: 4%
  {30, 34, SPECIES_GRANBULL},         //Chance: 4%
  {30, 34, SPECIES_GRANBULL},         //Chance: 1%
  {30, 34, SPECIES_GRANBULL},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute12_LandMonsInfo= {20, gRoute12_LandMons};

static const struct WildPokemon gRoute12_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_TENTACOOL},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_SHARPEDO},
};
static const struct WildPokemonInfo gRoute12_SurfMonsInfo = {5, gRoute12_SurfMons};


static const struct WildPokemon gRoute12_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_TENTACOOL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_TENTACOOL},
  {27, 29, SPECIES_TENTACOOL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute12_FishingMonsInfo = {5, gRoute12_FishingMons};






static const struct WildPokemon gRoute13_LandMons[] = 
{
  {28, 34, SPECIES_FOONGUS},         //Chance: 20% Jangmo-o
  {28, 34, SPECIES_DUBWOOL},         //Chance: 20% Luxray
  {28, 34, SPECIES_FOONGUS},         //Chance: 10% Luxio
  {28, 34, SPECIES_DUBWOOL},         //Chance: 10% Dubwool
  {28, 34, SPECIES_FOONGUS},         //Chance: 10% Breloom
  {28, 34, SPECIES_BRELOOM},         //Chance: 10% 
  {28, 34, SPECIES_BRELOOM},         //Chance: 5%
  {28, 34, SPECIES_FOONGUS},         //Chance: 5%
  {28, 34, SPECIES_JANGMO_O},         //Chance: 4%
  {28, 34, SPECIES_JANGMO_O},         //Chance: 4%
  {34, 39, SPECIES_LUXRAY},         //Chance: 1%
  {34, 39, SPECIES_LUXRAY},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute13_LandMonsInfo= {20, gRoute13_LandMons};

static const struct WildPokemon gRoute13_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_TENTACOOL},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_SHARPEDO},
};
static const struct WildPokemonInfo gRoute13_SurfMonsInfo = {5, gRoute13_SurfMons};


static const struct WildPokemon gRoute13_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_TENTACOOL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_TENTACOOL},
  {27, 29, SPECIES_TENTACOOL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute13_FishingMonsInfo = {5, gRoute13_FishingMons};




static const struct WildPokemon gRoute14_LandMons[] = 
{
  {28, 34, SPECIES_SWADLOON},         //Chance: 20% Xatu
  {28, 34, SPECIES_SANDACONDA},         //Chance: 20% Sandacobra
  {28, 34, SPECIES_SWADLOON},         //Chance: 10% Swadloon
  {28, 34, SPECIES_SANDACONDA},         //Chance: 10% Bewear
  {28, 34, SPECIES_XATU},         //Chance: 10% 
  {28, 34, SPECIES_BEWEAR},         //Chance: 10% 
  {28, 34, SPECIES_XATU},         //Chance: 5%
  {28, 34, SPECIES_BEWEAR},         //Chance: 5%
  {28, 34, SPECIES_SWADLOON},         //Chance: 4%
  {28, 34, SPECIES_XATU},         //Chance: 4%
  {28, 34, SPECIES_SWADLOON},         //Chance: 1%
  {28, 34, SPECIES_XATU},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute14_LandMonsInfo= {20, gRoute14_LandMons};




static const struct WildPokemon gRoute15_LandMons[] = 
{
  {28, 35, SPECIES_DIGGERSBY},         //Chance: 20% Ribombee
  {28, 35, SPECIES_SPOINK},         //Chance: 20% Houndoom
  {28, 35, SPECIES_DIGGERSBY},         //Chance: 10% Spoink
  {28, 35, SPECIES_SPOINK},         //Chance: 10% Grumpig
  {28, 35, SPECIES_SPOINK},         //Chance: 10% Diggersby
  {28, 35, SPECIES_HOUNDOOM},         //Chance: 10% 
  {28, 35, SPECIES_DIGGERSBY},         //Chance: 5%
  {28, 35, SPECIES_HOUNDOOM},         //Chance: 5%
  {28, 35, SPECIES_RIBOMBEE},         //Chance: 4%
  {32, 36, SPECIES_GRUMPIG},         //Chance: 4%
  {28, 35, SPECIES_RIBOMBEE},         //Chance: 1%
  {32, 36, SPECIES_GRUMPIG},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute15_LandMonsInfo= {20, gRoute15_LandMons};




static const struct WildPokemon gSafariCenter_LandMons[] = 
{
  {30, 36, SPECIES_NINCADA},         //Chance: 20% SPECIES_NINCADA
  {30, 36, SPECIES_AMBIPOM},         //Chance: 20% SPECIES_NINJASK
  {30, 36, SPECIES_NINCADA},         //Chance: 10% SPECIES_HERACROSS
  {30, 36, SPECIES_TAUROS},         //Chance: 10% SPECIES_AMBIPOM
  {30, 36, SPECIES_PYROAR},         //Chance: 10% SPECIES_PYROAR
  {30, 36, SPECIES_PYROAR},         //Chance: 10% 
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 4%
  {30, 36, SPECIES_HERACROSS},         //Chance: 4%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
};
static const struct WildPokemonInfo gSafariCenter_LandMonsInfo= {20, gSafariCenter_LandMons};

static const struct WildPokemon gSafariCenter_SurfMons[] = 
{
  {35, 58, SPECIES_WISHIWASHI},
  {35, 58, SPECIES_CHINCHOU},
  {35, 58, SPECIES_LANTURN},
  {45, 58, SPECIES_RELICANTH},
  {56, 58, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariCenter_SurfMonsInfo = {5, gSafariCenter_SurfMons};


static const struct WildPokemon gSafariCenter_FishingMons[] = 
{
  {15, 20, SPECIES_WISHIWASHI},
  {15, 20, SPECIES_CHINCHOU},
  {27, 29, SPECIES_WISHIWASHI},
  {27, 29, SPECIES_CHINCHOU},
  {27, 29, SPECIES_CHINCHOU},
  {33, 55, SPECIES_LANTURN},
  {33, 55, SPECIES_LANTURN},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariCenter_FishingMonsInfo = {5, gSafariCenter_FishingMons};









static const struct WildPokemon gSafariEast_LandMons[] = 
{
  {30, 36, SPECIES_NINCADA},         //Chance: 20% Turtonator
  {30, 36, SPECIES_AMBIPOM},         //Chance: 20% Nincada
  {30, 36, SPECIES_NINCADA},         //Chance: 10% Ninjask
  {30, 36, SPECIES_TAUROS},         //Chance: 10% SPECIES_AMBIPOM
  {30, 36, SPECIES_PYROAR},         //Chance: 10% SPECIES_PYROAR
  {30, 36, SPECIES_PYROAR},         //Chance: 10% 
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 4%
  {30, 36, SPECIES_TURTONATOR},         //Chance: 4%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
};
static const struct WildPokemonInfo gSafariEast_LandMonsInfo= {20, gSafariEast_LandMons};

static const struct WildPokemon gSafariEast_SurfMons[] = 
{
  {35, 58, SPECIES_WISHIWASHI},
  {35, 58, SPECIES_LUMINEON},
  {35, 58, SPECIES_LUMINEON},
  {45, 58, SPECIES_RELICANTH},
  {56, 58, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariEast_SurfMonsInfo = {5, gSafariEast_SurfMons};


static const struct WildPokemon gSafariEast_FishingMons[] = 
{
  {15, 20, SPECIES_WISHIWASHI},
  {15, 20, SPECIES_FINNEON},
  {27, 29, SPECIES_WISHIWASHI},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_FINNEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariEast_FishingMonsInfo = {5, gSafariEast_FishingMons};






static const struct WildPokemon gSafariNorth_LandMons[] = 
{
  {30, 36, SPECIES_NINCADA},         //Chance: 20% Stonjourner
  {30, 36, SPECIES_AMBIPOM},         //Chance: 20% Ninjask
  {30, 36, SPECIES_NINCADA},         //Chance: 10% Nincada
  {30, 36, SPECIES_TAUROS},         //Chance: 10% 
  {30, 36, SPECIES_PYROAR},         //Chance: 10% 
  {30, 36, SPECIES_PYROAR},         //Chance: 10% 
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 4%
  {30, 36, SPECIES_STONJOURNER},         //Chance: 4%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
};
static const struct WildPokemonInfo gSafariNorth_LandMonsInfo= {20, gSafariNorth_LandMons};

static const struct WildPokemon gSafariNorth_SurfMons[] = 
{
  {35, 58, SPECIES_WISHIWASHI},
  {35, 58, SPECIES_STARMIE},
  {35, 58, SPECIES_STARMIE},
  {45, 58, SPECIES_RELICANTH},
  {56, 58, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariNorth_SurfMonsInfo = {5, gSafariNorth_SurfMons};


static const struct WildPokemon gSafariNorth_FishingMons[] = 
{
  {15, 20, SPECIES_WISHIWASHI},
  {15, 20, SPECIES_STARYU},
  {27, 29, SPECIES_WISHIWASHI},
  {27, 29, SPECIES_STARYU},
  {27, 29, SPECIES_STARYU},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariNorth_FishingMonsInfo = {5, gSafariNorth_FishingMons};








static const struct WildPokemon gSafariWest_LandMons[] = 
{
  {30, 36, SPECIES_NINCADA},         //Chance: 20% Duraludon
  {30, 36, SPECIES_AMBIPOM},         //Chance: 20% Ninjask
  {30, 36, SPECIES_NINCADA},         //Chance: 10% Nincada
  {30, 36, SPECIES_TAUROS},         //Chance: 10% 
  {30, 36, SPECIES_PYROAR},         //Chance: 10% 
  {30, 36, SPECIES_PYROAR},         //Chance: 10% 
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 5%
  {30, 36, SPECIES_NINJASK},         //Chance: 4%
  {30, 36, SPECIES_DURALUDON},         //Chance: 4%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
  {30, 36, SPECIES_SHUCKLE},         //Chance: 1%
};
static const struct WildPokemonInfo gSafariWest_LandMonsInfo= {20, gSafariWest_LandMons};

static const struct WildPokemon gSafariWest_SurfMons[] = 
{
  {35, 58, SPECIES_WISHIWASHI},
  {35, 58, SPECIES_QUAGSIRE},
  {35, 58, SPECIES_QUAGSIRE},
  {45, 58, SPECIES_RELICANTH},
  {56, 58, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariWest_SurfMonsInfo = {5, gSafariWest_SurfMons};


static const struct WildPokemon gSafariWest_FishingMons[] = 
{
  {15, 20, SPECIES_WISHIWASHI},
  {15, 20, SPECIES_WOOPER},
  {27, 29, SPECIES_WISHIWASHI},
  {27, 29, SPECIES_WOOPER},
  {27, 29, SPECIES_WOOPER},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_WISHIWASHI},
  {33, 55, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gSafariWest_FishingMonsInfo = {5, gSafariWest_FishingMons};





static const struct WildPokemon gFuchsiaCity_SurfMons[] = 
{
  {35, 58, SPECIES_FINNEON},
  {35, 58, SPECIES_CHINCHOU},
  {35, 58, SPECIES_FINNEON},
  {45, 58, SPECIES_LUMINEON},
  {56, 58, SPECIES_LANTURN},
};
static const struct WildPokemonInfo gFuchsiaCity_SurfMonsInfo = {5, gFuchsiaCity_SurfMons};


static const struct WildPokemon gFuchsiaCity_FishingMons[] = 
{
  {15, 20, SPECIES_FINNEON},
  {15, 20, SPECIES_CHINCHOU},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_CHINCHOU},
  {33, 55, SPECIES_FINNEON},
  {33, 55, SPECIES_CHINCHOU},
  {33, 55, SPECIES_FINNEON},
  {33, 55, SPECIES_FINNEON},
  {33, 55, SPECIES_LANTURN},
};
static const struct WildPokemonInfo gFuchsiaCity_FishingMonsInfo = {5, gFuchsiaCity_FishingMons};






static const struct WildPokemon gRoute19_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_TENTACOOL},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_SHARPEDO},
};
static const struct WildPokemonInfo gRoute19_SurfMonsInfo = {5, gRoute19_SurfMons};


static const struct WildPokemon gRoute19_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_TENTACOOL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_TENTACOOL},
  {27, 29, SPECIES_TENTACOOL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute19_FishingMonsInfo = {5, gRoute19_FishingMons};


static const struct WildPokemon gRoute20_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_TENTACOOL},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_SHARPEDO},
};
static const struct WildPokemonInfo gRoute20_SurfMonsInfo = {5, gRoute20_SurfMons};


static const struct WildPokemon gRoute20_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_TENTACOOL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_TENTACOOL},
  {27, 29, SPECIES_TENTACOOL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute20_FishingMonsInfo = {5, gRoute20_FishingMons};



static const struct WildPokemon gRoute21_LandMons[] = 
{
  {31, 37, SPECIES_TANGELA},         //Chance: 20% Thwackey
  {31, 37, SPECIES_PERSIAN},         //Chance: 20% Croconaw
  {31, 37, SPECIES_BRAIXEN},         //Chance: 10% Fennekin
  {31, 37, SPECIES_CROCONAW},         //Chance: 10% Floette
  {31, 37, SPECIES_THWACKEY},         //Chance: 10% Persian
  {31, 37, SPECIES_BRAIXEN},         //Chance: 10% 
  {31, 37, SPECIES_CROCONAW},         //Chance: 5%
  {31, 37, SPECIES_CROCONAW},         //Chance: 5%
  {31, 37, SPECIES_THWACKEY},         //Chance: 4%
  {31, 37, SPECIES_THWACKEY},         //Chance: 4%
  {31, 37, SPECIES_THWACKEY},         //Chance: 1%
  {31, 37, SPECIES_THWACKEY},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute21_LandMonsInfo= {20, gRoute21_LandMons};

static const struct WildPokemon gRoute21_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_TENTACOOL},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_SHARPEDO},
};
static const struct WildPokemonInfo gRoute21_SurfMonsInfo = {5, gRoute21_SurfMons};


static const struct WildPokemon gRoute21_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_TENTACOOL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_TENTACOOL},
  {27, 29, SPECIES_TENTACOOL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
};
static const struct WildPokemonInfo gRoute21_FishingMonsInfo = {5, gRoute21_FishingMons};





static const struct WildPokemon gCinnabar_SurfMons[] = 
{
  {35, 58, SPECIES_TENTACOOL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_SHARPEDO},
  {45, 58, SPECIES_TENTACRUEL},
  {56, 58, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gCinnabar_SurfMonsInfo = {5, gCinnabar_SurfMons};


static const struct WildPokemon gCinnabar_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_TENTACOOL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_TENTACOOL},
  {27, 29, SPECIES_TENTACOOL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_TENTACRUEL},
  {33, 55, SPECIES_RELICANTH},
  {33, 55, SPECIES_RELICANTH},
};
static const struct WildPokemonInfo gCinnabar_FishingMonsInfo = {5, gCinnabar_FishingMons};







static const struct WildPokemon gSeafoam1F_LandMons[] = 
{
  {34, 41, SPECIES_SNORUNT},         //Chance: 20% Snowrunt 
  {34, 41, SPECIES_SWINUB},         //Chance: 20% Glalie
  {34, 41, SPECIES_SNORUNT},         //Chance: 10% 
  {34, 41, SPECIES_SWINUB},         //Chance: 10% 
  {34, 41, SPECIES_CUBCHOO},         //Chance: 10% Swinub
  {34, 41, SPECIES_VANILLITE},         //Chance: 10% Piloswine
  {34, 41, SPECIES_SNORUNT},         //Chance: 5% Vanillite
  {34, 41, SPECIES_SWINUB},         //Chance: 5% Vannillish
  {34, 41, SPECIES_CUBCHOO},         //Chance: 4% Cubcho
  {34, 41, SPECIES_VANILLITE},         //Chance: 4% Beartic
  {34, 41, SPECIES_PILOSWINE},         //Chance: 1%
  {34, 41, SPECIES_PILOSWINE},         //Chance: 1%
};
static const struct WildPokemonInfo gSeafoamF1_LandMonsInfo= {7, gSeafoam1F_LandMons};


static const struct WildPokemon gSeafoamB1F_LandMons[] = 
{
  {35, 42, SPECIES_SNORUNT},         //Chance: 20% Snowrunt 
  {35, 42, SPECIES_SWINUB},         //Chance: 20% Glalie
  {35, 42, SPECIES_SNORUNT},         //Chance: 10% 
  {35, 42, SPECIES_SWINUB},         //Chance: 10% 
  {35, 42, SPECIES_CUBCHOO},         //Chance: 10% Swinub
  {35, 42, SPECIES_VANILLITE},         //Chance: 10% Piloswine
  {35, 42, SPECIES_SNORUNT},         //Chance: 5% Vanillite
  {35, 42, SPECIES_VANILLITE},         //Chance: 5% Vannillish
  {35, 42, SPECIES_PILOSWINE},         //Chance: 4% Cubcho
  {35, 42, SPECIES_PILOSWINE},         //Chance: 4% Beartic
  {37, 44, SPECIES_BEARTIC},         //Chance: 1%
  {37, 44, SPECIES_BEARTIC},         //Chance: 1%
};
static const struct WildPokemonInfo gSeafoamB1F_LandMonsInfo= {7, gSeafoamB1F_LandMons};

static const struct WildPokemon gSeafoamB2F_LandMons[] = 
{
  {36, 43, SPECIES_SNORUNT},         //Chance: 20% Snowrunt 
  {36, 43, SPECIES_SWINUB},         //Chance: 20% Glalie
  {36, 43, SPECIES_SNORUNT},         //Chance: 10% 
  {36, 43, SPECIES_CUBCHOO},         //Chance: 10% 
  {36, 43, SPECIES_VANILLITE},         //Chance: 10% Swinub
  {36, 43, SPECIES_VANILLITE},         //Chance: 10% Piloswine
  {36, 43, SPECIES_PILOSWINE},         //Chance: 5% Vanillite
  {36, 43, SPECIES_PILOSWINE},         //Chance: 5% Vannillish
  {37, 45, SPECIES_BEARTIC},         //Chance: 4% Cubcho
  {37, 45, SPECIES_BEARTIC},         //Chance: 4% Beartic
  {37, 45, SPECIES_VANILLISH},         //Chance: 1%
  {37, 45, SPECIES_VANILLISH},         //Chance: 1%
};
static const struct WildPokemonInfo gSeafoamB2F_LandMonsInfo= {7, gSeafoamB2F_LandMons};

static const struct WildPokemon gSeafoamB3F_LandMons[] = 
{
  {37, 44, SPECIES_SNORUNT},         //Chance: 20% Snowrunt 
  {37, 44, SPECIES_SWINUB},         //Chance: 20% Glalie
  {37, 44, SPECIES_SNORUNT},         //Chance: 10% 
  {37, 44, SPECIES_CUBCHOO},         //Chance: 10% 
  {37, 44, SPECIES_VANILLITE},         //Chance: 10% Swinub
  {37, 44, SPECIES_VANILLITE},         //Chance: 10% Piloswine
  {37, 44, SPECIES_PILOSWINE},         //Chance: 5% Vanillite
  {37, 44, SPECIES_PILOSWINE},         //Chance: 5% Vannillish
  {38, 46, SPECIES_BEARTIC},         //Chance: 4% Cubcho
  {38, 46, SPECIES_BEARTIC},         //Chance: 4% Beartic
  {38, 46, SPECIES_VANILLISH},         //Chance: 1%
  {38, 46, SPECIES_VANILLISH},         //Chance: 1%
};
static const struct WildPokemonInfo gSeafoamB3F_LandMonsInfo= {7, gSeafoamB3F_LandMons};

static const struct WildPokemon gSeafoamB4F_LandMons[] = 
{
  {37, 44, SPECIES_SNORUNT},         //Chance: 20% Snowrunt 
  {37, 44, SPECIES_SWINUB},         //Chance: 20% Glalie
  {37, 44, SPECIES_CUBCHOO},         //Chance: 10% 
  {37, 44, SPECIES_VANILLITE},         //Chance: 10% 
  {37, 44, SPECIES_VANILLITE},         //Chance: 10% Swinub
  {37, 44, SPECIES_PILOSWINE},         //Chance: 10% Piloswine
  {37, 44, SPECIES_BEARTIC},         //Chance: 5% Vanillite
  {37, 44, SPECIES_BEARTIC},         //Chance: 5% Vannillish
  {38, 46, SPECIES_VANILLISH},         //Chance: 4% Cubcho
  {38, 46, SPECIES_VANILLISH},         //Chance: 4% Beartic
  {42, 46, SPECIES_GLALIE},         //Chance: 1%
  {42, 46, SPECIES_GLALIE},         //Chance: 1%
};
static const struct WildPokemonInfo gSeafoamB4F_LandMonsInfo= {7, gSeafoamB4F_LandMons};

static const struct WildPokemon gSeafoam_SurfMons[] = 
{
  {35, 58, SPECIES_SPHEAL},
  {35, 58, SPECIES_SPHEAL},
  {35, 58, SPECIES_SEALEO},
  {45, 58, SPECIES_SEALEO},
  {56, 58, SPECIES_LAPRAS},
};
static const struct WildPokemonInfo gSeafoam_SurfMonsInfo = {5, gSeafoam_SurfMons};


static const struct WildPokemon gSeafoam_FishingMons[] = 
{
  {15, 20, SPECIES_SPHEAL},
  {15, 20, SPECIES_MAGIKARP},
  {27, 29, SPECIES_SPHEAL},
  {27, 29, SPECIES_SPHEAL},
  {27, 29, SPECIES_MAGIKARP},
  {33, 55, SPECIES_SEALEO},
  {33, 55, SPECIES_SEALEO},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
};
static const struct WildPokemonInfo gSeafoam_FishingMonsInfo = {5, gSeafoam_FishingMons};

static const struct WildPokemon gPokemonMansion1F_LandMons[] =
{
  {36, 42, SPECIES_CRUSTLE},         //Chance: 20% Crustle
  {36, 42, SPECIES_BALTOY},         //Chance: 20% Sinistea
  {36, 42, SPECIES_SINISTEA},         //Chance: 10% Bronzor
  {36, 42, SPECIES_BALTOY},         //Chance: 10% Bronzong
  {36, 42, SPECIES_BRONZOR},         //Chance: 10% Baltoy
  {36, 42, SPECIES_CRUSTLE},         //Chance: 10% Claydoll
  {36, 42, SPECIES_BALTOY},         //Chance: 5% Golett
  {36, 42, SPECIES_BRONZOR},         //Chance: 5% Golurk
  {36, 42, SPECIES_CLAYDOL},         //Chance: 4%
  {36, 42, SPECIES_BRONZONG},         //Chance: 4%
  {36, 42, SPECIES_BRONZONG},         //Chance: 1%
  {36, 42, SPECIES_BRONZONG},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonMansion1F_LandMonsInfo= {7, gPokemonMansion1F_LandMons};

static const struct WildPokemon gPokemonMansionB1F_LandMons[] =
{
  {36, 42, SPECIES_CRUSTLE},         //Chance: 20% Crustle
  {36, 42, SPECIES_SINISTEA},         //Chance: 20% Sinistea
  {36, 42, SPECIES_SINISTEA},         //Chance: 10% Bronzor
  {36, 42, SPECIES_GOLETT},         //Chance: 10% Bronzong
  {36, 42, SPECIES_GOLETT},         //Chance: 10% Baltoy
  {36, 42, SPECIES_CRUSTLE},         //Chance: 10% Claydoll
  {36, 42, SPECIES_BALTOY},         //Chance: 5% Golett
  {36, 42, SPECIES_BALTOY},         //Chance: 5% Golurk
  {36, 42, SPECIES_GOLURK},         //Chance: 4%
  {36, 42, SPECIES_CLAYDOL},         //Chance: 4%
  {36, 42, SPECIES_CLAYDOL},         //Chance: 1%
  {36, 42, SPECIES_CLAYDOL},         //Chance: 1%
};
static const struct WildPokemonInfo gPokemonMansionB1F_LandMonsInfo= {7, gPokemonMansionB1F_LandMons};

static const struct WildPokemon gPowerPlant_LandMons[] =
{
  {36, 42, SPECIES_FLAAFFY},         //Chance: 20% Galvantula
  {36, 42, SPECIES_LUXIO},         //Chance: 20% Elektrik
  {36, 42, SPECIES_FLAAFFY},         //Chance: 10% Luxio
  {36, 42, SPECIES_LUXIO},         //Chance: 10% Luxray
  {36, 42, SPECIES_BOLTUND},         //Chance: 10% Flaffy
  {36, 42, SPECIES_GALVANTULA},         //Chance: 10% Boltund
  {36, 42, SPECIES_EELEKTRIK},         //Chance: 5% 
  {36, 42, SPECIES_GALVANTULA},         //Chance: 5% 
  {36, 42, SPECIES_EELEKTRIK},         //Chance: 4%
  {36, 42, SPECIES_LUXRAY},         //Chance: 4%
  {36, 42, SPECIES_LUXRAY},         //Chance: 1%
  {36, 42, SPECIES_LUXRAY},         //Chance: 1%
};
static const struct WildPokemonInfo gPowerPlant_LandMonsInfo= {7, gPowerPlant_LandMons};





static const struct WildPokemon gOneTown_SurfMons[] = 
{
  {35, 58, SPECIES_STARYU},
  {35, 58, SPECIES_STARYU},
  {35, 58, SPECIES_STARYU},
  {45, 58, SPECIES_STARMIE},
  {56, 58, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gOneTown_SurfMonsInfo = {5, gOneTown_SurfMons};


static const struct WildPokemon gOneTown_FishingMons[] = 
{
  {15, 20, SPECIES_MAGIKARP},
  {15, 20, SPECIES_STARYU},
  {27, 29, SPECIES_MAGIKARP},
  {27, 29, SPECIES_STARYU},
  {27, 29, SPECIES_STARYU},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gOneTown_FishingMonsInfo = {5, gOneTown_FishingMons};


static const struct WildPokemon gTreasureBeach_LandMons[] = 
{
  {39, 47, SPECIES_AZURILL},         //Chance: 20% Sandygast
  {39, 47, SPECIES_SANDYGAST},         //Chance: 20% Pallossand
  {39, 47, SPECIES_MARILL},         //Chance: 10% Maril
  {39, 47, SPECIES_MARILL},         //Chance: 10% Azumaril
  {39, 47, SPECIES_SANDYGAST},         //Chance: 10% Azurill
  {39, 47, SPECIES_AZURILL},         //Chance: 10% 
  {39, 47, SPECIES_AZUMARILL},         //Chance: 5%
  {39, 47, SPECIES_AZUMARILL},         //Chance: 5%
  {39, 47, SPECIES_PALOSSAND},         //Chance: 4%
  {39, 47, SPECIES_PALOSSAND},         //Chance: 4%
  {39, 47, SPECIES_PALOSSAND},         //Chance: 1%
  {39, 47, SPECIES_PALOSSAND},         //Chance: 1%
};
static const struct WildPokemonInfo gTreasureBeach_LandMonsInfo= {20, gTreasureBeach_LandMons};




static const struct WildPokemon gKindleRoad_LandMons[] = 
{
  {39, 47, SPECIES_CUTIEFLY},         //Chance: 20% Ribombee
  {39, 47, SPECIES_HOOTHOOT},         //Chance: 20% Noctowl
  {39, 47, SPECIES_CUTIEFLY},         //Chance: 10% Hoothoot
  {39, 47, SPECIES_HOOTHOOT},         //Chance: 10% Cutifly
  {39, 47, SPECIES_LITLEO},         //Chance: 10% Litleo
  {39, 47, SPECIES_LITLEO},         //Chance: 10% Pyroar
  {39, 47, SPECIES_RIBOMBEE},         //Chance: 5%
  {39, 47, SPECIES_NOCTOWL},         //Chance: 5%
  {39, 47, SPECIES_NOCTOWL},         //Chance: 4%
  {39, 47, SPECIES_NOCTOWL},         //Chance: 4%
  {39, 47, SPECIES_PYROAR},         //Chance: 1%
  {39, 47, SPECIES_PYROAR},         //Chance: 1%
};
static const struct WildPokemonInfo gKindleRoad_LandMonsInfo= {20, gKindleRoad_LandMons};

static const struct WildPokemon gKindleRoad_SurfMons[] = 
{
  {35, 58, SPECIES_REMORAID},
  {35, 58, SPECIES_MAGIKARP},
  {35, 58, SPECIES_MAGIKARP},
  {45, 58, SPECIES_OCTILLERY},
  {56, 58, SPECIES_GYARADOS},
};
static const struct WildPokemonInfo gKindleRoad_SurfMonsInfo = {5, gKindleRoad_SurfMons};


static const struct WildPokemon gKindleRoad_FishingMons[] = 
{
  {15, 20, SPECIES_REMORAID},
  {15, 20, SPECIES_MAGIKARP},
  {27, 29, SPECIES_REMORAID},
  {27, 29, SPECIES_REMORAID},
  {27, 29, SPECIES_MAGIKARP},
  {33, 55, SPECIES_OCTILLERY},
  {33, 55, SPECIES_OCTILLERY},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
  {33, 55, SPECIES_GYARADOS},
};
static const struct WildPokemonInfo gKindleRoad_FishingMonsInfo = {5, gKindleRoad_FishingMons};


static const struct WildPokemon gMtEmberOutside_LandMons[] = 
{
  {39, 47, SPECIES_NUMEL},         //Chance: 20% Numel
  {39, 47, SPECIES_SALANDIT},         //Chance: 20% Camerupt
  {39, 47, SPECIES_NUMEL},         //Chance: 10% Heatmor
  {39, 47, SPECIES_SALANDIT},         //Chance: 10% Durant
  {39, 47, SPECIES_DURANT},         //Chance: 10% Salandit
  {39, 47, SPECIES_DURANT},         //Chance: 10% 
  {39, 47, SPECIES_HEATMOR},         //Chance: 5%
  {39, 47, SPECIES_CAMERUPT},         //Chance: 5%
  {39, 47, SPECIES_CAMERUPT},         //Chance: 4%
  {39, 47, SPECIES_HEATMOR},         //Chance: 4%
  {39, 47, SPECIES_CAMERUPT},         //Chance: 1%
  {39, 47, SPECIES_HEATMOR},         //Chance: 1%
};
static const struct WildPokemonInfo gMtEmberOutside_LandMonsInfo= {20, gMtEmberOutside_LandMons};


static const struct WildPokemon gMtEmberInside_LandMons[] = 
{
  {39, 47, SPECIES_NUMEL},   //Chance: 20% Numel
  {39, 47, SPECIES_GRAVELER},   //Chance: 20% Camerupt
  {39, 47, SPECIES_BOLDORE},   //Chance: 10% Graveler
  {39, 47, SPECIES_BOLDORE},   //Chance: 10% Bolor
  {39, 47, SPECIES_LAIRON},   //Chance: 10% Lairon
  {39, 47, SPECIES_LAIRON},   //Chance: 10% 
  {39, 47, SPECIES_NUMEL},   //Chance: 5%
  {39, 47, SPECIES_GRAVELER},   //Chance: 5%
  {39, 47, SPECIES_BOLDORE},   //Chance: 4%
  {39, 47, SPECIES_CAMERUPT},   //Chance: 4%
  {39, 47, SPECIES_CAMERUPT},   //Chance: 1%
  {39, 47, SPECIES_CAMERUPT},   //Chance: 1%
};
static const struct WildPokemonInfo gMtEmberInside_LandMonsInfo= {7, gMtEmberInside_LandMons};



static const struct WildPokemon gCapeBrink_LandMons[] = 
{
  {39, 47, SPECIES_BIDOOF},         //Chance: 20% Dodrio
  {39, 47, SPECIES_SHROOMISH},         //Chance: 20% Dodou
  {39, 47, SPECIES_BIDOOF},         //Chance: 10% Shroomish
  {39, 47, SPECIES_SHROOMISH},         //Chance: 10% Breloom
  {39, 47, SPECIES_DODUO},         //Chance: 10% Bidoof
  {39, 47, SPECIES_DODUO},         //Chance: 10% Bibearal
  {39, 47, SPECIES_DODRIO},         //Chance: 5%
  {39, 47, SPECIES_BIBAREL},         //Chance: 5%
  {39, 47, SPECIES_BIBAREL},         //Chance: 4%
  {39, 47, SPECIES_BRELOOM},         //Chance: 4%
  {39, 47, SPECIES_BRELOOM},         //Chance: 1%
  {39, 47, SPECIES_BRELOOM},         //Chance: 1%
};
static const struct WildPokemonInfo gCapeBrink_LandMonsInfo= {20, gCapeBrink_LandMons};

static const struct WildPokemon gCapeBrink_SurfMons[] = 
{
  {35, 58, SPECIES_FINNEON},
  {35, 58, SPECIES_MAGIKARP},
  {35, 58, SPECIES_MAGIKARP},
  {45, 58, SPECIES_LUMINEON},
  {56, 58, SPECIES_LUMINEON},
};
static const struct WildPokemonInfo gCapeBrink_SurfMonsInfo = {5, gCapeBrink_SurfMons};


static const struct WildPokemon gCapeBrink_FishingMons[] = 
{
  {15, 20, SPECIES_FINNEON},
  {15, 20, SPECIES_MAGIKARP},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_MAGIKARP},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_LUMINEON},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_STARMIE},
  {33, 55, SPECIES_STARMIE},
};
static const struct WildPokemonInfo gCapeBrink_FishingMonsInfo = {5, gCapeBrink_FishingMons};


static const struct WildPokemon gThreeIslandPort_LandMons[] = 
{
  {39, 47, SPECIES_INKAY},         //Chance: 20% Inkay
  {39, 47, SPECIES_DWEBBLE},         //Chance: 20% Malamar
  {39, 47, SPECIES_INKAY},         //Chance: 10% Munchlax
  {39, 47, SPECIES_DWEBBLE},         //Chance: 10% Dwebbly Crustle
  {39, 47, SPECIES_MALAMAR},         //Chance: 10% 
  {39, 47, SPECIES_INKAY},         //Chance: 10% 
  {39, 47, SPECIES_DWEBBLE},         //Chance: 5%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 5%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 4%
  {39, 47, SPECIES_MUNCHLAX},         //Chance: 4%
  {39, 47, SPECIES_MUNCHLAX},         //Chance: 1%
  {39, 47, SPECIES_MUNCHLAX},         //Chance: 1%
};
static const struct WildPokemonInfo gThreeIslandPort_LandMonsInfo= {20, gThreeIslandPort_LandMons};


static const struct WildPokemon gThreeIslandPath_LandMons[] = 
{
  {39, 47, SPECIES_DWEBBLE},         //Chance: 20% Inkay
  {39, 47, SPECIES_DWEBBLE},         //Chance: 20% Malamar
  {39, 47, SPECIES_DWEBBLE},         //Chance: 10% Munchlax
  {39, 47, SPECIES_DWEBBLE},         //Chance: 10% Dwebbly Crustle
  {39, 47, SPECIES_DWEBBLE},         //Chance: 10% 
  {39, 47, SPECIES_DWEBBLE},         //Chance: 10% 
  {39, 47, SPECIES_CRUSTLE},         //Chance: 5%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 5%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 4%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 4%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 1%
  {39, 47, SPECIES_CRUSTLE},         //Chance: 1%
};
static const struct WildPokemonInfo gThreeIslandPath_LandMonsInfo= {6, gThreeIslandPath_LandMons};




static const struct WildPokemon gBondBridge_LandMons[] = 
{
  {41, 49, SPECIES_ORANGURU},         //Chance: 20% 
  {41, 49, SPECIES_PASSIMIAN},         //Chance: 20% Orangaru
  {41, 49, SPECIES_ORANGURU},         //Chance: 10% Passmissian
  {41, 49, SPECIES_PASSIMIAN},         //Chance: 10% Hitmonchan
  {41, 49, SPECIES_HITMONCHAN},         //Chance: 10% Hitmonlee
  {41, 49, SPECIES_HITMONLEE},         //Chance: 10% Clefairy
  {41, 49, SPECIES_HITMONCHAN},         //Chance: 5% JigglyPuff
  {41, 49, SPECIES_HITMONLEE},         //Chance: 5%
  {41, 49, SPECIES_CLEFAIRY},         //Chance: 4%
  {41, 49, SPECIES_JIGGLYPUFF},         //Chance: 4%
  {41, 49, SPECIES_CLEFAIRY},         //Chance: 1%
  {41, 49, SPECIES_JIGGLYPUFF},         //Chance: 1%
};
static const struct WildPokemonInfo gBondBridge_LandMonsInfo= {20, gBondBridge_LandMons};

static const struct WildPokemon gBondBridge_SurfMons[] = 
{
  {35, 58, SPECIES_REMORAID},
  {35, 58, SPECIES_BINACLE},
  {35, 58, SPECIES_BINACLE},
  {45, 58, SPECIES_OCTILLERY},
  {56, 58, SPECIES_BARBARACLE},
};
static const struct WildPokemonInfo gBondBridge_SurfMonsInfo = {5, gBondBridge_SurfMons};


static const struct WildPokemon gBondBridge_FishingMons[] = 
{
  {15, 20, SPECIES_REMORAID},
  {15, 20, SPECIES_BINACLE},
  {27, 29, SPECIES_REMORAID},
  {27, 29, SPECIES_REMORAID},
  {27, 29, SPECIES_BINACLE},
  {33, 55, SPECIES_REMORAID},
  {33, 55, SPECIES_BINACLE},
  {33, 55, SPECIES_OCTILLERY},
  {33, 55, SPECIES_OCTILLERY},
  {33, 55, SPECIES_BARBARACLE},
};
static const struct WildPokemonInfo gBondBridge_FishingMonsInfo = {5, gBondBridge_FishingMons};





static const struct WildPokemon gBerryForest_LandMons[] = 
{
  {41, 49, SPECIES_APPLIN},         //Chance: 20% Applin
  {41, 49, SPECIES_PHANTUMP},         //Chance: 20% Phantump
  {41, 49, SPECIES_SHROOMISH},         //Chance: 10% Tevanent
  {41, 49, SPECIES_APPLIN},         //Chance: 10% Drowzee
  {41, 49, SPECIES_PHANTUMP},         //Chance: 10% Hypno
  {41, 49, SPECIES_SHROOMISH},         //Chance: 10% Shroomish
  {41, 49, SPECIES_DROWZEE},         //Chance: 5% 
  {41, 49, SPECIES_TREVENANT},         //Chance: 5%
  {41, 49, SPECIES_TREVENANT},         //Chance: 4%
  {41, 49, SPECIES_DROWZEE},         //Chance: 4%
  {41, 49, SPECIES_HYPNO},         //Chance: 1%
  {41, 49, SPECIES_HYPNO},         //Chance: 1%
};
static const struct WildPokemonInfo gBerryForest_LandMonsInfo= {20, gBerryForest_LandMons};

static const struct WildPokemon gBerryForest_SurfMons[] = 
{
  {35, 58, SPECIES_WOOPER},
  {35, 58, SPECIES_FINNEON},
  {35, 58, SPECIES_FINNEON},
  {45, 58, SPECIES_QUAGSIRE},
  {56, 58, SPECIES_LUMINEON},
};
static const struct WildPokemonInfo gBerryForest_SurfMonsInfo = {5, gBerryForest_SurfMons};


static const struct WildPokemon gBerryForest_FishingMons[] = 
{
  {15, 20, SPECIES_FINNEON},
  {15, 20, SPECIES_WOOPER},
  {27, 29, SPECIES_FINNEON},
  {27, 29, SPECIES_WOOPER},
  {27, 29, SPECIES_MAGIKARP},
  {33, 55, SPECIES_MAGIKARP},
  {33, 55, SPECIES_WOOPER},
  {33, 55, SPECIES_FINNEON},
  {33, 55, SPECIES_QUAGSIRE},
  {33, 55, SPECIES_LUMINEON},
};
static const struct WildPokemonInfo gBerryForest_FishingMonsInfo = {5, gBerryForest_FishingMons};





static const struct WildPokemon gRoute23_LandMons[] = 
{
  {43, 56, SPECIES_AUDINO},         //Chance: 20% Audino
  {43, 56, SPECIES_GOTHORITA},         //Chance: 20% Pideot
  {43, 56, SPECIES_AUDINO},         //Chance: 10% Gothorita
  {43, 56, SPECIES_AUDINO},         //Chance: 10% Gothitelle
  {43, 56, SPECIES_GOTHORITA},         //Chance: 10% Medicham
  {43, 56, SPECIES_MEDICHAM},         //Chance: 10% 
  {43, 56, SPECIES_MEDICHAM},         //Chance: 5%
  {43, 56, SPECIES_PIDGEOT},         //Chance: 5%
  {43, 56, SPECIES_PIDGEOT},         //Chance: 4%
  {43, 56, SPECIES_GOTHITELLE},         //Chance: 4%
  {43, 56, SPECIES_GOTHITELLE},         //Chance: 1%
  {43, 56, SPECIES_GOTHITELLE},         //Chance: 1%
};
static const struct WildPokemonInfo gRoute23_LandMonsInfo= {20, gRoute23_LandMons};

static const struct WildPokemon gRoute23_SurfMons[] = 
{
  {35, 58, SPECIES_MARILL},
  {35, 58, SPECIES_CARVANHA},
  {35, 58, SPECIES_MARILL},
  {45, 58, SPECIES_AZUMARILL},
  {56, 58, SPECIES_SHARPEDO},
};
static const struct WildPokemonInfo gRoute23_SurfMonsInfo = {5, gRoute23_SurfMons};


static const struct WildPokemon gRoute23_FishingMons[] = 
{
  {15, 20, SPECIES_CARVANHA},
  {15, 20, SPECIES_MARILL},
  {27, 29, SPECIES_CARVANHA},
  {27, 29, SPECIES_MARILL},
  {27, 29, SPECIES_MARILL},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_SHARPEDO},
  {33, 55, SPECIES_AZUMARILL},
  {33, 55, SPECIES_AZUMARILL},
};
static const struct WildPokemonInfo gRoute23_FishingMonsInfo = {5, gRoute23_FishingMons};




static const struct WildPokemon gVictoryRoad1F_LandMons[] = 
{
  {45, 63, SPECIES_GRAVELER},   //Chance: 20% Graveler
  {45, 63, SPECIES_SANDSLASH},   //Chance: 20% Golem
  {45, 63, SPECIES_GRAVELER},   //Chance: 10% Hippopatas
  {45, 63, SPECIES_SANDSLASH},   //Chance: 10% Sandslash
  {45, 63, SPECIES_GOLBAT},   //Chance: 10% Golbat
  {45, 63, SPECIES_GOLBAT},   //Chance: 10% 
  {45, 63, SPECIES_HIPPOWDON},   //Chance: 5%
  {45, 63, SPECIES_HIPPOWDON},   //Chance: 5%
  {45, 63, SPECIES_GOLBAT},   //Chance: 4%
  {45, 63, SPECIES_GOLEM},   //Chance: 4%
  {45, 63, SPECIES_GOLEM},   //Chance: 1%
  {45, 63, SPECIES_GOLEM},   //Chance: 1%
};
static const struct WildPokemonInfo gVictoryRoad1F_LandMonsInfo= {4, gVictoryRoad1F_LandMons};


static const struct WildPokemon gVictoryRoad2F_LandMons[] = 
{
  {45, 63, SPECIES_BOLDORE},   //Chance: 20% Bolore
  {45, 63, SPECIES_SANDACONDA},   //Chance: 20% Gigalith
  {45, 63, SPECIES_BOLDORE},   //Chance: 10% Hippopatas
  {45, 63, SPECIES_SANDACONDA},   //Chance: 10% Sandaconda
  {45, 63, SPECIES_SWOOBAT},   //Chance: 10% Swoobat
  {45, 63, SPECIES_SWOOBAT},   //Chance: 10% 
  {45, 63, SPECIES_HIPPOWDON},   //Chance: 5%
  {45, 63, SPECIES_HIPPOWDON},   //Chance: 5%
  {45, 63, SPECIES_SWOOBAT},   //Chance: 4%
  {45, 63, SPECIES_GIGALITH},   //Chance: 4%
  {45, 63, SPECIES_GIGALITH},   //Chance: 1%
  {45, 63, SPECIES_GIGALITH},   //Chance: 1%
};
static const struct WildPokemonInfo gVictoryRoad2F_LandMonsInfo= {4, gVictoryRoad2F_LandMons};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//





const struct WildPokemonHeader gWildMonNightHeaders[] =
{
	
	{
    .mapGroup = MAP_GROUP(PALLET_TOWN),
    .mapNum = MAP_NUM(PALLET_TOWN),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gPalletTown_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gPalletTown_FishingMonsInfo,
  },
	{
    .mapGroup = MAP_GROUP(ROUTE_1),
    .mapNum = MAP_NUM(ROUTE_1),
    .landMonsInfo = &gRoute1_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(VIRIDIAN_CITY),
    .mapNum = MAP_NUM(VIRIDIAN_CITY),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gViridianCity_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gViridianCity_FishingMonsInfo,
  	},
  {
    .mapGroup = MAP_GROUP(ROUTE_22),
    .mapNum = MAP_NUM(ROUTE_22),
    .landMonsInfo = &gRoute22_LandMonsInfo,
    .waterMonsInfo = &gRoute22_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute22_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_2),
    .mapNum = MAP_NUM(ROUTE_2),
    .landMonsInfo = &gRoute2_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
    .mapNum = MAP_NUM(VIRIDIAN_FOREST),
    .landMonsInfo = &gViridianForest_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_3),
    .mapNum = MAP_NUM(ROUTE_3),
    .landMonsInfo = &gRoute3_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(MT_MOON_1F),
    .mapNum = MAP_NUM(MT_MOON_1F),
    .landMonsInfo = &gMTMoon1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(MT_MOON_B1F),
    .mapNum = MAP_NUM(MT_MOON_B1F),
    .landMonsInfo = &gMTMoonB1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(MT_MOON_B2F),
    .mapNum = MAP_NUM(MT_MOON_B2F),
    .landMonsInfo = &gMTMoonB2F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_4),
    .mapNum = MAP_NUM(ROUTE_4),
    .landMonsInfo = &gRoute4_LandMonsInfo,
    .waterMonsInfo = &gRoute4_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute4_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(CERULEAN_CITY),
    .mapNum = MAP_NUM(CERULEAN_CITY),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gCeruleanCity_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gCeruleanCity_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_24),
    .mapNum = MAP_NUM(ROUTE_24),
    .landMonsInfo = &gRoute24_LandMonsInfo,
    .waterMonsInfo = &gRoute24_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute24_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_25),
    .mapNum = MAP_NUM(ROUTE_25),
    .landMonsInfo = &gRoute25_LandMonsInfo,
    .waterMonsInfo = &gRoute25_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute25_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_5),
    .mapNum = MAP_NUM(ROUTE_5),
    .landMonsInfo = &gRoute5_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_6),
    .mapNum = MAP_NUM(ROUTE_6),
    .landMonsInfo = &gRoute6_LandMonsInfo,
    .waterMonsInfo = &gRoute6_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute6_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(VERMILION_CITY),
    .mapNum = MAP_NUM(VERMILION_CITY),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gVermillionCity_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gVermillionCity_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_11),
    .mapNum = MAP_NUM(ROUTE_11),
    .landMonsInfo = &gRoute11_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(DIGLETTS_CAVE_NORTH_ENTRANCE),
    .mapNum = MAP_NUM(DIGLETTS_CAVE_NORTH_ENTRANCE),
    .landMonsInfo = &gDiglettsCaveEntrance_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(DIGLETTS_CAVE_SOUTH_ENTRANCE),
    .mapNum = MAP_NUM(DIGLETTS_CAVE_NORTH_ENTRANCE),
    .landMonsInfo = &gDiglettsCaveEntrance_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(DIGLETTS_CAVE_B1F),
    .mapNum = MAP_NUM(DIGLETTS_CAVE_B1F),
    .landMonsInfo = &gDiglettsCaveB1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_9),
    .mapNum = MAP_NUM(ROUTE_9),
    .landMonsInfo = &gRoute9_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_10),
    .mapNum = MAP_NUM(ROUTE_10),
    .landMonsInfo = &gRoute10_LandMonsInfo,
    .waterMonsInfo = &gRoute10_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute10_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROCK_TUNNEL_1F),
    .mapNum = MAP_NUM(ROCK_TUNNEL_1F),
    .landMonsInfo = &gRockTunnel1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROCK_TUNNEL_B1F),
    .mapNum = MAP_NUM(ROCK_TUNNEL_B1F),
    .landMonsInfo = &gRockTunnelB1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_TOWER_3F),
    .mapNum = MAP_NUM(POKEMON_TOWER_3F),
    .landMonsInfo = &gPokemonTower3F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_TOWER_4F),
    .mapNum = MAP_NUM(POKEMON_TOWER_4F),
    .landMonsInfo = &gPokemonTower4F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_TOWER_5F),
    .mapNum = MAP_NUM(POKEMON_TOWER_5F),
    .landMonsInfo = &gPokemonTower5F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_TOWER_6F),
    .mapNum = MAP_NUM(POKEMON_TOWER_6F),
    .landMonsInfo = &gPokemonTower6F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_TOWER_7F),
    .mapNum = MAP_NUM(POKEMON_TOWER_7F),
    .landMonsInfo = &gPokemonTower7F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_8),
    .mapNum = MAP_NUM(ROUTE_8),
    .landMonsInfo = &gRoute8_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_7),
    .mapNum = MAP_NUM(ROUTE_7),
    .landMonsInfo = &gRoute7_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(CELADON_CITY),
    .mapNum = MAP_NUM(CELADON_CITY),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gCeladonCity_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gCeladonCity_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_16),
    .mapNum = MAP_NUM(ROUTE_16),
    .landMonsInfo = &gRoute16_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_17),
    .mapNum = MAP_NUM(ROUTE_17),
    .landMonsInfo = &gRoute17_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_18),
    .mapNum = MAP_NUM(ROUTE_18),
    .landMonsInfo = &gRoute18_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_12),
    .mapNum = MAP_NUM(ROUTE_12),
    .landMonsInfo = &gRoute12_LandMonsInfo,
    .waterMonsInfo = &gRoute12_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute12_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_13),
    .mapNum = MAP_NUM(ROUTE_13),
    .landMonsInfo = &gRoute13_LandMonsInfo,
    .waterMonsInfo = &gRoute13_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute13_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_14),
    .mapNum = MAP_NUM(ROUTE_14),
    .landMonsInfo = &gRoute14_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_15),
    .mapNum = MAP_NUM(ROUTE_15),
    .landMonsInfo = &gRoute15_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(SAFARI_ZONE_CENTER),
    .mapNum = MAP_NUM(SAFARI_ZONE_CENTER),
    .landMonsInfo = &gSafariCenter_LandMonsInfo,
    .waterMonsInfo = &gSafariCenter_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSafariCenter_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(SAFARI_ZONE_EAST),
    .mapNum = MAP_NUM(SAFARI_ZONE_EAST),
    .landMonsInfo = &gSafariEast_LandMonsInfo,
    .waterMonsInfo = &gSafariEast_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSafariEast_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
    .mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
    .landMonsInfo = &gSafariNorth_LandMonsInfo,
    .waterMonsInfo = &gSafariNorth_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSafariNorth_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(SAFARI_ZONE_WEST),
    .mapNum = MAP_NUM(SAFARI_ZONE_WEST),
    .landMonsInfo = &gSafariWest_LandMonsInfo,
    .waterMonsInfo = &gSafariWest_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSafariWest_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(FUCHSIA_CITY),
    .mapNum = MAP_NUM(FUCHSIA_CITY),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gFuchsiaCity_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gFuchsiaCity_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_19),
    .mapNum = MAP_NUM(ROUTE_19),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gRoute19_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute19_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_20),
    .mapNum = MAP_NUM(ROUTE_20),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gRoute20_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute20_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_21_A),
    .mapNum = MAP_NUM(ROUTE_21_A),
    .landMonsInfo = &gRoute21_LandMonsInfo,
    .waterMonsInfo = &gRoute21_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute21_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_21_B),
    .mapNum = MAP_NUM(ROUTE_21_B),
    .landMonsInfo = &gRoute21_LandMonsInfo,
    .waterMonsInfo = &gRoute21_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute21_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(CINNABAR_ISLAND),
    .mapNum = MAP_NUM(CINNABAR_ISLAND),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gCinnabar_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gCinnabar_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_1F),
    .mapNum = MAP_NUM(SEAFOAM_ISLANDS_1F),
    .landMonsInfo = &gSeafoamF1_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B1F),
    .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B1F),
    .landMonsInfo = &gSeafoamB1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B2F),
    .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B2F),
    .landMonsInfo = &gSeafoamB2F_LandMonsInfo,
    .waterMonsInfo = &gSeafoam_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSeafoam_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B3F),
    .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B3F),
    .landMonsInfo = &gSeafoamB3F_LandMonsInfo,
    .waterMonsInfo = &gSeafoam_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSeafoam_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B4F),
    .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B4F),
    .landMonsInfo = &gSeafoamB4F_LandMonsInfo,
    .waterMonsInfo = &gSeafoam_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gSeafoam_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_MANSION_1F),
    .mapNum = MAP_NUM(POKEMON_MANSION_1F),
    .landMonsInfo = &gPokemonMansion1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_MANSION_2F),
    .mapNum = MAP_NUM(POKEMON_MANSION_2F),
    .landMonsInfo = &gPokemonMansion1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_MANSION_3F),
    .mapNum = MAP_NUM(POKEMON_MANSION_3F),
    .landMonsInfo = &gPokemonMansion1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POKEMON_MANSION_B1F),
    .mapNum = MAP_NUM(POKEMON_MANSION_B1F),
    .landMonsInfo = &gPokemonMansionB1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(POWER_PLANT),
    .mapNum = MAP_NUM(POWER_PLANT),
    .landMonsInfo = &gPowerPlant_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(ONE_ISLAND),
    .mapNum = MAP_NUM(ONE_ISLAND),
    .landMonsInfo = NULL,
    .waterMonsInfo = &gOneTown_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gOneTown_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ONE_ISLAND_TREASURE_BEACH),
    .mapNum = MAP_NUM(ONE_ISLAND_TREASURE_BEACH),
    .landMonsInfo = &gTreasureBeach_LandMonsInfo,
    .waterMonsInfo = &gOneTown_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gOneTown_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ONE_ISLAND_KINDLE_ROAD),
    .mapNum = MAP_NUM(ONE_ISLAND_KINDLE_ROAD),
    .landMonsInfo = &gKindleRoad_LandMonsInfo,
    .waterMonsInfo = &gKindleRoad_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gKindleRoad_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(MT_EMBER_EXTERIOR),
    .mapNum = MAP_NUM(MT_EMBER_EXTERIOR),
    .landMonsInfo = &gMtEmberOutside_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_1F),
    .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_1F),
    .landMonsInfo = &gMtEmberInside_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_2F),
    .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_2F),
    .landMonsInfo = &gMtEmberInside_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_3F),
    .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_3F),
    .landMonsInfo = &gMtEmberInside_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(TWO_ISLAND_CAPE_BRINK),
    .mapNum = MAP_NUM(TWO_ISLAND_CAPE_BRINK),
    .landMonsInfo = &gCapeBrink_LandMonsInfo,
    .waterMonsInfo = &gCapeBrink_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gCapeBrink_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(THREE_ISLAND_PORT),
    .mapNum = MAP_NUM(THREE_ISLAND_PORT),
    .landMonsInfo = &gThreeIslandPort_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(THREE_ISLAND_DUNSPARCE_TUNNEL),
    .mapNum = MAP_NUM(THREE_ISLAND_DUNSPARCE_TUNNEL),
    .landMonsInfo = &gThreeIslandPath_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(THREE_ISLAND_BOND_BRIDGE),
    .mapNum = MAP_NUM(THREE_ISLAND_BOND_BRIDGE),
    .landMonsInfo = &gBondBridge_LandMonsInfo,
    .waterMonsInfo = &gBondBridge_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gBondBridge_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(THREE_ISLAND_BERRY_FOREST),
    .mapNum = MAP_NUM(THREE_ISLAND_BERRY_FOREST),
    .landMonsInfo = &gBerryForest_LandMonsInfo,
    .waterMonsInfo = &gBerryForest_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gBerryForest_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(ROUTE_23),
    .mapNum = MAP_NUM(ROUTE_23),
    .landMonsInfo = &gRoute23_LandMonsInfo,
    .waterMonsInfo = &gRoute23_SurfMonsInfo,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = &gRoute23_FishingMonsInfo,
  },
  {
    .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
    .mapNum = MAP_NUM(VICTORY_ROAD_1F),
    .landMonsInfo = &gVictoryRoad1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(VICTORY_ROAD_2F),
    .mapNum = MAP_NUM(VICTORY_ROAD_2F),
    .landMonsInfo = &gVictoryRoad2F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
  {
    .mapGroup = MAP_GROUP(VICTORY_ROAD_3F),
    .mapNum = MAP_NUM(VICTORY_ROAD_3F),
    .landMonsInfo = &gVictoryRoad1F_LandMonsInfo,
    .waterMonsInfo = NULL,
    .rockSmashMonsInfo = NULL,
    .fishingMonsInfo = NULL,
  },
};

const struct WildPokemonHeader gWildMonMorningHeaders[] =
{
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct WildPokemonHeader gWildMonEveningHeaders[] =
{
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct SwarmData gSwarmTable[] =
{
	/*{
		.mapName = 0xFF,
		.species = 0xFFFF,
	},*/
};

#else //Below is for Pokemon Unbound. Feel free to remove.

static const struct WildPokemon sRoute2_LandMonsNight[] =
{
	{9, 11, SPECIES_HOOTHOOT},
	{9, 11, SPECIES_RATTATA},
	{9, 11, SPECIES_INKAY},
	{9, 11, SPECIES_MINCCINO},
	{9, 11, SPECIES_ELECTRIKE},
	{9, 11, SPECIES_AZURILL},
	{9, 11, SPECIES_STUFFUL},
	{9, 11, SPECIES_STUFFUL},
	{10, 11, SPECIES_SCRAGGY},
	{10, 11, SPECIES_RIOLU},
	{11, 11, SPECIES_SCRAGGY},
	{11, 11, SPECIES_RIOLU},
};

static const struct WildPokemonInfo sRoute2_LandMonsInfoNight = {15, sRoute2_LandMonsNight};

static const struct WildPokemon sRoute3_LandMonsNight[] =
{
	{9, 12, SPECIES_WINGULL},
	{9, 12, SPECIES_BIDOOF},
	{9, 12, SPECIES_SLOWPOKE},
	{9, 12, SPECIES_SLOWPOKE},
	{9, 12, SPECIES_SHELLOS},
	{9, 12, SPECIES_SURSKIT},
	{9, 12, SPECIES_SURSKIT},
	{9, 12, SPECIES_BUIZEL},
	{10, 12, SPECIES_POLIWAG},
	{10, 12, SPECIES_POLIWAG},
	{10, 12, SPECIES_POLIWAG},
	{10, 12, SPECIES_POLIWAG},
};

static const struct WildPokemonInfo sRoute3_LandMonsInfoNight = {15, sRoute3_LandMonsNight};

static const struct WildPokemon sRoute4_LandMonsNight[] =
{
	{15, 17, SPECIES_HOOTHOOT},
	{15, 17, SPECIES_HOOTHOOT},
	{15, 17, SPECIES_LILLIPUP},
	{15, 17, SPECIES_LILLIPUP},
	{15, 17, SPECIES_EKANS},
	{15, 17, SPECIES_NUMEL},
	{15, 17, SPECIES_BUDEW},
	{15, 17, SPECIES_BUDEW},
	{15, 17, SPECIES_MANKEY},
	{15, 17, SPECIES_RALTS},
	{17, 17, SPECIES_MANKEY},
	{17, 17, SPECIES_RALTS},
};

static const struct WildPokemonInfo sRoute4_LandMonsInfoNight = {15, sRoute4_LandMonsNight};

static const struct WildPokemon sGrimWoods_LandMonsNight[] =
{
	{13, 16, SPECIES_WEEDLE},
	{14, 16, SPECIES_SEEDOT},
	{14, 16, SPECIES_PUMPKABOO},
	{14, 16, SPECIES_PUMPKABOO_M},
	{14, 16, SPECIES_PUMPKABOO_L},
	{14, 16, SPECIES_PUMPKABOO_XL},
	{15, 16, SPECIES_GASTLY},
	{15, 16, SPECIES_SHUPPET},
	{15, 16, SPECIES_DUSKULL},
	{15, 16, SPECIES_PHANTUMP},
	{16, 16, SPECIES_DUSKULL},
	{16, 16, SPECIES_PHANTUMP},
};

static const struct WildPokemonInfo sGrimWoods_LandMonsInfoNight = {15, sGrimWoods_LandMonsNight};

static const struct WildPokemon sRoute5_LandMonsNight[] =
{
	{15, 18, SPECIES_PURRLOIN},
	{15, 19, SPECIES_MURKROW},
	{15, 18, SPECIES_NIDORAN_M},
	{15, 18, SPECIES_NIDORAN_F},
	{16, 19, SPECIES_HOUNDOUR},
	{15, 18, SPECIES_PURRLOIN},
	{16, 19, SPECIES_LICKITUNG},
	{16, 19, SPECIES_LICKITUNG},
	{17, 19, SPECIES_VENONAT},
	{17, 19, SPECIES_VENONAT},
	{19, 19, SPECIES_DITTO},
	{19, 19, SPECIES_DITTO},
};

static const struct WildPokemonInfo sRoute5_LandMonsInfoNight = {15, sRoute5_LandMonsNight};

static const struct WildPokemon sRoute6_LandMonsMorning[] =
{
	{20, 22, SPECIES_BUNNELBY},
	{20, 22, SPECIES_LEDYBA},
	{20, 22, SPECIES_SHINX},
	{20, 22, SPECIES_DEERLING},
	{20, 22, SPECIES_BUNNELBY},
	{20, 22, SPECIES_KRICKETOT},
	{21, 22, SPECIES_KRICKETOT},
	{21, 22, SPECIES_KRICKETOT},
	{21, 22, SPECIES_DEERLING},
	{21, 22, SPECIES_KRICKETOT},
	{22, 22, SPECIES_LEDIAN},
	{22, 22, SPECIES_LUXIO},
};

static const struct WildPokemonInfo sRoute6_LandMonsInfoMorning = {15, sRoute6_LandMonsMorning};

static const struct WildPokemon sRoute6_LandMonsNight[] =
{
	{20, 22, SPECIES_BUNNELBY},
	{20, 22, SPECIES_SPINARAK},
	{20, 22, SPECIES_SHINX},
	{20, 22, SPECIES_DEERLING},
	{20, 22, SPECIES_BUNNELBY},
	{20, 22, SPECIES_KRICKETOT},
	{21, 22, SPECIES_KRICKETOT},
	{21, 22, SPECIES_KRICKETOT},
	{21, 22, SPECIES_DEERLING},
	{21, 22, SPECIES_KRICKETOT},
	{22, 22, SPECIES_ARIADOS},
	{22, 22, SPECIES_LUXIO},
};

static const struct WildPokemonInfo sRoute6_LandMonsInfoNight = {15, sRoute6_LandMonsNight};

static const struct WildPokemon sRoute7_LandMonsNight[] =
{
	{21, 23, SPECIES_RATTATA_A},
	{21, 23, SPECIES_HOOTHOOT},
	{21, 23, SPECIES_BUNEARY},
	{21, 23, SPECIES_DROWZEE},
	{21, 23, SPECIES_ABRA},
	{21, 23, SPECIES_MAREEP},
	{21, 23, SPECIES_SHINX},
	{21, 23, SPECIES_SHINX},
	{22, 23, SPECIES_RATTATA_A},
	{22, 23, SPECIES_BUNEARY},
	{23, 23, SPECIES_LUXIO},
	{23, 23, SPECIES_RATICATE_A},
};

static const struct WildPokemonInfo sRoute7_LandMonsInfoNight = {15, sRoute7_LandMonsNight};

static const struct WildPokemon sRoute8_LandMonsNight[] =
{
	{22, 25, SPECIES_SNOVER},
	{22, 25, SPECIES_SNORUNT},
	{22, 25, SPECIES_SNEASEL},
	{22, 25, SPECIES_SNORUNT},
	{22, 25, SPECIES_CUBCHOO},
	{22, 25, SPECIES_DEERLING_WINTER},
	{22, 25, SPECIES_DEERLING_WINTER},
	{22, 25, SPECIES_FLAAFFY},
	{23, 25, SPECIES_SNOVER},
	{23, 25, SPECIES_SNORUNT},
	{23, 25, SPECIES_MINIOR_SHIELD},
	{23, 25, SPECIES_MINIOR_SHIELD},
};

static const struct WildPokemonInfo sRoute8_LandMonsInfoNight = {15, sRoute8_LandMonsNight};

static const struct WildPokemon sFrozenForest_LandMonsNight[] =
{
	{23, 26, SPECIES_SNOVER},
	{23, 26, SPECIES_SNOVER},
	{23, 26, SPECIES_SNEASEL},
	{23, 26, SPECIES_CUBCHOO},
	{23, 26, SPECIES_CUBCHOO},
	{23, 26, SPECIES_CUBCHOO},
	{23, 26, SPECIES_SNOVER},
	{23, 26, SPECIES_SNEASEL},
	{23, 26, SPECIES_CUBCHOO},
	{23, 26, SPECIES_CUBCHOO},
	{26, 26, SPECIES_CUBCHOO},
	{26, 26, SPECIES_CUBCHOO},
};

static const struct WildPokemonInfo sFrozenForest_LandMonsInfoNight = {15, sFrozenForest_LandMonsNight};

static const struct WildPokemon sRoute11_LandMonsNight[] =
{
	{26, 29, SPECIES_NOCTOWL},
	{26, 29, SPECIES_EXEGGCUTE},
	{26, 29, SPECIES_SPOINK},
	{26, 29, SPECIES_SPOINK},
	{26, 29, SPECIES_GULPIN},
	{26, 29, SPECIES_MEDITITE},
	{26, 29, SPECIES_MEDITITE},
	{27, 29, SPECIES_TOGEDEMARU},
	{29, 29, SPECIES_NOCTOWL},
	{29, 29, SPECIES_GULPIN},
	{29, 29, SPECIES_NOCTOWL},
	{29, 29, SPECIES_GULPIN},
};

static const struct WildPokemonInfo sRoute11_LandMonsInfoNight = {15, sRoute11_LandMonsNight};

static const struct WildPokemon sRoute12_LandMonsNight[] =
{
	{29, 32, SPECIES_HOOTHOOT},
	{33, 36, SPECIES_ROCKRUFF},
	{33, 36, SPECIES_GOTHITA},
	{33, 36, SPECIES_MIENFOO},
	{33, 36, SPECIES_PONYTA},
	{33, 36, SPECIES_SNUBBULL},
	{34, 36, SPECIES_GOTHITA},
	{34, 36, SPECIES_MIENFOO},
	{34, 36, SPECIES_DEERLING_SUMMER},
	{33, 36, SPECIES_DEERLING_SUMMER},
	{34, 36, SPECIES_NOCTOWL},
	{35, 36, SPECIES_DEDENNE},
};

static const struct WildPokemonInfo sRoute12_LandMonsInfoNight = {15, sRoute12_LandMonsNight};

static const struct WildPokemon sRoute14_LandMonsNight[] =
{
	{37, 40, SPECIES_PELIPPER},
	{37, 40, SPECIES_BIBAREL},
	{37, 40, SPECIES_GOLDUCK},
	{37, 40, SPECIES_GASTRODON},
	{37, 40, SPECIES_FLOATZEL},
	{36, 40, SPECIES_SLOWPOKE},
	{37, 40, SPECIES_GLOOM},
	{37, 40, SPECIES_GLOOM},
	{38, 40, SPECIES_FLOATZEL},
	{37, 40, SPECIES_SLOWPOKE},
	{25, 30, SPECIES_MORELULL},
	{25, 30, SPECIES_MORELULL},
};

static const struct WildPokemonInfo sRoute14_LandMonsInfoNight = {15, sRoute14_LandMonsNight};

static const struct WildPokemon sVivillWoods_LandMonsNight[] =
{
	{30, 35, SPECIES_WEEDLE},
	{30, 35, SPECIES_WURMPLE},
	{30, 35, SPECIES_SCATTERBUG},
	{38, 41, SPECIES_COTTONEE},
	{39, 41, SPECIES_SWADLOON},
	{38, 41, SPECIES_PETILIL},
	{39, 41, SPECIES_SPEWPA},
	{39, 41, SPECIES_KAKUNA},
	{39, 41, SPECIES_SILCOON},
	{39, 41, SPECIES_CASCOON},
	{39, 41, SPECIES_SILCOON},
	{39, 41, SPECIES_CASCOON},
};

static const struct WildPokemonInfo sVivillWoods_LandMonsInfoNight = {15, sVivillWoods_LandMonsNight};

static const struct WildPokemon sRoute17_LandMonsNight[] =
{
	{47, 50, SPECIES_NOCTOWL},
	{47, 50, SPECIES_PELIPPER},
	{47, 50, SPECIES_NOCTOWL},
	{47, 50, SPECIES_PELIPPER},
	{47, 50, SPECIES_NOCTOWL},
	{47, 50, SPECIES_NOCTOWL},
	{47, 50, SPECIES_NOCTOWL},
	{47, 50, SPECIES_NOCTOWL},
	{48, 50, SPECIES_ZANGOOSE},
	{48, 50, SPECIES_SEVIPER},
	{40, 45, SPECIES_BAGON},
	{40, 45, SPECIES_BAGON},
};

static const struct WildPokemonInfo sRoute17_LandMonsInfoNight = {15, sRoute17_LandMonsNight};

static const struct WildPokemon sCootesBog_LandMonsNight[] =
{
	{48, 52, SPECIES_CROAGUNK},
	{49, 52, SPECIES_QUAGSIRE},
	{48, 52, SPECIES_CROAGUNK},
	{50, 52, SPECIES_SLIGGOO},
	{50, 52, SPECIES_SLIGGOO},
	{51, 52, SPECIES_DRAPION},
	{49, 52, SPECIES_CARNIVINE},
	{49, 52, SPECIES_GLOOM},
	{49, 52, SPECIES_GLOOM},
	{52, 52, SPECIES_TOXICROAK},
	{49, 52, SPECIES_GLOOM},
	{52, 52, SPECIES_TOXICROAK},
};

static const struct WildPokemonInfo sCootesBog_LandMonsInfoNight = {15, sCootesBog_LandMonsNight};

static const struct WildPokemon sMagnoliaFields_LandMonsNight[] =
{
	{49, 53, SPECIES_NOCTOWL},
	{49, 53, SPECIES_FURFROU},
	{49, 53, SPECIES_TRANQUILL},
	{49, 53, SPECIES_MUDSDALE},
	{49, 53, SPECIES_MUDSDALE},
	{49, 53, SPECIES_GOGOAT},
	{49, 53, SPECIES_FURFROU},
	{49, 53, SPECIES_GOGOAT},
	{50, 53, SPECIES_MILTANK},
	{50, 53, SPECIES_MILTANK},
	{50, 53, SPECIES_MILTANK},
	{50, 53, SPECIES_TAUROS},
};

static const struct WildPokemonInfo sMagnoliaFields_LandMonsInfoNight = {15, sMagnoliaFields_LandMonsNight};

static const struct WildPokemon sRoute18_LandMonsNight[] =
{
	{53, 57, SPECIES_NOCTOWL},
	{53, 57, SPECIES_SKUNTANK},
	{53, 57, SPECIES_NOCTOWL},
	{53, 57, SPECIES_SKUNTANK},
	{53, 57, SPECIES_BOUFFALANT},
	{53, 57, SPECIES_BOUFFALANT},
	{53, 57, SPECIES_NOCTOWL},
	{53, 57, SPECIES_SKUNTANK},
	{53, 57, SPECIES_SUDOWOODO},
	{53, 57, SPECIES_SUDOWOODO},
	{53, 57, SPECIES_SUDOWOODO},
	{53, 57, SPECIES_HAPPINY},
};

static const struct WildPokemonInfo sRoute18_LandMonsInfoNight = {15, sRoute18_LandMonsNight};

static const struct WildPokemon sRedwoodForest_LandMonsNight[] =
{
	{55, 65, SPECIES_ARIADOS},
	{55, 65, SPECIES_VIGOROTH},
	{55, 65, SPECIES_ARIADOS},
	{55, 65, SPECIES_VIGOROTH},
	{55, 65, SPECIES_URSARING},
	{55, 65, SPECIES_URSARING},
	{60, 65, SPECIES_HERACROSS},
	{60, 65, SPECIES_KOMALA},
	{60, 65, SPECIES_KOMALA},
	{60, 65, SPECIES_KOMALA},
	{60, 65, SPECIES_PASSIMIAN},
	{60, 65, SPECIES_ORANGURU},
};

static const struct WildPokemonInfo sRedwoodForest_LandMonsInfoNight = {15, sRedwoodForest_LandMonsNight};

const struct WildPokemonHeader gWildMonMorningHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(ROUTE_6),
		.mapNum = MAP_NUM(ROUTE_6),
		.landMonsInfo = &sRoute6_LandMonsInfoMorning,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct WildPokemonHeader gWildMonEveningHeaders[] =
{
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct WildPokemonHeader gWildMonNightHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(ROUTE_2),
		.mapNum = MAP_NUM(ROUTE_2),
		.landMonsInfo = &sRoute2_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_3),
		.mapNum = MAP_NUM(ROUTE_3),
		.landMonsInfo = &sRoute3_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_4),
		.mapNum = MAP_NUM(ROUTE_4),
		.landMonsInfo = &sRoute4_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(GRIM_WOODS),
		.mapNum = MAP_NUM(GRIM_WOODS),
		.landMonsInfo = &sGrimWoods_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_5),
		.mapNum = MAP_NUM(ROUTE_5),
		.landMonsInfo = &sRoute5_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_6),
		.mapNum = MAP_NUM(ROUTE_6),
		.landMonsInfo = &sRoute6_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_7),
		.mapNum = MAP_NUM(ROUTE_7),
		.landMonsInfo = &sRoute7_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_8),
		.mapNum = MAP_NUM(ROUTE_8),
		.landMonsInfo = &sRoute8_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(FROZEN_FOREST),
		.mapNum = MAP_NUM(FROZEN_FOREST),
		.landMonsInfo = &sFrozenForest_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_11),
		.mapNum = MAP_NUM(ROUTE_11),
		.landMonsInfo = &sRoute11_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_12),
		.mapNum = MAP_NUM(ROUTE_12),
		.landMonsInfo = &sRoute12_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_14_B),
		.mapNum = MAP_NUM(ROUTE_14_B),
		.landMonsInfo = &sRoute14_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_14_C),
		.mapNum = MAP_NUM(ROUTE_14_C),
		.landMonsInfo = &sRoute14_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VIVILL_WOODS),
		.mapNum = MAP_NUM(VIVILL_WOODS),
		.landMonsInfo = &sVivillWoods_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_17),
		.mapNum = MAP_NUM(ROUTE_17),
		.landMonsInfo = &sRoute17_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(COOTES_BOG),
		.mapNum = MAP_NUM(COOTES_BOG),
		.landMonsInfo = &sCootesBog_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_18_B),
		.mapNum = MAP_NUM(ROUTE_18_B),
		.landMonsInfo = &sRoute18_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(MAGNOLIA_FIELDS),
		.mapNum = MAP_NUM(MAGNOLIA_FIELDS),
		.landMonsInfo = &sMagnoliaFields_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(REDWOOD_FOREST),
		.mapNum = MAP_NUM(REDWOOD_FOREST),
		.landMonsInfo = &sRedwoodForest_LandMonsInfoNight,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct SwarmData gSwarmTable[] =
{
	{
		.mapName = MAPSEC_ROUTE_2,
		.species = SPECIES_POOCHYENA,
	},
	{
		.mapName = MAPSEC_ROUTE_3,
		.species = SPECIES_SENTRET,
	},
	{
		.mapName = MAPSEC_ROUTE_4,
		.species = SPECIES_BURMY,
	},
	{
		.mapName = MAPSEC_CINDER_VOLCANO,
		.species = SPECIES_VULPIX,
	},
	{
		.mapName = MAPSEC_ROUTE_5,
		.species = SPECIES_ELGYEM,
	},
	{
		.mapName = MAPSEC_VALLEY_CAVE,
		.species = SPECIES_DUNSPARCE,
	},
	{
		.mapName = MAPSEC_ROUTE_6,
		.species = SPECIES_SMEARGLE,
	},
	{
		.mapName = MAPSEC_ROUTE_7,
		.species = SPECIES_MR_MIME,
	},
	{
		.mapName = MAPSEC_ROUTE_8,
		.species = SPECIES_STANTLER,
	},
	{
		.mapName = MAPSEC_ROUTE_9,
		.species = SPECIES_KARRABLAST,
	},
	{
		.mapName = MAPSEC_ROUTE_10,
		.species = SPECIES_SHELMET,
	},
	{
		.mapName = MAPSEC_ROUTE_11,
		.species = SPECIES_GLAMEOW,
	},
	{
		.mapName = MAPSEC_THUNDERCAP_MOUNTAIN,
		.species = SPECIES_JOLTIK,
	},
	{
		.mapName = MAPSEC_THUNDERCAP_MOUNTAIN,
		.species = SPECIES_FERROSEED,
	},
	{
		.mapName = MAPSEC_ROUTE_12,
		.species = SPECIES_SWIRLIX,
	},
	{
		.mapName = MAPSEC_ROUTE_12,
		.species = SPECIES_SPRITZEE,
	},
	{
		.mapName = MAPSEC_VIVILL_WOODS,
		.species = SPECIES_PIKACHU,
	},
	{
		.mapName = MAPSEC_ANTISIS_SEWERS,
		.species = SPECIES_WHIRLIPEDE,
	},
	{
		.mapName = MAPSEC_ROUTE_17,
		.species = SPECIES_VOLBEAT,
	},
	{
		.mapName = MAPSEC_ROUTE_17,
		.species = SPECIES_ILLUMISE,
	},
	{
		.mapName = MAPSEC_COOTES_BOG,
		.species = SPECIES_CROCONAW,
	},
	{
		.mapName = MAPSEC_MAGNOLIA_FIELDS,
		.species = SPECIES_QUILAVA,
	},
	{
		.mapName = MAPSEC_ROUTE_18,
		.species = SPECIES_BAYLEEF,
	},
	{
		.mapName = MAPSEC_REDWOOD_FOREST,
		.species = SPECIES_NINCADA,
	},
};

#endif

#ifdef SWARM_CHANGE_HOURLY
const u8 gSwarmOrders[31][24] =
{
	{2, 1, 14, 21, 5, 16, 3, 23, 7, 4, 18, 19, 13, 17, 6, 0, 8, 9, 20, 22, 10, 11, 15, 12},
	{16, 19, 13, 23, 7, 9, 21, 17, 22, 8, 4, 3, 6, 0, 11, 20, 12, 1, 10, 2, 15, 14, 18, 5},
	{17, 8, 16, 6, 12, 19, 18, 3, 14, 22, 13, 11, 23, 2, 7, 21, 20, 10, 5, 15, 9, 0, 1, 4},
	{13, 6, 15, 3, 14, 12, 0, 18, 10, 5, 2, 17, 16, 7, 9, 1, 4, 19, 11, 23, 21, 8, 20, 22},
	{12, 7, 18, 13, 10, 2, 5, 14, 11, 23, 20, 22, 8, 15, 17, 4, 19, 16, 0, 6, 21, 1, 9, 3},
	{8, 18, 12, 15, 20, 0, 1, 13, 5, 11, 14, 21, 17, 10, 4, 16, 22, 6, 2, 19, 23, 3, 7, 9},
	{13, 11, 7, 20, 22, 3, 14, 10, 18, 6, 5, 12, 15, 23, 19, 17, 21, 0, 9, 8, 2, 16, 4, 1},
	{11, 20, 4, 2, 16, 17, 13, 12, 0, 10, 15, 14, 1, 19, 5, 8, 9, 18, 7, 21, 3, 6, 22, 23},
	{22, 18, 11, 17, 2, 9, 20, 16, 0, 13, 1, 6, 3, 14, 15, 10, 5, 8, 23, 4, 12, 21, 19, 7},
	{2, 5, 11, 7, 3, 23, 19, 1, 9, 16, 13, 15, 21, 8, 20, 12, 18, 4, 14, 10, 6, 17, 22, 0},
	{10, 18, 5, 1, 13, 15, 22, 2, 4, 3, 17, 9, 19, 21, 0, 8, 16, 11, 12, 14, 7, 23, 6, 20},
	{6, 13, 0, 4, 22, 10, 23, 17, 8, 1, 5, 11, 2, 3, 12, 19, 15, 20, 18, 9, 14, 7, 21, 16},
	{0, 22, 17, 11, 8, 15, 9, 4, 2, 7, 21, 13, 12, 6, 14, 18, 10, 23, 1, 3, 5, 20, 16, 19},
	{15, 16, 20, 5, 4, 6, 2, 21, 3, 19, 7, 8, 14, 13, 10, 23, 11, 18, 22, 0, 17, 12, 1, 9},
	{7, 12, 2, 0, 18, 4, 16, 8, 20, 17, 22, 23, 9, 1, 5, 14, 6, 21, 15, 3, 13, 19, 10, 11},
	{21, 4, 8, 14, 15, 7, 17, 19, 6, 0, 9, 1, 20, 11, 2, 23, 12, 18, 3, 16, 22, 13, 5, 10},
	{5, 3, 9, 19, 6, 14, 15, 10, 21, 7, 12, 0, 20, 16, 23, 13, 1, 22, 8, 11, 4, 2, 17, 18},
	{18, 0, 1, 19, 16, 21, 4, 5, 2, 9, 23, 7, 20, 12, 22, 15, 3, 6, 8, 11, 13, 17, 14, 10},
	{15, 16, 21, 9, 19, 6, 12, 20, 13, 18, 8, 0, 10, 22, 3, 7, 23, 5, 4, 17, 11, 2, 14, 1},
	{3, 14, 20, 16, 15, 13, 8, 4, 1, 21, 10, 5, 12, 9, 23, 6, 0, 17, 19, 7, 11, 22, 2, 18},
	{9, 7, 23, 12, 0, 1, 4, 15, 19, 17, 10, 2, 22, 5, 16, 11, 3, 6, 21, 13, 20, 18, 8, 14},
	{1, 21, 19, 17, 15, 23, 10, 6, 9, 12, 11, 0, 4, 3, 8, 22, 7, 14, 16, 20, 18, 5, 13, 2},
	{4, 9, 22, 12, 23, 11, 7, 5, 6, 2, 21, 20, 18, 14, 1, 10, 3, 15, 13, 17, 16, 19, 8, 0},
	{1, 2, 3, 10, 17, 5, 4, 22, 12, 20, 14, 9, 0, 18, 23, 15, 7, 13, 21, 11, 8, 19, 16, 6},
	{20, 23, 0, 19, 8, 18, 11, 22, 15, 14, 6, 2, 4, 12, 13, 3, 17, 7, 21, 16, 1, 9, 5, 10},
	{23, 10, 17, 19, 9, 14, 6, 7, 16, 12, 15, 18, 0, 4, 11, 2, 1, 3, 8, 5, 20, 22, 13, 21},
	{15, 21, 6, 18, 11, 22, 8, 4, 1, 7, 19, 16, 5, 20, 3, 10, 14, 2, 17, 12, 0, 9, 23, 13},
	{14, 17, 10, 9, 1, 8, 11, 7, 23, 15, 0, 5, 20, 19, 2, 16, 13, 3, 6, 18, 22, 4, 12, 21},
	{19, 15, 6, 22, 0, 20, 23, 11, 17, 14, 13, 16, 10, 1, 21, 9, 2, 12, 4, 7, 18, 5, 3, 8},
	{6, 4, 19, 16, 21, 22, 23, 9, 8, 20, 3, 10, 11, 12, 18, 5, 14, 2, 13, 1, 7, 15, 0, 17},
	{3, 18, 22, 8, 6, 1, 2, 0, 12, 14, 16, 4, 7, 9, 5, 13, 23, 17, 21, 20, 19, 10, 11, 15},
};
#endif

const u16 gSwarmTableLength = NELEMS(gSwarmTable);
