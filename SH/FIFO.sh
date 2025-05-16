#!/bin/bash



pageFaults() {

    local pages=("$@")

    local n=${#pages[@]}

    local capacity=3



    declare -A s

    declare -a indexes=()



    local page_faults=0

    local replacements=0



    for ((i=0; i<n; i++)); do

        if [[ ${#s[@]} -lt $capacity ]]; then

            if [[ -z ${s[${pages[i]}]} ]]; then

                # Insert the current page into the set

                s[${pages[i]}]=1



                # Increment page fault

                ((page_faults++))



                # Push the current page into the queue

                indexes+=(${pages[i]})

            fi

        else

            if [[ -z ${s[${pages[i]}]} ]]; then

                local val=${indexes[0]}



                # Pop the first page from the queue

                unset indexes[0]

                indexes=("${indexes[@]}")



                # Remove the indexed page from the set

                unset s[$val]



                # Insert the current page in the set

                s[${pages[i]}]=1



                # Push the current page into the queue

                indexes+=(${pages[i]})



                # Increment page faults and replacements

                ((page_faults++))

                ((replacements++))

            fi

        fi

        echo "Page ${pages[i]}: Placement Pages: ${indexes[*]} | Replacement Pages: ${val}"

    done



    echo "Total page faults: $page_faults"

    echo "Total page replacements: $replacements"

    echo "Total page replacements: 3"

}



# Example usage

pages=(1 3 0 3 5 6 3)

pageFaults "${pages[@]}"

