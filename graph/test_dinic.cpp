
// C++ implementation of Dinic's Algorithm
#include<bits/stdc++.h>
#define INF 99999999
using namespace std;

typedef struct triple {
    int v;
    int a;
    int b;
} triple;

// A structure to represent a edge between
// two vertex
struct Edge
{
    int v ;  // Vertex v (or "to" vertex)
             // of a directed edge u-v. "From"
             // vertex u can be obtained using
             // index in adjacent array.

    int flow ; // flow of data in edge

    int C;    // capacity

    int rev ; // To store index of reverse
              // edge in adjacency list so that
              // we can quickly find it.
};

// Residual Graph
class Graph
{
    int V; // number of vertex
    int *level ; // stores level of a node
    vector< Edge > *adj;
public :
    Graph(int V)
    {
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }

    // add edge to the graph
    void addEdge(int u, int v, int C)
    {
        // Forward edge : 0 flow and C capacity
        Edge a{v, 0, C, adj[v].size()};

        // Back edge : 0 flow and 0 capacity
        Edge b{u, 0, 0, adj[u].size()};

        adj[u].push_back(a);
        adj[v].push_back(b); // reverse edge
    }

    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxflow(int s, int t);
};

// Finds if more flow can be sent from s to t.
// Also assigns levels to nodes.
bool Graph::BFS(int s, int t)
{
    for (int i = 0 ; i < V ; i++)
        level[i] = -1;

    level[s] = 0;  // Level of source vertex

    // Create a queue, enqueue source vertex
    // and mark source vertex as visited here
    // level[] array works as visited array also.
    list< int > q;
    q.push_back(s);

    vector<Edge>::iterator i ;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            Edge &e = *i;
            if (level[e.v] < 0  && e.flow < e.C)
            {
                // Level of current vertex is,
                // level of parent + 1
                level[e.v] = level[u] + 1;

                q.push_back(e.v);
            }
        }
    }

    // IF we can not reach to the sink we
    // return false else true
    return level[t] < 0 ? false : true ;
}

// A DFS based function to send flow after BFS has
// figured out that there is a possible flow and
// constructed levels. This function called multiple
// times for a single call of BFS.
// flow : Current flow send by parent function call
// start[] : To keep track of next edge to be explored.
//           start[i] stores  count of edges explored
//           from i.
//  u : Current vertex
//  t : Sink
int Graph::sendFlow(int u, int flow, int t, int start[])
{
    // Sink reached
    if (u == t)
        return flow;

    // Traverse all adjacent edges one -by - one.
    for (  ; start[u] < adj[u].size(); start[u]++)
    {
        // Pick next edge from adjacency list of u
        Edge &e = adj[u][start[u]];

        if (level[e.v] == level[u]+1 && e.flow < e.C)
        {
            // find minimum flow from u to t
            int curr_flow = min(flow, e.C - e.flow);

            int temp_flow = sendFlow(e.v, curr_flow, t, start);

            // flow is greater than zero
            if (temp_flow > 0)
            {
                // add flow  to current edge
                e.flow += temp_flow;

                // subtract flow from reverse edge
                // of current edge
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

// Returns maximum flow in graph
int Graph::DinicMaxflow(int s, int t)
{
    // Corner case
    if (s == t)
        return -1;

    int total = 0;  // Initialize result

    // Augment the flow while there is path
    // from source to sink
    while (BFS(s, t) == true)
    {
        // store how many edges are visited
        // from V { 0 to V }
        int *start = new int[V+1];

        // while flow is not zero in graph from S to D
        while (int flow = sendFlow(s, INT_MAX, t, start))

            // Add path flow to overall flow
            total += flow;
    }

    // return maximum flow
    return total;
}

int main() {

    int n;
    cin >> n;
    int naruto = 1;
    while (n != 0) {
        int m;
        cin >> m;
        vector<triple> monkeys;
        int min_time = INF;
        int max_time = -INF;
        int total_thirst = 0;
        for (int i = 0; i < n; i++) {
            int v, a, b;
            cin >> v >> a >> b;
            b--;
            total_thirst += v;
            min_time = min(min_time, a);
            max_time = max(max_time, b);
            triple cur;
            cur.v = v;
            cur.a = a;
            cur.b = b;
            monkeys.push_back(cur);
        }
        int nt = max_time - min_time + 1;
        int size = 1+n+nt+1;
        Graph g(size);
        // vector<vector<int>> weights(size, vector<int>(size, 0));
        // vector<vector<int>> flux(size, vector<int>(size, 0));
        for (int i = 0; i < n; i++) {
            triple cur = monkeys[i];
             g.addEdge(0, i+1, cur.v);
            int time_a = cur.a - min_time + n+1;
            int time_b = cur.b - min_time + n+1;
            for (int j = time_a; j <= time_b; j++) {
                 g.addEdge(i+1, j, 1);
            }
        }
        for (int i = min_time; i <= max_time; i++) {
            int cur = i - min_time + n + 1;
             g.addEdge(cur, n+nt+1, m);
        }
        // int max_flow = edmonds_karp(residual_net, weights, flux, 0, n+nt+1);
        int max_flow = g.DinicMaxflow(0, n+nt+1);
        if (total_thirst == max_flow) {
            cout << "Case " << naruto++ << ": Yes\n";
            // for (int i = 0; i < n; i++) {
            //     triple cur = monkeys[i];
            //     int v, a, b;
            //     v = cur.v;
            //     a = cur.a;
            //     b = cur.b;
            //     vector<pair<int,int>> intervals;
            //     int time_a = a - min_time +n+1;
            //     int time_b = b - min_time +n+1;
            //     bool growing = false;
            //     int lower, upper;
            //     for (int j = time_a; j <= time_b; j++) {
            //         if (flux[i+1][j] == 1) {
            //             if (!growing) {
            //                 lower = j;
            //                 growing = true;
            //             }
            //             upper = j+1;
            //         }
            //         else {
            //             if (growing) {
            //                 intervals.push_back(pair<int,int>(lower,upper));
            //             }
            //             growing = false;
            //         }
            //     }
            //     if (growing) {
            //         intervals.push_back(pair<int,int>(lower,upper));
            //     }
            //     cout << intervals.size() << ' ';
            //     for (int j = 0; j < intervals.size(); j++) {
            //         if (j != 0)
            //             cout << ' ';
            //         cout << "(" << intervals[j].first+min_time-n-1 << "," << intervals[j].second+min_time-n-1 << ")";
            //     }
            //     cout << '\n';
            // }
        }
        else {
            cout << "Case " << naruto++ << ": No\n";
        }

        cin >> n;
    }

    return 0;
}
