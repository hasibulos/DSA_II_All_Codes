#include <bits/stdc++.h> // সব স্ট্যান্ডার্ড হেডার একসাথে ইনক্লুড করা হয়েছে
using namespace std;

// ===== Function to perform Topological Sort using Kahn's Algorithm =====
void topologicalSort(vector<vector<int>> &graph, int V)
{
    vector<int> indegree(V, 0); // প্রতিটি node-এর indegree count রাখার জন্য ভেক্টর

    // Step 1: প্রতিটি node-এর indegree (কতগুলো incoming edge আছে) বের করা
    for (int u = 0; u < V; u++)
    {
        for (int v : graph[u])
            indegree[v]++; // u থেকে v তে edge থাকলে, v এর indegree ১ বাড়বে
    }

    // Step 2: indegree == 0 এমন সব node কে queue তে রাখা
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i); // যাদের incoming edge নাই, তারা আগে আসতে পারে

    vector<int> topoOrder; // টপোলজিকাল অর্ডার সংরক্ষণ করার জন্য ভেক্টর

    // Step 3: যতক্ষণ queue খালি না হয়, node বের করে প্রসেস করা
    while (!q.empty())
    {
        int u = q.front();      // queue এর প্রথম element নেওয়া
        q.pop();                // queue থেকে remove করা
        topoOrder.push_back(u); // এই node কে টপোলজিকাল অর্ডারে যোগ করা

        // Step 4: এই node থেকে যেসব neighbor আছে, তাদের indegree কমানো
        for (int v : graph[u])
        {
            indegree[v]--; // কারণ u node এখন remove হয়ে গেছে
            if (indegree[v] == 0)
                q.push(v); // যদি কোনো node-এর indegree 0 হয়ে যায়, তাকে queue তে তোলা
        }
    }

    // Step 5: চেক করা — সব vertex টপোলজিকাল অর্ডারে এসেছে কিনা
    if (topoOrder.size() != V)
    {
        cout << "Graph has a cycle! Topological sort not possible." << endl;
        // যদি না আসে, তাহলে graph cyclic — তাই sort করা সম্ভব না
    }
    else
    {
        // Step 6: টপোলজিকাল অর্ডার প্রিন্ট করা
        cout << "Topological Sort Order: ";
        for (int node : topoOrder)
            cout << node << " ";
        cout << endl;
    }
}

// ===== Main Function =====
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V; // vertex সংখ্যা ইনপুট নেওয়া

    cout << "Enter number of edges: ";
    cin >> E; // edge সংখ্যা ইনপুট নেওয়া

    vector<vector<int>> graph(V); // adjacency list তৈরি করা

    cout << "Enter " << E << " edges (u v) meaning u -> v:\n";
    // Step 1: সব edge ইনপুট নেওয়া এবং graph তৈরি করা
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;         // u -> v edge ইনপুট নেওয়া
        graph[u].push_back(v); // adjacency list এ যোগ করা
    }

    // Step 2: টপোলজিকাল sort ফাংশন কল করা
    topologicalSort(graph, V);

    return 0; // প্রোগ্রাম শেষ
}
#include <bits/stdc++.h> // সব স্ট্যান্ডার্ড হেডার একসাথে ইনক্লুড করা হয়েছে
using namespace std;

// ===== Function to perform Topological Sort using Kahn's Algorithm =====
void topologicalSort(vector<vector<int>> &graph, int V)
{
    vector<int> indegree(V, 0); // প্রতিটি node-এর indegree count রাখার জন্য ভেক্টর

    // Step 1: প্রতিটি node-এর indegree (কতগুলো incoming edge আছে) বের করা
    for (int u = 0; u < V; u++)
    {
        for (int v : graph[u])
            indegree[v]++; // u থেকে v তে edge থাকলে, v এর indegree ১ বাড়বে
    }

    // Step 2: indegree == 0 এমন সব node কে queue তে রাখা
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i); // যাদের incoming edge নাই, তারা আগে আসতে পারে

    vector<int> topoOrder; // টপোলজিকাল অর্ডার সংরক্ষণ করার জন্য ভেক্টর

    // Step 3: যতক্ষণ queue খালি না হয়, node বের করে প্রসেস করা
    while (!q.empty())
    {
        int u = q.front();      // queue এর প্রথম element নেওয়া
        q.pop();                // queue থেকে remove করা
        topoOrder.push_back(u); // এই node কে টপোলজিকাল অর্ডারে যোগ করা

        // Step 4: এই node থেকে যেসব neighbor আছে, তাদের indegree কমানো
        for (int v : graph[u])
        {
            indegree[v]--; // কারণ u node এখন remove হয়ে গেছে
            if (indegree[v] == 0)
                q.push(v); // যদি কোনো node-এর indegree 0 হয়ে যায়, তাকে queue তে তোলা
        }
    }

    // Step 5: চেক করা — সব vertex টপোলজিকাল অর্ডারে এসেছে কিনা
    if (topoOrder.size() != V)
    {
        cout << "Graph has a cycle! Topological sort not possible." << endl;
        // যদি না আসে, তাহলে graph cyclic — তাই sort করা সম্ভব না
    }
    else
    {
        // Step 6: টপোলজিকাল অর্ডার প্রিন্ট করা
        cout << "Topological Sort Order: ";
        for (int node : topoOrder)
            cout << node << " ";
        cout << endl;
    }
}

// ===== Main Function =====
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V; // vertex সংখ্যা ইনপুট নেওয়া

    cout << "Enter number of edges: ";
    cin >> E; // edge সংখ্যা ইনপুট নেওয়া

    vector<vector<int>> graph(V); // adjacency list তৈরি করা

    cout << "Enter " << E << " edges (u v) meaning u -> v:\n";
    // Step 1: সব edge ইনপুট নেওয়া এবং graph তৈরি করা
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;         // u -> v edge ইনপুট নেওয়া
        graph[u].push_back(v); // adjacency list এ যোগ করা
    }

    // Step 2: টপোলজিকাল sort ফাংশন কল করা
    topologicalSort(graph, V);

    return 0; // প্রোগ্রাম শেষ
}
