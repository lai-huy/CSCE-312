/*
	Sample Solution-1 for Lab-1, Problem-4
*/

unsigned int input;
unsigned int output;


//For input interface implementation
inline void read_inputs_from_ip_if() {
	printf("input signal: ");
	scanf("%d", &input);
}

//For output interface implementation
inline void write_output_to_op_if() {
	printf("output signal: %d\n", output);
}


//The code segment which implements the decision logic
inline void control_action() {
	//Requirement 1, 2, 3
	switch (input & 0xf) {
	case 5:
	case 7:
	case 13:
		output = 0x1;
	}

	//Requirement 4
	switch (input & 0x31) {
	case 32:
	case 49:
		output = output | 0x2;
	}

	//Requirement 5
	if ((input & 0xc0) == 0xc0)
		output = output | 0x4;

}


//The main program
int main(int argc, char* argv[]) {

	/*The main control loop which keeps the system alive and responsive for ever,
	until the system is powered off */
	for (; ; ) {
		input = 0;
		output = 0;
		read_inputs_from_ip_if();
		control_action();
		write_output_to_op_if();

	}

	return 0;
}
