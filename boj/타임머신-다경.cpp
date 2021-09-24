#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N,M;
long long visited[501]; // visited[i]: 1번에서 i번으로 갈 때의 최소시간
vector<pair<int,int>> v[501]; //v[출발지]: <가중치, 목적지>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A,B,C;
    bool cycle=false;

    cin>>N>>M;

    //초기화
    for(int i=1; i<=N; i++) visited[i] = 987654321;

    for(int i=0; i<M; i++){
        cin>>A>>B>>C;
        v[A].push_back({C,B}); // C=0:순간이동 C<0:타임머신으로 과거
    }

    visited[1] = 0; //출발지
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=0; j<v[i].size(); j++){
                if(visited[i]==987654321) continue;
                // 출발지가 방문한 지점이여야만, 갱신 가능
                if(visited[v[i][j].second] > visited[i]+v[i][j].first){
                    visited[v[i][j].second] = visited[i]+v[i][j].first;
                    if(k==N){
                        // n-1번 반복 이후, n번째 반복에서도 거리 값이 갱신된다면 음수 순환 존재
                        cycle = true;
                    }
                }
            }
        }
    }

    //출력
    if(cycle){ //1번 도시에서 어떤 도시로 가는 과정 중 무한히 과거 => -1
        cout<<-1;
        return 0;
    }
    for(int i=2; i<=N; i++){
        //해당 도시로 가는 경로가 없다면 => -1
        if(visited[i] == 987654321) visited[i] = -1;
        cout<<visited[i]<<'\n';
    }

    return 0;
}