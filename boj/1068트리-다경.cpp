#include <iostream>
#include <cstring>
using namespace std;
int N,del,ans=0;
int nodes[50];
int child_cnt[50];
bool alive[50];

bool DFS(int i){
    bool ret;

    if(!alive[i]) return false;
    if(nodes[i]==-1) return true;

    ret=DFS(nodes[i]);
    alive[i]=ret;

    return ret;
}
int main(){
    memset(child_cnt, 0, sizeof(child_cnt));
    memset(alive, true, sizeof(alive));

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>nodes[i];
        if(nodes[i]==-1) continue; //root
        child_cnt[nodes[i]]++;
    }
    cin>>del;
    alive[del]=false;
    child_cnt[nodes[del]]--;

    for(int i=0; i<N; i++){
        if(DFS(i) && child_cnt[i]<=0){
            ans++;
        }
    }

    cout<<ans;

    return 0;
}