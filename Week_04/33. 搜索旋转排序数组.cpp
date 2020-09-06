/*
    ���ö��ֲ�������ת�������ҵ�Ŀ��ֵ

    ��Ҫ��������ȷ����ǰλ���ǲ��Ǵ��ڱ���ת�Ĳ��֣�����������Ԫ�غ͵�ǰλ��Ԫ�ؽ��бȽϾͿ��Եõ����

    (1) ���������Ԫ�رȵ�ǰλ��Ԫ��С����ǰλ��δ���ڱ���ת��λ��
    (2) ���������Ԫ�رȵ�ǰλ��Ԫ�ش���ǰλ�ô��ڱ���ת�Ĳ�����
    (3) ���δ���ڱ���ת���֣�����Ҫ�ж�target�Ƿ����󲿷����䣬�� nums[0] <= target && target < nums[mid]
    (4) ������ڱ���ת���֣�����Ҫ�ж�target�Ƿ����Ҳ������䣬  �� nums[mid] < target && target <= nums[right]
    (5) �����жϽ����ȷ����һ���������ƻ������Ʋ�����ֱ���ҵ�Ŀ��ֵ�����left > right����˵��δ�ҵ�
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;	/* found it */ 

            if (nums[0] <= nums[mid]) { 
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {  
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
