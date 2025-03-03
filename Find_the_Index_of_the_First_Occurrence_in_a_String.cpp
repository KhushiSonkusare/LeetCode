class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t index = haystack.find(needle);
    
    // If find() returns npos, needle was not found, so return -1
    if (index == std::string::npos) {
        return -1;
    }
    
    return static_cast<int>(index); 
    }
};