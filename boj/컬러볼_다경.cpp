#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
vector<pair<int,pair<int,int>>> balls; //<크기,<색, 인덱스>>
int main(){
    int c; //색
    int s; //크기
    int idx;
    int ans[200000];
    int colortotal[200001];
    int sizetotal[200001];
    int total=0;
    memset(ans, 0, sizeof(ans));
    memset(colortotal, 0, sizeof(colortotal));
    memset(sizetotal, 0, sizeof(sizetotal));

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>c>>s;
        balls.push_back({s,{c,i}});
    }
    sort(balls.begin(), balls.end()); //크기순으로 오름차순 정렬

    for(int i=0; i<N; i++){
        //크기가 작고, 색이 다른 공
        s = balls[i].first;
        c = balls[i].second.first, idx = balls[i].second.second;

        if(i!=0 && balls[i-1].second.first==c && balls[i-1].first==s){
            //바로 이전과 크기와 색상이 같을 경우
            ans[idx] = ans[balls[i-1].second.second];
        }
        else{
            ans[idx] = total - colortotal[c]-sizetotal[s];
        }

        sizetotal[s] += s;
        colortotal[c] += s;
        total += s;
    }

    for(int i=0; i<N; i++){
        cout<<ans[i]<<'\n';
    }

    return 0;
}