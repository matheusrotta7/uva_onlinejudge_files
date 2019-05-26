#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> train;
        for (int j = 0; j < m; j++) {
            int cur;
            cin >> cur;
            train.push_back(cur);
        }
        int upper = train.size()-1;
        int swaps = 0;
        while (true) {
            bool swapped = false;
            // swaps++;
            for (int j = 0; j < upper; j++) {
                if (train[j] > train[j+1]) {
                    swapped = true;
                    swaps++;
                    int temp = train[j];
                    train[j] = train[j+1];
                    train[j+1] = temp;
                }
            }
            upper--;
            if (!swapped)
                break;
        }
        cout <<"Optimal train swapping takes "<< swaps << " swaps." << '\n';
    }

    return 0;
}
