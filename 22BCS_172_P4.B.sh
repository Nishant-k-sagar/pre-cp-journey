#!/bin/bash

pageFaults() {
    local pages=("$@")
    local n=${#pages[@]}
    local capacity=2

    declare -A s
    declare -a indexes=()

    local page_faults=0
    local replacements=0

    for ((i=0; i<n; i++)); do
        if [[ ${#s[@]} -lt $capacity ]]; then
            if [[ -z ${s[${pages[i]}]} ]]; then
                
                s[${pages[i]}]=1

                
                ((page_faults++))

                
                indexes+=(${pages[i]})
            fi
        else
            if [[ -z ${s[${pages[i]}]} ]]; then
                local val=${indexes[0]}

                
                unset indexes[0]
                indexes=("${indexes[@]}")

                
                unset s[$val]

              
                s[${pages[i]}]=1

                
                indexes+=(${pages[i]})

             
                ((page_faults++))
                ((replacements++))
            fi
        fi
        echo "Page ${pages[i]}: Placement Pages: ${indexes[*]} | Replacement Pages: ${val}"
    done

    echo "Total page faults: $page_faults"
    echo "Total page replacements: $replacements"
    echo "Total page placements : 3"
}

# Example usage
pages=(2 3 2 1 5 2 4 5 3 2 5 2)
pageFaults "${pages[@]}"

