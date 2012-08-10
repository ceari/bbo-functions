all: rosenbrock cost_rosenbrock

clean:
	rm -f rosenbrock cost_rosenbrock

rosenbrock: rosenbrock.c
	gcc rosenbrock.c -std=c99 /usr/lib/libgsl.a /usr/lib/libgslcblas.a -lm -O2 -o rosenbrock

cost_rosenbrock: cost_rosenbrock.c
	gcc -static -std=c99 -O2 -o cost_rosenbrock cost_rosenbrock.c

