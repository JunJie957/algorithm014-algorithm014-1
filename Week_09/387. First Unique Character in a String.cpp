/*
	��ϣ���¼���ʳ��ִ�����λ�ã�����ڹ�ϣ����ɾѡ��ֻ����һ����λ����С��ֵ 
*/ 
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> um;
        for (int i = 0; i < s.length(); ++i) {
            ++um[s[i]].first;
            um[s[i]].second = i;
        }

        int min_loc = s.length();
        for (auto& iter : um) {
            if (iter.second.first == 1) {
                min_loc = min(iter.second.second, min_loc);
            }
        }
        return min_loc == s.length() ? -1 : min_loc;
    }
};
