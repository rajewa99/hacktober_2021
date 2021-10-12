#include <bits/stdc++.h>
using namespace std;

/*Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '[') {
                string temp = "", temp1 = "";
                while (st.top() != "]") {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                int n = 0;
                --i;
                while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
                    i--;
                }
                for (int j = i + 1; s[j] != '['; ++j) {
                    n = n * 10 + (s[j] - '0');
                }
                for (int j = 0; j < n; ++j) {
                    temp1 += temp;
                }
                i++;
                st.push(temp1);
            }
            else if (s[i] == ']' || (s[i] >= 'a' && s[i] <= 'z')) {
                string tmp = "";
                tmp.push_back(s[i]);
                st.push(tmp);
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.decodeString(s) << '\n';
    return 0;
}
