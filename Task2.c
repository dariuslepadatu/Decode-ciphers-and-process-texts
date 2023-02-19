#include "./utils.h"
#define OSUTA 100
#define DOSUTE 200
#define OMIE 1000
#define AZERO 48
#define ANOUA 57
#define ZECE 10
#define ACINCI 53
#define ASASE 54
#define ALFA 26
#define AA 65
#define AZ 90
#define AE 69
#define Aa 97
#define Az 122
#define Af 102

void Caesar(int K, char sir[], int l) {
    int i = 0, u[OMIE], k = 0;
    for (i = 0; i < l - 1; i++) {
        u[i] = (int)sir[i];
       if (u[i] >= AZERO && u[i] <= ANOUA) {
            k = K%ZECE;
           if (u[i] - k < AZERO && u[i] <= ACINCI) {
               u[i] = u[i] - k + ZECE;
           } else if (u[i] - k < AZERO  && u[i] > ACINCI) {
               u[i] = u[i] - k;
               if (u[i] < AZERO) {
                   u[i] = u[i] + ZECE;
               }
           } else if (u[i] - k < AZERO) {
               u[i] = u[i] - k + ZECE;
           } else {
               u[i] = u[i] - k;
               if (u[i] < AZERO) {
                   u[i] = u[i] + ZECE;
               }
           }
        }

        if (u[i] >= AA && u[i] <= AZ) {
           if (u[i] - K < AA && K > ALFA && u[i] < AE) {
               u[i] = u[i] - K%ALFA + ALFA;
           } else if (u[i] - K < AA && K > ALFA && u[i] >= AE) {
               u[i] = u[i] - K%ALFA;
           } else if (u[i] - K < AA) {
               u[i] = u[i] - K + ALFA;
           } else {
               u[i] = u[i] - K;
           }
        }

        if (u[i] >= Aa && u[i] <= Az) {
           if (u[i] - K < Aa && K > ALFA && u[i] < Af) {
               u[i] = u[i] - K%ALFA + ALFA;
           } else if (u[i] - K < Aa && K > ALFA && u[i] >= Af) {
               u[i] = u[i] - K%ALFA;
           } else if (u[i] - K < Aa) {
               u[i] = u[i] - K + ALFA;
           } else {
               u[i] = u[i] - K;
           }
        }
          // printf("%d ", u[i]);
        }
    // printf("\n");
    for (i = 0; i < l - 1; i++) {
        printf("%c", u[i]);
    }
    // printf("\n");
    // printf("\n %s \n", sir);
}

void Vigenere(char cheie[], char sir[], int ls, int lc) {
    int i = 0, kext[OMIE], cont = 0, lext = 0, u[OMIE], k = 0;
    for (i = 0; i < ls; i++) {
        if (cont > lc-1) {
            cont = 0;
        }
        kext[i] = (int)cheie[cont]-AA;
        lext++;
        cont++;
        u[i] = (int)sir[i];
    // printf("%d ", kext[i]);
    }
    for (i = 0; i < ls; i++) {
        if (u[i] >= AZERO && u[i] <= ANOUA) {
            k = kext[i]%ZECE;
           if (u[i] - k < AZERO && u[i] <= ACINCI) {
               u[i] = u[i] - k + ZECE;
           } else if (u[i] - k < AZERO  && u[i] > ACINCI) {
               u[i] = u[i] - k;
               if (u[i] < AZERO) {
                   u[i] = u[i] + ZECE;
               }
           } else if (u[i] - k < AZERO) {
               u[i] = u[i] - k + ZECE;
           } else {
               u[i] = u[i] - k;
               if (u[i] < AZERO) {
                   u[i] = u[i] + ZECE;
               }
           }
        }
        if (u[i] >= AA && u[i] <= AZ) {
           if (u[i] - kext[i] < AA && kext[i] > ALFA && u[i] < AE) {
               u[i] = u[i] - kext[i]%ALFA + ALFA;
           } else if (u[i] - kext[i] < AA && kext[i] > ALFA && u[i] >= AE) {
               u[i] = u[i] - kext[i]%ALFA;
           } else if (u[i] - kext[i] < AA) {
               u[i] = u[i] - kext[i] + ALFA;
           } else {
               u[i] = u[i] - kext[i];
           }
        }

        if (u[i] >= Aa && u[i] <= Az) {
           if (u[i] - kext[i] < Aa && kext[i] > ALFA && u[i] < Af) {
               u[i] = u[i] - kext[i]%ALFA + ALFA;
           } else if (u[i] - kext[i] < Aa && kext[i] > ALFA && u[i] >= Af) {
               u[i] = u[i] - kext[i]%ALFA;
           } else if (u[i] - kext[i] < Aa) {
               u[i] = u[i] - kext[i] + ALFA;
           } else {
               u[i] = u[i] - kext[i];
           }
        }
        printf("%c", u[i]);
    }
}

void Addition(int K, char sir1[], char sir2[], int l1, int l2) {
    int i = 0, u[OMIE], v[OMIE], sum[OMIE], k = 0, ok = 0;
    int c = 0, cont = 0, j = 0, un[OMIE], vn[OMIE];
    if (sir1[l1-1] != '\n') {
        l1++;
    }
    if (sir2[l2-1] != '\n') {
        l2++;
    }
    for (i = 0; i < l1 - 1; i++) {
        u[i] = (int)sir1[i];
        if (u[i] >= AZERO && u[i] <= ANOUA) {
            k = K%ZECE;
           if (u[i] - k < AZERO && u[i] <= ACINCI) {
               u[i] = u[i] - k + ZECE;
           } else if (u[i] - k < AZERO  && u[i] > ACINCI) {
               u[i] = u[i] - k;
               if (u[i] < AZERO) {
                   u[i] = u[i] + ZECE;
               }
           } else if (u[i] - k < AZERO) {
               u[i] = u[i] - k + ZECE;
           } else {
               u[i] = u[i] - k;
               if (u[i] < AZERO) {
                   u[i] = u[i] + ZECE;
               }
           }
        }
        un[i] = (char)u[i] - '0';
        // printf("%d", un[i]);
    }
        // printf("\n");
    for (i = 0; i < l2 - 1; i++) {
        v[i] = (int)sir2[i];
        if (v[i] >= AZERO && v[i] <= ANOUA) {
            k = K%ZECE;
           if (v[i] - k < AZERO && v[i] <= ACINCI) {
               v[i] = v[i] - k + ZECE;
           } else if (v[i] - k < AZERO  && v[i] > ACINCI) {
               v[i] = v[i] - k;
               if (v[i] < AZERO) {
                   v[i] = v[i] + ZECE;
               }
           } else if (v[i] - k < AZERO) {
               v[i] = v[i] - k + ZECE;
           } else {
               v[i] = v[i] - k;
               if (v[i] < AZERO) {
                   v[i] = v[i] + ZECE;
               }
           }
        }
        vn[i] = (char)v[i] - '0';
        // printf("%d", vn[i]);
    }
    i = l1-2;
    j = l2-2;
    while (i >= 0 && j >= 0) {
        sum[cont] = (un[i] + vn[j] + c)%ZECE;
        c = (un[i] + vn[j] + c)/ZECE;
        cont++;
        i--;
        j--;
    }
    if (l1 < l2) {
        while (j >= 0) {
            sum[cont] = (vn[j] + c)%ZECE;
            c = (vn[j] + c)/ZECE;
            cont++;
            j--;
    }
    } else if (l1 > l2) {
        while (i >= 0) {
            sum[cont] = (un[i] + c)%ZECE;
            c = (un[i] + c)/ZECE;
            cont++;
            i--;
        }
    } else {
        if (c > 0) {
            sum[cont] = c;
            cont++;
        }
    }
    while (ok == 0) {
        if (sum[cont] != 0) {
            ok = 1;
        } else {
            cont--;
        }
    }
    for (cont; cont >= 0; cont--) {
    printf("%d", sum[cont]);
    }
}
void SolveTask2() {
    int lsir = 0, lcheie = 0, K = 0, nrtask = 0, lsir1 = 0, lsir2 = 0;
    char sir[OMIE], cheie[OMIE], codtask[OMIE], sir1[OMIE], sir2[OMIE];
    scanf("%d\n", &nrtask);
    fgets(codtask, OMIE, stdin);
    if (strcmp(codtask, "vigenere\n") == 0) {
        fgets(cheie, OMIE, stdin);
        fgets(sir, OMIE, stdin);
        for (lsir = 0; sir[lsir] != '\0'; ++lsir) {}
        for (lcheie = 0; cheie[lcheie] != '\0'; ++lcheie) {}
        if (cheie[lcheie-1] == '\n') {
            cheie[lcheie-1] = '\0';
            lcheie = lcheie-1;
        }
        if (sir[lsir-1] == '\n') {
        sir[lsir-1] = '\0';
        lsir = lsir-1;
        }
        Vigenere(cheie, sir, lsir, lcheie);
    } else if (strcmp(codtask, "caesar\n") == 0) {
        scanf("%d\n", &K);
        fgets(sir, OMIE, stdin);
        for (lsir = 0; sir[lsir] != '\0'; ++lsir) {}
        // for (i = lcheie-1; i >= 0; i--) {
        // // printf("%d",cheie[i]);
        // }
        // // printf("%d\n",K);
        Caesar(K, sir, lsir);
    }  else if (strcmp(codtask, "addition\n") == 0) {
        scanf("%d\n", &K);
        fgets(sir1, OMIE, stdin);
        for (lsir1 = 0; sir1[lsir1] != '\0'; ++lsir1) {}
        fgets(sir2, OMIE, stdin);
        for (lsir2 = 0; sir2[lsir2] != '\0'; ++lsir2) {}
        // puts(sir1);
        // puts(sir2);
        Addition(K, sir1, sir2, lsir1, lsir2);
    }
    printf("\n");
}



