#!/bin/bash

# Function to convert the first letter of each word to uppercase
convert_first_letter_to_uppercase() {
    local string="$1"
    local result=""
    for word in $string; do
        result="${result} $(echo ${word^})"
    done
    echo "String with first letter of each word in uppercase: $result"
}

# Function to print the frequency count of each character in the string
print_character_frequency() {
    local string="$1"
    local char_count=()
    for (( i=0; i<${#string}; i++ )); do
        char="${string:i:1}"
        if [[ "${char}" =~ [[:alpha:]] ]]; then
            char=${char^^} # Convert to uppercase
        fi
        ((char_count[ASCII_CODE_OF_$char]++))
    done
    echo "Frequency count of each character in the string:"
    for char in "${!char_count[@]}"; do
        echo "${char^}: ${char_count[$char]}"
    done
}

# Prompt the user to enter a string
read -p "Enter a string: " input_string

# Call the function to convert the first letter of each word to uppercase
convert_first_letter_to_uppercase "$input_string"

# Call the function to print the frequency count of each character in the string
print_character_frequency "$input_string"
