#include <stdio.h>

void taotep() {
    FILE *f = fopen("b4.txt", "w");
    fprintf(f, "6\n5.5 2.1 9.3 1.0 4.8 3.6");
    fclose(f);
}

void doctep(float a[], int *n) {
    FILE *f = fopen("b4.txt", "r");
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

void insertionsort(float a[], int n) {
    int i, j;
    float key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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
    insertionsort(a, n);   

    printf("Day so da sap xep: ");     
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    ghitep(a, n);           
	printf("Ghi vao file thanh cong");
    
	return 0;
}

