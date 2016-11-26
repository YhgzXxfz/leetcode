class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string cipher;
        for (auto& str : strs) {
            cipher += to_string(str.size()) + "@" + str;
        }
        return cipher;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int pos = 0;
        while (pos < s.size()) {
            int at = s.find_first_of('@', pos);
            int len = stoi(s.substr(pos, at-pos));
            pos = at+1;
            result.emplace_back(s.substr(at+1, len));
            pos += len;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
