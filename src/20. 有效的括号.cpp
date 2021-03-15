class Solution {
public:
    bool isValid(string s) {
        if (s.size() <= 1)
            return false;
        stack<char> store;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                store.push(c);
            else {
                if (store.empty())
                    return false;
                char temp = store.top();
                store.pop();
                if (c == ')') {
                    if (temp == '(')
                        continue;
                    else
                        return false;
                }
                else if (c == '}') {
                    if (temp == '{')
                        continue;
                    else
                        return false;
                }
                else if (c == ']') {
                    if (temp == '[')
                        continue;
                    else
                        return false;
                }
            }
        }
        if (!store.empty())
            return false;
        return true;
    }
};