#!/bin/bash

# Function to check if two strings are anagrams
is_anagram() {
    local str1="$1"
    local str2="$2"

    # Remove spaces and convert to lowercase
    str1=$(echo "$str1" | tr -d ' ' | tr '[:upper:]' '[:lower:]')
    str2=$(echo "$str2" | tr -d ' ' | tr '[:upper:]' '[:lower:]')

    # Check if the sorted strings are equal
    if [ "$(echo "$str1" | fold -w1 | sort | tr -d '\n')" = "$(echo "$str2" | fold -w1 | sort | tr -d '\n')" ]; then
        echo "The strings '$str1' and '$str2' are anagrams."
    else
        echo "The strings '$str1' and '$str2' are not anagrams."
    fi
}

# Prompt the user to enter the strings
read -p "Enter the first string: " string1
read -p "Enter the second string: " string2

# Call the function to check if the strings are anagrams
is_anagram "$string1" "$string2"
