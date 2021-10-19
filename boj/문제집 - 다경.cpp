#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int N,M;
vector<int> preSolve[32001]; //먼저 풀어야 함
vector<int> afterSolve[32001];
queue<int> q;
vector<int> ans;
bool visited[32001];
int entry[32001]; //진입차수
int main(){
    int A,B;
    memset(visited, false, sizeof(visited));
    memset(entry, 0, sizeof(entry));

    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>A>>B;
        preSolve[B].push_back(A);
        afterSolve[A].push_back(B);
        entry[B]++;
    }

    int cnt=0,cur;
    while(cnt<N){
        for(int i=1; i<N+1; i++){
            if(!entry[i] && !visited[i]){
                q.push(i);
                ans.push_back(i);
                visited[i] = 1;
                cnt++;
                break;
            }
        }

        cur = q.front();
        q.pop();
        for(int i=0; i<afterSolve[cur].size(); i++){
            entry[afterSolve[cur][i]]--;
        }
    }

    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';


    return 0;
}