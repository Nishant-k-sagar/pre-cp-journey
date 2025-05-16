get_grade() {
    
    read -p "Enter the student's marks: " marks

    
    if [ "$marks" -ge 90 ] && [ "$marks" -le 100 ]; then
        echo "Grade: A"
    elif [ "$marks" -ge 80 ] && [ "$marks" -le 89 ]; then
        echo "Grade: B"
    elif [ "$marks" -ge 70 ] && [ "$marks" -le 79 ]; then
        echo "Grade: C"
    elif [ "$marks" -ge 60 ] && [ "$marks" -le 69 ]; then
        echo "Grade: D"
    else
        echo "Grade: F"
    fi
}


get_grade
