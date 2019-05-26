#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int> x;
    int a;
    int n = 0;
    while(scanf("%d", &a)!=EOF) {
        x.push_back(a);
        n++;
    }
    vector<int> m(n, -1);
    vector<int> p(n, -1);
    m[0] = 0;
    int l = 1;
    for (int i = 1; i < n; i++) {
        if (x[i] < x[m[0]]) {
            m[0] = i;
        }
        else if (x[i] > x[m[l-1]]) {
            m[l] = i;
            p[i] = m[l-1];
            l++;
        }
        else if (x[i] == x[m[0]]) continue;
        else if (x[i] == x[m[l-1]]) continue;
        else {
            bool unactive = false;
            int lo = 0, hi = l-1;
            while (hi - lo > 1) {
                int mid = (hi + lo)/2;
                if(x[i] < x[m[mid]]) {
                    hi = mid;
                }
                else if (x[i] > x[m[mid]]) {
                    lo = mid;
                }
                else {
                    unactive = true;
                    break;
                }
            }
            if (!unactive) {
                m[hi] = i;
                p[i] = m[lo];

            }
        }
    }
    int aux = m[l-1];
    stack<int> s;
    while (p[aux]!=-1) {
        s.push(x[aux]);
        aux = p[aux];
    }
    s.push(x[aux]);
    cout << l << "\n-\n";
    while(!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }


    return 0;
}
