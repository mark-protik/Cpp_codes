#include <iostream>
using namespace std;
void func(int ara[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int ara[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row_size = sizeof(ara) / sizeof(ara[0]);
    int col_size = sizeof(ara[0]) / sizeof(ara[0][0]);

    func(ara, row_size, col_size);
}