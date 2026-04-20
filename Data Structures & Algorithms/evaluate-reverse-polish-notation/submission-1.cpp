class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // [2, 3, +, 3, 1, *, +]
        // 2 -> stack [2]
        // 3 -> stack [2, 3]
        // + -> stack [5]

        stack<string> s;
        int level = 0;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int second_operand = stoi(s.top()); s.pop();
                int first_operand = stoi(s.top()); s.pop();
                if (tokens[i] == "+") s.push(to_string(first_operand + second_operand));
                if (tokens[i] == "-") s.push(to_string(first_operand - second_operand));
                if (tokens[i] == "*") s.push(to_string(first_operand * second_operand));
                if (tokens[i] == "/") s.push(to_string(first_operand / second_operand));
            } else {
                s.push(tokens[i]);
            }
        }

        return stoi(s.top());
    }
};
