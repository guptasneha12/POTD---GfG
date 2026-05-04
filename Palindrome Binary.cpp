class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        // integer to binary
        string binary=bitset<32>(n).to_string();
        // remove leading zeros
        binary=binary.substr(binary.find('1'));
        string revbinary=binary;
        reverse(revbinary.begin(),revbinary.end());
        return binary==revbinary;
    }
};