#include <iostream>
#include <vector>

using namespace std;

/*--------------------动态规划O(n^2)--------------------*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),head(0),len(1);
        if(n<2)
            return s;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n-1;++i){
            dp[i][i]=1;
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                if(len<2){
                    head=i;
                    len=2;
                }
            }
            else
                dp[i][i+1]=0;
        }
        dp[n-1][n-1]=1;
        
        for(int j=2;j<n;++j){
            for(int i=0;i+j<n;++i){
                if(s[i]==s[i+j])
                    dp[i][i+j]=dp[i+1][i+j-1];
                else
                    dp[i][i+j]=0;
                if(dp[i][i+j]==1){
                    head=i;
                    len=j+1;
                }
                    
            }
        }
        return s.substr(head,len);
    }
};

/*----------------占位符回文中心遍历O(n^2)---------------*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),res(0),center(0);
        if(n<2)
            return s;
        //解决奇偶回文问题插入占位符#sub#sub#共n+1个
        int len=2*n+1;
        for(int i=0;i<len;++i){
            int temp(1);
            for(int j=1;i-j>=0&&i+j<len;j++){
                //偶数索引均是占位符
                if((i-j)%2==0)
                    temp+=2;
                //映射回原字符串的索引
                else if(s[(i-j-1)/2]==s[(i+j-1)/2])
                    temp+=2;
                else
                    break;
            }
            if(temp>res){
                res=temp;
                center=i;
            }
        }
        //总是有：占位符个数和=目标回文串长度+1，因此res=2*(目标回文串长度)+1
        //换算出返回回文子串长度
        res=(res-1)/2;
        int head;
        //含占位符的头部索引(增广索引)/2 = 原字符串头部索引
        head=(center-res)/2;
        return s.substr(head,res);
    }
};

/*------------Manacher算法(俗称马拉车算法)O(n)-----------*/