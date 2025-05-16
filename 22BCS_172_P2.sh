#!/bin/bash

calculateNeed() {
    for ((i = 0; i < P; i++)); do
        for ((j = 0; j < R; j++)); do
            
            need[$i,$j]=$(( maxm[$i,$j] - allot[$i,$j] ))
        done
    done
}

isSafe() {
    calculateNeed

    declare -a finish=(0 0 0)

    declare -a safeSeq

    declare -a work=("${avail[@]}")

    count=0
    while ((count < P)); do
        
        found=false
        for ((p = 0; p < P; p++)); do
            if ((finish[$p] == 0)); then
                j=0
                for ((j = 0; j < R; j++)); do
                    if ((need[$p,$j] > work[$j])); then
                        break
                    fi
                done

               
                if ((j == R)); then
                    
                    for ((k = 0; k < R; k++)); do
                        work[$k]=$(( work[$k] + allot[$p,$k] ))
                    done

                    
                    safeSeq[$count]=$p

                
                    finish[$p]=1

                    found=true
                    ((count++))
                fi
            fi
        done

        if [[ $found == false ]]; then
            echo "System is not in a safe state"
            return 1
        fi
    done


    echo "System is in a safe state."
    echo "Safe sequence is: ${safeSeq[@]}"
    return 0
}
read -p "Enter number of processes: " P
read -p "Enter number of resources: " R

declare -a processes
declare -a avail
declare -A maxm
declare -A allot

echo "Enter available instances of resources:"
for ((i = 0; i < R; i++)); do
    read -p "Resource $((i+1)): " avail[$i]
done

echo "Enter maximum resources that can be allocated to processes:"
for ((i = 0; i < P; i++)); do
    for ((j = 0; j < R; j++)); do
        read -p "Process $((i+1)), Resource $((j+1)): " maxm[$i,$j]
    done
done

echo "Enter resources allocated to processes:"
for ((i = 0; i < P; i++)); do
    for ((j = 0; j < R; j++)); do
        read -p "Process $((i+1)), Resource $((j+1)): " allot[$i,$j]
    done
done

isSafe

