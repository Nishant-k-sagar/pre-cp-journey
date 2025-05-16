#!/bin/bash

# Process array containing arrival time and burst time
processes=(
    [1]="P1 0 10"
    [2]="P2 1 5"
    [3]="P3 2 8"
    [4]="P4 3 3"
)

# Function to calculate waiting time
calculate_waiting_time() {
    local -n burst_times=$1
    local -n waiting_times=$2

    waiting_times[1]=0 # First process has 0 waiting time

    for ((i=2; i<=${#burst_times[@]}; i++)); do
        waiting_times[$i]=$((waiting_times[$((i-1))] + burst_times[$((i-1))]))
    done
}

# Function to calculate turnaround time
calculate_turnaround_time() {
    local -n burst_times=$1
    local -n waiting_times=$2
    local -n turnaround_times=$3

    for ((i=1; i<=${#burst_times[@]}; i++)); do
        turnaround_times[$i]=$((waiting_times[$i] + burst_times[$i]))
    done
}

# Function to calculate average time
calculate_average_time() {
    local -n times=$1
    local sum=0

    for time in ${times[@]}; do
        sum=$((sum + time))
    done

    echo "Average time: $(bc -l <<< "scale=2; $sum / ${#times[@]}")"
}

# Main function
main() {
    local -a burst_times=()
    local -a waiting_times=()
    local -a turnaround_times=()

    # Extract burst times from processes array
    for process in "${processes[@]}"; do
        burst_times+=($(echo "$process" | awk '{print $3}'))
    done

    calculate_waiting_time burst_times waiting_times
    calculate_turnaround_time burst_times waiting_times turnaround_times

    echo "Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time"
    for i in "${!processes[@]}"; do
        echo "${processes[$i]} | ${waiting_times[$((i+1))]} | ${turnaround_times[$((i+1))]}"
    done

    calculate_average_time waiting_times
    calculate_average_time turnaround_times
}

main