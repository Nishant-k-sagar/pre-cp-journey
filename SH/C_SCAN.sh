#!/bin/bash

# Function to perform C-SCAN disk scheduling
CSCAN() {
    local -n arr=$1
    local head=$2
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
    left+=(0)
    right+=($((disk_size - 1)))

    # Tracks on the left of the head will be serviced when
    # once the head comes back to the beginning (left end).
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

    # First service the requests on the right side of the head
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

        # Accessed track is now new head
        head=$cur_track
    done

    # Once reached the right end, jump to the beginning
    head=0

    # Adding seek count for head returning from 199 to 0
    seek_count=$((disk_size - 1))

    # Now service the requests again which are left
    for ((i = 0; i < ${#left[@]}; i++)); do
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

echo "Initial position of head: $head"
CSCAN arr head
