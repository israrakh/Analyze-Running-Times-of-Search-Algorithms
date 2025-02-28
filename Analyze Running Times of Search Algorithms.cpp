// Analyze Running Times of Search Algorithms.cpp
// Recursive and Iterative Binary seach, Sequential search algorithms

#include <iostream>
#include <vector>
#include <algorithm> //This is for sort

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
    //Creatting and populate the vector
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    //Sort the vector
    sort(arr.begin(), arr.end());

    //Targets to search
    int target1 = 5; //Present in the list
    int target2 = 12; //Not present in the list

    cout << "Contents of vector: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    //Recursive Binary Search
    int index = recursiveBinarySearch(arr, target1, 0, arr.size() - 1);
    cout << "Recursive Binary Search:" << endl;
    if (index != -1) {
        cout << "Target " << target1 << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target1 << " was not found, return value is " << index << endl;
    }

    index = recursiveBinarySearch(arr, target2, 0, arr.size() - 1);
    if (index != -1) {
        cout << "Target " << target2 << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target2 << " was not found, return value is " << index << endl;
    }

    //Iterative Binary Search
    index = iterativeBinarySearch(arr, target1);
    cout << "Iterative Binary Search:" << endl;
    if (index != -1) {
        cout << "Target " << target1 << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target1 << " was not found, return value is " << index << endl;
    }

    index = iterativeBinarySearch(arr, target2);
    if (index != -1) {
        cout << "Target " << target2 << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target2 << " was not found, return value is " << index << endl;
    }

    //Sequential Search
    index = sequentialSearch(arr, target1);
    cout << "Sequential Search:" << endl;
    if (index != -1) {
        cout << "Target " << target1 << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target1 << " was not found, return value is " << index << endl;
    }

    index = sequentialSearch(arr, target2);
    if (index != -1) {
        cout << "Target " << target2 << " found at index: " << index << endl;
    }
    else {
        cout << "Target " << target2 << " was not found, return value is " << index << endl;
    }

    return 0;
}
