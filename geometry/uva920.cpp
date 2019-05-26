#include<bits/stdc++.h>

using namespace std;

bool comp (pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}

double dist (int xa, int ya, int xb, int yb) {
    return sqrt(((double) xa - (double) xb)*((double) xa - (double) xb) + ((double) ya - (double) yb)*((double) ya - (double) yb));
}

int main() {

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        vector<pair<int,int>> points;
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            points.push_back(pair<int,int>(x, y));
        }

        sort(points.begin(), points.end(), comp);

        int y_max = 0;
        double red_area = 0.0;

        for (int j = 0; j < n; j += 2) {
            if (points[j+1].second > y_max) {
                int y_cut = y_max;
                int x_peak = points[j+1].first;
                int y_peak = points[j+1].second;
                int x_col = points[j].first;
                int y_col = points[j].second;
                red_area += ((double)(y_peak - y_cut))*dist(x_peak, y_peak, x_col, y_col)/((double)(y_peak - y_col));
                y_max = y_peak;
            }
        }

        printf("%.2lf\n", red_area);
    }

    return 0;
}
