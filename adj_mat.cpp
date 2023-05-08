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
bool check(int ara[][V], int x, int y)
{
    if (ara[x][y] == 1 && ara[y][x] == 1)
        return true;
    else
        return false;
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

    int x, y;
    cout << "Enter nodes : ";
    cin >> x >> y;
    if (check(mat, x, y))
        cout << "Connected!";
    else
        cout << "Not connected!";
}