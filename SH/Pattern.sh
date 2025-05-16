#!/bin/bash

# Define the number of rows
rows=5

# Loop through each row
for (( i=1; i<=rows; i++ )); do
    # Loop through each column in the current row
    for (( j=1; j<=i; j++ )); do
        echo -n "$j"
    done
    echo "" # Move to the next line after printing each row
done
