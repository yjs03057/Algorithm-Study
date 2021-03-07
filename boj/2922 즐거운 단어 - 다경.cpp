#include <iostream>
using namespace std;
string input;
int Nsize;
long long int tracking(int vcnt, int ccnt, int lcnt, int idx){
    long long int ans=0;
    //자음, 모음 연속 3개 막기
    if(vcnt>=3 || ccnt>=3 || lcnt>=3) return 0;

    if(idx==Nsize){
        //L포함
        if(lcnt>0) return 1;
        return 0;
    }

    if(input[idx]=='_'){
        ans += (5*tracking(vcnt+1, 0, lcnt, idx+1));
        ans += (20*tracking(0, ccnt+1, lcnt, idx+1));
        ans += tracking(0,ccnt+1, lcnt+1, idx+1);
    }
    else{
        switch(input[idx]){
            case 'A': case 'E': case 'I': case 'O': case 'U':
                ans = tracking(vcnt+1,0,lcnt,idx+1);
                break;
            case 'L':
                ans = tracking(0,ccnt+1,lcnt+1,idx+1);
                break;
            default:
                ans = tracking(0, ccnt+1, lcnt, idx+1);
                break;
        }
    }

    return ans;
}
int main(){
    cin>>input;
    //1. L 포함
    //2. 모음 3개 연속 X
    //3. 자음 3개 연속 X
   Nsize = input.size();
   cout<< tracking(0,0,0,0)<<endl;

    return 0;
}