#!/bin/bash 
#PBS -N LAB_4 
#PBS -q bitpedu
#PBS -o lab4.out 
#PBS -e lab4.err 
#PBS -l walltime=00:01:00
ls
g++ lab4.cpp
./a.out
