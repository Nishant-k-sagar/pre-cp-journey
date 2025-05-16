#!/bin/bash

# Function to check if a number is a perfect square
is_perfect_square() {
    local num=$1
    local sqrt=$(echo "sqrt($num)" | bc) # Calculate square root using bc command
    local floor_sqrt=$(echo "$sqrt/1" | bc) # Round down to the nearest integer

    if (( floor_sqrt * floor_sqrt == num )); then
        return 0 # Perfect square
    else
        return 1 # Not a perfect square
    fi
}

# Prompt the user to enter the number
read -p "Enter a number: " input_number

# Call the function to check if the number is a perfect square
if is_perfect_square "$input_number"; then
    echo "$input_number is a perfect square."
else
    echo "$input_number is not a perfect square."
fi
