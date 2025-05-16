#!/bin/bash

# Function to print a triangle pattern using asterisks
print_triangle() {
    local size=$1
    for (( i=1; i<=size; i++ )); do
        for (( j=1; j<=size-i; j++ )); do
            echo -n " "
        done
        for (( k=1; k<=i; k++ )); do
            echo -n "* "
        done
        echo ""
    done
}

# Prompt the user to enter the size of the triangle
read -p "Enter the size of the triangle: " triangle_size

# Call the function to print the triangle pattern
print_triangle "$triangle_size"
