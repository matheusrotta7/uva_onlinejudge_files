#include <bits/stdc++.h>

using namespace std;

int main() {

    set<long int> s;
    long int cur = 1;
    s.insert(cur);
    auto it = s.begin();
    while (s.size() < 2000) {
        cur = *it;
        s.insert(cur*2);
        s.insert(cur*3);
        s.insert(cur*5);
        it++;
    }

    cout << "The 1500'th ugly number is " << *next(s.begin(), 1499) << ".\n";
    return 0;
}
