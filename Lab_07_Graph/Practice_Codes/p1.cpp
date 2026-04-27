🧭 1. Pathfinding in a Grid (BFS)

#include<bits/stdc++.h> // All standard libraries included
using namespace std;

const int N = 4; // Grid size is fixed at 4x4
bool visited[N][N]; // To track visited cells during BFS
int dx[] = {0, 0, 1, -1}; // Movement in 4 directions (right, left, down, up)
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y, bool grid[N][N]) {
    // Check if cell is inside grid, not blocked, and not visited
    return x >= 0 && y >= 0 && x < N && y < N && !grid[x][y] && !visited[x][y];
}

bool bfs(bool grid[N][N], int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q; // Queue for BFS
    q.push({startX, startY}); // Start from given cell
    visited[startX][startY] = true; // Mark start as visited

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop(); // Current cell
        if (x == endX && y == endY) return true; // Destination reached

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i]; // Next cell
            if (isValid(nx, ny, grid)) {
                visited[nx][ny] = true;
                q.push({nx, ny}); // Add to queue
            }
        }
    }
    return false; // No path found
}

int main() {
    bool grid[N][N];
    cout << "Enter 4x4 grid (0 = free, 1 = blocked):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j]; // Input grid

    int startX, startY, endX, endY;
    cout << "Enter start coordinates (x y): ";
    cin >> startX >> startY;
    cout << "Enter end coordinates (x y): ";
    cin >> endX >> endY;

    cout << "Is path available? " << (bfs(grid, startX, startY, endX, endY) ? "Yes" : "No") << endl;
    return 0;
}

🧪 Sample Input:

0 0 0 0
0 1 1 0
0 1 0 0
0 0 0 0
0 0
3 3

✅ Output:

Is path available? Yes

💰 2. Cost Calculation (Dijkstra’s Algorithm)

#include<bits/stdc++.h> // All standard libraries included
using namespace std;

const int INF = 1e9; // Infinity value for unreachable nodes
vector<vector<pair<int, int>>> graph; // Adjacency list with weights

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF); // Distance array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0; // Distance to start node is 0
    pq.push({0, start}); // Push start node

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop(); // Current node
        if (d > dist[u]) continue; // Skip if already visited with shorter path

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // Update distance
                pq.push({dist[v], v}); // Push updated node
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    graph.resize(n + 1); // Resize graph

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Input edge
        graph[u].push_back({v, w});
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;

    vector<int> dist = dijkstra(start, n);
    for (int i = 1; i <= n; ++i)
        cout << "Cost to reach node " << i << ": " << dist[i] << endl;
    return 0;
}

🧪 Sample Input:

7 7
1 2 2
1 3 1
2 4 3
3 4 1
4 5 2
5 6 1
6 7 7
1

✅ Output:

Cost to reach node 1: 0
Cost to reach node 2: 2
Cost to reach node 3: 1
Cost to reach node 4: 2
Cost to reach node 5: 4
Cost to reach node 6: 5
Cost to reach node 7: 12

🧮 3. Topological Sorting (Kahn’s Algorithm)

#include<bits/stdc++.h> // All standard libraries included
using namespace std;

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n + 1, 0), result;
    for (int u = 1; u <= n; ++u)
        for (int v : adj[u])
            inDegree[v]++; // Count incoming edges

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (inDegree[i] == 0)
            q.push(i); // Push nodes with no incoming edges

    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u); // Add to result
        for (int v : adj[u]) {
            if (--inDegree[v] == 0)
                q.push(v); // Push if no more incoming edges
        }
    }
    return result;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n + 1); // Adjacency list

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; // Input edge
        adj[u].push_back(v);
    }

    vector<int> order = topoSort(n, adj);
    cout << "Topological Order: ";
    for (int node : order)
        cout << node << " ";
    cout << endl;
    return 0;
}

🧪 Sample Input:

6 6
1 2
1 3
2 4
3 4
4 5
5 6

✅ Output:

Topological Order: 1 2 3 4 5 6
