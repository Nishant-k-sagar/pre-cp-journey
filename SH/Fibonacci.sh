#!/bin/bash

# Function to print the Fibonacci series up to a specified number
fibonacci_series() {
    local num=$1
    local a=0
    local b=1
    local temp
    echo "Fibonacci series up to $num:"
    while [ $a -le $num ]; do
        echo -n "$a "
        temp=$((a + b))
        a=$b
        b=$temp
    done
    echo ""
}

# Prompt the user to enter a number
read -p "Enter a number: " input_number

# Call the function to print the Fibonacci series up to the specified number
fibonacci_series "$input_number"
