#!/bin/bash

# Define the Morse code mapping
declare -A morse_code=(
    ['A']='.-' ['B']='-...' ['C']='-.-.' ['D']='-..'  ['E']='.'
    ['F']='..-.' ['G']='--.'  ['H']='....' ['I']='..'   ['J']='.---'
    ['K']='-.-' ['L']='.-..' ['M']='--'   ['N']='-.'   ['O']='---'
    ['P']='.--.' ['Q']='--.-' ['R']='.-.' ['S']='...'  ['T']='-'
    ['U']='..-' ['V']='...-' ['W']='.--'  ['X']='-..-' ['Y']='-.--'
    ['Z']='--..' ['1']='.----' ['2']='..---' ['3']='...--' ['4']='....-' 
    ['5']='.....' ['6']='-....' ['7']='--...' ['8']='---..' ['9']='----.' 
    ['0']='-----' [' ']='/' ['.']='.-.-.-' [',']='--..--' ['?']='..--..'
    ['!']='-.-.--' ['\']='.-..-.' ['/']='-..-.' ['(']='-.--.' [')']='-.--.-'
)

# Function to translate text to Morse code
text_to_morse() {
    local text="$1"
    local morse=""
    local len=${#text}
    for (( i=0; i<len; i++ )); do
        char="${text:$i:1}"
        morse+=" ${morse_code[$char]}"
    done
    echo "$morse"
}

# Function to translate Morse code to text
morse_to_text() {
    local morse="$1"
    local text=""
    local morse_array=($morse)
    for code in "${morse_array[@]}"; do
        for key in "${!morse_code[@]}"; do
            if [[ "${morse_code[$key]}" == "$code" ]]; then
                text+="$key"
            fi
        done
    done
    echo "$text"
}

# Prompt the user for input
read -p "Enter 'text' to convert to Morse code or Morse code to convert to 'text': " input

# Check if the input is Morse code or text and perform the translation
if [[ "$input" == *"."* || "$input" == *"-"* ]]; then
    translated_text=$(morse_to_text "$input")
    echo "Translated Morse code to text: $translated_text"
else
    translated_morse=$(text_to_morse "$input")
    echo "Translated text to Morse code: $translated_morse"
fi
