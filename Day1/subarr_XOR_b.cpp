class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long c =0;
        long long x =0;
        map<int,int> mp;
        mp[0] =1;
        long long b =0;
        for(int i =0;i<n;i++){
            x^=nums[i];
            int rem = b^x;
            c+=mp[rem];
            mp[x]++;
        }
        return c;
    }
};