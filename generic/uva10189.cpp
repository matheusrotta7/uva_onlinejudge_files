#include <bits/stdc++.h>

using namespace std;

#define BOMB -9999

int main() {
    int num_test = 1;
    int a, b;
    cin >> a >> b;
    int field[110][110];
    while (a != 0 && b != 0) {
        if (num_test != 1)
            cout << '\n';
        for (int i = 0; i < 110; i++) {
            for (int j = 0; j < 110; j++) field[i][j] = 0;
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                char square;
                cin >> square;
                if (square == '*') {
                    field[i][j] = BOMB;
                    for (int k = max (0, i-1); k <= min (i+1, a-1); k++) {
                        for (int l = max (0, j-1); l <= min (j+1, b-1); l++) {
                            field[k][l]++; //its ok to increment bomb value because it is very negative
                        }
                    }
                }
                else if (square == '.') {
                    //do the conga
                }
                else cout << "Something went terribly wrong\n";
            }
        }
        cout << "Field #" << num_test++ << ":\n";
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (field[i][j] < 0) cout << '*';
                else cout << field[i][j];
            }
            cout << '\n';
        }
        cin >> a >> b;
    }
    return 0;
}
