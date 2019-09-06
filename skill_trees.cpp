#include <string>
#include <vector>

using namespace std;

int count(string skill, string s){
    int prevIdx = 0;
    for(int i = 0; i < skill.length(); i++){
        int idx = 0;
        for(int j = idx; j < s.length(); j++){
            if(s[j] == skill[i]){
                idx = j;
                break;
            }
        }
        for(int k = i+1; k < skill.length(); k++){
            for(int j = prevIdx; j < idx; j++){
                if(s[j] == skill[k]){
                    return 0;
                }
            }
        }
        prevIdx = idx;    
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int tree_len = skill_trees.size();
    for(string s : skill_trees){
        answer += count(skill, s);
    }
    return answer;
}
