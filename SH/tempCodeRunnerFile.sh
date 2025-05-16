#!/bin/bash

# Function to find the worst fit for a process
worstFit() {
    local -a blockSize=("$@")
    local m=${#blockSize[@]}
    local -a processSize=(212 417 112 426)  # Example process sizes

    local -a allocation=()
    for ((i = 0; i < ${#processSize[@]}; i++)); do
        local wstIdx=-1
        for ((j = 0; j < m; j++)); do
            if ((blockSize[j] >= processSize[i])); then
                if [[ $wstIdx == -1 || blockSize[wstIdx] < blockSize[j] ]]; then
                    wstIdx=$j
                fi
            fi
        done

        if [[ $wstIdx != -1 ]]; then
            allocation[i]=$wstIdx
            blockSize[wstIdx]=$((blockSize[wstIdx] - processSize[i]))
        fi
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
worstFit 100 500 200 300 600
