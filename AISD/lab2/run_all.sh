
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

# Run the Python script to generate plots and tables
echo "Generating plots and comparison table..."

# Check if tabulate is installed
python3 -c "import tabulate" &>/dev/null
if [ $? -ne 0 ]; then
    echo "Installing required Python module 'tabulate'..."
    pip3 install tabulate
fi

# Check if pandas and matplotlib are installed
python3 -c "import pandas, matplotlib" &>/dev/null
if [ $? -ne 0 ]; then
    echo "Installing required Python modules 'pandas' and 'matplotlib'..."
    pip3 install pandas matplotlib
fi

# Run the Python script
python3 plot_search_results.py

echo "Analysis complete. Results are available in 'search_algorithms_comparison.png'"