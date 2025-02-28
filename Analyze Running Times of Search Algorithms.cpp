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
    int N = 50000;
    double SumRBS = 0, SumIBS = 0, SumSeqS = 0;

    //Creating random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    //Loop over different sizes of N
    for (int size : {5000, 50000, 100000, 150000, 1000000}) {
        SumRBS = 0;
        SumIBS = 0;
        SumSeqS = 0;

        for (int i = 0; i < 10; ++i) {
            //Generating a vector with N random numbers
            vector<int> arr(size);
            for (int j = 0; j < arr.size(); ++j) {
                arr[j] = dis(gen);
            }

            //Sorting the vector
            sort(arr.begin(), arr.end());

            //Generating a random target value
            int target = dis(gen);

            //Measuring time for Recursive Binary Search
            auto start = high_resolution_clock::now();
            recursiveBinarySearch(arr, target, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();
            duration<double> durationRBS = duration_cast<microseconds>(end - start);
            SumRBS += durationRBS.count();

            //Measuring time for Iterative Binary Search
            start = high_resolution_clock::now();
            iterativeBinarySearch(arr, target);
            end = high_resolution_clock::now();
            duration<double> durationIBS = duration_cast<microseconds>(end - start);
            SumIBS += durationIBS.count();

            //Measuring time for Sequential Search
            start = high_resolution_clock::now();
            sequentialSearch(arr, target);
            end = high_resolution_clock::now();
            duration<double> durationSeqS = duration_cast<microseconds>(end - start);
            SumSeqS += durationSeqS.count();
        }

        //Printing average running times for the size of N
        cout << "For N = " << size << ":\n";
        cout << "Average Running Time for Recursive Binary Search in microseconds: " << SumRBS / 10 << endl;
        cout << "Average Running Time for Iterative Binary Search in microseconds: " << SumIBS / 10 << endl;
        cout << "Average Running Time for Sequential Search in microseconds: " << SumSeqS / 10 << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}

