#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,d,k,c;
vector<int> sushi;
int arr[3001];
int cnt=0; //가짓수
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp, ans=0;
    memset(arr, 0, sizeof(arr));

    cin>>N>>d>>k>>c;
    for(int i=0; i<N; i++){
        cin>>tmp;
        sushi.push_back(tmp);
    }

    int start=0,end=k-1;
    for(int i=0; i<k; i++){
        if(!arr[sushi[i]]) cnt++;
        arr[sushi[i]]++;
    }
    if(!arr[c]) ans = max(ans, cnt+1);
    else ans = max(ans, cnt);

    while(start<N-1){
        //start
        arr[sushi[start]]--;
        if(!arr[sushi[start]]) cnt--; //종류 감소
        start++;

        //end
        if(++end==N) end=0; //순환
        if(!arr[sushi[end]]) cnt++; //종류 증가
        arr[sushi[end]]++;

        if(!arr[c]) ans = max(ans, cnt+1);
        else ans = max(ans, cnt);
    }

    cout<<ans;

    return 0;
}