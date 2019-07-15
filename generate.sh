#!/bin/bash

for ((i = 0 ; i < 128000 ; i++)); 
do
    printf '%.5f\n' "$(printf '0x0.%04xp1' $RANDOM)"
done
