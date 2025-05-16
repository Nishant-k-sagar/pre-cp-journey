#!/bin/bash

# Function to initialize the game board
initialize_board() {
    board=( " " " " " " " " " " " " " " " " " " " " " " " )
}

# Function to display the game board
display_board() {
    echo " ${board[0]} | ${board[1]} | ${board[2]} "
    echo "---|---|---"
    echo " ${board[3]} | ${board[4]} | ${board[5]} "
    echo "---|---|---"
    echo " ${board[6]} | ${board[7]} | ${board[8]} "
}

# Function to check if a player has won
check_win() {
    local player=$1
    if [[ (${board[0]} == "$player" && ${board[1]} == "$player" && ${board[2]} == "$player") ||
          (${board[3]} == "$player" && ${board[4]} == "$player" && ${board[5]} == "$player") ||
          (${board[6]} == "$player" && ${board[7]} == "$player" && ${board[8]} == "$player") ||
          (${board[0]} == "$player" && ${board[3]} == "$player" && ${board[6]} == "$player") ||
          (${board[1]} == "$player" && ${board[4]} == "$player" && ${board[7]} == "$player") ||
          (${board[2]} == "$player" && ${board[5]} == "$player" && ${board[8]} == "$player") ||
          (${board[0]} == "$player" && ${board[4]} == "$player" && ${board[8]} == "$player") ||
          (${board[2]} == "$player" && ${board[4]} == "$player" && ${board[6]} == "$player") ]]; then
        echo "Player $player wins!"
        exit
    fi
}

# Function to check if the game is a draw
check_draw() {
    for cell in "${board[@]}"; do
        if [ "$cell" == " " ]; then
            return 0 # Game is not a draw
        fi
    done
    echo "The game is a draw!"
    exit
}

# Function to get the player's move
get_move() {
    local player=$1
    echo "Player $player's turn (X or O):"
    read -p "Enter the position (1-9): " position
    if ! [[ "$position" =~ ^[1-9]$ ]]; then
        echo "Invalid position. Please enter a number between 1 and 9."
        get_move $player
    elif [ "${board[$position-1]}" != " " ]; then
        echo "Position already taken. Try again."
        get_move $player
    else
        board[$position-1]=$player
    fi
}

# Function to start the game
start_game() {
    initialize_board
    display_board
    while true; do
        get_move "X"
        display_board
        check_win "X"
        check_draw
        get_move "O"
        display_board
        check_win "O"
        check_draw
    done
}

# Start the game
start_game
