#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bbobStructures.h"
#include "benchmarksdeclare.h"

extern TwoDoubles f101(double* x);
extern TwoDoubles f102(double* x);
extern TwoDoubles f103(double* x);
extern TwoDoubles f104(double* x);
extern TwoDoubles f105(double* x);
extern TwoDoubles f106(double* x);
extern TwoDoubles f107(double* x);
extern TwoDoubles f108(double* x);
extern TwoDoubles f109(double* x);
extern TwoDoubles f110(double* x);
extern TwoDoubles f111(double* x);
extern TwoDoubles f112(double* x);
extern TwoDoubles f113(double* x);
extern TwoDoubles f114(double* x);
extern TwoDoubles f115(double* x);
extern TwoDoubles f116(double* x);
extern TwoDoubles f117(double* x);
extern TwoDoubles f118(double* x);
extern TwoDoubles f119(double* x);
extern TwoDoubles f120(double* x);
extern TwoDoubles f121(double* x);
extern TwoDoubles f122(double* x);
extern TwoDoubles f123(double* x);
extern TwoDoubles f124(double* x);
extern TwoDoubles f125(double* x);
extern TwoDoubles f126(double* x);
extern TwoDoubles f127(double* x);
extern TwoDoubles f128(double* x);
extern TwoDoubles f129(double* x);
extern TwoDoubles f130(double* x);
extern void initbenchmarkshelper();
extern void setNoiseSeed(unsigned int _seed, unsigned int _seedn);
extern void initbenchmarksnoisy(void);

int main(int argc, char** argv) {
    if (argc < 5) {
        printf("Usage: bbfunc <instance> <seed> <function_name> <dimensions D> <xopt_1> ... <xopt_D> <x_1> ... <x_D>\n");
        return 0;
    }
    char* instance = argv[1];
    int seed = atoi(argv[2]);
    char* func_name = argv[3];
    DIM = atoi(argv[4]);
    
    setNoiseSeed(seed, seed);
    
    if (argc < 5 + 2*DIM) {
        printf("Usage: bbfunc <instance> <seed> <function_name> <dimensions D> <xopt_1> ... <xopt_D> <x_1> ... <x_D>\n");
        return 0;
    }
    
    initbenchmarkshelper();
    initbenchmarksnoisy();
    
    for (int i = 0; i < DIM; i++) Xopt[i] = strtod(argv[5 + i], NULL);
    
    double* x = malloc(sizeof(double) * 2);
    for (int i = 0; i < DIM; i++) x[i] = strtod(argv[5 + DIM + i], NULL);
    
    TwoDoubles res;
    if (strcmp(func_name, "f101") == 0) {
        res = f101(x);
    } else if (strcmp(func_name, "f102") == 0) {
        res = f102(x);
    } else if (strcmp(func_name, "f103") == 0) {
        res = f103(x);
    } else if (strcmp(func_name, "f104") == 0) {
        res = f104(x);
    } else if (strcmp(func_name, "f105") == 0) {
        res = f105(x);
    } else if (strcmp(func_name, "f106") == 0) {
        res = f106(x);
    } else if (strcmp(func_name, "f107") == 0) {
        res = f107(x);
    } else if (strcmp(func_name, "f108") == 0) {
        res = f108(x);
    } else if (strcmp(func_name, "f109") == 0) {
        res = f109(x);
    } else if (strcmp(func_name, "f110") == 0) {
        res = f110(x);
    } else if (strcmp(func_name, "f111") == 0) {
        res = f111(x);
    } else if (strcmp(func_name, "f112") == 0) {
        res = f112(x);
    } else if (strcmp(func_name, "f113") == 0) {
        res = f113(x);
    } else if (strcmp(func_name, "f114") == 0) {
        res = f114(x);
    } else if (strcmp(func_name, "f115") == 0) {
        res = f115(x);
    } else if (strcmp(func_name, "f116") == 0) {
        res = f116(x);
    } else if (strcmp(func_name, "f117") == 0) {
        res = f117(x);
    } else if (strcmp(func_name, "f118") == 0) {
        res = f118(x);
    } else if (strcmp(func_name, "f119") == 0) {
        res = f119(x);
    } else if (strcmp(func_name, "f120") == 0) {
        res = f120(x);
    } else if (strcmp(func_name, "f121") == 0) {
        res = f121(x);
    } else if (strcmp(func_name, "f122") == 0) {
        res = f122(x);
    } else if (strcmp(func_name, "f123") == 0) {
        res = f123(x);
    } else if (strcmp(func_name, "f124") == 0) {
        res = f124(x);
    } else if (strcmp(func_name, "f125") == 0) {
        res = f125(x);
    } else if (strcmp(func_name, "f126") == 0) {
        res = f126(x);
    } else if (strcmp(func_name, "f127") == 0) {
        res = f127(x);
    } else if (strcmp(func_name, "f128") == 0) {
        res = f128(x);
    } else if (strcmp(func_name, "f129") == 0) {
        res = f129(x);
    } else if (strcmp(func_name, "f130") == 0) {
        res = f130(x);
    } else {
        printf("Unrecognized function\n");
        return 0;
    }
    
    printf("%f\n", res.Fval);
    
    return 0;
}
