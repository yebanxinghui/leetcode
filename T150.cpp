class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens)
        {
            int len = i.size()-1;
            if(i[len] >= '0' && i[len] <= '9')
            {
                s.push(stoi(i));
            }
            else
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                switch(i[0])
                {
                    case '+': s.push(num1 + num2);break;
                    case '-': s.push(num2 - num1);break;
                    case '*': s.push(num2 * num1);break;
                    case '/': s.push(num2 / num1);break;
                }
            }
        }
        return s.top();
    }
};