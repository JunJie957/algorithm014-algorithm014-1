class Solution {
public:
	/*
		̰�Ĳ��ԣ����ǽ���С�����㺢��θ�ڵı��ɸ����ӣ������ı�������θ�ڸ���ĺ��ӣ����������ϾͿ����������ĺ��ӡ�

		ʱ�临�Ӷȣ�sort() -> O(nlongn)  ���� -> O(n + m)  ===>   O(nlongn)
		
		�ռ临�Ӷȣ�O(1) ֻ���˳�������ͳ��
	*/
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());	// ����θ�ڴ�С��������
		sort(s.begin(), s.end());	// ���ձ���������С��������
		int count = 0;	
		for (int i = 0, j = 0; i < g.size() && j < s.size(); ++i, ++j) {
			while (j < s.size() && s[j] < g[i]) 
				++j;	 // θ�ڲ����ϣ����������ҵ�����ı���
			
			if (j < s.size()) 
				++count; // �����ǰλ����Ч���򽫱���δ������
		}
		return count;
	}
};
