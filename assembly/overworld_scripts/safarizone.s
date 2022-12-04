.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_GoldTeeth:
	giveitem ITEM_GOLD_TEETH 0x1 MSG_FIND
	end