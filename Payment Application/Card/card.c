#include <stdio.h>
#include "../Card/card.h"
ST_cardData_t c1[5];

void getCardHolderNameTest() {
	int s;
	printf("Tester Name: SeifEldien\n");
	printf("Functio+n Name: getCardHolderName\n");
	for (int i = 0;i <= 4;i++) {
		s = sizeof(c1[0].cardHolderName);
		printf("Test Case : %d \n", i);
		printf("Input data :");
		puts(c1[i].cardHolderName);
		if (strlen(c1[i].cardHolderName) < 20) {
			printf("Actual result : WRONG_NAME\n");
		}
		else if (strlen(c1[i].cardHolderName) > 24) {
			printf("Actual result : LIMIT_EXCEEDED\n");
		}
		else
			printf("Actual result : CARD_OK\n");
	}
	printf("******************************\n");
	printf("******************************\n");
}

		void getcardExpirationDate() {
			int s;
			printf("Tester Name: SeifEldien\n");
			printf("Function Name: cardExpirationDate\n");
			for (int i = 0;i <= 4;i++) {
				s = sizeof(c1[0].cardExpirationDate);
				printf("Test Case : %d \n", i);
				printf("Input data :");
				puts(c1[i].cardExpirationDate);
				if (strlen(c1[i].cardExpirationDate) == 0) {
					printf("Actual result : WRONG_EXP_DATE\n");
				}
				else if (strlen(c1[i].cardExpirationDate) > 5) {
					printf("Actual result : WRONG_EXP_DATE\n");
				}
				else if (strlen(c1[i].cardExpirationDate) < 5) {
					printf("Actual result : WRONG_EXP_DATE\n");
				}
				else {
					printf("Actual result : CARD_OK\n");
				}
			}
			printf("******************************\n");
			printf("******************************\n");
		}


		void getCardPANTest(){
			uint8_t PAN[19];
			char x = " ";
			char z = " ";
			int s = 0;
			
			

			printf("Tester Name: SeifEldien\n");
			printf("Function Name: primaryAccountNumber\n");
			for (int i = 0;i <= 4;i++) {
				printf("Test Case : %d \n", i);
				printf("Input data :");
				puts(c1[i].primaryAccountNumber);
				for(int j = 0;j<=19;j++){
					z = c1[i].primaryAccountNumber[j];
				if(isalpha(z)==1) {
					//printf("PAN_CHECK : WRONG_PAN\n");
					s = 1;
				}
				else if (isalpha(z) == 2) {
					//printf("PAN_CHECK : WRONG_PAN\n");
					s = 1;
				}
				else {
					//printf("PAN_CHECK : OK\n");
				}

				}
				if (s == 0) {

					if (strlen(c1[i].primaryAccountNumber) == 0) {
						printf("Actual result : WRONG_PAN\n");
					}
					else if (strlen(c1[i].primaryAccountNumber) > 19) {
						printf("Actual result : WRONG_PAN\n");
					}
					else if (strlen(c1[i].primaryAccountNumber) < 16) {
						printf("Actual result : WRONG_PAN\n");
					}
					else  {
						puts("CARD_OK\n");
					}

				}

				else {
					printf("WRONG_PAN\n");
				}
			}
		}

int cards() {
	
		strcpy(c1[0].cardHolderName,"seifo");
		strcpy(c1[0].cardExpirationDate,"02/2024");
		strcpy(c1[0].primaryAccountNumber,"4567");



		strcpy(c1[1].cardHolderName, "seifooooop");
		strcpy(c1[1].cardExpirationDate, "02/2024");
		strcpy(c1[1].primaryAccountNumber, "10231456789034567");

		strcpy(c1[2].cardHolderName, "se");
		strcpy(c1[2].cardExpirationDate, "07/2024");
		strcpy(c1[2].primaryAccountNumber, "0");

		strcpy(c1[3].cardHolderName, "seifooooooooooooooooooo");
		strcpy(c1[3].cardExpirationDate, "06/24");
		strcpy(c1[3].primaryAccountNumber, "83737dhdfdgf34rty");
	
	
		strcpy(c1[4].cardHolderName, "seifodsodsodo");
		strcpy(c1[4].cardExpirationDate, "02/26");
		strcpy(c1[4].primaryAccountNumber, "83737");
	
	getCardHolderNameTest(c1);
	getcardExpirationDate(c1);
	getCardPANTest(c1);
}

