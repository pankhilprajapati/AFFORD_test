  
#include <bits/stdc++.h> 
using namespace std; 


// for traversing 
bool findin(vector<vector<char>>& board,int i, int j,string word,int index){
    
    if(i<0||j<0||i>=board.size() || j>=board[0].size() ||word[index] != board[i][j]) return false;
    if(index == word.size()-1) return true;
    char tem = board[i][j];
    board[i][j] = '*';
    bool  val = findin(board,i+1,j,word,index+1)||findin(board,i-1,j,word,index+1)||findin(board,i,j+1,word,index+1)||findin(board,i,j-1,word,index+1);
    board[i][j] = tem;
    return val;

}

// main function that return the true or false;
bool havein(vector<vector<char>>& board, string word){
    if(word.size() == 0) return true;
    if(board.empty()|| board[0].empty()) return false;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(findin(board,i,j,word,0)){
                return true;
            }
        }
    }
    return false;
}

int main(){

    // Add any type of board using the input
    vector<vector<char>> board= {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // taking the string input to find the string in the board
    string word;
    cin>>word;

    if(havein(board,word)){
    cout<<"True";
}
    else{
        cout<<"False";
    }
    
}