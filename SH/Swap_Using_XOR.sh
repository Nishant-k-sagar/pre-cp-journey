#!/bin/bash

# Prompt the user to enter the values of the variables
read -p "Enter the value of variable 'a': " a
read -p "Enter the value of variable 'b': " b

echo "Before swapping:"
echo "a = $a"
echo "b = $b"

# Perform the swap using bitwise XOR
a=$((a ^ b))
b=$((a ^ b))
a=$((a ^ b))

echo "After swapping:"
echo "a = $a"
echo "b = $b"
