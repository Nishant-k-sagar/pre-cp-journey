#!/bin/bash

# Function to perform First Fit allocation
firstFit() {
    local -a blockSize=("$@")
    local m=${#blockSize[@]}
    local -a processSize=(212 417 112 426)  # Example process sizes

    local -a allocation=()
    for ((i = 0; i < ${#processSize[@]}; i++)); do
        for ((j = 0; j < m; j++)); do
            if ((blockSize[j] >= processSize[i])); then
                allocation[i]=$j
                blockSize[j]=$((blockSize[j] - processSize[i]))
                break
            fi
        done
    done

    echo "Process No.    Process Size    Block no."
    for ((i = 0; i < ${#processSize[@]}; i++)); do
        local bidx=${allocation[i]:-}
        local bnum
        if [[ -n $bidx ]]; then
            bnum=$((bidx + 1))
        else
            bnum="Not Allocated"
        fi
        printf "%11d %12d %13s\n" "$((i + 1))" "${processSize[i]}" "$bnum"
    done
}

# Example usage
firstFit 100 500 200 300 600
