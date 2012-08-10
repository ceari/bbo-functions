all: rosenbrock

clean:
		rm -f rosenbrock

rosenbrock:
		gcc -std=c99 -lm -lgsl -lgslcblas -O2 -o rosenbrock rosenbrock.c
