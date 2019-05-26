#include <bits/stdc++.h>

using namespace std;

int main() {

    set<int> test;
    test.insert(3);
    test.insert(3);
    test.insert(4);
    test.insert(5);
    test.insert(-34);
    cout << *(test.rbegin()) << '\n';
    return 0;
}
