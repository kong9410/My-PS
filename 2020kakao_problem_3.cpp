#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<vector<int>> key_rotate(const vector<vector<int>>& key){
	vector<vector<int>> rot;
	rot.resize(key.size());
	for(int c = 0; c < key.size(); c++){
		rot[c].resize(key.size());
	}
	
	// cout << rot.size() << " " << rot[0].size() << endl;
	for(int r = 0; r < key.size(); r++){
		for(int c = 0; c < key.size(); c++){
			rot[key.size() - c - 1][r] = key[r][c];
		}
	}
	return rot;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
	int limit = key.size() + (key.size()-1) * 2;
	int center = key.size() - 1;
	int rotate = 4;
	while(rotate--){
		for(int startR = 0; startR < limit - key.size() + 1; startR++){
			for(int startC = 0; startC < limit - key.size() + 1; startC++){
				int bg[limit][limit];
				memset(bg, 0, sizeof(bg));
				for(int r = startR; r < startR + key.size(); r++){
					for(int c = startC; c < startC + key.size(); c++){
						bg[r][c] += key[r - startR][c - startC];
					}
				}
				bool flag = true;
				for(int r = center; r < center + key.size(); r++){
					for(int c = center; c < center + key.size(); c++){
						bg[r][c] += lock[r-center][c-center];
						if(!(bg[r][c] == 1)){
							flag = false;
						}
					}
				}
				for(int r = 0; r < limit; r++){
					for(int c = 0; c < limit; c++){
						cout << bg[r][c] << " ";
					}
					cout << endl;
				}
				if(flag) cout << "true" << endl;
				else cout << "false\n";
				cout << endl;
				if(flag) answer = true;
			}
		}
		key = key_rotate(key);
	}
    return answer;
}

int main()
{
	cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
}
