#!/bin/bash

# Function to print the reverse of a number
print_reverse() {
    local num=$1
    local reverse=""
    while [ $num -gt 0 ]; do
        remainder=$((num % 10))
        reverse="${reverse}${remainder}"
        num=$((num / 10))
    done
    echo "Reverse of the number is: $reverse"
}

# Prompt the user to enter a number
read -p "Enter a number: " input_number

# Call the function to print the reverse of the number
print_reverse "$input_number"
