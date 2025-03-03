#!/bin/bash

echo "=========================================="
echo "Building and running search algorithms lab"
echo "=========================================="

# Check if g++ is installed locally
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler not found. Please install it."
    exit 1
fi

# Check if Python is installed
if ! command -v python3 &> /dev/null; then
    echo "Warning: Python 3 not found. Visualization will not be available."
    PYTHON_AVAILABLE=false
else
    PYTHON_AVAILABLE=true
fi

# Compile the C++ programs locally
echo "Compiling the C++ programs..."

g++ -std=c++11 -o lab2_1 lab2_1.cpp
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile lab2_1.cpp"
    exit 1
fi

g++ -std=c++11 -o lab2_2 lab2_2.cpp
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile lab2_2.cpp"
    exit 1
fi

g++ -std=c++11 -o lab2 lab2.cpp
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile lab2.cpp"
    exit 1
fi

# Run the C++ programs locally to generate data
echo "Running binary search algorithm..."
./lab2_1

echo "Running BST search algorithm..."
./lab2_2

echo "Running hash search algorithm..."
./lab2

# Now handle the Python part if Python is available
if [ "$PYTHON_AVAILABLE" = true ]; then
    echo "Would you like to create visualizations? (requires matplotlib)"
    echo "1) Yes"
    echo "2) No"
    read -p "Enter your choice (1-2): " VIZ_CHOICE
    
    if [ "$VIZ_CHOICE" == "1" ]; then
        # Try installing matplotlib if needed
        echo "Checking for required Python packages..."
        if ! python3 -c "import matplotlib" &>/dev/null; then
            echo "Matplotlib not found. Would you like to install it?"
            echo "1) Yes"
            echo "2) No"
            read -p "Enter your choice (1-2): " INSTALL_CHOICE
            
            if [ "$INSTALL_CHOICE" == "1" ]; then
                echo "Installing matplotlib..."
                python3 -m pip install matplotlib
                if [ $? -ne 0 ]; then
                    echo "Failed to install matplotlib. Skipping visualization."
                    VIZ_CHOICE="2"
                fi
            else
                echo "Skipping visualization as matplotlib is required."
                VIZ_CHOICE="2"
            fi
        fi
        
        if [ "$VIZ_CHOICE" == "1" ]; then
            echo "Running Python visualization..."
            python3 comparison-plot.py
            
            # Check if the PNGs were created
            if [ -f "search_comparison.png" ] && [ -f "search_comparison_table.png" ]; then
                echo "=========================================="
                echo "Success! Visualization created successfully."
                echo "Files:"
                echo "- search_comparison.png (График сравнения)"
                echo "- search_comparison_table.png (Таблица результатов)"
                echo "=========================================="
                
                # Try to open one of the images
                if [ "$(uname)" == "Darwin" ]; then
                    open search_comparison.png
                elif command -v xdg-open &> /dev/null; then
                    xdg-open search_comparison.png
                else
                    echo "Images are ready for viewing."
                fi
            else
                echo "Error: Failed to generate visualization."
            fi
        fi
    else
        echo "Skipping visualization as requested."
    fi
else
    echo "Python not found. Skipping visualization."
fi

# Clean up executable files
echo "Cleaning up..."
rm -f lab2_1 lab2_2 lab2

echo "Done!"