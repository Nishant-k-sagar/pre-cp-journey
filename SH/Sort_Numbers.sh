sort_numbers() {
   
    read -p "Enter the first number: " num1
    read -p "Enter the second number: " num2
    read -p "Enter the third number: " num3

    
    if [ "$num1" -le "$num2" ] && [ "$num1" -le "$num3" ]; then
        if [ "$num2" -le "$num3" ]; then
            echo "Numbers in ascending order: $num1 $num2 $num3"
        else
            echo "Numbers in ascending order: $num1 $num3 $num2"
        fi
    elif [ "$num2" -le "$num1" ] && [ "$num2" -le "$num3" ]; then
        if [ "$num1" -le "$num3" ]; then
            echo "Numbers in ascending order: $num2 $num1 $num3"
        else
            echo "Numbers in ascending order: $num2 $num3 $num1"
        fi
    else
        if [ "$num1" -le "$num2" ]; then
            echo "Numbers in ascending order: $num3 $num1 $num2"
        else
            echo "Numbers in ascending order: $num3 $num2 $num1"
        fi
    fi
}


sort_numbers
