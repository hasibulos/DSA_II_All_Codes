#include <bits/stdc++.h> // সব standard library include করা
using namespace std;

// ---------------------------
// Edge structure
// ---------------------------
struct Edge
{
    int u, v, w; // u থেকে v তে weight w
};

int main()
{
    int vertex, edges;
    cin >> vertex >> edges; // vertex সংখ্যা ও edge সংখ্যা input নেওয়া

    vector<Edge> graph(edges); // সব edge সংরক্ষণ করার জন্য array তৈরি

    // ---------------------------
    // Input edges (number-only)
    // ---------------------------
    for (int i = 0; i < edges; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].w; // u, v, weight
    }

    int source = 0;                    // source vertex (0 ধরে নেওয়া)
    vector<int> dist(vertex, INT_MAX); // distance array init করা, সব infinity
    dist[source] = 0;                  // source distance = 0

    // ---------------------------
    // Step 1: Relax all edges vertex-1 times
    // ---------------------------
    for (int i = 1; i <= vertex - 1; i++) // vertex-1 বার repeat করা
    {
        for (int j = 0; j < edges; j++) // সব edge check করা
        {
            int u = graph[j].u; // edge start
            int v = graph[j].v; // edge end
            int w = graph[j].w; // edge weight

            // যদি u পর্যন্ত path জানা থাকে এবং path দিয়ে v improve হয়
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w; // distance update করা
            }
        }
    }

    // ---------------------------
    // Step 2: Check negative weight cycle
    // ---------------------------
    bool NegativeCycle = false;
    for (int j = 0; j < edges; j++)
    {
        int u = graph[j].u;
        int v = graph[j].v;
        int w = graph[j].w;

        // যদি আবার distance improve হয় → negative cycle আছে
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
        {
            cout << "Negative weight cycle detected" << endl;
            NegativeCycle = true;
            break; // loop stop
        }
    }

    if (NegativeCycle)
        return 1; // exit program

    // ---------------------------
    // Step 3: Print shortest distances
    // ---------------------------
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << "Vertex " << i << " Distance: " << dist[i] << endl;
    }

    return 0;
}
