#!/bin/bash

BEGIN=$(date +%s)
for ((i = 0 ; i < 1000 ; i++)); 
do
    cat 128k.txt
done | ./percentile 95 > /dev/null
END=$(date +%s)
echo "It took "$((END-BEGIN))" seconds to complete"