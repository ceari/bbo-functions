all: bbfunc

clean:
	rm -f bbfunc

bbfunc: bbfunc.c
	gcc benchmarkshelper.c benchmarksdeclare.c benchmarksnoisy.c bbfunc.c -std=c99 -lm -O2 -g -o bbfunc
