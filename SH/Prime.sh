is_prime() {
    num=$1
    if [ $num -lt 2 ]; then
        echo "Not Prime"
        return
    fi

    for ((i=2; i*i<=$num; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            echo "Not Prime"
            return
        fi
    done

    echo "Prime"
}

read -p "Enter a number: " number

    result=$(is_prime $number)
    echo "The number $number is $result."

