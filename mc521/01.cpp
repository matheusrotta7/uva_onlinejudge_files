#include<bits/stdc++.h>

using namespace std;

int main () {

    int a, b, c;
    //hardcodable, no need to think
    while (scanf("%d %d %d\n", &a,&b,&c) != EOF) {
        if (a == 0 && b == 0 && c == 0) {
            cout << "*\n";
        }
        else if (a == 0 && b == 0 && c == 1) {
            cout << "C\n";
        }
        else if (a == 0 && b == 1 && c == 0) {
            cout << "B\n";
        }
        else if (a == 0 && b == 1 && c == 1) {
            cout << "A\n";
        }
        else if (a == 1 && b == 0 && c == 0) {
            cout << "A\n";
        }
        else if (a == 1 && b == 0 && c == 1) {
            cout << "B\n";
        }
        else if (a == 1 && b == 1 && c == 0) {
            cout << "C\n";
        }
        else if (a == 1 && b == 1 && c == 1) {
            cout << "*\n";
        }
    }



    return 0;
}
