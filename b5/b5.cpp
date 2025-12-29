#include <stdio.h>

void taotep() {
    FILE *f = fopen("b5.txt", "w");
    fprintf(f, "6\n5.5 2.1 9.3 1.0 4.8 3.6");
    fclose(f);
}

void doctep(float a[], int *n) {
    FILE *f = fopen("b5.txt", "r");
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

void bubblesort(float a[], int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
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
    bubblesort(a, n);     

    printf("Day so da sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    ghitep(a, n);          
	printf("Ghi vao file thanh cong");
    
	return 0;
}

