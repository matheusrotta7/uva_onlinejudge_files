#include<bits/stdc++.h>

using namespace std;

int main() {


    long int memory[70];
    memory[0] = -1;
    memory[1] = 1;
    memory[2] = 1;
    memory[3] = 1;
    for (int i = 1; i <= 60; i++) { //regra formadora do problema
        memory[i+3] = memory[i] + memory[i+1] + memory[i+2];
    }



    int n;
    cin >> n;
    long int caso = 0;
    while (n != 0) {
        caso++;
        cout << "Case " << caso << ": " << memory[n] << '\n';
        cin >> n;
    }

    return 0;
}
