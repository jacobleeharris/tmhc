#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <binary_file>"
  exit 1
fi

BINARY_FILE=$1

# Use nm to list symbols and their offsets
nm -n "$BINARY_FILE" | awk '
{
  if ($1 ~ /^[0-9a-fA-F]+$/ && $2 != "U") {
    printf "%s = 0x%s;\n", $3, $1
  }
}'
