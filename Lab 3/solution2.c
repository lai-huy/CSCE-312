/*
	Sample Solution-2 for Lab-1, Problem-4
*/

unsigned int input;  
unsigned int output;  


//For input interface implementation
inline void read_inputs_from_ip_if(){
	printf("input signal: ");
	scanf("%d", &input);
}

//For output interface implementation
inline void write_output_to_op_if(){
	printf("output signal: %d\n", output);
}


//The code segment which implements the decision logic
inline void control_action(){

	switch (input & 0xff)
	{
		case 5:
		case 7:
		case 13:
			output = 1;
		break;

		case 32:
		case 34:
		case 36:
		case 38:
		case 40:
		case 42:
		case 44:
		case 46:
		case 49:
		case 51:
			output = 2;
		break;

		case 53:
		case 55:
			output = 3;
		break;

		case 57:
		case 59:
			output = 2;
		break;

		case 61:
			output = 3;
		break;

		case 63:
			output = 2;
		break;

		case 69:
		case 71:
		case 77:
			output = 1;
		break;

		case 96:
		case 98:
		case 100:
		case 102:
		case 104:
		case 106:
		case 108:
		case 110:
		case 113:
		case 115:
			output = 2;
		break;

		case 117:
		case 119:
			output = 3;
		break;
		
		case 121:
		case 123:
		case 127:
			output = 2;
		break;

		case 133:
		case 135:
		case 141:
			output = 1;
		break;
		
		case 160:
		case 162:
		case 164:
		case 166:
		case 168:
		case 170:
		case 172:
		case 174:
		case 177:
		case 179:
			output = 2;
		break;

		case 181:
		case 183:
			output = 3;
		break;

		case 185:
		case 187:
		case 191:
			output = 2;
		break;
		
		case 192:
		case 193:
		case 194:
		case 195:
		case 196:
			output = 4;
		break;

		case 197:
			output = 5;
		break;

		case 198:
			output = 4;
		break;

		case 199:
			output = 5;
		break;

		case 200:
		case 201:
		case 202:
		case 203:
		case 204:
			output = 4;
		break;

		case 205:
			output = 5;
		break;
		
		case 206:
		case 207:
		case 208:
		case 209:
		case 210:
		case 211:
		case 212:
		case 213:
		case 214:
		case 215:
		case 216:
		case 217:
		case 218:
		case 219:
		case 220:
		case 221:
		case 222:
		case 223:
			output = 4;
		break;

		case 224:
			output = 6;
		break;

		case 225:
			output = 4;
		break;

		case 226:
			output = 6;
		break;
		
		case 227:
			output = 4;
		break;

		case 228:
			output = 6;
		break;

		case 229:
			output = 4;
		break;

		case 230:
			output = 6;
		break;

		case 231:
			output = 4;
		break;

		case 232:
			output = 6;
		break;

		case 233:
			output = 4;
		break;
		
		case 234:
			output = 6;
		break;

		case 235:
			output = 4;
		break;

		case 236:
			output = 6;
		break;

		case 237:
			output = 4;
		break;

		case 238:
			output = 6;
		break;

		case 239:
		case 240:
			output = 4;
		break;

		case 241:
			output = 6;
		break;

		case 242:
			output = 4;
		break;

		case 243:
			output = 6;
		break;

		case 244:
			output = 4;
		break;

		case 245:
			output = 7;
		break;

		case 246:
			output = 4;
		break;

		case 247:
			output = 7;
		break;

		case 248:
			output = 4;
		break;

		case 249:
			output = 6;
		break;

		case 250:
			output = 4;
		break;

		case 251:
			output = 6;
		break;

		case 252:
			output = 5;
		break;

		case 253:
			output = 7;
		break;

		case 254:
			output = 4;
		break;

		case 255:
			output = 6;
		break;
	}

}


//The main program
int main(int argc, char *argv[])
{
	
	/*The main control loop which keeps the system alive and responsive for ever, 
	until the system is powered off */
	for (; ; )
	{
		input  = 0;
        output = 0;
		read_inputs_from_ip_if();
		control_action();
		write_output_to_op_if();
	}
	
	return 0;
}
