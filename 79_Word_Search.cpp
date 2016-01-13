int d1[4]={0,1,0,-1};
int d2[4]={-1,0,1,0};
class Solution {
private:
    string myString;
public:
    bool exist(vector<vector<char>>& board, string word) {
        myString =word;
        vector<vector<bool>> ok(board.size(),vector<bool>(board[0].size(),true));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    ok[i][j]=false;
                    if(solve(i,j,word.size(),1,1,ok,board))
                        return true;
                    ok[i][j]=true;
                }
            }
        return false;
    }
    bool itCanDoIt(int x,int y,vector<vector<bool>> &ok){
        if(x<0||x>=ok.size()||y<0||y>=ok[0].size()||(!ok[x][y]))
            return false;
        return true;
    }
    bool solve(int x,int y,int wordLength,int depth,int direct,vector<vector<bool>> &ok,vector<vector<char>> &board){
        if(wordLength==depth){
            return true;
        }else{
            if(depth==1){
                for(int i=0;i<4;i++){
                    int a=x+d1[i];
                    int b=y+d2[i];
                    if(itCanDoIt(a,b,ok)&&myString[depth]==board[a][b]){
                        ok[a][b]=false;
                        if(solve(a,b,wordLength,depth+1,i,ok,board))
                            return true;
                        ok[a][b]=true;
                    }
                }
            }else{
                for(int i=(direct+3)%4,j=0;j<3;i=(i+1)%4,j++){
                    int a=x+d1[i];
                    int b=y+d2[i];
                    if(itCanDoIt(a,b,ok)&&myString[depth]==board[a][b]){
                        ok[a][b]=false;
                        if(solve(a,b,wordLength,depth+1,i,ok,board))
                            return true;
                        ok[a][b]=true;
                    }
                }
            }
        }
        return false;
    }
};
