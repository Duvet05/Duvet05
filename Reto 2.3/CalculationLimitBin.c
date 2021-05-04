/*Gonzalo Galvez Cortez (Duvet05): Reto 2.2*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
/*Initial condition, n must be an integer*/
int main(int argc, char** argv){
    int n =  atoi(argv[1]);
    printf("n value: %d\n", n);
    double fn_C, fn_ASM;
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);	
	fn_C = function_calculationBin(n);
	clock_gettime(CLOCK_REALTIME, &end);
    double total_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 10e9;
    printf("Time measured in C, using Binary Exponentiation Method:\n%0.10lf seconds.\n", total_time);
	printf("In C:       f(%d) = %0.10lf.\n", n, fn_C);
    clock_gettime(CLOCK_REALTIME, &start);	
	fn_ASM = function_calculationBinASM(n);
	clock_gettime(CLOCK_REALTIME, &end);
    total_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 10e9;
    printf("Time measured in ASM, using Binary Exponentiation Method:\n%0.10lf seconds.\n", total_time);
	printf("In ASM:     f(%d) = %0.10lf.\n", n, fn_ASM);
    return 0;
}

double function_calculationBin(int n){
    double base, x = 1;
    base = 1+(1.0/n);
    while(n != 0){
        if(n & 1)
            x *= base;
        base *= base;
        n >>= 1;
    }
    return x;
}