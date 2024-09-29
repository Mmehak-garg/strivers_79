Number: 5.7
Floor: 5
Ceil: 6

Number: 5
Floor: 5
Ceil: 5

Number: -5.7
Floor: -6
Ceil: -5
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // m1 -> using map count the freq of each element and check freq > [n/3] tc -> O(N) and SC O(N)(O(N) for the best and average case and for the worst case, it will be O(N2))
        // m2 Extended Boyer Moore’s Voting Algorithm
        int n = nums.size();
        int c1 =0,c2 =0;
        int ele1 = INT_MIN,ele2 = INT_MIN;
        for(int i =0;i<n;i++){
            if(c1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                c1++;
            }
            else if(c2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                c2++;
            }
            else if(nums[i] == ele1) c1++;
            else if(nums[i] == ele2) c2++;
            else c1--,c2--;
        }
        c1 = 0;c2 =0;
        for(int i =0;i<n;i++){
            if(ele1== nums[i]) c1++;
           else if(ele2 == nums[i])c2++;
        }
        vector<int> ans;
        if(c1>(n/3)) ans.push_back(ele1);
        if(c2>(n/3)) ans.push_back(ele2);
        return ans;
    }
};