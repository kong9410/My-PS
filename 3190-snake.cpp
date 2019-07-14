#include <iostream>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;

struct snake{
    int y;
    int x;
    int direction;
};

bool game_over = false;
int sec = 0;
int board[101][101];
deque<snake> snk;
queue<pair<int, int>> mv;
int dirY[] = {1, 0};
int dirX[] = {0, -1};

void play(){
    while(!game_over){
        int headY = snk.front().y;
        int headX = snk.front().x;
        int direction = snk.front().direction;
        //시간이 지나 명령이 들어왔을 때
        if(!mv.empty() && sec == mv.front().first){
            char comm = mv.front().second;
            mv.pop();
            if(comm = 'L'){
                direction = 1;
            }
            else if(comm = 'D'){
                direction = 0;
            }
        }
        //시간이 지나지 않았을 때
        else{
            headY += dirY[direction];
            headX += dirX[direction];
            if(board[headY][headX] == 1){
                
            }
        }
        
    }
}

int main(){
    int n, k, l;

    //게임판 크기
    cin >> n;
    //init
    memset(board, 0, sizeof(board));

    //먹이가 있는 곳
    cin >> k;
    while(k--){
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }

    //명령어
    cin >> l;
    while(l--){
        int sec;
        char dir;
        cin >> sec >> dir;
        mv.push({sec, dir});
    }

    //뱀의 초기 위치
    snk.push_back({y : 0, x : 0, direction : 1});

    return 0;
}
