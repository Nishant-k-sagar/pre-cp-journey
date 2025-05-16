#!/bin/bash

# Function to check if a string is a valid email address
is_valid_email() {
    local email=$1
    local regex="^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    if [[ $email =~ $regex ]]; then
        echo "The email address '$email' is valid."
    else
        echo "The email address '$email' is not valid."
    fi
}

# Prompt the user to enter the email address
read -p "Enter an email address: " input_email

# Call the function to check if the input is a valid email address
is_valid_email "$input_email"
