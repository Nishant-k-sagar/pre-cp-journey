#!/bin/bash

mkfifo user1_to_user2 user2_to_user1


user1() {
    while true; do
        read -p "User 1: " message
        echo "$message" > user1_to_user2
    done
}

user2() {
    while true; do
        read -p "User 2: " message
        echo "$message" > user2_to_user1
    done
}

user1 &
user2 &

while true; do
    if read -t 1 user1_message < user1_to_user2; then
        echo "User 1 says: $user1_message"
    fi
    if read -t 1 user2_message < user2_to_user1; then
        echo "User 2 says: $user2_message"
    fi
done

rm user1_to_user2 user2_to_user1
