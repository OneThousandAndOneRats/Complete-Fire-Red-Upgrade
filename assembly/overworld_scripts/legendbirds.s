.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


EventScript_Zapdos:
	lock
    faceplayer
    cry 0x91 0x2
    preparemsg gText_LegendBirdCry 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_ZAPDOS_G 0x32 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto EndThis
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x2BF
    fadescreen 0x0
    release
    end

EventScript_Moltres:
	lock
    faceplayer
    cry 0x92 0x2
    preparemsg gText_LegendBirdCry 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_MOLTRES_G 0x32 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto EndThis
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x2BD
    fadescreen 0x0
    release
    end

 EventScript_Articuno:
	lock
    faceplayer
    cry 0x90 0x2
    preparemsg gText_LegendBirdCry 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_ARTICUNO_G 0x32 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto EndThis
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x2BE
    fadescreen 0x0
    release
    end

EventScript_BruteBonnet:
    lock
    faceplayer
    cry 0x4F3 0x2
    preparemsg gText_BruteBonnetCry 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_BRUTEBONNET 0x32 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto EndThis
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x200
    fadescreen 0x0
    release
    end

EventScript_Articuno_Binoculars:
	lockall
	msgbox gText_ArticunoBinoculars MSG_KEEPOPEN
	showpokepic SPECIES_ARTICUNO_G 0xA 0x3
	pause 0x14
	waitkeypress
	hidepokepic
	setvar 0x8004 0x90
	special 0x163
	releaseall
	end


EndThis:
	release 
    end
