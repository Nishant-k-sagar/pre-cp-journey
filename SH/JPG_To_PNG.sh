#!/bin/bash

# Rename all files with the extension .jpg to have a .png extension
for file in *.jpg; do
    if [ -f "$file" ]; then
        mv "$file" "${file%.jpg}.png"
        echo "Renamed $file to ${file%.jpg}.png"
    fi
done
