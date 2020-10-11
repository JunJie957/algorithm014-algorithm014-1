学习笔记

各类排序算法的C++实现

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

/*
    选择排序：选择一个元素，依次和无序区域的数进行比较，直到找到本轮的最大/最小值，然后进行交换

    时间复杂度：O(n²)
    空间复杂度：O(1)
    稳定性：稳定，不会改变相同元素的相对位置
*/
void SelectSort(vector<int>& data) {
    int size = data.size();
    for (int i = 0; i < size - 1; ++i) {
        int min = i;  // 选出一个最小值的下标，依次和无序区域的所有数进行比较
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(data[min], data[i]); // 如果当前最小值下标变化，则进行值的交换
        }
    }
}

/*
    直接插入排序：选择一个元素，依次和有序区间的所有值进行比较，直到找到合适的位置，将此元素插入
                  插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率。
                  但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位。
    
    时间复杂度：O(n²)
    空间复杂度：O(1)
    稳定性：稳定，不会改变相同元素的相对位置
*/
void InsertSort(vector<int>& data) {
    int size = data.size();
    for (int i = 1; i < size; ++i) {
        int val = data[i];
        int pos = i - 1;
        while (pos >= 0 && val < data[pos]) {   // 搜索有序区间，找到待插入的位置
            data[pos + 1] = data[pos]; // 元素往后移动，腾出待插入的位置
            --pos;
        }
        data[pos + 1] = val; // 将元素放入到有序区间的合适位置
    }
}

/*
    冒泡排序：初始状态下整个原始序列为无序区,每遍历一遍就浮现出无序区最大的元素放在有序区;
              随着遍历,最终无序区长度变为0,整个原始序列变为有序序列.

    时间复杂度：O(n²)
    空间复杂度：O(1)
    稳定性：稳定，不会改变相同元素的相对位置
*/
void BubbleSort(vector<int>& data) {
    int size = data.size();
    for (int i = 0; i < size; ++i) {
        bool flag = false;
        // 每一次遍历将无序区域最大的值放在有序区域的首部位置
        for (int j = 0; j < size - i - 1; ++j) {    
            if (data[j + 1] < data[j]) {
                flag = true;
                swap(data[j + 1], data[j]); 
            }
        }
        if (!flag) return; // 说明无序区的元素已经有序，不需要继续遍历
    }
}

/*
    希尔排序(缩小增量排序)：直接插入排序的高效版本
                            希尔排序做的改进是将原始待排序序列以一个偏移量h进行逻辑上的分组,对组内的元素采用插入排序,使得原始序列基本有序;
                            偏移量逐渐减小,每减小一次进行组内插入排序,最后一轮则以1为偏移量,也就是将原待排序列分为同一组进行组内排序,也就是简单的插入排序;
                            该排序算法对于无序序列很不理想的情况有利.

    时间复杂度：O(n^(3/2))，下界是O(n*logn)
    空间复杂度：O(1)
    稳定性：不稳定，会改变相同元素的相对位置
*/
void ShellSort(vector<int>& data) {
    int size = data.size();
    for (int h = size / 2; h > 0; h /= 2) {
        for (int i = h; i < size; ++i) {
            int val = data[i];
            int pos = i - h;
            while (pos >= 0 && data[pos] > val) {
                data[pos + h] = data[pos]; // 将元素向后移动，为待插入的元素腾出位置
                pos -= h;
            }
            data[pos + h] = val;
        }
    }
}


/*
    归并排序：分而治之的思想，将序列不断的分为更小的子序列，直到序列个数为1，然后合并，最终整个序列变得有序

    时间复杂度：O(n*log(n))
    空间复杂度：O(n)
    稳定性：稳定，不会改变相同元素的相对位置
*/
void Merge(vector<int>& data, int left, int mid, int right);    // 两个子序列的归并操作
void MergeSort(vector<int>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(data, left, mid);      // 分：将大的序列不断的分解为小的序列
        MergeSort(data, mid + 1, right);
        Merge(data, left, mid, right);  //  归并：将两个有序序列合并为一个序列
    }
}

void Merge(vector<int>& data, int left, int mid, int right) {

    // 1、保存临时合并的结果，最后赋值给data数组
    vector<int> tmp(right - left + 1, 0);

    // 2、合并两个序列
    int i = left, j = mid + 1, pos = 0;
    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            tmp[pos++] = data[i++];
        } else {
            tmp[pos++] = data[j++];
        }
    }
    while (i <= mid)   tmp[pos++] = data[i++];
    while (j <= right) tmp[pos++] = data[j++];

    // 3、将合并的数组赋值给原数组，原数组起始位置为left
    for (int i = 0; i < pos; ++i) {
        data[left++] = tmp[i];
    }
}

/*
    快速排序：每次在无序序列中选择一个中轴数，将无序区间分为大于中轴数和小于中轴数的两部分，
              在两个子区间内各自进行相同的划分操作，直至整个序列有序
              快速排序在划分子区间时，进行排序操作；而归并排序在合并子区间时，进行排序操作
    
    时间复杂度：O(n*log(n))
    空间复杂度：O(n)
    稳定性：稳定，不会改变相同元素的相对位置
*/
void QuickSort(vector<int>& data, int l, int r) {
    if (l < r) {
        int i = l, j = r;
        swap(data[l],data[r]); // 选右边的数作为中轴数，将右边的数交换到最左端即可。
        int x = data[l]; // 选最左边的数作为中轴数，如果选择其他的数，则直接将其与最左边的数进行交换即可
        while (i < j) {
            while (i < j && data[j] >= x) {
                --j; // 从右向左找第一个小于x的数
            }
            if (i < j) data[i++] = data[j];
               
            while (i < j && data[i] < x) {
                ++i; // 从左向右找第一个大于等于x的数
            }
            if (i < j) data[j--] = data[i];
        }
        data[i] = x;
        QuickSort(data, l, i - 1);  // 递归调用, 此时 i 就是中轴数的下标
        QuickSort(data, i + 1, r);
    }
}

int main()
{
    vector<int> data{ 9,3,1,0,4,6,2,7,8 };
    // SelectSort(data);    // 选择排序
    // InsertSort(data);    // 插入排序
    // BubbleSort(data);    // 冒泡排序
    // ShellSort(data);     // 希尔排序
    // MergeSort(data, 0, data.size() - 1); // 归并排序
    QuickSort(data, 0, data.size() - 1); // 快速排序
    for (auto iter : data) {
        cout << iter << " ";
    }
	return 0;
}