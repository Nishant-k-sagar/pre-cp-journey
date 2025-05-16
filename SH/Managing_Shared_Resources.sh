#!/bin/bash

COUNTER_FILE="shared_counter.txt"

if [[ ! -f "$COUNTER_FILE" ]]; then
    echo "0" > "$COUNTER_FILE"
fi

increment_counter() {
    (
        flock -x 200
        current_value=$(<"$COUNTER_FILE")
        new_value=$((current_value + 1))
        echo "$new_value" > "$COUNTER_FILE"
    ) 200>"$COUNTER_FILE.lock"
}

for _ in {1..10}; do
    increment_counter &
done

wait

final_value=$(<"$COUNTER_FILE")
echo "Final counter value: $final_value"

rm "$COUNTER_FILE.lock"
