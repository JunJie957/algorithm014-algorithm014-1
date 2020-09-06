class Solution {
public:
	/*
		贪心策略：总是将最小能满足孩子胃口的饼干给孩子，将大块的饼干留给胃口更大的孩子，这样策略上就可以满足更多的孩子。

		时间复杂度：sort() -> O(nlongn)  遍历 -> O(n + m)  ===>   O(nlongn)
		
		空间复杂度：O(1) 只用了常量进行统计
	*/
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());	// 按照胃口从小到大排序
		sort(s.begin(), s.end());	// 按照饼干容量从小到大排序
		int count = 0;	
		for (int i = 0, j = 0; i < g.size() && j < s.size(); ++i, ++j) {
			while (j < s.size() && s[j] < g[i]) 
				++j;	 // 胃口不符合，继续遍历找到更大的饼干
			
			if (j < s.size()) 
				++count; // 如果当前位置有效，则将饼干未给孩子
		}
		return count;
	}
};
