#include<iostream>
#include<algorithm>
using namespace std;

long long *arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
    int j = 1;
    cin >> test_case;
    while(test_case--){
        int p;
        cin >> p;
        arr = new long long[p];
        for(int i = 0; i < p; i++){
            cin >> arr[i];
        }
        if(p == 1){
            cout << "#" << j++ << " " << arr[0] * arr[0] << endl;
        }
        else{
            sort(arr, arr+p);
            cout << "#" << j++ << " " << arr[0] * arr[p-1] << endl;
        }
    }

    return 0;
}
