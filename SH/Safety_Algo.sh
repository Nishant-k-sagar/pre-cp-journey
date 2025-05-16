#!/bin/bash

# Function to find the need of each process
calculateNeed() {
    for ((i = 0; i < P; i++)); do
        for ((j = 0; j < R; j++)); do
            # Need of instance = maxm instance - allocated instance
            need[$i,$j]=$(( maxm[$i,$j] - allot[$i,$j] ))
        done
    done
}

# Function to find if the system is in a safe state
isSafe() {
    calculateNeed

    # Mark all processes as unfinished
    declare -a finish=(0 0 0 0 0)

    # To store safe sequence
    declare -a safeSeq

    # Make a copy of available resources
    declare -a work=("${avail[@]}")

    # While all processes are not finished or the system is not in a safe state
    count=0
    while ((count < P)); do
        # Find a process which is not finished and whose needs can be satisfied with current resources
        found=false
        for ((p = 0; p < P; p++)); do
            if ((finish[$p] == 0)); then
                j=0
                for ((j = 0; j < R; j++)); do
                    if ((need[$p,$j] > work[$j])); then
                        break
                    fi
                done

                # If all needs of p were satisfied
                if ((j == R)); then
                    # Add the allocated resources of current process to the available resources
                    for ((k = 0; k < R; k++)); do
                        work[$k]=$(( work[$k] + allot[$p,$k] ))
                    done

                    # Add this process to the safe sequence
                    safeSeq[$count]=$p

                    # Mark this process as finished
                    finish[$p]=1

                    found=true
                    ((count++))
                fi
            fi
        done

        # If we could not find a next process in the safe sequence
        if [[ $found == false ]]; then
            echo "System is not in a safe state"
            return 1
        fi
    done

    # If system is in safe state, print the safe sequence
    echo "System is in a safe state."
    echo "Safe sequence is: ${safeSeq[@]}"
    return 0
}

# Main code
read -p "Enter number of processes: " P
read -p "Enter number of resources: " R

declare -a processes
declare -a avail
declare -A maxm
declare -A allot

# Taking input for available instances of resources
echo "Enter available instances of resources:"
for ((i = 0; i < R; i++)); do
    read -p "Resource $((i+1)): " avail[$i]
done

# Taking input for maximum resources that can be allocated to processes
echo "Enter maximum resources that can be allocated to processes:"
for ((i = 0; i < P; i++)); do
    for ((j = 0; j < R; j++)); do
        read -p "Process $((i+1)), Resource $((j+1)): " maxm[$i,$j]
    done
done

# Taking input for resources allocated to processes
echo "Enter resources allocated to processes:"
for ((i = 0; i < P; i++)); do
    for ((j = 0; j < R; j++)); do
        read -p "Process $((i+1)), Resource $((j+1)): " allot[$i,$j]
    done
done

# Check if the system is in a safe state
isSafe
