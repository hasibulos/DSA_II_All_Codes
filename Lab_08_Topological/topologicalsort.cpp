#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<vector<int>> &graph, int V)
{
    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++)
    {
        for (int v : graph[u])
            indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topoOrder;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : graph[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    if (topoOrder.size() != V)
    {
        cout << "Topological sort not possible." << endl;
    }
    else
    {
        cout << "Topological Sort Order: ";
        for (int node : topoOrder)
            cout << node << " ";
        cout << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter " << E << " edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    topologicalSort(graph, V);

    return 0;
}
