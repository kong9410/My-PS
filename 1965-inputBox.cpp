//boxes를 long long으로 선언안하면 틀림
//왜그런건지는 모르겠네
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long boxes[1001];
    int dp[1001];
    int bigbox = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> boxes[i];
    }
    dp[0] = 0;
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(boxes[i] > boxes[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        bigbox = max(bigbox, dp[i]);
    }
    cout << bigbox+1;
    return 0;
}
