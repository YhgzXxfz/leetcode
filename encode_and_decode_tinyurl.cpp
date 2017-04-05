#include <chrono>
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long_tiny_map.find(longUrl) != long_tiny_map.end()) return long_tiny_map[longUrl];
        
        hash<string> str_hash;
        string tiny_url = prefix + to_string(str_hash(longUrl)) + to_string(std::chrono::high_resolution_clock::now());
        tiny_long_map[tiny_url] = longUrl;
        long_tiny_map[longUrl] = tiny_url;
        return tiny_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tiny_long_map[shortUrl];
    }
    
private:
    unordered_map<string, string> tiny_long_map;
    unordered_map<string, string> long_tiny_map;
    const string prefix = "http://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
