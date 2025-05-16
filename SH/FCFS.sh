#!/bin/bash



echo "Enter the number of processes:"

read n

burst_time=()

waiting_time=()

turnaround_time=()



echo "Enter the burst time for each process:"



for (( i=0; i<n; i++ ))

do

    read burst_time[$i]

done



waiting_time[0]=0

total_wt=0

total_tat=0



# Calculate waiting time for each process

for (( i=1; i<n; i++ ))

do

    waiting_time[$i]=$((waiting_time[$((i-1))]+burst_time[$((i-1))]))

    total_wt=$((total_wt+waiting_time[$i]))

done



# Calculate turnaround time for each process

for (( i=0; i<n; i++ ))

do

    turnaround_time[$i]=$((waiting_time[$i]+burst_time[$i]))

    total_tat=$((total_tat+turnaround_time[$i]))

done



echo "Processes    Burst Time    Waiting Time    Turnaround Time"



for (( i=0; i<n; i++ ))

do

    echo "  $i           ${burst_time[$i]}               ${waiting_time[$i]}               ${turnaround_time[$i]}"

done



avg_wt=$(echo "scale=2; $total_wt / $n" | bc)

avg_tat=$(echo "scale=2; $total_tat / $n" | bc)



echo "Average Waiting Time: $avg_wt"

echo "Average Turnaround Time: $avg_tat"





total_bt=0



# Calculate total burst time

for (( i=0; i<n; i++ ))

do

    total_bt=$((total_bt+burst_time[$i]))

done



avg_bt=$(echo "scale=2; $total_bt / $n" | bc)

echo "Average Burst Time: $avg_bt"

