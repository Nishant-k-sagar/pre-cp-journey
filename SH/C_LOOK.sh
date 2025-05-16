#!/bin/bash

# Function to perform C-LOOK on the request
# array starting from the given head
CLOOK() {
    local -n arr=$1
    local head=$2
    local seek_count=0
    local distance
    local cur_track
    local left=()
    local right=()
    local seek_sequence=()

    # Tracks on the left of the
    # head will be serviced when
    # once the head comes back
    # to the beginning (left end)
    for i in "${arr[@]}"; do
        if [ "$i" -lt "$head" ]; then
            left+=("$i")
        elif [ "$i" -gt "$head" ]; then
            right+=("$i")
        fi
    done

    # Sorting left and right vectors
    left=($(printf '%s\n' "${left[@]}" | sort -n))
    right=($(printf '%s\n' "${right[@]}" | sort -n))

    # First service the requests
    # on the right side of the
    # head
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

    # Once reached the right end
    # jump to the last track that
    # is needed to be serviced in
    # left direction
    seek_count=$((seek_count + (left[0] - head)))
    head=${left[0]}

    # Now service the requests again
    # which are left
    for i in "${left[@]}"; do
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

        # Accessed track is now the new head
        head=$cur_track
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

echo "Initial position of head: $head"
CLOOK arr head
