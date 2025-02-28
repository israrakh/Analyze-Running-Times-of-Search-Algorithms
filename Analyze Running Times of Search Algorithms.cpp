// Analyze Running Times of Search Algorithms.cpp
// Recursive and Iterative Binary seach, Sequential search algorithms, Random Numbers

#include <iostream>
#include <vector>
#include <algorithm> //This is for sort
#include <random> //For generating random numbers

using namespace std;

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
    //Creatting a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100); //Random numbers between 1 and 100

    //Filling the vector with random numbers
    vector<int> arr(10);  //Adjusting size as needed
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = dis(gen);
    }

    //Sorting the vector
    sort(arr.begin(), arr.end());

    //Generate a random target value
    int target = dis(gen); //Random target in the same range (1 to 100)

    //Printing the contents of the vector and the random target value
    cout << "Contents of vector: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Randomly generated target: " << target << endl;

    //Performming searches using the three search methods

    //Recursive Binary Search
    int index = recursiveBinarySearch(arr, target, 0, arr.size() - 1);
    cout << "Recursive Binary Search:" << endl;
    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target << " was not found, return value is " << index << endl;
    }

    //Iterative Binary Search
    index = iterativeBinarySearch(arr, target);
    cout << "Iterative Binary Search:" << endl;
    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target << " was not found, return value is " << index << endl;
    }

    //Sequential Search
    index = sequentialSearch(arr, target);
    cout << "Sequential Search:" << endl;
    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target << " was not found, return value is " << index << endl;
    }

    return 0;
}

