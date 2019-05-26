#include<bits/stdc++.h>

using namespace std;

int main () {

    // bool first = true;
    int n;
    cin >> n;
    while (n != 0) {
        // if (!first) {
        //     cout << '\n';
        // }
        // else {
        //     first = false;
        // }
        //this internal loop loops through permutations, stops when reads 0
        // cout << "I am in case " << n << '\n';
        while (true) {

            stack<int> st;
            int to_arrive = 1; //first to arrive is 1
            bool success = true;
            for (int i = 0; i < n; i++) {
                int cur;
                cin >> cur;
                if (cur == 0)
                    goto leave;

                if (cur >= to_arrive) {
                    while (cur != to_arrive) {
                        st.push(to_arrive++);
                    }
                    st.push(to_arrive++);
                    st.pop(); //remove desired value because cur == to_arrive
                    // success = true;
                }
                else { //we must search for element in the stack

                    if (st.empty()) {
                        success = false;
                        goto shortcut;
                    }
                    if (st.top() ==  cur) {
                        st.pop();
                    }
                    else {
                        success = false;
                        goto shortcut;
                    }

                }
            }
            shortcut:
            cout << "stack is empty?" << (bool)st.empty()  << '\n';
            if (!success) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }

        }
        leave:



        cout << '\n';
        cin >> n;
    }


    return 0;
}
