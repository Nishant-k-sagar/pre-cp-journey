


#!/bin/bash

# Prompt the user to enter values for 'a' and 'b'
read -p "Enter the value of 'a': " a
read -p "Enter the value of 'b': " b

# Calculate the expression
result=$(( (a + b) * (a + b) - (a - b) * (a - b) ))

# Print the result
echo "Result: $result"
