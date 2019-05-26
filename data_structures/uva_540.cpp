#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct element {
    int person;
    int team;
    element(int person, int team) {
        this->person = person;
        this->team = team;
    }
};


int main (int argc, const char** argv) {

    element* set_people = (element*) malloc (1000000*sizeof(element)); //max number of elements is one million

    int num_teams = -1;
    scanf("%d", &num_teams);

    int test_case = 1;
    while (num_teams != 0) {
        queue<element> main;
        queue<element> aux;
        printf("Scenario #%d\n", test_case++);
        for (int i = 0; i < num_teams; i++) {
            int num_elements = -1;
            scanf("%d", &num_elements);
            for (int j = 0; j < num_elements; j++) {
                int person_id = -1;
                scanf("%d", &person_id);
                element new_person = *(new element(person_id, i)); //i is the team because of the loop logic
                set_people[person_id] = new_person;
            }
        }
        //--------algorithm implementation----------//
        //read enqueue's or dequeue's or stop's:
        while(1) {
            char buffer[50];
            scanf("%s", buffer);
            if(strcmp(buffer, "ENQUEUE") == 0) {
                int person_id;
                scanf("%d", &person_id);

                if (main.empty()) { //if there is no one on the queue, add element and continue loop
                    main.push(set_people[person_id]);
                    continue;
                }

                int insertee_team = set_people[person_id].team;
                element insertee = set_people[person_id];
                bool found_team = false;
                while (!main.empty()) {
                    if (main.front().team == insertee_team) {
                        //element has found his team, so we will start the procedure to insert him
                        //q.front is currently from the same team as the insertee, so let's pop him to further analyze
                        found_team = true;
                        aux.push(main.front()); //add to auxiliary queue
                        main.pop();
                        bool found_change = false;
                        while (!main.empty()) {
                            if (main.front().team != insertee_team) { //if the team is over, insert the insertee
                                found_change = true;
                                aux.push(insertee);
                                while (!main.empty()) { //finish copying the rest of the main queue to the aux one
                                    aux.push(main.front());
                                    main.pop();
                                }
                            }
                            else {
                                aux.push(main.front()); //add to auxiliary queue
                                main.pop();
                            }
                        }
                        if (!found_change) {
                            aux.push(insertee);
                        }
                    }
                    else {
                        aux.push(main.front()); //add to auxiliary queue
                        main.pop();
                    }
                }
                if (!found_team) {
                    aux.push(set_people[person_id]);
                }
                swap (main, aux); //because we want to keep main with the current situation always
            }
            else if (strcmp(buffer, "DEQUEUE") == 0) {
                printf("%d\n", main.front().person);
                main.pop();
            }
            else if (strcmp(buffer, "STOP") == 0) {
                break; //exit execution loop
            }
            else {
                printf("Read something invalid, stopping execution\n");
                return 0;
            }
        }
        scanf("%d", &num_teams);
        printf("\n");
    }

    return 0;
}
