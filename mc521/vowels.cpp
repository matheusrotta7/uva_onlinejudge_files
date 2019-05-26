#include <bits/stdc++.h>

using namespace std;

int main () {


    vector<string> base (5);
    base[0].append("aeiou");
    base[1].append("eioua");
    base[2].append("iouae");
    base[3].append("ouaei");
    base[4].append("uaeio");

    int lastc = -1;
    int lastd = -1;


    int k;
    cin >> k;
    bool suc = true;
    if (k < 25) {
        suc = false;
        goto skip;
    }


    // unordered_set<pair<int,int>> ver;

    //try to decompose into to numbers greater than 5
    int c, d;
    c = k;
    d = 1;
    while (d < 5) {
        for (int i = 2; i <= c-1; i++) { //naive search for divisors
            if (c % i == 0) {
                c = c/i;
                d = d*i;
                break;
            }
            else if (i == c-1) {
                suc = false;
                goto skip;
            }
        }
        if (c < 5) {
            if ((c == lastd && d == lastc) || (c == lastc && d == lastd)) {
                suc = false;
                goto skip;
            }
            else {
                lastd = d;
                lastc = c;
                int aux;
                aux = c;
                c = d;
                d = aux;

            }
        }
    }
    skip:
    if (suc) {
        int a, b;
        a = c-5;
        b = d-5;
        //print final word, must define base
        //first 5 lines:
        for (int i = 0; i < 5; i++) {
            cout << base[i];
            for (int j = 0; j < b; j++) {
                cout << 'a'; //padding with a's
            }
        }
        //final 'a' lines
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < d; j++) {
                cout << 'a';
            }
        }
        cout << '\n';
    }
    else {
        cout << "-1\n";
    }



    return 0;
}
