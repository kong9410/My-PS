/*
2. 다음 문자가 적혀져있는 판이있다.
각 열의 맨위에서 부터 시작하며 이동한 칸의 문자를 보고 다음과 같이 처리한다.
'#' : 아래로 한칸 이동
'>' : 오른쪽 한칸 이동
'<' : 왼쪽 한칸 이동
'*' : 한번 방문시 아래로 한칸 이동, 두번째 방문시 멈춘다.
'>'와 '<'가 겹쳐 영원히 반복되는 경우는 주어지지않는다.
오른쪽이나 왼쪽 끝으로 벗어난 경우는 카운트를 하지 않는다.
각 열에서 출발하여 판의 맨 밑에 도착한 경우는 몇개인지 세어라.

예시

입력 : ["######", "##>#*#", "<#<**>", "##*>#<", "##**##"]

######  << 시작
##>#*#
<#<**>
##*>#<
##**##
             << 도착
답 : 3 
*/
int cnt = 0;

void dfs(int y, int x, bool stop, const vector<string> drum){
    if(x < 0 || x >= drum[0].size()) return;
    if(y == drum.size()){
        cnt += 1;
        return;
    }
    if(drum[y][x] == '#'){
        y+=1;
    }
    else if(drum[y][x] == '>'){
        x+=1;
    }
    else if(drum[y][x] == '<'){
        x-=1;
    }
    else if(drum[y][x] == '*'){
        if(stop == false){
            stop = true;
            y += 1;
        }
        else{
            return;
        }
    }
    dfs(y, x, stop, drum);
}

int solution(vector<string> drum){
    int answer = -1;
    int bottom = drum[0].size();
    int gesu = drum.size();
    for(int i = 0; i < gesu; i++){
        dfs(0, i, false, drum);
    }
    answer = cnt;
    return answer;
}
