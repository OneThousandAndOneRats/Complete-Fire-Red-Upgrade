.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_ViridianForest_LeonsBaseNPC:
	lock
	faceplayer
	msgbox gText_ViridianForestLeonsNPC 0x6
	release
	end
