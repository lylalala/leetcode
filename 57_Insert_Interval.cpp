//this is a good problem. the boundary treatment is difficult and complex
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }
        int left,right;
        Interval temp(newInterval.start,newInterval.end);
        //折半查找到newInterval.start应该插入的位置(intervals的i位置)，如果有前值(i-1)并且前值的end和newInterval.start有重叠，则left记录为i-1，否则为i
        //折半查找到newInterval.end应该插入的位置(intervals的i位置)，如果有后值(i+1)并且后值的start和newInterval.end有重叠，则right记录为i+1，否则为i
        int l=0,r=intervals.size()-1;
        int m;
        while(l<=r){
            m=(l+r)/2;
            if(intervals[m].start<newInterval.start)
                l=m+1;
            else
                r=m-1;
        }
        left=l;
        
        l=0;
        r=intervals.size()-1;
        while(l<=r){
            m=(l+r)/2;
            if(intervals[m].end<newInterval.end)
                l=m+1;
            else
                r=m-1;
        }
        right=l;

        //修改值
        if(left-1>=0&&intervals[left-1].end>=newInterval.start){
            temp.start=intervals[--left].start;
        }
        if(right<=intervals.size()-1&&intervals[right].start<=newInterval.end){
            temp.end=intervals[right++].end;
        }
        
        //给res放入intervals中0--->(left)的值
        //给res放入Interval temp(left->start,right->end)的值
        //给res放入intervals中(right+1)--->intervals.end()-1的值
        if(left-1>=0)
            res.insert(res.end(),intervals.begin(),intervals.begin()+left);
        res.push_back(temp);
        if(right<=intervals.size()-1)
            res.insert(res.end(),intervals.begin()+right,intervals.end());
        return res;
    }
};
