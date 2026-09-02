class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; 
        int read = 0;  
        while (read < chars.size()) {
            char current_char = chars[read];
            int count = 0;
            while (read < chars.size() && chars[read] == current_char) {
                read++;
                count++;
            }
            chars[write++] = current_char;
            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
