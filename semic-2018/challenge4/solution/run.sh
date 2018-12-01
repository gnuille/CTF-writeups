#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Usage:"
	echo "./run.sh target [omp]"
	exit 1
	
fi

make clean
make target=$1 $2

if [ $# -eq 2 ]
then
	export OMP_NUM_THREADS=96
	./solve_omp.bin
else
	./solve.bin
fi
