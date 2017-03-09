#include <iostream>
#include <stack>
#include <string>
using namespace std;
int priority(char c);
int main() {
    stack<char> op;
    char* ans = new char[40];
    string middle;
    char ch;
        int num = 0;
        cin>>middle;
        for(int j=0; j<middle.size(); j++) {
            ch = middle[j];
            if(ch>='0'&&ch<='9') {
                ans[num++] = ch;
            }
            else if( ch == '(') {
                op.push(ch);
            }
            else if( ch == ')') {
                while(op.top() != '(') {
                    ans[num++] = op.top();
                    op.pop();
                }
                op.pop();
            }
            else {
                if(op.empty())
                    op.push(ch);
                else {
                    if(priority(ch) > priority(op.top()))
                        op.push(ch);
                      else {
                          while(!op.empty()&&(priority(ch)<=priority(op.top()))) {
                              ans[num++] = op.top();
                              op.pop();
                          }
                          op.push(ch);
                      }
                }
            }
        }
        while(!op.empty()) {
            ans[num++] = op.top();
            op.pop();
        }
        for(int i=0; i<num; i++)
            cout<<ans[i];
        cout<<endl;
    delete [] ans;
    return 0;
}

int priority(char c) {
    if(c == '-' || c == '+')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    return 0;
}
