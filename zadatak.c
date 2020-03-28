#include <stdio.h>
#include <stdlib.h>

int veci(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int toInt(char a) {
    int x = a - '0';
    return x;
}

char toChar(int a) {
    return a + '0';
}

void ispisStringa(char A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", A[i]);
    }
    printf("\n");
}

void zbrajanjeStringova(char A[], int M, char B[], int N, char zbroj[]) {
    int i = veci(M, N) + 1;
    int pr = 0, a, b;

    while (M > 0 || N > 0) {
        M--;
        N--;
        i--;

        if (M >= 0 && N >= 0) {
            //pretvaranje char->int
            a = toInt(A[M]);
            b = toInt(B[N]);            

            //jedinicu upisujem
            zbroj[i] = toChar((a + b + pr) % 10);
            
            //desetica ide dalje
            pr = ((a + b + pr) / 10);

        }
        else if (N < 0) {
            a = toInt(A[M]);

            zbroj[i] = toChar((a + pr) % 10);
            pr = (a + pr) / 10;
        }
        else {
            b = toInt(B[N]);

            zbroj[i] = toChar((b + pr) % 10);
            pr = ((b + pr) / 10);
        }
        printf("\nprvi broj: %d\t drugi broj: %d\t desetica za dalje: %d", a, b, pr);
    }
    if (pr != 0) {
        //upis zadnjeg ostatka ako nije 0
        zbroj[0] = toChar(pr);
    }
    else {
        zbroj[0] = '\0';
    }
}

int main()
{
    const int M = 19, N = 15;
    char S1[M] = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char S2[N] = { '1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1', '2', '3', '4', '5'};
    
    char* rezultat = (char*)malloc(sizeof(char) * (veci(N, M) + 1));
    printf("\nM: %d\nPrvi string:\t", M);
    ispisStringa(S1, M);
    printf("\nN: %d\nDrugi string:\t", N);
    ispisStringa(S2, N);

    zbrajanjeStringova(S1, M, S2, N, rezultat);
    printf("\nZbroj: ");
    ispisStringa(rezultat, veci(N, M) + 1);
}
