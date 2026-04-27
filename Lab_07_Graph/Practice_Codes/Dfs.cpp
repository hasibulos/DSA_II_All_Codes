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
    cout << "Enter the root node for DFS: ";
    cin >> root_node;

    int visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0; // Mark all nodes as unvisited
    }

    stack<int> st;
    st.push(root_node);

    cout << "DFS Traversal Order: ";

    while (!st.empty())
    {
        int current_node = st.top();
        st.pop();

        if (visited[current_node] == 1)
            continue;

        // Visit node
        cout << current_node << " ";
        visited[current_node] = 1;

        
        for (int i = graph[current_node].size() - 1; i >= 0; i--)
        {
            int adjacent_node = graph[current_node][i];
            if (visited[adjacent_node] == 0)
            {
                st.push(adjacent_node);
            }
        }
    }

    cout << endl;
    return 0;
}
