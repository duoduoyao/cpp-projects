#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "StockData.hpp"

// Function to open a file
std::ifstream openFile(std::string name) { 
    std::ifstream in(name);
    if (!in.is_open()) {
        std::cerr << "Unable to open " << name << std::endl;
        exit(EXIT_FAILURE);  // since we are in function, return would go back to main
    }
    return in;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " stockDataFile\n";
        return EXIT_FAILURE;
    }

    std::ifstream inputFile = openFile(argv[1]);

    std::vector<StockData> data;
    std::string line;

    // Skip the header line
    std::getline(inputFile, line);
    // Read stock data from file
    while (std::getline(inputFile, line)) {
        data.push_back(StockData::fromString(line));
    }
    // Create a vector of daily returns
    std::vector<double> dailyReturns;
    for (size_t i = 1; i < data.size(); ++i) {
        dailyReturns.push_back(data[i].rateOfReturn(data[i - 1]));
    }
    // Compute average daily return
    double averageReturn = std::accumulate(dailyReturns.begin(), dailyReturns.end(), 0.0) / dailyReturns.size();
    // Find maximum and minimum returns
    auto max = std::max_element(dailyReturns.begin(), dailyReturns.end());
    auto min = std::min_element(dailyReturns.begin(), dailyReturns.end());

    // FInd the corresponding dates for max and min returns
    std::string maxDate = data[std::distance(dailyReturns.begin(), max) + 1].date;
    std::string minDate = data[std::distance(dailyReturns.begin(), min) + 1].date;

    // Print the results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average Daily Return: " << averageReturn << "%\n";
    std::cout << "Largest Gain: " << *max << "% on " << maxDate << "\n";
    std::cout << "Largest Loss: " << *min << "% on " << minDate << "\n";

    return EXIT_SUCCESS;
}