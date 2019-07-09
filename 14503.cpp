#include <iostream>
#include <cstring>
using namespace std;

int n, m;

int room[55][55];
bool clean[55][55];
int res = 0;
//0 북, 1 동, 2 남, 3 서
int dirR[] = {1, 0, -1, 0};
int dirC[] = {0, 1, 0, -1};
void dfs(int r, int c, int d, bool used)
{
    //청소를 안하고, 뒤로 돌아온 상태가 아니라면
    if (!clean[r][c] && !used)
    {
        //cout<<r<<c<<"clean\n";
        clean[r][c] = true;
        res += 1;
    }
    bool flag = false;
    //4방향 청소 유무 확인
    for (int i = 0; i < 4; i++)
    {
        int y = r + dirR[i];
        int x = c + dirC[i];
        if (!clean[y][x])
        {
            if(room[y][x]!=1){
                flag = true;
                break;
            }
        }
    }
    //청소할 수 있는 곳이 없으면 뒤로 돌아가기
    if (!flag)
    {
        int y = r + dirR[((d + 2) % 4)];
        int x = c + dirC[((d + 2) % 4)];
        if (room[y][x] == 1)
            return;
        used = true;
        dfs(y, x, d, used);
        return;
    }
    int t = d - 1;
    if (t < 0)
        t = 3;
    int dr = r + dirR[t];
    int dc = c + dirC[t];
    //청소할 곳이 있다면 그 방향으로 회전 후 한칸 전진
    if (!clean[dr][dc] && room[dr][dc] != 1)
    {
        used = false;
        d = t;
        dfs(dr, dc, d, used);
    }
    //청소할 곳이 없다면 그 방향으로 회전 후 다시 탐색
    else if (clean[dr][dc] || room[dr][dc] == 1)
    {
        used = true;
        d = t;
        dfs(r, c, d, used);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, c, d; //d=0북, 1동, 2남, 3서
    cin >> n >> m;
    cin >> r >> c >> d;
    memset(clean, false, sizeof(clean));
    for (int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            room[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> room[i][j];
        }
    }

    r+=1;
    c+=1;
    dfs(r, c, d, false);
    cout << res;
    return 0;
}
