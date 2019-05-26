#include <stdio.h>
#include <stdlib.h>
#include <deque>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        deque<int> deq;
        for (int i = 1; i <=n; i++) {
            deq.push_back(i);
        }

        if (deq.size() == 1) {
            printf("Discarded cards:\n");
        }
        else {
            printf("Discarded cards: ");
        }

        while(deq.size() > 1) {
            if (deq.size() > 2) {
                printf("%d, ", deq.front());
            }
            else {
                printf("%d\n", deq.front());
            }
            deq.pop_front(); //remove printed element
            deq.push_back(deq.front()); //copy top card to the bottom
            deq.pop_front(); //remove top card
        }
        printf("Remaining card: %d\n", deq.front());
        scanf("%d", &n); //read n for next iteration
    }
    return 0;
}
