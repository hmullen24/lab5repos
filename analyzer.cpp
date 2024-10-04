//
// Created by harrison mullen on 10/3/24.
//

#include <iostream>
#include <ostream>

#include "StringData.h"

class Searches {
public:
    int linearSearch(const std::vector<std::string> container, const std::string element) {
        int indexResult = -1 ;
        for (int i = 0; i < container.size(); i++) {
            if (container[i] == element) {
                indexResult = i ;
                break ;
            }
        }
        return indexResult ;
    }

    int binarySearch(const std::vector<std::string> container, const std::string element) {
        int indexResult = -1 ;
        int lowIndex = 0 ;
        int highIndex = container.size() - 1 ;
        while (highIndex >= lowIndex) {
            int split = (highIndex + lowIndex) / 2 ;
            if (container[split] > element) {
                highIndex = split - 1 ;
            }
            else if (container[split] < element) {
                lowIndex = split + 1 ;
            }
            else if (container[split] == element) {
                indexResult = split ;
                break ;
            }
        }
        return indexResult ;
    }
};

int main() {
    std::vector dataSet = getStringData() ;
    Searches searches ;

    // linear search for "not_here"
    auto startTime = std::chrono::system_clock::now() ;
    int indexFound = searches.linearSearch(dataSet, "not_here") ;
    auto endTime = std::chrono::system_clock::now() ;

    double duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count() ;

    std::cout << "Linear search for 'not_here': \nIndex = " << indexFound << "\nTime: " << duration << "\n" << std::endl ;

    // binary search for "not_here"
    startTime = std::chrono::system_clock::now() ;
    indexFound = searches.binarySearch(dataSet, "not_here") ;
    endTime = std::chrono::system_clock::now() ;

    duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count() ;

    std::cout << "Binary search for 'not_here': \nIndex = " << indexFound << "\nTime: " << duration << "\n" << std::endl ;

    // linear search for "mzzzz"
    startTime = std::chrono::system_clock::now() ;
    indexFound = searches.linearSearch(dataSet, "mzzzz") ;
    endTime = std::chrono::system_clock::now() ;

    duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count() ;

    std::cout << "Linear search for 'mzzzz': \nIndex = " << indexFound << "\nTime: " << duration << "\n" << std::endl ;

    // binary search for "mzzzz"
    startTime = std::chrono::system_clock::now() ;
    indexFound = searches.binarySearch(dataSet, "mzzzz") ;
    endTime = std::chrono::system_clock::now() ;

    duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count() ;

    std::cout << "Binary search for 'mzzzz': \nIndex = " << indexFound << "\nTime: " << duration << "\n" << std::endl ;

    // linear search for "aaaaa"
    startTime = std::chrono::system_clock::now() ;
    indexFound = searches.linearSearch(dataSet, "aaaaa") ;
    endTime = std::chrono::system_clock::now() ;

    duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count() ;

    std::cout << "Linear search for 'aaaaa': \nIndex = " << indexFound << "\nTime: " << duration << "\n" << std::endl ;

    // binary search for "aaaaa"
    startTime = std::chrono::system_clock::now() ;
    indexFound = searches.binarySearch(dataSet, "aaaaa") ;
    endTime = std::chrono::system_clock::now() ;

    duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count() ;

    std::cout << "Binary search for 'aaaaa': \nIndex = " << indexFound << "\nTime: " << duration << "\n" << std::endl ;
    return 0 ;
}