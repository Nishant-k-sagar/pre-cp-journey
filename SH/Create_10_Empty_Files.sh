#!/bin/bash

# Loop through numbers from 1 to 10 and create empty files
for (( i=1; i<=10; i++ )); do
    touch "file$i.txt"
done

# Print a message indicating the files have been created
echo "Created 10 empty files: file1.txt, file2.txt, ..., file10.txt"
