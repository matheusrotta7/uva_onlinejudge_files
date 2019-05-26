#include<bits/stdc++.h>

using namespace std;

#define SIZE 50000
#define REPEAT 150

int main () {

    vector<int> ref(SIZE);
    ref[0] = 0;
    for (int i = 1; i < SIZE; i++) {
        ref[i] = ref[i-1] + i;
        // cout << ref[i] << '\n';
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1 || x == 2) {
            cout << "No\n";
            continue;
        }
        auto lb = lower_bound(ref.begin(), ref.end(), x);
        int lbound = *lb;
        if (lbound == x) {
            cout << "Yes\n";
            continue;
        }
        else {
            bool found = false;
            if (lbound - 1 == x) {
                cout << "Yes\n";
                goto foundit;
            }
            int sum = 0;
            for (int j = 1; j < SIZE; j++) {
                sum += ref[j];
                if (lbound - sum == x) {
                    cout << "Yes\n";
                    found = true;
                    goto foundit;
                }
                else if (lbound - sum < x) {
                    break;
                }
            }

            for (int rep = 0; rep < REPEAT; rep++) {
                sum = 0;
                lb = next(lb, 1);
                lbound = *lb;
                for (int j = 1; j < SIZE; j++) {
                    sum += ref[j];
                    if (lbound - sum == x) {
                        cout << "Yes\n";
                        goto foundit;
                    }
                    else if (lbound - sum < x) {
                        break;
                    }
                }

            }




        }
        cout << "No\n";
        foundit:
        int dummy = 42;
    }


    return 0;
}
