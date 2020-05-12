#include <stdio.h>
#include <stdbool.h>


void provjera(int* R, int N) {
	bool uzlazno = true;
	bool silazno = true;
	int t1, t2;

	t1 = R[0];
	t2 = R[0];

	for (int i = 1; i < N; i++) {
		if (R[i] < t1) {
			uzlazno = false;
		}
		else {
			t1 = R[i];
		}

		if (R[i] > t2) {
			silazno = false;
		}
		else {
			t2 = R[i];
		}
	}

	if (silazno == true || uzlazno == true) {
		printf("\nDA");
	}
	else {
		printf("\nNE");
	}
}


int main() {
	int N = 10;
	int R[10];

	//manji prema vecem
	for (int i = 0; i < N; i++) {
		R[i] = i;
	}

	provjera(R, N);

	//veci prema manjem
	for (int i = N-1; i > 0; i--) {
		R[i] = i;
	}

	provjera(R, N);

	//nije poredan
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			R[i] = i;
		}
		else {
			R[i] = i * 12;
		}
	}

	provjera(R, N);
}
