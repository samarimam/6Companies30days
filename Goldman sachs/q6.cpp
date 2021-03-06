class Solution {
public:
    int gcd(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return 0;
    
    if(a == b)
        return a;
    
    if(a > b)
        return gcd(a-b, b);
    
    return gcd(a, b-a);
}

string gcdOfStrings(string str1, string str2) {
    
    int len1 = str1.size();
    int len2 = str2.size();
    
    
    if(str1 + str2 == str2 + str1){
        int a = gcd(len1, len2);
        return str1.substr(0, a);
    }
    
    return "";
}};