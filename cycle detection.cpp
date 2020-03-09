#include <iostream>
using namespace std;
int node, edge;
int mat[500][500];
bool vis[500];

bool DFS(int u)
{
    if (vis[u])
        return true;

    vis[u] = true;

    for (int i = 1; i <= node; i++)
    {
        if (mat[u][i])
        {
            if (DFS(i))
            {
                cout << i << " ";
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }
    for (int i = 1; i <= node; i++)
    {
        for(int k=1;k<=node;k++){
            vis[k]=0;
        }
        if (DFS(i))
        {
            cout << "\nDetected" << endl;
        }
        else
            cout << "\nNot Detected" << endl;
    }
}
/*
7 6
1 2
2 3
3 4
4 5
5 6
6 7

 */
