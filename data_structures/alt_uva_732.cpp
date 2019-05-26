#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#include <map>
#include <stack>
#include <vector>

using namespace std;

typedef struct input {
    char* sequence;
    int index;
    int i_num;
    int o_num;
    bool done;
} input;

bool compare (input a, input b) {
    return (strcmp (a.sequence, b.sequence) < 0);
}

vector<input> generate_inputs (vector<input> inputs, int length) {
    bool all_done = false;
    while (!all_done) {

        vector<input>::iterator it;
        vector<input> aux;

        for (it = inputs.begin(); it != inputs.end(); it++) {
            if ((*it).i_num + (*it).o_num < 2*length) { //if there is still letters to be put
                if ((*it).i_num > (*it).o_num) { //if the number of inserted i's is bigger than the number of o's, try to insert i and o
                    if ((*it).i_num == length) { //if the i's have reached their limit, we can only insert o
                        (*it).sequence[(*it).index++] = 'o';
                        (*it).sequence[(*it).index] = '\0';
                        (*it).o_num++;
                    }
                    else { //if the i's have not reached their limit, we can insert i or o
                        input new_input;
                        new_input.sequence = (char*) malloc(2*length + 1);
                        strcpy (new_input.sequence, (*it).sequence);
                        new_input.index = (*it).index;
                        new_input.sequence[new_input.index++] = 'o';
                        new_input.sequence[new_input.index] = '\0';
                        new_input.i_num = (*it).i_num;
                        new_input.o_num = (*it).o_num + 1;
                        new_input.done = false;
                        aux.push_back(new_input);

                        (*it).sequence[(*it).index++] = 'i';
                        (*it).sequence[(*it).index] = '\0';
                        (*it).i_num++;
                    }
                }
                else { //if the number of i's is the same as o's, just add an i
                    (*it).sequence[(*it).index++] = 'i';
                    (*it).sequence[(*it).index] = '\0';
                    (*it).i_num++;
                }
            }
            else {
                (*it).done = true;
            }

        }
        it = inputs.end();
        inputs.insert(it, aux.begin(), aux.end()); //adds the aux vector at the end of the inputs vector

        all_done = true;

        for (it = inputs.begin(); it != inputs.end(); it++) {
            if ((*it).done == false) all_done = false;
        }
    }
    return inputs;
}



int main() {
    char source[50];
    char target[50];
    while (scanf("%s", source) != EOF) {
        scanf("%s", target);
        if (strlen(source) != strlen(target)) {
            printf("[\n]\n"); //if the strings don't have the same size, they are not anagrams
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

        //generate all possible inputs
        int length = strlen(target);
        vector<input> inputs;
        input first;
        first.sequence = (char*) malloc(2*length + 1);
        first.sequence[0] = 'i';
        first.sequence[1] = '\0';
        first.i_num = 1;
        first.o_num = 0;
        first.index = 1; //because there is 'i' already
        first.done = false;
        inputs.push_back(first);
        inputs = generate_inputs (inputs, length);

        //now we have a vector of possible inputs
        //we will try each one and check if the generated string is the same as the target
        //but first we will sort the vector in alphabetical order
        sort (inputs.begin(), inputs.end(), compare);

        printf("[\n");
        vector<input>::iterator it;
        for (it = inputs.begin(); it != inputs.end(); it++) {
            int p = 0; //p points to a certain char in source
            int q = 0; //q is the index for the generated string
            stack<char> st;
            char generated[50];
            for (int i = 0; i < 2*length; i++) { //2*length is equivalent to strlen((*it).sequence)
                if ((*it).sequence[i] == 'i') {
                    st.push(source[p++]);
                }
                else {
                    generated[q++] = st.top();
                    st.pop();
                }
            }
            generated[q] = '\0';
            if (strcmp(generated, target) == 0) {
                for (int j = 0; j < 2*length; j++) {
                    printf("%c", (*it).sequence[j]);
                    if (j != 2*length - 1) printf(" ");
                }
                printf("\n");
            }
        }
        printf("]\n");
        for (it = inputs.begin(); it != inputs.end(); it++) free((*it).sequence);
    }
    return 0;
}
