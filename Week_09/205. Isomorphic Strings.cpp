/*
	����1����ϣ����¼�ַ��Ķ�Ӧλ�ã�Ȼ��ȷ�Ϲ�ϣ���ȼ�ÿ��λ���ϵ��ַ��Ƿ���ͬ 
*/ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>> um1, um2;
        for (int i = 0; i < s.length(); ++i) {
            um1[s[i]].emplace_back(i);
            um2[t[i]].emplace_back(i);
        }

        if (um1.size() != um2.size()) return false;

        for (auto& i : um1) {
            for (int j = 0; j < i.second.size(); ++j) {
                if (t[i.second[0]] != t[i.second[j]]) 
                    return false;
            }
        }
        return true;
    }
};

/*
	����2���ַ������ң����������ַ��������ҵ�ǰ�ַ��ĳ���λ�ã��ܻ᷵�ص�һ�γ��ֵ�λ��
	
		   ���λ�ö���ͬ�Ļ���˵������ͬ���� 
*/ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.length(); ++i) {
            if (s.find(s[i]) != t.find(t[i])) 
                return false;
        }
        return true;
    }
};
