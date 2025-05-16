#!/bin/bash


source_file="\\wsl.localhost\\Ubuntu\\root\\lab2\\bcs230q2.sh"


destination_file="\\wsl.localhost\\Ubuntu\\root\\lab4"


lock_file="/tmp/copy_lock"


exec 200>"$lock_file"
flock -n 200 || { echo "Another process is already copying."; exit 1; }

# Copy the file
cp "$source_file" "$destination_file"
echo "File copied successfully."

# Release the lock
exec 200>&-