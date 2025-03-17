#!/bin/bash

echo "Starting String Search Algorithm Analysis..."

# Compile the C++ code
echo "Compiling C++ code..."
g++ -o search_algorithms lab2.cpp -std=c++11 -O2

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting..."
    exit 1
fi

# Run the C++ program
echo "Running search algorithms benchmark..."
./search_algorithms

# Check if the results file exists
if [ ! -f "substring_search_results.txt" ]; then
    echo "Results file not found. Exiting..."
    exit 1
fi

# Set up Python virtual environment
echo "Setting up Python virtual environment..."

# Check if venv directory exists
if [ ! -d "venv" ]; then
    echo "Creating new virtual environment..."
    python3 -m venv venv
else
    echo "Using existing virtual environment..."
fi

# Activate the virtual environment
echo "Activating virtual environment..."
source venv/bin/activate

# Install required packages from requirements.txt
echo "Installing required Python packages..."
pip install -r requirements.txt

# Run the Python script in the virtual environment
echo "Generating plots and comparison table..."
python plot_search_results.py

# Deactivate the virtual environment
echo "Deactivating virtual environment..."
deactivate

echo "Analysis complete. Results are available in 'search_algorithms_comparison.png'"