#include <bits/stdc++.h>

typedef struct item {
    int weight;
    int value;
} item;

using namespace std;

int top_down(vector<vector<int>> &dp_table, vector<item> bag, int n, int m) {

    if (dp_table[n][m] != -1)
        return dp_table[n][m];
    else {
        int dont_take = top_down(dp_table, bag, n-1, m);

        if (bag[n-1].weight > m) {
            dp_table[n][m] = dont_take;
            return dont_take;
        }
        else {
            int maximus = max(dont_take, top_down(dp_table, bag, n-1, m-bag[n-1].weight) + bag[n-1].value);
            dp_table[n][m] = maximus;
            return maximus;
        }
    }
}

int main () {

    //receive input:
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<item> bag(m);
        long int sum = 0;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            sum += num;
            bag[j].weight = num;
            bag[j].value = num;
        }

        vector<vector<int>> dp_table(m+1, vector<int>(sum/2 + 1, -1)); //-1 means not yet calculated
        //base case of recursion is dp_table[0, j] = 0:
        for (int j = 0; j < sum/2 + 1; j++)
            dp_table[0][j] = 0;

        int closer_to_half = top_down(dp_table, bag, m, sum/2);
        int complement = sum - closer_to_half;
        cout << complement - closer_to_half << '\n';
    }

    return 0;
}
