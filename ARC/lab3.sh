#!/bin/bash 
#PBS -N LAB_3 
#PBS -q bitpedu
#PBS -o lab3.out 
#PBS -e lab3.err 
#PBS -l walltime=00:01:00
cd $PBS_O_WORKDIR
g++ lab3.cpp
./a.out
