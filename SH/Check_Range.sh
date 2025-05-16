check_range() {
    number=$1

    if [ "$number" -ge 10 ] && [ "$number" -le 20 ]; then
        echo "$number is between 10 and 20 (inclusive)."
    else
        echo "$number is not between 10 and 20 (inclusive)."
    fi
}

echo "enter the number:"
read num
check_range $num
