#!/bin/bash

calculate_optimal_schedule() {
    local n=$1
    local -n arrival_time=$2
    local -n burst_time=$3

    local total_turnaround_time=0
    local completion_time=0

    declare -A completion_times

    # Initialize an array to track whether a process has been scheduled
    declare -a scheduled
    for ((i=1; i<=$n; i++)); do
        scheduled[$i]=0
    done

    # Sort processes based on arrival time
    for ((i=1; i<=$n; i++)); do
        for ((j=$i+1; j<=$n; j++)); do
            if ((arrival_time[$i] > arrival_time[$j])); then
                # Swap arrival time
                temp=${arrival_time[$i]}
                arrival_time[$i]=${arrival_time[$j]}
                arrival_time[$j]=$temp

                # Swap burst time
                temp=${burst_time[$i]}
                burst_time[$i]=${burst_time[$j]}
                burst_time[$j]=$temp
            fi
        done
    done

    # Calculate completion times for each process
    for ((i=1; i<=$n; i++)); do
        completion_time=$((completion_time + burst_time[$i]))
        completion_times[$i]=$completion_time
    done

    # Calculate turnaround time for each process
    for ((i=1; i<=$n; i++)); do
        turnaround_time=$((completion_times[$i] - arrival_time[$i]))
        total_turnaround_time=$((total_turnaround_time + turnaround_time))
    done

    # Calculate average turnaround time
    avg_turnaround_time=$(bc <<< "scale=2; $total_turnaround_time / $n")
    echo "Average Turnaround Time: $avg_turnaround_time"
}

# Input data
declare -a arrival_time=(0.0 0.6 1.0)
declare -a burst_time=(9 5 2)
n=${#arrival_time[@]}

# Call the function to calculate optimal schedule and average turnaround time
calculate_optimal_schedule $n arrival_time burst_time

total_time=$((completion_times[${#completion_times[@]}] - arrival_time[1]))
cpu_utilization=$(bc <<< "scale=2; ($total_turnaround_time / $total_time) * 100")
echo "CPU Utilization: $cpu_utilization%"
