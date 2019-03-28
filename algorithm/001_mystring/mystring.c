#include <stdio.h>

#define MAX_STR_LEN 256

int mystrlen(const char *str) {
    int i = 0;
    while( str[i] != '\0') {
        i++;
    }
    return i;
}

int mystrcmp(const char *s1, const char *s2) {
    int s1Len = mystrlen(s1);
    int s2Len = mystrlen(s2);
    if (s1Len > 0 && s1Len == s2Len) {
        int i;
        for (i = 0; i < s1Len; i++) {
                if (s1[i] != s2[i]) {
                    return -1;
                }
        }
    } else {
        return -1;
    
    }
    return 0;
}

char* mystrcpy(char *dest, const char *source) {
    int i = 0;

    while(source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';

    return &dest[0];
}

char* mystrncpy(char *dest, const char *source, int n) {
    int i = 0;
    while (source[i] != '\0' && i < n) {
        dest[i] = source[i];
        i++;
    }

    while (i < n) {
        dest[i] = '\0';
    }
    
    return &dest[0];
}

int main(void) {
    char str[MAX_STR_LEN] = "";
    char dest[MAX_STR_LEN] = "";
    
    printf("### Please input \"bye\" to exit. ###\n");
    while(mystrcmp(str, "bye")) {
        printf("input string : ");
        scanf("%s", str);
        printf("strlen() result : %d\n", mystrlen(str));
        mystrncpy(dest, str, mystrlen(str));
        printf("strncpy() result : %s\n", dest);
        mystrcpy(dest, str);
        printf("strcpy() result : %s\n", dest);
    }

    return 0;
}
