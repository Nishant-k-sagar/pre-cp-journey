reverse_number() {
    local n=$1
    local sign=1

    
    if ((n < 0)); then
        sign=-1
        n=$(( -n ))
    fi

    local reversed=0

    while ((n > 0)); do
        digit=$((n % 10))
        reversed=$((reversed * 10 + digit))
        n=$((n / 10))
    done

    echo $((reversed * sign))
}


read -p "Enter an integer: " input
result=$(reverse_number "$input")

echo "Input: $input, Output: $result"

