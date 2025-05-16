perform_operations() {
    read -p "Enter the first floating-point number: " num1
    read -p "Enter the second floating-point number: " num2

    sum=$(echo "$num1 + $num2" | bc -l)
    difference=$(echo "$num1 - $num2" | bc -l)
    product=$(echo "$num1 * $num2" | bc -l)
    
    if [ "$num2" != 0 ]; then
        quotient=$(echo "$num1 / $num2" | bc -l)
        echo "Quotient (num1 / num2): $quotient"
    else
        echo "Cannot divide by zero."
    fi

    echo "Sum (num1 + num2): $sum"
    echo "Difference (num1 - num2): $difference"
    echo "Product (num1 * num2): $product"
}

perform_operations