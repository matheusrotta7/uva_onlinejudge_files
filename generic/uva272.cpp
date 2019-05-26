#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    bool b = true; // begin
    while (scanf("%c", &c) != EOF) {
        if (c == '"') {
            if (b) {
                cout << "``";
                b = !b;
            }
            else {
                cout << "''";
                b = !b;
            }
        }
        else cout << c;
    }

    return 0;
}
