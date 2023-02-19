#include "./utils.h"
#define MAX 6000
#define OSUTA 100
#define ZECE 10
#define AA 65
#define AZ 90
#define Aa 97
#define Az 122

void citire(char *s) {
    int i = 0;
    while (scanf("%c", &s[i]) != EOF) {
        if (s[i-1] == ZECE && s[i] == ZECE) {
        } else {
            i++;
        }
    }
    s[i] = '\0';
}

void SolveTask3() {
    char s[MAX], pairs[MAX][OSUTA];
    int nrapp[MAX] = {0};
    int p = 0, q = 0, cont = 0, l0 = 0, k = 0;
    int nrtask = 0, i = 0, j = 0, ok = 0;
    int sum = 0;
    scanf("%d\n", &nrtask);
    citire(s);
    // printf("%s", s);
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != ',' &&
        s[i] != '.'&& s[i] != '!' && s[i] != ';') {
            pairs[p][q] = s[i];
            if (s[i] != ' ' && s[i] != '\n') {
                q++;
            }
        } else if (s[i] == ' ' || s[i] == '\n') {
            p++;
            q = 0;
        }
    }
    p++;
    while ((pairs[p][0] < AA || pairs[p][0] > AZ) &&
    (pairs[p][0] < Aa || pairs[p][0] > Az)) {
        p--;
    }
    for (i = 0; i < p; i++) {
        strncat(pairs[i], " ", OSUTA);
        strncat(pairs[i], pairs[i+1], OSUTA);
    }
    for (i = 0; i < p; i++) {
        for (j = i+1; j < p; j++) {
            if (strcmp(pairs[i], pairs[j]) == 0) {
                for (k = j; k < p+1; k++) {
                    strncpy(pairs[k], pairs[k+1], OSUTA);
                    nrapp[k] = nrapp[k+1];
                }
                nrapp[i]++;
                p--;
            }
        }
    }
    for (i = 0; i < p; i++) {
        nrapp[i]++;
        sum++;
    }
    printf("%d\n", sum);
    for (i = 0; i < p; i++) {
        printf("%s %d\n", pairs[i], nrapp[i]);
    }
}
