#include "./utils.h"
#define ZECE 10
#define OSUTA 100
#define DOSUTE 200
#define AZERO 48
#define ANOUA 57
#define Aa 97
#define Ac 99
#define Aspace 32

int palindrom(int sum) {
    int pal = 0, aux = 0, r = 0;
    aux = sum;
    while (sum > 0) {
        r = sum%ZECE;
        sum = sum/ZECE;
        pal = pal*ZECE+r;
    }
    if (aux == pal) {
        return 1;
    } else {
        return 0;
    }
}

int prim(int sum) {
    int ok = 0 , n = sum%OSUTA, i = 0;
    for (i = 2; i <= n/2; i++) {
        if (n%i == 0) {
        ok = 1;
        }
    }
    if (ok == 1) {
        return 0;
    } else {
        return 1;
    }
}

int traseuC(int u[OSUTA], int N, int K) {
    int i = 0, suma = 0, cont = K, cont2 = 0;
    for (i = 0; i < N; i++) {
        if (i%K == 0 && (cont != 0)) {
            suma = suma + u[i];
            cont--;
            cont2 = cont2 + K;
        }
        while (cont != 0) {
        suma = suma + u[cont2%N];
        cont--;
        cont2 = cont2 + K;
        }
    }
    return suma;
}

void SolveTask1() {
        char sir[DOSUTE], cod[OSUTA] = {0};
        int j = 0, m = 0, n = 0, cont = 0, k = 0, a = 1;
        int i = 0, l = 0, amax = 0, xm = 0, yn = 0;
        int N = 0, K = 0, u[OSUTA], cont1 = 0, matrix[OSUTA][OSUTA]={0};
        int miscare = 1, num = 0, sum = 0;
        char max = '0';
        scanf("%d %d\n", &m, &n);
        fgets(sir, DOSUTE, stdin);
        // puts(sir);
        int lungime = 0;
        matrix[0][0] = 1;
        for (lungime = 0; sir[lungime] != '\0'; ++lungime) {}
        if (sir[lungime-1] < AZERO ||
        (sir[lungime-1] > ANOUA && sir[lungime-1] < Aa) ||
        sir[lungime-1] > Ac) {
        sir[lungime-1]='\0';
        }
        if (sir[lungime-2] < AZERO ||
        (sir[lungime-2] > ANOUA && sir[lungime-2] < Aa) ||
        sir[lungime-2] > Ac) {
        sir[lungime-2]='\0';
        }
            while (i <= lungime) {
                if (sir[i] == ' ' || i == lungime || sir[lungime] == ' ') {
                    k = 0;
                    for (j = cont; j < i; j++) {
                        if ((sir[j] >= AZERO && sir[j] <= ANOUA)
                        || (sir[j] >= Aa && sir[j] <= Ac)) {
                        cod[k] = sir[j];
                        k = k+1;
                        }
                    }
                    if (cod[0] == 'a') {
                        max = -1;
                        for (l = 1; l < k; l++) {
                            if (cod[l] > max) {
                                max = cod[l];
                                amax = l;
                            }
                        }
                        if (amax == 1) {
                            yn++;
                            miscare++;
                        }
                        if (amax == 2) {
                            xm--;
                            miscare++;
                        }
                        if (amax == 3) {
                            yn--;
                            miscare++;
                        }
                        if (amax == 4) {
                            xm++;
                            miscare++;
                        }
                        matrix[xm][yn] = miscare;
                    }
                    if (cod[0] == 'b') {
                        sum = 0;
                        a = 1;
                        for (l = k - 1; l >= 1; l--) {
                            num = cod[l] - '0';
                            sum = sum + a*num;
                            a = a*ZECE;
                        }
                    if (palindrom(sum) == 1 && prim(sum%OSUTA) == 1) {
                        yn--;
                        miscare++;
                    }
                    if (palindrom(sum) == 1 && prim(sum%OSUTA) == 0) {
                        yn++;
                        miscare++;
                    }
                    if (palindrom(sum) == 0 && prim(sum%OSUTA) == 1) {
                        xm--;
                        miscare++;
                    }
                    if (palindrom(sum) == 0 && prim(sum%OSUTA) == 0) {
                        xm++;
                        miscare++;
                    }
                        matrix[xm][yn] = miscare;
                    }
                    if (cod[0] == 'c') {
                        N = cod[1] - '0';
                        K = cod[2] - '0';
                        cont1 = 0;
                        for (l = 3; l < k; l++) {
                            u[cont1] = cod[l] - '0';
                            cont1++;
                        }
                        if (traseuC(u, N, K) % 4 == 0) {
                            yn--;
                            miscare++;
                        }
                        if (traseuC(u, N, K) % 4 == 1) {
                            xm--;
                            miscare++;
                        }
                        if (traseuC(u, N, K) % 4 == 2) {
                            yn++;
                            miscare++;
                        }
                        if (traseuC(u, N, K) % 4 == 3) {
                            xm++;
                            miscare++;
                        }
                        matrix[xm][yn] = miscare;
                    }
                    cont = i+1;
                }
                i = i+1;
            }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
}
