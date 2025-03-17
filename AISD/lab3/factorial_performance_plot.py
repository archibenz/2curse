
import matplotlib.pyplot as plt
import pandas as pd
import os

def read_factorial_data(filename="factorial_times.txt"):
    """
    Read factorial performance data from file.
    
    Parameters:
        filename (str): Path to the data file
        
    Returns:
        pandas.DataFrame: DataFrame with columns 'n', 'iterative_time', and 'recursive_time'
    """
    # Check if file exists
    if not os.path.isfile(filename):
        raise FileNotFoundError(f"File {filename} not found. Please make sure the file exists.")
    
    try:
        # Read data from file
        df = pd.read_csv(filename, sep=r'\s+', header=None, 
                         names=['n', 'iterative_time', 'recursive_time'])
        
        return df
        
    except Exception as e:
        print(f"Error reading data from {filename}: {str(e)}")
        print("Please make sure the file format is correct: each line should contain three values: n, iterative_time, recursive_time")
        raise

def plot_factorial_comparison(data):
    """
    Create and save a plot comparing factorial algorithm performance.
    
    Parameters:
        data (pandas.DataFrame): DataFrame with columns 'n', 'iterative_time', and 'recursive_time'
    """
    plt.figure(figsize=(10, 6))
    
    # Plot iterative algorithm (blue solid line with circles)
    plt.plot(data['n'], data['iterative_time'], 'o-', color='blue', linewidth=2, 
             markersize=6, label='Итеративный алгоритм')
    
    # Plot recursive algorithm (red dashed line with squares)
    plt.plot(data['n'], data['recursive_time'], 's--', color='red', linewidth=2, 
             markersize=6, label='Рекурсивный алгоритм')
    
    # Add title and labels
    plt.title('Сравнение производительности итеративного и рекурсивного алгоритмов вычисления факториала', 
              fontsize=12)
    plt.xlabel('n', fontsize=11)
    plt.ylabel('Время выполнения (мкс)', fontsize=11)
    
    # Add grid and legend
    plt.grid(True, alpha=0.3)
    plt.legend(fontsize=10)
    
    # Adjust layout
    plt.tight_layout()
    
    # Save plot
    plt.savefig('factorial_comparison.png', dpi=300)
    print("График сохранен в файл 'factorial_comparison.png'")
    
    # Display plot
    plt.show()

def main():
    """Main function to execute the program."""
    try:
        # Read data
        data = read_factorial_data()
        
        # Plot and save comparison
        plot_factorial_comparison(data)
        
    except Exception as e:
        print(f"Ошибка: {str(e)}")

if __name__ == "__main__":
    main()