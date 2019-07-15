#include <iostream>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;

struct snake
{
    int y;
    int x;
    int direction;
};

bool game_over = false;
int _sec = 0;
int board[102][102];
deque<snake> snk;
queue<pair<int, char>> mv;
int dirY[] = {0, 1, 0, -1}; //right, down, left, up
int dirX[] = {1, 0, -1, 0};
int n, k, l;

bool gameover(int headY, int headX)
{
    int len = snk.size();
    if (headY > n || headY <= 0 || headX > n || headX <= 0)
        return true;
    for (int i = 0; i < len; i++)
    {
        if (snk[i].y == headY && snk[i].x == headX)
        {
            return true;
        }
    }
    return false;
}

void play()
{
    while (!game_over)
    {
        
        int headY = snk.front().y;
        int headX = snk.front().x;
        int direction = snk.front().direction;
        //시간이 지나 명령이 들어왔을 때
        if (!mv.empty() && _sec == mv.front().first)
        {
            char comm = mv.front().second;
            //cout << comm << endl;
            mv.pop();
            //왼쪽으로 90도 회전
            if (comm == 'L')
            {
                direction = ((direction + 3) % 4);
            }
            //오른쪽으로 90도 회전
            else if (comm == 'D')
            {
                direction = ((direction + 1) % 4);
            }
        }
        headY += dirY[direction];
        headX += dirX[direction];
        //움직일 수 있는 곳인지 확인
        _sec += 1;
        //cout << _sec << "|" << headX << " " << headY << "|>" << direction << endl;
        game_over = gameover(headY, headX);

        //머리 이동
        snk.push_front({headY, headX, direction});
        if (board[headY][headX] == 1){
            board[headY][headX] = 0;
        }
        //사과를 먹은게 아니면 꼬리자르기
        else if (board[headY][headX] != 1)
        {
            snk.pop_back();
        }
    }
}

int main()
{

    //게임판 크기
    cin >> n;
    //init
    memset(board, 0, sizeof(board));

    //먹이가 있는 곳
    cin >> k;
    while (k--)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }

    //명령어
    cin >> l;
    while (l--)
    {
        int sec;
        char dir;
        cin >> sec >> dir;
        mv.push({sec, dir});
    }

    //뱀의 초기 위치
    snk.push_back({y : 1, x : 1, direction : 0});
    play();
    cout << _sec;
    return 0;
}
