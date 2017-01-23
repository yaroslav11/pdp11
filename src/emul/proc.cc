#include "proc.h"

Proc::Proc(int16_t stack, int16_t prog){
	memory = new Memory_unit();
	state = new Interstate();
	instruction = new Instructions();

	ticks_seqential = 0;
	ticks_pipelined = 0;

	this->stack = stack;
	this->prog = prog;
}

Proc::~Proc(){
	delete memory;
	delete state;
	delete instruction;
}

void Proc::step(){
	state->pc = memory->registers[7];
	int16_t instr;
	memory->read_word(state->pc, &instr);
	entry = &(instruction->decode[instr]);

	entry->fetch(state, memory, entry);
	entry->execute(state, entry);
	entry->writeback(state, memory, entry);
}
