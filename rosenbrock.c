#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_randist.h>

const double x_opt = 1.34;
const double f_opt = 0;
    
gsl_rng* rng;

double max(double a, double b) {
    return a >= b ? a : b;
}

double fGN(double f, double beta) {
    return f * exp(beta * gsl_ran_gaussian(rng, 1.0));
}

double f_pen(double* x, int D) {
    double res = 0;
    for (int i = 0; i < D; i++) res += max(0, abs(x[i]) - 5) * max(0, abs(x[i]) - 5);
    return 100 * res;
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: rosenbrock <instance> <seed> <dimensions D> <x_1> <x_2> ... <x_D>\n");
        return 0;
    }
    char* instance = argv[1];
    int seed = atoi(argv[2]);

    FILE* fd = fopen(instance, "r");
    double instance_val = 1.0;
    fscanf(fd, "%lf", &instance_val);
    
    rng = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(rng, seed);
    
    int D = atoi(argv[3]);
    if (argc < 4 + D) {
        printf("Usage: rosenbrock <instance> <seed> <dimensions D> <x_1> <x_2> ... <x_D>\n");
        return 0;
    }
    double* x = (double*) malloc(sizeof(double) * D);
    double* z = (double*) malloc(sizeof(double) * D);
    
    for (int i = 0; i < D; i++) {
        x[i] = strtod(argv[4+i], NULL);
        z[i] = max(1, sqrt(D) / 8) * (x[i] - x_opt) + 1;
    }
    
    double f_rosenbrock = 0;
    for (int i = 1; i <= D-1; i++) {
        f_rosenbrock += 100 * (z[i-1]*z[i-1] - z[i]) * (z[i-1]*z[i-1] - z[i]) + (z[i-1] - 1) * (z[i-1] - 1);
    }
    
    double f_110 = fGN(f_rosenbrock, 1) + f_pen(x, D) + f_opt + instance_val;
    
    printf("%f\n", f_110);
    
    free(x);
    free(z);
    return 0;
}
