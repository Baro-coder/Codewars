#include <stdio.h>
#include <stdbool.h>

#define BR_LEFT '('
#define BR_RIGHT ')'

/* *** Func *** */
bool valid_parentheses(const char* str) {
    int opened = 0;
    char c = *str;

    while(c) {
        // printf("\tc: %c\n", c);
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
/* *** Func *** */

/* *** TESTS *** */
// -- True tests
void testTrue(void) {
    const int strsCount = 5;
    const char* strs[] = {
        "()",
        "((()))",
        "()()()",
        "(()())()",
        "()(())((()))(())()",
    };

    bool result = false;

    printf("True Tests:\n");
    for(int i = 0; i < strsCount; i++) {
        result = valid_parentheses(strs[i]);
        printf("  [%d]: %d : \'%s\'\n", i, result, strs[i]);
    }
}

// -- False tests
void testFalse(void) {
    const int strsCount = 5;
    const char* strs[] = {
        ")(",
        "()()(",
        "((())",
        "())(()",
        ")()",
        ")",
    };

    bool result = false;

    printf("False Tests:\n");
    for(int i = 0; i < strsCount; i++) {
        result = valid_parentheses(strs[i]);
        printf("  [%d]: %d : \'%s\'\n", i, result, strs[i]);
    }
}

/* *** Main Driver *** */
int main(void) {
    
    testTrue();
    testFalse();

    return 0;
}