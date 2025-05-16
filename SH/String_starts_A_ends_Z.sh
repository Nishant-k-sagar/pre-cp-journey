check_string() {
    user_input=$1
    
    first_char="${user_input:0:1}"
    last_char="${user_input: -1}"

    if [ "$first_char" == "A" ] && [ "$last_char" == "Z" ]; then
        echo "The string starts with 'A' and ends with 'Z'."
    else
        echo "The string does not meet the specified criteria."
    fi
}

read -p "Enter a string: " user_input
check_string "$user_input"
