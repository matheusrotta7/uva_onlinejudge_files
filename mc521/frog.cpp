#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> lengths(n);

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        lengths[i] = aux;
    }

    sort(lengths.begin(), lengths.end()); //do menor pro maior
    //check if there is a one unit difference between consecutives
    //because if there is, any number is reachable
    bool good = false;
    for (int i = 1; i < n; i++) {
        if ((lengths[i] - lengths[i-1]) == 1) {
            good = true;
            break;
        }
    }
    if (!good) {
        //solve for more complicated cases
        vector<int> diff_old(n);
        vector<int> diff_new(n);
        for (int i = 0; i < n; i++) {
            diff_new[i] = lengths[i];
        }
        int cur_size = n;
        loop:
        for (int i = 0; i < cur_size; i++) {
            diff_old[i] = diff_new[i];
        }
        cur_size--;
        for (int i = 1; i < cur_size+1; i++) {
            int check = diff_new[i-1] = diff_old[i] - diff_old[i-1];
            if (check == 1)
                goto nice;
        }
        diff_new.pop_back();
        // diff_old.pop_back();
        sort (diff_new.begin(), diff_new.end());
        if (cur_size > 1 && diff_new[cur_size-1] > 0) {
            diff_old.pop_back();
            goto loop;
        }
        else {
            //check if desired number is multiple of last non null number from diff_old
            int num = diff_old[diff_old.size()-1];
            if (x % num == 0)
                goto nice;
        }

        cout << "NO\n";
    }
    else { //if good
        nice:
        cout << "YES\n";
    }
    return 0;
}
