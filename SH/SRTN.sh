#!/bin/bash

process_ids=("P1" "P2" "P3" "P4" "P5")
arrival_times=(3 1 4 0 2)
burst_times=(1 4 2 6 3)
remaining_times=("${burst_times[@]}")

total_processes=${#process_ids[@]}
total_waiting_time=0
total_turnaround_time=0
completed_processes=0
current_time=0
prev_process=-1

while (( completed_processes < total_processes ))
do
  shortest=-1
  min_remaining_time=99999
  for (( i=0; i<total_processes; i++ ))
  do
    if (( arrival_times[i] <= current_time && remaining_times[i] < min_remaining_time && remaining_times[i] > 0 ))
    then
      min_remaining_time=${remaining_times[i]}
      shortest=$i
    fi
  done

  if (( shortest != -1 ))
  then
    remaining_times[shortest]=$((remaining_times[shortest] - 1))
    current_time=$((current_time + 1))

    if (( remaining_times[shortest] == 0 ))
    then
      completed_processes=$((completed_processes + 1))
      turnaround_times[shortest]=$((current_time - arrival_times[shortest]))
      waiting_times[shortest]=$((turnaround_times[shortest] - burst_times[shortest]))
    fi
  else
    current_time=$((current_time + 1))
  fi
done

for (( i=0; i<total_processes; i++ ))
do
  total_waiting_time=$((total_waiting_time + waiting_times[i]))
  total_turnaround_time=$((total_turnaround_time + turnaround_times[i]))
done

average_waiting_time=$(echo "scale=2; $total_waiting_time / $total_processes" | bc)
average_turnaround_time=$(echo "scale=2; $total_turnaround_time / $total_processes" | bc)

echo "Average Waiting Time: $average_waiting_time"
echo "Average Turnaround Time: $average_turnaround_time"
