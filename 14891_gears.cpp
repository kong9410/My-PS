#include<iostream>
#include<cstring>
using namespace std;

class gear{
public:
    int gearlist[8];
    int top;
    int left;
    int right;
    int status;

    void setGear(int lists[8]){
        memcpy(gearlist, lists, sizeof(gearlist));
        this->setLeft();
        this->setRight();
        this->setTop();
        status = 0;
    }
    void rotate(){
        if(status == 1){
            this->rightRotate();
        }
        else if(status == -1){
            this->leftRotate();
        }
    }
    void setStatus(int before){
        status = before * -1;
    }
    //반시계방향
    void leftRotate(){
        int tmp;
        tmp = gearlist[0];
        for(int i = 0; i < 7; i++){
            gearlist[i] = gearlist[i+1];
        }
        gearlist[7] = tmp;
        status = 0;
    }
    //시계방향
    void rightRotate(){
        int tmp;
        tmp = gearlist[7];
        for(int i = 7; i > 0; i--){
            gearlist[i] = gearlist[i-1];
        }
        gearlist[0] = tmp;
        status = 0;
    }
    void setLeft(){
        left = gearlist[6];
    }
    void setRight(){
        right = gearlist[2];
    }
    void setTop(){
        top = gearlist[0];
    }
    int getRight(){
        return right;
    }
    int getLeft(){
        return left;
    }
    int getTop(){
        return top;
    }
    void initSetup(){
        status = 0;
    }
};

//gears
gear g[4];
void left_dfs(int a, int b){
    if(a < 0){
        return;
    }
    if(g[a].right != g[b].left){
        g[a].setStatus(g[b].status);
        left_dfs(a-1, b-1);
    }
}
void right_dfs(int a, int b){
    if(a >= 4) return;
    if(g[a].left != g[b].right){
        g[a].setStatus(g[b].status);
        right_dfs(a+1, b+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rotate_count;
    int select, direction;
    int res_sum = 0;
    int gearlist[8];
	char c;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
			cin >> c;
			gearlist[j] = (int)(c-'0');
        }
        g[i].setGear(gearlist);
    }
    cin >> rotate_count;
    while(rotate_count--){
        cin >> select >> direction;     //1 : 시계, -1 : 반시계
        select -= 1;    //인덱스 배열과 맞추기
        int beforeLeft = select, beforeRight = select;
        int leftIdx = select-1;
        int rightIdx = select+1;
        g[select].setStatus(direction*-1);
        left_dfs(select-1, select);
        right_dfs(select+1, select);
		    for (int i = 0; i < 4; i++) {
			      g[i].rotate();
            g[i].initSetup();
            g[i].setLeft();
            g[i].setRight();
            g[i].setTop();
        }
        
    }
    int score = 1;
    for(int i = 0; i < 4; i++){
			if (g[i].getTop() == 1) {
				res_sum += score;
			}
            score*=2;
        }
    cout << res_sum;
    return 0;
}
