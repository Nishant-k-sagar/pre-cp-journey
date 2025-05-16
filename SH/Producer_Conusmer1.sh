#!/bin/bash


data_file="/tmp/data.txt"


> "$data_file"


producer() {
    for i in {1..10}; do
  
        data="Data $i"

     
        exec 200>>"$data_file"
        flock -x 200

        echo "$data" >> "$data_file"

       
        flock -u 200

        echo "Producer wrote: $data"
        sleep 1
    done
}


consumer() {
    while true; do

        exec 200<"$data_file"
        flock -x 200

       
        while read -r line; do
            echo "Consumer read: $line"
           

           
            sed -i '1d' "$data_file"
        done < "$data_file"

     
        flock -u 200

        sleep 2
    done
}


producer &
producer_pid=$!

consumer &
consumer_pid=$!

wait $producer_pid
wait $consumer_pid