
#!/bin/bash
g++ -std=c++17 -O2 -o lab3 lab3.cpp
if [ $? -eq 0 ]; then
    ./lab3 "$@"
else
    echo "Compilation failed"
fi