#include <bits/stdc++.h>

using namespace std;


typedef struct submission {
    int time;
    char problem;
    string veredict;
} submission;

int main () {

    vector<submission> subs;
    int num_ac = 0;
    int time_penalty = 0;


    vector<bool> solved_problem(26, false);

    int subs_size = 0;


    int minutes;
    char problem;
    string veredict;
    cin >> minutes >> problem >> veredict;
    // submission new_sub;
    // new_sub.time = minutes;
    // new_sub.problem = problem;
    // new_sub.veredict = veredict;
    // subs.push_back(new_sub);
    // subs_size++;

    while (minutes != -1) {

        submission new_sub;
        new_sub.time = minutes;
        new_sub.problem = problem;
        new_sub.veredict = veredict;
        if (solved_problem[problem - 65])
            goto skip;
        if (veredict == "right") {
            solved_problem[problem - 65] = true; //(int) A -> 65, solved_problem[0] = true
        }
        subs.push_back(new_sub);
        subs_size++;
        skip:
        cin >> minutes >> problem >> veredict;
    }

    for (int i = 0; i < subs_size; i++) {
        // cout << "cur time penalty is: " << time_penalty << '\n';
        if (subs[i].veredict == "right") {
            time_penalty += subs[i].time;
        }
        else if (solved_problem[i]){ //current submission is wrong but probably solved the problem later on
            time_penalty += 20;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (solved_problem[i])
            num_ac++;
    }

    cout << num_ac << ' ' << time_penalty << '\n';



    return 0;
}
