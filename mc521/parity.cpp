#include<bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;

    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < n; i++) {

        int cur;
        cin >> cur;

        if (cur % 2 == 0) {
            even.push_back(cur);
        }
        else {
            odd.push_back(cur);
        }
    }

    int even_len = even.size();
    int odd_len = odd.size();
    if (abs(even_len - odd_len) <= 1) {
        cout << "0\n";
    }
    else {
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        if (even_len > odd_len) {
            bool choice = true;
            while(!odd.empty() || choice == true) {

                if (choice) {
                    choice = !choice;
                    even.pop_back();
                }
                else {
                    choice = !choice;
                    
                    odd.pop_back();
                }

            }
            int cur_len;
            cur_len = even.size();
            int sum = 0;
            for (int i = 0; i < cur_len; i++) {
                sum += even[i];
            }
            cout << sum << '\n';

        }
        else {
            bool choice = true;
            while(!even.empty() || choice == true) {

                if (choice) {
                    choice = !choice;
                    odd.pop_back();
                }
                else {
                    choice = !choice;

                    even.pop_back();
                }

            }

            int cur_len;
            cur_len = odd.size();
            int sum = 0;
            for (int i = 0; i < cur_len; i++) {
                sum += odd[i];
            }
            cout << sum << '\n';
        }
    }


    return 0;
}
