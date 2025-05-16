extract_and_print_emails() {
    file=$1

 
    if [ -f "$file" ]; then
        while IFS= read -r email; do
           
            if [[ "$email" == *@* ]]; then
                echo "Valid Email: $email"
            else
                echo "Invalid Email: $email"
            fi
        done < "$file"
    else
        echo "File not found: $file"
    fi
}


read -p "Enter the name of the text file: " filename


extract_and_print_emails "$filename"

