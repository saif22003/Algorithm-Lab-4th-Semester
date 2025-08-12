// 09. Sum of Subset.cpp
// # Find all subsets of a set that sum to a given target

#include <iostream>
using namespace std;

const int MAX = 100;

void sumOfSubsets(int set[], int subset[], int n, int index, int subsetSize, int currentSum, int target) {
    if (currentSum == target) {
        cout << "{ ";
        for (int i = 0; i < subsetSize; i++)
            cout << subset[i] << " ";
        cout << "}" << endl;
        return;
    }

    if (index == n || currentSum > target)
        return;

    subset[subsetSize] = set[index];
    
    sumOfSubsets(set, subset, n, index, subsetSize + 1, currentSum + set[index], target);

    sumOfSubsets(set, subset, n, index + 1, subsetSize, currentSum, target);
}

int main() {
    int n, target;
    int set[MAX], subset[MAX];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> set[i];

    cout << "Enter target sum: ";
    cin >> target;

    cout << "\nSubsets with sum " << target <<endl;
    sumOfSubsets(set, subset, n, 0, 0, 0, target);
    cout << endl << endl;

    return 0;
}



//Result:

// Enter number of elements: 4 
// Enter the elements:
// 2 4 6 10
// Enter target sum: 16

// Subsets with sum 16
// { 2 2 2 2 2 2 2 2 }
// { 2 2 2 2 2 2 4 }
// { 2 2 2 2 2 6 }
// { 2 2 2 2 4 4 }
// { 2 2 2 4 6 }
// { 2 2 2 10 }
// { 2 2 4 4 4 }
// { 2 2 6 6 }
// { 2 4 4 6 }
// { 2 4 10 }
// { 4 4 4 4 }
// { 4 6 6 }
// { 6 10 }