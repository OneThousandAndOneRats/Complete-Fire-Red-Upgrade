#include "../defines_battle.h"
#include "../../include/battle.h"
#include "../../include/constants/trainer_classes.h"
#include "../../include/constants/trainers.h"
#include "../../include/constants/opponents.h"
#include "../../include/constants/battle_ai.h"
#include "../../include/easy_text.h"
#include "../../include/new/build_pokemon_2.h"
#include "../../include/constants/items.h"

//Ability_Hidden
//Ability_Random_1_2
//Ability_1
//Ability_2
//Ability_RandomAll
//Different Structs in \include\battle.h

/*
https://www.pokecommunity.com/showthread.php?t=443915
0 - won't use moves that have no or a negative effect AI_SCRIPT_CHECK_BAD_MOVE
1 - will actually create some difference in viability scores based on basic calculations AI_SCRIPT_SEMI_SMART
2 - starts understanding things like type effectiveness, damage and fainting AI_SCRIPT_CHECK_GOOD_MOVE
3 - with a chance of about 3/10, some status moves will get priority on the first turn (list of move scripts at 081DBAA7)
4 - with a chance of about 5/10, move effects in this list will get priority: http://pastebin.com/raw.php?i=TP5gCBHp
5 - with a chance of about 4/10, non-damaging moves will get priority
6 - if there are other pokes left on the ai's team, with a chance of a bit more than 6/10 it will give priority to non-damaging moves. chance raises to a bit more than 9/10 if the user (possibly also its ally) has baton pass
7 - 0, 1 and 2 all in one
8 - ai will start looking at health percentages and decide using moves based on that
9 - broken/unfinished, does nothing
10 through 28 - nop
29 - roamer; will attempt to flee on the first turn
30 - safari
31 - unused; will flee on 20% health and lower
*/


//PARTY_FLAG_CUSTOM_MOVES
//PARTY_FLAG_HAS_ITEM

//~~~~~~~~~~~~~~~~~~|Pallet Town Starter Fight|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_RivalLabFire[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_FENNEKIN,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_RivalLabGrass[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_GROOKEY,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_RivalLabWater[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_TOTODILE,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 22 Early Rival Fight|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_RivalEarly22Fire[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_WOOLOO,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_FENNEKIN,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_RivalEarly22Grass[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_WOOLOO,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_GROOKEY,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_RivalEarly22Water[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_WOOLOO,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_TOTODILE,
    },
};

//~~~~~~~~~~~~~~~~~~|Viridian Forest|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVFRick[] = {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_BLIPBUG,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_KRICKETOT,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVFDoug[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_BLIPBUG,
    },
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_DOTTLER,
    },
     {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_BLIPBUG,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVFSammy[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_COMBEE,
    },
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_SEWADDLE,
    },
    
};

const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVFCharlie[] = {
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_SEWADDLE,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_KRICKETOT,
    },
     {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_SEWADDLE,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVFAnthony[] = {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_KRICKETOT,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_BLIPBUG,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_SEWADDLE,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_COMBEE,
    },
    
};

//~~~~~~~~~~~~~~~~~~|Pewter Gym|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_CamperPGLiam[] = { //TODO MAYBE UPDATE THIS TO A ENGINEER
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_KRICKETOT,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_IGGLYBUFF,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_LeaderPGBrock[] = {
    {
        
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_WHISMUR,
        .moves = {
            MOVE_ECHOEDVOICE,
            MOVE_POUND,
            MOVE_ASTONISH,
            MOVE_MELODY,
        },
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_JIGGLYPUFF,
        .moves = {
            MOVE_BLUES,
            MOVE_DISARMINGVOICE,
            MOVE_SING,
            MOVE_PLAYNICE,
        },
        .ability = Ability_2,
    },
    {
        
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_KRICKETUNE,
        .moves = {
            MOVE_BLUES,
            MOVE_STRUGGLEBUG,
            MOVE_ABSORB,
            MOVE_FURYCUTTER,
        },
        .ability = Ability_Hidden,
    },
    
};

//~~~~~~~~~~~~~~~~~~|Route 3|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_LassR3Janice[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_MARILL,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_GLAMEOW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR3Colton[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_COMBEE,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_DOTTLER,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_PARAS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR3Ben[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_MANKEY,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_NIDORAN_M,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_NIDORAN_F,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR3Greg[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_NINCADA,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_DOTTLER,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_CUTIEFLY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR3Calvin[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_AIPOM,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_POOCHYENA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR3Sally[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_FINNEON,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_FLAAFFY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR3James[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_KRICKETUNE,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_KRICKETUNE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR3Robin[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_HOOTHOOT,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SHROOMISH,
    },
};


//~~~~~~~~~~~~~~~~~~|Mt Moon 1F|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherMTMF1Kent[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_DOTTLER,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_VOLBEAT,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_LassMTMF1Iris[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_BIDOOF,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_CLEFAIRY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_NerdMTMF1Jovan[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_TYNAMO,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_KLINK,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_SHINX,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherMTMF1Robby[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_DOTTLER,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_ILLUMISE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassMTMF1Miriam[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_SUNKERN,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_SUNKERN,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_WOOLOO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterMTM1FJosh[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_PIDGEY,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ODDISH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerMTM1FMarcos[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_ARON,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ROGGENROLA,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_GEODUDE,
    },
};

//~~~~~~~~~~~~~~~~~~|Mt Moon B2F|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_RocketMTMB2F_1[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_POOCHYENA,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_NICKIT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketMTMB2F_2[] = { 
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ZUBAT,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_PANCHAM,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_RocketMTMB2F_3[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_DEINO,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_RocketMTMB2F_4[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_TEDDIURSA,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_CROAGUNK,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_NIDORINO,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_NerdMTMB2FMiguel[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_TYNAMO,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_KLINK,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_PORYGON,
    },
};


//~~~~~~~~~~~~~~~~~~|Mt Moon Summit|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_HikerMTSDon[] = {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_DRUDDIGON,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_TURTONATOR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerMTSRon[] = {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_CAMERUPT,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_MAMOSWINE,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_STONJOURNER,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerMTSJon[] = {
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_CLAYDOL,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_AGGRON,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_CRUSTLE,
    },
};

//~~~~~~~~~~~~~~~~~~|Route 4|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_LassR4Crissy[] = {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_URSARING,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_NIDOQUEEN,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_WIGGLYTUFF,
    },
};

//~~~~~~~~~~~~~~~~~~|Cerulean City|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonItemCustomMoves sParty_RivalCeruleanCityFire[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_MANKEY,
        .moves = {
            MOVE_CLAW,
            MOVE_KARATECHOP,
            MOVE_FURYSWIPES,
            MOVE_LOWKICK,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_STARYU,
        .moves = {
            MOVE_SWIFT,
            MOVE_WATERGUN,
            MOVE_RECOVER,
            MOVE_COSMICRAY,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARON,
        .moves = {
            MOVE_PROTECT,
            MOVE_ROCKTOMB,
            MOVE_METALCLAW,
            MOVE_MUDSLAP,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BRAIXEN,
        .moves = {
            MOVE_FLAMECHARGE,
            MOVE_PRESTO,
            MOVE_FIRESPIN,
            MOVE_CONFUZZLE,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalCeruleanCityGrass[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_MANKEY,
        .moves = {
            MOVE_CLAW,
            MOVE_KARATECHOP,
            MOVE_FURYSWIPES,
            MOVE_LOWKICK,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_NUMEL,
        .moves = {
            MOVE_FLAMEBURST,
            MOVE_MAGNITUDE,
            MOVE_FOCUSENERGY,
            MOVE_TACKLE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARON,
        .moves = {
            MOVE_PROTECT,
            MOVE_ROCKTOMB,
            MOVE_METALCLAW,
            MOVE_MUDSLAP,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_THWACKEY,
        .moves = {
            MOVE_DRUMROLL,
            MOVE_RAZORLEAF,
            MOVE_SCREECH,
            MOVE_TAUNT,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalCeruleanCityWater[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_MANKEY,
        .moves = {
            MOVE_CLAW,
            MOVE_KARATECHOP,
            MOVE_FURYSWIPES,
            MOVE_LOWKICK,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_PETILIL,
        .moves = {
            MOVE_SLEEPPOWDER,
            MOVE_MEGADRAIN,
            MOVE_LEECHSEED,
            MOVE_GROWTH,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARON,
        .moves = {
            MOVE_PROTECT,
            MOVE_ROCKTOMB,
            MOVE_METALCLAW,
            MOVE_MUDSLAP,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_CROCONAW,
        .moves = {
            MOVE_ICEFANG,
            MOVE_BEASTSENSE,
            MOVE_CLAW,
            MOVE_WATERGUN,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMCeruleanGymLuis[] = { //TODO: UPDATE THIS TO A MALE PICKNICKER
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_AIPOM,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BUNNELBY,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_BIBAREL,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_PicknickerCeruleanGymDiana[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MEOWTH,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_GLAMEOW,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_LeaderCGMisty[] = {
    {
        
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_EEVEE,
        .moves = {
            MOVE_QUICKATTACK,
            MOVE_BITE,
            //MOVE_SWIFT,
            MOVE_RETURN,
            MOVE_SANDATTACK,
        },
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_LITLEO,
        .moves = {
            MOVE_NOBLEROAR,
            //MOVE_HEADBUTT,
            MOVE_RETURN,
            MOVE_EMBER,
            MOVE_WORKUP,
        },
        .ability = Ability_1,
    },
    {
        
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_STUFFUL,
        .moves = {
            MOVE_BRUTALSWING,
           // MOVE_FLAIL,
            MOVE_RETURN,
            MOVE_PAYBACK,
            MOVE_BABYDOLLEYES,
        },
        .ability = Ability_1,
    },
    {
        
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DIGGERSBY,
        .moves = {
            //MOVE_TAKEDOWN,
            MOVE_RETURN,
            MOVE_DOUBLEKICK,
            MOVE_MUDSHOT,
            MOVE_QUICKATTACK,
        },
        .ability = Ability_Hidden,
    },
    
};

const struct TrainerMonNoItemDefaultMoves sParty_RocketCeruleanCity[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SALANDIT,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_MIGHTYENA,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 24|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR24Cale[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CUTIEFLY,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CUTIEFLY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR24Ali[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_FLABEBE,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_GOOMY,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_HORSEA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR24Timmy[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ABRA,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_WOOPER,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SPOINK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR24Reli[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_NOIBAT,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_CLEFAIRY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR24Ethan[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_HOUNDOUR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketR24[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CROAGUNK,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_INKAY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR24Shane[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_GOTHITA,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_STARYU,
    },
};

//~~~~~~~~~~~~~~~~~~|Route 25|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_HikerR25Franklin[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SANDSHREW,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_ARON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR25Wayne[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_GEODUDE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ROGGENROLA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR25Joey[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_WOOPER,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_CUTIEFLY,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_LUXIO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR25Dan[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_STARYU,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_NUMEL,
    },
    
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR25Kelsey[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_APPLIN,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PETILIL,
    },
    
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR25Nob[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SILICOBRA,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ROGGENROLA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR25Flint[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_NATU,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_MARILL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR25Chad[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_KADABRA,
    },
    
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR25Haley[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_REMORAID,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_HORSEA,
    },
    
};


//~~~~~~~~~~~~~~~~~~|Route 6|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR6Keigo[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_CUTIEFLY,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_SWADLOON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR6Ricky[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MEDITITE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_HELIOPTILE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_TEDDIURSA,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR6Nancy[]= {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_MORELULL,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_GOTHITA,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR6Elijah[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_JOLTIK,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR6Isabelle[]= {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_FINNEON,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_MILCERY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR6Jeff[]= {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_NUMEL,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SALANDIT,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_TYROGUE,
    },
};

//~~~~~~~~~~~~~~~~~~|Route 11|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR11Eddie[]= {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_TEDDIURSA,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_CROAGUNK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GamerR11Hugo[]= {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_PANCHAM,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DROWZEE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_EngineerR11Bernie[]= {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_KLINK,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_YAMPER,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR11Dave[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_HAWLUCHA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR11Dillon[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SKRELP,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GamerR11Jasper[]= {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BINACLE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MEDITITE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MEOWTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_EngineerR11Braxton[]= {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_STUNFISK,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_HELIOPTILE,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_BRONZOR,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_GamerR11Darian[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_HOUNDOUR,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_QUAGSIRE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterR11Yasu[]= {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_STARYU,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PIDGEOTTO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GamerR11Dirk[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DUBWOOL,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_BRELOOM,
    },
};


//~~~~~~~~~~~~~~~~~~|S.S. Anne|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnneTrevor[]= {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_HORSEA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_BINACLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnneEdmond[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_REMORAID,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_CHINCHOU,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_CROCONAW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanSSAnneBarny[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_CARVANHA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnnePhilip[]= {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_STARYU,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnneHuey[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_RELICANTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnneDylan[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SPHEAL,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_OCTILLERY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnneDuncan[]= {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_WOOPER,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_BIBAREL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SailorSSAnneLeonard[]= {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_AZURILL,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_MARILL,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_AZUMARILL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GentlemanSSAnneThomas[]= {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_KADABRA,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_THIEVUL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GentlemanSSAnneArthur[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_NIDORINA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassSSAnneAnn[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SUNFLORA,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GLOOM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterSSAnneTyler[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_LOUDRED,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_PHANTUMP,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SANDSLASH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanSSAnneDale[]= {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_FINNEON,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_GYARADOS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GentlemanSSAnneBrooks[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_MEDITITE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_MEOWTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassSSAnneDawn[]= {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_FLAAFFY,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_BEWEAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GentlemanSSAnneLamar[]= {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_TEDDIURSA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_MURKROW,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_SILICOBRA,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalSSAnneWater[]= {
    
    
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ELGYEM,
        .moves = {
            MOVE_BLACKHOLE,
            MOVE_COSMICRAY,
            MOVE_HEADBUTT,
            MOVE_HEALBLOCK,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_HONEDGE,
        .moves = {
            MOVE_AERIALACE,
            MOVE_RUSTYRIVET,
            MOVE_SWORDSDANCE,
            MOVE_FURYCUTTER
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_HOUNDOOM,
        .moves = {
            MOVE_BEATUP,
            MOVE_THUNDERFANG,
            MOVE_EMBER,
            MOVE_HOWL,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_CROCONAW,
        .moves = {
            MOVE_FERALBITE,
            MOVE_ICEFANG,
            MOVE_WATERPULSE,
            MOVE_BEASTSENSE,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalSSAnneGrass[]= {
    
    
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ELGYEM,
        .moves = {
            MOVE_BLACKHOLE,
            MOVE_COSMICRAY,
            MOVE_HEADBUTT,
            MOVE_HEALBLOCK,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_HONEDGE,
        .moves = {
            MOVE_AERIALACE,
            MOVE_RUSTYRIVET,
            MOVE_SWORDSDANCE,
            MOVE_FURYCUTTER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_CARVANHA,
        .moves = {
            MOVE_AQUAJET,
            MOVE_FERALBITE,
            MOVE_ICEFANG,
            MOVE_SWAGGER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_THWACKEY,
        .moves = {
            MOVE_BEAMEDNOTE,
            MOVE_KNOCKOFF,
            MOVE_RAZORLEAF,
            MOVE_SCREECH,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};
const struct TrainerMonItemCustomMoves sParty_RivalSSAnneFire[]= {
    
    
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ELGYEM,
        .moves = {
            MOVE_BLACKHOLE,
            MOVE_COSMICRAY,
            MOVE_HEADBUTT,
            MOVE_HEALBLOCK,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_HONEDGE,
        .moves = {
            MOVE_AERIALACE,
            MOVE_RUSTYRIVET,
            MOVE_SWORDSDANCE,
            MOVE_FURYCUTTER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_TREVENANT,
        .moves = {
            MOVE_SHADOWCLAW,
            MOVE_LEECHSEED,
            MOVE_FEINTATTACK,
            MOVE_INGRAIN,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BRAIXEN,
        .moves = {
            MOVE_PRESTO,
            MOVE_MAGICMISSILE,
            MOVE_FIRESPIN,
            MOVE_FLAMECHARGE,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};



//~~~~~~~~~~~~~~~~~~|Vermillion Gym|~~~~~~~~~~~~~~~~~~//

const struct TrainerMonNoItemDefaultMoves sParty_SailorVermillionGymDwayne[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_FLOETTE,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_RIBOMBEE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_EngineerVermillionGymBaily[]= {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_MARILL,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_MIME_JR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GentlemanVermillionGymTucker[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SYLVEON,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_LeaderVermillionGymLTSurge[] = {
    {  
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_FLOETTE,
        .moves = {
            MOVE_WISH,
            MOVE_MAGICALLEAF,
            //MOVE_FAIRYWIND,
            MOVE_DAZZLINGGLEAM,
            MOVE_LUCKYCHANT,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_CLEFAIRY,
        .moves = {
            MOVE_PULSAR,
            MOVE_STARBURST,
            MOVE_SING,
            //MOVE_DISARMINGVOICE,
            MOVE_DAZZLINGGLEAM,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_MAWILE,
        .moves = {
            MOVE_FEINTATTACK,
            MOVE_VICEGRIP,
            MOVE_FAIRYWIND,
            //MOVE_DAZZLINGGLEAM,
            MOVE_ASTONISH,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_AZUMARILL,
        .moves = {
            MOVE_AQUATAIL,
            MOVE_PLAYROUGH,
            MOVE_DEFENSECURL,
            MOVE_ROLLOUT,
        },
        .ability = Ability_2,
    },
};

//~~~~~~~~~~~~~~~~~~|Route 9|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR9Alicia[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_MILCERY,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ALCREMIE_STRAWBERRY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR9Jeremy[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_HIPPOPOTAS,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GRAVELER,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SANDSLASH,
    },
    
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR9Chris[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_AIPOM,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SWELLOW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR9Brent[]= {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_WHIRLIPEDE,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_VESPIQUEN,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_LEAVANNY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR9Alan[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BOLDORE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_GRAVELER,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherR9Conner[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_VOLBEAT,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ILLUMISE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR9Drew[]= {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GLAMEOW,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PERSIAN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR9Brice[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GIGALITH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR9Caitlin[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SWIRLIX,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_TANGELA,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 10|~~~~~~~~~~~~~~~~~~//
//North 
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR10Heidi[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_EEVEE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_DUBWOOL,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_TYNAMO,
    },
};

//~~~~~~~~~~~~~~~~~~|Rock Tunnel|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacRTAshton[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SANDYGAST,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MURKROW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacRTWinston[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_DRUDDIGON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerRTMartha[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_STARYU,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacRTSteve[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MINIOR_SHIELD,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_MAGNETON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerRTAllen[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_ARON,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_BOLDORE,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SKARMORY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerRTEric[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_DIGLETT,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DUGTRIO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerRTLenny[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_NUMEL,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DIGGERSBY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerRTOliver[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_QUAGSIRE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerRTLucas[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SOLROCK,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_LUNATONE,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_PicknickerRTSofia[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_GOLETT,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SALANDIT,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_HikerRTDudley[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_BALTOY,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_GRAVELER,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SANDSLASH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacRTCooper[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_GOOMY,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_DEINO,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_PicknickerRTLeah[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_YAMPER,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BOLTUND,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerRTAriana[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_HEATMOR,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_FLORGES_BLUE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerRTDana[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_BINACLE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SWADLOON,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_LITLEO,
    },

};

const struct TrainerMonNoItemDefaultMoves sParty_RocketRockTunnelA[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_HEATMOR,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_DUGTRIO,
    },

};
const struct TrainerMonNoItemDefaultMoves sParty_RocketRockTunnelB[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_PALOSSAND,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_BARBARACLE,
    },

};

//~~~~~~~~~~~~~~~~~~|Route 10|~~~~~~~~~~~~~~~~~~//
//South
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR10Carol[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DROWZEE,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_URSARING,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR10Clark[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_DWEBBLE,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_NUMEL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_HikerR10Trent[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_MINIOR_SHIELD,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacR10Herman[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SPOINK,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_OCTILLERY,
    },
};


//~~~~~~~~~~~~~~~~~~|Pokemon Tower|~~~~~~~~~~~~~~~~~~//
//Pre SilphScope //UPDATE THIS TO POST SILPH SCOPE
const struct TrainerMonItemCustomMoves sParty_RivalPkmTowerWater[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_LICKITUNG,
        .moves = {
            MOVE_SLAM,
            MOVE_SALTRUB,
            MOVE_TASTE,
            MOVE_KNOCKOFF,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_MISDREAVUS,
        .moves = {
            MOVE_THUNDERWAVE,
            MOVE_HEX,
            MOVE_FLOURISH,
            MOVE_CONFUZZLE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METALCLAW,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_HOUNDOOM,
        .moves = {
            MOVE_FIREFANG,
            MOVE_BEATUP,
            MOVE_THUNDERFANG,
            MOVE_BITE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_FERALIGATR,
        .moves = {
            MOVE_FERALBITE,
            MOVE_AQUATAIL,
            MOVE_ICEFANG,
            MOVE_BEASTSENSE,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalPkmTowerGrass[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_LICKITUNG,
        .moves = {
            MOVE_SLAM,
            MOVE_SALTRUB,
            MOVE_TASTE,
            MOVE_KNOCKOFF,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_MISDREAVUS,
        .moves = {
            MOVE_THUNDERWAVE,
            MOVE_HEX,
            MOVE_FLOURISH,
            MOVE_CONFUZZLE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METALCLAW,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SHARPEDO,
        .moves = {
            MOVE_ICEFANG,
            MOVE_AQUAJET,
            MOVE_SWAGGER,
            MOVE_FERALBITE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_RILLABOOM,
        .moves = {
            MOVE_DRUMBEATING,
            MOVE_KNOCKOFF,
            MOVE_BEAMEDNOTE,
            MOVE_SLAM,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};
const struct TrainerMonItemCustomMoves sParty_RivalPkmTowerFire[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_LICKITUNG,
        .moves = {
            MOVE_SLAM,
            MOVE_SALTRUB,
            MOVE_TASTE,
            MOVE_KNOCKOFF,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_MISDREAVUS,
        .moves = {
            MOVE_THUNDERWAVE,
            MOVE_HEX,
            MOVE_FLOURISH,
            MOVE_CONFUZZLE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METALCLAW,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_TREVENANT,
        .moves = {
            MOVE_SHADOWCLAW,
            MOVE_WILLOWISP,
            MOVE_LEECHSEED,
            MOVE_INGRAIN,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_DELPHOX,
        .moves = {
            MOVE_MYSTICALFIRE,
            MOVE_MAGICMISSILE,
            MOVE_PRESTO,
            MOVE_LIGHTSCREEN,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};
//~~~~~~~~~~~~~~~~~~|Route 8|~~~~~~~~~~~~~~~~~~//

const struct TrainerMonNoItemDefaultMoves sParty_LassR8Julia[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_APPLIN,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_SWIRLIX,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GamerR8Rich[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_HITMONTOP,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_HITMONCHAN,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_HITMONLEE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdR8Glenn[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_KLINK,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_HONEDGE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TwinsR8EliAnne[]= {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_CLEFABLE,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_WIGGLYTUFF,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR8Paige[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SNEASEL,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_MEOWSTIC,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdR8Leslie[]= {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_LILEEP,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_AMAURA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR8Andrea[]= {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_FLOETTE,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GOTHORITA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassR8Megan[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_FLORGES_BLUE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR8Jaren[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_WHIRLIPEDE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_WHIRLIPEDE,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SCOLIPEDE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR8Ricardo[]= {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_SKRELP,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_GOLBAT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_GamerR8Stan[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_VULPIX,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_PERSIAN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdR8Aidan[]= {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_THIEVUL,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_LAIRON,
    },
};
//~~~~~~~~~~~~~~~~~~|Route 16|~~~~~~~~~~~~~~~~~~//
//Pre-Pokeflute
const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleR16LeaJed[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_NINETALES,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_HOUNDOOM,
    },
};

//~~~~~~~~~~~~~~~~~~|Celadon Gym|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_LassCeladonGymKay[]= {
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_HONEDGE,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_LAIRON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyCeladonGymBridget[]= {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BRONZOR,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BELDUM,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_KLINK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolTrainerCeladonGymMary[]= {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_SKARMORY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_LassCeladonGymLisa[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MAGNETON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerCeladonGymTina[]= {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_KLINK,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BELDUM,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BRONZOR,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_HONEDGE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyCeladonGymLori[]= {
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_BRONZOR,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_HONEDGE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyCeladonGymTamia[]= {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_MAGNETON,
    },
};
const struct TrainerMonNoItemCustomMoves sParty_LeaderCeladonGymErika[] = {
    {  
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SKARMORY,
        .moves = {
            MOVE_SPIKES,
            MOVE_AIRCUTTER,
            MOVE_METALCLAW,
            MOVE_SWIFT,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_LAIRON,
        .moves = {
            MOVE_TAKEDOWN,
            MOVE_ROCKSLIDE,
            MOVE_IRONHEAD,
            MOVE_ROAR,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MAGNETON,
        .moves = {
            MOVE_FLASHCANNON,
            MOVE_ELECTROBALL,
            MOVE_THUNDERWAVE,
            MOVE_TRIATTACK,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_ZENHEADBUTT,
            MOVE_METALCLAW,
            MOVE_MAGNETRISE,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_DURALUDON,
        .moves = {
            MOVE_DRAGONTAIL,
            MOVE_BREAKINGSWIPE,
            MOVE_HONECLAWS,
            MOVE_METALCLAW,
        },
        .ability = Ability_1,
    },
};

//~~~~~~~~~~~~~~~~~~|Rocket Hideout|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_7[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SNEASEL,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_DEINO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_8[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_THIEVUL,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_MIGHTYENA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_9[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_MURKROW,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HOUNDOOM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_10[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_GLOOM,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_GOLBAT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_11[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_CROAGUNK,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_HYPNO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_12[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_CROAGUNK,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_CROAGUNK,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SKRELP,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SALAZZLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_13[] = {
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_MALAMAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_14[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_KADABRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_15[] = {
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_WEAVILE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_16[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_PANGORO,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_NINETALES,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_17[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_HONCHKROW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketHideout_18[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_MURKROW,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_TOXICROAK,
    },
};
const struct TrainerMonNoItemCustomMoves sParty_RocketBossHideoutGiovani[] = {
    {  
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_DODUO,
        .moves = {
            MOVE_UPROAR,
            MOVE_HARSHCLAW,
            MOVE_PLUCK,
            MOVE_AGILITY,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_CUBCHOO,
        .moves = {
            MOVE_BRINE,
            MOVE_FURYSWIPES,
            MOVE_ICYWIND,
            MOVE_CHARM,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MIGHTYENA,
        .moves = {
            MOVE_HUNTERMARK,
            MOVE_FERALBITE,
            MOVE_ASSURANCE,
            MOVE_SCARYFACE,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_LUXRAY,
        .moves = {
            MOVE_THUNDERFANG,
            MOVE_HARSHCLAW,
            MOVE_ROAR,
            MOVE_SWAGGER,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_NIDOKING,
        .moves = {
            MOVE_MEGAHORN,
            MOVE_HARSHCLAW,
            MOVE_CHIPAWAY,
            MOVE_POISONSTING,
        },
        .ability = Ability_1,
    },
};




const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerHope[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_GASTLY,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_HAUNTER,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerPatricia[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SHUPPET,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_GASTLY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerCarly[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_LITWICK,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_SANDYGAST,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerLaurel[]= {
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_TREVENANT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerJody[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_LITWICK,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SHUPPET,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerPaula[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_MISDREAVUS,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_SHEDINJA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerRuth[]= {
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_YAMASK,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_GASTLY,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_YAMASK,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_GASTLY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerKarina[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_LITWICK,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_PHANTUMP,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SANDYGAST,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerJanae[]= {
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_MISMAGIUS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerAngelica[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_HAUNTER,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_GENGAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerEmilia[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_YAMASK,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_XATU,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPkmTowerJennifer[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_DHELMISE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketPkmTower_19[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_THIEVUL,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MIGHTYENA,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_HOUNDOOM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketPkmTower_20[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HYPNO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketPkmTower_21[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SCOLIPEDE,
    },
};

//~~~~~~~~~~~~~~~~~~|Fighting Dojo|~~~~~~~~~~~~~~~~~~//

const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltDojoHideki[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_KRICKETUNE,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_VESPIQUEN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltDojoHitoshi[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_PARASECT,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_NINJASK,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_DURANT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltDojoAaron[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_RIBOMBEE,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ORBEETLE,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HERACROSS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltDojoMike[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SCOLIPEDE,
    },
};
const struct TrainerMonNoItemCustomMoves sParty_BlackBeltBossDojoKoichi[]= {
    {  
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SHEDINJA,
        .moves = {
            MOVE_SHADOWSNEAK,
            MOVE_SHADOWBALL,
            MOVE_CONFUSERAY,
            MOVE_ABSORB,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_HERACROSS,
        .moves = {
            MOVE_TAKEDOWN,
            MOVE_BRICKBREAK,
            MOVE_AERIALACE,
            MOVE_NIGHTSLASH,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SCOLIPEDE,
        .moves = {
            MOVE_BUGBITE,
            MOVE_VENOSHOCK,
            MOVE_MEGAHORN,
            MOVE_BATONPASS,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_VESPIQUEN,
        .moves = {
            MOVE_HEALORDER,
            MOVE_TOXIC,
            MOVE_AIRSLASH,
            MOVE_ATTACKORDER,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_GALVANTULA,
        .moves = {
            MOVE_ELECTROBALL,
            MOVE_SIGNALBEAM,
            MOVE_ELECTROWEB,
            MOVE_STICKYWEB,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_CRUSTLE,
        .moves = {
            MOVE_SHELLSMASH,
            MOVE_BUGBITE,
            MOVE_ROCKSLIDE,
            MOVE_STEALTHROCK,
        },
        .ability = Ability_1,
    },
};

//~~~~~~~~~~~~~~~~~~|Silph Co|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_24[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_KADABRA,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_PANGORO,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_TREVENANT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphJerry[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HELIOLISK,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_DURANT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_23[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_AMOONGUSS,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_WEAVILE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphConnor[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_METANG,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_MAGNETON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_25[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_GYARADOS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphJose[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_TYNAMO,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_KLINK,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_BRONZONG,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_27[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SHUPPET,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_THIEVUL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_26[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HITMONLEE,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_NOCTOWL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphRodney[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_MAGNEZONE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_29[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_GOTHORITA,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SCOLIPEDE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_JugglerSilphDalton[]= {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GASTLY,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SPHEAL,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_APPLIN,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GASTLY,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SPHEAL,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_APPLIN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphBeau[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_BOLTUND,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_28[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_CUBCHOO,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MIGHTYENA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_30[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_ORBEETLE,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_NIDOQUEEN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_31[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_TAUROS,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SHARPEDO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphTaylor[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_JOLTEON,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_STUNFISK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_33[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_PYROAR,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_HIPPOWDON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_35[]= {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_MALAMAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphJoshua[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_LAIRON,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_LUXRAY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_34[]= {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_HONCHKROW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_32[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HYPNO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_36[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_VESPIQUEN,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_FROSLASS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphParker[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_PORYGON,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_PORYGON2,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_38[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MEDICHAM,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_TOXICROAK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_37[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_LITWICK,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_DUBWOOL,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SEADRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphEd[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ELGYEM,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BRONZONG,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_AMPHAROS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_39[]= {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_EXPLOUD,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistSilphTravis[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SOLROCK,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_LUNATONE,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_MINIOR_SHIELD,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_40[]= {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SEVIPER,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_VILEPLUME,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RocketSilph_41[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HAWLUCHA,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_GENGAR,
    },
};



const struct TrainerMonItemCustomMoves sParty_RivalSilphWater[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_GOLETT,
        .moves = {
            MOVE_STOMPINGTANTRUM,
            MOVE_MEGAPUNCH,
            MOVE_MAINTENANCE,
            MOVE_RUSTYRIVET,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_MISDREAVUS,
        .moves = {
            MOVE_THUNDERWAVE,
            MOVE_HEX,
            MOVE_FLOURISH,
            MOVE_PAINSPLIT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HAKAMO_O,
        .moves = {
            MOVE_HEADBUTT,
            MOVE_DRUMROLL,
            MOVE_DRAGONTAIL,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METALCLAW,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_HOUNDOOM,
        .moves = {
            MOVE_FIREFANG,
            MOVE_BEATUP,
            MOVE_THUNDERFANG,
            MOVE_FEINTATTACK,
        },
        .heldItem = ITEM_CHARCOAL,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_FERALIGATR,
        .moves = {
            MOVE_HARSHCLAW,
            MOVE_AQUATAIL,
            MOVE_ICEFANG,
            MOVE_BEASTSENSE,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalSilphGrass[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_GOLETT,
        .moves = {
            MOVE_STOMPINGTANTRUM,
            MOVE_MEGAPUNCH,
            MOVE_MAINTENANCE,
            MOVE_RUSTYRIVET,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_MISDREAVUS,
        .moves = {
            MOVE_THUNDERWAVE,
            MOVE_HEX,
            MOVE_FLOURISH,
            MOVE_PAINSPLIT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HAKAMO_O,
        .moves = {
            MOVE_HEADBUTT,
            MOVE_DRUMROLL,
            MOVE_DRAGONTAIL,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METALCLAW,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SHARPEDO,
        .moves = {
            MOVE_ICEFANG,
            MOVE_AQUAJET,
            MOVE_CRUNCH,
            MOVE_MAUL,
        },
        .heldItem = ITEM_MYSTIC_WATER,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_RILLABOOM,
        .moves = {
            MOVE_DRUMBEATING,
            MOVE_KNOCKOFF,
            MOVE_SUDDENSHOUT,
            MOVE_WOODHAMMER,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};
const struct TrainerMonItemCustomMoves sParty_RivalSilphFire[]= {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_GOLETT,
        .moves = {
            MOVE_STOMPINGTANTRUM,
            MOVE_MEGAPUNCH,
            MOVE_MAINTENANCE,
            MOVE_RUSTYRIVET,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_MISDREAVUS,
        .moves = {
            MOVE_THUNDERWAVE,
            MOVE_HEX,
            MOVE_FLOURISH,
            MOVE_PAINSPLIT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_HAKAMO_O,
        .moves = {
            MOVE_HEADBUTT,
            MOVE_DRUMROLL,
            MOVE_DRAGONTAIL,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_METANG,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METALCLAW,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_TREVENANT,
        .moves = {
            MOVE_SHADOWCLAW,
            MOVE_WILLOWISP,
            MOVE_LEECHSEED,
            MOVE_INGRAIN,
        },
        .heldItem = ITEM_MIRACLE_SEED,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_DELPHOX,
        .moves = {
            MOVE_MYSTICALFIRE,
            MOVE_LIGHTSCREEN,
            MOVE_PRESTO,
            MOVE_VORTEX,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_RocketBossSilphGiovani[] = {
    {  
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_TAUROS,
        .moves = {
            MOVE_TAKEDOWN,
            MOVE_FORAGE,
            MOVE_WORKUP,
            MOVE_PAYBACK,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_URSARING,
        .moves = {
            MOVE_SLASH,
            MOVE_FERALSTRIKES,
            MOVE_HARSHCLAW,
            MOVE_FEINTATTACK,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_DODRIO,
        .moves = {
            MOVE_SWORDSDANCE,
            MOVE_HARSHCLAW,
            MOVE_PLUCK,
            MOVE_TRIATTACK,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_MIGHTYENA,
        .moves = {
            MOVE_CRUNCH,
            MOVE_MAUL,
            MOVE_HUNTERMARK,
            MOVE_SWAGGER,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_LUXRAY,
        .moves = {
            MOVE_CRUNCH,
            MOVE_THUNDERFANG,
            MOVE_HARSHCLAW,
            MOVE_SWAGGER,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_NIDOKING,
        .moves = {
            MOVE_EARTHPOWER,
            MOVE_POISONJAB,
            MOVE_HARSHCLAW,
            MOVE_MEGAHORN,
        },
        .ability = Ability_1,
    },
};


const struct TrainerMonNoItemDefaultMoves sParty_PsychicSaffronGymCameron[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_CHIMECHO,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_KADABRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PsychicSaffronGymTyron[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_HYPNO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerSaffronGymStacy[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MISMAGIUS,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_XATU,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_MALAMAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PsychicSaffronGymPreston[]= {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_SIGILYPH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerSaffronGymAmanda[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_NINETALES,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_DELPHOX,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ChannelerSaffronGymTasha[]= {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MALAMAR,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_CHIMECHO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PsychicSaffronGymJohan[]= {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_KADABRA,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_HYPNO,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_LeaderSaffronSabrina[] = {
    {  
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_MR_MIME,
        .moves = {
            MOVE_REFLECT,
            MOVE_LIGHTSCREEN,
            MOVE_CHAOSMAGIC,
            MOVE_TRANSMUTE,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_MISMAGIUS,
        .moves = {
            MOVE_BREAKALEG,
            MOVE_MYSTICALFIRE,
            MOVE_HEX,
            MOVE_FLOURISH,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SIGILYPH,
        .moves = {
            MOVE_AIRSLASH,
            MOVE_INCANTATION,
            MOVE_TRANSMUTE,
            MOVE_WHIRLWIND,
        },
        .ability = Ability_2, //maybe hidden tinted lens
    },
    {  
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_CHIMECHO,
        .moves = {
            MOVE_HEALBELL,
            MOVE_INCANTATION,
            MOVE_SAFEGUARD,
            MOVE_PITCHPERFECT,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_NINETALES,
        .moves = {
            MOVE_NASTYPLOT,
            MOVE_ENCHANT,
            MOVE_FLAMETHROWER,
            MOVE_BEFUDDLE,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_ALAKAZAM,
        .moves = {
            MOVE_ENCHANT,
            MOVE_PSYCHIC,
            MOVE_FLOURISH,
            MOVE_RECOVER,
        },
        .ability = Ability_Hidden,
    },
};



//~~~~~~~~~~~~~~~~~~|Route 16|~~~~~~~~~~~~~~~~~~//
//Post-Pokeflute
const struct TrainerMonNoItemDefaultMoves sParty_BikerR16Lao[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_SEVIPER,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_GENGAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR16Koji[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_PRIMEAPE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR16Luke[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_PANGORO,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_TOXICROAK,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_BANETTE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR16Hideo[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_AMOONGUSS,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_HONCHKROW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR16Ruben[]= {
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_DEINO,
    },
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_WEAVILE,
    },
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_DIGGERSBY,
    },
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_SANDACONDA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR16Camron[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_VESPIQUEN,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_COFAGRIGUS,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 17|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR17Isaiah[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_TAUROS,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_BikerR17Virgil[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_HERACROSS,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_UMBREON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR17Raul[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_METAGROSS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR17Billy[]= {
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_PERSIAN,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_DUBWOOL,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_DIGGERSBY,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_BIBAREL,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_BEWEAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR17Jamal[]= {
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_LAMPENT,
    },
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_DUGTRIO,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_MAWILE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR17Nikolas[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_CAMERUPT,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SCOLIPEDE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR17Zeek[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_BARBARACLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueBallR17Corey[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_TURTONATOR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR17Jaxon[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_HOUNDOOM,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_PALOSSAND,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR17William[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_URSARING,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_BEWEAR,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 18|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR18Jacob[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SWELLOW,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_NOCTOWL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR18Wilton[]= {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_XATU,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR18Ramiro[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_CHATOT,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_HAWLUCHA,
    },
};



//~~~~~~~~~~~~~~~~~~|Route 12|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR12Ned[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_ALOMOMOLA,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_GYARADOS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR12Chip[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SHARPEDO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR12Hank[]= {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_KINGDRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR12Elliot[]= {
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_OCTILLERY,
    },
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_VAPOREON,
    },
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleR12GiaJes[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_PASSIMIAN,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_ORANGURU,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_SUNFLORA,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_BELLOSSOM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RockerR12Luca[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_KRICKETUNE,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_EXPLOUD,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_RILLABOOM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperR12Justin[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_PALOSSAND,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_HEATMOR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR12Andrew[]= {
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_DRAGALGE,
    },
};



//~~~~~~~~~~~~~~~~~~|Route 13|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR13Alma[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_GRUMPIG,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_FLAPPLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR13Sebastian[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_HONCHKROW,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SWELLOW,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_DODRIO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR13Susie[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_FLAREON,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_APPLETUN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyR13Lola[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_AZUMARILL,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_SYLVEON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyR13Sheila[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_FLORGES_YELLOW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR13Valerie[]= {
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_VESPIQUEN,
    },
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_GRANBULL,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_TROPIUS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR13Gwen[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_DURANT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR13Robert[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SWOOBAT,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_CROBAT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR13Perry[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_PIDGEOT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR13Jared[]= {
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_TREVENANT,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_STUNFISK,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_CAMERUPT,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 14|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR14Carter[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_HONCHKROW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR14Mitch[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_CHATOT,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_CHATOT,
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_CHATOT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR14Beck[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_HAWLUCHA,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_XATU,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR14Marlon[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_DODRIO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR14Donald[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_FLAPPLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR14Benny[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_PIDGEOT,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SWELLOW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TwinsR14KiriJan[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_NIDOKING,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_NIDOQUEEN,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_ALAKAZAM,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_GOTHITELLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR14Gerald[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_GENGAR,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_WEAVILE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR14Malik[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_PURUGLY,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_THIEVUL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR14Lukas[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_KLANG,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_GOLEM,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_GOLURK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR14Isaac[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_EXPLOUD,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 15|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR15Becky[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_CHIMECHO,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_PERSIAN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CrushKinR15RonMya[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_HITMONLEE,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_HITMONCHAN,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_MEDICHAM,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_TOXICROAK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR15Celia[]= {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_LICKITUNG,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_AMBIPOM,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_LILLIGANT,
    },
};

const struct TrainerMonNoItemDefaultMoves sParty_BikerR15Ernest[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_MALAMAR,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_ORBEETLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerR15Alex[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_DRUDDIGON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyR15Grace[]= {
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_BELLOSSOM,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_SUNFLORA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BeautyR15Olivia[]= {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_LUMINEON,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_AUDINO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR15Kindra[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_WIGGLYTUFF,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_MISMAGIUS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR15Chester[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SWELLOW,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SWELLOW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR15Edwin[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_SWOOBAT,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_HAWLUCHA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR15Yazmin[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_MARACTUS,
    },
};


//~~~~~~~~~~~~~~~~~~|Fuchsia Gym|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_JugglerFuchsiaKayden[]= {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_SLURPUFF,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ALCREMIE_STRAWBERRY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_JugglerFuchsiaNate[]= {
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_TROPIUS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_JugglerFuchsiaKirk[]= {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_MILTANK,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_LICKILICKY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_JugglerFuchsiaShawn[]= {
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_SINISTEA,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_POLTEAGEIST,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TamerFuchsiaPhil[]= {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_VANILLISH,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_VANILLISH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TamerFuchsiaEdgar[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_MUNCHLAX,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_APPLETUN,
    },
};
const struct TrainerMonNoItemCustomMoves sParty_LeaderFuchsiaKoga[] = {
    {  
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SLURPUFF,
        .moves = {
            MOVE_PLAYROUGH,
            MOVE_WISH,
            MOVE_SYRUPSMACK,
            MOVE_FOODCOMA,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_POLTEAGEIST,
        .moves = {
            MOVE_STRENGTHSAP,
            MOVE_SHADOWBALL,
            MOVE_SALTRUB,
            MOVE_TEATIME,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_ALCREMIE_STAR,
        .moves = {
            MOVE_SUGARRUSH,
            MOVE_FEAST,
            MOVE_DAZZLINGGLEAM,
            MOVE_ATTRACT,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_APPLETUN,
        .moves = {
            MOVE_APPLEACID,
            MOVE_FEAST,
            MOVE_MORNINGMEAL,
            MOVE_ENERGYBALL,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_LICKILICKY,
        .moves = {
            MOVE_POWERWHIP,
            MOVE_ORDERUP,
            MOVE_FEAST,
            MOVE_SLAM,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_SNORLAX,
        .moves = {
            MOVE_CHOMP,
            MOVE_SWALLOW,
            MOVE_MORNINGMEAL,
            MOVE_HIGHHORSEPOWER,
        },
        .ability = Ability_2,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 19|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19Richard[]= {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_LUMINEON,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_VAPOREON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19Reece[]= {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_SEADRA,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_AZUMARILL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19Mathew[]= {
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_BIBAREL,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_QUAGSIRE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19Douglas[]= {
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_KINGDRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19David[]= {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_BARBARACLE,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_OCTILLERY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19Tony[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_SHARPEDO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR19Axle[]= {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ALOMOMOLA,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_RELICANTH,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ALOMOMOLA,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_RELICANTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroR19LiaLuc[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_LUMINEON,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_LANTURN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR19Anya[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_LANTURN,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR19Alice[]= {
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_WALREIN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR19Connie[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_FERALIGATR,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_SHARPEDO,
    },
};

//~~~~~~~~~~~~~~~~~~|Route 21|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR21Wade[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_OCTILLERY,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_TENTACRUEL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR21Ronald[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_ALOMOMOLA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroR21LilIan[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR21Spencer[]= {
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_BIBAREL,
    },
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_AZUMARILL,
    },
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_BARBARACLE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR21Claude[]= {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_SHARPEDO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanR21Nolan[]= {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_RELICANTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR21Jack[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_LUMINEON,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_FERALIGATR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR21Jerome[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_WALREIN,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_KINGDRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR21Roland[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_SHARPEDO,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_DRAGALGE,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 20|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR20Barry[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_STARMIE,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_RELICANTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR20Darrin[]= {
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_AZUMARILL,
    },
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_VAPOREON,
    },
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_OCTILLERY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR20Shirley[]= {
    {
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_DRAGALGE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR20Tiffany[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_ALOMOMOLA,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_QUAGSIRE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR20Irene[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_FLORGES_ORANGE,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_TANGROWTH,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperR20Roger[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_SKARMORY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR20Nora[]= {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SHARPEDO,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_TENTACRUEL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMR20Dean[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_OCTILLERY,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_BIBAREL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerR20Missy[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_PYROAR,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_TREVENANT,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_MEDICHAM,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_AGGRON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFR20Melissa[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_WALREIN,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_GYARADOS,
    },
};


//~~~~~~~~~~~~~~~~~~|Pokemon Mansion|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_YoungsterPkmMansionJohnson[]= {
    {
        .iv = 0,
        .lvl = 65,
        .species = SPECIES_GOODRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BurglerPkmMansionArnie[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_THIEVUL,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_MALAMAR,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_NINJASK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BurglerPkmMansionSimon[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_POLTEAGEIST,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistPkmMansionBraydon[]= {
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_MAGNETON,
    },
    {
        .iv = 0,
        .lvl = 52,
        .species = SPECIES_MAGNETON,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_MAGNEZONE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistPkmMansionTed[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_BRONZONG,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_HELIOLISK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BurglerPkmMansionLewis[]= {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_HONCHKROW,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_HYPNO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_ScientistPkmMansionIvan[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_KLINKLANG,
    },
};


//~~~~~~~~~~~~~~~~~~|Route 10|~~~~~~~~~~~~~~~~~~//
//Outside PowerPlant
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacR10Mark[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_GOODRA,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_METAGROSS,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_KOMMO_O,
    },
};


//~~~~~~~~~~~~~~~~~~|Cinnabar Gym|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BurglerCinnabarGymQuinn[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_NINJASK,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_SWELLOW,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdCinnabarGymErik[]= {
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_HAWLUCHA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdCinnabarGymAvery[]= {
    {
        .iv = 0,
        .lvl = 67,
        .species = SPECIES_GYARADOS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BurglerCinnabarGymRamon[]= {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_VESPIQUEN,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_SKARMORY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdCinnabarGymDerek[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_XATU,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BurglerCinnabarGymDusty[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_CHATOT,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_PIDGEOT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdCinnabarGymZac[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 0,
        .lvl = 54,
        .species = SPECIES_SWOOBAT,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_SWELLOW,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_LeaderCinnabarBlaine[] = {
    {  
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_XATU,
        .moves = {
            MOVE_VORTEX,
            MOVE_ARCANEAETHER,
            MOVE_INCANTATION,
            MOVE_WISH,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_CHATOT,
        .moves = {
            MOVE_DEAFEN,
            MOVE_RAP,
            MOVE_BLUES,
            MOVE_ROOST,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_HAWLUCHA,
        .moves = {
            MOVE_HONECLAWS,
            MOVE_FLYINGPRESS,
            MOVE_HIGHJUMPKICK,
            MOVE_ROOST,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_SWOOBAT,
        .moves = {
            MOVE_PSYCHIC,
            MOVE_AIRSLASH,
            MOVE_CALMMIND,
            MOVE_ATTRACT,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_PIDGEOT,
        .moves = {
            MOVE_AIRSLASH,
            MOVE_HURRICANE,
            MOVE_ROOST,
            MOVE_TAILWIND,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_CROBAT,
        .moves = {
            MOVE_AIRSLASH,
            MOVE_POISONFANG,
            MOVE_VENOSHOCK,
            MOVE_LEECHLIFE,
        },
        .ability = Ability_Hidden,
    },
};

//~~~~~~~~~~~~~~~~~~|Treasure Beach|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFTreasureBeachAmara[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_STARMIE,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_SHARPEDO,
    },
};

//~~~~~~~~~~~~~~~~~~|Kindle Road|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFKindleRoadAbigail[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_BARBARACLE,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_VAPOREON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PicknickerKindleRoadClaire[]= {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_PALOSSAND,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_APPLETUN,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_ORANGURU,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CrushGirlKindleRoadTanya[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_MEDICHAM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CamperKindleRoadBryce[]= {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_FROSLASS,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_GRUMPIG,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_LEAVANNY,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_MEOWSTIC,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_BOLTUND,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMKindleRoadGarret[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_DRAGALGE,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_KINGDRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CrushKinKindleRoadMikKia[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_PANGORO,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_BRELOOM,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_PASSIMIAN,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_PRIMEAPE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltKindleRoadHugh[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_HITMONTOP,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_HAWLUCHA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltKindleRoadShea[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_HERACROSS,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_TOXICROAK,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CrushGirlKindleRoadSharon[]= {
    {
        .iv = 0,
        .lvl = 68,
        .species = SPECIES_BEWEAR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMKindleRoadFinn[]= {
    {
        .iv = 0,
        .lvl = 69,
        .species = SPECIES_AZUMARILL,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFKindleRoadMaria[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_DRAGALGE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_FishermanKindleRoadTommy[]= {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_MAGIKARP,
    },
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_GYARADOS,
    },
};


//~~~~~~~~~~~~~~~~~~|MT Ember|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_RangerMtEmberBeth[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_HELIOLISK,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_TAUROS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CrushGirlMtEmberJocelyn[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_HITMONLEE,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_HITMONCHAN,
    },
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_HITMONTOP,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_RangerMtEmberLogan[]= {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_PYROAR,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_BOLTUND,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_GLACEON,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_SLURPUFF,
    },
};

//~~~~~~~~~~~~~~~~~~|Three Island Town|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_BikerThreeTownGoon_1[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_MAWILE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerThreeTownGoon_2[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_HITMONCHAN,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_CAMERUPT,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BikerThreeTownGoon_3[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_SALAZZLE,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_SEVIPER,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CueballThreeTownPaxton[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_PANGORO,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_BEARTIC,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_GENGAR,
    },
};


//~~~~~~~~~~~~~~~~~~|Bond Bridge|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_TwinsBondBridgeJoyMeg[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_BIBAREL,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_DIGGERSBY,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_SOLROCK,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_LUNATONE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_AromaBondBridgeViolet[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_BELLOSSOM,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_VILEPLUME,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TuberBondBridgeAlexis[]= {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_STARMIE,
    },
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_KINGDRA,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFBondBridgeTisha[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_RELICANTH,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_DRAGALGE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TuberBondBridgeAmira[]= {
    {
        .iv = 0,
        .lvl = 68,
        .species = SPECIES_QUAGSIRE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_AromaBondBridgeNikki[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_LILLIGANT,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_SUNFLORA,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_LEAFEON,
    },
};


//~~~~~~~~~~~~~~~~~~|Viridian Gym|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_TamerViridianGymCole[]= {
    {
        .iv = 0,
        .lvl = 69,
        .species = SPECIES_FERALIGATR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltViridianGymKiyo[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_URSARING,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolViridianGymSamuel[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_MIGHTYENA,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_BEARTIC,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_ZANGOOSE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolViridianGymYuji[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_SHARPEDO,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltViridianGymAtsushi[]= {
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_GRANBULL,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_SEVIPER,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TamerViridianGymJason[]= {
    {
        .iv = 0,
        .lvl = 69,
        .species = SPECIES_LUXRAY,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolViridianGymWarren[]= {
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_NIDOQUEEN,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltViridianGymTakashi[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_TAUROS,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_URSARING,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_TAUROS,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_URSARING,
    },
};

const struct TrainerMonNoItemCustomMoves sParty_LeaderViridianGiovani[] = {
    
    {  
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_PRIMEAPE,
        .moves = {
            MOVE_ADRENALINE,
            MOVE_MAUL,
            MOVE_STOMPINGTANTRUM,
            MOVE_CLOSECOMBAT,
        },
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_GRANBULL,
        .moves = {
            MOVE_CRUNCH,
            MOVE_MAUL,
            MOVE_PLAYROUGH,
            MOVE_HUNTERMARK,
        },
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_DODRIO,
        .moves = {
            MOVE_RUPTURE,
            MOVE_DRILLPECK,
            MOVE_SWORDSDANCE,
            MOVE_TRIATTACK,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_LUXRAY,
        .moves = {
            MOVE_WILDCHARGE,
            MOVE_RUPTURE,
            MOVE_CRUNCH,
            MOVE_ROAR,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 64,
        .species = SPECIES_URSALUNA,
        .moves = {
            MOVE_HAMMERARM,
            MOVE_PLAYROUGH,
            MOVE_BRUTALCLAW,
            MOVE_HIGHHORSEPOWER,
        },
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 66,
        .species = SPECIES_NIDOKING,
        .moves = {
            MOVE_BRUTALCLAW,
            MOVE_MEGAHORN,
            MOVE_POISONJAB,
            MOVE_EARTHPOWER,
        },
        .ability = Ability_Hidden,
    },
};


const struct TrainerMonItemCustomMoves sParty_RivalR22LateWater[]= {
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_GALVANTULA,
        .moves = {
            MOVE_STICKYWEB,
            MOVE_SUCKERPUNCH,
            MOVE_BUGBUZZ,
            MOVE_ELECTROWEB,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_GOLURK,
        .moves = {
            MOVE_EARTHQUAKE,
            MOVE_HAMMERARM,
            MOVE_HEIRLOOMHIT,
            MOVE_HEAVYSLAM,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_KOMMO_O,
        .moves = {
            MOVE_CLANGINGSCALES,
            MOVE_DRAGONDANCE,
            MOVE_DRAGONCLAW,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_METAGROSS,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METEORMASH,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 65,
        .species = SPECIES_HOUNDOOM,
        .moves = {
            MOVE_NASTYPLOT,
            MOVE_INFERNO,
            MOVE_THUNDERFANG,
            MOVE_CRUNCH,
        },
        .heldItem = ITEM_CHARCOAL,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 67,
        .species = SPECIES_FERALIGATR,
        .moves = {
            MOVE_BRUTALCLAW,
            MOVE_AQUATAIL,
            MOVE_ICEFANG,
            MOVE_SCREECH,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalR22LateGrass[]= {
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_GALVANTULA,
        .moves = {
            MOVE_STICKYWEB,
            MOVE_SUCKERPUNCH,
            MOVE_BUGBUZZ,
            MOVE_ELECTROWEB,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_GOLURK,
        .moves = {
            MOVE_EARTHQUAKE,
            MOVE_HAMMERARM,
            MOVE_HEIRLOOMHIT,
            MOVE_HEAVYSLAM,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_KOMMO_O,
        .moves = {
            MOVE_CLANGINGSCALES,
            MOVE_DRAGONDANCE,
            MOVE_DRAGONCLAW,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_METAGROSS,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METEORMASH,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 64,
        .species = SPECIES_SHARPEDO,
        .moves = {
            MOVE_ICEFANG,
            MOVE_AQUAJET,
            MOVE_SAVAGE,
            MOVE_MAUL,
        },
        .heldItem = ITEM_MYSTIC_WATER,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 67,
        .species = SPECIES_RILLABOOM,
        .moves = {
            MOVE_DRUMBEATING,
            MOVE_KNOCKOFF,
            MOVE_BOOMBURST,
            MOVE_WOODHAMMER,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};
const struct TrainerMonItemCustomMoves sParty_RivalR22LateFire[]= {
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_GALVANTULA,
        .moves = {
            MOVE_STICKYWEB,
            MOVE_SUCKERPUNCH,
            MOVE_BUGBUZZ,
            MOVE_ELECTROWEB,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_GOLURK,
        .moves = {
            MOVE_EARTHQUAKE,
            MOVE_HAMMERARM,
            MOVE_HEIRLOOMHIT,
            MOVE_HEAVYSLAM,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_KOMMO_O,
        .moves = {
            MOVE_CLANGINGSCALES,
            MOVE_DRAGONDANCE,
            MOVE_DRAGONCLAW,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_METAGROSS,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METEORMASH,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 65,
        .species = SPECIES_TREVENANT,
        .moves = {
            MOVE_SHADOWCLAW,
            MOVE_HORNLEECH,
            MOVE_PHANTOMFORCE,
            MOVE_WILLOWISP,
        },
        .heldItem = ITEM_MIRACLE_SEED,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 67,
        .species = SPECIES_DELPHOX,
        .moves = {
            MOVE_MYSTICALFIRE,
            MOVE_LIGHTSCREEN,
            MOVE_ARCANEAETHER,
            MOVE_WILLOWISP,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

//~~~~~~~~~~~~~~~~~~|Victory Road|~~~~~~~~~~~~~~~~~~//
const struct TrainerMonNoItemDefaultMoves sParty_CoolVictoryRoadNaomi[]= {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_EELEKTROSS,
    },
    {
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_MEOWSTIC,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolVictoryRoadRolando[]= {
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_HERACROSS,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_CHANDELURE,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_SLURPUFF,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_BlackBeltVictoryRoadDaisuke[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_HITMONLEE,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_PANGORO,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_HAWLUCHA,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_BRELOOM,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_JugglerVictoryRoadNelson[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_CHIMECHO,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_HYPNO,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_NINETALES,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_TamerVictoryRoadVincent[]= {
    {
        .iv = 0,
        .lvl = 71,
        .species = SPECIES_HYDREIGON,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_JugglerVictoryRoadGregory[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_WALREIN,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_GOLEM,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_MINIOR_SHIELD,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_GLALIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolVictoryRoadGeorge[]= {
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_SNORLAX,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_DHELMISE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_PokeManiacVictoryRoadDawson[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_PORYGON2,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_DITTO,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_TURTONATOR,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolVictoryRoadAlexa[]= {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_DUGTRIO,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_GALVANTULA,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_TROPIUS,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolVictoryRoadColby[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_BRONZONG,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_MARACTUS,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_AUDINO,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_STARMIE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolVictoryRoadCaroline[]= {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_AGGRON,
    },
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_SCOLIPEDE,
    },
};
const struct TrainerMonNoItemDefaultMoves sParty_CoolCoupleVictoryRoadRayTyra[]= {
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_FLAPPLE,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_APPLETUN,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_ESPEON,
    },
    {
        .iv = 0,
        .lvl = 59,
        .species = SPECIES_UMBREON,
    },
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_CRADILY,
    },
    {
        .iv = 0,
        .lvl = 61,
        .species = SPECIES_AURORUS,
    },
};



//~~~~~~~~~~~~~~~~~~|Elite 4|~~~~~~~~~~~~~~~~~~//

const struct TrainerMonItemCustomMoves sParty_E4Lorelei[] = {
    {  
        .iv = 0,
        .lvl = 68,
        .species = SPECIES_SUNFLORA,
        .moves = {
            MOVE_SUNNYDAY,
            MOVE_CURINGLIGHT,
            MOVE_SOLARBEAM,
            MOVE_SUNBEAM,
        },
        .heldItem = ITEM_HEAT_ROCK,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 68,
        .species = SPECIES_ILLUMISE,
        .moves = {
            MOVE_ZENHEADBUTT,
            MOVE_FOCUSEDBEAM,
            MOVE_BUGBUZZ,
            MOVE_HALLOWFOCUS,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_LANTURN,
        .moves = {
            MOVE_LUSTERSHOT,
            MOVE_LIGHTSHIELD,
            MOVE_HYDROPUMP,
            MOVE_SIGNALBEAM,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_HELIOLISK,
        .moves = {
            MOVE_SEARINGSUN,
            MOVE_PARABOLICCHARGE,
            MOVE_THUNDERWAVE,
            MOVE_RUINOUSLIGHT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 72,
        .species = SPECIES_BELLOSSOM,
        .moves = {
            MOVE_PURITY,
            MOVE_SEARINGSUN,
            MOVE_QUIVERDANCE,
            MOVE_LEAFSTORM,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 74,
        .species = SPECIES_AMPHAROS,
        .moves = {
            MOVE_LIGHTSPEEDPUNCH,
            MOVE_FOCUSEDBEAM,
            MOVE_DRAGONPULSE,
            MOVE_DISCHARGE,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_2,
    },
};
const struct TrainerMonItemCustomMoves sParty_E4Bruno[] = {
    {  
        .iv = 0,
        .lvl = 69,
        .species = SPECIES_WEAVILE,
        .moves = {
            MOVE_HONECLAWS,
            MOVE_NIGHTSLASH,
            MOVE_SNATCH,
            MOVE_ICESHARD,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 69,
        .species = SPECIES_UMBREON,
        .moves = {
            MOVE_MOONLIGHT,
            MOVE_PROTECT,
            MOVE_TOXIC,
            MOVE_ASSURANCE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 71,
        .species = SPECIES_HONCHKROW,
        .moves = {
            MOVE_NIGHTSLASH,
            MOVE_SUCKERPUNCH,
            MOVE_WINGATTACK,
            MOVE_SWAGGER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 71,
        .species = SPECIES_PANGORO,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_SKYUPPERCUT,
            MOVE_CRUNCH,
            MOVE_TAUNT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_MALAMAR,
        .moves = {
            MOVE_NIGHTSLASH,
            MOVE_BREAKALEG,
            MOVE_TOPSYTURVY,
            MOVE_SUPERPOWER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 75,
        .species = SPECIES_HYDREIGON,
        .moves = {
            MOVE_BODYSLAM,
            MOVE_DRAGONRUSH,
            MOVE_CRUNCH,
            MOVE_ROAR,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};
const struct TrainerMonItemCustomMoves sParty_E4Agatha[] = {
    {  
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_CLEFABLE,
        .moves = {
            MOVE_WORMHOLE,
            MOVE_METEORMASH,
            MOVE_MOONBLAST,
            MOVE_MOONLIGHT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_ORBEETLE,
        .moves = {
            MOVE_GAMMAPOWER,
            MOVE_BIGBANG,
            MOVE_PULSAR,
            MOVE_ABDUCT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 72,
        .species = SPECIES_SOLROCK,
        .moves = {
            MOVE_FLAMETHROWER,
            MOVE_METEORSHOWER,
            MOVE_ROCKSLIDE,
            MOVE_COSMICPOWER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 72,
        .species = SPECIES_LUNATONE,
        .moves = {
            MOVE_ICEBEAM,
            MOVE_METEORSHOWER,
            MOVE_ROCKSLIDE,
            MOVE_COSMICPOWER,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 74,
        .species = SPECIES_PORYGON_Z,
        .moves = {
            MOVE_TRIATTACK,
            MOVE_WORMHOLE,
            MOVE_BIGBANG,
            MOVE_NASTYPLOT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 76,
        .species = SPECIES_BEHEEYEM,
        .moves = {
            MOVE_ABDUCT,
            MOVE_RELATIVITY,
            MOVE_RECOVER,
            MOVE_NEUTRONSHOT,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_Hidden,
    },
};
const struct TrainerMonItemCustomMoves sParty_E4Lance[] = {
    {  
        .iv = 0,
        .lvl = 71,
        .species = SPECIES_STONJOURNER,
        .moves = {
            MOVE_HEIRLOOMHIT,
            MOVE_FORTIFY,
            MOVE_STEALTHROCK,
            MOVE_PROTECT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_Hidden,
    },
    {  
        .iv = 0,
        .lvl = 71,
        .species = SPECIES_CLAYDOL,
        .moves = {
            MOVE_RAPIDSPIN,
            MOVE_EARTHPOWER,
            MOVE_FORTIFY,
            MOVE_COREBLAST,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_RELICANTH,
        .moves = {
            MOVE_HEADSMASH,
            MOVE_WEIGHDOWN,
            MOVE_PERSEVERANCE,
            MOVE_REST,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_BRONZONG,
        .moves = {
            MOVE_COREBLAST,
            MOVE_GYROBALL,
            MOVE_TIMEGEAR,
            MOVE_MAINTENANCE,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_2,
    },
    {  
        .iv = 0,
        .lvl = 75,
        .species = SPECIES_SPIRITOMB,
        .moves = {
            MOVE_GAURDDRAIN,
            MOVE_DARKPULSE,
            MOVE_SUCKERPUNCH,
            MOVE_HEIRLOOMHIT,
        },
        .heldItem = ITEM_NONE,
        .ability = Ability_1,
    },
    {  
        .iv = 0,
        .lvl = 77,
        .species = SPECIES_AEGISLASH,
        .moves = {
            MOVE_KINGSSHIELD,
            MOVE_SACREDSWORD,
            MOVE_SWORDSDANCE,
            MOVE_BOLSTER,
        },
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalChampionWater[]= {
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_VANILLUXE,
        .moves = {
            MOVE_FREEZEDRY,
            MOVE_BLIZZARD,
            MOVE_GUMSHOT,
            MOVE_SUGARRUSH,
        },
        .heldItem = ITEM_NEVER_MELT_ICE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_GOLURK,
        .moves = {
            MOVE_EARTHQUAKE,
            MOVE_DYNAMICPUNCH,
            MOVE_HEIRLOOMHIT,
            MOVE_HEAVYSLAM,
        },
        .heldItem = ITEM_BLACK_BELT,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_KOMMO_O,
        .moves = {
            MOVE_CLANGINGSCALES,
            MOVE_DRAGONDANCE,
            MOVE_DRAGONCLAW,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_THROAT_SPRAY,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_METAGROSS,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METEORMASH,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 75,
        .species = SPECIES_HOUNDOOM,
        .moves = {
            MOVE_NASTYPLOT,
            MOVE_INFERNO,
            MOVE_THUNDERFANG,
            MOVE_CRUNCH,
        },
        .heldItem = ITEM_CHARCOAL,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 80,
        .species = SPECIES_FERALIGATR,
        .moves = {
            MOVE_BRUTALCLAW,
            MOVE_AQUATAIL,
            MOVE_ICEFANG,
            MOVE_ADRENALINE,
        },
        .heldItem = ITEM_WATER_GEM,
        .ability = Ability_1,
    },
};

const struct TrainerMonItemCustomMoves sParty_RivalChampionGrass[]= {
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_VANILLUXE,
        .moves = {
            MOVE_FREEZEDRY,
            MOVE_BLIZZARD,
            MOVE_GUMSHOT,
            MOVE_SUGARRUSH,
        },
        .heldItem = ITEM_NEVER_MELT_ICE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_GOLURK,
        .moves = {
            MOVE_EARTHQUAKE,
            MOVE_DYNAMICPUNCH,
            MOVE_HEIRLOOMHIT,
            MOVE_HEAVYSLAM,
        },
        .heldItem = ITEM_BLACK_BELT,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_KOMMO_O,
        .moves = {
            MOVE_CLANGINGSCALES,
            MOVE_DRAGONDANCE,
            MOVE_DRAGONCLAW,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_THROAT_SPRAY,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_METAGROSS,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METEORMASH,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 75,
        .species = SPECIES_SHARPEDO,
        .moves = {
            MOVE_ICEFANG,
            MOVE_AQUAJET,
            MOVE_SAVAGE,
            MOVE_MAUL,
        },
        .heldItem = ITEM_MYSTIC_WATER,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 80,
        .species = SPECIES_RILLABOOM,
        .moves = {
            MOVE_DRUMBEATING,
            MOVE_KNOCKOFF,
            MOVE_BOOMBURST,
            MOVE_DEAFEN,
        },
        .heldItem = ITEM_GRASS_GEM,
        .ability = Ability_1,
    },
};
const struct TrainerMonItemCustomMoves sParty_RivalChampionFire[]= {
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_VANILLUXE,
        .moves = {
            MOVE_FREEZEDRY,
            MOVE_BLIZZARD,
            MOVE_GUMSHOT,
            MOVE_SUGARRUSH,
        },
        .heldItem = ITEM_NEVER_MELT_ICE,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 70,
        .species = SPECIES_GOLURK,
        .moves = {
            MOVE_EARTHQUAKE,
            MOVE_DYNAMICPUNCH,
            MOVE_HEIRLOOMHIT,
            MOVE_HEAVYSLAM,
        },
        .heldItem = ITEM_BLACK_BELT,
        .ability = Ability_Hidden,
    },
    {
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_KOMMO_O,
        .moves = {
            MOVE_CLANGINGSCALES,
            MOVE_DRAGONDANCE,
            MOVE_DRAGONCLAW,
            MOVE_SKYUPPERCUT,
        },
        .heldItem = ITEM_THROAT_SPRAY,
        .ability = Ability_2,
    },
    {
        .iv = 0,
        .lvl = 73,
        .species = SPECIES_METAGROSS,
        .moves = {
            MOVE_BULLETPUNCH,
            MOVE_PURSUIT,
            MOVE_METEORMASH,
            MOVE_ZENHEADBUTT,
        },
        .heldItem = ITEM_LIFE_ORB,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 75,
        .species = SPECIES_TREVENANT,
        .moves = {
            MOVE_SHADOWCLAW,
            MOVE_WILLOWISP,
            MOVE_HORNLEECH,
            MOVE_LEECHSEED,
        },
        .heldItem = ITEM_MIRACLE_SEED,
        .ability = Ability_1,
    },
    {
        .iv = 0,
        .lvl = 80,
        .species = SPECIES_DELPHOX,
        .moves = {
            MOVE_MYSTICALFIRE,
            MOVE_ENCHANT,
            MOVE_ARCANEAETHER,
            MOVE_WILLOWISP,
        },
        .heldItem = ITEM_FIRE_GEM,
        .ability = Ability_1,
    },
};

#define NO_NAME {_END, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE}
#define RIVAL_NAME {_G, _a, _r, _y, _END}
#define GIOVANNI_NAME {_G, _i, _o, _v, _a, _n, _n, _i, _END}
#define GRUNT_NAME {_G, _r, _u, _n, _t, _END}
#define GOON_NAME {_G, _o, _o, _n, _END}

const struct Trainer gTrainers[] = {
    [TRAINER_NONE] = {
        .trainerName = NO_NAME,
    },
    //~~~~~~~~~~~~~~~~~~|Pallet Town Starter Fight|~~~~~~~~~~~~~~~~~~//
    [TRAINER_RIVAL_OAKS_LAB_FENNEKIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RivalLabFire),
        .party = {.NoItemDefaultMoves = sParty_RivalLabFire}
    },

    [TRAINER_RIVAL_OAKS_LAB_GROOKEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RivalLabGrass),
        .party = {.NoItemDefaultMoves = sParty_RivalLabGrass}
    },
    [TRAINER_RIVAL_OAKS_LAB_TOTODILE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RivalLabWater),
        .party = {.NoItemDefaultMoves = sParty_RivalLabWater}
    },

    //~~~~~~~~~~~~~~~~~~|Route 22 Early Rival Fight|~~~~~~~~~~~~~~~~~~//
    [TRAINER_RIVAL_ROUTE22_EARLY_FENNEKIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE,
        .partySize = NELEMS(sParty_RivalEarly22Fire),
        .party = {.NoItemDefaultMoves = sParty_RivalEarly22Fire}
    },
    [TRAINER_RIVAL_ROUTE22_EARLY_GROOKEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RivalEarly22Grass),
        .party = {.NoItemDefaultMoves = sParty_RivalEarly22Grass}
    },
    [TRAINER_RIVAL_ROUTE22_EARLY_TOTODILE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RivalEarly22Water),
        .party = {.NoItemDefaultMoves = sParty_RivalEarly22Water}
    },

    //~~~~~~~~~~~~~~~~~~|Viridian Forest|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BUG_CATCHER_RICK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_R, _i, _c, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherVFRick),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherVFRick}
    },
    [TRAINER_BUG_CATCHER_DOUG] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_D, _o, _u, _g, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherVFDoug),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherVFDoug}
    },
    [TRAINER_BUG_CATCHER_SAMMY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_A, _n, _t, _h, _o, _n, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherVFAnthony),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherVFAnthony}
    },
    [TRAINER_BUG_CATCHER_ANTHONY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_C, _h, _a, _r, _l, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherVFCharlie),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherVFCharlie}
    },
    [TRAINER_BUG_CATCHER_CHARLIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_S, _a, _m, _m, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherVFSammy),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherVFSammy}
    },

    //~~~~~~~~~~~~~~~~~~|Pewter Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_CAMPER_LIAM] = { 
        .partyFlags = 0,
        .trainerClass = CLASS_ENGINEER, //CLASS CAMPER
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_WORKER, //TRAINER_PIC_CAMPER
        .trainerName = {_L, _i, _a, _m, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperPGLiam),
        .party = {.NoItemDefaultMoves = sParty_CamperPGLiam}
    },
    [TRAINER_LEADER_BROCK] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BROCK,
        .trainerName = {_B, _r, _o, _c, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderPGBrock),
        .party = {.NoItemCustomMoves = sParty_LeaderPGBrock}
    },

    //~~~~~~~~~~~~~~~~~~|Route 3|~~~~~~~~~~~~~~~~~~//
    [TRAINER_LASS_JANICE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_J, _a, _n, _i, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR3Janice),
        .party = {.NoItemDefaultMoves = sParty_LassR3Janice}
    },
    [TRAINER_BUG_CATCHER_COLTON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_C, _o, _l, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR3Colton),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR3Colton}
    },
    [TRAINER_YOUNGSTER_BEN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_B, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR3Ben),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR3Ben}
    },
    [TRAINER_BUG_CATCHER_GREG] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_G, _r, _e, _g, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR3Greg),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR3Greg}
    },
    [TRAINER_YOUNGSTER_CALVIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_C, _a, _l, _v, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR3Calvin),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR3Calvin}
    },
    [TRAINER_LASS_SALLY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_S, _a, _l, _l, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR3Sally),
        .party = {.NoItemDefaultMoves = sParty_LassR3Sally}
    },
    [TRAINER_BUG_CATCHER_JAMES] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_J, _a, _m, _e, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR3James),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR3James}
    },
    [TRAINER_LASS_ROBIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_R, _o, _b, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR3Robin),
        .party = {.NoItemDefaultMoves = sParty_LassR3Robin}
    },



    //~~~~~~~~~~~~~~~~~~|Mt Moon 1F|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BUG_CATCHER_KENT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_K, _e, _n, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherMTMF1Kent),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherMTMF1Kent}
    },
    [TRAINER_LASS_IRIS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_I, _r, _i, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassMTMF1Iris),
        .party = {.NoItemDefaultMoves = sParty_LassMTMF1Iris}
    },
    [TRAINER_SUPER_NERD_JOVAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_J, _o, _v, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_NerdMTMF1Jovan),
        .party = {.NoItemDefaultMoves = sParty_NerdMTMF1Jovan}
    },
    [TRAINER_BUG_CATCHER_ROBBY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_R, _o, _b, _b, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherMTMF1Robby),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherMTMF1Robby}
    },
    [TRAINER_LASS_MIRIAM] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_M, _i, _r, _i, _a, _m, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassMTMF1Miriam),
        .party = {.NoItemDefaultMoves = sParty_LassMTMF1Miriam}
    },
    [TRAINER_YOUNGSTER_JOSH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_J, _o, _s, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterMTM1FJosh),
        .party = {.NoItemDefaultMoves = sParty_YoungsterMTM1FJosh}
    },
    [TRAINER_HIKER_MARCOS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_M, _a, _r, _c, _o, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerMTM1FMarcos),
        .party = {.NoItemDefaultMoves = sParty_HikerMTM1FMarcos}
    },

    //~~~~~~~~~~~~~~~~~~|Mt Moon B2F|~~~~~~~~~~~~~~~~~~//
    [TRAINER_TEAM_ROCKET_GRUNT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketMTMB2F_1),
        .party = {.NoItemDefaultMoves = sParty_RocketMTMB2F_1}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_2] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketMTMB2F_2),
        .party = {.NoItemDefaultMoves = sParty_RocketMTMB2F_2}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_3] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketMTMB2F_3),
        .party = {.NoItemDefaultMoves = sParty_RocketMTMB2F_3}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_4] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketMTMB2F_4),
        .party = {.NoItemDefaultMoves = sParty_RocketMTMB2F_4}
    },
    [TRAINER_SUPER_NERD_MIGUEL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_M, _i, _g, _u, _e, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_NerdMTMB2FMiguel),
        .party = {.NoItemDefaultMoves = sParty_NerdMTMB2FMiguel}
    },

    //~~~~~~~~~~~~~~~~~~|Mt Moon Summit|~~~~~~~~~~~~~~~~~~//
    [TRAINER_HIKER_DON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_D, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerMTSDon),
        .party = {.NoItemDefaultMoves = sParty_HikerMTSDon}
    },
    [TRAINER_HIKER_RON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_R, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerMTSRon),
        .party = {.NoItemDefaultMoves = sParty_HikerMTSRon}
    },
    [TRAINER_HIKER_JON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_J, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerMTSJon),
        .party = {.NoItemDefaultMoves = sParty_HikerMTSJon}
    },
    //~~~~~~~~~~~~~~~~~~|Route 4|~~~~~~~~~~~~~~~~~~//
    [TRAINER_LASS_CRISSY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_C, _r, _i, _s, _s, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR4Crissy),
        .party = {.NoItemDefaultMoves = sParty_LassR4Crissy}
    },

    //~~~~~~~~~~~~~~~~~~|Cerulean City|~~~~~~~~~~~~~~~~~~//
    [TRAINER_RIVAL_CERULEAN_WATER] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalCeruleanCityWater),
        .party = {.ItemCustomMoves = sParty_RivalCeruleanCityWater}
    },
    [TRAINER_RIVAL_CERULEAN_GRASS] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalCeruleanCityGrass),
        .party = {.ItemCustomMoves = sParty_RivalCeruleanCityGrass}
    },
    [TRAINER_RIVAL_CERULEAN_FIRE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalCeruleanCityFire),
        .party = {.ItemCustomMoves = sParty_RivalCeruleanCityFire}
    },
    [TRAINER_SWIMMER_MALE_LUIS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,//CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_CAMPER,//TRAINER_PIC_SWIMMER_M,
        .trainerName = {_L, _u, _i, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMCeruleanGymLuis),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMCeruleanGymLuis}
    },
    [TRAINER_PICNICKER_DIANA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_D, _i, _a, _n, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerCeruleanGymDiana),
        .party = {.NoItemDefaultMoves = sParty_PicknickerCeruleanGymDiana}
    },
    [TRAINER_LEADER_MISTY] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_MISTY,
        .trainerName = {_M, _i, _s, _t, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderCGMisty),
        .party = {.NoItemCustomMoves = sParty_LeaderCGMisty}
    },

    [TRAINER_TEAM_ROCKET_GRUNT_5] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketCeruleanCity),
        .party = {.NoItemDefaultMoves = sParty_RocketCeruleanCity}
    },

    
    //~~~~~~~~~~~~~~~~~~|Route 24|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BUG_CATCHER_CALE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_C, _a, _l, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR24Cale),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR24Cale}
    },
    [TRAINER_LASS_ALI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_A, _l, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR24Ali),
        .party = {.NoItemDefaultMoves = sParty_LassR24Ali}
    },
    [TRAINER_YOUNGSTER_TIMMY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_T, _i, _m, _m, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR24Timmy),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR24Timmy}
    },
    [TRAINER_LASS_RELI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_R, _e, _l, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR24Reli),
        .party = {.NoItemDefaultMoves = sParty_LassR24Reli}
    },
    [TRAINER_CAMPER_ETHAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_E, _t, _h, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR24Ethan),
        .party = {.NoItemDefaultMoves = sParty_CamperR24Ethan}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_6] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketR24),
        .party = {.NoItemDefaultMoves = sParty_RocketR24}
    },
    [TRAINER_CAMPER_SHANE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_S, _h, _a, _n, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR24Shane),
        .party = {.NoItemDefaultMoves = sParty_CamperR24Shane}
    },


    //~~~~~~~~~~~~~~~~~~|Route 25|~~~~~~~~~~~~~~~~~~//
    [TRAINER_HIKER_FRANKLIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_F, _r, _a, _n, _k, _l, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR25Franklin),
        .party = {.NoItemDefaultMoves = sParty_HikerR25Franklin}
    },
    [TRAINER_HIKER_WAYNE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_W, _a, _y, _n, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR25Wayne),
        .party = {.NoItemDefaultMoves = sParty_HikerR25Wayne}
    },
    [TRAINER_YOUNGSTER_JOEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_J, _o, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR25Joey),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR25Joey}
    },
    [TRAINER_YOUNGSTER_DAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_D, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR25Dan),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR25Dan}
    },
    [TRAINER_PICNICKER_KELSEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_K, _e, _l, _s, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR25Kelsey),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR25Kelsey}
    },
    [TRAINER_HIKER_NOB] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_N, _o, _b, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR25Nob),
        .party = {.NoItemDefaultMoves = sParty_HikerR25Nob}
    },
    [TRAINER_CAMPER_FLINT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_F, _l, _i, _n, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR25Flint),
        .party = {.NoItemDefaultMoves = sParty_CamperR25Flint}
    },
    [TRAINER_YOUNGSTER_CHAD] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_C, _h, _a, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR25Chad),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR25Chad}
    },
    [TRAINER_LASS_HALEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_H, _a, _l, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR25Haley),
        .party = {.NoItemDefaultMoves = sParty_LassR25Haley}
    },


    //~~~~~~~~~~~~~~~~~~|Route 6|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BUG_CATCHER_KEIGO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_K, _e, _i, _g, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR6Keigo),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR6Keigo}
    },
    [TRAINER_CAMPER_RICKY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_R, _i, _c, _k, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR6Ricky),
        .party = {.NoItemDefaultMoves = sParty_CamperR6Ricky}
    },
    [TRAINER_PICNICKER_NANCY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_N, _a, _n, _c, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR6Nancy),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR6Nancy}
    },
    [TRAINER_BUG_CATCHER_ELIJAH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_E, _l, _i, _j, _a, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR6Elijah),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR6Elijah}
    },
    [TRAINER_PICNICKER_ISABELLE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_I, _s, _a, _b, _e, _l, _l, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR6Isabelle),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR6Isabelle}
    },
    [TRAINER_CAMPER_JEFF] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_J, _e, _f, _f, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR6Jeff),
        .party = {.NoItemDefaultMoves = sParty_CamperR6Jeff}
    },

    //~~~~~~~~~~~~~~~~~~|Route 11|~~~~~~~~~~~~~~~~~~//
    [TRAINER_YOUNGSTER_EDDIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_E, _d, _d, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR11Eddie),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR11Eddie}
    },
    [TRAINER_GAMER_HUGO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GAMBLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = {_H, _u, _g, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GamerR11Hugo),
        .party = {.NoItemDefaultMoves = sParty_GamerR11Hugo}
    },
    [TRAINER_ENGINEER_BERNIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_ENGINEER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_WORKER,
        .trainerName = {_B, _e, _r, _n, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_EngineerR11Bernie),
        .party = {.NoItemDefaultMoves = sParty_EngineerR11Bernie}
    },
    [TRAINER_YOUNGSTER_DAVE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_D, _a, _v, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR11Dave),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR11Dave}
    },
    [TRAINER_YOUNGSTER_DILLON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_D, _i, _l, _l, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR11Dillon),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR11Dillon}
    },
    [TRAINER_GAMER_JASPER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GAMBLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = {_J, _a, _s, _p, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GamerR11Jasper),
        .party = {.NoItemDefaultMoves = sParty_GamerR11Jasper}
    },
    [TRAINER_ENGINEER_BRAXTON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_ENGINEER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_WORKER,
        .trainerName = {_B, _r, _a, _x, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_EngineerR11Braxton),
        .party = {.NoItemDefaultMoves = sParty_EngineerR11Braxton}
    },
    [TRAINER_GAMER_DARIAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GAMBLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = {_D, _a, _r, _i, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GamerR11Darian),
        .party = {.NoItemDefaultMoves = sParty_GamerR11Darian}
    },
    [TRAINER_YOUNGSTER_YASU] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_Y, _a, _s, _u, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterR11Yasu),
        .party = {.NoItemDefaultMoves = sParty_YoungsterR11Yasu}
    },
    [TRAINER_GAMER_DIRK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GAMBLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = {_D, _i, _r, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GamerR11Dirk),
        .party = {.NoItemDefaultMoves = sParty_GamerR11Dirk}
    },


    //~~~~~~~~~~~~~~~~~~|S.S. Anne|~~~~~~~~~~~~~~~~~~//
    [TRAINER_SAILOR_TREVOR] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_T, _r, _e, _v, _o, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnneTrevor),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnneTrevor}
    },
    [TRAINER_SAILOR_EDMOND] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_E, _d, _m, _o, _n, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnneEdmond),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnneEdmond}
    },
    [TRAINER_FISHERMAN_BARNY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_B, _a, _r, _n, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanSSAnneBarny),
        .party = {.NoItemDefaultMoves = sParty_FishermanSSAnneBarny}
    },
    [TRAINER_SAILOR_PHILLIP] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_P, _h, _i, _l, _l, _i, _p, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnnePhilip),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnnePhilip}
    },
    [TRAINER_SAILOR_HUEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_H, _u, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnneHuey),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnneHuey}
    },
    [TRAINER_SAILOR_DYLAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_D, _y, _l, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnneDylan),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnneDylan}
    },
    [TRAINER_SAILOR_DUNCAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_D, _u, _n, _c, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnneDuncan),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnneDuncan}
    },
    [TRAINER_SAILOR_LEONARD] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_L, _e, _o, _n, _a, _r, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorSSAnneLeonard),
        .party = {.NoItemDefaultMoves = sParty_SailorSSAnneLeonard}
    },
    [TRAINER_GENTLEMAN_THOMAS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GENTLEMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = {_T, _h, _o, _m, _a, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GentlemanSSAnneThomas),
        .party = {.NoItemDefaultMoves = sParty_GentlemanSSAnneThomas}
    },
    [TRAINER_GENTLEMAN_ARTHUR] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GENTLEMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = {_A, _r, _t, _h, _u, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GentlemanSSAnneArthur),
        .party = {.NoItemDefaultMoves = sParty_GentlemanSSAnneArthur}
    },
    [TRAINER_LASS_ANN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_A, _n, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassSSAnneAnn),
        .party = {.NoItemDefaultMoves = sParty_LassSSAnneAnn}
    },
    [TRAINER_YOUNGSTER_TYLER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_T, _y, _l, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterSSAnneTyler),
        .party = {.NoItemDefaultMoves = sParty_YoungsterSSAnneTyler}
    },
    [TRAINER_FISHERMAN_DALE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_D, _a, _l, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanSSAnneDale),
        .party = {.NoItemDefaultMoves = sParty_FishermanSSAnneDale}
    },
    [TRAINER_GENTLEMAN_BROOKS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GENTLEMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = {_B, _r, _o, _o, _k, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GentlemanSSAnneBrooks),
        .party = {.NoItemDefaultMoves = sParty_GentlemanSSAnneBrooks}
    },
    [TRAINER_LASS_DAWN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_D, _a, _w, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassSSAnneDawn),
        .party = {.NoItemDefaultMoves = sParty_LassSSAnneDawn}
    },
    [TRAINER_GENTLEMAN_LAMAR] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GENTLEMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = {_L, _a, _m, _a, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GentlemanSSAnneLamar),
        .party = {.NoItemDefaultMoves = sParty_GentlemanSSAnneLamar}
    },


    [TRAINER_RIVAL_SS_ANNE_WATER] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL_2,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalSSAnneWater),
        .party = {.ItemCustomMoves = sParty_RivalSSAnneWater}
    },
    [TRAINER_RIVAL_SS_ANNE_GRASS] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL_2,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalSSAnneGrass),
        .party = {.ItemCustomMoves = sParty_RivalSSAnneGrass}
    },
    [TRAINER_RIVAL_SS_ANNE_FIRE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL_2,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalSSAnneFire),
        .party = {.ItemCustomMoves = sParty_RivalSSAnneFire}
    },


    //~~~~~~~~~~~~~~~~~~|Vermillion Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_SAILOR_DWAYNE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SAILOR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = {_D, _w, _a, _y, _n, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SailorVermillionGymDwayne),
        .party = {.NoItemDefaultMoves = sParty_SailorVermillionGymDwayne}
    },
    [TRAINER_ENGINEER_BAILY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_ENGINEER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_WORKER,
        .trainerName = {_B, _a, _i, _l, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_EngineerVermillionGymBaily),
        .party = {.NoItemDefaultMoves = sParty_EngineerVermillionGymBaily}
    },
    [TRAINER_GENTLEMAN_TUCKER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GENTLEMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = {_T, _u, _c, _k, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GentlemanVermillionGymTucker),
        .party = {.NoItemDefaultMoves = sParty_GentlemanVermillionGymTucker}
    },
    [TRAINER_LEADER_LT_SURGE] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_LT_SURGE,
        .trainerName = {_L, _t, _PERIOD, _SPACE, _S, _u, _r, _g, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderVermillionGymLTSurge),
        .party = {.NoItemCustomMoves = sParty_LeaderVermillionGymLTSurge}
    },
    [TRAINER_PICNICKER_ALICIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_A, _l, _i, _c, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR9Alicia),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR9Alicia}
    },
    [TRAINER_HIKER_JEREMY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_J, _e, _r, _e, _m, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR9Jeremy),
        .party = {.NoItemDefaultMoves = sParty_HikerR9Jeremy}
    },
    [TRAINER_CAMPER_CHRIS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_C, _h, _r, _i, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR9Chris),
        .party = {.NoItemDefaultMoves = sParty_CamperR9Chris}
    },
    [TRAINER_BUG_CATCHER_BRENT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_B, _r, _e, _n, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR9Brent),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR9Brent}
    },
    [TRAINER_HIKER_ALAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_A, _l, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR9Alan),
        .party = {.NoItemDefaultMoves = sParty_HikerR9Alan}
    },
    [TRAINER_BUG_CATCHER_CONNER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BUG_CATCHER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = {_C, _o, _n, _n, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BugCatcherR9Conner),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherR9Conner}
    },
    [TRAINER_CAMPER_DREW] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_D, _r, _e, _w, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR9Drew),
        .party = {.NoItemDefaultMoves = sParty_CamperR9Drew}
    },
    [TRAINER_HIKER_BRICE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_B, _r, _i, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR9Brice),
        .party = {.NoItemDefaultMoves = sParty_HikerR9Brice}
    },
    [TRAINER_PICNICKER_CAITLIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_C, _a, _i, _t, _l, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR9Caitlin),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR9Caitlin}
    },

    //~~~~~~~~~~~~~~~~~~|Route 10|~~~~~~~~~~~~~~~~~~//
    //North
    [TRAINER_PICNICKER_HEIDI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_H, _e, _i, _d, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR10Heidi),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR10Heidi}
    },

    //~~~~~~~~~~~~~~~~~~|Rock Tunnel|~~~~~~~~~~~~~~~~~~//
    [TRAINER_POKEMANIAC_ASHTON] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_A, _s, _h, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacRTAshton),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacRTAshton}
    },
    [TRAINER_POKEMANIAC_WINSTON] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_W, _i, _n, _s, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacRTWinston),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacRTWinston}
    },
    [TRAINER_PICNICKER_MARTHA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_M, _a, _r, _t, _h, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerRTMartha),
        .party = {.NoItemDefaultMoves = sParty_PicknickerRTMartha}
    },
    [TRAINER_POKEMANIAC_STEVE] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_S, _t, _e, _v, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacRTSteve),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacRTSteve}
    },
    [TRAINER_HIKER_ALLEN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_A, _l, _l, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerRTAllen),
        .party = {.NoItemDefaultMoves = sParty_HikerRTAllen}
    },
    [TRAINER_HIKER_ERIC] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_E, _r, _i, _c, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerRTEric),
        .party = {.NoItemDefaultMoves = sParty_HikerRTEric}
    },
    [TRAINER_HIKER_LENNY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_L, _e, _n, _n, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerRTLenny),
        .party = {.NoItemDefaultMoves = sParty_HikerRTLenny}
    },
    [TRAINER_HIKER_OLIVER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_O, _l, _i, _v, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerRTOliver),
        .party = {.NoItemDefaultMoves = sParty_HikerRTOliver}
    },
    [TRAINER_HIKER_LUCAS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_L, _u, _c, _a, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerRTLucas),
        .party = {.NoItemDefaultMoves = sParty_HikerRTLucas}
    },
    [TRAINER_PICNICKER_SOFIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_S, _o, _f, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerRTSofia),
        .party = {.NoItemDefaultMoves = sParty_PicknickerRTSofia}
    },
    [TRAINER_HIKER_DUDLEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_D, _u, _d, _l, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerRTDudley),
        .party = {.NoItemDefaultMoves = sParty_HikerRTDudley}
    },
    [TRAINER_POKEMANIAC_COOPER] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_C, _o, _o, _p, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacRTCooper),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacRTCooper}
    },
    [TRAINER_PICNICKER_LEAH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_L, _e, _a, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerRTLeah),
        .party = {.NoItemDefaultMoves = sParty_PicknickerRTLeah}
    },
    [TRAINER_PICNICKER_ARIANA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_A, _r, _i, _a, _n, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerRTAriana),
        .party = {.NoItemDefaultMoves = sParty_PicknickerRTAriana}
    },
    [TRAINER_PICNICKER_DANA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_D, _a, _n, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerRTDana),
        .party = {.NoItemDefaultMoves = sParty_PicknickerRTDana}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_BASEMENT_A] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketRockTunnelA),
        .party = {.NoItemDefaultMoves = sParty_RocketRockTunnelA}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_BASEMENT_B] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketRockTunnelB),
        .party = {.NoItemDefaultMoves = sParty_RocketRockTunnelB}
    },


    //~~~~~~~~~~~~~~~~~~|Route 10|~~~~~~~~~~~~~~~~~~//
    //South
    [TRAINER_PICNICKER_CAROL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_C, _a, _r, _o, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR10Carol),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR10Carol}
    },
    [TRAINER_HIKER_CLARK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_C, _l, _a, _r, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR10Clark),
        .party = {.NoItemDefaultMoves = sParty_HikerR10Clark}
    },
    [TRAINER_HIKER_TRENT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_HIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = {_T, _r, _e, _n, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_HikerR10Trent),
        .party = {.NoItemDefaultMoves = sParty_HikerR10Trent}
    },
    [TRAINER_POKEMANIAC_HERMAN] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_H, _e, _r, _m, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacR10Herman),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacR10Herman}
    },
    [TRAINER_RIVAL_POKENON_TOWER_WATER] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalPkmTowerWater),
        .party = {.ItemCustomMoves = sParty_RivalPkmTowerWater}
    },
    [TRAINER_RIVAL_POKENON_TOWER_GRASS] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalPkmTowerGrass),
        .party = {.ItemCustomMoves = sParty_RivalPkmTowerGrass}
    },
    [TRAINER_RIVAL_POKENON_TOWER_FIRE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalPkmTowerFire),
        .party = {.ItemCustomMoves = sParty_RivalPkmTowerFire}
    },
    //~~~~~~~~~~~~~~~~~~|Route 8|~~~~~~~~~~~~~~~~~~//
    [TRAINER_LASS_JULIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_J, _u, _l, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR8Julia),
        .party = {.NoItemDefaultMoves = sParty_LassR8Julia}
    },
    [TRAINER_GAMER_RICH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GAMBLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = {_R, _i, _c, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GamerR8Rich),
        .party = {.NoItemDefaultMoves = sParty_GamerR8Rich}
    },
    [TRAINER_SUPER_NERD_GLENN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_G, _l, _e, _n, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdR8Glenn),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdR8Glenn}
    },
    [TRAINER_TWINS_ELI_ANNE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TWINS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = {_E, _l, _i, _SPACE, _HYPHEN, _SPACE, _A, _n, _n, _e, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TwinsR8EliAnne),
        .party = {.NoItemDefaultMoves = sParty_TwinsR8EliAnne}
    },
    [TRAINER_LASS_PAIGE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_P, _a, _i, _g, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR8Paige),
        .party = {.NoItemDefaultMoves = sParty_LassR8Paige}
    },
    [TRAINER_SUPER_NERD_LESLIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_L, _e, _s, _l, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdR8Leslie),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdR8Leslie}
    },
    [TRAINER_LASS_ANDREA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_A, _n, _d, _r, _e, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR8Andrea),
        .party = {.NoItemDefaultMoves = sParty_LassR8Andrea}
    },
    [TRAINER_LASS_MEGAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_M, _e, _g, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassR8Megan),
        .party = {.NoItemDefaultMoves = sParty_LassR8Megan}
    },
    [TRAINER_BIKER_JAREN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_J, _a, _r, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR8Jaren),
        .party = {.NoItemDefaultMoves = sParty_BikerR8Jaren}
    },
    [TRAINER_BIKER_RICARDO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_R, _i, _c, _a, _r, _d, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR8Ricardo),
        .party = {.NoItemDefaultMoves = sParty_BikerR8Ricardo}
    },
    [TRAINER_GAMER_STAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_GAMBLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = {_S, _t, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_GamerR8Stan),
        .party = {.NoItemDefaultMoves = sParty_GamerR8Stan}
    },
    [TRAINER_SUPER_NERD_AIDAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_A, _i, _d, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdR8Aidan),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdR8Aidan}
    },

    //~~~~~~~~~~~~~~~~~~|Route 16|~~~~~~~~~~~~~~~~~~//
    //Pre-Pokeflute
    [TRAINER_YOUNG_COUPLE_LEA_JED] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNG_COUPLE,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = {_L, _e, _a, _SPACE, _HYPHEN, _SPACE, _J, _e, _d, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungCoupleR16LeaJed),
        .party = {.NoItemDefaultMoves = sParty_YoungCoupleR16LeaJed}
    },

    //~~~~~~~~~~~~~~~~~~|Celadon Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_LASS_KAY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_K, _a, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassCeladonGymKay),
        .party = {.NoItemDefaultMoves = sParty_LassCeladonGymKay}
    },
    [TRAINER_BEAUTY_BRIDGET] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_B, _r, _i, _d, _g, _e, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyCeladonGymBridget),
        .party = {.NoItemDefaultMoves = sParty_BeautyCeladonGymBridget}
    },
    [TRAINER_COOLTRAINER_MARY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = {_M, _a, _r, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolTrainerCeladonGymMary),
        .party = {.NoItemDefaultMoves = sParty_CoolTrainerCeladonGymMary}
    },
    [TRAINER_LASS_LISA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_LASS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = {_L, _i, _s, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_LassCeladonGymLisa),
        .party = {.NoItemDefaultMoves = sParty_LassCeladonGymLisa}
    },
    [TRAINER_PICNICKER_TINA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_T, _i, _n, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerCeladonGymTina),
        .party = {.NoItemDefaultMoves = sParty_PicknickerCeladonGymTina}
    },
    [TRAINER_BEAUTY_LORI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_L, _o ,_r, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyCeladonGymLori),
        .party = {.NoItemDefaultMoves = sParty_BeautyCeladonGymLori}
    },
    [TRAINER_BEAUTY_TAMIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_T, _a ,_m, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyCeladonGymTamia),
        .party = {.NoItemDefaultMoves = sParty_BeautyCeladonGymTamia}
    },
    [TRAINER_LEADER_ERIKA] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_ERIKA,
        .trainerName = {_E, _r, _i, _k, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderCeladonGymErika),
        .party = {.NoItemCustomMoves = sParty_LeaderCeladonGymErika}
    },


    //~~~~~~~~~~~~~~~~~~|Rocket Hideout|~~~~~~~~~~~~~~~~~~//
    [TRAINER_TEAM_ROCKET_GRUNT_7] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_7),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_7}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_8] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_8),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_8}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_9] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_9),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_9}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_10] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_10),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_10}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_11] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_11),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_11}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_12] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_12),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_12}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_13] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_13),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_13}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_14] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_14),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_14}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_15] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_15),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_15}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_16] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_16),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_16}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_17] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_17),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_17}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_18] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketHideout_18),
        .party = {.NoItemDefaultMoves = sParty_RocketHideout_18}
    },
    [TRAINER_BOSS_GIOVANNI] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_BOSS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .trainerName = GIOVANNI_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RocketBossHideoutGiovani),
        .party = {.NoItemCustomMoves = sParty_RocketBossHideoutGiovani}
    },

    //~~~~~~~~~~~~~~~~~~|Pokemon Tower|~~~~~~~~~~~~~~~~~~//
    //POST SILpHSCOPE
    [TRAINER_CHANNELER_HOPE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_H, _o, _p, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerHope),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerHope}
    },
    [TRAINER_CHANNELER_PATRICIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_P, _a, _t, _r, _i, _c, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerPatricia),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerPatricia}
    },
    [TRAINER_CHANNELER_CARLY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_C, _a, _r, _l, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerCarly),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerCarly}
    },
    [TRAINER_CHANNELER_LAUREL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_L, _a, _u, _r, _e, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerLaurel),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerLaurel}
    },
    [TRAINER_CHANNELER_JODY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_J, _o, _d, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerJody),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerJody}
    },
    [TRAINER_CHANNELER_PAULA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_P, _a, _u, _l, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerPaula),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerPaula}
    },
    [TRAINER_CHANNELER_RUTH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_R, _u, _t, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerRuth),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerRuth}
    },
    [TRAINER_CHANNELER_KARINA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_K, _a, _r, _i, _n, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerKarina),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerKarina}
    },
    [TRAINER_CHANNELER_JANAE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_J, _a, _n, _a, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerJanae),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerJanae}
    },
    [TRAINER_CHANNELER_ANGELICA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_A, _n, _g, _e, _l, _i, _c, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerAngelica),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerAngelica}
    },
    [TRAINER_CHANNELER_EMILIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_E, _m, _i, _l, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerEmilia),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerEmilia}
    },
    [TRAINER_CHANNELER_JENNIFER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_J, _e, _n, _n, _i, _f, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerPkmTowerJennifer),
        .party = {.NoItemDefaultMoves = sParty_ChannelerPkmTowerJennifer}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_19] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketPkmTower_19),
        .party = {.NoItemDefaultMoves = sParty_RocketPkmTower_19}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_20] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketPkmTower_20),
        .party = {.NoItemDefaultMoves = sParty_RocketPkmTower_20}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_21] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketPkmTower_21),
        .party = {.NoItemDefaultMoves = sParty_RocketPkmTower_21}
    },


    //~~~~~~~~~~~~~~~~~~|Fighting Dojo|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BLACK_BELT_HIDEKI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_H, _i, _d, _e, _k, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltDojoHideki),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltDojoHideki}
    },
    [TRAINER_BLACK_BELT_AARON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_A, _a, _r, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltDojoAaron),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltDojoAaron}
    },
    [TRAINER_BLACK_BELT_HITOSHI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_H, _i, _t, _o, _s, _h, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltDojoHitoshi),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltDojoHitoshi}
    },
    [TRAINER_BLACK_BELT_MIKE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_M, _i, _k, _e,_END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltDojoMike),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltDojoMike}
    },
    [TRAINER_BLACK_BELT_KOICHI] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_K, _o, _i, _c, _h, _i, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_BlackBeltBossDojoKoichi),
        .party = {.NoItemCustomMoves = sParty_BlackBeltBossDojoKoichi}
    },
    

    //~~~~~~~~~~~~~~~~~~|Silph Co|~~~~~~~~~~~~~~~~~~//
    [TRAINER_TEAM_ROCKET_GRUNT_24] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_24),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_24}
    },
    [TRAINER_SCIENTIST_JERRY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_J, _e, _r, _r, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphJerry),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphJerry}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_23] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_23),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_23}
    },
    [TRAINER_SCIENTIST_CONNOR] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_C, _o, _n, _n, _o, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphConnor),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphConnor}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_25] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_25),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_25}
    },
    [TRAINER_SCIENTIST_JOSE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_J, _o, _s, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphJose),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphJose}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_27] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_27),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_27}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_26] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_26),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_26}
    },
    [TRAINER_SCIENTIST_RODNEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_R, _o, _d, _n, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphRodney),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphRodney}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_29] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_29),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_29}
    },
    [TRAINER_JUGGLER_DALTON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_D, _a, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerSilphDalton),
        .party = {.NoItemDefaultMoves = sParty_JugglerSilphDalton}
    },
    [TRAINER_SCIENTIST_BEAU] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_B, _e, _a, _u, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphBeau),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphBeau}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_28] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_28),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_28}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_30] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_30),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_30}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_31] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_31),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_31}
    },
    [TRAINER_SCIENTIST_TAYLOR] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_T, _a, _y, _l, _o, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphTaylor),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphTaylor}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_33] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_33),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_33}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_35] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_35),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_35}
    },
    [TRAINER_SCIENTIST_JOSHUA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_J, _o, _s, _h, _u, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphJoshua),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphJoshua}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_34] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_34),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_34}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_32] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_32),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_32}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_36] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_36),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_36}
    },
    [TRAINER_SCIENTIST_PARKER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_P, _a, _r, _k, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphParker),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphParker}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_38] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_38),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_38}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_37] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_37),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_37}
    },
    [TRAINER_SCIENTIST_ED] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_E, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphEd),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphEd}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_39] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_39),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_39}
    },
    [TRAINER_SCIENTIST_TRAVIS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_T, _r, _a, _v, _i, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistSilphTravis),
        .party = {.NoItemDefaultMoves = sParty_ScientistSilphTravis}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_40] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_40),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_40}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_41] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TEAM_ROCKET,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = GRUNT_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RocketSilph_41),
        .party = {.NoItemDefaultMoves = sParty_RocketSilph_41}
    },



    [TRAINER_RIVAL_SILPH_WATER] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalSilphWater),
        .party = {.ItemCustomMoves = sParty_RivalSilphWater}
    },
    [TRAINER_RIVAL_SILPH_GRASS] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalSilphGrass),
        .party = {.ItemCustomMoves = sParty_RivalSilphGrass}
    },
    [TRAINER_RIVAL_SILPH_FIRE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalSilphFire),
        .party = {.ItemCustomMoves = sParty_RivalSilphFire}
    },
    [TRAINER_BOSS_GIOVANNI_2] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_BOSS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .trainerName = GIOVANNI_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RocketBossSilphGiovani),
        .party = {.NoItemCustomMoves = sParty_RocketBossSilphGiovani}
    },


    //~~~~~~~~~~~~~~~~~~|Saffron Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_PSYCHIC_CAMERON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PSYCHIC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = {_C, _a, _m, _e, _r, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PsychicSaffronGymCameron),
        .party = {.NoItemDefaultMoves = sParty_PsychicSaffronGymCameron}
    },
    [TRAINER_PSYCHIC_TYRON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PSYCHIC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = {_T, _y, _r, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PsychicSaffronGymTyron),
        .party = {.NoItemDefaultMoves = sParty_PsychicSaffronGymTyron}
    },
    [TRAINER_CHANNELER_STACY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_S, _t, _a, _c, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerSaffronGymStacy),
        .party = {.NoItemDefaultMoves = sParty_ChannelerSaffronGymStacy}
    },
    [TRAINER_PSYCHIC_PRESTON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PSYCHIC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = {_P, _r, _e, _s, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PsychicSaffronGymPreston),
        .party = {.NoItemDefaultMoves = sParty_PsychicSaffronGymPreston}
    },
    [TRAINER_CHANNELER_AMANDA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_A, _m, _a, _n, _d, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerSaffronGymAmanda),
        .party = {.NoItemDefaultMoves = sParty_ChannelerSaffronGymAmanda}
    },
    [TRAINER_CHANNELER_TASHA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CHANNELER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = {_T, _a, _s, _h, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ChannelerSaffronGymTasha),
        .party = {.NoItemDefaultMoves = sParty_ChannelerSaffronGymTasha}
    },
    [TRAINER_PSYCHIC_JOHAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PSYCHIC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = {_J, _o, _h, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PsychicSaffronGymJohan),
        .party = {.NoItemDefaultMoves = sParty_PsychicSaffronGymJohan}
    },
    [TRAINER_LEADER_SABRINA] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_SABRINA,
        .trainerName = {_S, _a, _b, _r, _i, _n, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderSaffronSabrina),
        .party = {.NoItemCustomMoves = sParty_LeaderSaffronSabrina}
    },

    //~~~~~~~~~~~~~~~~~~|Route 16|~~~~~~~~~~~~~~~~~~//
    //Post-Pokeflute
    [TRAINER_BIKER_LAO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_L, _a, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR16Lao),
        .party = {.NoItemDefaultMoves = sParty_BikerR16Lao}
    },
    [TRAINER_CUE_BALL_KOJI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_K, _o, _j, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR16Koji),
        .party = {.NoItemDefaultMoves = sParty_CueBallR16Koji}
    },
    [TRAINER_CUE_BALL_LUKE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_L, _u, _k, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR16Luke),
        .party = {.NoItemDefaultMoves = sParty_CueBallR16Luke}
    },
    [TRAINER_BIKER_HIDEO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_H, _i, _d, _e, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR16Hideo),
        .party = {.NoItemDefaultMoves = sParty_BikerR16Hideo}
    },
    [TRAINER_BIKER_RUBEN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_R, _u, _b, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR16Ruben),
        .party = {.NoItemDefaultMoves = sParty_BikerR16Ruben}
    },
    [TRAINER_CUE_BALL_CAMRON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_C, _a, _m, _r, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR16Camron),
        .party = {.NoItemDefaultMoves = sParty_CueBallR16Camron}
    },



    //~~~~~~~~~~~~~~~~~~|Route 17|~~~~~~~~~~~~~~~~~~//
    [TRAINER_CUE_BALL_ISAIAH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_I, _s, _a, _i, _a, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR17Isaiah),
        .party = {.NoItemDefaultMoves = sParty_CueBallR17Isaiah}
    },
    [TRAINER_BIKER_VIRGIL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_V, _i, _r, _g, _i, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR17Virgil),
        .party = {.NoItemDefaultMoves = sParty_BikerR17Virgil}
    },
    [TRAINER_CUE_BALL_RAUL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_R, _a, _u, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR17Raul),
        .party = {.NoItemDefaultMoves = sParty_CueBallR17Raul}
    },
    [TRAINER_BIKER_BILLY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_B, _i, _l, _l, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR17Billy),
        .party = {.NoItemDefaultMoves = sParty_BikerR17Billy}
    },
    [TRAINER_CUE_BALL_JAMAL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_J, _a, _m, _a, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR17Jamal),
        .party = {.NoItemDefaultMoves = sParty_CueBallR17Jamal}
    },
    [TRAINER_BIKER_NIKOLAS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_N, _i, _k, _o, _l, _a, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR17Nikolas),
        .party = {.NoItemDefaultMoves = sParty_BikerR17Nikolas}
    },
    [TRAINER_CUE_BALL_ZEEK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_Z, _e, _e, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR17Zeek),
        .party = {.NoItemDefaultMoves = sParty_CueBallR17Zeek}
    },
    [TRAINER_CUE_BALL_COREY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_C, _o, _r, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueBallR17Corey),
        .party = {.NoItemDefaultMoves = sParty_CueBallR17Corey}
    },
    [TRAINER_BIKER_JAXON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_J, _a, _x, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR17Jaxon),
        .party = {.NoItemDefaultMoves = sParty_BikerR17Jaxon}
    },
    [TRAINER_BIKER_WILLIAM] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_W, _i, _l, _l, _i, _a, _m, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR17William),
        .party = {.NoItemDefaultMoves = sParty_BikerR17William}
    },




    //~~~~~~~~~~~~~~~~~~|Route 18|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BIRD_KEEPER_JACOB] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_J, _a, _c, _o, _b, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR18Jacob),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR18Jacob}
    },
    [TRAINER_BIRD_KEEPER_WILTON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_W, _i, _l, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR18Wilton),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR18Wilton}
    },
    [TRAINER_BIRD_KEEPER_RAMIRO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_R, _a, _m, _i, _r, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR18Ramiro),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR18Ramiro}
    },


    //~~~~~~~~~~~~~~~~~~|Route 12|~~~~~~~~~~~~~~~~~~//
    [TRAINER_FISHERMAN_NED] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_N, _e, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR12Ned),
        .party = {.NoItemDefaultMoves = sParty_FishermanR12Ned}
    },
    [TRAINER_FISHERMAN_CHIP] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_C, _h, _i, _p, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR12Chip),
        .party = {.NoItemDefaultMoves = sParty_FishermanR12Chip}
    },
    [TRAINER_FISHERMAN_HANK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_H, _a, _n, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR12Hank),
        .party = {.NoItemDefaultMoves = sParty_FishermanR12Hank}
    },
    [TRAINER_FISHERMAN_ELLIOT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_E, _l, _l, _i, _o, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR12Elliot),
        .party = {.NoItemDefaultMoves = sParty_FishermanR12Elliot}
    },
    [TRAINER_YOUNG_COUPLE_GIA_JES] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNG_COUPLE,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = {_G, _i, _a, _SPACE, _HYPHEN, _SPACE, _J, _e, _s, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungCoupleR12GiaJes),
        .party = {.NoItemDefaultMoves = sParty_YoungCoupleR12GiaJes}
    },
    [TRAINER_ROCKER_LUCA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_ROCKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = {_L, _u, _c, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RockerR12Luca),
        .party = {.NoItemDefaultMoves = sParty_RockerR12Luca}
    },
    [TRAINER_CAMPER_JUSTIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_J, _u, _s, _t, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperR12Justin),
        .party = {.NoItemDefaultMoves = sParty_CamperR12Justin}
    },
    [TRAINER_FISHERMAN_ANDREW] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_A, _n, _d, _r, _e, _w, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR12Andrew),
        .party = {.NoItemDefaultMoves = sParty_FishermanR12Andrew}
    },


    //~~~~~~~~~~~~~~~~~~|Route 13|~~~~~~~~~~~~~~~~~~//
    [TRAINER_PICNICKER_ALMA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_A, _l, _m, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR13Alma),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR13Alma}
    },
    [TRAINER_BIRD_KEEPER_SEBASTIAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_S, _e, _b, _a, _s, _t, _i , _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR13Sebastian),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR13Sebastian}
    },
    [TRAINER_PICNICKER_SUSIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_S, _u, _s, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR13Susie),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR13Susie}
    },
    [TRAINER_BEAUTY_LOLA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_L, _o, _l, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyR13Lola),
        .party = {.NoItemDefaultMoves = sParty_BeautyR13Lola}
    },
    [TRAINER_BEAUTY_SHEILA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_S, _h, _e, _i, _l, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyR13Sheila),
        .party = {.NoItemDefaultMoves = sParty_BeautyR13Sheila}
    },
    [TRAINER_PICNICKER_VALERIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_V, _a, _l, _e, _r, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR13Valerie),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR13Valerie}
    },
    [TRAINER_PICNICKER_GWEN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_G, _w, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR13Gwen),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR13Gwen}
    },
    [TRAINER_BIRD_KEEPER_ROBERT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_R, _o, _b, _e, _r, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR13Robert),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR13Robert}
    },
    [TRAINER_BIRD_KEEPER_PERRY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_P, _e, _r, _r, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR13Perry),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR13Perry}
    },
    [TRAINER_BIKER_JARED] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_J, _a, _r, _e, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR13Jared),
        .party = {.NoItemDefaultMoves = sParty_BikerR13Jared}
    },


    //~~~~~~~~~~~~~~~~~~|Route 14|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BIRD_KEEPER_CARTER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_C, _a, _r, _t, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR14Carter),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR14Carter}
    },
    [TRAINER_BIRD_KEEPER_MITCH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_M, _i, _t, _c, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR14Mitch),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR14Mitch}
    },
    [TRAINER_BIRD_KEEPER_BECK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_B, _e, _c, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR14Beck),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR14Beck}
    },
    [TRAINER_BIRD_KEEPER_MARLON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_M, _a, _r, _l, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR14Marlon),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR14Marlon}
    },
    [TRAINER_BIRD_KEEPER_DONALD] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_D, _o, _n, _a, _l, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR14Donald),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR14Donald}
    },
    [TRAINER_BIRD_KEEPER_BENNY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_B, _e, _n, _n, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR14Benny),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR14Benny}
    },
    [TRAINER_TWINS_KIRI_JAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TWINS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = {_K, _i, _r, _i, _SPACE, _HYPHEN, _SPACE, _J, _a, _n, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TwinsR14KiriJan),
        .party = {.NoItemDefaultMoves = sParty_TwinsR14KiriJan}
    },
    [TRAINER_BIKER_GERALD] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_G, _e, _r, _a, _l, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR14Gerald),
        .party = {.NoItemDefaultMoves = sParty_BikerR14Gerald}
    },
    [TRAINER_BIKER_MALIK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_M, _a, _l, _i, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR14Malik),
        .party = {.NoItemDefaultMoves = sParty_BikerR14Malik}
    },
    [TRAINER_BIKER_LUKAS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_L, _u, _k, _a, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR14Lukas),
        .party = {.NoItemDefaultMoves = sParty_BikerR14Lukas}
    },
    [TRAINER_BIKER_ISAAC] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_I, _s, _a, _a, _c, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR14Isaac),
        .party = {.NoItemDefaultMoves = sParty_BikerR14Isaac}
    },



    //~~~~~~~~~~~~~~~~~~|Route 15|~~~~~~~~~~~~~~~~~~//
    [TRAINER_PICNICKER_BECKY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_B, _e, _c, _k, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR15Becky),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR15Becky}
    },
    [TRAINER_CRUSH_KIN_RON_MYA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CRUSH_KIN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = {_R, _o, _n, _SPACE, _HYPHEN, _SPACE, _M, _y, _a, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CrushKinR15RonMya),
        .party = {.NoItemDefaultMoves = sParty_CrushKinR15RonMya}
    },
    [TRAINER_PICNICKER_CELIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_C, _e, _l, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR15Celia),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR15Celia}
    },
    [TRAINER_BIKER_ERNEST] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_E, _r, _n, _e, _s, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR15Ernest),
        .party = {.NoItemDefaultMoves = sParty_BikerR15Ernest}
    },
    [TRAINER_BIKER_ALEX] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = {_A, _l, _e, _x, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerR15Alex),
        .party = {.NoItemDefaultMoves = sParty_BikerR15Alex}
    },
    [TRAINER_BEAUTY_GRACE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_G, _r, _a, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyR15Grace),
        .party = {.NoItemDefaultMoves = sParty_BeautyR15Grace}
    },
    [TRAINER_BEAUTY_OLIVIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BEAUTY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = {_O, _l, _i, _v, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BeautyR15Olivia),
        .party = {.NoItemDefaultMoves = sParty_BeautyR15Olivia}
    },
    [TRAINER_PICNICKER_KINDRA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_K, _i, _n, _d, _r, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR15Kindra),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR15Kindra}
    },
    [TRAINER_BIRD_KEEPER_CHESTER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_C, _h, _e, _s, _t, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR15Chester),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR15Chester}
    },
    [TRAINER_BIRD_KEEPER_EDWIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_E, _d, _w, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR15Edwin),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR15Edwin}
    },
    [TRAINER_PICNICKER_YAZMIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_Y, _a, _z, _m, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR15Yazmin),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR15Yazmin}
    },


    //~~~~~~~~~~~~~~~~~~|Fuchsia Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_JUGGLER_KAYDEN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_K, _a, _y, _d, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerFuchsiaKayden),
        .party = {.NoItemDefaultMoves = sParty_JugglerFuchsiaKayden}
    },
    [TRAINER_JUGGLER_NATE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_N, _a, _t, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerFuchsiaNate),
        .party = {.NoItemDefaultMoves = sParty_JugglerFuchsiaNate}
    },
    [TRAINER_JUGGLER_KIRK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_K, _i, _r, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerFuchsiaKirk),
        .party = {.NoItemDefaultMoves = sParty_JugglerFuchsiaKirk}
    },
    [TRAINER_JUGGLER_SHAWN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_S, _h, _a, _w, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerFuchsiaShawn),
        .party = {.NoItemDefaultMoves = sParty_JugglerFuchsiaShawn}
    },
    [TRAINER_TAMER_PHIL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TAMER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = {_P, _h, _i, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TamerFuchsiaPhil),
        .party = {.NoItemDefaultMoves = sParty_TamerFuchsiaPhil}
    },
    [TRAINER_TAMER_EDGAR] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TAMER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = {_E, _d, _g, _a, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TamerFuchsiaEdgar),
        .party = {.NoItemDefaultMoves = sParty_TamerFuchsiaEdgar}
    },
    [TRAINER_LEADER_KOGA] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_KOGA,
        .trainerName = {_K, _o, _g, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderFuchsiaKoga),
        .party = {.NoItemCustomMoves = sParty_LeaderFuchsiaKoga}
    },



    //~~~~~~~~~~~~~~~~~~|Route 19|~~~~~~~~~~~~~~~~~~//
    [TRAINER_SWIMMER_MALE_RICHARD] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_R, _i, _c, _h, _a, _r, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19Richard),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19Richard}
    },
    [TRAINER_SWIMMER_MALE_REECE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_R, _e, _e, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19Reece),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19Reece}
    },
    [TRAINER_SWIMMER_MALE_MATTHEW] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_M, _a, _t, _t, _h, _e, _w, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19Mathew),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19Mathew}
    },
    [TRAINER_SWIMMER_MALE_DOUGLAS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_D, _o, _u, _g, _l, _a, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19Douglas),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19Douglas}
    },
    [TRAINER_SWIMMER_MALE_DAVID] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_D, _a, _v, _i, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19David),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19David}
    },
    [TRAINER_SWIMMER_MALE_TONY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_T, _o, _n, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19Tony),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19Tony}
    },
    [TRAINER_SWIMMER_MALE_AXLE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_A, _x, _l, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR19Axle),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR19Axle}
    },

    [TRAINER_SIS_AND_BRO_LIA_LUC] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SIS_AND_BRO,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = {_L, _i, _a, _SPACE, _HYPHEN, _SPACE, _L, _u, _c, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SisAndBroR19LiaLuc),
        .party = {.NoItemDefaultMoves = sParty_SisAndBroR19LiaLuc}
    },
    [TRAINER_SWIMMER_FEMALE_ANYA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_A, _n, _y, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR19Anya),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR19Anya}
    },
    [TRAINER_SWIMMER_FEMALE_ALICE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_A, _l, _i, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR19Alice),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR19Alice}
    },
    [TRAINER_SWIMMER_FEMALE_CONNIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_C, _o, _n, _n, _i, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR19Connie),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR19Connie}
    },

    //~~~~~~~~~~~~~~~~~~|Route 21|~~~~~~~~~~~~~~~~~~//
    [TRAINER_FISHERMAN_WADE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_W, _a, _d, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR21Wade),
        .party = {.NoItemDefaultMoves = sParty_FishermanR21Wade}
    },
    [TRAINER_FISHERMAN_RONALD] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_R, _o, _n, _a, _l, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR21Ronald),
        .party = {.NoItemDefaultMoves = sParty_FishermanR21Ronald}
    },
    [TRAINER_SIS_AND_BRO_LIL_IAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SIS_AND_BRO,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = {_L, _i, _l, _SPACE, _HYPHEN, _SPACE, _I, _a, _n, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SisAndBroR21LilIan),
        .party = {.NoItemDefaultMoves = sParty_SisAndBroR21LilIan}
    },
    [TRAINER_SWIMMER_MALE_SPENCER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_S, _p, _e, _n, _c, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR21Spencer),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR21Spencer}
    },
    [TRAINER_FISHERMAN_CLAUDE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_C, _l, _a, _u, _d, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR21Claude),
        .party = {.NoItemDefaultMoves = sParty_FishermanR21Claude}
    },
    [TRAINER_FISHERMAN_NOLAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_N, _o, _l, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanR21Nolan),
        .party = {.NoItemDefaultMoves = sParty_FishermanR21Nolan}
    },
    [TRAINER_SWIMMER_MALE_JACK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_J, _a, _c, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR21Jack),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR21Jack}
    },
    [TRAINER_SWIMMER_MALE_JEROME] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_J, _e, _r, _o, _m, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR21Jerome),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR21Jerome}
    },
    [TRAINER_SWIMMER_MALE_ROLAND] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_R, _o, _l, _a, _n, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR21Roland),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR21Roland}
    },


    //~~~~~~~~~~~~~~~~~~|Route 20|~~~~~~~~~~~~~~~~~~//
    [TRAINER_SWIMMER_MALE_BARRY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_B, _a, _r, _r, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR20Barry),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR20Barry}
    },
    [TRAINER_SWIMMER_MALE_DARRIN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_D, _a, _r, _r, _i, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR20Darrin),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR20Darrin}
    },
    [TRAINER_SWIMMER_FEMALE_SHIRLEY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_S, _h, _i, _r, _l, _e, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR20Shirley),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR20Shirley}
    },
    [TRAINER_SWIMMER_FEMALE_TIFFANY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_T, _i, _f, _f, _a, _n, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR20Tiffany),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR20Tiffany}
    },
    [TRAINER_PICNICKER_IRENE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_I, _r, _e, _n, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR20Irene),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR20Irene}
    },
    [TRAINER_BIRD_KEEPER_ROGER] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIRD_KEEPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = {_R, _o, _g, _e, _r, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BirdKeeperR20Roger),
        .party = {.NoItemDefaultMoves = sParty_BirdKeeperR20Roger}
    },
    [TRAINER_SWIMMER_FEMALE_NORA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_N, _o, _r, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR20Nora),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR20Nora}
    },
    [TRAINER_SWIMMER_MALE_DEAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_D, _e, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMR20Dean),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMR20Dean}
    },
    [TRAINER_PICNICKER_MISSY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_M, _i, _s, _s, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerR20Missy),
        .party = {.NoItemDefaultMoves = sParty_PicknickerR20Missy}
    },
    [TRAINER_SWIMMER_FEMALE_MELISSA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_M, _e, _l, _i, _s, _s, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFR20Melissa),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFR20Melissa}
    },


    //~~~~~~~~~~~~~~~~~~|Pokemon Mansion|~~~~~~~~~~~~~~~~~~//
    [TRAINER_YOUNGSTER_JOHNSON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_YOUNGSTER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = {_J, _o, _h, _n, _s, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_YoungsterPkmMansionJohnson),
        .party = {.NoItemDefaultMoves = sParty_YoungsterPkmMansionJohnson}
    },
    [TRAINER_BURGLAR_ARNIE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BURGLAR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = {_J, _o, _h, _n, _s, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BurglerPkmMansionArnie),
        .party = {.NoItemDefaultMoves = sParty_BurglerPkmMansionArnie}
    },
    [TRAINER_BURGLAR_SIMON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BURGLAR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = {_S, _i, _m, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BurglerPkmMansionSimon),
        .party = {.NoItemDefaultMoves = sParty_BurglerPkmMansionSimon}
    },
    [TRAINER_SCIENTIST_BRAYDON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_B, _r, _a, _y, _d, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistPkmMansionBraydon),
        .party = {.NoItemDefaultMoves = sParty_ScientistPkmMansionBraydon}
    },
    [TRAINER_SCIENTIST_TED] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_T, _e, _d, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistPkmMansionTed),
        .party = {.NoItemDefaultMoves = sParty_ScientistPkmMansionTed}
    },
    [TRAINER_BURGLAR_LEWIS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BURGLAR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = {_L, _e, _w, _i, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BurglerPkmMansionLewis),
        .party = {.NoItemDefaultMoves = sParty_BurglerPkmMansionLewis}
    },
    [TRAINER_SCIENTIST_IVAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SCIENTIST,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCIENTIST_M,
        .trainerName = {_I, _v, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_ScientistPkmMansionIvan),
        .party = {.NoItemDefaultMoves = sParty_ScientistPkmMansionIvan}
    },

    //~~~~~~~~~~~~~~~~~~|Route 10|~~~~~~~~~~~~~~~~~~//
    //Outside PowerPlant
    [TRAINER_POKEMANIAC_MARK] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_M, _a, _r, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacR10Mark),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacR10Mark}
    },

    //~~~~~~~~~~~~~~~~~~|Cinnabar Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BURGLAR_QUINN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BURGLAR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = {_Q, _u, _i, _n, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BurglerCinnabarGymQuinn),
        .party = {.NoItemDefaultMoves = sParty_BurglerCinnabarGymQuinn}
    },
    [TRAINER_SUPER_NERD_ERIK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_E, _r, _i, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdCinnabarGymErik),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdCinnabarGymErik}
    },
    [TRAINER_SUPER_NERD_AVERY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_A, _v, _e, _r, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdCinnabarGymAvery),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdCinnabarGymAvery}
    },
    [TRAINER_BURGLAR_RAMON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BURGLAR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = {_R, _a, _m, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BurglerCinnabarGymRamon),
        .party = {.NoItemDefaultMoves = sParty_BurglerCinnabarGymRamon}
    },
    [TRAINER_SUPER_NERD_DEREK] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_D, _e, _r, _e, _k, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdCinnabarGymDerek),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdCinnabarGymDerek}
    },
    [TRAINER_BURGLAR_DUSTY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BURGLAR,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = {_D, _u, _s, _t, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BurglerCinnabarGymDusty),
        .party = {.NoItemDefaultMoves = sParty_BurglerCinnabarGymDusty}
    },
    [TRAINER_SUPER_NERD_ZAC] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SUPER_NERD,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = {_Z, _a, _c, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SuperNerdCinnabarGymZac),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdCinnabarGymZac}
    },
    [TRAINER_LEADER_BLAINE] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLAINE,
        .trainerName = {_B, _l, _a, _i, _n, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderCinnabarBlaine),
        .party = {.NoItemCustomMoves = sParty_LeaderCinnabarBlaine}
    },

    //~~~~~~~~~~~~~~~~~~|Treasure Beach|~~~~~~~~~~~~~~~~~~//
    [TRAINER_SWIMMER_FEMALE_AMARA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_A, _m, _a, _r, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFTreasureBeachAmara),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFTreasureBeachAmara}
    },

    //~~~~~~~~~~~~~~~~~~|Kindle Road|~~~~~~~~~~~~~~~~~~//
    [TRAINER_SWIMMER_FEMALE_ABIGAIL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_A, _b, _i, _g, _a, _i, _l, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFKindleRoadAbigail),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFKindleRoadAbigail}
    },
    [TRAINER_PICNICKER_CLAIRE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PICNICKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = {_C, _l, _a, _i, _r, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PicknickerKindleRoadClaire),
        .party = {.NoItemDefaultMoves = sParty_PicknickerKindleRoadClaire}
    },
    [TRAINER_CRUSH_GIRL_TANYA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CRUSH_GIRL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = {_T, _a, _n, _y, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CrushGirlKindleRoadTanya),
        .party = {.NoItemDefaultMoves = sParty_CrushGirlKindleRoadTanya}
    },
    [TRAINER_CAMPER_BRYCE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CAMPER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = {_B, _r, _y, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CamperKindleRoadBryce),
        .party = {.NoItemDefaultMoves = sParty_CamperKindleRoadBryce}
    },
    [TRAINER_SWIMMER_MALE_GARRETT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_G, _a, _r, _r, _e, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMKindleRoadGarret),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMKindleRoadGarret}
    },
    [TRAINER_CRUSH_KIN_MIK_KIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CRUSH_KIN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = {_M, _i, _k, _SPACE, _HYPHEN, _SPACE, _K, _i, _a, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CrushKinKindleRoadMikKia),
        .party = {.NoItemDefaultMoves = sParty_CrushKinKindleRoadMikKia}
    },
    [TRAINER_BLACK_BELT_HUGH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_H, _u, _g, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltKindleRoadHugh),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltKindleRoadHugh}
    },
    [TRAINER_BLACK_BELT_SHEA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_S, _h, _e, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltKindleRoadShea),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltKindleRoadShea}
    },
    [TRAINER_CRUSH_GIRL_SHARON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CRUSH_GIRL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = {_S, _h, _a, _r, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CrushGirlKindleRoadSharon),
        .party = {.NoItemDefaultMoves = sParty_CrushGirlKindleRoadSharon}
    },
    [TRAINER_SWIMMER_MALE_FINN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_M,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = {_F, _i, _n, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerMKindleRoadFinn),
        .party = {.NoItemDefaultMoves = sParty_SwimmerMKindleRoadFinn}
    },
    [TRAINER_SWIMMER_FEMALE_MARIA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_M, _a, _r, _i, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFKindleRoadMaria),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFKindleRoadMaria}
    },
    [TRAINER_FISHERMAN_TOMMY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_FISHERMAN,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = {_T, _o, _m, _m, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_FishermanKindleRoadTommy),
        .party = {.NoItemDefaultMoves = sParty_FishermanKindleRoadTommy}
    },

    //~~~~~~~~~~~~~~~~~~|MT Ember|~~~~~~~~~~~~~~~~~~//
    [TRAINER_PKMN_RANGER_BETH] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PKMN_RANGER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PKMN_RANGER_F,
        .trainerName = {_B, _e, _t, _h, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RangerMtEmberBeth),
        .party = {.NoItemDefaultMoves = sParty_RangerMtEmberBeth}
    },
    [TRAINER_CRUSH_GIRL_JOCELYN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CRUSH_GIRL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = {_J, _o, _c, _e, _l, _y, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CrushGirlMtEmberJocelyn),
        .party = {.NoItemDefaultMoves = sParty_CrushGirlMtEmberJocelyn}
    },
    [TRAINER_PKMN_RANGER_LOGAN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PKMN_RANGER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PKMN_RANGER_M,
        .trainerName = {_L, _o, _g, _a, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_RangerMtEmberLogan),
        .party = {.NoItemDefaultMoves = sParty_RangerMtEmberLogan}
    },

    //~~~~~~~~~~~~~~~~~~|Three Island Town|~~~~~~~~~~~~~~~~~~//
    [TRAINER_BIKER_GOON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = GOON_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerThreeTownGoon_1),
        .party = {.NoItemDefaultMoves = sParty_BikerThreeTownGoon_1}
    },
    [TRAINER_BIKER_GOON_2] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = GOON_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerThreeTownGoon_2),
        .party = {.NoItemDefaultMoves = sParty_BikerThreeTownGoon_2}
    },
    [TRAINER_BIKER_GOON_3] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BIKER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = GOON_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BikerThreeTownGoon_3),
        .party = {.NoItemDefaultMoves = sParty_BikerThreeTownGoon_3}
    },
    [TRAINER_CUE_BALL_PAXTON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_CUE_BALL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = {_P, _a, _x, _t, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CueballThreeTownPaxton),
        .party = {.NoItemDefaultMoves = sParty_CueballThreeTownPaxton}
    },
    [TRAINER_TWINS_JOY_MEG] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TWINS,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = {_J, _o, _y, _SPACE, _HYPHEN, _SPACE, _M, _e, _g, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TwinsBondBridgeJoyMeg),
        .party = {.NoItemDefaultMoves = sParty_TwinsBondBridgeJoyMeg}
    },
    [TRAINER_AROMA_LADY_VIOLET] = {
        .partyFlags = 0,
        .trainerClass = CLASS_AROMA_LADY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = {_V, _i, _o, _l, _e, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_AromaBondBridgeViolet),
        .party = {.NoItemDefaultMoves = sParty_AromaBondBridgeViolet}
    },
    [TRAINER_TUBER_ALEXIS] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TUBER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = {_A, _l, _e, _x, _i, _s, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TuberBondBridgeAlexis),
        .party = {.NoItemDefaultMoves = sParty_TuberBondBridgeAlexis}
    },
    [TRAINER_SWIMMER_FEMALE_TISHA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_SWIMMER_F,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = {_T, _i, _s, _h, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_SwimmerFBondBridgeTisha),
        .party = {.NoItemDefaultMoves = sParty_SwimmerFBondBridgeTisha}
    },
    [TRAINER_TUBER_AMIRA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TUBER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = {_A, _m, _i, _r, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TuberBondBridgeAmira),
        .party = {.NoItemDefaultMoves = sParty_TuberBondBridgeAmira}
    },
    [TRAINER_AROMA_LADY_NIKKI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_AROMA_LADY,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = {_N, _i, _k, _k, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_AromaBondBridgeNikki),
        .party = {.NoItemDefaultMoves = sParty_AromaBondBridgeNikki}
    },


    //~~~~~~~~~~~~~~~~~~|Viridian Gym|~~~~~~~~~~~~~~~~~~//
    [TRAINER_TAMER_COLE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TAMER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = {_C, _o, _l, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TamerViridianGymCole),
        .party = {.NoItemDefaultMoves = sParty_TamerViridianGymCole}
    },
    [TRAINER_BLACK_BELT_KIYO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_K, _i, _y, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltViridianGymKiyo),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltViridianGymKiyo}
    },
    [TRAINER_COOLTRAINER_SAMUEL] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = {_C, _o, _l, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolViridianGymSamuel),
        .party = {.NoItemDefaultMoves = sParty_CoolViridianGymSamuel}
    },
    [TRAINER_COOLTRAINER_YUJI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = {_Y, _u, _j, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolViridianGymYuji),
        .party = {.NoItemDefaultMoves = sParty_CoolViridianGymYuji}
    },
    [TRAINER_BLACK_BELT_ATSUSHI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_A, _t, _s, _u, _s, _h, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltViridianGymAtsushi),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltViridianGymAtsushi}
    },
    [TRAINER_TAMER_JASON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TAMER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = {_J, _a, _s, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TamerViridianGymJason),
        .party = {.NoItemDefaultMoves = sParty_TamerViridianGymJason}
    },
    [TRAINER_COOLTRAINER_WARREN] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = {_W, _a, _r, _r, _e, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolViridianGymWarren),
        .party = {.NoItemDefaultMoves = sParty_CoolViridianGymWarren}
    },
    [TRAINER_BLACK_BELT_TAKASHI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_T, _a, _k, _a, _s, _h, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltViridianGymTakashi),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltViridianGymTakashi}
    },
    [TRAINER_LEADER_GIOVANNI] = {
        .partyFlags = PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_LEADER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .trainerName = GIOVANNI_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_LeaderViridianGiovani),
        .party = {.NoItemCustomMoves = sParty_LeaderViridianGiovani}
    },


    //~~~~~~~~~~~~~~~~~~|Route 22 Late Rival|~~~~~~~~~~~~~~~~~~//
    [TRAINER_RIVAL_ROUTE22_LATE_WATER] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalR22LateWater),
        .party = {.ItemCustomMoves = sParty_RivalR22LateWater}
    },
    [TRAINER_RIVAL_ROUTE22_LATE_GRASS] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalR22LateGrass),
        .party = {.ItemCustomMoves = sParty_RivalR22LateGrass}
    },
    [TRAINER_RIVAL_ROUTE22_LATE_FIRE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLUE_2,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalR22LateFire),
        .party = {.ItemCustomMoves = sParty_RivalR22LateFire}
    },

    //~~~~~~~~~~~~~~~~~~|Victory Road|~~~~~~~~~~~~~~~~~~//
    [TRAINER_COOLTRAINER_NAOMI] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = {_N, _a, _o, _m, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolVictoryRoadNaomi),
        .party = {.NoItemDefaultMoves = sParty_CoolVictoryRoadNaomi}
    },
    [TRAINER_COOLTRAINER_ROLANDO] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = {_R, _o, _l, _a, _n, _d, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolVictoryRoadRolando),
        .party = {.NoItemDefaultMoves = sParty_CoolVictoryRoadRolando}
    },
    [TRAINER_BLACK_BELT_DAISUKE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_BLACK_BELT,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = {_D, _a, _i, _s, _u, _k, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_BlackBeltVictoryRoadDaisuke),
        .party = {.NoItemDefaultMoves = sParty_BlackBeltVictoryRoadDaisuke}
    },
    [TRAINER_JUGGLER_NELSON] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_N, _e, _l, _s, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerVictoryRoadNelson),
        .party = {.NoItemDefaultMoves = sParty_JugglerVictoryRoadNelson}
    },
    [TRAINER_TAMER_VINCENT] = {
        .partyFlags = 0,
        .trainerClass = CLASS_TAMER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = {_V, _i, _n, _c, _e, _n, _t, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_TamerVictoryRoadVincent),
        .party = {.NoItemDefaultMoves = sParty_TamerVictoryRoadVincent}
    },
    [TRAINER_JUGGLER_GREGORY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_JUGGLER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = {_G, _r, _e, _g, _o, _r, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_JugglerVictoryRoadGregory),
        .party = {.NoItemDefaultMoves = sParty_JugglerVictoryRoadGregory}
    },
    [TRAINER_COOLTRAINER_GEORGE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = {_G, _e, _o, _r, _g, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolVictoryRoadGeorge),
        .party = {.NoItemDefaultMoves = sParty_CoolVictoryRoadGeorge}
    },
    [TRAINER_POKEMANIAC_DAWSON] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_PIC_POKEMANIAC,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = {_D, _a, _w, _s, _o, _n, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_PokeManiacVictoryRoadDawson),
        .party = {.NoItemDefaultMoves = sParty_PokeManiacVictoryRoadDawson}
    },
    [TRAINER_COOLTRAINER_ALEXA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = {_A, _l, _e, _x, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolVictoryRoadAlexa),
        .party = {.NoItemDefaultMoves = sParty_CoolVictoryRoadAlexa}
    },
    [TRAINER_COOLTRAINER_COLBY] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = {_C, _o, _l, _b, _y, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolVictoryRoadColby),
        .party = {.NoItemDefaultMoves = sParty_CoolVictoryRoadColby}
    },
    [TRAINER_COOLTRAINER_CAROLINE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOLTRAINER,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = {_C, _a, _r, _o, _l, _i, _n, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolVictoryRoadCaroline),
        .party = {.NoItemDefaultMoves = sParty_CoolVictoryRoadCaroline}
    },
    [TRAINER_COOL_COUPLE_RAY_TYRA] = {
        .partyFlags = 0,
        .trainerClass = CLASS_COOL_COUPLE,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .trainerName = {_R, _a, _y, _SPACE, _HYPHEN, _SPACE, _M, _y, _a, _END},
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = NELEMS(sParty_CoolCoupleVictoryRoadRayTyra),
        .party = {.NoItemDefaultMoves = sParty_CoolCoupleVictoryRoadRayTyra}
    },


    //~~~~~~~~~~~~~~~~~~|Elite 4|~~~~~~~~~~~~~~~~~~//

    [TRAINER_ELITE_FOUR_LORELEI] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_ELITE_4,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_LORLEI,
        .trainerName = {_L, _o, _r, _e, _l, _e, _i, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_E4Lorelei),
        .party = {.ItemCustomMoves = sParty_E4Lorelei}
    },
    [TRAINER_ELITE_FOUR_BRUNO] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_ELITE_4,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BRUNO,
        .trainerName = {_B, _r, _u, _n, _o, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_E4Bruno),
        .party = {.ItemCustomMoves = sParty_E4Bruno}
    },
    [TRAINER_ELITE_FOUR_AGATHA] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_ELITE_4,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_AGATHA,
        .trainerName = {_A, _g, _a, _t, _h, _a, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_E4Agatha),
        .party = {.ItemCustomMoves = sParty_E4Agatha}
    },
    [TRAINER_ELITE_FOUR_LANCE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_ELITE_4,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_LANCE,
        .trainerName = {_L, _a, _n, _c, _e, _END},
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_E4Lance),
        .party = {.ItemCustomMoves = sParty_E4Lance}
    },

    [TRAINER_CHAMPION_FIRST_WATER] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BLUE_3,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalChampionWater),
        .party = {.ItemCustomMoves = sParty_RivalChampionWater}
    },
    [TRAINER_CHAMPION_FIRST_GRASS] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BLUE_3,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalChampionGrass),
        .party = {.ItemCustomMoves = sParty_RivalChampionGrass}
    },
    [TRAINER_CHAMPION_FIRST_FIRE] = {
        .partyFlags = PARTY_FLAG_HAS_ITEM | PARTY_FLAG_CUSTOM_MOVES,
        .trainerClass = CLASS_RIVAL,
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BLUE_3,
        .trainerName = RIVAL_NAME,
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_GOOD_MOVE | AI_SCRIPT_SEMI_SMART,
        .partySize = NELEMS(sParty_RivalChampionFire),
        .party = {.ItemCustomMoves = sParty_RivalChampionFire}
    },
};