#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
    Item(int p, int w) : profit(p), weight(w) {}
};

bool cmp(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

double fractionalKnapsack(int W, Item arr[], int N) {
    sort(arr, arr + N, cmp);
    double finalValue = 0.0;
    for (int i = 0; i < N && W > 0; ++i) {
        
        int take = min(W, arr[i].weight);
        finalValue += (double)take / arr[i].weight * arr[i].profit;
        W -= take;
    }
    return finalValue;
}

int main() {
    int W = 50;
    Item arr[] = {{50, 10}, {90, 20}, {100, 30}};
    int N = 3;
    std::cout << fractionalKnapsack(W, arr, N);
    return 0;
}
