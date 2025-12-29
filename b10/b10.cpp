#include <stdio.h>

void taotep() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "6\n 2.5 -3.4 7.8 1.2 0 -5.6");
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

float lonnhat(float a[], int n) {
    float max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main() {
    float a[100];
    int n;

    taotep();
    doctep(a, n);

    printf("Gia tri lon nhat = %.2f", lonnhat(a, n));
    return 0;
}

