class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(int i=0;i<strs.size();i++){
            encoded_string.append(strs[i]);
            encoded_string.append("1933");
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
    //     auto first_non_digit = std::find_if_not(text.begin(), text.end(), [](unsigned char c) {
    //     return std::isdigit(c);
    // });
    //     size_t digit_count = std::distance(text.begin(), first_non_digit);
    //     if (digit_count > 0) {
        
    //         // 4. Dynamically extract the substring containing only the numbers
    //         std::string number_substring = text.substr(0, digit_count);
            
    //         // 5. Convert the dynamic string into an actual integer data type
    //         int num_value = std::stoi(number_substring);
            
    //         // 6. Delete the exact number of processed digits from the original string
    //         text.erase(0, digit_count);
    //     }

    //     while(num_value!=0){
    //         string res;
    //         for(int i=0;.i<s.size();i++){
    //             if(s[i]=="!"){
    //                 num_value--;
    //                 decoded_string.push_back(res);
    //             }
    //             else{
    //                 res.append(s[i]);
    //             }

    //         }
    //     }
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' && s[i+1]=='9' && s[i+2]=='3' && s[i+3]=='3'){
                decoded_string.push_back(res);
                res.erase();
                i = i + 3;
            }
            else{
                res+=s[i];
            }
        }
        return decoded_string;
    }
};
