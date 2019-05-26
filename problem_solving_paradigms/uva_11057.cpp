#include <bits/stdc++.h>

using namespace std;

bool first = true;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
    int num_of_books;
    while (scanf("%d", &num_of_books) != EOF) {
        int* books = (int*) malloc (num_of_books*sizeof(int));
        for (int i = 0; i < num_of_books; i++) {
            scanf("%d", &books[i]);
        }
        int money;
        scanf("%d", &money);
        qsort(books, num_of_books, sizeof(int), cmpfunc);
        int hi=num_of_books-1, lo=0;
        int best_hi, best_lo;
        while (hi > lo) {
            if (books[lo] + books[hi] > money) hi--;
            else if (books[lo] + books[hi] < money) lo++;
            else {
                best_hi = hi;
                best_lo = lo;
                hi--;
                lo++;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", books[best_lo], books[best_hi]);
        free (books);
    }
}
