#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    bool b = true; // begin
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') cout << c;
        else
            printf("%c", c-7);
    }

    return 0;
}
