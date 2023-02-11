// File named "lab5_prob6.c"
#include <stdio.h>
int very_fast_function(int i)
{
	if ((i * 64 + 1) > 1024)
		return i++;
	else
		return 0;
	__asm__(
		"rrmovq %rbx, %rcx"
		"rraddq %rcx, %rcx\n\t"
		"rraddq %rcx, %rcx\n\t"
		"rraddq %rcx, %rcx\n\t"
		"rraddq %rcx, %rcx\n\t"
		"rraddq %rcx, %rcx\n\t"
		"iraddq $0x1, %rcx\n\t"
		"isubq $0x400, %rcx\n\t"
		"jle else\n\t"
		"iraddq $0x1, %rbx\n\t"
		"rrmovq %rbx, %rax\n\t"
		"ret\n\t"
		"else:\n\t"
		"irmovq $0x0, %rax\n\t"
		"ret\n\t");
}

int main(int argc, char *argv[])
{
	int i;
	i = 40;
	printf("The function value of  i is %d\n", very_fast_function(i));
	return 0;
}
