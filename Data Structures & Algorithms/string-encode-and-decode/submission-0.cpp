class Solution {
public:
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        vector<int> sizes;
        string res;

        // Store lengths
        for (string& s : strs) {
            sizes.push_back(s.size());
        }

        // Store lengths followed by comma
        for (int sz : sizes) {
            res.append(to_string(sz));
            res.push_back(',');
        }

        // Separator between metadata and actual strings
        res.push_back('#');

        // Store all strings
        for (string& s : strs) {
            res.append(s);
        }

        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<int> sizes;
        vector<string> res;

        int i = 0;

        // Read all lengths until '#'
        while (s[i] != '#') {
            int j = i;

            while (s[j] != ',') {
                j++;
            }

            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }

        // Skip '#'
        i++;

        // Extract strings using stored lengths
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};
