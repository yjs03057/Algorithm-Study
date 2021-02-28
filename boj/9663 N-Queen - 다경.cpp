#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,ans=0;
int map[15][15];
vector<pair<int,int>> queens;
//int map[15][15]에 저장했더니, 검사하는 과정에서 시간초과가 나는 것 같아서 벡터 자료형에 퀸 위치 저장
bool rowcolcheck(int x, int y){

    for(int i=0; i<queens.size(); i++){
        if(queens[i].first == x || queens[i].second == y) return false;
    }

    return true;
}
bool diagonalcheck(int x, int y){

    for(int i=0; i<queens.size(); i++){
        if(abs(queens[i].first-x) == abs(queens[i].second-y)) return false;
    }

    return true;
}
int DFS(int cnt){

    if(cnt==n-1){
        ans++;
        return 1;
    }

    for(int i=0; i<n; i++){
        if(rowcolcheck(cnt+1,i) && diagonalcheck(cnt+1,i)){
            queens.push_back(make_pair(cnt+1,i));
            DFS(cnt+1);
            queens.pop_back();
        }
    }

    return 0;
}
int main(){
    cin>>n;

    memset(map,0,sizeof(map));
    for(int i=0; i<n; i++){
        queens.push_back(make_pair(0,i));
        DFS(0);
        queens.pop_back();
    }

    cout<<ans<<endl;

    return 0;
}