#include <iostream>
#include <ctime>
using namespace std;

// Quick Sort Partition
int Partition(int A[], int start, int end) {
    int key = A[end];
    int pi = start;
    for (int i = start; i < end; i++) {
        if (A[i] < key) {
            swap(A[i], A[pi]);
            pi++;
        }
    }
    swap(A[pi], A[end]);
    return pi;
}

// Quick Sort Recursive Function
void Quick_sort(int A[], int start, int end) {
    if (start < end) {
        int pi = Partition(A, start, end);
        Quick_sort(A, start, pi - 1);
        Quick_sort(A, pi + 1, end);
    }
}

// Bubble Sort Function
void Bubble_sort(int B[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (B[j] > B[j + 1]) {
                swap(B[j], B[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int A[n], B[n]; 

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i] = A[i]; 
    }

    // Time for Quick Sort
    clock_t start_qs = clock();
    Quick_sort(A, 0, n - 1);
    clock_t end_qs = clock();

    // Time for Bubble Sort
    clock_t start_bs = clock();
    Bubble_sort(B, n);
    clock_t end_bs = clock();

    cout <<endl << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    double time_qs = double(end_qs - start_qs) / CLOCKS_PER_SEC * 1000;
    double time_bs = double(end_bs - start_bs) / CLOCKS_PER_SEC * 1000;

    cout << endl << "Time taken by Quick Sort: " << time_qs << " ms";
    cout << endl <<"Time taken by Bubble Sort: " << time_bs << " ms"<<endl;
    return 0;
}


// Result:
// Enter the size of the array: 5
// Enter the elements: 5 4 3 2 1

// Sorted array is: 1 2 3 4 5 
// Time taken by Quick Sort: 0.003 ms
// Time taken by Bubble Sort: 0.001 ms