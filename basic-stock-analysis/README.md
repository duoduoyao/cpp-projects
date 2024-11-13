# Stock Data and the STL

This project uses C++ for basic stock data processing and analysis, reading daily stock data from CSV files into a structured format managed by a flexible StockData class. It computes daily returns and performs key descriptive statistics, such as average daily returns and the largest gains and losses, leveraging STL functions like accumulate, max_element, and min_element. While this serves as a basic financial data analysis tool, it can also act as a foundation for future enhancements.

Daily stock data in CSV format where the data
files look like - 
```
Date,Open,High,Low,Close,Volume
10/02/2023,171.22,174.3,170.93,173.75,52164539
10/03/2023,172.26,173.63,170.82,172.4,49594609
10/04/2023,171.09,174.21,170.97,173.66,53020289
```

### Description for each file:
1. __StockData.hpp__ declares a StockData class to track individual records
   from a file. Note that this class as a static method (i.e., the method
   belongs to the class) to create a StockData object from a string.
2. __StockData.cpp__ implements the StockData class.
3. __stringutility.hpp__ declares a function that splits apart a string by a delimiter.
4. __stringutility.cpp__ implements the the `splitline()` function.
5. __stock.cpp__ provides the main function. You'll implement the assignment 
  functionality in this file.
6. __Makefile__ generates the stock executable.
7. __appl_202310.csv__ contains Apple's stock data from October 2023.

### Building and Running Projects
	1.	Navigate to the basic-stock-analysis directory: cd basic-stock-analysis
	2.	Build the project using the provided Makefile (if applicable): make
	3.	Run the executable: ./stock appl_202310.csv

### The results(standard output) as follows:
Average Daily Return: -0.08%
Largest Gain: 1.48% on 20231006
Largest Loss: -2.46% on 20231026

### STL functions:
- [accumulate()](https://en.cppreference.com/w/cpp/algorithm/accumulate)
- [max_element()](https://en.cppreference.com/w/cpp/algorithm/max_element)
- [min_element()](https://en.cppreference.com/w/cpp/algorithm/min_element)
- [begin()](https://en.cppreference.com/w/cpp/iterator/begin) 
- [end()](https://en.cppreference.com/w/cpp/iterator/end)
- [std::distance](https://en.cppreference.com/w/cpp/iterator/distance)
