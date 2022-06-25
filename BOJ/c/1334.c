#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a; *a = *b; *b = temp;
}

int check(char *number, int len) {
    int i;
    for (i = 0; i < len / 2; i++) 
        if (number[i] != number[len - 1 - i]) return 0;
    return 1;
}

void plusOne(char *number, int len) {
    int i; 
    
    if (number[0] == 9) {
        number[0] = 0;
        number[1]++;
    }
    else number[0]++;
    
    for (i = 1; i < len - 1; i++) {
        if (number[i] == 10) {
            number[i] = 0;
            number[i + 1]++;
        }
    }
    
    if (number[len - 1] == 10) {
        number[len - 1] = 0;
        number[len] = 1;
    }
}

void reverse(char *ch, int len) {
	int i; for (i = 0; i < len / 2; i++) swap(ch + i, ch + len - 1 - i);
}

void intify(char *ch, int len) {
	int i; for (i = 0; i < len; i++) {
		ch[i] -= '0';
	}
}

int main() {
    char number[52];
    scanf("%s", &number);
    int len = strlen(number), i;
    intify(number, len);
    reverse(number, len);
    
    while (1) {
        plusOne(number, len);
        len = strlen(number);
        if (check(number, len)) {
            for (i = 0; i < len; i++) printf("%d", number[i]);
            return 0;
        }
                    for (i = 0; i < len; i++) printf("%d", number[i]);
                    printf("\n");
    }
}
