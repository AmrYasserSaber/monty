directory="."         # Use the current directory
old_word="main.h"      # The word to replace
new_word="monty.h"     # The replacement word

# Loop through all .c files in the directory
for file in "$directory"/*.c; do
    # Check if any files match the pattern
    [ -e "$file" ] || continue
    
    # Create a backup of the original file
    cp "$file" "$file.bak"
    
    # Replace the old word with the new word in the file content
    sed -i "s/$old_word/$new_word/g" "$file"
done

echo "Word replacement complete."