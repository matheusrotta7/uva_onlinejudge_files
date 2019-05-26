#include <bits/stdc++.h>

using namespace std;

int main () {



    int n;
    cin >> n;

    vector<int> class1(26, 0);
    vector<int> class2(26, 0);

    //greedy solution?
    for (int i = 0; i < n; i++) {
        string student;
        cin >> student;

        char letter = student[0];
        int ref = letter - 97; //a : 97 in dec.
        if (class1[ref] <= class2[ref]) {
            class1[ref]++;
        }
        else {
            class2[ref]++;
        }
    }

    int min_x = 0;

    for (int i = 0; i < 26; i++) {
        int num_chatty_students = class1[i];
        if (num_chatty_students == 0)
            continue;
        else {
            min_x += (num_chatty_students*(num_chatty_students-1))/2;
        }

    }

    for (int i = 0; i < 26; i++) {
        int num_chatty_students = class2[i];
        if (num_chatty_students == 0)
            continue;
        else {
            min_x += (num_chatty_students*(num_chatty_students-1))/2;
        }
    }

    cout << min_x << '\n';



    return 0;
}
