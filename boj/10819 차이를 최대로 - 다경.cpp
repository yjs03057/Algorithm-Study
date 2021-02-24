#include <iostream>
#include <cstring>
using namespace std;
int n, ans=-1;
int arr[8];
bool visited[8];
int DFS(int cur, int idx, int result){
    if(idx==n-1){
        //끝
        if(ans < result){
            ans = result;
            return result;
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i]) {
            visited[i] = true;
            DFS(arr[i],idx+1,result+abs(cur-arr[i]));
            visited[i] = false;
        }
    }

    return result;
}
int main(){
    int tmp;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        arr[i] = tmp;
    }

    memset(visited, false, sizeof(visited));
    for(int i=0; i<n; i++){
        visited[i] = true;
        DFS(arr[i],0, 0);
        visited[i]= false;
    }

    cout<<ans<<endl;

    return 0;
}