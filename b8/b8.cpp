#include <stdio.h>

void taotep() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "6\n1.5 -2.0 3.21 -4.12 5.0 0.0");
    fclose(f);
}

void doctep(float a[], int *n) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        *n = 0;
        return;
    }

    fscanf(f, "%d", n);
    printf("Du lieu doc tu tep: ");
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%f", &a[i]);
        printf("%.2f ", a[i]);
    }
    printf("\n");

    fclose(f);
}

float tongduong(float a[], int n) {
    float tong = 0.0f;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            tong += a[i];
        }
    }
    return tong;
}

int main() {
    float a[100];
    int n;
    float kq;

    taotep();            
    doctep(a, &n);        
	
	printf("Day so da sap xep: ");     
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
	
    kq = tongduong(a, n);

    printf("Tong cac so duong trong day la: %.2f\n", kq);

    return 0;
}

