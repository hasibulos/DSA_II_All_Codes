#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> graph(vertices + 1); // +1 for 1-based indexing

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        // graph[v].push_back({u, w}); // Uncomment this for undirected graph
    }

    // Output adjacency list
    for (int i = 1; i <= vertices; i++)
    {
        cout << i << " -> ";
        for (auto &edge : graph[i])
        {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
