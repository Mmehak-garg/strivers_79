class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // M1 find the sum of the triplets -> O(N^3);
        // M2 -> with set Tc = O(N^2*(log(no. of unique triplets)))  due to use of set & Sc = O(N^2)
      set<vector<int>> s;
        int n = nums.size();
        for(int i =0;i<n;i++){
            set<int> hash;
            for(int j = i+1;j<n;j++){
                int sum = nums[i]+nums[j];
                int rem = -sum;
                if(hash.find(rem) != hash.end()){
                   vector<int> temp = {nums[i],nums[j],rem};
                   sort(temp.begin(),temp.end());
                   s.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }
         vector<vector<int>> ans(s.begin(),s.end());
         return ans ;
    }
};
//M3 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // M1 find the sum of the triplets -> O(N^3);
        // M2 -> with set Tc = O(N^2*(log(no. of unique triplets)))  due to use of set & Sc = O(N^2)
        // M2 -> using three pointer -> O(NlogN)+O(N2) 
        sort(nums.begin(),nums.end()); // for having distinct triplets
        int n = nums.size();
        int i = 0;
        vector<vector<int>> ans;
        for(int i =0;i<n-1;i++){

            if(i!= 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;

            while(j<k){
                
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum>0) k--;
                else j++;    
            }   
                     
        }
        return ans ;

    }
};