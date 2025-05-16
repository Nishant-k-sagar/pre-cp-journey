#!/bin/bash

# Function to check if a number is prime
is_prime() {
    local num=$1
    if [ $num -le 1 ]; then
        return 1 # Not prime
    fi
    for (( i=2; i*i<=num; i++ )); do
        if [ $((num % i)) -eq 0 ]; then
            return 1 # Not prime
        fi
    done
    return 0 # Prime
}

# Function to print all prime numbers within a range
print_prime_numbers() {
    local start=$1
    local end=$2
    echo "Prime numbers within the range $start to $end:"
    for (( num=start; num<=end; num++ )); do
        if is_prime $num; then
            echo -n "$num "
        fi
    done
    echo ""
}

# Function to print the sum of even numbers within a range
print_sum_of_even_numbers() {
    local start=$1
    local end=$2
    local sum=0
    for (( num=start; num<=end; num++ )); do
        if [ $((num % 2)) -eq 0 ]; then
            sum=$((sum + num))
        fi
    done
    echo "Sum of even numbers within the range $start to $end: $sum"
}

# Prompt the user to enter the range
read -p "Enter the start of the range: " start_range
read -p "Enter the end of the range: " end_range

# Call the functions to print prime numbers and sum of even numbers within the range
print_prime_numbers "$start_range" "$end_range"
print_sum_of_even_numbers "$start_range" "$end_range"
