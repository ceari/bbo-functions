#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char* result_file = argv[1];
    FILE* fd = fopen(result_file, "r");
    double d;
    fscanf(fd, "%lf", &d);
    fgetc(fd);
    fscanf(fd, "%lf", &d);
    fscanf(fd, "%lf", &d);
    printf("%f\n", d);
    return 0;
}
