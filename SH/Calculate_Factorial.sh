#!/bin/bash

# Function to calculate the factorial of a number
factorial() {
    local num=$1
    local result=1
    for (( i=1; i<=$num; i++ )); do
        result=$((result * i))
    done
    echo $result
}

# Function to calculate factorial of numbers ranging from 1 to 10
calculate_factorials() {
    for (( n=1; n<=10; n++ )); do
        fact=$(factorial $n)
        echo "Factorial of $n is $fact"
    done
}

# Call the function to calculate factorial of numbers ranging from 1 to 10
calculate_factorials
