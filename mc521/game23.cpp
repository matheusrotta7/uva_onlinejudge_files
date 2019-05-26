#include<bits/stdc++.h>

using namespace std;

int main() {


    int num_of_mov = 0;
    int n, m;
    cin >> n >> m;
    if (m%n != 0) {
        cout << "-1\n";
    }
    else {
        if (n == m) {
            cout << "0\n";
        }
        else {
            int quoc = m/n;
            bool div_by_2, div_by_3;
            while ((div_by_2 = (quoc % 2 == 0)) || (div_by_3 = (quoc % 3 == 0))) {
                if (div_by_2) {
                    quoc /= 2;
                }
                else if (div_by_3) {
                    quoc /= 3;
                }
                num_of_mov++;
            }
            if (quoc == 1) {
                cout << num_of_mov << '\n';
            }
            else {
                cout << "-1\n";
            }
        }
    }








    return 0;
}
