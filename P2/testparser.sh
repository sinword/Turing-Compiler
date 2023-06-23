for file in ./input/*.t; do
    echo "$file"
    ./parser < "$file"
done
