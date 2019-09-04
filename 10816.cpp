#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int lower_idx(int target, int len, vector<int> v1){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(target <= v1[mid]) en = mid;
        else st = mid+1;
    }
    return st;
}
int upper_idx(int target, int len, vector<int> v1){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(target < v1[mid]) en = mid;
        else st = mid+1;
    }
    return st;
}
vector<int> solution(vector<int> v1, vector<int> v2, int n, int m){
    vector<int> answer;
    sort(v1.begin(), v1.end());
    for(int s : v1)
        cout << s << " ";
    for(int i = 0; i < v2.size(); i++){
        int et = v2.size();
        int target = v2[i];
        cout << upper_idx(target, et, v1) << " " << lower_idx(target, et, v1) << endl;
        int deb = upper_idx(target,et,v1) - lower_idx(target, et, v1);
        answer.push_back(deb);
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    vector<int> v1, v2;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int card;
        cin >> card;
        v1.push_back(card);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int card;
        cin >> card;
        v2.push_back(card);
    }

    for(int s : solution(v1, v2, n, m))
        cout << s << " ";

    return 0;
}
