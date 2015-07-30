#! /bin/sh

for i in 2 3 4
do
    echo "\n-------------------- Trying with $i threads --------------------\n"
    build/sub_set $1 $i 2>/dev/null
done
