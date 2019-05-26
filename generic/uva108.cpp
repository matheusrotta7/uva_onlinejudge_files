#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int cur_max = -999999999;
    for (int gb = 1; gb <= n; gb++) { //iterate over grouping numbers

        vector<vector<int>> grouped(n, vector<int>(n-gb+1));
        for (int i = 0; i < n; i++) {  //iterate over lines
            for (int j = 0; j < n-gb+1; j++) { //iterate over starting points in the line
                int sum = 0;
                for (int k = j; k < j + gb; k++) { //iterate over grouped numbers
                    sum += matrix[i][k];
                }
                grouped[i][j] = sum;
            }
        }

        //let's apply max_sum_subarray to each column
        for (int j = 0; j < n-gb+1; j++) { //iterate over columns
            cur_max = max(cur_max, grouped[0][j]);
            for (int i = 1; i < n; i++) { //iterate over lines
                grouped[i][j] = max(grouped[i][j], grouped[i][j] + grouped[i-1][j]);
                cur_max = max(cur_max, grouped[i][j]);
            }
        }
        int dummy = 0;
        dummy++;
    }
    cout << cur_max << '\n';
    return 0;
}
