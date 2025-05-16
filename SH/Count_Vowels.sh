count_vowels() {
    local string=$1
    local vowels="aeiouAEIOU"
    local count=0

    for ((i = 0; i < ${#string}; i++)); do
        char="${string:i:1}"
        if [[ "$vowels" == *"$char"* ]]; then
            count=$((count + 1))
        fi
    done

    echo $count
}


read -p "Enter a string: " input_string
result=$(count_vowels "$input_string")
echo "Number of vowels in \"$input_string\": $result"

