/*
3. 인쇄기에서 인쇄를 하려한다. 
인쇄 요청 시간에 인쇄 대기 목록에 들어오며
인쇄 순서는 문서의 페이지수가 적은 순서대로 인쇄가된다.
인쇄되는 동안에는 다른 문서를 인쇄할 수 없다.
페이수가 같을 경우 먼저 요청된 문서를 인쇄한다.
입력은 [문서번호, 요청시간, 페이지수]이다.
입력은 요청시간과 문서번호가 증가하는 순으로 주어진다.
페이지 한장 처리하는데 1초가 걸리며
페이지를 전부 처리했을 때 새로운 요청이 들어오면 그 요청까지 포함한 인쇄목록에서 우선순위를 정한 뒤 인쇄를 한다.
문서를 인쇄되는 순으로 나타내어라


입력 : {{1, 0, 5}, {2, 2, 2}, {3, 3, 1}, {4, 4, 1}, {5, 10, 2}}
출력 : 1, 3, 4, 2, 5
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// [문서번호, 인쇄요청시간, 페이지수]
// 1페이지당 1초
// 시간이 같으면 번호 우선

struct s_docu
{
    int docnum;
    int t_time;
    int pages;
};
bool timecompare(vector<int> a, vector<int> b)
{
    if (a[2] == b[2])
    {
        return a[1] < b[1];
    }
    return a[2] < b[2];
}

vector<int> solution(vector<vector<int>> data)
{
    vector<int> answer;
    sort(data.begin(), data.end(), timecompare);
    vector<bool> complete;
    complete.resize(data.size()+1, false);
    for (auto d : data)
    {
        cout << d[0] << d[1] << d[2] << endl;
    }
    int cnt = 0;
    int t_watch = 0;
    s_docu q = {0, 0, 0};
    while (cnt != data.size())
    {
        if (q.pages <= 0)
        {
            q.pages = INT32_MAX;
            bool input = false;
            for (int i = 0; i < data.size(); i++)
            {
                if (t_watch >= data[i][1])
                {
                    if (q.pages > data[i][2] && complete[data[i][0]] == false)
                    {
                        q.docnum = data[i][0];
                        q.t_time = data[i][1];
                        q.pages = data[i][2];
                        input = true;
                    }
                }
            }
            if(input){
                answer.push_back(q.docnum);
                complete[q.docnum] = true;
                cnt += 1;
            }
            else{
                q.pages = 0;
            }
        }
        q.pages -= 1;
        t_watch += 1;
        
        //cout << q.pages << " ";
    }
    return answer;
}
