#include<bits/stdc++.h>

using namespace std;

int main () {

    int n;
    cin >> n;
    vector<string> line(n);
    vector<string> save_line(n);
    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        line[i] = cur;
        save_line[i] = cur;
    }
    sort(line.begin(), line.end());
    // for (int i = 0; i < n; i++)
    //     cout << line[i] << '\n';
    vector<string> reverse_line(n);
    for (int i = 0; i < n; i++) {
        reverse_line[i] = line[n-1-i];
    }
    if (save_line == line) {
        cout << "INCREASING";
    }
    else if (save_line == reverse_line) {
        cout << "DECREASING";

    }
    else {
        cout << "NEITHER";

    }


    return 0;
}
