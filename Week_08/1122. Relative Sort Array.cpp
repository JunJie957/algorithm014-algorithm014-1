// ��ϣ������arr2�г��ֵ�Ԫ�أ�map����δ������arr2�е�Ԫ��
// ִ����ʱ��0 ms, ������ C++ �ύ�л����� 100.00% ���û� 
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
