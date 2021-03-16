#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
int n;
int ops[4];
long long maxnum=-1000000000,minnum=1000000000;
int solution(int idx,long long cur, int oper){
    if(idx==n-1){
        long long now;
        switch(oper){
            case 0:
                now = cur+num[idx];
                break;
            case 1:
                now = cur-num[idx];
                break;
            case 2:
                now = cur*num[idx];
                break;
            case 3:
                now = cur/num[idx];
                break;
        }

        maxnum = max(maxnum,now);
        minnum = min(minnum,now);
        return 1;
    }

    //cur => cur oper num[idx]

    for(int i=0; i<4; i++){
        // + - * /
        if(ops[i]>0){
            ops[i]--;
            switch(oper){
                case 0:
                    solution(idx+1,cur+num[idx],i);
                    break;
                case 1:
                    solution(idx+1,cur-num[idx],i);
                    break;
                case 2:
                    solution(idx+1,cur*num[idx],i);
                    break;
                case 3:
                    solution(idx+1,cur/num[idx],i);
                    break;
            }
            ops[i]++;
        }
    }

    return 0;
}
int main(){
    int tmp;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        num.push_back(tmp);
    }
    for(int i=0; i<4; i++){
        cin>>ops[i];
    }

    for(int i=0; i<4; i++){
        // + - * /
        if(ops[i]>0){
            ops[i]--;
            solution(1,num[0],i);
            ops[i]++;
        }
    }

    cout<<maxnum<<endl<<minnum<<endl;

    return 0;
}