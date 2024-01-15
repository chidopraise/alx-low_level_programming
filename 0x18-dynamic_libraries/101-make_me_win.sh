#!/bin/bash

# Check if steghide is installed
if ! command -v steghide &> /dev/null; then
    echo "Error: steghide is not installed. Please install it first."
    exit 1
fi

# Check if the correct number of arguments is provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <lsb_file> <output_file> <passphrase>"
    exit 1
fi

# Extract data using steghide
lsb_file="$1"
output_file="$2"
passphrase="$3"

# Run steghide with the provided arguments
steghide extract -sf "$lsb_file" -xf "$output_file" -p "$passphrase"

# Check the exit code of steghide
if [ $? -eq 0 ]; then
    echo "LSB file successfully decoded."
else
    echo "Error: Failed to decode LSB file."
fi
