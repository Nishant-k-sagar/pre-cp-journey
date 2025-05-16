perform_operations() {
    num1=$1
    num2=$2

    sum=$((num1 + num2))
    difference=$((num1 - num2))
    product=$((num1 * num2))

    if [ $num2 -ne 0 ]; then
        division=$(echo "scale=2; $num1 / $num2" | bc)
    else
        division="Undefined (division by zero)"
    fi

    echo "Sum: $sum"
    echo "Difference: $difference"
    echo "Product: $product"
    echo "Division: $division"
}


read -p "Enter the first number: " number1
read -p "Enter the second number: " number2

# Check if the inputs are valid numbers
#if [[ $number1 =~ ^[0-9]+$ && $number2 =~ ^[0-9]+$ ]]; then
    perform_operations $number1 $number2
#else
    #echo "Please enter valid numbers."
#fi

