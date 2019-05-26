#include<bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;
    vector<int> binary;
    bool started = false;
    for (int i = 29; i >= 0; i--) {
        // int cur_bit;
        if (n >= pow(2, i)) {
            if (!started){
                started = true;
            }
            binary.push_back(1);
            n -= (int) pow(2, i);
        }
        else if (started) {
            binary.push_back(0);
        }
    }

    int b_size = binary.size();
    int acc = 0;
    for (int i = b_size-1; i >= 0; i--) {
        acc += ((int) pow(2, i))*binary[i];
    }
    cout << acc;


    return 0;
}
