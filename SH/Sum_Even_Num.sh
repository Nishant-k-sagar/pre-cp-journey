sum_even_numbers() {
    local start=$1
    local end=$2

    
    if ((start % 2 != 0)); then
        start=$((start + 1))
    fi

    if ((end % 2 != 0)); then
        end=$((end - 1))
    fi

    local sum=0

    for ((i = start; i <= end; i += 2)); do
        sum=$((sum + i))
    done

    echo $sum
}


read -p "Enter the start of the range: " start
read -p "Enter the end of the range: " end

result=$(sum_even_numbers "$start" "$end")
echo "Sum of even numbers in the range [$start, $end]: $result"

