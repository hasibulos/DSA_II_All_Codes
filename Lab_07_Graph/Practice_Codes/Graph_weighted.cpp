#include <bits/stdc++.h>
using namespace std;
int main()
{
    int vertices, edges, weight;
    cin >> vertices >> edges;
    int graph[vertices][vertices];
    for (int i = 0; i <= vertices; i++)
    {
        for (int j = 0; j <= vertices; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight; // For undirected graph if we comment this work as a directed graph
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}