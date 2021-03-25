#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m, ans=987654321;
int map[52][52];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
bool closed[13]; //폐업 체크
void calc(){
    int sum=0;

    for(int i=0; i<house.size(); i++){
        int least=987654321;

        for(int j=0; j<chicken.size(); j++){
            if(!closed[j]){
                //폐업하지 않은 치킨 집
                least = min(least,
                            abs(chicken[j].first - house[i].first)
                            + abs(chicken[j].second - house[i].second));
            }
        }

        sum += least;
    }
    ans = min(ans, sum);

    return;
}
void setClose(int idx, int cnt){
    if(cnt==chicken.size()-m){
        //치킨 거리 계산
        calc();
        return;
    }

    for(int i=idx; i<chicken.size(); i++){
        closed[i] = true;
        setClose(i+1,cnt+1);
        closed[i] = false;
    }

    return;
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            if(map[i][j]==2) chicken.push_back(make_pair(i,j));
            else if(map[i][j]==1) house.push_back(make_pair(i,j));
        }
    }

    memset(closed, false, sizeof(closed));
    setClose(0,0);  //폐업시킬 치킨집 고름

    cout<<ans<<endl;

    return 0;
}