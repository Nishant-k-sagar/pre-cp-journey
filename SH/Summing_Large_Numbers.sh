#!/bin/bash


numbers=(1 2 3 4 5 6 7 8 9 10)

total_elements=${#numbers[@]}

num_processes=4

chunk_size=$((total_elements / num_processes))

total_sum=0

calculate_chunk_sum() {
    local start=$1
    local end=$2
    local chunk_sum=0

    for ((i = start; i < end; i++)); do
        chunk_sum=$((chunk_sum + numbers[i]))
    done

    echo "$chunk_sum"
}

for ((i = 0; i < num_processes; i++)); do
    start=$((i * chunk_size))
    end=$((start + chunk_size))

    chunk_sum=$(calculate_chunk_sum "$start" "$end")

    total_sum=$((total_sum + chunk_sum))
done

echo "Total sum: $total_sum"


























# #!/bin/bash

# # Function to calculate the sum of numbers in a given portion of the list
# calculate_sum() {
#     local start=$1
#     local end=$2
#     local sum=0
#     for ((i=start; i<=end; i++)); do
#         ((sum+=numbers[i]))
#     done
#     echo "$sum"
# }

# # Main script

# # Check if numbers.txt exists
# if [ ! -f "numbers.txt" ]; then
#     echo "Error: numbers.txt not found."
#     exit 1
# fi

# # Read numbers from numbers.txt into an array
# mapfile -t numbers < "numbers.txt"

# # Get the total number of elements in the array
# total_numbers="${#numbers[@]}"

# # Define the number of child processes (adjust as needed)
# num_processes=4

# # Calculate the number of elements each child process will handle
# elements_per_process=$((total_numbers / num_processes))

# # Array to store process IDs
# pids=()

# # Start child processes to calculate sum of each portion of the list
# for ((i=0; i<num_processes; i++)); do
#     start=$((i * elements_per_process))
#     end=$((start + elements_per_process - 1))
    
#     # Handle the case when the total number of elements is not evenly divisible
#     if [ $i -eq $((num_processes - 1)) ]; then
#         end=$((total_numbers - 1))
#     fi
    
#     # Calculate sum in child process
#     calculate_sum "$start" "$end" &
#     pids+=("$!")
# done

# # Wait for all child processes to finish and collect their results
# sum=0
# for pid in "${pids[@]}"; do
#     wait "$pid"
#     sum=$((sum + $(<"${pid}/status")))
# done

# # Print the final sum
# echo "The sum of all numbers is: $sum"
