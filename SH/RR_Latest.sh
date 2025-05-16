#!/bin/bash





# Define an array to store process names

processes=("P1" "P2" "P3" "P4")



# Define an array to store burst times for each process

burst_times=(8 4 9 5)



# Define the time quantum (time slice)

time_quantum=3



# Calculate the number of processes

num_processes=${#processes[@]}



# Initialize waiting time, turnaround time, and remaining burst time arrays

waiting_time=()

turnaround_time=()

remaining_burst=()



# Initialize total waiting time and total turnaround time variables

total_waiting_time=0

total_turnaround_time=0



# Copy burst times to the remaining burst time array

for ((i=0; i<num_processes; i++)); do

    remaining_burst[$i]=${burst_times[$i]}

done



# Simulate Round Robin scheduling

current_time=0

while true; do

    all_done=true

    for ((i=0; i<num_processes; i++)); do

        if [ ${remaining_burst[$i]} -gt 0 ]; then

            all_done=false

            if [ ${remaining_burst[$i]} -gt $time_quantum ]; then

                current_time=$((current_time + time_quantum))

                remaining_burst[$i]=$((remaining_burst[$i] - time_quantum))

            else

                current_time=$((current_time + remaining_burst[$i]))

                waiting_time[$i]=$((current_time - burst_times[$i]))

                remaining_burst[$i]=0

            fi

        fi

    done



    if $all_done; then

        break

    fi

done



# Calculate turnaround time for each process

for ((i=0; i<num_processes; i++)); do

    turnaround_time[$i]=$((burst_times[$i] + waiting_time[$i]))

    total_waiting_time=$((total_waiting_time + waiting_time[$i]))

    total_turnaround_time=$((total_turnaround_time + turnaround_time[$i]))

done



# Calculate average waiting time and average turnaround time

average_waiting_time=$(bc <<< "scale=2; $total_waiting_time / $num_processes")

average_turnaround_time=$(bc <<< "scale=2; $total_turnaround_time / $num_processes")



# Print the results

echo "Round Robin Scheduling Algorithm Simulation (Time Quantum: $time_quantum)"

echo "-----------------------------------"

echo "Process  Burst Time  Waiting Time  Turnaround Time"

for ((i=0; i<num_processes; i++)); do

    echo "${processes[$i]}        ${burst_times[$i]}           ${waiting_time[$i]}             ${turnaround_time[$i]}"

done

echo "-----------------------------------"

echo "Average Waiting Time: $average_waiting_time"

echo "Average Turnaround Time: $average_turnaround_time"

