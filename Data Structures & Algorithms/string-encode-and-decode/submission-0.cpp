class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (string s : strs) {
            res += to_string(s.size()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find delimiter #
            while (s[j] != '#') {
                j++;
            }

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract string
            string word = s.substr(j + 1, len);
            res.push_back(word);

            // Move to next encoded part
            i = j + 1 + len;
        }

        return res;
    }
};