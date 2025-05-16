#!/bin/bash

# Function to determine the day of the week
get_day_of_week() {
    local day_number=$1
    case $day_number in
        1) echo "Sunday" ;;
        2) echo "Monday" ;;
        3) echo "Tuesday" ;;
        4) echo "Wednesday" ;;
        5) echo "Thursday" ;;
        6) echo "Friday" ;;
        7) echo "Saturday" ;;
        *) echo "Invalid day number. Please enter a number between 1 and 7." ;;
    esac
}

# Prompt the user to enter the numerical representation of the day
read -p "Enter the numerical representation of the day (1 for Sunday, 2 for Monday, etc.): " day_number

# Call the function to determine the day of the week
get_day_of_week "$day_number"
