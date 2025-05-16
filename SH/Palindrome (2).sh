#!/bin/bash

# Function to check if a string is a palindrome
is_palindrome() {
    local string="$1"
    local reversed_string=$(echo "$string" | rev)
    if [ "$string" = "$reversed_string" ]; then
        return 0 # Palindrome
    else
        return 1 # Not a palindrome
    fi
}

# Prompt the user to enter the string
read -p "Enter a string: " input_string

# Call the function to check if the string is a palindrome
if is_palindrome "$input_string"; then
    echo "$input_string is a palindrome."
else
    echo "$input_string is not a palindrome."
fi
