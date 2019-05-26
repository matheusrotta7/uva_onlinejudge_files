#include<bits/stdc++.h>

using namespace std;

// int sol = 0;

vector<vector<bool>> occupy(vector<vector<bool>> board, int i, int j) {
    int a, b, c;
    int min_ = min(i, j);
    int its = 8 - abs(i-j);
    for (a = i-min_, b = j-min_, c = 0; c < its; a++, b++, c++) {
        board[a][b] = true;
    }
    for (a = i, b = 0; b < 8; b++) {
        board[a][b] = true;
    }
    for (a = 0, b = j; a < 8; a++) {
        board[a][b] = true;
    }
    for (a=i, b=j; a < 8 && b >= 0; a++, b--) {
        board[a][b] = true;
    }
    for (a=i, b=j; b < 8 && a >= 0; a--, b++) {
        board[a][b] = true;
    }
    return board;
}



void find_solutions(vector<vector<bool>> board, vector<vector<int>> &solutions, int c, vector<int> cur_sol) {
    if (c == 8) {
        solutions.push_back(cur_sol);
        // cout << "Found solution #" << sol++ << '\n';
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (!board[i][c]) {
            cur_sol[c] = i+1;
            vector<vector<bool>> aux_board = occupy(board, i, c);
            find_solutions(aux_board, solutions, c+1, cur_sol);
        }
    }
}

int main () {

    vector<vector<int>> solutions;
    vector<vector<bool>> board(8, vector<bool>(8, false));
    vector<int> cur_sol(8, -1);

    for (int i = 0; i < 8; i++) {
        if (!board[i][0]) {
            cur_sol[0] = i+1;
            vector<vector<bool>> aux_board = occupy(board, i, 0);
            find_solutions(aux_board, solutions, 1, cur_sol);
        }
    }
    // cout << solutions.size() << '\n';
    int naruto = 1;
    int ss = solutions.size();
    vector<int> cur(8);
    while (scanf("%d %d %d %d %d %d %d %d", &cur[0], &cur[1], &cur[2], &cur[3], &cur[4], &cur[5], &cur[6], &cur[7]) != EOF) {
        int min_ = 10;
        for (int i = 0; i < ss; i++) {
            int num_moves = 0;
            for (int j = 0; j < 8; j++) {
                if (solutions[i][j] != cur[j])
                    num_moves++;
            }
            min_ = min(min_, num_moves);
        }
        cout << "Case " << naruto++ << ": " << min_ << '\n';
    }

    return 0;
}
