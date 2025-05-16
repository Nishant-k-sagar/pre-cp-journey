#!/bin/bash

# Function to check if a given year is a leap year
is_leap_year() {
    local year=$1
    if (( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )); then
        return 0 # Leap year
    else
        return 1 # Not a leap year
    fi
}

# Function to validate a given day within a year
is_valid_day() {
    local year=$1
    local month=$2
    local day=$3

    # Define an associative array to store the number of days in each month
    declare -A days_in_month
    days_in_month=( [1]=31 [2]=28 [3]=31 [4]=30 [5]=31 [6]=30 [7]=31 [8]=31 [9]=30 [10]=31 [11]=30 [12]=31 )

    # Check for leap year and update days in February accordingly
    if is_leap_year $year; then
        days_in_month[2]=29
    fi

    # Check if the day is within the valid range for the given month
    if (( day >= 1 && day <= ${days_in_month[$month]} )); then
        return 0 # Valid day
    else
        return 1 # Invalid day
    fi
}

# Prompt the user to enter the year, month, and day
read -p "Enter the year: " input_year
read -p "Enter the month (1-12): " input_month
read -p "Enter the day: " input_day

# Call the function to check if the year is a leap year
if is_leap_year $input_year; then
    echo "$input_year is a leap year."
else
    echo "$input_year is not a leap year."
fi

# Call the function to check if the day is valid within the year
if is_valid_day $input_year $input_month $input_day; then
    echo "The day $input_day is valid for $input_month/$input_year."
else
    echo "The day $input_day is not valid for $input_month/$input_year."
fi
