matrix_addition() {
    rows=$1
    cols=$2

    
    declare -a matrix1
    declare -a matrix2

    
    echo "Enter elements of the first matrix:"
    for ((i=0; i<rows; i++)); do
        for ((j=0; j<cols; j++)); do
            read -p "Enter element at position [$((i+1))][$((j+1))]: " value
            index=$((i * cols + j))
            matrix1[$index]=$value
        done
    done

    
    echo "Enter elements of the second matrix:"
    for ((i=0; i<rows; i++)); do
        for ((j=0; j<cols; j++)); do
            read -p "Enter element at position [$((i+1))][$((j+1))]: " value
            index=$((i * cols + j))
            matrix2[$index]=$value
        done
    done

    
    echo "Resultant matrix after addition:"
    for ((i=0; i<rows; i++)); do
        for ((j=0; j<cols; j++)); do
            index=$((i * cols + j))
            result=$((matrix1[$index] + matrix2[$index]))
            echo -n "$result "
        done
        echo
    done
    
    
    
    
    echo "Resultant matrix after subtraction:"
    for ((i=0; i<rows; i++)); do
        for ((j=0; j<cols; j++)); do
            index=$((i * cols + j))
            result=$((matrix1[$index] - matrix2[$index]))
            echo -n "$result "
        done
        echo
    done
    
    
    echo "Resultant matrix after multiplication:"
    for ((i=0; i<rows; i++)); do
        for ((j=0; j<cols; j++)); do
            result=0
            for ((k=0; k<cols; k++)); do
                index1=$((i * cols + k))
                index2=$((k * cols + j))
                result=$((result + matrix1[$index1] * matrix2[$index2]))
            done
            echo -n "$result "
        done
        echo
    done
    
 
    
}


read -p "Enter the number of rows: " rows
read -p "Enter the number of columns: " cols


matrix_addition $rows $cols



