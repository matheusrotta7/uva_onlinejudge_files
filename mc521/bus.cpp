#include <bits/stdc++.h>

using namespace std;

int main() {


    vector<string> bus(6);
    bus[0] = "+------------------------+";
    bus[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    bus[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    bus[3] = "|#.......................|";
    bus[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    bus[5] = "+------------------------+";

    int n;
    cin >> n;

    if (n <= 4) {
        for (int i = 0; i < n; i++) {
            bus[i+1][1] = 'O';
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            bus[i+1][1] = 'O';
        }
    }
    int col = 3;
    int row = 1;
    for (int i = 4; i < n; i++) {
        bus[row][col] = 'O';
        if (row != 4) {
            if (row == 2)
                row += 2;
            else
                row++;
        }
        else { //row = 4
            row = 1;
            col += 2;
        }
    }

    for (int i = 0; i < 6; i++) {
        cout << bus[i] << '\n';
    }


    return 0;
}
