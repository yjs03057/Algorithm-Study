#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int N,K;
int main(){
    int cur,next;
    queue<int> q;
    stack<int> st;
    int visited[100001]; //부모 노드 저장
    memset(visited, -1, sizeof(visited));

    cin>>N>>K;
    // 수빈 위치 : X
    // 걷기 : X+1, X-1
    // 순간이동 : 2*X

    visited[N]=-2; //시작점 표시
    q.push(N);
    while(!q.empty()){
        cur = q.front();
        if(cur==K) break;

        //순간이동
        next = 2*cur;
        if(next>=0 && next<=100000) {
            if (visited[next]==-1) {
                q.push(next);
                visited[next] = cur;
            }
        }

        //걷기
        next = cur+1;
        if(next>=0 && next<=100000){
            if(visited[next]==-1){
                q.push(next);
                visited[next] = cur;
            }
        }

        next = cur-1;
        if(next>=0 && next<=100000){
            if(visited[next]==-1){
                q.push(next);
                visited[next] = cur;
            }
        }

        q.pop();
    }

    while(1){
        st.push(cur);
        cur = visited[cur];
        if(cur==-2) break;
    }
    cout<<st.size()-1<<endl;
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }

    return 0;
}