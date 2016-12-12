class Solution {
public:
    string parseTernary(string expression) {
        while (expression.size() > 5) {
            int pos = expression.find_last_of('?');
            expression = expression.substr(0,pos-1) 
                    + (expression[pos-1] == 'T' ? expression[pos+1] : expression[pos+3]) 
                    + expression.substr(pos+4);
        }
        return expression[0] == 'T' ? expression.substr(2,1) : expression.substr(4,1);
    }
};
