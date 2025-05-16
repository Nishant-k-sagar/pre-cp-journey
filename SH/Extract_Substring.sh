extract_substring() {
    local string=$1
    local start=$2
    local end=$3


    if ((start < 0)); then
        start=0
    fi

    if ((end >= ${#string})); then
        end=$(( ${#string} - 1 ))
    fi


    local substring="${string:start:end-start+1}"
    echo "$substring"
}


read -p "Enter a string: " input_string
read -p "Enter the starting index: " start_index
read -p "Enter the ending index: " end_index

result=$(extract_substring "$input_string" "$start_index" "$end_index")
echo "Extracted substring: \"$result\""

