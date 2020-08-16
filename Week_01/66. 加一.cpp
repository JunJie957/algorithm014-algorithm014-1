
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; --i) {
            ++digits[i];
            if (digits[i] >= 10) {
                digits[i] %= 10;
            }
            else {
                break;
            }
        }

        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

