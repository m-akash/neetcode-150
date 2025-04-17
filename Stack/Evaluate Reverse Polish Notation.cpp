#include <bits/stdc++.h>
using namespace std;
static unordered_set<string> expression({"+", "-", "*", "/"});
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token : tokens) {
            if(expression.find(token) == expression.end()) {
                st.push(stoi(token));
            }
            else {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                if(token == "+") st.push(x + y);
                else if(token == "-") st.push(x - y);
                else if(token == "*") st.push(x * y);
                else st.push(x / y); 
            }   
        }
        return st.top();
    }
};