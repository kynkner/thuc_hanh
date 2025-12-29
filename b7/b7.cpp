#include <stdio.h>

void taotep() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "6\n1.5 2.0 1.5 3.2 1.5 4.0\n1.5");
    fclose(f);
}

void doctep(float a[], int *n, float *x) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        *n = 0;
        *x = 0;
        return;
    }

    fscanf(f, "%d", n);
    printf("Du lieu doc tu tep:\n");
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%f", &a[i]);
        printf("%.2f ", a[i]);
    }
    printf("\n");

    fscanf(f, "%f", x);
    printf("So can dem x = %.2f\n", *x);

    fclose(f);
}

int demso(float a[], int n, float x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            dem++;
        }
    }
    return dem;
}

int main() {
    float a[100];
    int n;
    float x;
    int kq;

    taotep();                 
    doctep(a, &n, &x);        

    kq = demso(a, n, x);

    printf("So lan xuat hien cua %.2f la: %d\n", x, kq);

    return 0;
}

