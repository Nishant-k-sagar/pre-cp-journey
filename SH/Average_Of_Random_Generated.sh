#!/bin/bash

# Function to find the average of numbers
calculate_average() {
    local sum=0
    local count=0
    for number in "$@"; do
        sum=$((sum + number))
        ((count++))
    done
    if [ $count -eq 0 ]; then
        echo "No numbers provided."
        return 1
    fi
    local average=$((sum / count))
    echo "Average of the numbers: $average"
}

# Generate random numbers
random_numbers=()
for (( i=0; i<10; i++ )); do
    random_numbers+=( $((RANDOM % 100)) )
done

echo "Generated random numbers: ${random_numbers[@]}"

# Call the function to find the average of the random numbers
calculate_average "${random_numbers[@]}"
