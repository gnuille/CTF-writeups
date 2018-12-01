CC=gcc

CFLAGS = -lcrypto
ifeq "$(target)" "test"
	CFLAGS+= -D TEST
endif

all: solve.bin

omp: solve_omp.bin

solve_omp.bin: solve.c
	$(CC) $< -o $@ $(CFLAGS) -fopenmp

solve.bin: solve.c
	$(CC) $< -o $@ $(CFLAGS) 

clean: 
	rm -f *.bin
