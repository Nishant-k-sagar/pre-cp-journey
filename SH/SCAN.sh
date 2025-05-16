#!/bin/bash

# Function to perform SCAN disk scheduling
SCAN() {
    local -n arr=$1
    local head=$2
    local direction=$3
    local size=${#arr[@]}
    local disk_size=200
    local seek_count=0
    local distance
    local cur_track
    local left=()
    local right=()
    local seek_sequence=()

    # Appending end values which have to be visited
    # before reversing the direction
    if [ "$direction" == "left" ]; then
        left+=(0)
    elif [ "$direction" == "right" ]; then
        right+=($((disk_size - 1)))
    fi

    # Populate left and right vectors
    for ((i = 0; i < size; i++)); do
        if [ "${arr[i]}" -lt "$head" ]; then
            left+=("${arr[i]}")
        elif [ "${arr[i]}" -gt "$head" ]; then
            right+=("${arr[i]}")
        fi
    done

    # Sort left and right vectors
    left=($(printf '%s\n' "${left[@]}" | sort -n))
    right=($(printf '%s\n' "${right[@]}" | sort -n))

    # Run the while loop two times.
    # One by one scanning right and left of the head
    run=2
    while [ $run -gt 0 ]; do
        if [ "$direction" == "left" ]; then
            for ((i = ${#left[@]} - 1; i >= 0; i--)); do
                cur_track=${left[i]}
                # Appending current track to seek sequence
                seek_sequence+=("$cur_track")

                # Calculate absolute distance
                distance=$((cur_track - head))
                if [ "$distance" -lt 0 ]; then
                    distance=$(( -distance ))
                fi

                # Increase the total count
                seek_count=$((seek_count + distance))

                # Accessed track is now the new head
                head=$cur_track
            done
            direction="right"
        elif [ "$direction" == "right" ]; then
            for ((i = 0; i < ${#right[@]}; i++)); do
                cur_track=${right[i]}
                # Appending current track to seek sequence
                seek_sequence+=("$cur_track")

                # Calculate absolute distance
                distance=$((cur_track - head))
                if [ "$distance" -lt 0 ]; then
                    distance=$(( -distance ))
                fi

                # Increase the total count
                seek_count=$((seek_count + distance))

                # Accessed track is now the new head
                head=$cur_track
            done
            direction="left"
        fi
        ((run--))
    done

    echo "Total number of seek operations = $seek_count"
    echo "Seek Sequence is:"

    # Print the seek sequence
    for ((i = 0; i < ${#seek_sequence[@]}; i++)); do
        echo "${seek_sequence[i]}"
    done
}

# Main code
arr=(176 79 34 60 92 11 41 114)
head=50
direction="left"

SCAN arr head direction
