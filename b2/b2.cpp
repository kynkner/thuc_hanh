#include<stdio.h>
#include<stdlib.h>

void taotep(){
	FILE * f = fopen("b2.txt", "w");
	fprintf(f, "5.375 5");
	fclose(f);
}

void doctep(float *x, int *n){
	FILE *f = fopen("b2.txt", "r");
	if(f == NULL){
		printf("Khong mo duoc tep \n");
		*x = 0;
		*n = 0;
		return;
	}
	fscanf(f,"%f %d", x, n);
	fclose(f);
}

char *doinhiphan(float x, int n) {
    long phannguyen = (long)x;
    float phanle = x - phannguyen;

    char a[64];
    char b[64];   
    int i = 0, j;
    if (phannguyen == 0)
        a[i++] = '0';
    else {
        while (phannguyen > 0) {
            a[i++] = (phannguyen % 2) + '0';
            phannguyen /= 2;
        }
    }
    for (j = 0; j < n; j++) {
        phanle *= 2;
        if (phanle >= 1) {
            b[j] = '1';
            phanle -= 1;
        } else {
            b[j] = '0';
        }
    }
    char *kq = (char *)malloc(i + n + 2);
    int k = 0;
    for (j = i - 1; j >= 0; j--)
        kq[k++] = a[j];
    kq[k++] = '.';
    for (j = 0; j < n; j++)
        kq[k++] = b[j];

    kq[k] = '\0';
    return kq;
}

int main() {
    float x;
    int n;

    taotep();           
    doctep(&x, &n);      

    char *bin = doinhiphan(x, n);		
    printf("So nhi phan: %s\n", bin);

    free(bin);
    return 0;
}
