#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

#include "emul/instr_implementation.h"

using namespace std;

/*
int main(int argc, char** argv){
	Proc* cpu = new Proc(4095, 4096);

	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	delete cpu;

	return ret;
}
//*/

int main(int argc, char** argv){
	Proc* cpu = new Proc(4095, 4096);

	int32_t fake = 0;

	cpu->memory->registers[0] = 1;
	cpu->memory->registers[1] = 1;

	printf("R0= %d\nR1= %d\n", cpu->memory->registers[0], cpu->memory->registers[1] );

	Instruction_entry entry;
	entry.mode1 = 0;
	entry.mode2 = 0;
	entry.src = 0;
	entry.dst = 1;

	//

	fake = fetch_two_operand_1(cpu->state, cpu->memory, &entry);
	execute_add(cpu->state, &entry);
	writeback_two_operand_1(cpu->state, cpu->memory, &entry);
	printf("\tResult:\nR0= %d\nR1= %d\n", cpu->memory->registers[0], cpu->memory->registers[1] );


	delete cpu;
	return 0;
}
