import pandas as pd
import matplotlib.pyplot as plt
from tabulate import tabulate
import sys

def plot_search_results(csv_file='substring_search_results.txt'):
    # Read data from CSV file
    data = pd.read_csv(csv_file, sep=';')
    
    # Rename columns for display purposes
    display_data = data.copy()
    display_data.rename(columns={
        'TimeKMP(ms)': 'Binary Search(ms)', 
        'TimeBoyerMoore(ms)': 'BST Search(ms)',
        'TimeRabinKarp(ms)': 'Hash Search(ms)'
    }, inplace=True)
    
    # Create the plot
    plt.figure(figsize=(12, 6))
    
    # Plot each algorithm with smooth lines (no markers)
    plt.plot(data['StringLength'], data['TimeKMP(ms)'], 'r-', linewidth=2, label='Binary Search')
    plt.plot(data['StringLength'], data['TimeBoyerMoore(ms)'], 'g-', linewidth=2, label='BST Search')
    plt.plot(data['StringLength'], data['TimeRabinKarp(ms)'], 'b-', linewidth=2, label='Hash Search')
    
    # Add labels and title
    plt.xlabel('String Length')
    plt.ylabel('Execution Time (ms)')
    plt.title('Comparison of Search Algorithms')
    plt.legend()
    plt.grid(True)
    
    # Save and show the plot
    plt.savefig('search_algorithms_comparison.png')
    plt.tight_layout()
    plt.show()
    
    # Display comparison table
    print("\nComparison Table of Search Algorithms:\n")
    
    # Calculate the average time ratio compared to the fastest algorithm (BST)
    data['Binary_to_BST_Ratio'] = data['TimeKMP(ms)'] / data['TimeBoyerMoore(ms)']
    data['Hash_to_BST_Ratio'] = data['TimeRabinKarp(ms)'] / data['TimeBoyerMoore(ms)']
    
    # Select columns for display
    table_data = pd.DataFrame({
        'StringLength': display_data['StringLength'],
        'Binary Search(ms)': display_data['Binary Search(ms)'],
        'BST Search(ms)': display_data['BST Search(ms)'],
        'Hash Search(ms)': display_data['Hash Search(ms)'],
        'Binary/BST Ratio': data['Binary_to_BST_Ratio'],
        'Hash/BST Ratio': data['Hash_to_BST_Ratio']
    })
    
    # Round the values for better display
    table_data = table_data.round(2)
    
    # Display the table
    print(tabulate(table_data, headers='keys', tablefmt='pretty', showindex=False))
    
    # Summary statistics
    print("\nSummary Statistics:")
    print(f"Average Binary Search/BST Search ratio: {data['Binary_to_BST_Ratio'].mean():.2f}x")
    print(f"Average Hash Search/BST Search ratio: {data['Hash_to_BST_Ratio'].mean():.2f}x")
    print(f"BST Search is the fastest algorithm in this comparison.")

if __name__ == "__main__":
    # Check if a custom file path is provided
    if len(sys.argv) > 1:
        plot_search_results(sys.argv[1])
    else:
        plot_search_results()