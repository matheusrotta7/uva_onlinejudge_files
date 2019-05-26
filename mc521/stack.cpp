#include <bits/stdc++.h>

using namespace std;

int main () {

    int val = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == '-') {
            if (val > 0)
                val--;
        }
        else if (op == '+') {
            val++;
        }
        else {
            cout << "error\n";
        }
    }

    cout << val << '\n';



    return 0;
}
