#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
} graph[100];

int main()
{
    int parent[100], rnk[100];
    int n, e;
    cout << "Enter number of v and e: " << endl;
    cin >> n >> e;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }

    sort(graph, graph + e, [](Edge a, Edge b)
         { return a.w < b.w; });

    int cost = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++)
    {
        int u = graph[i].u;
        int v = graph[i].v;
        int w = graph[i].w;

        int a = u, b = v;
        while (a != parent[a])
            a = parent[a];
        while (b != parent[b])
            b = parent[b];

        if (a != b)
        {
            cout << u << " - " << v << " = " << w << endl;
            cost += w;

            if (rnk[a] < rnk[b])
                swap(a, b);

            parent[b] = a;
            if (rnk[a] == rnk[b])
                rnk[a]++;
        }
    }

    cout << "\nTotal cost = " << cost << endl;

    return 0;
}
