class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res ;
        int start = 0;
        int end = tokens.size();
        stack<int> operand;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                int result = first + second;
                operand.push(result);
            }
            else if(tokens[i]=="-"){
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                int result = first - second;
                operand.push(result);
            }
            else if(tokens[i]=="/"){
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                int result = first / second;
                operand.push(result);
            }
            else if(tokens[i]=="*"){
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                int result = first * second;
                operand.push(result);
            }
            else{
                operand.push(stoi(tokens[i]));
            }
        }
        return operand.top();

    }
};