# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:

    int minSwaps(string s) {
        int ans = 0;
        for(char ch:s){
            if(ch == '[') ans++;
            else if(ans>0) ans--;
        }
        return (ans+1)/2;
    }
    // int minSwaps(string s) {
    //     int balance = 0;
    //     int swaip = 0;
    //     for( char x : s){
        
    //         if(x=='['){
    //             balance++;
    //         }else{
    //              balance--;
    //         }

    //         if(balance < 0){
    //             swaip++;
    //             balance+=2;
    //         }
    //     }
    //   return swaip;

    // }

    // int minSwaps(string s) {
    //     int size = 0;
    //     int n = s.size();
    //     for (int i = 0; i < n; i++) {
    //         char ch = s[i];
    //         if (ch == '[')
    //             size++;
    //         else if (size > 0) 
    //             size--;
    //     }
    //     return (size + 1) / 2;
    // }
};

```