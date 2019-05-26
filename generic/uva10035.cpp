#include <bits/stdc++.h>

using namespace std;

int main() {

    long int a, b;
    cin >> a >> b;
    while (a != 0 || b != 0) {
        vector<int> va, vb;
        while (a != 0) {
            va.insert(va.begin(), a%10);
            a /= 10;
        }
        while (b != 0) {
            vb.insert(vb.begin(), b%10);
            b /= 10;
        }
        if (va.size() > vb.size()) {
            while (vb.size() < va.size()) vb.insert(vb.begin(), 0);
        }
        else if (va.size() < vb.size()) {
            while (va.size() < vb.size()) va.insert(va.begin(), 0);
        }
        int carry = 0;
        int num_carries = 0;
        for (int i = va.size()-1; i >= 0; i--) {
            if (va[i] + vb[i] + carry > 9) {
                num_carries++;
                carry = 1;
            }
            else
                carry = 0;
        }
        if (num_carries == 0)
            cout << "No carry operation.\n";
        else if (num_carries == 1)
            cout << "1 carry operation.\n";
        else
            cout << num_carries << " carry operations.\n";

        cin >> a >> b;
    }

    return 0;
}
