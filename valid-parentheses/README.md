# ***Valid Parentheses***

## [**Link**](https://www.codewars.com/kata/6411b91a5e71b915d237332d)

---

## **Description**

Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return `true` if the string is valid, and `false` if it's invalid.

### **Examples**

``` text
"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true
```

### **Constraints**

`0 <= length of input <= 100`

- All inputs will be strings, consisting only of characters `(` and `)`.
- Empty strings are considered balanced (and therefore valid), and will be tested.
- For languages with mutable strings, the inputs should not be mutated.

**Protip:** *If you are trying to figure out why a string of parentheses is invalid, paste the parentheses into the code editor, and let the code highlighting show you!*

---

## **Solution**

**C** :

``` c
#include <stdbool.h>

#define BR_LEFT '('
#define BR_RIGHT ')'

bool valid_parentheses(const char* str) {
    int opened = 0;
    char c = *str;

    while(c) {
        if(c == BR_LEFT) {
            opened++;
        } else if (c == BR_RIGHT) {
            opened--;
            if(opened < 0) {
                return false;
            }
        }
        c = *(++str);
    }

    return opened == 0;
}
```
