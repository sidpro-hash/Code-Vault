/*
 *
 *
 * @author SidPro
 * @version 1.0
 *
 * Implement the myAtoi(string s) function, which converts a string to 
 * a 32-bit signed integer (similar to C/C++'s atoi function).
 *
*/


class MyAtoi {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool negative = false;
        bool nominus=true,leading=true,noplus=true;
        long long int sum = 0;
        for(int i=0;i<n;++i){
           
           if(s[i]>='0' && s[i]<='9'){
               nominus=false;
               leading=false;
               noplus=false;
               sum = sum*10+(s[i]-'0');
               
               if(negative && sum>=2147483648)return INT_MIN;
               else if(!negative && sum>=2147483647)return 2147483647;
           }
            else if(s[i]==' ' && leading) {
               continue;
           }
           else if(s[i]=='-' && nominus){
               negative=true;
               leading=false;
               nominus=false;
               noplus=false;
           }
            else if(s[i]=='+' && noplus){
               negative=false;
               leading=false;
               nominus=false;
                noplus=false;
            }
            else{
                break;
            }
        }
        int SUM = sum;
        if(negative)
            return SUM*-1;
        
        return SUM;
    }
};