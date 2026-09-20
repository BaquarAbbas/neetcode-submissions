class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(auto ch: s){
            if(isalnum(ch))
             res.push_back(tolower(ch));
        }

        int start = 0; int end = res.size() - 1;
        while(start < end){
            if(res[start] != res[end])
             return false;
            
            start++;
            end--;
        }
        return true;

    }
};
