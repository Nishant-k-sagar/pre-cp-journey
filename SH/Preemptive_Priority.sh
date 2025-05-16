#!/bin/bash

calculate_execution_times() {
    local num_processes=$1
    local -n process_arrival_time=$2
    local -n process_burst_time=$3
    local -n process_priority=$4

    local total_waiting_time=0
    local total_turnaround_time=0
    local current_time=0
    local completed_processes=0
    declare -a burst_remaining_time
    declare -a waiting_times
    declare -a turnaround_times
    declare -a processed_processes

    for ((i = 0; i < num_processes; i++)); do
        burst_remaining_time[$i]=${process_burst_time[$i]}
        processed_processes[$i]=0
    done

    while ((completed_processes != num_processes)); do
        local highest_priority=-1
        local highest_priority_index=-1

        for ((i = 0; i < num_processes; i++)); do
            if ((${process_arrival_time[$i]} <= $current_time)) && ((${process_priority[$i]} > $highest_priority)) && ((${burst_remaining_time[$i]} > 0)); then
                highest_priority=${process_priority[$i]}
                highest_priority_index=$i
            fi
        done

        if (($highest_priority_index == -1)); then
            current_time=$((current_time + 1))
            continue
        fi

        burst_remaining_time[$highest_priority_index]=$((burst_remaining_time[$highest_priority_index] - 1))
        current_time=$((current_time + 1))

        if ((${burst_remaining_time[$highest_priority_index]} == 0)); then
            waiting_times[$highest_priority_index]=$((current_time - ${process_arrival_time[$highest_priority_index]} - ${process_burst_time[$highest_priority_index]}))
            turnaround_times[$highest_priority_index]=$((current_time - ${process_arrival_time[$highest_priority_index]}))
            total_waiting_time=$((total_waiting_time + ${waiting_times[$highest_priority_index]}))
            total_turnaround_time=$((total_turnaround_time + ${turnaround_times[$highest_priority_index]}))
            completed_processes=$((completed_processes + 1))
            processed_processes[$highest_priority_index]=1
        fi

        for ((i = 0; i < num_processes; i++)); do
            if ((${process_arrival_time[$i]} <= $current_time)) && ((${processed_processes[$i]} == 0)) && ((${process_priority[$i]} > $highest_priority)); then
                waiting_times[$i]=$((waiting_times[$i] + 1))
            fi
        done
    done

    avg_waiting_time=$(bc <<<"scale=2; $total_waiting_time / $num_processes")
    avg_turnaround_time=$(bc <<<"scale=2; $total_turnaround_time / $num_processes")

    echo "Average Waiting Time: $avg_waiting_time"
    echo "Average Turnaround Time: $avg_turnaround_time"
}

declare -a arrival_times=(0 1 2 3 4)
declare -a burst_times=(4 3 1 5 2)
declare -a priorities=(2 3 4 5 5)
num_processes=${#arrival_times[@]}

calculate_execution_times $num_processes arrival_times burst_times priorities

