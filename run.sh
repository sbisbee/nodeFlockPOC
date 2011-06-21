#!/bin/sh

NUM_THREADS=10

rm balance

for i in `seq 0 $NUM_THREADS`; do
  node ./index.js $i &
done
