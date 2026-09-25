class Solution {
public:
    vector<string> result;

    string phone[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string current) {
        // If all digits are processed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters for current digit
        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);

            backtrack(digits, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return result;
    }
};