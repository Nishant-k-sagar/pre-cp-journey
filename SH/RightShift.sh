#!/bin/bash

# Prompt the user to enter the number and the number of positions to right shift
read -p "Enter the number: " number
read -p "Enter the number of positions to right shift: " shift_count

# Perform the right shift operation
result=$((number >> shift_count))

# Print the result
echo "Result of right shifting $number by $shift_count positions: $result"
