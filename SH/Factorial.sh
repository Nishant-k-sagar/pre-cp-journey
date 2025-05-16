factorial() {
    if [[ $1 -eq 0 || $1 -eq 1 ]]; then
        echo 1
    else
        echo $(( $1 * $(factorial $(( $1 - 1 ))) ))
    fi
}


for ((i = 1; i <= 10; i++)); do
    echo $(factorial $i)
done

