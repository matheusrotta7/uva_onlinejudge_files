#include <stdio.h>
#include <cmath>

typedef struct array {
    int m[9][9];
} array;

bool success = false;
int num = 0;


bool line_check_valid (array ar, int line, int dim) {
    bool valid = true;
    int ref = ar.m[line][0];
    for (int j = 1; j < dim; j++) {
        if (ar.m[line][j] == ref) valid = false;
    }
    return valid;
}

bool column_check_valid (array ar, int column, int dim) {
    bool valid = true;
    int ref = ar.m[0][column];
    for (int j = 1; j < dim; j++) {
        if (ar.m[j][column] == ref) valid = false;
    }
    return valid;
}

bool box_check_valid (array ar, int dim) {
    bool valid = true;
    int aux = sqrt(dim); //dim = 9 --> aux = 3

    for (int i = 0; i < dim; i += aux) {
        for (int j = 0; j < dim; j += aux) {
            int ref = ar.m[i][j];
            for (int k = i; k < i + aux; k++) {
                for (int l = j; l < j + aux; l++) {
                    if (!(i == k &&  j == l)) {
                        if (ar.m[k][l] == ref) valid = false;
                    }
                }
            }
        }
    }
    return valid;
}

bool is_valid (array ar, int dim) {
    bool aux = true;
    for (int i = 0; i < dim; i++) {
        aux = aux && line_check_valid (ar, i, dim) && column_check_valid(ar, i, dim);
    }
    aux = aux && box_check_valid (ar, dim);
    return aux;
}

bool line_check (int i, array ar, int a, int b, int dim) {
    bool valid = true;
    for (int j = 0; j < dim; j++) {
        if (ar.m[a][j] == i) valid = false;
    }
    return valid;
}

bool column_check (int i, array ar, int a, int b, int dim) {
    bool valid = true;
    for (int j = 0; j < dim; j++) {
        if (ar.m[j][b] == i) valid = false;
    }
    return valid;
}

bool box_check (int i, array ar, int a, int b, int dim) {
    bool valid = true;
    int aux = sqrt(dim);
    a = (a/aux)*aux;
    b = (b/aux)*aux;
    for (int j = a; j < a + aux; j++) {
        for (int k = b; k < b + aux; k++) {
            if (ar.m[j][k] == i) valid = false;
        }
    }
    return valid;
}

array copy (array ar, array aux, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            aux.m[i][j] = ar.m[i][j];
        }
    }
    return aux;
}

array solve (array ar, int a, int b, int dim) {
    num++;
    array aux;
    aux = copy (ar, aux, dim);
    if (a == dim - 1 && b == dim) success = true;

    if (b == dim) {
        a++;
        b = 0;
    }

    if (ar.m[a][b] == 0) {
        for (int i = 1; i <= dim; i++) {
            if(line_check (i, aux, a, b, dim) && column_check (i, aux, a, b, dim) && box_check (i, aux, a, b, dim)) {
                aux.m[a][b] = i;
                ar = solve (aux, a, b+1, dim);
                if (success) break;
                else aux.m[a][b] = 0;
            }
        }
    }
    else {
        ar = solve (ar, a, b+1, dim);
    }
    return ar;
}

int main () {
    bool first_execution = true;
    int n;
    while (scanf("%d", &n) != EOF) {
        if (!first_execution) {
            printf("\n");
        }
        else {
            first_execution = false;
        }
        if (n == 3) {
            //logic used for n = 3:
            array input;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    input.m[i][j] = 0; //initiate values of the m matrix as zero
                }
            }
            // printf("Input elements as requested: (input zero if blank) \n");

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    // printf("Input element (%d,%d): \n", i, j);
                    scanf("%d", &input.m[i][j]);
                }
            }

            input = solve (input, 0, 0, 9);

            if (success && is_valid(input, 9)) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        printf("%d", input.m[i][j]);
                        if (j != 8) printf(" ");
                    }
                    printf("\n");
                }
            }
            else {
                printf("NO SOLUTION\n");
            }

        }
        else if (n == 2) {
            //same logic but adapted for the 4x4 sudoku
            array input;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    input.m[i][j] = 0; //initiate values of the m matrix as zero
                }
            }
            // printf("Input elements as requested: (input zero if blank) \n");

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    // printf("Input element (%d,%d): \n", i, j);
                    scanf("%d", &input.m[i][j]);
                }
            }

            input = solve (input, 0, 0, 4);

            if (success && is_valid(input, 4)) {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        printf("%d", input.m[i][j]);
                        if (j != 3) printf(" ");
                    }
                    printf("\n");
                }
            }
            else {
                printf("NO SOLUTION\n");
            }

        }
        else if (n == 1) {
            int loner;
            scanf("%d", &loner);
            if (loner == 0) printf("1\n");
            else printf("%d\n", loner);
        }
        success = false;
    }

    return 0;
}
