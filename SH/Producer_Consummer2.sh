#!/bin/bash

# Function for the producer process
producer() {
    # Data to be produced
    data="This is some data."
    
    # Write data to file
    echo "Producer: Produced data: \"$data\"" > shared_file
    
    # Notify consumer that data is ready
    echo "Producer: Data produced."
}

# Function for the consumer process
consumer() {
    # Read data from file
    data=$(cat shared_file)
    
    # Process data
    echo "Consumer: Processed data: \"$data\""
}

# Main script

# Ensure the shared file exists and is empty
touch shared_file
> shared_file

# Run producer and consumer functions in background
producer &
consumer &

# Wait for both processes to finish
wait

# Clean up shared file
rm shared_file
