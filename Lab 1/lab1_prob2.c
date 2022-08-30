#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
    FILE* file;
    if ((file=fopen("lab1_prob2_out.txt", "w")) == NULL) {
        printf("Error opening the file, so exiting\n");
        exit(1);
    }

    fprintf(file, "Size of unsigned int is %lu.\n", sizeof(unsigned int));
    fprintf(file, "Size of double is %lu.\n", sizeof(double));
    fprintf(file, "Size of long is %lu.\n", sizeof(long));
    fprintf(file, "Size of long long is %lu.\n", sizeof(long long));
    fprintf(file, "Size of char is %lu.\n", sizeof(char));
    fprintf(file, "Size of float is %lu.\n", sizeof(float));
    fprintf(file, "Size of struct timeval is %lu.\n", sizeof(struct timeval));

    return 0;
}