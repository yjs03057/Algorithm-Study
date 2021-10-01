#include <iostream>
#include <cstring>
using namespace std;
int T,n;
int arr[100001];
int ans,start;
int visited[100001]; //0:미방문, 1:사이클, -1:사이클 실패
bool no_cycle[100001];
bool DFS(int i){
    bool ret=false;
    int nxt=arr[i];
    if(visited[nxt]==0 || (visited[nxt]==-1 && no_cycle[nxt])){
        visited[nxt]=1;
        if(nxt==start) return 1; //팀 구현 완료
        ret = DFS(nxt);
        if(!ret) visited[nxt] = -1;
        return ret;
    }

    //팀 구현 못 함
    no_cycle[nxt]=1;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T>0){
        ans=0;
        memset(visited, 0, sizeof(visited));
        memset(no_cycle,0, sizeof(no_cycle));
        memset(arr, 0, sizeof(arr));

        cin>>n;
        for(int i=1; i<=n; i++) cin>>arr[i];

        for(int i=1; i<=n; i++){
            if(visited[i]>0) continue; //사이클완성이면 안 돌게 함
            start=i;
            DFS(i);
        }
        for(int i=1; i<=n; i++){
            if(visited[i]!=1) ans++; //다음 노드를 보고 방문하지 않는 경우도 있으므로 0도 포함해야함
        }

        cout<<ans<<'\n';
        T--;
    }

    return 0;
}