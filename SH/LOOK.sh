#!/bin/bash

# Function to perform LOOK disk scheduling
LOOK() {
    local -n arr=$1
    local head=$2
    local direction=$3
    local seek_count=0
    local distance
    local cur_track
    local left=()
    local right=()
    local seek_sequence=()

    # Appending values which are currently at left and right
    # direction from the head.
    for i in "${arr[@]}"; do
        if [ "$i" -lt "$head" ]; then
            left+=("$i")
        elif [ "$i" -gt "$head" ]; then
            right+=("$i")
        fi
    done

    # Sorting left and right vectors for servicing tracks in the
    # correct sequence.
    left=($(printf '%s\n' "${left[@]}" | sort -n))
    right=($(printf '%s\n' "${right[@]}" | sort -n))

    # Run the while loop two times.
    # One by one scanning right and left side of the head.
    local run=2
    while ((run--)); do
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
            # Reversing the direction
            direction="right"
        elif [ "$direction" == "right" ]; then
            for i in "${right[@]}"; do
                cur_track=$i

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
            # Reversing the direction
            direction="left"
        fi
    done

    echo "Total number of seek operations = $seek_count"
    echo "Seek Sequence is:"

    # Print the seek sequence
    for i in "${seek_sequence[@]}"; do
        echo "$i"
    done
}

# Main code
arr=(176 79 34 60 92 11 41 114)
head=50
direction="right"

echo "Initial position of head: $head"
LOOK arr head direction
