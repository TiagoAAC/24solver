#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char* argv[]) {

	double a, b, c, d;
	bool ativo = true;

	do {
		printf("Enter 4 numbers or 0 0 0 0 to leave:\n");
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

		bool flag = false;

		double ab[6], cd[6], ac[6], bd[6], bc[6], ad[6];
		char tab[6][20], tcd[6][20], tac[6][10], tbd[6][10], tbc[6][10], tad[6][10];


		//VALIDATE INPUT
		while (ativo && (a <= 0 || b <= 0 || c <= 0 || d <= 0)) {
			if (a == 0 && b == 0 && c == 0 && d == 0) {
				ativo = false;
			}
			else
				if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
					printf("Invalid numbers, please enter numbers positive numers above 0\n");
					scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
				}
		}


		if (ativo == true) {



			// FASE 1
			//DECLARE POSSIBILITIES BETWEEN AB , CD, AC, BD, BC, AD
			//STORE THE OPERATIONS IN A STRING ARRAY
			ab[0] = a + b;
			ab[1] = a - b;
			ab[2] = b - a;
			ab[3] = a * b;
			ab[4] = a / b;
			ab[5] = b / a;

			sprintf(tab[0], "(%d + %d)", (int)a, (int)b);
			sprintf(tab[1], "(%d - %d)", (int)a, (int)b);
			sprintf(tab[2], "(%d - %d)", (int)b, (int)a);
			sprintf(tab[3], "%d * %d", (int)a, (int)b);
			sprintf(tab[4], "%d / %d", (int)a, (int)b);
			sprintf(tab[5], "%d / %d", (int)b, (int)a);


			cd[0] = c + d;
			cd[1] = c - d;
			cd[2] = d - c;
			cd[3] = c * d;
			cd[4] = c / d;
			cd[5] = d / c;

			sprintf(tcd[0], "(%d + %d)", (int)c, (int)d);
			sprintf(tcd[1], "(%d - %d)", (int)c, (int)d);
			sprintf(tcd[2], "(%d - %d)", (int)d, (int)c);
			sprintf(tcd[3], "%d * %d", (int)c, (int)d);
			sprintf(tcd[4], "%d / %d", (int)c, (int)d);
			sprintf(tcd[5], "%d / %d", (int)d, (int)c);


			ac[0] = a + c;
			ac[1] = a - c;
			ac[2] = c - a;
			ac[3] = a * c;
			ac[4] = a / c;
			ac[5] = c / a;

			sprintf(tac[0], "(%d + %d)", (int)a, (int)c);
			sprintf(tac[1], "(%d - %d)", (int)a, (int)c);
			sprintf(tac[2], "(%d - %d)", (int)c, (int)a);
			sprintf(tac[3], "%d * %d", (int)a, (int)c);
			sprintf(tac[4], "%d / %d", (int)a, (int)c);
			sprintf(tac[5], "%d / %d", (int)c, (int)a);

			bd[0] = b + d;
			bd[1] = b - d;
			bd[2] = d - b;
			bd[3] = b * d;
			bd[4] = b / d;
			bd[5] = d / b;

			sprintf(tbd[0], "(%d + %d)", (int)b, (int)d);
			sprintf(tbd[1], "(%d - %d)", (int)b, (int)d);
			sprintf(tbd[2], "(%d - %d)", (int)d, (int)b);
			sprintf(tbd[3], "%d * %d", (int)b, (int)d);
			sprintf(tbd[4], "%d / %d", (int)b, (int)d);
			sprintf(tbd[5], "%d / %d", (int)d, (int)b);

			bc[0] = b + c;
			bc[1] = b - c;
			bc[2] = c - b;
			bc[3] = b * c;
			bc[4] = b / c;
			bc[5] = c / b;

			sprintf(tbc[0], "(%d + %d)", (int)b, (int)c);
			sprintf(tbc[1], "(%d - %d)", (int)b, (int)c);
			sprintf(tbc[2], "(%d - %d)", (int)c, (int)b);
			sprintf(tbc[3], "%d * %d", (int)b, (int)c);
			sprintf(tbc[4], "%d / %d", (int)b, (int)c);
			sprintf(tbc[5], "%d / %d", (int)c, (int)b);

			ad[0] = a + d;
			ad[1] = a - d;
			ad[2] = d - a;
			ad[3] = a * d;
			ad[4] = a / d;
			ad[5] = d / a;

			sprintf(tad[0], "(%d + %d)", (int)a, (int)d);
			sprintf(tad[1], "(%d - %d)", (int)a, (int)d);
			sprintf(tad[2], "(%d - %d)", (int)d, (int)a);
			sprintf(tad[3], "%d * %d", (int)a, (int)d);
			sprintf(tad[4], "%d / %d", (int)a, (int)d);
			sprintf(tad[5], "%d / %d", (int)d, (int)a);


			//FASE 2
			//MATH

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (ab[i] + cd[j]  == 24 && flag == false) {
						printf("%s + %s = 24\n", tab[i], tcd[j]);
						flag=true;  
						 
					}
					if (ab[i] - cd[j]  == 24 && flag == false) {
						printf("%s - %s = 24\n", tab[i], tcd[j]);
						flag=true;  
						 
					}
					if (ab[i] * cd[j]  == 24 && flag == false) {
						printf("%s * %s = 24\n", tab[i], tcd[j]);
						flag=true;  
						 
					}
					if (cd[j] != 0) {
						if (ab[i] / cd[j]  == 24 && flag == false) {
							printf("%s / %s = 24\n", tab[i], tcd[j]);
							flag=true;  
							 
						}
					}
					if (cd[j] - ab[i]  == 24 && flag == false) {
						printf("%s - %s = 24\n", tcd[j], tab[i]);
						flag=true;  
						 
					}
					//SOLO */
					if (ab[i] * c) {
						if (ab[i] * c + d  == 24 && flag == false) {
							printf("%s * %d + %d = 24\n", tab[i], (int)c, (int)d);
							flag=true;  
							 
						}
						if (ab[i] * c - d  == 24 && flag == false) {
							printf("%s * %d - %d = 24\n", tab[i], (int)c, (int)d);
							flag=true;  
							 
						}
						if (ab[i] * c * d  == 24 && flag == false) {
							printf("%s * %d * %d = 24\n", tab[i], (int)c, (int)d);
							flag=true;  
							 
						}
						if (ab[i] * c / d  == 24 && flag == false) {
							printf("%s * %d / %d = 24\n", tab[i], (int)c, (int)d);
							flag=true;  
							 
						}
					}
					if (ab[i] / c + d  == 24 && flag == false) {
						printf("%s / %d + %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if (ab[i] / c - d  == 24 && flag == false) {
						printf("%s / %d - %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if (ab[i] / c * d  == 24 && flag == false) {
						printf("%s / %d * %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if (ab[i] / c / d  == 24 && flag == false) {
						printf("%s / %d / %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if (ab[i] * d + c  == 24 && flag == false) {
						printf("%s * %d + %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] * d - c  == 24 && flag == false) {
						printf("%s * %d - %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] * d * c  == 24 && flag == false) {
						printf("%s * %d * %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] * d / c  == 24 && flag == false) {
						printf("%s * %d / %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] / d + c  == 24 && flag == false) {
						printf("%s / %d + %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] / d - c  == 24 && flag == false) {
						printf("%s / %d - %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] / d * c  == 24 && flag == false) {
						printf("%s / %d * %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if (ab[i] / d / c  == 24 && flag == false) {
						printf("%s / %d / %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}

					//SOLO ab +-
					if ((ab[i] + c) * d  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if ((ab[i] + c) / d  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if ((ab[i] - c) * d  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if ((ab[i] - c) / d  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tab[i], (int)c, (int)d);
						flag=true;  
						 
					}
					if ((ab[i] - d) * c  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if ((ab[i] - d) / c  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if ((ab[i] + d) * c  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tab[i], (int)d, (int)c);
						 
						flag=true;  
					}
					if ((ab[i] + d) / c  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tab[i], (int)d, (int)c);
						flag=true;  
						 
					}
					if ((c - ab[i]) * d  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)c, tab[i], (int)d);
						flag=true;  
						 
					}
					if ((c - ab[i]) / d  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)c, tab[i], (int)d);
						flag=true;  
						 
					}
					if ((d - ab[i]) * c  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)d, tab[i], (int)c);
						flag=true;  
						 
					}
					if ((d - ab[i]) / c  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)d, tab[i], (int)c);
						flag=true;  
						 
					}
					//SOLO cd +-
					if ((cd[j] + a) * b  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tcd[j], (int)a, (int)b);
						flag=true;  
						 
					}
					if ((cd[j] + a) / b  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tcd[j], (int)a, (int)b);
						flag=true;  
						 
					}
					if ((cd[j] - a) * b  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tcd[j], (int)a, (int)b);
						flag=true;
						 
					}
					if ((cd[j] - a) / b  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tcd[j], (int)a, (int)b);
						flag=true;  
					}
					if ((cd[j] + b) * a  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tcd[j], (int)b, (int)a);
						flag=true;  
					}
					if ((cd[j] + b) / a  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tcd[j], (int)b, (int)a);
						flag=true;  
					}
					if ((cd[j] - b) * a  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tcd[j], (int)b, (int)a);
						flag=true;  
					}
					if ((cd[j] - b) / a  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tcd[j], (int)b, (int)a);
						flag=true;  
					}
					if ((a - cd[j]) * b  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)a, tcd[j], (int)b);
						flag=true;  
					}
					if ((a - cd[j]) / b  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)a, tcd[j], (int)b);
						flag=true;  
					}
					if ((b - cd[j]) * a  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)b, tcd[j], (int)a);
						flag=true;  
					}
					if ((b - cd[j]) / a  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)b, tcd[j], (int)a);
						flag=true;  
					}
				}
			}

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (ac[i] + bd[j]  == 24 && flag == false) {
						printf("%s + %s = 24\n", tac[i], tbd[j]);
						flag=true;  
					}
					if (ac[i] - bd[j]  == 24 && flag == false) {
						printf("%s - %s = 24\n", tac[i], tbd[j]);
						flag=true;  
					}
					if (ac[i] * bd[j]  == 24 && flag == false) {
						printf("%s * %s = 24\n", tac[i], tbd[j]);
						flag=true;  
					}
					if (bd[j] != 0) {
						if (ac[i] / bd[j]  == 24 && flag == false) {
							printf("%s / %s = 24\n", tac[i], tbd[j]);
							flag=true;  
						}
					}
					if (ac[i] * b) {
						if (ac[i] * b + d  == 24 && flag == false) {
							printf("%s * %d + %d = 24\n", tac[i], (int)b, (int)d);
							flag=true;  
						}
						if (ac[i] * b - d  == 24 && flag == false) {
							printf("%s * %d - %d = 24\n", tac[i], (int)b, (int)d);
							flag=true;  
						}
						if (ac[i] * b * d  == 24 && flag == false) {
							printf("%s * %d * %d = 24\n", tac[i], (int)b, (int)d);
							flag=true;  
						}
						if (ac[i] * b / d  == 24 && flag == false) {
							printf("%s * %d / %d = 24\n", tac[i], (int)b, (int)d);
							flag=true;  
						}
					}
					if (ac[i] / b + d  == 24 && flag == false) {
						printf("%s / %d + %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if (ac[i] / b - d  == 24 && flag == false) {
						printf("%s / %d - %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if (ac[i] / b * d  == 24 && flag == false) {
						printf("%s / %d * %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if (ac[i] / b / d  == 24 && flag == false) {
						printf("%s / %d / %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}

					if (ac[i] * d + b  == 24 && flag == false) {
						printf("%s * %d + %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] * d - b  == 24 && flag == false) {
						printf("%s * %d - %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] * d * b  == 24 && flag == false) {
						printf("%s * %d * %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] * d / b  == 24 && flag == false) {
						printf("%s * %d / %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] / d + b  == 24 && flag == false) {
						printf("%s / %d + %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] / d - b  == 24 && flag == false) {
						printf("%s / %d - %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] / d * b  == 24 && flag == false) {
						printf("%s / %d * %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if (ac[i] / d / b  == 24 && flag == false) {
						printf("%s / %d / %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}

					//SOLO
					if ((ac[i] + b) * d  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if ((ac[i] + b) / d  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if ((ac[i] - b) * d  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if ((ac[i] - b) / d  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tac[i], (int)b, (int)d);
						flag=true;  
					}
					if ((ac[i] - d) * b  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if ((ac[i] - d) / b  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if ((ac[i] + d) * b  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if ((ac[i] + d) / b  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tac[i], (int)d, (int)b);
						flag=true;  
					}
					if ((b - ac[i]) * d  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)b, tac[i], (int)d);
						flag=true;  
					}
					if ((b - ac[i]) / d  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)b, tac[i], (int)d);
						flag=true;  
					}
					if ((d - ac[i]) * b  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)d, tac[i], (int)b);
						flag=true;  
					}
					if ((d - ac[i]) / b  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)d, tac[i], (int)b);
						flag=true;  
					}
					if ((a - bd[j]) * c  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)a, tbd[j], (int)c);
						flag=true;  
					}
					if ((a - bd[j]) / c  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)a, tbd[j], (int)c);
						flag=true;  
					}
					if ((c - bd[j]) * a  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)c, tbd[j], (int)a);
						flag=true;  
					}
					if ((c - bd[j]) / a  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)c, tbd[j], (int)a);
						flag=true;  
					}
					if ((bd[j] + a) * c  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tbd[j], (int)a, (int)c);
						flag=true;  
					}
					if ((bd[j] + a) / c  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tbd[j], (int)a, (int)c);
						flag=true;  
					}
					if ((bd[j] + c) * a  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tbd[j], (int)c, (int)a);
						flag=true;  
					}
					if ((bd[j] + c) / a  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tbd[j], (int)c, (int)a);
						flag=true;  
					}

				}
			}

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (bc[i] + ad[j]  == 24 && flag == false) {
						printf("%s + %s = 24\n", tbc[i], tad[j]);
						flag=true;  
					}
					if (bc[i] - ad[j]  == 24 && flag == false) {
						printf("%s - %s = 24\n", tbc[i], tad[j]);
						flag=true;  
					}
					if (bc[i] * ad[j]  == 24 && flag == false) {
						printf("%s * %s = 24\n", tbc[i], tad[j]);
						flag=true;  
					}
					if (ad[j] != 0) {
						if (bc[i] / ad[j]  == 24 && flag == false) {
							printf("%s / %s = 24\n", tbc[i], tad[j]);
							flag=true;  
						}
					}
					if (bc[i] * a) {
						if (bc[i] * a + d  == 24 && flag == false) {
							printf("%s * %d + %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
						if (bc[i] * a - d  == 24 && flag == false) {
							printf("%s * %d - %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
						if (bc[i] * a * d  == 24 && flag == false) {
							printf("%s * %d * %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
						if (bc[i] * a / d  == 24 && flag == false) {
							printf("%s * %d / %d = 24\n", tbc[i], (int)a, (int)d);

						}
					}
					if (bc[i] / a + d  == 24 && flag == false) {
						printf("%s / %d + %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] / a - d  == 24 && flag == false) {
						printf("%s / %d - %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] / a * d  == 24 && flag == false) {
						printf("%s / %d * %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] / a / d  == 24 && flag == false) {
						printf("%s / %d / %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] * d + a  == 24 && flag == false) {
						printf("%s * %d + %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] * d - a  == 24 && flag == false) {
						printf("%s * %d - %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] * d * a  == 24 && flag == false) {
						printf("%s * %d * %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] * d / a  == 24 && flag == false) {
						printf("%s * %d / %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] / d + a  == 24 && flag == false) {
						printf("%s / %d + %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] / d - a  == 24 && flag == false) {
						printf("%s / %d - %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] / d * a  == 24 && flag == false) {
						printf("%s / %d * %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] / d / a  == 24 && flag == false) {
						printf("%s / %d / %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if (bc[i] * a + d  == 24 && flag == false) {
						printf("%s * %d + %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] * a - d  == 24 && flag == false) {
						printf("%s * %d - %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] * a * d  == 24 && flag == false) {
						printf("%s * %d * %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if (bc[i] * a / d  == 24 && flag == false) {
						printf("%s * %d / %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}

					//+-
					if (bc[i] + a) {
						if ((bc[i] + a) * d  == 24 && flag == false) {
							printf("(%s + %d) * %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
						if ((bc[i] + a) / d  == 24 && flag == false) {
							printf("(%s + %d) / %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
					}
					if (bc[i] - a) {
						if ((bc[i] - a) * d  == 24 && flag == false) {
							printf("(%s - %d) * %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
						if ((bc[i] - a) / d  == 24 && flag == false) {
							printf("(%s - %d) / %d = 24\n", tbc[i], (int)a, (int)d);
							flag=true;  
						}
					}
					if (bc[i] - d) {
						if ((bc[i] - d) * a  == 24 && flag == false) {
							printf("(%s - %d) * %d = 24\n", tbc[i], (int)d, (int)a);
							flag=true;  
						}
						if ((bc[i] - d) / a  == 24 && flag == false) {
							printf("(%s - %d) / %d = 24\n", tbc[i], (int)d, (int)a);
							flag=true;  
						}
					}
					if ((bc[i] + d) * a  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tbc[i], (int)d, (int)a);

					}
					if ((bc[i] + d) / a  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if ((a - bc[i]) * d  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)a, tbc[i], (int)d);
						flag=true;  
					}
					if ((a - bc[i]) / d  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)a, tbc[i], (int)d);
						flag=true;  
					}
					if ((d - bc[i]) * a  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)d, tbc[i], (int)a);
						flag=true;  
					}
					if ((d - bc[i]) / a  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)d, tbc[i], (int)a);
						flag=true;  
					}
					if ((b - ad[j]) * c  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)b, tad[j], (int)c);
						flag=true;  
					}
					if ((b - ad[j]) / c  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)b, tad[j], (int)c);
						flag=true;  
					}
					if ((c - ad[j]) * b  == 24 && flag == false) {
						printf("(%d - %s) * %d = 24\n", (int)c, tad[j], (int)b);
						flag=true;  
					}
					if ((c - ad[j]) / b  == 24 && flag == false) {
						printf("(%d - %s) / %d = 24\n", (int)c, tad[j], (int)b);
						flag=true;  
					}
					if ((bc[i] + a) * d  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if ((bc[i] + a) / d  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if ((bc[i] - a) * d  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if ((bc[i] - a) / d  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tbc[i], (int)a, (int)d);
						flag=true;  
					}
					if ((bc[i] - d) * a  == 24 && flag == false) {
						printf("(%s - %d) * %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if ((bc[i] - d) / a  == 24 && flag == false) {
						printf("(%s - %d) / %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if ((bc[i] + d) * a  == 24 && flag == false) {
						printf("(%s + %d) * %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
					if ((bc[i] + d) / a  == 24 && flag == false) {
						printf("(%s + %d) / %d = 24\n", tbc[i], (int)d, (int)a);
						flag=true;  
					}
				}

			}
		}



		if (flag == false && ativo) {
			printf("No possible solutions found\n");
		}

	} while (ativo);



	return 0;
}