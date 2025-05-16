#!/bin/bash

# Function to calculate binomial coefficient (n choose k)
binomial_coefficient() {
    local n=$1
    local k=$2
    local result=1
    if (( k > n - k )); then
        k=$((n - k))
    fi
    for (( i=0; i<k; i++ )); do
        result=$((result * (n - i)))
        result=$((result / (i + 1)))
    done
    echo $result
}

# Function to print Pascal's triangle
print_pascals_triangle() {
    local rows=$1
    for (( n=0; n<rows; n++ )); do
        for (( k=0; k<=n; k++ )); do
            coefficient=$(binomial_coefficient $n $k)
            echo -n "$coefficient "
        done
        echo ""
    done
}

# Prompt the user to enter the number of rows for Pascal's triangle
read -p "Enter the number of rows for Pascal's triangle: " num_rows

# Call the function to print Pascal's triangle
print_pascals_triangle $num_rows
