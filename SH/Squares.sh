#!/bin/bash

# Function to print squares of numbers from 1 to the given number
print_squares() {
    local num=$1
    for (( i=1; i<=num; i++ )); do
        square=$((i * i))
        echo "$i * $i = $square"
    done
}

# Prompt the user to enter a number
read -p "Enter a number: " input_number

# Call the function to print squares of numbers from 1 to the given number
print_squares "$input_number"
