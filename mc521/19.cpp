#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> occur(26, 0);
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        int access = input[i] - 97;
        occur[access]++;
    }

    int occure, occuri, occurn, occurt;
    occurn = occur[13];
    occure = occur[4];
    occuri = occur[8];
    occurt = occur[19];
    // if (occurn <= 2) {
    //     cout << '0';
    // }
    // else {
    //     occure = occure/3;
    //     occurn = occurn/2;
    //     int min_ie = min (occure, occuri);
    //     int min_nt = min (occurt, occurn);
    //     int super_min = min (min_ie, min_nt);
    //     cout << super_min;
    //
    // }
    bool first = true;
    int num = 0;
    while (occurn != 0 && occure != 0 && occuri != 0 && occurt != 0) {
        if (first) {
            first = false;
            if (occurn >= 3)
                occurn -= 3;
            else
                goto end;

            if (occure >= 3)
                occure -= 3;
            else
                goto end;

            if (occurt >= 1)
                occurt -= 1;
            else
                goto end;

            if (occuri >= 1)
                occuri -= 1;
            else
                goto end;

            num++;
        }
        else {
            if (occurn >= 2)
                occurn -= 2;
            else
                goto end;

            if (occure >= 3)
                occure -= 3;
            else
                goto end;

            if (occurt >= 1)
                occurt -= 1;
            else
                goto end;

            if (occuri >= 1)
                occuri -= 1;
            else
                goto end;

            num++;
        }

    }
    end: cout << num;

    return 0;
}
