#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
        int evalRPN( vector<string>& tokens ) {
            stack<int> S;
            for ( int i = 0; i < tokens.size(); i++ ) {
                string op = tokens[i];
                if ( op[0] >= '0' && op[0] <= '9' ) {
                    int num = stoi ( op );
                    S.push ( num );
                } else {
                    int num1 = S.top(); S.pop();
                    int num2 = S.top(); S.pop();
                    switch ( op[0] )
                    {
                        case '+': S.push ( num1 + num2 ); break;
                        case '-': S.push ( num2 - num1 ); break;
                        case '*': S.push ( num1 * num2 ); break;
                        default: S.push ( num2 / num1 ); break;
                    }
                }
            }
            return S.top();
        }
};