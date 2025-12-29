#include <stdio.h>

void taotep() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "5\n-2.5 3.4 -1.2 0 4.6");
    fclose(f);
}

void doctep(float a[], int &n) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        return;
    }

    fscanf(f, "%d", &n);
    printf("Du lieu doc tu tep: ");
    for (int i = 0; i < n; i++) {
        fscanf(f, "%f", &a[i]);
        printf("%.2f ", a[i]);
    }
    printf("\n");

    fclose(f);
}

float tongam(float a[], int n) {
    float s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            s += a[i];
    }
    return s;
}

int main() {
    float a[100];
    int n;

    taotep();
    doctep(a, n);

    printf("Tong cac so am = %.2f", tongam(a, n));
    return 0;
}

