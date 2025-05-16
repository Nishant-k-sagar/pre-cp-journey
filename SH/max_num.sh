
find_max() {
    max=$1


    for num in "$@"; do
        if [ "$num" -gt "$max" ]; then
            max=$num
        fi
    done

    echo "Maximum number: $max"
}


find_max 23 56 12 78
