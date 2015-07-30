#! /bin/sh

for i in 2 5 10
do
    echo "\n-------------------- Trying with $i --------------------\n"
    build/sub_set $i
done

for i in 50 100 200 500 1000
do
    echo "\n-------------------- Trying with $i --------------------\n"
    build/sub_set $i 2> /dev/null
done
