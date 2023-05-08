#include <bits/stdc++.h>
using namespace std;

void display(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
void adj_node(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bool check(vector<int> adj[], int node, int target)
{
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] == target)
            return true;
    }
    return false;
}
void DFS(int i, vector<int> vec[], int visited[])
{
    cout << i << " ";
    visited[i] = 1;
    for (int x : vec[i])
    {
        if (visited[x] == 0)
        {
            DFS(x, vec, visited);
        }
    }
}
int main()
{
    int node, edge;
    cout << "Enter node & edge: ";
    cin >> node >> edge;

    vector<int> ara[node];

    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;

        adj_node(ara, x, y);
    }

    display(ara, node);
    cout << endl;

    int visited[node] = {0};
    int root;
    cout << "enter root : ";
    cin >> root;
    DFS(root, ara, visited);
}