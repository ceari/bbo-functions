#include <stdio.h>
#include <stdlib.h>

#include "bbobStructures.h"
#include "benchmarksdeclare.h"


extern TwoDoubles f110(double* x);
extern void initbenchmarkshelper();
extern void setNoiseSeed(unsigned int _seed, unsigned int _seedn);

int main(int argc, char** argv) {
    char* func_name = argv[1];
    DIM = atoi(argv[2]);
    DIM = 2;
    
    setNoiseSeed(1234, 12345);
    
    initbenchmarkshelper();
    initbenchmarksnoisy();
    
    Xopt[0] = 1.34;
    Xopt[1] = 1.34;

    double* x = malloc(sizeof(double) * 2);
    x[0] = 4.34;
    x[1] = 1.34;
    TwoDoubles res = f110(x);
    
    printf("%f %f\n", res.Fval, res.Ftrue);
    
    return 0;
}
