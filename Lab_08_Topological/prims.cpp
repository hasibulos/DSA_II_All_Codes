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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(vertex, 0);

    int start_node = 0;
    pq.push(make_pair(0, start_node));

    int total_cost = 0;                            

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int weight = p.first;
        int top_item = p.second;

        if (visited[top_item] == 1)
            continue;

        visited[top_item] = 1;
        total_cost += weight;

        cout << "Added Vertex: " << top_item
             << " and Edge Weight: " << weight << endl;

        for (int i = 0; i < graph[top_item].size(); i++)
        {
            int v = graph[top_item][i].first;
            int w = graph[top_item][i].second;

            if (visited[v] == 0)
            {
                pq.push(make_pair(w, v));
            }
        }
    }

    cout << "\nMinimum Cost of MST = " << total_cost << endl;

    return 0;
}