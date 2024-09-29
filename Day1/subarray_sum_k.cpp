class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute approach 

           int c =0;
           int n = nums.size();
           for(int i =0;i<n;i++){
            int sum =0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                if(sum == k) c++;
            }
           }
           return c;
           

           // using mp
           map<int,int> m;
           m[0] =1;
           int prefixsum = 0;
           int n = nums.size();
           int c =0;
           for(int i =0;i<n;i++){
                prefixsum +=nums[i];
                int rem = prefixsum-k;
                if(m.find(rem) != m.end()) c+=m[rem];
                m[prefixsum]++;
           }
           return c;

    }
};