#include <bits/stdc++.h>

using namespace std;

int min_index, max_index;
bool found_valid_max, found_valid_min;

int min(int a, int b, int c)
{
int m = a;
if (m > b)
	m = b;
if (m > c)
	m = c;
return m;
}

int printMaxSubSquare(int** M, int R, int C)
{
  int i,j;

  int** S = (int**) malloc (R*sizeof(int*));
  for (int i = 0; i < R; i++) {
      S[i] = (int*) malloc (C*sizeof(int));
  }

  int max_of_s, max_i, max_j;

  /* Set first column of S[][]*/
  for(i = 0; i < R; i++)
     S[i][0] = M[i][0];

  /* Set first row of S[][]*/
  for(j = 0; j < C; j++)
     S[0][j] = M[0][j];

  /* Construct other entries of S[][]*/
  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(M[i][j] == 1)
        S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }
  }

  /* Find the maximum entry, and indexes of maximum entry
     in S[][] */
  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i;
         max_j = j;
      }
    }
  }

  for (int i = 0; i < R; i++) {
      free(S[i]);
  }
  free (S);

  return max_of_s;
  // printf("Maximum size sub-matrix is: \n");
  // for(i = max_i; i > max_i - max_of_s; i--)
  // {
  //   for(j = max_j; j > max_j - max_of_s; j--)
  //   {
  //     printf("%d ", M[i][j]);
  //   }
  //   printf("\n");
  // }
}

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
			if (arr[mid] <= maximum)
            	found_valid_min = true;
            min_index = mid;
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
        max_index = mid;
		if (mid >= minimum)
        	found_valid_max = true;
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

        int num_of_intervals;
        scanf("%d", &num_of_intervals);

        for (int i = 0; i < num_of_intervals; i++) {
            int side = -42;
            int minimum, max;
            scanf("%d %d", &minimum, &max);

            int** binary = (int**) calloc (a, sizeof(int*));
            for (int i = 0; i < a; i++) {
                binary[i] = (int*) calloc (b, sizeof(int));
            }

            //we must, for each line, binary search the minimum and the maximum
            for (int j = 0; j < a; j++) {
                found_valid_max = false;
                found_valid_min = false;
                binary_search_min (grapevine[j], 0, b-1, minimum, max);
                binary_search_max (grapevine[j], 0, b-1, max, b, minimum);
                if (found_valid_max || found_valid_min) {
                    for (int k = min_index; k <= max_index; k++) binary[j][k] = 1;
                }
				else {
					// printf("BANANAAAAAAAAAAA!!!!\n");
				}
            }

            side = printMaxSubSquare(binary, a, b);
			for (int i = 0; i < a; i++) {
                free(binary[i]);
            }
			free(binary);
            printf("%d\n", side);
        }

        for (int i = 0; i < a; i++) {
            free(grapevine[i]);
        }
		free(grapevine);

        printf("-\n");
    }
    return 0;
}
