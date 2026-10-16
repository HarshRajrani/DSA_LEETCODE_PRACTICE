class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
       typedef  pair<int , int>p ;
        unordered_map<int , int> mp ;

        for(int &num : nums){
            mp[num]++ ;
        }

        priority_queue<p , vector<p> , greater<p>> pq ;

        for(auto &it : mp){
            int value = it.first;
            int freq = it.second ;

            pq.push({freq , value}) ;

            if(pq.size() > k) pq.pop() ;
        }

        vector<int> ans ; 

        while(!pq.empty()){
            ans.push_back(pq.top().second) ;
            pq.pop() ;
        }
        return ans ;
    }
};