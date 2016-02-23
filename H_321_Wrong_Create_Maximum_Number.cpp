class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,pair<int,int>>> n;
        vector<pair<int,int>> pos;
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            n.push_back(pair<int,pair<int,int>>(nums1[i],pair<int,int>(1,i+1)));
        }
        for(int i=0;i<nums2.size();i++){
            n.push_back(pair<int,pair<int,int>>(nums2[i],pair<int,int>(2,i+1)));
        }
        //sort(n.begin(),n.end(),myComp);
        mysort(n,0,int(n.size()));
        for (int i=0; i<n.size(); i++) {
            pos.push_back(n[i].second);
        }
        vector<bool> ok(n.size(),true);
        int theK=int(n.size())-k;
        int kk=k;
        while(theK>0&&kk>0){
            int it;
            for(it=0;it<n.size();it++){
                if ((it+1<n.size())&&(n[it].first==n[it+1].first)&&(n[it].second.second==n[it+1].second.second)&&(n[it].second.second!=1)) {
                    int temp1,temp2;
                    if (n[it].second.first==1) {
                        temp1=nums1[pos[it].second-2];
                        temp2=nums2[pos[it+1].second-2];
                    }else{
                        temp1=nums2[pos[it].second-1];
                        temp2=nums1[pos[it+1].second-1];
                    }
                    if (temp1>temp2) {
                        it++;
                    }
                }
                if(ok[it]&&(n[it].second.second-1)<=theK){
                    res.push_back(n[it].first);
                    theK-=(n[it].second.second-1);
                    kk--;
                    break;
                }
            }
            int temp=n[it].second.second;
            n[it].second.second=0;
            for(int i=0;i<n.size();i++){
                if((ok[i])&&n[i].second.first==n[it].second.first){
                    n[i].second.second-=temp;
                    if (n[i].second.second<=0) {
                        ok[i]=false;
                    }
                }
            }
        }
        if(kk==0)
            return res;
        vector<int> n1(nums1);
        int len1=int(n1.size());
        vector<int> n2(nums2);
        int len2=int(n2.size());
        for(int i=0;i<ok.size();i++){
            if(!ok[i]){
                if(pos[i].first==1){
                    n1[pos[i].second-1]=-1;
                    len1--;
                }
                else{
                    n2[pos[i].second-1]=-1;
                    len2--;
                }
            }
        }
        int i=0,j=0;
        while(!(len1==0&&len2==0)){
            while((!n1.empty())&&n1[i]<0&&len1>0)
                i++;
            while((!n2.empty())&&n2[j]<0&&len2>0)
                j++;
            if(len2==0||(len1>0&&n1[i]>=n2[j])){
                if(len1>0&&len2>0&&n1[i]==n2[j]){
                    int tempi=i,tempj=j;
                    while (tempi<n1.size()&&tempj<n2.size()&&n1[tempi]==n2[tempj]) {
                        tempi++;
                        tempj++;
                    }
                    if (tempi==n1.size()||(tempj<n2.size()&&n2[tempj]>n1[tempi])) {
                        res.push_back(n2[j]);
                        len2--;
                        j++;
                    }else{
                        res.push_back(n1[i]);
                        len1--;
                        i++;
                    }
                }
                else{
                    res.push_back(n1[i]);
                    len1--;
                    i++;
                }
            }
            else{
                res.push_back(n2[j]);
                len2--;
                j++;
            }
        }
        return res;
    }
    void mysort(vector<pair<int,pair<int,int>>> &n,int start,int end){
        int len=end-start;
        if (len>1) {
            int i=len>1,j=len-i;
            mysort(n, start, start+i);
            mysort(n, start+i, end);
            int posi=start,posj=start+i;
            vector<pair<int,pair<int,int>>> temp;
            while (!(i==0&&j==0)) {
                if (j==0||(i>0&&n[posi].first>=n[posj].first)) {
                    if (j!=0&&n[posi].first==n[posj].first&&n[posi].second.second>n[posj].second.second) {
                        temp.push_back(n[posj++]);
                        j--;
                    }else{
                        temp.push_back(n[posi++]);
                        i--;
                    }
                }else{
                    temp.push_back(n[posj++]);
                    j--;
                }
            }
            for (int it=0; it<temp.size(); it++) {
                n[start+it]=temp[it];
            }
        }
    }
};

