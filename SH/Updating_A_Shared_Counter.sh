#!/bin/bash


counter_file="/tmp/counter"

echo 0 > "$counter_file"


update_counter() {

    exec 200>>"$counter_file"
    flock -x 200


    counter=$(<"$counter_file")


    ((counter += 10000))

    echo "$counter" > "$counter_file"


    flock -u 200
}


num_processes=5


for ((i = 0; i < num_processes; i++)); do
    update_counter &
done


wait


final_counter=$(<"$counter_file")
echo "Final counter value: $final_counter"