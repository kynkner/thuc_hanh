#include <stdio.h>
#include <stdlib.h>

void taotep() {
    FILE *f = fopen("b1.txt", "w");
    fprintf(f, "25");
    fclose(f);
}

void doctep(long *n) {
    FILE *f = fopen("b1.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        *n = 0;
        return;
    }
    fscanf(f, "%ld", n);
    fclose(f);
}

char *doinhiphan(long n) {
    char temp[64]; 
    int i = 0;
    if (n == 0) {
        char *bin = (char *)malloc(2 * sizeof(char));
        bin[0] = '0';
        bin[1] = '\0';
        return bin;
    }
    while (n > 0) {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    }
    char *bin = (char *)malloc((i + 1) * sizeof(char));
    int j;
    for (j = 0; j < i; j++) {
        bin[j] = temp[i - j - 1];
    }
    bin[i] = '\0';
    return bin;
}

int main() {
    long n;
    taotep();
    doctep(&n);

    char *bin = doinhiphan(n);
    printf("So nhi phan: %s\n", bin);

    free(bin);
    return 0;
}

