is_palindrome() {
    original_number=$1

    
    reversed_decimal=$(echo "$original_number" | rev)
    if [ "$original_number" == "$reversed_decimal" ]; then
        echo "Decimal representation is a palindrome."
    else
        echo "Decimal representation is not a palindrome."
    fi

    binary_representation=$(echo "obase=2; $original_number" | bc)
    reversed_binary=$(echo "$binary_representation" | rev)
    if [ "$binary_representation" == "$reversed_binary" ]; then
        echo "Binary representation is a palindrome."
    else
        echo "Binary representation is not a palindrome."
    fi
}

read -p "Enter the number" num
is_palindrome $num




