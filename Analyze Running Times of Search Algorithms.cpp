// Analyze Running Times of Search Algorithms.cpp
// Recursive and Iterative Binary seach, Sequential search algorithms, Random Numbers, Rate of Growth

#include <iostream>
#include <vector>
#include <algorithm> //This is for sort
#include <random> //For generating random numbers
#include <chrono> //For timing the execution

using namespace std;
using namespace chrono;

int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            return recursiveBinarySearch(arr, target, mid + 1, high);
        }
        else {
            return recursiveBinarySearch(arr, target, low, mid - 1);
        }
    }
    return -1;
}

int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    //Variables for measuring time
    int N = 150000;
    //Variables to accumulate times
    double SumRBS = 0, SumIBS = 0, SumSeqS = 0;

    //Looping 10 times to measure time for each search method
    for (int i = 0; i < 10; ++i) {
        //Generating a vector of N random numbers in the range (1, 100)
        vector<int> arr(N);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);

        for (int& num : arr) {
            num = dis(gen);
        }

        //Sorting the vector
        sort(arr.begin(), arr.end());

        //Generating a random target value between 1 and 100
        int target = dis(gen);

        //Time Recursive Binary Search
        auto start = high_resolution_clock::now();
        recursiveBinarySearch(arr, target, 0, arr.size() - 1);
        auto stop = high_resolution_clock::now();
        duration<double> durationRBS = stop - start;
        SumRBS += durationRBS.count() * 1000000;  // Convert to microseconds

        //Time Iterative Binary Search
        start = high_resolution_clock::now();
        iterativeBinarySearch(arr, target);
        stop = high_resolution_clock::now();
        duration<double> durationIBS = stop - start;
        SumIBS += durationIBS.count() * 1000000;  // Convert to microseconds

        //Time Sequential Search
        start = high_resolution_clock::now();
        sequentialSearch(arr, target);
        stop = high_resolution_clock::now();
        duration<double> durationSeqS = stop - start;
        SumSeqS += durationSeqS.count() * 1000000;  // Convert to microseconds
    }

    //Printing the average times for each search method
    cout << "Average Running Time for Recursive Binary Search in microseconds: " << SumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds: " << SumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Search in microseconds: " << SumSeqS / 10 << endl;


    return 0;
}

