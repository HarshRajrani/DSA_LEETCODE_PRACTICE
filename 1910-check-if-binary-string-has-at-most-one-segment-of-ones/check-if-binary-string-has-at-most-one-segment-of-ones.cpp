class Solution {
public:
    bool checkOnesSegment(string s) {

        return s.find("01") == string::npos ;
        // they find the particular string is it doesn't exit return true 
    }
};