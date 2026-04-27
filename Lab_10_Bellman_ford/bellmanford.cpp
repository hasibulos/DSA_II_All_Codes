#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<Edge> graph(edges);
    map<char, int> mp; // for mapping characters to integers
    int index = 0;     // to assign new integer indices

    for (int i = 0; i < edges; i++)
    {
        // Read input as characters
        char u, v;
        int w;
        cin >> u >> v >> w;

        if (mp.find(u) == mp.end())
        {
            mp[u] = index++;
        }
        if (mp.find(v) == mp.end())
        {
            mp[v] = index++;
        }

        graph[i].u = mp[u];
        graph[i].v = mp[v];
        graph[i].w = w;
        // cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }

    int source = 0;
    vector<int> dist(vertex, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= vertex - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = graph[j].u;
            int v = graph[j].v;
            int w = graph[j].w;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool NegativeCycle = false;
    for (int j = 0; j < edges; j++)
    {
        int u = graph[j].u;
        int v = graph[j].v;
        int w = graph[j].w;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
        {
            cout << "Negative weight cycle detected" << endl;
            NegativeCycle = true;
            break;
        }
    }

    if (NegativeCycle)
        return 1;

    else
    {
        // cout << "Vertex Distance from Source" << endl;
        // for (int i = 0; i < vertex; i++)
        // {
        //     cout << "Vertex: " << i << " " << dist[i] << endl;
        // }
        for (const auto &pair : mp)
        {
            char vertexChar = pair.first;
            int vertexIndex = pair.second;
            cout << "Vertex: " << vertexChar << " Distance from Source: " << dist[vertexIndex] << endl;
        }
    }

    return 0;
}

/*Input:


7 12
0 1 -1
0 2 4
1 5 2
1 6 2
2 4 -2
3 4 9
3 2 6
4 5 5
5 2 -5
5 6 6
6 0 2
6 3 -2


*/