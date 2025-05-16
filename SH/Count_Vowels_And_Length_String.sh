#!/bin/bash

# Function to count the number of vowels in a string
count_vowels() {
    local string=$1
    local vowel_count=0
    for (( i=0; i<${#string}; i++ )); do
        char="${string:i:1}"
        case $char in
            [aeiouAEIOU]) ((vowel_count++));;
        esac
    done
    echo "Number of vowels in the string: $vowel_count"
}

# Function to calculate the length of a string
calculate_length() {
    local string=$1
    local length=${#string}
    echo "Length of the string: $length"
}

# Prompt the user to enter a string
read -p "Enter a string: " input_string

# Call the functions to count vowels and calculate length of the string
count_vowels "$input_string"
calculate_length "$input_string"
