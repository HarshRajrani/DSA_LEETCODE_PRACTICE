class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        
        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));// converting and inserting the binary value to number  
        }
        
        int n = nums.size();
        
        string result= "";
        
        for(int number = 0; number <= 65536; number++) {
            if(st.find(number) == st.end()) { // check all the number of st 
                result = bitset<16>(number).to_string(); // converting the number into binary
                break;
            }
        }
        
        return result.substr(16-n);
        
    }
};