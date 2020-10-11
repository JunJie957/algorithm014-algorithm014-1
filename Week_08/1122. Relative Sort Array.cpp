// 哈希表处理在arr2中出现的元素，map处理未出现在arr2中的元素
// 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户 
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> um;
        for (auto& iter : arr1) ++um[iter];
           
        int pos = -1;
        for (auto& iter : arr2) {
            while (--um[iter] >= 0) arr1[++pos] = iter;
            um.erase(iter);
        }

        map<int, int> m{ um.begin(),um.end() };
        for (auto& iter : m) {
            while (--iter.second >= 0) arr1[++pos] = iter.first;
        }
        return arr1;
    }
};
