#!/bin/bash


function print_odd {
    for ((i = 1; i <= 10; i += 2)); do
        echo $i
        sleep 0.5
    done
}

function print_even {
    for ((i = 2; i <= 10; i += 2)); do
        echo $i
        sleep 0.5
    done
}


print_odd & 
pid1=$!

print_even &
pid2=$!


wait $pid1
wait $pid2