#!/bin/bash


red_light() {
    echo "Red Light"
    sleep 5
}


yellow_light() {
    echo "Yellow Light"
    sleep 2
}

green_light() {
    echo "Green Light"
    sleep 5
}


main() {
    while true; do
       
        red_light

        yellow_light

        
        green_light
    done
}

main &


wait