#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void initialization(int *ara, int node)
{
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            *((ara + i * node) + j) = 0;
}

void edge_making(int *ara, int x, int y, int node)
{
    *((ara + x * node) + y) = 1;
    *((ara + y * node) + x) = 1;
}

void display(int *ara, int node)
{
    for (int i = 0; i < node; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < node; j++)
        {
            cout << *((ara + i * node) + j) << " ";
        }
        cout << endl;
    }
}

signed main()
{

    int node, edge;
    cout << "Enter total node and edge : ";
    cin >> node >> edge;

    int mat[node][node];
    int node1, node2;

    initialization(&mat[0][0], node);

    for (int i = 0; i < edge; i++)
    {
        cout << "Enter adj node : ";
        cin >> node1 >> node2;
        edge_making(&mat[0][0], node1, node2, node);
    }

    display(&mat[0][0], node);

    cout << endl;

    //?............................. another segment....................................
    //!.................................................................................

    vector<int> arr;
    queue<int> q;
    int visited[node] = {0};

    //! you can choose root anything !
    int root;
    cout << "Root : ";
    cin >> root;
    
    q.push(root);
    visited[root] = 1;
    arr.push_back(root);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int j = 0; j < node; j++)
        {
            if (mat[x][j] == 1 && visited[j] == 0)
            {
                arr.push_back(j);
                visited[j] = 1;
                q.push(j);
            }
        }
        
    }



























    cout << "BFS graph : ";
    for (auto x : arr)
        cout << x << " ";
}