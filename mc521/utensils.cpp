#include <bits/stdc++.h>

using namespace std;

int main () {


    int n, k;
    cin >> n >> k;
    int max_usage = -1;

    // vector<int> utensils_left(n);
    vector<int> utensil_usage(101, 0); //access directly by number, increment

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        utensil_usage[aux]++;
        max_usage = max(max_usage, utensil_usage[aux]);
        // utensils_left[i] = aux;
    }

    int num_dishes = ceil((float)max_usage/(float)k);
    int min_stolen = 0;
    for (int i = 1; i < 101; i++) {
        if (utensil_usage[i] == 0) {
            //dont do anything
        }
        else {
            min_stolen += k*num_dishes - utensil_usage[i]; //what is left is what was stolen
        }
    }
    cout << min_stolen << '\n';


    return 0;
}
