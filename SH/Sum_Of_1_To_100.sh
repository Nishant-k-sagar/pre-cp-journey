#!/bin/bash

# Initialize sum variable
sum=0

# Loop through numbers from 1 to 100 and add them to sum
for (( i=1; i<=100; i++ )); do
    sum=$((sum + i))
done

# Print the sum
echo "The sum of numbers from 1 to 100 is: $sum"
