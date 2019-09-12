#include <bits/stdc++.h>

using namespace std;

int a[100][100], vis[100][100];
int r, c, TotalOne;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check(int x, int y)
{
    return (x >= 0 && x < r && y >= 0 &&  y < c);
}

void dfs(int i, int j)
{
    TotalOne++;
    vis[i][j] = 1;
    for(int k = 0; k < 8; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if(check(x, y) && vis[x][y] == 0 && a[x][y] == 1)
            dfs(x, y);
    }
}

int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];

    int mx = INT_MIN;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(vis[i][j] == 0 && a[i][j] == 1)
            {
                TotalOne = 0;
                dfs(i, j);

                if(TotalOne > mx)
                    mx = TotalOne;
            }
        }
    }

    cout << mx;

    return 0;
}
