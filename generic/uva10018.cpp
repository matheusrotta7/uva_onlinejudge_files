#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        int num_iterations = 1;
        while (true) {
            vector<int> va;
            int counter = 0;
            long int save_a = a;
            while (a != 0) {
                counter++;
                va.push_back(a%10);
                a /= 10;
            }//123 ---> 321
            counter--;
            long int reverse_a = 0;
            for (int j = 0; j < va.size(); j++) {
                reverse_a += va[j]*(long int)pow(10, counter--);
            }
            long int sum = save_a + reverse_a;
            long int save = sum;
            // counter = 0;
            vector<int> vsum;
            while (sum != 0) {
                // counter++;
                vsum.push_back(sum%10);
                sum /= 10;
            }
            if ((vsum.size() % 2) == 0) {
                vector<int> first_half (vsum.begin(), vsum.begin() + vsum.size()/2);
                vector<int> second_half (vsum.begin() + vsum.size()/2, vsum.end());
                bool equal = true;
                int sh_size = second_half.size();
                for (int j = 0; j < first_half.size(); j++) {
                    if (first_half[j] != second_half[sh_size-1-j])
                        equal = false;
                }
                if (equal) {
                    cout << num_iterations << ' ' << save << '\n';
                    break;
                }

            }
            else {
                vector<int> first_half(vsum.begin(), vsum.begin() + vsum.size()/2);
                vector<int> second_half(vsum.begin() + vsum.size()/2 + 1, vsum.end());
                bool equal = true;
                int sh_size = second_half.size();
                for (int j = 0; j < first_half.size(); j++) {
                    if (first_half[j] != second_half[sh_size-1-j])
                        equal = false;
                }
                if (equal) {
                    cout << num_iterations << ' ' << save << '\n';
                    break;
                }
            }
            num_iterations++;
            a = save;
        }
    }

    return 0;
}
