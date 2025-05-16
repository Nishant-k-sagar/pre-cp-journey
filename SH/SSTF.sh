#!/bin/bash

# Calculates difference of each track number with the head position
calculatedifference() {
    local -n request=$1
    local head=$2
    local -n diff=$3
    local n=$4

    for ((i = 0; i < n; i++)); do
        diff[$i,0]=$(( head - request[$i] ))
        diff[$i,1]=0
        # Absolute difference
        if (( diff[$i,0] < 0 )); then
            diff[$i,0]=$(( -diff[$i,0] ))
        fi
    done
}

# Find unaccessed track which is at minimum distance from head
findMIN() {
    local -n diff=$1
    local n=$2

    local index=-1
    local minimum=1000000000

    for ((i = 0; i < n; i++)); do
        if (( !diff[$i,1] && minimum > diff[$i,0] )); then
            minimum=${diff[$i,0]}
            index=$i
        fi
    done

    echo $index
}

shortestSeekTimeFirst() {
    local -n request=$1
    local head=$2
    local n=$3

    if (( n == 0 )); then
        return
    fi

    # Create array to store differences and track accessed flag
    local diff=()
    for ((i = 0; i < n; i++)); do
        diff[$i,0]=0
        diff[$i,1]=0
    done

    local seekcount=0
    local seeksequence=()

    for ((i = 0; i < n; i++)); do
        seeksequence[$i]=$head
        calculatedifference request head diff n
        local index=$(findMIN diff n)
        diff[$index,1]=1
        (( seekcount += diff[$index,0] ))
        head=${request[$index]}
    done
    seeksequence[$n]=$head

    echo "Total number of seek operations = $seekcount"
    echo "Seek sequence is :"
    for ((i = 0; i <= n; i++)); do
        echo "${seeksequence[$i]}"
    done
}

# Main code
proc=(176 79 34 60 92 11 41 114)
n=${#proc[@]}

shortestSeekTimeFirst proc 50 $n
