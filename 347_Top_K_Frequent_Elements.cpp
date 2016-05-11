class Solution {
private:
    void adjust(vector<pair<int,int>>& arr,int father){
        while(father<arr.size()){
            if((father*2+2)<arr.size()){
                int small=(arr[father*2+1].second<arr[father*2+2].second)?father*2+1:father*2+2;
                if(arr[father].second>arr[small].second){
                    swap(arr[father],arr[small]);
                    father=small;
                }else{
                    break;
                }
            }else if((father*2+1)<arr.size()){
                if(arr[father].second>arr[father*2+1].second){
                    swap(arr[father],arr[father*2+1]);
                    father=father*2+1;
                }else{
                    break;
                }
            }else
                break;
            
        }
    }
    void adjust2(vector<pair<int,int>>& arr,int son){
        while(son!=0){
            int temp=(son-1)/2;
            if(arr[temp].second>arr[son].second){
                swap(arr[temp],arr[son]);
                son=temp;
            }else{
                break;
            }
        }
    }
    void make_heap(vector<pair<int,int>>& arr){
        for(int i=(arr.size()-2)/2;i>=0;i--){
            adjust(arr,i);
        }
    }
    void insert(vector<pair<int,int>>& arr,pair<int,int> a){
        swap(arr[0],arr[arr.size()-1]);
        arr.pop_back();
        adjust(arr,0);
        arr.push_back(a);
        adjust2(arr,arr.size()-1);
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> tree;
        for(int i=0;i<nums.size();i++){
            if(tree.find(nums[i])!=tree.end())
                tree[nums[i]]++;
            else
                tree[nums[i]]=1;
        }
        map<int,int>::iterator it=tree.begin();
        vector<pair<int,int>> arr(tree.size(),pair<int,int>(0,0));
        for(int i=0;i<arr.size();i++,it++){
            arr[i].first=it->first;
            arr[i].second=it->second;
        }
        vector<pair<int,int>> res(k+1,pair<int,int>(0,0));
        for(int i=0;i<res.size();i++)
            res[i]=arr[i];
        make_heap(res);
        for(int i=res.size();i<arr.size();i++){
            insert(res,arr[i]);
        }
        swap(res[0],res[res.size()-1]);
        res.pop_back();
        if(!res.empty()) adjust(res,0);
        vector<int> result(k,0);
        for(int i=k-1;i>=0;i--){
            swap(res[0],res[res.size()-1]);
            result[i]=res.back().first;
            res.pop_back();
            if(!res.empty()) adjust(res,0);
        }
        return result;
    }
};
