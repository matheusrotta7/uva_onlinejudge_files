#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct car {
    int time;
    int input_order;
} car;

int main () {
    int c; //number of test cases
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        queue<car> left;
        queue<car> right;
        int n, t, m; //n: n is the capacity of the ferry; t is the time to cross the river; m is the number of cars
        scanf ("%d %d %d", &n, &t, &m);
        int* print = (int*) malloc(m*sizeof(int)); //
        for (int j = 0; j < m; j++) {
            car new_car;
            new_car.input_order = j;
            scanf("%d", &new_car.time);
            char buffer[10];
            scanf("%s", buffer);
            if (strcmp(buffer, "right") == 0) right.push(new_car);
            else if (strcmp(buffer, "left") == 0) left.push(new_car);
            else {
                printf("READ SOMETHING UNEXPECTED, ENDING EXECUTION\n");
            }
        }
        int cur_time = 0; //current time
        bool side = 0; //0 means left, 1 means right -- starting on the left as requested
        while (!right.empty() || !left.empty()) {
            if ((right.front().time > cur_time || right.empty()) && (left.front().time > cur_time || left.empty())) {
                cur_time++;
                continue;
            }
            if (side == 0) {
                int cars_taken = 0;
                while (cars_taken < n && !left.empty() && left.front().time <= cur_time) {
                    print[left.front().input_order] = cur_time + t;
                    left.pop();
                    cars_taken++;
                }
            }
            else {
                int cars_taken = 0;
                while (cars_taken < n && !right.empty() && right.front().time <= cur_time) {
                    print[right.front().input_order] = cur_time + t;
                    right.pop();
                    cars_taken++;
                }
            }
            side = !side; //toggle side
            cur_time += t; //update time
        }
        for (int k = 0; k < m; k++) {
            printf("%d\n", print[k]);
        }
        if (i != c-1)
            printf("\n");
    }
    return 0;
}
