all: bbfunc bbcost

clean:
	rm -f bbfunc bbcost

bbfunc: bbfunc.c
	gcc benchmarkshelper.c benchmarksdeclare.c benchmarksnoisy.c bbfunc.c -std=c99 -static -lm -O2 -g -o bbfunc

bbcost: bbcost.c
	gcc bbcost.c -std=c99 -O2 -g -static -o bbcost
