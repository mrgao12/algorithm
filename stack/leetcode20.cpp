#include <stack>
#include <string>
using namespace std;

class Solution {
    public:
        bool isValid ( string s ) {
            stack<char> S;

            for ( int i = 0; i < s.length(); i++ ) {
                switch ( s[i] ) {
                    case '(': case '[': case '{': S.push ( s[i] ); break;
                    case ')':
                        if ( ! S.empty() && S.top() == '(' ) S.pop();
                        else return false;
                        break;
                    case ']':
                        if ( ! S.empty() && S.top() == '[' ) S.pop();
                        else return false;
                        break;
                    default:
                        if ( ! S.empty() && S.top() == '{' ) S.pop();
                        else return false;
                        break;
                }
            }

            return S.empty();
        }
};