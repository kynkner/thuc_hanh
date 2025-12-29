#include <stdio.h>

void taotep() {
    FILE *f = fopen("b6.txt", "w");
    fprintf(f, "5");   
    fclose(f);
}

void doctep(int *n) {
    FILE *f = fopen("b6.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        *n = 0;
        return;
    }
    fscanf(f, "%d", n);
    fclose(f);
}

long giaithua(int n) {
    long gt = 1;
    for (int i = 1; i <= n; i++) {
        gt *= i;
    }
    return gt;
}

int main() {
    int n;
    long kq;

    taotep();           
    doctep(&n);       

    printf("Gia tri n doc tu tep: %d\n", n);

    kq = giaithua(n);

    printf("Gia thua cua %d la: %ld\n", n, kq);

    return 0;
}

