class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }
        unordered_map<char,int>need;
        for(char c : t){
            need[c]++;
        }
        unordered_map<char,int>window;
        int have = 0;
        int required = need.size();
        int left  =0;
        int minLength = INT_MAX;
        int minLeft = 0;
        for(int right = 0;right < s.length();right++){
            char c = s[right];
            window[c]++; //add char

            if(need.count(c) && window[c] == need[c]){
                have++;
            }
            while(have == required){
                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    minLeft = left;
                }
                char leftChar = s[left];
                window[leftChar]--;
                if(need.count(leftChar) && window[leftChar] < need[leftChar]){
                    have--;
                }
                left++;
            }
        }
        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(minLeft,minLength);
        
    }
};
