#!/bin/bash

# Function to download a file from a given URL
download_file() {
    local url=$1
    local filename=$(basename "$url")
    
    # Download the file
    echo "Downloading file: $url"
    wget -q "$url" -O "$filename"
    
    # Print a message after download completes
    echo "Downloaded file: $url to $filename"
}

# Main script

# Check if file_list.txt exists
if [ ! -f "file_list.txt" ]; then
    echo "Error: file_list.txt not found."
    exit 1
fi

# Read the list of URLs from file_list.txt and start downloading each file concurrently
while IFS= read -r url; do
    download_file "$url" &
done < "file_list.txt"

# Wait for all download processes to finish
wait
