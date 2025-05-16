#!/bin/bash

# Function to perform FCFS disk scheduling
FCFS() {
    local -n arr=$1
    local head=$2
    local size=${#arr[@]}
    local seek_count=0
    local distance
    local cur_track

    for ((i = 0; i < size; i++)); do
        cur_track=${arr[i]}
        distance=$(( cur_track - head ))

        # Absolute distance
        if (( distance < 0 )); then
            distance=$(( -distance ))
        fi

        # Increase the total count
        seek_count=$(( seek_count + distance ))

        # Accessed track is now new head
        head=$cur_track
    done

    echo "Total number of seek operations = $seek_count"
    echo "Seek Sequence is:"

    # Print the seek sequence
    for ((i = 0; i < size; i++)); do
        echo "${arr[i]}"
    done
}

# Main code
arr=(176 79 34 60 92 11 41 114)
head=50

FCFS arr head
