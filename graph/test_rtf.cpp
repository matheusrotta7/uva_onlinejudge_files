
// C++ program to implement push-relabel algorithm for
// getting maximum flow of graph
#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

typedef struct triple {
    int v;
    int a;
    int b;
} triple;

struct Edge
{
    // To store current flow and capacity of edge
    int flow, capacity;

    // An edge u--->v has start vertex as u and end
    // vertex as v.
    int u, v;

    Edge(int flow, int capacity, int u, int v)
    {
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};

// Represent a Vertex
struct Vertex
{
    int h, e_flow;

    Vertex(int h, int e_flow)
    {
        this->h = h;
        this->e_flow = e_flow;
    }
};

// To represent a flow network
class Graph
{
    int V;    // No. of vertices
    vector<Vertex> ver;
    vector<Edge> edge;

    // Function to push excess flow from u
    bool push(int u);

    // Function to relabel a vertex u
    void relabel(int u);

    // This function is called to initialize
    // preflow
    void preflow(int s);

    // Function to reverse edge
    void updateReverseEdgeFlow(int i, int flow);

public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // returns maximum flow from s to t
    int getMaxFlow(int s, int t);
};

Graph::Graph(int V)
{
    this->V = V;

    // all vertices are initialized with 0 height
    // and 0 excess flow
    for (int i = 0; i < V; i++)
        ver.push_back(Vertex(0, 0));
}

void Graph::addEdge(int u, int v, int capacity)
{
    // flow is initialized with 0 for all edge
    edge.push_back(Edge(0, capacity, u, v));
}

void Graph::preflow(int s)
{
    // Making h of source Vertex equal to no. of vertices
    // Height of other vertices is 0.
    ver[s].h = ver.size();

    //
    for (int i = 0; i < edge.size(); i++)
    {
        // If current edge goes from source
        if (edge[i].u == s)
        {
            // Flow is equal to capacity
            edge[i].flow = edge[i].capacity;

            // Initialize excess flow for adjacent v
            ver[edge[i].v].e_flow += edge[i].flow;

            // Add an edge from v to s in residual graph with
            // capacity equal to 0
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
        }
    }
}

// returns index of overflowing Vertex
int overFlowVertex(vector<Vertex>& ver)
{
    for (int i = 1; i < ver.size() - 1; i++)
       if (ver[i].e_flow > 0)
            return i;

    // -1 if no overflowing Vertex
    return -1;
}

// Update reverse flow for flow added on ith Edge
void Graph::updateReverseEdgeFlow(int i, int flow)
{
    int u = edge[i].v, v = edge[i].u;

    for (int j = 0; j < edge.size(); j++)
    {
        if (edge[j].v == v && edge[j].u == u)
        {
            edge[j].flow -= flow;
            return;
        }
    }

    // adding reverse Edge in residual graph
    Edge e = Edge(0, flow, u, v);
    edge.push_back(e);
}

// To push flow from overflowing vertex u
bool Graph::push(int u)
{
    // Traverse through all edges to find an adjacent (of u)
    // to which flow can be pushed
    for (int i = 0; i < edge.size(); i++)
    {
        // Checks u of current edge is same as given
        // overflowing vertex
        if (edge[i].u == u)
        {
            // if flow is equal to capacity then no push
            // is possible
            if (edge[i].flow == edge[i].capacity)
                continue;

            // Push is only possible if height of adjacent
            // is smaller than height of overflowing vertex
            if (ver[u].h > ver[edge[i].v].h)
            {
                // Flow to be pushed is equal to minimum of
                // remaining flow on edge and excess flow.
                int flow = min(edge[i].capacity - edge[i].flow,
                               ver[u].e_flow);

                // Reduce excess flow for overflowing vertex
                ver[u].e_flow -= flow;

                // Increase excess flow for adjacent
                ver[edge[i].v].e_flow += flow;

                // Add residual flow (With capacity 0 and negative
                // flow)
                edge[i].flow += flow;

                updateReverseEdgeFlow(i, flow);

                return true;
            }
        }
    }
    return false;
}

// function to relabel vertex u
void Graph::relabel(int u)
{
    // Initialize minimum height of an adjacent
    int mh = INT_MAX;

    // Find the adjacent with minimum height
    for (int i = 0; i < edge.size(); i++)
    {
        if (edge[i].u == u)
        {
            // if flow is equal to capacity then no
            // relabeling
            if (edge[i].flow == edge[i].capacity)
                continue;

            // Update minimum height
            if (ver[edge[i].v].h < mh)
            {
                mh = ver[edge[i].v].h;

                // updating height of u
                ver[u].h = mh + 1;
            }
        }
    }
}

// main function for printing maximum flow of graph
int Graph::getMaxFlow(int s, int t)
{
    preflow(s);

    // loop untill none of the Vertex is in overflow
    while (overFlowVertex(ver) != -1)
    {
        int u = overFlowVertex(ver);
        if (!push(u))
            relabel(u);
    }

    // ver.back() returns last Vertex, whose
    // e_flow will be final maximum flow
    return ver.back().e_flow;
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
        int max_flow = g.getMaxFlow(0, n+nt+1);
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
