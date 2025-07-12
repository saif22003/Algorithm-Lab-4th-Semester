// Implement the 0/1 knapsack problem that will generate
// an optimal solution for the given set of instance such as
// no of elements n cost pi and weight wi.

#include <iostream>
using namespace std;

int knapsack(int index, int w, int weights[], int values[]) {
    if (index == 0) {
        if (weights[0] <= w)
            return values[0];
        else
            return 0;
    }

    int dontPick = knapsack(index - 1, w, weights, values);
    int pick = 0;
    if (weights[index] <= w)
        pick = values[index] + knapsack(index - 1, w - weights[index], weights, values);

    return max(pick, dontPick);
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter value and weight:"<<endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "Maximum value in Knapsack = " << knapsack(n - 1, W, weights, values) << endl;

    return 0;
}


// Result:
// Enter the number of items: 3
// Enter value and weight:
// Item 1: 5 7
// Item 2: 3 4
// Item 3: 5 1
// Enter the maximum weight of the knapsack: 5
// Maximum value in Knapsack = 8