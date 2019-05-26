#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <stack>
#include <string.h>

using namespace std;

int main() {
    char source[50];
    char target[50];
    while (scanf("%s", source) != EOF) {
        scanf("%s", target);
        if (strlen(source) != strlen(target)) {
            printf("[\n]\n"); //if the string don't have the same size, they are not anagrams
            continue;
        }

        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < strlen(source); i++) {
            map<char, int>::iterator it = m1.find(source[i]);
            if (it != m1.end()) it->second++;
            else m1.insert(pair<char, int>(source[i], 1));
        }
        for (int i = 0; i < strlen(target); i++) {
            map<char, int>::iterator it = m2.find(target[i]);
            if (it != m2.end()) it->second++;
            else m2.insert(pair<char, int>(target[i], 1));
        }
        if (m1 != m2) {
            printf("[\n]\n"); //if the letters are not the same, they are not anagrams
            continue;
        }

        //from this point on we are certain that source and target are anagrams
        //but we don't know if one can become the other via stacking

        stack<char> st;
        char print[50];
        int index = 0;
        int cur = 0;
        bool possible = true;
        for (int i = 0; i < strlen(target); i++) {
            char wanted = target[i];
            if(!st.empty() && st.top() == wanted) {
                print[index++] = 'o';
                st.pop();
            }
            else {
                while (source[cur] != wanted && cur < strlen(source)) {
                    print[index++] = 'i';
                    st.push(source[cur++]);
                }
                if (cur < strlen(source)) {
                    print[index++] = 'i';
                    print[index++] = 'o';
                    cur++;
                }
                else {
                    possible = false;
                }
            }
        }
        if (possible) {
            print[index] = '\0';
            printf("[\n");
            for (int i = 0; i < strlen(print); i++) {
                printf("%c", print[i]);
                if (i != strlen(print) - 1) printf(" ");
            }
            printf("\n]\n");
        }
    }
    return 0;
}
