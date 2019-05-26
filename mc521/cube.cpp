#include<bits/stdc++.h>

using namespace std;



int main() {


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int area;
        cin >> area;

        cout << (int) sqrt(area/6) << '\n';
    }



    return 0;
}
