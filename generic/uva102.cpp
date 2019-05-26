#include <bits/stdc++.h>

using namespace std;

int main() {
    int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    while (scanf("%d %d %d %d %d %d %d %d %d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) != EOF) {
        int total = b1 + b2 + b3 + g1 + g2 + g3 + c1 + c2 + c3;
        int min;
        int bcg = total - b1 - c2 - g3;
        min = bcg;
        string res = "BCG";
        int bgc = total - b1 - g2 - c3;
        if (bgc < min) {
            min = bgc;
            res = "BGC";
        }
        int cbg = total - c1 - b2 - g3;
        if (cbg < min) {
            min = cbg;
            res = "CBG";
        }
        int cgb = total - c1 - g2 - b3;
        if (cgb < min) {
            min = cgb;
            res = "CGB";
        }
        int gbc = total - g1 - b2 - c3;
        if (gbc < min) {
            min = gbc;
            res = "GBC";
        }
        int gcb = total - g1 - c2 - b3;
        if (gcb < min) {
            min = gcb;
            res = "GCB";
        }
        cout << res << ' ' << min << '\n';
    }

    return 0;
}
