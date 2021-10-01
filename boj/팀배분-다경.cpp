#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;
int n;
vector<int> hate[101]; //싫어하는 사람들 저장
set<int> blue;
set<int> white;
int visited[101]; //0:미지정, 1:청팀, -1:백팀
queue<int> q;
int main(){
    int cnt,h,cur;
    memset(visited, 0, sizeof(visited));

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>cnt;
        for(int j=0; j<cnt; j++){
            cin>>h;
            hate[i].push_back(h);
        }
    }

    cnt=0;
    while(cnt<n){
        for(int k=1; k<=n; k++){
            if(visited[k]) continue;
            q.push(k);
            visited[k]=1;
            break;
        }
        cnt++;
        while(!q.empty()){
            cur= q.front();
            q.pop();
            if(hate[cur].empty()){
                //아무 팀이나 가도 상관 없음
                visited[cur]=1;
            }
            for(int i=0; i<hate[cur].size(); i++){
                if(visited[hate[cur][i]]) continue;
                q.push(hate[cur][i]);
                visited[hate[cur][i]] = -visited[cur];
                cnt++;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==1) blue.insert(i);
        else white.insert(i);
    }

    cout<<blue.size()<<'\n';
    for(auto b: blue) cout<<b<<' ';
    cout<<'\n'<<white.size()<<'\n';
    for(auto w: white) cout<<w<<' ';

    return 0;
}