class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        //find the row
        int i=0;
        int j=matrix.size()-1;
        int mid;
        while(i<=j){
            mid=(i+j)/2;
            if(target>=matrix[mid][0])
                i=mid+1;
            else
                j=mid-1;
        }
        int row=i-1;
        if(row<0)
            return false;
        i=0;
        j=matrix[0].size()-1;
        while(i<=j){
            mid=(i+j)/2;
            if(target==matrix[row][mid]) return true;
            if(target>matrix[row][mid])
                i=mid+1;
            else
                j=mid-1;
        }
        return false;
    }
};
