#include<bits/stdc++.h>

using namespace std;

// #define MAX_SIZE 500010
// #define MODULO 100000007

int main () {


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        string cur;
        cin >> cur;

        int len = cur.size();
        if (len > 26) {
            cout << "No\n";
            goto carry_on;
        }
        else {
            vector<int> count(26, 0);
            for (int j = 0; j < len; j++) {
                int check = ++count[cur[j]-97];
                if (check > 1) {
                    cout << "No\n";
                    goto carry_on;
                }
            }
            // bool
            for (int j = 0; j < 26; j++) {
                if (count[j] == 1) {
                    //found first 1
                    for (int k = j+1; k < 26; k++) {
                        if (count[k] == 0) {
                            //found first 0, all from here MUST be 0
                            for (int l = k+1; l < 26; l++) {
                                if (count[l] == 1) {
                                    cout << "No\n";
                                    goto carry_on;
                                }
                            }
                        }
                    }

                }
            }

        }
        // cout << "Yes" << i << '\n';
        cout << "Yes\n";
        // goto carry_on;
        // goto carry_on;
        int dummy;
        carry_on:
        dummy = 42;


    }

    return 0;
}
