#!/bin/bash

contains_both() {
    local str="$1"
    local has_lowercase=false
    local has_uppercase=false

    for (( i=0; i<${#str}; i++ )); do
        char="${str:$i:1}"
        if [[ "$char" =~ [[:lower:]] ]]; then
            has_lowercase=true
        elif [[ "$char" =~ [[:upper:]] ]]; then
            has_uppercase=true
        fi
    done

    if [ "$has_lowercase" = true ] && [ "$has_uppercase" = true ]; then
        echo "The string contains both lowercase and uppercase letters."
    else
        echo "The string does not contain both lowercase and uppercase letters."
    fi
}

# Prompt the user to enter the string
read -p "Enter a string: " input_string

# Call the function with the input string
contains_both "$input_string"
