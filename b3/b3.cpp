#include <stdio.h>

void taotep() {
    FILE *f = fopen("b3.txt", "w");
    fprintf(f, "6\n5.5 2.1 9.3 1.0 4.8 3.6");
    fclose(f);
}

void doctep(float a[], int *n) {
    FILE *f = fopen("b3.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        *n = 0;
        return;
    }

    fscanf(f, "%d", n);
    printf("Day so chua sap xep: ");
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%f", &a[i]);
        printf("%.2f ", a[i]);
    }
     printf("\n");
    fclose(f);
}

void selectsort(float a[], int n) {
    int i, j, min;
    float temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void ghitep(float a[], int n) {
    FILE *f = fopen("result.txt", "w");
    if (f == NULL) {
        printf("Khong ghi duoc tep!\n");
        return;
    }

    fprintf(f, "Day sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%.2f ", a[i]);
    }
    fclose(f);
}

int main() {
    float a[100];
    int n;

    taotep();              
    doctep(a, &n);       
    selectsort(a, n);
	printf("Day so da sap xep: ");     
     for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
    ghitep(a, n);         

    printf("Ghi vao file thanh cong");
    return 0;
}

