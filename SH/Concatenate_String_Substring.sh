#!/bin/bash

# Function to concatenate two strings
concatenate_strings() {
    local string1=$1
    local string2=$2
    local concatenated_string="${string1}${string2}"
    echo "Concatenated string: $concatenated_string"
}

# Function to extract a substring from the concatenated string
extract_substring() {
    local concatenated_string=$1
    local start_index=$2
    local end_index=$3
    local substring="${concatenated_string:$start_index:$((end_index - start_index + 1))}"
    echo "Substring from index $start_index to $end_index: $substring"
}

# Prompt the user to enter two strings
read -p "Enter the first string: " string1
read -p "Enter the second string: " string2

# Call the function to concatenate the strings
concatenate_strings "$string1" "$string2"

# Concatenate the strings
concatenated_string="${string1}${string2}"

# Prompt the user to enter start and end indices for the substring
read -p "Enter the start index for the substring: " start_index
read -p "Enter the end index for the substring: " end_index

# Call the function to extract the substring
extract_substring "$concatenated_string" "$start_index" "$end_index"
