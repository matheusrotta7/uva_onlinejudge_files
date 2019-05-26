#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int savea, saveb, savec, saved;
        savea = a;
        saveb = b;
        savec = c;
        saved = d;
        int only_possible_score;
        if (d == 0) {
            int min_3_ = min (b, c);
            min_3_ = min (min_3_, a);
            only_possible_score = a*a + b*b + c*c + 7*min_3_;
            cout << only_possible_score << '\n';
            continue;
        }


        //separar em duas heuristicas (se for um meio termo, ferrou)
        //maximiza potencia 2:
        int score_heu_1;
        int max_card;
        if (a > b) {
            if (a > c) {
                //a é a maior
                a += d;
            }
            else {
                c += d;
            }
        }
        else {
            if (b > c) {
                b += d;
            }
            else {
                c += d;
            }
        }
        int min_3 = min (b, c);
        min_3 = min (min_3, a);
        score_heu_1 = a*a + b*b + c*c + 7*min_3;

        a = savea;
        b = saveb;
        c = savec;
        // d = saved;


        //maximiza minimo:
        while (d > 0) {

            if (a < b) {
                if (a < c) {
                    //a é menor
                    a += 1;
                }
                else {
                    c += 1;
                }
            }
            else {
                if (b < c) {
                    b += 1;
                }
                else {
                    c += 1;
                }
            }
            d--;
        }
        int min_3new = min (b, c);
        min_3new = min (min_3new, a);
        int score_heu_2 = a*a + b*b + c*c + 7*min_3new;
        cout << max(score_heu_1, score_heu_2) << '\n';
    }

    return 0;
}
