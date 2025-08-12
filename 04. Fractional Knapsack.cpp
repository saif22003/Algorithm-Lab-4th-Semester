//Implement the factorial knapsack problem that will
// generate an optimal solution for the given set of
// instance.

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter the number of items: ";
    cin >> num;

    double value[num], weight[num], ratio[num];
    double capacity;

    cout << "Enter the maximum capacity: ";
    cin >> capacity;

    for (int i = 0; i < num; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> value[i] >> weight[i];
        ratio[i] = value[i] / weight[i];
    }

    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    double totalProfit = 0;

    for (int i = 0; i < num; i++) {
        if (weight[i] <= capacity) {
            totalProfit += value[i];
            capacity -= weight[i];
        } else {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}

// Result:

// Enter the number of items: 3
// Enter the maximum capacity: 5
// Item 1: 5 3
// Item 2: 7 2
// Item 3: 4 3
// Maximum profit: 12