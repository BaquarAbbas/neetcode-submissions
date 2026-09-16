class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
         return false;

        int countChars[26] = {0};
        for(auto ch: s){
            countChars[ch - 'a']++;
        }

        for(auto ch: t){
            countChars[ch - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(countChars[i] != 0)
             return false;
        }

        return true;
    }
};
