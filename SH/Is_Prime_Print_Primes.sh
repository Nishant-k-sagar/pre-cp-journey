is_prime() {
    if [[ $1 -le 1 ]]; then
        return 1  
    fi

    for ((i = 2; i*i <= $1; i++)); do
        if (( $1 % i == 0 )); then
            return 1  
        fi
    done

    return 0  
}

print_primes() {
    for ((num = $1; num <= $2; num++)); do
        if is_prime "$num"; then
            echo -n "$num "
        fi
    done

    echo
}


read -p "Enter a positive integer for is_prime: " input_prime
if is_prime "$input_prime"; then
    echo "True"
else
    echo "False"
fi

read -p "Enter two positive integers for print_primes (start end): " start end
print_primes "$start" "$end"

