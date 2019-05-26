#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, q;
    cin >> n >> q;

    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        values[i] = cur;
    }

    for (int j = 0; j < q; j++) {
        int query;
        cin >> query;

        auto low = lower_bound(values.begin(), values.end(), query);
        if (*low == query) {
            cout << low - values.begin() << '\n';
        }
        else {
            cout << "-1" << '\n';
        }
    }

    return 0;
}
