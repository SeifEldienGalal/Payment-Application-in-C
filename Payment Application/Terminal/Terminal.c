#include <stdio.h>
#include <time.h>
#include <dos.h>
#include "Terminal.h"

ST_terminalData_t c2[5];

void getTransactionDateTest() {

	printf("Tester Name: SeifEldien\n");
	printf("Function Name: getTransactionDateTest\n");
	for (int i = 0; i <= 4; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data :");
		puts(c2[i].transactionDate);
		printf("Expected result: TERMINAL_OK \n");

		if (strlen(c2[i].transactionDate) == 0){
			printf("Actual result : WRONG_DATE\n");
		}
		else if (strlen(c2[i].transactionDate) < 10) {
			printf("Actual result : WRONG_DATE\n");
		}
		//else if ((strlen(c2[i].transactionDate) != strlen(("DD/MM/YYY")))) {
		//	printf("Actual result : WRONG_DATE\n");
	//	}
		else if (strlen(c2[i].transactionDate) > 10) {
			printf("Actual result : WRONG_DATE\n");
		}
		else {
			printf("Actual result:TERMINAL_OK\n ");
		};
	}
	printf("******************************\n");
	printf("******************************\n");

}


void isCardExpriedTest() {
	char ex_date, transdate;
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: isCardExpried\n");
	for (int i = 0; i <= 4; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data :");
		puts(c2[i].cardExpirationDate);
		char day[2], month[2], year[5],day_2[2],month_2[2],year_2[5];
		day[0] = c2[i].cardExpirationDate[0];
		day[1] = c2[i].cardExpirationDate[1];
		 
		month[0] = c2[i].cardExpirationDate[3];
		month[1] = c2[i].cardExpirationDate[4];

		year[0] = c2[i].cardExpirationDate[6];
		year[1] = c2[i].cardExpirationDate[7];
		year[2] = c2[i].cardExpirationDate[8];
		year[3] = c2[i].cardExpirationDate[9];


		//-----------------------------------------------------------

		day_2[0] = c2[i].transactionDate[0];
		day_2[1] = c2[i].transactionDate[1];

		month_2[0] = c2[i].transactionDate[3];
		month_2[1] = c2[i].transactionDate[4];

		year_2[0] = c2[i].transactionDate[6];
		year_2[1] = c2[i].transactionDate[7];
		year_2[2] = c2[i].transactionDate[8];
		year_2[3] = c2[i].transactionDate[9];

		int y1 = atoi(year);
		int y2 = atoi(year_2);

		int m1 = atoi(month);
		int m2 = atoi(month_2);

		int d1 = atoi(day);
		int d2 = atoi(day_2);
		 
		if (y1 >= y2) {
			printf("Expected result: TERMINAL_OK\n");
			printf("Actual result : EXPIRED_CARD\n");
		}
		else if (m1 >= m2) {
			printf("Expected result: TERMINAL_OK\n");
			printf("Actual result : EXPIRED_CARD\n");
		}
		else if (d1 >= d2) {
			printf("Expected result: TERMINAL_OK\n");
			printf("Actual result : EXPIRED_CARD\n");
		}
		else {
			printf("Expected result: TERMINAL_OK\n");
			printf("Actual result : TERMINAL_OK\n");
		}

		//ex_date = strptime(c2[i].cardExpirationDate);
		//transdate = strptime(c2[i].transactionDate);
		//printf("%c  %c", ex_date,transdate);
		//printf("d", difftime(ex_date, transdate));
		//printf("Test Case : %d \n", i);
		//printf("Input data :");
		//puts(c2[i].cardExpirationDate);
		//printf("Expected result: TERMINAL_OK \n");
		//if (difftime(ex_date, transdate)<=0) {
		//	printf("Actual result : EXPIRED_CARD\n");
		//}
		//else if (strlen(c2[i].cardExpirationDate) < 10) {
		//	printf("Actual result : WRONG_DATE\n");
		//}
		//else if ((strlen(c2[i].transactionDate) != strlen(("DD/MM/YYY")))) {
		//	printf("Actual result : WRONG_DATE\n");
	//	}
	//	else if (strlen(c2[i].cardExpirationDate) > 10) {
	//		printf("Actual result : WRONG_DATE\n");
	//	}
	//	else {
	//		printf("Actual result:TERMINAL_OK\n ");
	//	};
	}
	printf("******************************\n");
	printf("******************************\n");
}
void isBelowMaxAmountTest() {
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: isBelowMaxAmount\n");
	for (int i = 0; i <= 4; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data : %f \n",c2[i].transAmount);
	
		printf("Expected result: TERMINAL_OK \n");

		if (c2[i].transAmount > c2[i].maxTransAmount) {
			printf("Actual result : EXCEED_MAX_AMOUNT\n");
		}
		else   {
			printf("Actual result :TERMINAL_OK\n");
		}
	}
	printf("******************************\n");
	printf("******************************\n");


}



void  setMaxAmountTest() {
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: setMaxAmountTest\n");
	for (int i = 0; i <= 4; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data : %f \n", c2[i].maxTransAmount);

		printf("Expected result: TERMINAL_OK \n");

		if (c2[i].maxTransAmount<=0) {
			printf("Actual result : INVALID_MAX_AMOUNT\n");
		}
		else {
			printf("Actual result :TERMINAL_OK\n");
		}
	}
	printf("******************************\n");
	printf("******************************\n");


}

void getTransactionAmountTest() {
	printf("******************************\n");
	printf("******************************\n");

	printf("Tester Name: SeifEldien\n");
	printf("Function Name: getTransactionAmountTest\n");
	for (int i = 0; i <= 4; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data : %f \n", c2[i].transAmount);

		printf("Expected result: TERMINAL_OK \n");
		printf("Maximum transaction amount is: %f ", c2[i].maxTransAmount);
		printf("\n");
		if (c2[i].transAmount <= 0) {
			printf("Actual result : INVALID_AMOUNT\n");
		}
		else if (c2[i].transAmount > c2[i].maxTransAmount) {
			printf("Actual result : INVALID_AMOUNT\n");
		}
		else {
			printf("Actual result :TERMINAL_OK\n");
		}
	}
	printf("******************************\n");
	printf("******************************\n");
}



void isValidCardPANTest() {
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: isValidCardPANTest\n");
	for (int i = 0; i <= 4; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data : %f \n", c2[i].CardPAN);

		printf("Expected result: TERMINAL_OK \n");

		int length = checkLength(c2[i].CardPAN);
		if (length == 0) {
			printf("Actual result: INVALID_CARD\n");
			
		}
		else{
			int checkSumValue = checkSum1(c2[i].CardPAN, length);
			if (checkSumValue != 1) {
				printf("Actual result: INVALID_CARD\n");

			}
			else {
				printf("Actual result: TERMINAL_OK\n");

			}
		}

		

		//int cardType = validate(c2[i].CardPAN);
		//printf("%s\n", cardType);

	}
}

int checkLength(long int creditCard) {
	int i = 1;
	while (creditCard > 9) {
		i++;
		creditCard /= 10;
	}
	if (i < 13 || i>16) {
		return 0;
	}
	return i;
}

int checkSum1(long int creditCard, int length) {
	int i = 0;
	int temp = 0;
	int first = 0;
	int second = 0;
	int final = 0;

	while (creditCard) {
		if (i % 2 != 0) {
			first = ((creditCard % 10) * 2);
			if (first > 9) {
				while (first) {
					temp += first % 10;
					first /= 10;
				}
			}
			temp += first;
		}
		else {
			second += creditCard % 10;
		}
		creditCard /= 10;
		i++;
	}

	temp += second;

	final = temp % 10;

	if (final == 0) {
		return 1;
	}

	return 0;
}

int validate(long creditCard)
{
	
		// number2 will hold the first two digits.
		long int number1 = creditCard, number2 = creditCard;
		while (creditCard) {
			number2 = number1;
			number1 = creditCard;
			creditCard /= 10;
	}

		if (number2 == 34 || number2 == 37) {
			return 1;
		}

		if (number2 >= 51 && number2 <= 55) {
			return 1;
		}

		if (number2 >= 40 && number2 <= 49) {
			return 1;
		}

		return 0;

		
}



int terminals() {
	
	 strcpy(c2[0].transactionDate,"26/07/2022");
	strcpy(c2[0].cardExpirationDate, "23/02/2021");
	c2[0].transAmount = 12000;
	c2[0].maxTransAmount = 10000;
	c2[0].CardPAN = 5450752676678832;



	strcpy(c2[1].transactionDate,"26/07/2023");
	strcpy(c2[1].cardExpirationDate, "02/05/2024");
	c2[1].transAmount = 5000;
	c2[1].maxTransAmount = 3000;
	c2[1].CardPAN = 40001789010;

	strcpy(c2[2].transactionDate,"26/02/7");
	strcpy(c2[2].cardExpirationDate, "07/01/2024");
	c2[2].transAmount = 7000;
	c2[2].maxTransAmount = 7000;
	c2[2].CardPAN = 4000123446789010;

	strcpy(c2[3].transactionDate,"26/07/2022");
	strcpy(c2[3].cardExpirationDate, "06/02/2024");
	c2[3].transAmount = 5000;
	c2[3].maxTransAmount = 1000000;
	c2[3].CardPAN = 4000123456789010;

	strcpy(c2[4].transactionDate,"06/07/2022");
	strcpy(c2[4].cardExpirationDate, "02/02/2026");
	c2[4].transAmount = 0;
	c2[4].maxTransAmount = 0;
	c2[4].CardPAN = 5557789048348209;

	getTransactionDateTest();
	isCardExpriedTest();
	isBelowMaxAmountTest();
	setMaxAmountTest();
	isValidCardPANTest();
	getTransactionAmountTest();
}