#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m, tc=1;
bool visited[501];
vector<int> edges[501];
bool DFS(int num, int before){
    int nxt;
    bool ret=true;
    visited[num]=1;

    for(int i=0; i<edges[num].size(); i++){
        nxt = edges[num][i];
        if(nxt==before) continue;
        if(visited[nxt]) return false;

        ret = DFS(nxt,num);
        if(!ret) return ret;
    }

    return ret;
}
int main(){
    int a,b, tree=0;


    while(1){
        cin>>n>>m;
        if(n==0&&m==0) break;
        //초기화
        for(int i=0; i<=n; i++) edges[i].clear();
        memset(visited, false, sizeof(visited));
        tree=0;

        for(int i=0; i<m; i++){
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            if(DFS(i,-1)) tree++;
        }

        cout<<"Case "<<tc++<<": ";
        if(tree==0) cout<<"No trees."<<'\n';
        else if(tree==1) cout<<"There is one tree."<<'\n';
        else cout<<"A forest of "<<tree<<" trees."<<'\n';
    }

    return 0;
}