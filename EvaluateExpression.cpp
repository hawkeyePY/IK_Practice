
/*
 * Complete the function below.
 */
string generateString (string op, string s, string currS, int pos) {
    
    string newString;
    if (op=="") { 
        if(currS.empty()) {
            newString = s[pos];
            newString += s[pos+1];
            
        } else {
            newString = currS+s[pos+1];
        } 
    }
        
    if (op=="*") {
        if(currS.empty()) {
            newString = s[pos];
            newString += "*";
            newString += s[pos+1];
        } else {
            newString = currS+"*"+s[pos+1];
        } 
    }
       
    if (op=="+") {
        if(currS.empty()) {
            newString = s[pos];
            newString += "+";
            newString += s[pos+1];
        } else {
            newString = currS+"+"+s[pos+1];
        } 
    }
    
    return newString;
}

int precedence(char op) {
    if (op=='+') {
        return 1;
    }
    if (op=='*') {
        return 2;
    }
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch(op) {
        case '+': return a+b;
        case '*': return a*b;
    }
}

bool checkExpression(long long int target, string final) {
    stack<int> value;
    stack<int> ops;
    
    for(int i=0; i<final.length();i++) {
        
        if(isdigit(final[i])) {
            int val =0;
            while(i<final.length() && isdigit(final[i])) {
                val = (val*10) + (final[i]-'0');
                i++;
            }
            
            
            value.push(val);
        }
        {
            
            while(!ops.empty() && precedence(ops.top())
                               >= precedence(final[i])) {
                int val2 = value.top();
                
                value.pop();
                int val1 = value.top();
                value.pop();
                char op = ops.top();
                ops.pop();
                
                value.push(applyOperation(val1,val2,op));
            }
            if( i<final.length()) {
                ops.push(final[i]);
            }
        }
    }
    
    while(!ops.empty()) {
        int val2 = value.top();
        value.pop();
        
        int val1 = value.top();
        value.pop();
        
        char op = ops.top();
        ops.pop();
        
        value.push(applyOperation(val1,val2,op));
    }
    if (value.top() == target) {
        return true;
    }
    return false;    
}

void generate_all_expressions_helper(string s, long long int target, unordered_map<string, int>& res, int pos, string op, string newString) {
    
    if(pos == s.length()-1) { //this is the final hit
        // check for expression
        if(checkExpression(target, newString)) {
            // res.push_back(newString);
            res[newString]=1;
            return;
        }
        return;
    }
    
    newString = generateString(op, s,newString, pos);
    
    generate_all_expressions_helper(s, target, res, pos+1, "", newString);
    generate_all_expressions_helper(s, target, res, pos+1, "*", newString);
    generate_all_expressions_helper(s, target, res, pos+1, "+", newString);
}

vector <string> generate_all_expressions(string s, long long int target) {
    vector<string> res;
    unordered_map<string,int> mymap;
 
    string empty = "";
    generate_all_expressions_helper(s, target, mymap, 0, "",  empty);
    empty = "";
    generate_all_expressions_helper(s, target, mymap, 0, "*", empty);
    empty = "";
    generate_all_expressions_helper(s, target, mymap, 0, "+", empty);
    for(auto it= mymap.begin();it!= mymap.end();it++) {
        res.push_back(it->first);
    }
    return res;
}

