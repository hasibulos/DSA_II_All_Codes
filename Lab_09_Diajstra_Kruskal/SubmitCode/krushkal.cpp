#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int parent[vertex];
    int rank[vertex];

    for (int i = 0; i < vertex; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    vector<pair<int, int>> mst;

    for (int i = 0; i < edge; i++)
    {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        int pu = u;
        while (parent[pu] != pu)
        {
            parent[pu] = parent[parent[pu]];
            pu = parent[pu];
        }
        int pv = v;
        while (parent[pv] != pv)
        {
            parent[pv] = parent[parent[pv]];
            pv = parent[pv];
        }
        if (pu != pv)
        {
            mst.push_back({u, v});
            totalWeight += w;

            if (rank[pu] < rank[pv])
                parent[pu] = pv;
            else if (rank[pu] > rank[pv])
                parent[pv] = pu;
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n";
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].first << " - " << mst[i].second << " = " << edges[i].first << "\n";
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";

    return 0;
}
