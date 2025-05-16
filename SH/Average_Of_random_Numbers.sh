generate_random_numbers() {
    local n=$1
    local start=$2
    local end=$3

    
    shuf -i "$start-$end" -n "$n" | tr '\n' ' '
}

calculate_average() {
    local numbers=($@)
    local sum=0
    local count=${#numbers[@]}

    for num in "${numbers[@]}"; do
        sum=$((sum + num))
    done

    echo "Generated random numbers: [${numbers[@]}]"
    echo "Average: $(awk "BEGIN {print $sum / $count}")"
}


read -p "Enter the number of random numbers: " n
read -p "Enter the start of the range: " start
read -p "Enter the end of the range: " end

random_numbers=($(generate_random_numbers "$n" "$start" "$end"))
calculate_average "${random_numbers[@]}"

