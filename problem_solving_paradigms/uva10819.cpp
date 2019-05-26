#include <bits/stdc++.h>

typedef struct item {
    int weight;
    int value;
} item;

using namespace std;

int M;
// bool used_refund;

int top_down(vector<vector<int>> &dp_table, vector<item> bag, int n, int m, bool used_refund) {
    // if (M - m > 2000 && !used_refund) {
    //     m += 200;
    //     used_refund = true;
    // }
    if (dp_table[n][m] != -1)
        return dp_table[n][m];
    else {
        int dont_take = top_down(dp_table, bag, n-1, m, used_refund);
        bool fits_budget, fits_budget_with_refund;
        fits_budget = (bag[n-1].weight <= m);
        fits_budget_with_refund = (bag[n-1].weight <= m + 200 && !used_refund && M-m+bag[n-1].weight >= 2000);

        if (!fits_budget && !fits_budget_with_refund) {
            dp_table[n][m] = dont_take;
            return dont_take;
        }
        else {
            if (!fits_budget && fits_budget_with_refund) {
                used_refund = true;
                m += 200;
            }
            int maximus = max(dont_take, top_down(dp_table, bag, n-1, m-bag[n-1].weight, used_refund) + bag[n-1].value);
            dp_table[n][m] = maximus;
            return maximus;
        }
    }
}

int main () {

    //receive input:
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        vector<item> bag(n);
        M = m;
        // used_refund = false;
        for (int i = 0; i < n; i++) {
            int weight, value;
            cin >> weight >> value;
            bag[i].weight = weight;
            bag[i].value = value;
        }

        // if (m > 1800)
        //     m += 200; //budget gets a 200 dollar increase if it exceeds 2000

        vector<vector<int>> dp_table(n+1, vector<int>(m+1, -1)); //-1 means not yet calculated
        //base case of recursion is dp_table[0, j] = 0:
        for (int i = 0; i < m+1; i++)
            dp_table[0][i] = 0;

        int max_value;
        max_value = top_down(dp_table, bag, n, m, false);
        cout << max_value << '\n';
    }

    return 0;
}
