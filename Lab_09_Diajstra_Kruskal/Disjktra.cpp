#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<pair<int, int>>> graph(vertex);

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int source = 0;
    int visited[vertex];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < vertex; i++)
    {
        visited[i] = INT_MAX;
    }

    visited[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int cost = graph[u][i].second;

            if (visited[v] > visited[u] + cost)
            {
                visited[v] = visited[u] + cost;
                pq.push(make_pair(visited[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " \t " << visited[i] << "\n";
    }

    return 0;
}
