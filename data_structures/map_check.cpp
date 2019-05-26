#include <stdio.h>
#include <map>

using namespace std;

int main() {
    map<int, int> m1;
    map<int, int> m2;

    pair<int,int> p1 = pair<int, int>(4, 7);
    pair<int,int> p2 = pair<int, int>(6, 8);
    pair<int,int> p3 = pair<int, int>(6, 8);
    pair<int,int> p4 = pair<int, int>(4, 7);

    m1.insert(p1);
    m1.insert(p2);
    m2.insert(p3);
    m2.insert(p4);

    map<int, int>::iterator it = m1.find(6);
    it->second++;
    printf("incremented: %d\n", (m1.find(6))->second);

    printf("%s\n", m1 == m2? "true" : "false");
    return 0;
}
