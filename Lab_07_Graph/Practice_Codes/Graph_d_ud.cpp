#include <bits/stdc++.h>
using namespace std;
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    int graph[vertices][vertices];
    for (int i = 0; i <= vertices; i++)
    {
        for (int j = 0; j <= vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        // graph[v][u] = 1; // Uncomment this line for undirected graph
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
// This code creates an adjacency matrix for a directed graph based on user input.
// Example Input:
// 5 6
// 0 1
// 0 2
// 3 0
// 1 3
// 2 4
// 1 4
// Example Output:
// 0 1 1 0 0
// 0 0 0 1 1
// 0 0 0 0 1
// 1 0 0 0 0
// 0 0 0 0 0
// Note: To create an undirected graph, uncomment the line 'graph[v][u] = 1;'.