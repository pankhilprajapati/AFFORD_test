  
#include <bits/stdc++.h> 
using namespace std; 
// return true or false to check the valid paranthesis
bool check_string(string str){
    stack<char> stack;
    int n = str.size();
    for(auto i:str){
        if(i=='{' || i == '(' || i == '['){
            stack.push(i);
            continue;
        }
        if(stack.empty()){
            return false;
        }
        char x = stack.top();
        if((x == '(' && i == ')')||(x == '{' && i == '}') || (x == '['&& i=='[')){
            stack.pop();
        }
        else{
            return false;
        }
    }
    if(stack.empty()){
        return true;
    }
    return false;
}

int main(){
    string str;
    // input the string to check
    cin>>str;

    if(check_string(str)){
        cout<<"True";
    }else{
        cout<<"False";
    }
}