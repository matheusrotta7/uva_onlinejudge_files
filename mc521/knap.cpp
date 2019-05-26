#include<bits/stdc++.h>

using namespace std;

int recursive (vector<int> items, int n, weight) {
    int r;
    if ((r = recursive(items, n-1)) + items[n] <= weight) {

        return r + items[n];
    }
    else {
        return max(r, recursive(items, n-2))
    }
}

int main() {

    long int weight;
    cin >> weight;
    vector<int> items;

    int cur;
    while (scanf("%d", &cur) != EOF) {
        items.push_back(cur);
    }

    sort(items.begin(), items.end(), greater<int>());
    int n = items.size();
    recursive(items, n, weight);


    return 0;
}
