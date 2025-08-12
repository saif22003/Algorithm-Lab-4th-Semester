// #Binary Search 

#include <iostream>
#include <algorithm> 
using namespace std;

int binarySearch(int arr[], int low, int high, int item) {
    if (low > high)
        return -1;  

    int mid = (low + high) / 2;

    if (arr[mid] == item)
        return mid;  
    else if (item < arr[mid])
        return binarySearch(arr, low, mid - 1, item);  
    else
        return binarySearch(arr, mid + 1, high, item); 
}

int main() {
    int n, i, item;
    cout << "Enter the size of an array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the element you want to search: ";
    cin >> item;

    int result = binarySearch(arr, 0, n - 1, item);

    if (result != -1)
        cout << "Element found at index " << result << " [Indexing starts from 0]." << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}


// Resut: 

// Enter the size of an array: 5
// Enter the elements of the array: 3 2 1 4 5
// Sorted array: 1 2 3 4 5 
// Enter the element you want to search: 3
// Element found at index 2 [Indexing starts from 0].