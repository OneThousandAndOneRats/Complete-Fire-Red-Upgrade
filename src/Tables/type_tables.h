
/*
@;format: attacking type, defending type, damage multiplier
@;the multiplier is a (decimal) fixed-point number:
@�2.0 TYPE_MUL_SUPER_EFFECTIVE
@�1.0 TYPE_MUL_NORMAL
@;�0.5 TYPE_MUL_NOT_EFFECTIVE
@;�0.0 TYPE_MUL_NO_EFFECT
*/

const u8 gTypeEffectiveness[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{
	[TYPE_NORMAL]=
    {
        [TYPE_ROCK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_NO_EFFECT,
    	[TYPE_MYSTIC] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_BEAST] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_FIRE]=
    {
        [TYPE_FIRE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_WATER] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_BUG] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_DRAGON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_COSMIC] = TYPE_MUL_NOT_EFFECTIVE,
   		[TYPE_BEAST] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_FOOD] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_WATER]=
    {
        [TYPE_FIRE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_WATER] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DRAGON] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_SOUND] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_COSMIC] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_NO_EFFECT,
    },
    [TYPE_ELECTRIC]=
    {
        [TYPE_WATER] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ELECTRIC] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_NO_EFFECT,
        [TYPE_FLYING] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DRAGON] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_LIGHT] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_BEAST] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_GRASS]=
    {
        [TYPE_FIRE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_WATER] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FLYING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_BUG] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DRAGON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_NOT_EFFECTIVE,

    },
    [TYPE_ICE]=
    {
        [TYPE_WATER] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FLYING] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DRAGON] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FIRE] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_BEAST] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_FOOD] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_FIGHTING]=
    {
        [TYPE_NORMAL] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FLYING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_PSYCHIC] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_BUG] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DARK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_NO_EFFECT,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_POISON]=
    {
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NO_EFFECT,
		[TYPE_COSMIC] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_FOOD] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_GROUND]=
    {
        [TYPE_FIRE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ELECTRIC] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FLYING] = TYPE_MUL_NO_EFFECT,
        [TYPE_BUG] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_SOUND] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_COSMIC] = TYPE_MUL_NO_EFFECT,

    },
    [TYPE_FLYING]=
    {
        [TYPE_ELECTRIC] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FIGHTING] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_BUG] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_SOUND] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_COSMIC] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_PSYCHIC]=
    {
        [TYPE_FIGHTING] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_PSYCHIC] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_DARK] = TYPE_MUL_NO_EFFECT,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_SOUND] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_MYSTIC] =  TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_BUG]=
    {
        [TYPE_FIRE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FIGHTING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FLYING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_PSYCHIC] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_DARK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_COSMIC] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_FOOD] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_ROCK]=
    {
        [TYPE_FIRE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FIGHTING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FLYING] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_BUG] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_COSMIC] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_GHOST]=
    {
        [TYPE_NORMAL] = TYPE_MUL_NO_EFFECT,
        [TYPE_PSYCHIC] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DARK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_LIGHT] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_DRAGON]=
    {
        [TYPE_DRAGON] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_NO_EFFECT,
   		[TYPE_LIGHT] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_DARK]=
    {
        [TYPE_FIGHTING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_PSYCHIC] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DARK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_LIGHT] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_STEEL]=
    {
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FIRE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_WATER] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ELECTRIC] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_MYSTIC] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_BEAST] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_FAIRY]=
    {
        [TYPE_POISON] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FIRE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FIGHTING] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DRAGON] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_DARK] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_LIGHT] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_BEAST]=
    {
        [TYPE_MYSTIC] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_PSYCHIC] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_NORMAL] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_FIGHTING] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_FOOD] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_ICE] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_STEEL] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_BUG] =  TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_SOUND]=
    {
        [TYPE_LIGHT] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_ELECTRIC] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_PSYCHIC] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_MYSTIC] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_ICE] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_GROUND] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_WATER] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_STEEL] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_SOUND] = TYPE_MUL_NOT_EFFECTIVE,
    	[TYPE_COSMIC] = TYPE_MUL_NO_EFFECT,
    },
    [TYPE_LIGHT]=
    {
        [TYPE_DARK] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_POISON] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_BUG] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_GROUND] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_COSMIC]=
    {
        [TYPE_LIGHT] = TYPE_MUL_SUPER_EFFECTIVE,
    	[TYPE_SOUND] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_BUG] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_RELIC] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_GRASS] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_ROCK] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_GROUND] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_ICE] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_MYSTIC] =  TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_RELIC]=
    {
        [TYPE_MYSTIC] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_FAIRY] =  TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_GRASS] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_POISON] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_ELECTRIC] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_ROCK] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_DARK] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_PSYCHIC] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_NORMAL] =  TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_MYSTIC]=
    {
       [TYPE_SOUND] =  TYPE_MUL_NOT_EFFECTIVE,
   		[TYPE_COSMIC] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_RELIC] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_DARK] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_PSYCHIC] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_NORMAL] =  TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_BEAST] =  TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_MYSTIC] =  TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_FOOD]=
    {
        [TYPE_FIGHTING] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_PSYCHIC] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_RELIC] = TYPE_MUL_SUPER_EFFECTIVE,
		[TYPE_POISON] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_BUG] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_FLYING] = TYPE_MUL_NOT_EFFECTIVE,
		[TYPE_FOOD] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_NOT_EFFECTIVE,
    },
    [TYPE_FUNGUS]=
    {
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_GHOST] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_WATER] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FUNGUS] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_FOOD] = TYPE_MUL_SUPER_EFFECTIVE,
        [TYPE_ROCK] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FIGHTING] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_FAIRY] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_LIGHT] = TYPE_MUL_NOT_EFFECTIVE,
        [TYPE_ICE] = TYPE_MUL_NO_EFFECT,
    },
    [TYPE_TECH]=
    {
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
    },
    [TYPE_SHADOW]=
    {
        [TYPE_GRASS] = TYPE_MUL_SUPER_EFFECTIVE,
    },
};