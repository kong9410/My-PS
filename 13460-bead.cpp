#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct bead
{
    int ry;
    int rx;
    int by;
    int bx;
    int cnt;
};
int n, m;
char board[11][11];
int goalY, goalX;
int answer=-1;
int dirY[] = {-1, 0, 1, 0};
int dirX[] = {0, 1, 0, -1};
bool visited[11][11][11][11];
queue<bead> q;
bead ball;


void bfs(){
    while(!q.empty()){
        int ry = q.front().ry;
        int rx = q.front().rx;
        int by = q.front().ry;
        int bx = q.front().rx;
        int cnt = q.front().cnt;
        q.pop();
        if(cnt > 10) {
            return;
        }
        if(ry == goalY && rx == goalX){
            answer = cnt;
            return;
        }
        for(int i = 0; i < 4; i++){
            int dry = ry + dirY[i];
            int drx = rx + dirX[i];
            int dby = by + dirY[i];
            int dbx = bx + dirX[i];
            while(true){
                if(board[dry][drx] == '#'){
                    dry -= dirY[i];
                    drx -= dirX[i];
                    break;
                }
                if(board[dry][drx] == 'O') break;
                dry += dirY[i];
                drx += dirX[i];
            }
            while(true){
                if(board[dby][dbx] == '#'){
                    dby -= dirY[i];
                    dbx -= dirX[i];
                    break;
                }
                if(board[dby][dbx] == 'O') break;
                dby += dirY[i];
                dbx += dirX[i];
            }
            if(goalY == dby && goalX == dbx) continue;
            if(dry == dby && drx == dbx){
                if(i == 0){
                    if(ry < by) dby+=1;
                    else dry+=1;
                }else if(i == 1){
                    if(rx < bx) drx-=1;
                    else dbx-=1;
                }else if(i == 2){
                    if(ry < by) dby-=1;
                    else dry-=1;
                }else if(i == 3){
                    if(rx < bx) drx+=1;
                    else dbx+=1;
                }
            }
            if(!visited[dry][drx][dby][dbx]){
                visited[dry][drx][dby][dbx] = true;
                bead daum = {dry, drx, dby, dbx, cnt+1};
                q.push(daum);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                ball.ry = i;
                ball.rx = j;
            }
            else if (board[i][j] == 'B')
            {
                ball.ry = i;
                ball.rx = j;
            }
            else if (board[i][j] == 'O')
            {
                goalY = i;
                goalX = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    visited[ball.ry][ball.rx][ball.by][ball.bx] = true;
    q.push({ball.ry, ball.rx, ball.by, ball.bx, 0});
    bfs();
    cout << answer;
    
    return 0;
}
