class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        // Step 1: Count frequency
        for (auto &word : words) {
            mp[word]++;
        }

        // Step 2: Custom comparator
        auto cmp = [&](pair<int, string>& a, pair<int, string>& b) {

            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        };

        // Step 3: Min heap
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(cmp)
        > pq(cmp);

        // Step 4: Maintain heap size k
        for (auto &it : mp) {

            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 5: Extract answer
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};