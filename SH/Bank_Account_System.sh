#!/bin/bash

ACCOUNT_FILE="account_balance.txt"
echo "1000" > "$ACCOUNT_FILE" 

deposit() {
    local amount=$1
    (
        flock -x 200
        current_balance=$(<"$ACCOUNT_FILE")
        new_balance=$((current_balance + amount))
        echo "$new_balance" > "$ACCOUNT_FILE"
    ) 200>"$ACCOUNT_FILE.lock"
}

withdraw() {
    local amount=$1
    (
        flock -x 200
        current_balance=$(<"$ACCOUNT_FILE")
        if ((current_balance >= amount)); then
            new_balance=$((current_balance - amount))
            echo "$new_balance" > "$ACCOUNT_FILE"
        else
            echo "Insufficient balance!"
        fi
    ) 200>"$ACCOUNT_FILE.lock"
}

deposit 200
withdraw 100
deposit 50

current_balance=$(<"$ACCOUNT_FILE")
echo "Current balance: $current_balance"
