// 틀린문제
// 테스트케이스 2개 미통과
// 인덱스를 고려해야하는데 그부분이 안된듯
// 코드 

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> mp;
    vector<pair<int, pair<int, string>>> t_sum;
    for(int i = 0; i < genres.size(); i++){
        mp[genres[i]].push_back({plays[i], i});
    }
    
    // 장르 합이 제일 큰것을 찾기
    for(auto m = mp.begin(); m != mp.end(); m++){
        int sum = 0;
        for(int j = 0; j < genres.size(); j++){
            if(m->first == genres[j]){
                sum += plays[j];
            }
        }
        t_sum.push_back({sum, m->first});
    }
    sort(t_sum.begin(), t_sum.end());
    reverse(t_sum.begin(), t_sum.end());
    
    // 정렬된 키 순으로 2개씩 구하기
    for(auto m = mp.begin(); m != mp.end(); m++){
        sort(m->second.begin(), m->second.end());
        reverse(m->second.begin(), m->second.end());
    }
    for(int i = 0; i < t_sum.size(); i++){
        for(int j = 0; j < mp[t_sum[i].second].size() && j < 2; j++){
            answer.push_back(mp[t_sum[i].second][j].second);
        }
    }
    return answer;
}
