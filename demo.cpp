class Solution {
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define endl "\n"
#define show(arr) for (auto i: arr) {cout << i << ' ';} cout << "\n"
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define debug(x) cout << #x << " = " << (x) << endl;

int initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int count = 0;
        int product = 1;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left++];
            }

            count += right - left + 1;
        }

        return count;
    }
};