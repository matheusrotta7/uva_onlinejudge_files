#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int M, C, price[25][25]; // price[g (<= 20)][model (<= 20)]
int memo[210][25]; //TOP-DOWN: dp table memo[money (<= 200)][g (<= 20)]

int shop (int money, int g) {
    if (money < 0) return -1000000000; //fail, return a large -ve number
    if (g == C) return M - money; //we have bought last garment, done
    if (memo[money][g] != -1) //TOP-DOWN: this state has been visited
        return memo[money][g]; //TOP-DOWN: simply return the value in DP memo table
    int ans = -1000000000;
    for (int model = 1; model <= price[g][0]; model++) //try all possible models
        ans = max(ans, shop(money - price[g][model], g + 1));
    return memo[money][g] = ans; //TOP-DOWN: assign ans to dp table + return it!
}

int main () {
    int i, j, TC, score;

    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &M, &C);
        for (i = 0; i < C; i++) {
            scanf("%d", &price[i][0]); //to simplify coding, store K in price[i][0]
            for (j = 1; j <= price[i][0]; j++) scanf("%d", &price[i][j]);
        }
        memset(memo, -1, sizeof memo); //TOP-DOWN: initialize DP memo table
        score = shop(M, 0); // start the top-down DP (recursive backtracking++)
        if (score < 0) printf("no solution\n");
        else printf("%d\n", score);
    }
}
