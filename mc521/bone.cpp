#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;


    vector<bool> holes(n+1, false); //false if there is no hole
    //n+1 to index directly

    int last_pos = 1; //last place the bone was

    for (int i = 0; i < m; i++) {
        int pos;
        scanf("%d", &pos);
        holes[pos] = true;
    }
    if (holes[1] == true) { //then the bone falls prematurely into hole no 1
        cout << '1';
        goto end;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d\n", &a, &b);
        if (last_pos == a) {
            last_pos = b;
        }
        else if (last_pos == b) {
            last_pos = a;
        }

        if (holes[last_pos] == true) {
            cout << last_pos;
            goto end;
        }
    }
    cout << last_pos;
    end:
    return 0;
}
