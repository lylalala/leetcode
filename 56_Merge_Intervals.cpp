//it can also use point to exchange
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0)
            return res;
        //sort
        qsortInterval(intervals,0,intervals.size()-1);
        
        //traverse
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(res[res.size()-1].end>=intervals[i].start)
                res[res.size()-1].end=max(res[res.size()-1].end,intervals[i].end);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
    void qsortInterval(vector<Interval>& list,int left,int right){
        if(left>=right)
            return;
        int leftPos=left;
        int rightPos=right;
        Interval judge=list[left];
        while(leftPos<rightPos){
            while(leftPos<rightPos&&list[rightPos].start>=judge.start)
                rightPos--;
            list[leftPos]=list[rightPos];
            while(leftPos<rightPos&&list[leftPos].start<judge.start)
                leftPos++;
            list[rightPos]=list[leftPos];
        }
        list[leftPos]=judge;
        qsortInterval(list,left,leftPos-1);
        qsortInterval(list,leftPos+1,right);
    }
};
