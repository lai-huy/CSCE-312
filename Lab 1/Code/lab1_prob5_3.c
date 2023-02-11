//CSCE 312: Lab-1 Problem-5 framework
// This is version-2; bugfix for timediff
/* ***   README   **** */
/*This file is a framework: i.e. there is no actual code whose execution time will be
  measured. You need to populate the appropriate functions with the code that you wrote
  for the previous problems in order to get useful data.

  Turning in this file without your code will result in zero points being awarded for this problem.

  run this file as: gcc FileName.c -o ExecutableName -lrt

*/
#include <stdio.h>
#include <time.h>

// Macro definitions to ensure portablity between both sun.cs and linux.cs

#if defined(sun)
#define CLOCKNAME CLOCK_HIGHRES

#else
#define CLOCKNAME CLOCK_PROCESS_CPUTIME_ID
#endif

unsigned int driver_on_seat;
unsigned int driver_seat_belt_fastened;
unsigned int engine_running;
unsigned int doors_closed;
unsigned int key_in_car;
unsigned int door_lock_lever;
unsigned int brake_pedal;
unsigned int car_moving;

unsigned int bell = 0;
unsigned int door_lock_actu = 0;
unsigned int brake_actu = 0;

void read_inputs_from_ip_if() {
    printf("Is the Driver on the Seat?\t");
    scanf("%u", &driver_on_seat);

    printf("Is the Driver Seat Belt Fastened?\t");
    scanf("%u", &driver_seat_belt_fastened);

    printf("Is the Enginer Running?\t");
    scanf("%u", &engine_running);

    printf("Are the Doors Closed?\t");
    scanf("%u", &doors_closed);

    printf("Is the Key in Car?\t");
    scanf("%u", &key_in_car);

    printf("Is the Door Lock Leaver activated?\t");
    scanf("%u", &door_lock_lever);

    printf("Is the Break Pedal activated?\t");
    scanf("%u", &brake_pedal);

    printf("Is the Car Moving?\t");
    scanf("%u", &car_moving);
}

void write_output_to_op_if() {
    printf("\n(BELL, DLA, BA):\t%u %u %u\n", bell, door_lock_actu, brake_actu);
}

// The code segment which implements the decision logic
void control_action() {
    if (engine_running && !doors_closed)
        bell = 1;
    if (engine_running && !driver_seat_belt_fastened)
        bell = 1;
    else
        bell = 0;

    if (!driver_on_seat && key_in_car)
        door_lock_actu = 0;
    if (driver_on_seat && door_lock_lever)
        door_lock_actu = 1;
    else
        door_lock_actu = 0;

    if (brake_pedal && car_moving)
        brake_actu = 1;
    else
        brake_actu = 0;
}


/* ---     You should not have to modify anything below this line ---------*/

/*timespec diff from
http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/
*/
struct timespec diff(struct timespec start, struct timespec end) {
    struct timespec temp;
    //the if condition handles time stamp end being smaller than than
    //time stamp start which could lead to negative time.

    if ((end.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}

int main(int argc, char* argv[]) {
    unsigned int cpu_mhz;
    unsigned long long int begin_time, end_time;
    struct timespec timeDiff, timeres;
    struct timespec time1, time2, calibrationTime;

    clock_gettime(CLOCKNAME, &time1);
    clock_gettime(CLOCKNAME, &time2);
    calibrationTime = diff(time1, time2); //calibration for overhead of the function calls
    clock_getres(CLOCKNAME, &timeres);  // get the clock resolution data

    read_inputs_from_ip_if(); // get the sensor inputs

    clock_gettime(CLOCKNAME, &time1); // get current time
    control_action();                 // process the sensors
    clock_gettime(CLOCKNAME, &time2);   // get current time

    write_output_to_op_if();    // output the values of the actuators

    timeDiff = diff(time1, time2); // compute the time difference

    printf("Timer Resolution = %u nanoseconds \n ", (unsigned int) timeres.tv_nsec);
    printf("Calibrartion time = %u seconds and %u nanoseconds \n ", (unsigned int) calibrationTime.tv_sec, (unsigned int) calibrationTime.tv_nsec);
    printf("The measured code took %u seconds and ", (unsigned int) (timeDiff.tv_sec - calibrationTime.tv_sec));
    printf(" %u nano seconds to run \n", (unsigned int) (timeDiff.tv_nsec - calibrationTime.tv_nsec));

    return 0;
}
