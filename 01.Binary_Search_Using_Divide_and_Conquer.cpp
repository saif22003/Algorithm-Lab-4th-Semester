#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int item) {
    if (low > high)
        return -1;  

    int mid = (low + high) / 2;

    if (arr[mid] == item)
        return mid;  
    else if (item < arr[mid])
        return binarySearch(arr, low, mid - 1, item);  // Search left half
    else
        return binarySearch(arr, mid + 1, high, item); // Search right half
}

int main() {
    int n,i,item;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element want to search: ";
    cin>>item;
  

    int result = binarySearch(arr, 0, n , item);

    if (result != -1)
        cout << "Element found at index " << result <<" [Indexing starts from 0]."<< endl;
    else
        cout << "Element not found" << endl;

    return 0;
}