#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int root_node;
    cout << "Enter the root node for BFS: ";
    cin >> root_node;

    // start BFS
    int visited[vertices];

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0; // Mark all nodes as unvisited
    }

    queue<int> q;
    q.push(root_node);
    visited[root_node] = 1; // Mark root node as visited

    cout << "BFS Traversal Order: ";

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";

        // Explore all adjacent nodes
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int adjacent_node = graph[current_node][i];
            if (visited[adjacent_node] == 0)
            {
                q.push(adjacent_node);
                visited[adjacent_node] = 1; // Mark as visited
            }
        }
    }

    cout << endl;
    return 0;
}