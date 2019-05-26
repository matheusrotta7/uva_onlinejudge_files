#include<bits/stdc++.h>

using namespace std;


int main () {

    vector<int> dwarves(9);
    vector<int> dwarves_copy(9);
    for (int i = 0; i < 9; i++) {
        int cur;
        cin >> cur;
        dwarves[i] = cur;
        dwarves_copy[i] = cur;
    }
    int fake1, fake2;
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            dwarves[i] = 0;
            dwarves[j] = 0;
            int sum = 0;
            for (int k = 0; k < 9; k++) {
                sum += dwarves[k];
            }
            if (sum == 100) {
                fake1 = i;
                fake2 = j;
                goto end;
            }
            dwarves[i] = dwarves_copy[i];
            dwarves[j] = dwarves_copy[j]; //restore ancient values
        }
    }
    end:
    for (int i = 0; i < 9; i++) {
        if (i == fake1 || i == fake2) {
            continue;
        }
        cout << dwarves_copy[i] << '\n';
    }




    return 0;
}
