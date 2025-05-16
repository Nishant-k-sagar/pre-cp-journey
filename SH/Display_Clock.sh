#!/bin/bash

# Function to display the digital clock
display_clock() {
    while true; do
        clear # Clear the screen
        echo "$(date +"%T")" # Display the current time
        sleep 1 # Wait for 1 second
    done
}

# Call the function to display the digital clock
display_clock
