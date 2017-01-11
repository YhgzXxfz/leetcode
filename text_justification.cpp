class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for(int i = 0, k, l; i < words.size(); i += k) {
            for(k = l = 0; i + k < words.size() && l + words[i+k].size() <= maxWidth - k; k++) {
                l += words[i+k].size();
            }
            
            string curr = words[i];
            for(int j = 0; j < k - 1; j++) {
                if(i + k >= words.size()) curr += " ";
                else curr += string((maxWidth-l)/(k-1) + (j < (maxWidth-l) % (k-1)), ' ');
                curr += words[i+j+1];
            }
            curr += string(maxWidth - curr.size(), ' ');
            result.push_back(curr);
        }
        return result;
    }
};
