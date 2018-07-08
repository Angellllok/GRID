#!/bin/bash
#PBS -l walltime=00:01:00
#PBS -N lab1
#PBS -q bitpedu
#PBS -o lab1.out
#PBS -e lab1.err
cd $PBS_O_WORKDIR
g++ GridApplication.cpp
./a.out