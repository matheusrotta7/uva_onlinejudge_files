#include <bits/stdc++.h>

using namespace std;

int min_index, max_index;
bool found_valid_max, found_valid_min;

int binary_search_min (int arr[], int l, int r, int x, int maximum)
{

   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x) {
            found_valid_min = true;
            int i = mid;
			min_index = i;
            i--;
            while (i >= 0 && arr[i] == x) {
                min_index = i;
                i--;
            }
            return min_index;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x) {
			if (arr[mid] <= maximum) {
				found_valid_min = true;
				min_index = mid;
			}
            return binary_search_min (arr, l, mid-1, x, maximum);
        }

        // Else the element can only be present
        // in right subarray
        return binary_search_min (arr, mid+1, r, x, maximum);
   }

   // We reach here when element is not
   // present in array
   return -1;
}

int binary_search_max (int arr[], int l, int r, int x, int b, int minimum)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x) {
            found_valid_max = true;
            int i = mid;
			max_index = i;
            i++;
            while (i <= b-1 && arr[i] == x) {
                max_index = i;
                i++;
            }
            return max_index;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binary_search_max (arr, l, mid-1, x, b, minimum);

        // Else the element can only be present
        // in right subarray

		if (arr[mid] >= minimum) {
			found_valid_max = true;
			max_index = mid;
		}
        return binary_search_max (arr, mid+1, r, x, b, minimum);
   }

   // We reach here when element is not
   // present in array
   return -1;
}

int main () {

    while (1) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;

        int** grapevine = (int**) malloc (a*sizeof(int*));
        for (int i = 0; i < a; i++) {
            grapevine[i] = (int*) malloc (b*sizeof(int));
        }

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                scanf("%d", &grapevine[i][j]);
            }
        }

		int length = a+b-1;
		int** diagonals = (int**) malloc ((length)*sizeof(int*));
		int* diag_size = (int*) malloc ((length)*sizeof(int)); //this is informative, to know the size
															  //of each line in diagonals
		int i1 = 0, i2 = 0;
		//now we will create a matrix that possesses the diagonals of the first line and column

		//going through the first line, stopping at first element
		for (int i = b-1; i >= 0; i--) {
			int line = 0;
			int col = i;
			i2 = 0;
			diag_size[i1] = min(b-i, a);
			diagonals[i1] = (int*) malloc (diag_size[i1] * sizeof(int));
			while (col <= b-1 && line <= a-1) {
				diagonals[i1][i2++] = grapevine[line][col];
				line++;
				col++;
			}
			i1++;
		}

		//going through the first column, but starting at second element because the first
		//was already visitted by the first for...
		for (int i = 1; i < a; i++) {
			int line = i;
			int col = 0;
			i2 = 0;
			diag_size[i1] = min(a-i, b);
			diagonals[i1] = (int*) malloc (diag_size[i1] * sizeof(int));
			while (col <= b-1 && line <= a-1) {
				diagonals[i1][i2++] = grapevine[line][col];
				line++;
				col++;
			}
			i1++;
		}

        int num_of_intervals;
        scanf("%d", &num_of_intervals);

        for (int i = 0; i < num_of_intervals; i++) {
            int side = -42;
            int minimum, max;
            scanf("%d %d", &minimum, &max);

			for (int j = 0; j < length; j++) {
				found_valid_max = false;
                found_valid_min = false;
                binary_search_min (diagonals[j], 0, diag_size[j]-1, minimum, max);
                binary_search_max (diagonals[j], 0, diag_size[j]-1, max, diag_size[j], minimum);
				int cur_side;

                if (found_valid_max || found_valid_min) {
                    // for (int k = min_index; k <= max_index; k++) binary[j][k] = 1;
					cur_side = max_index - min_index + 1;
                }
				else {
					// printf("BANANAAAAAAAAAAA!!!!\n");
					cur_side = 0;
				}

				if (cur_side > side) side = cur_side;
			}

            printf("%d\n", side);
        }

        for (int i = 0; i < a; i++) {
            free(grapevine[i]);
        }
		free(grapevine);

		for (int i = 0; i < length; i++) {
			free (diagonals[i]);
		}
		free(diagonals);
		free(diag_size);

        printf("-\n");
    }
    return 0;
}
