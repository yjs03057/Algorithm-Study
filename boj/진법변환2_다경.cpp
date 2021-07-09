#include <iostream>
#include <stack>
using namespace std;
int main(){

    int N, B;
    string ans="";
    stack<int> s;
    int quotient, remainder; //몫, 나머지
    //A:10 ~ Z:35

    cin>>N>>B;
    quotient=N;
    while(quotient>=B){
        remainder = quotient%B;
        quotient = quotient/B;
        s.push(remainder);
    }
    s.push(quotient);

    while(!s.empty()){
        if(s.top()>=10) ans += char(s.top()+55);
        else ans += char(s.top()+'0');
        s.pop();
    }

    cout<<ans;

    return 0;
}
