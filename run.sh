#!/bin/bash

for ((i = 0 ; i < 1000 ; i++)); 
do
    cat 128k.txt
done | ./percentile 95

