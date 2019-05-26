#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> emp;
        emp.push_back(a);
        emp.push_back(b);
        emp.push_back(c);
        sort(emp.begin(), emp.end());
        cout << "Case " << i+1 << ": " << emp[1] << '\n';
    }

    return 0;
}
