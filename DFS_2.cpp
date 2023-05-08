#include <iostream>
using namespace std;
#define V 5

void initialization(int ara[][V])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            ara[i][j] = 0;
}

void edge_making(int ara[][V], int x, int y)
{
    ara[x][y] = 1;
    ara[y][x] = 1;
}

void display(int ara[][V])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < V; j++)
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }
}
void DFS(int i, int ara[][V], int visited[])
{
    cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < V; j++)
    {
        if (ara[i][j] == 1 && visited[j] == 0)
            DFS(j, ara, visited);
    }
}
signed main()
{
    int mat[V][V];

    initialization(mat);

    edge_making(mat, 0, 1);
    edge_making(mat, 0, 2);
    edge_making(mat, 0, 3);
    edge_making(mat, 0, 4);
    edge_making(mat, 1, 2);
    edge_making(mat, 2, 3);
    edge_making(mat, 3, 4);

    display(mat);

    int visited[V] = {0};
    int root;
    cout << "Enter root : ";
    cin >> root;

    DFS(root, mat, visited);
}