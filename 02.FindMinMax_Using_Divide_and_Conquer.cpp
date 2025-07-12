#include <iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {
    
    if (low == high) {
       minVal = arr[low];
       maxVal = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (arr[low] < minVal) minVal = arr[low];
            if (arr[high] > maxVal) maxVal = arr[high];
        } else {
            if (arr[high] < minVal) minVal = arr[high];
            if (arr[low] > maxVal) maxVal = arr[low];
        }
        return;
    }


    int mid = (low + high) / 2;

    findMinMax(arr, low, mid, minVal, maxVal);       // Left part
    findMinMax(arr, mid + 1, high, minVal, maxVal);   // Right part
}

int main() {
    int arr[] = {10, 3, 5, 8, 1, 9, 12, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

 
    int minVal = arr[0];
    int maxVal = arr[0];

    findMinMax(arr, 0, n - 1, minVal, maxVal);

    cout << "Minimum value is: " << minVal << endl;
    cout << "Maximum value is: " << maxVal << endl;

    return 0;
}

//Resultl:
// Minimum value is: 0
// Maximum value is: 12