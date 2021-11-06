#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int N;
int ans[1000001];
int A[1000001];
stack<int> s;
int main(){
    memset(ans,0,sizeof(ans));

    cin>>N;
    for(int i=1; i<N+1; i++){
        cin>>A[i];
    }

    for(int i=N; i>0; i--){

        while(!s.empty() && s.top()<=A[i]) s.pop();

        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();

        s.push(A[i]);
    }

    for(int i=1; i<N+1; i++) cout<<ans[i]<<' ';

    return 0;
}