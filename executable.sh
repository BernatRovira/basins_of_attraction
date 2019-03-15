#!/bin/bash

N=500;     # Network size
gamma=100;  # Sigmoid steepness
beta=2.44;     # Coding level constant
theta=0;    # Excitatory threshold
temps=200;  # Simulation time
dt=0.01;    # Time interval
ham=7;      # IC hamming distance 

./do_adaptation $N $gamma $beta $theta $temps $dt $ham
