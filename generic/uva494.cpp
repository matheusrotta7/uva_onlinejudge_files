#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    while (scanf("%c", &c) != EOF) {
        int counter = 0;
        while (true) {
            if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
                counter++;
                while ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
                    c = getchar();
                }
                if (c == '\n')
                    break;
            }
            else if (c == '\n')
                break;
            else {
                c = getchar();
            }

        }
        cout << counter << '\n';
    }

    return 0;
}
