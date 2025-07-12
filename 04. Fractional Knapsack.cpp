//Implement the factorial knapsack problem that will
// generate an optimal solution for the given set of
// instance.

#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int weight, value;
    double ratio;
};

bool com(item &a,item &b) {
    return a.ratio > b.ratio;
}

int main() {
    int x, y, num, i;
    cout << "Enter the number of items: ";
    cin >> num;

    item items[num];
    double w, total = 0;
    cout << "Enter the maximum capacity to select items: ";
    cin >> w;
    cout << "Enter value and weight:\n";
    for (i = 0; i < num; i++) {
    cout << "Item " << i + 1 << ": ";
    cin >> x >> y;
    items[i].value = x;
    items[i].weight = y;
    items[i].ratio = (double)x / y;
  }


    sort(items, items + num, com);

    for (i = 0; i < num; i++) {
        if (items[i].weight <= w) {
            total += items[i].value;
            w -= items[i].weight; 
        } else {
            total += items[i].ratio * w;
            break;
        }
    }

    cout <<"Maximum profit: "<< total << endl;
    return 0;
}

// Result:
// Enter the number of items: 3
// Enter the maximum capacity to select items: 5
// Enter value and weight:
// Item 1: 5 3
// Item 2: 7 2
// Item 3: 4 3
// Maximum profit: 12