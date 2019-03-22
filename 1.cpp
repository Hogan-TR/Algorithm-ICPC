#include <iostream>
#include <cstdio>
using namespace std;
int x, y, p, q,mi=9999999;
int m, n;
int a[1000][1000];
int book[1000][1000];
void dfs(int x, int y, int step);
int main()
{
    //行 列
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    scanf("%d%d%d%d", &x, &y, &p, &q);
    book[x][y]=1;
    dfs(x,y,0);
    printf("%d",mi);
    return 0;
}
void dfs(int x, int y, int step)
{
    int e[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int tx, ty;
    if (x == p && y == q)
    {
        if (step < mi)
            mi = step;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        tx = x + e[i][0];
        ty = y + e[i][1];

        if (tx < 1 || tx > m || ty < 1 || ty > n)
            continue;
        if (a[tx][ty] == 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
}