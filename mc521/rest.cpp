#include <bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;

    int cur_rest = 0;
    int cur_max_rest = 0;
    bool in_a_rest = false;

    vector<int> acc (2*n + 1);


    for (int i = 0; i < n; i++) {
        cin >> acc[i];
    }
    for (int i = 0; i < n; i++) {
        acc[n+i] = acc[i];
    }


    for (int i = 0; i < 2*n; i++) {
        int act; //action: work or rest
        act = acc[i];

        if (in_a_rest) {
            if (act == 0) {
                //rest is over
                cur_max_rest = max(cur_rest, cur_max_rest);
                in_a_rest = false;
                cur_rest = 0;
            }
            else {
                cur_rest++;
            }
        }
        else { //must try to start resting
            if (act == 0) {
                //cry
            }
            else {
                in_a_rest = true;
                cur_rest++;
            }
        }
    }
    cout << cur_max_rest << '\n';









    return 0;
}
