#include <iostream>
#include <string>
using namespace std;
int N,K;
string num;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K>>num;
    //K개의 숫자 제거
    int tmp=K;

    char ans[500001];
    ans[0] = num[0];
    int idx=1;

    for(int i=1; i<N; i++){
        //삭제 횟수가 남아있고, 바로 앞 숫자보다 클 경우
        //=> 바로 앞 숫자 삭제하고 넣기
        while(ans[idx-1]<num[i] && K>0 && idx>0){
            idx--;
            K--;
        }
        ans[idx] = num[i];
        idx++;
    }

    for(int i=0; i<N-tmp; i++) cout<<ans[i];

    return 0;
}