#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, counter = 0;
    while (scanf("%d %d", &a, &b) != EOF) {
        string c;
        cin.ignore();
        for (int i = 0; i < b; i++) getline(cin, c);
        counter++;
    }
    cout << counter << '\n';
    return 0;
}
