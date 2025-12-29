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
    
    fgets(s, 200, f);
    fclose(f);
}

char *doichuhoa(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z'){
        	s[i] = s[i] - 32;
		}
       i++;
    }
    return s;
}

int main() {
    char s[200];

    taotep();
    doctep(s);
	printf("Du lieu trong file: %s ", s);
	printf("\n");
    printf("So ky tu chu hoa: %s ", doichuhoa(s));
    return 0;
}

