#include <bits/stdc++.h>

using namespace std;

int main() {

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;
        double total = 0;
        vector<int> grades;
        for (int j = 0; j < n; j++) {
            int grade;
            cin >> grade;
            grades.push_back(grade);
            total += grade;
        }
        double avg = total/(double) n;
        int above_avg = 0;
        for (int j = 0; j < n; j++) {
            if (grades[j] > avg)
                above_avg++;
        }
        double percentage = (double)above_avg/(double)n;
        percentage *= 100;

        printf("%.3lf%%\n", percentage);
    }

    return 0;
}
