#include <iostream>
#include <vector>
#include <map>

using std::vector,std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
        vector<int>::iterator it;
        int i = 0;
        for(it = nums.begin();it!=nums.end();++it){
            
            if(hash.count(*it)!=0)
            {
                res.push_back(hash[*it]);
                res.push_back(i);
                return res;
            }
            int temp = target - *it;
            hash[temp]=i;
            i++;   
        }
        return res;
    }
};

//哈希表