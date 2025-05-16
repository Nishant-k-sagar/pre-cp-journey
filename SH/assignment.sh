#!/bin/bash

# Function for printing odd numbers
print_odd() {
    for ((i=1; i<=10; i+=2)); do
        echo $i
    done
}

# Function for printing even numbers
print_even() {
    for ((i=2; i<=10; i+=2)); do
        echo $i
    done
}

# Create child processes to print odd and even numbers
print_odd &  # Start printing odd numbers in the background
pid_odd=$!   # Get the PID of the odd process

print_even   # Start printing even numbers in the foreground

# Wait for the odd process to finish before exiting
wait $pid_odd

===================================================
#!/bin/bash

# Define the file locations
source_file="/path/to/source/file"
destination_file="/path/to/destination/file"
lock_file="/tmp/copy_lock"

# Check if lock file exists, if not create it
if [ -e "$lock_file" ]; then
    echo "Another process is currently copying the file. Exiting."
    exit 1
else
    touch "$lock_file"
fi

# Perform the copy operation
cp "$source_file" "$destination_file"

# Remove the lock file after the copy operation is complete
rm "$lock_file"

===============================================
#!/bin/bash

# Initialize the counter file with value 0
echo 0 > counter.txt

# Function to increment the counter by 10,000
increment_counter() {
    for ((i=0; i<10000; i++)); do
        # Use a file lock to prevent race conditions
        flock counter.txt -c 'count=$(<counter.txt); echo "$((count + 1))" > counter.txt'
    done
}

# Create 5 child processes to increment the counter
for ((i=1; i<=5; i++)); do
    increment_counter &
done

# Wait for all child processes to finish
wait

# Read and display the final counter value
final_count=$(<counter.txt)
echo "Final counter value: $final_count"

# Clean up the counter file
rm counter.txt
=============================================
#!/bin/bash

# Function to display the traffic light status
display_traffic_light() {
    case $1 in
        "red") echo "Red Light";;
        "yellow") echo "Yellow Light";;
        "green") echo "Green Light";;
    esac
}

# Function to control the traffic light sequence
control_traffic_light() {
    while true; do
        echo "Switching to Red Light"
        echo "red" > light_status
        sleep 5

        echo "Switching to Green Light"
        echo "green" > light_status
        sleep 5

        echo "Switching to Yellow Light"
        echo "yellow" > light_status
        sleep 2
    done
}

# Create a file to store the current light status
echo "green" > light_status

# Start the traffic light control process
control_traffic_light &

# Main loop to display the traffic light status
while true; do
    light=$(<light_status)
    display_traffic_light $light
    sleep 1
done
===========================================
#!/bin/bash

# Function to download file from URL
download_file() {
    url=$1
    filename=$(basename "$url")
    curl -s -o "$filename" "$url"
}

# List of URLs to download
urls=(
    "https://example.com/file1.txt"
    "https://example.com/file2.txt"
    "https://example.com/file3.txt"
)

# Create a temporary directory for downloads
temp_dir=$(mktemp -d)

# Change directory to the temporary directory
cd "$temp_dir" || { echo "Error: Unable to change directory."; exit 1; }

# Loop through the URLs and start a separate process to download each file
for url in "${urls[@]}"; do
    download_file "$url" &
done

# Wait for all download processes to finish
wait

# Move the downloaded files to the desired location
destination_dir="/path/to/destination"
mkdir -p "$destination_dir"
mv * "$destination_dir"

# Clean up the temporary directory
rm -r "$temp_dir"
==========================================
#!/bin/bash

# Function for sending messages
send_message() {
    user=$1
    message=$2
    echo "$user: $message" >> chat_room.log
}

# Function for receiving messages
receive_messages() {
    tail -n 0 -f chat_room.log | grep -v "^\s*$"
}

# Initialize the chat room log file
> chat_room.log

# Simulate users sending and receiving messages
user1="User1"
user2="User2"

# Start a process for receiving messages
receive_messages &

# User1 sends messages
send_message "$user1" "Hello, User2!"
send_message "$user1" "How are you?"

# User2 sends messages
send_message "$user2" "Hi, User1!"
send_message "$user2" "I'm good, thanks!"

# Wait for a few seconds to allow messages to be received
sleep 2

# Clean up by killing the tail process
pkill -P $$

=========================================================

#!/bin/bash

# Define the list of numbers
numbers=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15)

# Function to calculate the sum of numbers in a given range
calculate_sum() {
    local start=$1
    local end=$2
    local sum=0

    for ((i=start; i<=end; i++)); do
        sum=$((sum + numbers[i]))
    done

    echo $sum
}

# Split the list into two equal parts
total_numbers=${#numbers[@]}
mid=$((total_numbers / 2))

# Create child processes to calculate the sum of each half
calculate_sum 0 $((mid - 1)) &
pid1=$!

calculate_sum $mid $((total_numbers - 1)) &
pid2=$!

# Wait for the child processes to finish and get the results
wait $pid1
result1=$?

wait $pid2
result2=$?

# Calculate the final sum
final_sum=$((result1 + result2))

echo "The sum of the numbers is: $final_sum"

=============================================#!/bin/bash

# Initialize the bank account balance
balance=1000

# Function for depositing money into the bank account
deposit() {
    amount=$1
    balance=$((balance + amount))
}

# Function for withdrawing money from the bank account
withdraw() {
    amount=$1
    if [ $amount -le $balance ]; then
        balance=$((balance - amount))
    else
        echo "Insufficient funds for withdrawal."
    fi
}

# Create multiple processes to simulate customers depositing and withdrawing money
for i in {1..5}; do
    # Randomly choose between deposit and withdrawal
    action=$((RANDOM % 2))
    amount=$((RANDOM % 500 + 1))  # Random amount between 1 and 500

    if [ $action -eq 0 ]; then
        deposit $amount
        echo "Customer $i deposited $amount. New balance: $balance"
    else
        withdraw $amount
        echo "Customer $i withdrew $amount. New balance: $balance"
    fi
done
========================================


#!/bin/bash

# Define the lock file
lock_file="/tmp/shared_resource.lock"

# Function to acquire the lock
acquire_lock() {
    # Check if the lock file exists
    while [ -e "$lock_file" ]; do
        sleep 1  # Wait for the lock to be released
    done
    touch "$lock_file"  # Create the lock file
}

# Function to release the lock
release_lock() {
    rm "$lock_file"  # Remove the lock file
}

# Simulate accessing the shared resource
access_shared_resource() {
    acquire_lock  # Acquire the lock before accessing the resource

    echo "Accessing shared resource..."
    sleep 3  # Simulate using the shared resource

    release_lock  # Release the lock after accessing the resource
}

# Simulate multiple processes trying to access the shared resource
echo "Process 1 wants to access the shared resource."
access_shared_resource &

echo "Process 2 wants to access the shared resource."
access_shared_resource &

# Wait for the processes to finish
wait

==============================================================