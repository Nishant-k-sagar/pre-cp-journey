calculate_roots() {
    read -p "Enter the coefficient a: " a
    read -p "Enter the coefficient b: " b
    read -p "Enter the coefficient c: " c

    discriminant=$((b * b - 4 * a * c))

    if [ "$discriminant" -gt 0 ]; then
        root1=$(echo "scale=2; (-$b + sqrt($discriminant)) / (2 * $a)" | bc)
        root2=$(echo "scale=2; (-$b - sqrt($discriminant)) / (2 * $a)" | bc)
        echo "Roots are real and distinct."
        echo "Root 1: $root1"
        echo "Root 2: $root2"
    elif [ "$discriminant" -eq 0 ]; then
        root=$(echo "scale=2; -$b / (2 * $a)" | bc)
        echo "Roots are real and identical."
        echo "Root: $root"
    else
        real_part=$(echo "scale=2; -$b / (2 * $a)" | bc)
        imaginary_part=$(echo "scale=2; sqrt($((-discriminant))) / (2 * $a)" | bc)
        echo "Roots are complex conjugates."
        echo "Root 1: $real_part + i$imaginary_part"
        echo "Root 2: $real_part - i$imaginary_part"
    fi
}

calculate_roots