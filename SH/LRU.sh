#!/bin/bash



# Function to calculate page faults using LRU algorithm

pageFaults() {

    local -a pages=("$@")

    local n=${#pages[@]}

    local capacity=4



    declare -A s

    declare -A indexes

    local page_faults=0



    for ((i=0; i<n; i++)); do

        # Check if the set can hold more pages

        if [[ ${#s[@]} -lt $capacity ]]; then

            if [[ ! ${s[${pages[i]}]} ]]; then

                s[${pages[i]}]=1

                ((page_faults++))

            fi

            indexes[${pages[i]}]=$i

        else

            if [[ ! ${s[${pages[i]}]} ]]; then

                lru=999999

                for it in "${!s[@]}"; do

                    if [[ ${indexes[$it]} -lt $lru ]]; then

                        lru=${indexes[$it]}

                        val=$it

                    fi

                done

                unset s[$val]

                s[${pages[i]}]=1

                ((page_faults++))

            fi

            indexes[${pages[i]}]=$i

        fi

    done



    echo "$page_faults"

}



# Driver code

pages=(1 3 0 3 5 6 3)

pageFaults "${pages[@]}"


make the changes in the code so that it prints replacement pages and number or replacement pages

