#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <amount_of_unique_random_numbers>"
  exit 1
fi

count=$1
min=1
max=10000

# Check if count is not greater than the range
range_size=$((max - min + 1))
if (( count > range_size )); then
  echo "Error: Cannot generate $count unique numbers between $min and $max."
  exit 1
fi

declare -A generated
random_numbers=""

while (( ${#generated[@]} < count )); do
  num=$((RANDOM % range_size + min))
  if [[ -z "${generated[$num]}" ]]; then
    generated[$num]=1
    random_numbers+="$num "
  fi
done

# Trim trailing space
random_numbers=${random_numbers% }

./push_swap ${random_numbers} | ./checker ${random_numbers}
./push_swap ${random_numbers} | wc -l
#funcheck -ac ./push_swap ${random_numbers}
./push_swap ${random_numbers}
./pushswap ${random_numbers}

echo ${random_numbers}
