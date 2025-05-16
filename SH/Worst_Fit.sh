#!/bin/bash

# Function to allocate memory to blocks as per worst fit algorithm
worstFit() {
    local -n blockSize=$1
    local -n processSize=$2
    local n=${#processSize[@]}
    local allocation=()

    # Initialize allocation array
    for ((i=0; i<n; i++)); do
        allocation[i]=-1
    done

    # Pick each process and find suitable blocks according to its size
    for ((i=0; i<n; i++)); do
        local wstIdx=-1
        for ((j=0; j<${#blockSize[@]}; j++)); do
            if ((blockSize[j] >= processSize[i])); then
                if ((wstIdx == -1)); then
                    wstIdx=j
                elif ((blockSize[wstIdx] < blockSize[j])); then
                    wstIdx=j
                fi
            fi
        done

        # If a block is found for the current process
        if ((wstIdx != -1)); then
            # Allocate block j to process i
            allocation[i]=$((wstIdx + 1))
            # Reduce available memory in this block
            blockSize[wstIdx]=$((blockSize[wstIdx] - processSize[i]))
        fi
    done

    # Print process allocation details
    echo -e "Process No.\tProcess Size\tBlock no."
    for ((i=0; i<n; i++)); do
        echo -ne " $((i+1))\t\t${processSize[i]}\t\t"
        if ((allocation[i] != -1)); then
            echo "${allocation[i]}"
        else
            echo "Not Allocated"
        fi
    done
}

# Driver code
blockSize=(100 200 300 400 500 600)
processSize=(426)
worstFit blockSize processSize
