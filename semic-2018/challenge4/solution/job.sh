#!/bin/bash

echo "#!/bin/bash
#SBATCH --job-name=ctf_hash
#SBATCH --workdir=.
#SBATCH --output=ctf_hash.out
#SBATCH --error=ctf_hash.err
#SBATCH --time=03:00:00
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=96
#SBATCH --partition=thunder

./run.sh omp omp" > temp.run
sbatch < temp.run
rm temp.run

