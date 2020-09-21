
void core_exception_entry(int num)
{
	/* check if in thread mode, check current exception priority */
	stack_push_word(APSR);
	stack_push_word(PC);
	stack_push_word(LR);
	stack_push_word(R12);
	stack_push_word(R3);
	stack_push_word(R2);
	stack_push_word(R1);
	stack_push_word(R0);
	
	LR = EXCEPTION_RETURN_ADDRESS; // FFFFFF9 or ...
	PC = vector_get(num);
	
	/* update machine status */
}

void core_exception_exit(void)
{
	
}
