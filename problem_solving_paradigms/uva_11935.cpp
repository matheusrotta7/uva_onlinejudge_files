#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

typedef struct instance {
    int d;
    int n;
    int l;
    bool is_goal;
    bool is_gas_station;
} instance;

using namespace std;

double calculate_consumption (int d, int n, int l) {
    return (((double) d*n)/100.0) + (double) l*d;
}

int main () {
    while (1) {

        vector<instance> desert;

        int fc, dummy;
        char dummy_string[50];
        scanf("%d %s %s %d", &dummy, dummy_string, dummy_string, &fc);

        if (fc == 0) break;

        instance first_inst;
        first_inst.n = fc;
        first_inst.l = 0;
        first_inst.is_goal = false;
        first_inst.is_gas_station = false;
        //distance is not yet defined

        desert.push_back(first_inst);

        int current_position = 0;

        while (1) {
            int event_position;
            scanf("%d", &event_position);
            char buffer[50];

            if (event_position == current_position) {

                scanf("%s", buffer);

                if (strcmp (buffer, "Leak") == 0) {
                    desert.back().l++;
                }
                else if (strcmp (buffer, "Mechanic") == 0) {
                    desert.back().l = 0;
                }
                else if (strcmp (buffer, "Goal") == 0) {
                    desert.back().is_goal = true;
                    break;
                }
                else if (strcmp (buffer, "Fuel") == 0) {
                    int new_fc;
                    char dummy[50];
                    scanf("%s %d", dummy, &new_fc);
                    desert.back().n = new_fc;
                }
                else if (strcmp (buffer, "Gas") == 0) {
                    desert.back().is_gas_station = true;
                }
            }
            else { //new position discovered

                desert.back().d = event_position - current_position;
                current_position = event_position;

                instance new_inst;
                new_inst.l = desert.back().l;
                new_inst.n = desert.back().n;
                new_inst.is_goal = false;
                new_inst.is_gas_station = false;
                desert.push_back(new_inst);

                scanf("%s", buffer);

                if (strcmp (buffer, "Goal") == 0) {
                    desert.back().is_goal = true;
                    break;
                }
                else if (strcmp (buffer, "Fuel") == 0) {
                    int new_fc;
                    char dummy[50];
                    scanf("%s %d", dummy, &new_fc);
                    desert.back().n = new_fc;
                }
                else if (strcmp (buffer, "Leak") == 0) {
                    desert.back().l++;
                }
                else if (strcmp (buffer, "Mechanic") == 0) {
                    desert.back().l = 0;
                }
                else if (strcmp (buffer, "Gas") == 0) {
                    desert.back().is_gas_station = true;
                }
            }
        }

        vector<instance>::iterator it;
        double max_consumption = 0;
        double cur_consumption = 0;

        for (it = desert.begin(); it != desert.end(); it++) {
            if (!(it->is_goal || it->is_gas_station)) {
                cur_consumption += calculate_consumption (it->d, it->n, it->l);
            }
            else {
                if (it->is_gas_station) {
                    if (max_consumption < cur_consumption) max_consumption = cur_consumption;
                    cur_consumption = calculate_consumption (it->d, it->n, it->l);
                }
                if (it->is_goal) {
                    if (max_consumption < cur_consumption) max_consumption = cur_consumption;
                }
            }
        }
        printf("%.3lf\n", max_consumption);
    }
    return 0;
}
