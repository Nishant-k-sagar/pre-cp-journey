#!/bin/bash

# Array for storing Process Id, Burst Time, Average Waiting Time & Average Turn Around Time.
A=()
total=0
avg_wt=0
avg_tat=0

read -p "Enter number of processes: " n
echo "Enter Burst Time:"

# User Input Burst Time and allocating Process Id.
for ((i=0; i<n; i++)); do
    read -p "P$((i+1)): " burst_time
    A+=("$i" "$burst_time")
done

# Sorting processes according to their Burst Time.
for ((i=0; i<n; i++)); do
    index=$i
    for ((j=i+1; j<n; j++)); do
        if ((A[j*2+1] < A[index*2+1])); then
            index=$j
        fi
    done
    temp=${A[i*2+1]}
    A[i*2+1]=${A[index*2+1]}
    A[index*2+1]=$temp
    temp=${A[i*2]}
    A[i*2]=${A[index*2]}
    A[index*2]=$temp
done

A[0*2+2]=0

# Calculation of Waiting Times
for ((i=1; i<n; i++)); do
    A[i*2+2]=0
    for ((j=0; j<i; j++)); do
        A[i*2+2]=$((A[i*2+2] + A[j*2+1]))
    done
    total=$((total + A[i*2+2]))
done

avg_wt=$(bc -l <<< "scale=2; $total / $n")
total=0

echo "P   BT   WT   TAT"

# Calculation of Turn Around Time and printing the data.
for ((i=0; i<n; i++)); do
    A[i*2+3]=$((A[i*2+1] + A[i*2+2]))
    total=$((total + A[i*2+3]))
    echo "P${A[i*2]}   ${A[i*2+1]}   ${A[i*2+2]}   ${A[i*2+3]}"
done

avg_tat=$(bc -l <<< "scale=2; $total / $n")

echo "Average Waiting Time= $avg_wt"
echo "Average Turnaround Time= $avg_tat"