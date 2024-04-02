class Solution {
public:
    bool check(string s, string t) {
        unordered_map<char,char> m;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++){
            char s1 = s[i];
            char t1 = t[i];
            if(m.count(s1)>0){
                if(m[s[i]]!=t[i])
                    return false;
            }
            else{
                m[s[i]]=t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        if(check(s,t) && check(t,s))
            return true;
        return false;
    }
};

//Leetcode
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself