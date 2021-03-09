#include <iostream>
#include <stack>
using namespace std;
int main(){
    string input;
    int ans=0, cnt=0; //cnt: P의 갯수
    cin>>input;

    for(int i=0; i<input.size(); i++){
        if(input[i] =='P') cnt++;
        else if(cnt>=2 && input[i+1]=='P'){
            //현재 내가 A일 때, PPAP 만들 수 있는 조건
            cnt--; //PPAP -> P로 치환시 P의 갯수 감소
            i++;
        }
        else{
            //A인데, PPAP가 안 됨.
            cout<<"NP"<<endl;
            return 0;
        }
    }

    if(cnt==1) cout<<"PPAP"<<endl;
    else cout<<"NP"<<endl;
}