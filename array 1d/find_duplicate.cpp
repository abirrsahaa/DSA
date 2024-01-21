// my logic works but te way lakshay bhaiya used its beyond my reach thats simply genius !!

// my logic :
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // if we can play with the index that the best procedure
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int element = nums[i] - 1;
            arr[element]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 2)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// lakshay bhaiya logiclass Solution {
public:
int findDuplicate(vector<int> &nums)
{
    while (nums[0] != nums[nums[0]])
    {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}
}
;
c:
