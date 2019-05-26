#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> values(n);
    vector<char> answer;


    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        values[i] = aux;
    }

    int rs = n-1;
    int ls = 0;
    int cur_max = -99999;
    int num_in_seq = 0;
    bool still_possible = true;
    while (num_in_seq < n && still_possible) {
        if (values[rs] < values[ls]) {
            //then we should prefer using rs
            if (values[rs] > cur_max) {
                //then we can use rs
                cur_max = values[rs];
                num_in_seq++;
                rs--; //right side goes to the left
                answer.push_back('R');
            }
            else {
                //then we must see if ls is bigger than cur_max
                if (values[ls] > cur_max) {
                    //then we can use ls
                    cur_max = values[ls];
                    num_in_seq++;
                    ls++; //left side goes to the right
                    answer.push_back('L');
                }
                else {
                    //if we got to this point, rs < cur_max and ls < cur_max, it is impossible to continue
                    still_possible = false;
                }
            }
        }
        else if (values[ls] < values[rs]) {
            //then we should prefer using ls
            if (values[ls] > cur_max) {
                //then we can use ls
                cur_max = values[ls];
                num_in_seq++;
                ls++; //left side goes to the right
                answer.push_back('L');
            }
            else {
                //then we must see if rs is bigger than cur_max
                if (values[rs] > cur_max) {
                    //then we can use rs
                    cur_max = values[rs];
                    num_in_seq++;
                    rs--; //right side goes to the left
                    answer.push_back('R');
                }
                else {
                    //if we got to this point, ls < cur_max and rs < cur_max, it is impossible to continue
                    still_possible = false;
                }
            }
        }
        else {
            //this is the case where ls = rs
            //must only check if last value is bigger than cur_max
            if (values[ls] > cur_max) {
                num_in_seq++;
                answer.push_back('L');
            }
            still_possible = false;
        }
    }
    printf("%d\n", num_in_seq);
    for (int i = 0; i < num_in_seq; i++) {
        printf("%c", answer[i]);
    }
    printf("\n");



    return 0;
}
