#!/bin/bash

calculate_execution_times() {
    local num_processes=$1
    local -n process_arrival_time=$2
    local -n process_burst_time=$3

    local total_waiting=0
    local total_turnaround=0

    local current_time=0
    local completed_processes=0

    declare -a completion_times
    declare -a waiting_times
    declare -a turnaround_times
    declare -a burst_remaining_times

    for ((i = 0; i < num_processes; i++)); do
        burst_remaining_times[$i]=${process_burst_time[$i]}
    done

    while ((completed_processes != num_processes)); do
        local shortest_burst=-1
        local shortest_index=-1

        for ((i = 0; i < num_processes; i++)); do
            if ((${process_arrival_time[$i]} <= $current_time)) && ((${burst_remaining_times[$i]} > 0)); then
                if (($shortest_burst == -1)) || ((${burst_remaining_times[$i]} < $shortest_burst)); then
                    shortest_burst=${burst_remaining_times[$i]}
                    shortest_index=$i
                fi
            fi
        done

        if (($shortest_index == -1)); then
            current_time=$((current_time + 1))
            continue
        fi

        completion_times[$shortest_index]=$((current_time + ${process_burst_time[$shortest_index]}))
        current_time=${completion_times[$shortest_index]}
        waiting_times[$shortest_index]=$((current_time - ${process_burst_time[$shortest_index]} - ${process_arrival_time[$shortest_index]}))
        turnaround_times[$shortest_index]=$((current_time - ${process_arrival_time[$shortest_index]}))
        total_waiting=$((total_waiting + ${waiting_times[$shortest_index]}))
        total_turnaround=$((total_turnaround + ${turnaround_times[$shortest_index]}))
        burst_remaining_times[$shortest_index]=0
        completed_processes=$((completed_processes + 1))
    done

    avg_waiting=$(bc <<<"scale=2; $total_waiting / $num_processes")
    avg_turnaround=$(bc <<<"scale=2; $total_turnaround / $num_processes")

    echo "Average Waiting Time: $avg_waiting"
    echo "Average Turnaround Time: $avg_turnaround"
}

declare -a arrival_times=(3 1 4 0 2)
declare -a burst_times=(1 4 2 6 3)
num_processes=${#arrival_times[@]}

calculate_execution_times $num_processes arrival_times burst_times

