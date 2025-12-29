#include <stdio.h>


void taotep() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "Xin Chao HaNoi 2025");
    fclose(f);
}

void doctep(char s[]) {
    FILE *f = fopen("data.txt", "r");
    int i = 0;
    char ch;

    if (f == NULL) {
        printf("Khong mo duoc tep!\n");
        return;
    }
     printf("Du lieu trong file: ");

    while ((ch = fgetc(f)) != EOF) {
        printf("%c", ch);   
        s[i++] = ch;      
    }
    printf("\n");
    s[i] = '\0';
//    fgets(s, 200, f);
    fclose(f);
}

int tongchuhoa(char s[]) {
    int dem = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z')
            dem++;
        i++;
    }
    return dem;
}

int main() {
    char s[200];

    taotep();
    doctep(s);
//	printf("%s ", s);

    printf("So ky tu chu hoa = %d", tongchuhoa(s));
    return 0;
}

