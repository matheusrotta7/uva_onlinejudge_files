#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct chamber {
    int mass;
    int num_of_spec;
    vector<int> save;
} chamber;

bool compare_species (int a, int b) {
    return a < b;
}

bool compare_chambers (chamber a, chamber b) {
    return a.mass > b.mass;
}

double calculate_imbalance (vector<chamber> result, int total_mass, int c) {
    double sum = 0;
    double average = (double) total_mass/ (double) c;
    vector<chamber>::iterator it;
    for (it = result.begin(); it < result.end(); it++) {
        sum += fabs(it->mass - average);
    }
    return sum;
}


int main () {

    int c, s, iteration;
    iteration = 1;

    while (scanf("%d %d", &c, &s) != EOF) {
        vector<chamber> centrifuge;

        for (int i = 0; i < c; i++) {
            chamber new_chamber;
            new_chamber.mass = 0;
            new_chamber.num_of_spec = 0;
            centrifuge.push_back(new_chamber);
        }

        vector<int> species;
        int total_mass = 0;

        for (int i = 0; i < s; i++) {
            int mass;
            scanf("%d", &mass);
            total_mass += mass;
            species.push_back(mass);
        }

        sort (species.begin(), species.end(), compare_species);

        int index = 0;
        bool grows = true;

        while (!species.empty()) {

            centrifuge[index].mass += species.back();
            centrifuge[index].num_of_spec++;
            centrifuge[index].save.push_back(species.back());
            species.pop_back();
            if (index == c-1 && grows) {
                grows = false;
                continue;
            }
            if (grows) {
                index++;
            }
            else {
                index--;
            }
        }

        double imbalance = calculate_imbalance (centrifuge, total_mass, c);

        printf("Set #%d\n", iteration);
        vector<chamber>::iterator it;
        int aux = 0;
        for (it = centrifuge.begin(); it < centrifuge.end(); it++) {
            printf(" %d: ", aux++);
            if (it->save.size() == 2) {
                printf("%d %d\n", it->save[0], it->save[1]);
            }
            else if (it->save.size() == 1) printf("%d\n", it->save[0]);
            else printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
        iteration++;
    }

    return 0;
}
