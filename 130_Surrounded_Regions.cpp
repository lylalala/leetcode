int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
class Solution {
private:
    typedef pair<int,int> pp;
public:
    void dothis(int x,int y,vector<vector<char>>& board,vector<vector<bool>>& ok){
        queue<pp> q;
        q.push(pp(x,y));
        q.push(pp(-1,0));
        ok[x][y]=false;
        while(q.front().first!=-1){
            while(q.front().first!=-1){
                pp temp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=temp.first+dx[i];
                    int yy=temp.second+dy[i];
                    if(xx>=0&&xx<board.size()&&yy>=0&&yy<board[0].size()&&board[xx][yy]=='O'&&ok[xx][yy]){
                        q.push(pp(xx,yy));
                        ok[xx][yy]=false;
                    }
                }
            }
            q.pop();
            q.push(pp(-1,0));
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty())
            return;
        vector<vector<bool>> ok(board.size(),vector<bool>(board[0].size(),true));
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'&&ok[0][i])
                dothis(0,i,board,ok);
            if(board[board.size()-1][i]=='O'&&ok[board.size()-1][i]) dothis(board.size()-1,i,board,ok);
        }
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]=='O'&&ok[i][0]) dothis(i,0,board,ok);
            if(board[i][board[0].size()-1]=='O'&&ok[i][board[0].size()-1]) dothis(i,board[0].size()-1,board,ok);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]=(ok[i][j])?'X':'O';
            }
        }
    }
};
