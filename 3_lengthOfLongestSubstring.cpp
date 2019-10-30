#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<2)
            return s.size();
        int res(0),max(0),head(0),tail(0);
        map<char,int> index;
        while(tail<s.size()){
            map<char,int>::iterator it = index.find(s[tail]);
            if(it==index.end()||it->second<=head){
                res++;
                if(res>max)
                    max=res;
            }
            else{
                head = it->second;
                res=tail-head+1;
            }
            index[s[tail]]=tail+1;
            tail++;
        } 
        return max;
    }      
};
