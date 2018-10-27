CFLAGS= -Wall -fpic -coverage -lm -std=c99

.PHONY: run
run:
	-./testme

testMe: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

randomTest: testme run
	gcov testme.c >> randomtestresults.out
	cat testme.c.gcov >> randomtestresults.out
