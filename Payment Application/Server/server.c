#include<stdio.h>
#include"server.h"
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

EN_transState_t tstate;
ST_accountsDB_t accountsDB[255];
ST_transaction_t axx[255] = {0};
ST_transaction_t savedtrans[255] = { 0 };



void listSavedTransactions() {
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: listSavedTransactions\n");
	int lower = 1, upper = 6, count = 10;
	char result[50];
	float x;
	EN_accountState_t op;
	op = RUNNING;
	uint8_t res[200] = " ";
	uint8_t transaction[20] = " ";
	uint8_t DB[20] = " ";
	int s;
	s = 0;
	for (int i = 0; i < 11; i++) {
		printf(" #########################\n");
		for (int j = 0; j < 11; j++) {
			
			strcpy(DB, accountsDB[j].primaryAccountNumber);
			strcpy(transaction, axx[i].cardHolderData.primaryAccountNumber);
			if (strcmp(DB, transaction) == 0) {//0 MEANS THAT IF THEY ARE EQUAL!


				if (axx[i].terminalData.maxTransAmount >= axx[i].terminalData.transAmount) {
					if (accountsDB[j].state == op) {
						if (accountsDB[j].balance >= axx[i].terminalData.transAmount) {

							s = 1;
							printf("Balance Before transaction:%f\n", accountsDB[j].balance);
							strcpy(res, "Actual result : APPROVED\n");
							accountsDB[j].balance = accountsDB[j].balance - axx[i].terminalData.transAmount;
							x = accountsDB[j].balance;
							j = 11;
						}
						else {
							printf("Actual result : DECLINED_INSUFFECIENT_FUND\n");
						}
					}
					}
					else {
						strcpy(res, "Transaction exceeds the Maximum allowed amount...");
						s = 2;
					}
					

			}
			else {
					strcpy(res, "Actual result : DECLINED_STOLEN_CARD\n");
					s = 2;
			}
			}

		
		printf("\n");
		printf("Test Case : %d \n", i);
		printf("Input data :\n");
		printf("Old Transaction Sequence Number is:%s\n", axx[i].transactionSequenceNumber);
		printf("The New Transaction sequence number is: ");
		for (int j = 0; j < count; j++) {
			int num = (rand() % (upper - lower + 1)) + lower;
			sprintf(result, "%i", num);
			printf("%s", result);
			

		}
		printf("\n");
		printf("Transaction Date:%s\n", axx[i].terminalData.transactionDate);
		printf("Transaction Amount:%f\n", axx[i].terminalData.transAmount);

		if (s == 0) {
			strcpy(res, "Actual result : FRAUD_CARD\n");
		}
		else if (s == 1) {
			printf("Balance After Transaction :%f \n", x);
		}
		else {
			printf("Balance After Transaction : Denied Transaction \n");

		}
		puts(res);
		
	
		printf("Cardholder Name: %s\n", axx[i].cardHolderData.cardHolderName);
		if (strlen(axx[i].cardHolderData.cardHolderName) < 20) {
			printf("Actual result : WRONG_NAME\n");
		}
		else if (strlen(axx[i].cardHolderData.cardHolderName) > 24) {
			printf("Actual result : NAME_LIMIT_EXCEEDED\n");
		}
		else {
			printf("Actual result : CARD_NAME_OK\n");
		}
		printf("PAN:%s\n", axx[i].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date: %s\n", axx[i].cardHolderData.cardExpirationDate);
		printf(" #########################\n");
		printf("\n");
		x = 0;
	}
		
	
	printf("SERVER_OK");

	printf("\n");
	printf("\n");
}



void saveTransaction() {
	char result[50];
	EN_accountState_t op;
	op = RUNNING;
	uint8_t res[200] = " ";
	uint8_t transaction[20] = " ";
	uint8_t DB[20] = " ";
	int s;
	s = 0;
	int lower = 1, upper = 6, count = 10;
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: saveTransactiontTest\n");
	for (int i = 0; i < 11; i++) {
		s = 0;
		for (int j = 0; j < 11; j++) {
			strcpy(DB, accountsDB[j].primaryAccountNumber);
			strcpy(transaction, axx[i].cardHolderData.primaryAccountNumber);
			if (strcmp(DB, transaction) == 0) {//0 MEANS THAT IF THEY ARE EQUAL!


				if (accountsDB[j].balance >= axx[i].terminalData.transAmount) {
					if (accountsDB[j].state == op) {
						s = 1;
						strcpy(res, "Actual result : APPROVED\n");
						//accountsDB[j].balance = accountsDB[j].balance - axx[i].terminalData.transAmount;
					}
					else {
						strcpy(res, "Actual result : DECLINED_STOLEN_CARD\n");
						s = 2;
					}

				}
				else {
					strcpy(res, "Actual result : DECLINED_INSUFFECIENT_FUND");
					s = 2;
				}
			}
		}

		if (atoi(axx[i].transactionSequenceNumber) == 0) {
			printf("No Previous Transaction sequence number was found...\n ");
		}
		else {
			printf("The Old transaction sequence number is : ");
			printf("%s\n", axx[i].transactionSequenceNumber);
			srand(time(0));
			printf("The New Transaction sequence number is: ");
			for (int j = 0; j < count; j++) {
				int num = (rand() % (upper - lower + 1)) + lower;
				sprintf(result, "%i", num);

				printf("%s", result);


			}
			printf("\n");

		}
		if (s == 0) {
			strcpy(res, "Actual result : FRAUD_CARD\n");
		}
		printf("Test Case : %d \n", i);
		printf("Input data :");
		puts(axx[i].cardHolderData.primaryAccountNumber);
		printf("******************************\n");
		puts(res);


		


	}
	printf("\n");



	printf("SERVER_OK\n");
	printf("\n");
}


void isAmountAvailableTest() {

	printf("Tester Name: SeifEldien\n");
	printf("Function Name: isAmountAvailableTest\n");
	for (int i = 0; i < 11; i++) {
		printf("Test Case : %d \n", i);
		printf("Input data :");
		printf("%i \n",(int)axx[i].terminalData.transAmount);
		if (axx[i].terminalData.transAmount == 0) {
			printf("Actual Result: TRANSACTION_AMOUNT_UNAVAILABLE \n");
		}
		else if(axx[i].terminalData.transAmount>accountsDB[i].balance){
			printf("Actual Result: LOW_BALANCE \n");
		}
		else {
			printf("Actual Result: SERVER_OK \n");

		}
	}
	printf("******************************\n");
	printf("******************************\n");

}


void isBlockedAccountTest() {
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: isBlockedAccountTest\n");
	for (int i = 0; i < 11; i++) {
		printf("Test Case : %d \n", i);
		if (accountsDB[i].state == BLOCKED) {
			printf("BLOCKED_ACCOUNT \n");
		}
		else {
			printf("SERVER_OK \n");
		}
	}
	printf("******************************\n");
	printf("******************************\n");

}


void isValidAccountTest() {
	uint8_t res[200] = " ";
	uint8_t transaction[20] = " ";
	uint8_t DB[20] = " ";
	int s;
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: isValidAccountTest\n");
	for (int i = 0; i < 11; i++) {
		s = 0;
		for (int j = 0; j < 11; j++) {
			strcpy(DB, accountsDB[j].primaryAccountNumber);
			strcpy(transaction, axx[i].cardHolderData.primaryAccountNumber);
			if (strcmp(DB, transaction) == 0) {//0 MEANS THAT IF THEY ARE EQUAL!
				strcpy(res, "Actual result : SERVER_OK\n");
				//accountsDB[j].balance = accountsDB[j].balance - axx[i].terminalData.transAmount;
				s = 1;
			}

			else {
				strcpy(res, "Actual result : ACCOUNT_NOT_FOUND\n");
				s = 2;
			}

		}

	if (s == 0) {
		strcpy(res, "Actual result : ACCOUNT_NOT_FOUND\n");
	}
	printf("Test Case : %d \n", i);
	printf("Input data :");
	puts(axx[i].cardHolderData.primaryAccountNumber);
	printf("******************************\n");
	puts(res);

	printf("%d", s);
	printf("******************************\n");
	}

	printf("******************************\n");
	printf("******************************\n");
}



void recieveTransactionDataTest() {
	char month[2], year[5],minute[4],hour[4],seconds[4],scond_1[20],s2[20];
	char y1, m1, d1, s1, h1,mi1, serial_num;
	
	EN_accountState_t op;
	op = RUNNING;
	uint8_t res[200] = " ";
	uint8_t transaction[20]=" ";
	uint8_t DB[20] =" ";
	int s;
	printf("Tester Name: SeifEldien\n");
	printf("Function Name: recieveTransactionDataTest\n");
	for (int i = 0; i <11 ; i++) {
		s = 0;
		for (int j = 0; j < 11; j++) {
			strcpy(DB , accountsDB[j].primaryAccountNumber);
			strcpy(transaction , axx[i].cardHolderData.primaryAccountNumber);
			if (strcmp(DB , transaction)==0) {//0 MEANS THAT IF THEY ARE EQUAL!

				
				if (accountsDB[j].balance >= axx[i].terminalData.transAmount) {
					if (accountsDB[j].state == op){
						s = 1;
						strcpy(res, "Actual result : APPROVED\n");
						//accountsDB[j].balance = accountsDB[j].balance - axx[i].terminalData.transAmount;
					}
					else {
						strcpy(res, "Actual result : DECLINED_STOLEN_CARD\n");
						s = 2;
					}
					
				}
				else {
					strcpy( res  ,"Actual result : DECLINED_INSUFFECIENT_FUND");
					s = 2;
				}
			}
			



		}
		if (s == 0) {
			strcpy(res , "Actual result : FRAUD_CARD\n");
		}
		printf("Test Case : %d \n", i);
		printf("Input data :");
		puts(axx[i].cardHolderData.primaryAccountNumber);
		printf("******************************\n");
		puts(res);

		printf("%d", s);
		printf("******************************\n");

		

	}
	
	
		printf("******************************\n");
		printf("******************************\n");
}


	


int servers() {
	accountsDB[0].state =  RUNNING;
	strcpy(accountsDB[0].primaryAccountNumber,  "8989374615436851");
	accountsDB[0].balance = 2000.0;
	strcpy(axx[0].terminalData.transactionDate, "01/02/2023");
	strcpy(axx[0].cardHolderData.cardHolderName, "seifooooooooooooooooooo");
	strcpy(axx[0].cardHolderData.cardExpirationDate, "06/2026");


	strcpy(axx[0].transactionSequenceNumber , "4461366623");
    strcpy(axx[0].cardHolderData.primaryAccountNumber,  "8989374615436851" );//correct PAN
	axx[0].terminalData.maxTransAmount = 3400;
	axx[0].terminalData.transAmount = 3000;// correct amount
	
	
	
	


	accountsDB[1].state = BLOCKED ;
	strcpy(accountsDB[1].primaryAccountNumber , "5807007074043875");
	accountsDB[1].balance = 100000;
	strcpy(axx[1].terminalData.transactionDate, "03/23/2026");
	strcpy(axx[1].cardHolderData.cardHolderName, "seifhatemgalalooooooooo");
	strcpy(axx[1].cardHolderData.cardExpirationDate, "05/2028");


	strcpy(axx[1].transactionSequenceNumber , "3454156453");
    strcpy(axx[1].cardHolderData.primaryAccountNumber, "5807007074043875");//correct in database
	axx[1].terminalData.maxTransAmount = 50000;
	axx[1].terminalData.transAmount = 1900;//correct , but will exit




	accountsDB[2].state = RUNNING;
	strcpy(accountsDB[2].primaryAccountNumber , "1989374615336851");
	accountsDB[2].balance = 2000.0;
	strcpy(axx[2].terminalData.transactionDate, "01/24/2025");
	strcpy(axx[2].cardHolderData.cardHolderName, "KareemMaged");
	strcpy(axx[2].cardHolderData.cardExpirationDate, "04/2027");


	strcpy(axx[2].transactionSequenceNumber , "4462365623");
    strcpy(axx[2].cardHolderData.primaryAccountNumber, "5807007076243875");//wrong not in database
	axx[2].terminalData.maxTransAmount = 1900;//
	axx[2].terminalData.transAmount = 1900;//correct , but will exit




	accountsDB[3].state = BLOCKED;
	strcpy(accountsDB[3].primaryAccountNumber , "2989374615436852");
	accountsDB[3].balance = 2000.0;
	strcpy(axx[3].terminalData.transactionDate, "03/23/2025");
	strcpy(axx[3].cardHolderData.cardHolderName, "Seif");
	strcpy(axx[3].cardHolderData.cardExpirationDate, "02/2025");


	strcpy(axx[3].transactionSequenceNumber , "0");
	strcpy(axx[3].cardHolderData.primaryAccountNumber, "5807007076043875");//correct in database
	axx[3].terminalData.maxTransAmount = 0 ;
	axx[3].terminalData.transAmount = 0;//wrong amount 


	accountsDB[4].state = RUNNING;
	strcpy(accountsDB[4].primaryAccountNumber, "3988374615436853");
	accountsDB[4].balance = 200000.0;
	strcpy(axx[4].terminalData.transactionDate, "01/30/2022");
	strcpy(axx[4].cardHolderData.cardHolderName, "Sameer");
	strcpy(axx[4].cardHolderData.cardExpirationDate, "07/2024");


	strcpy(axx[4].transactionSequenceNumber , "6461366626");
	strcpy(axx[4].cardHolderData.primaryAccountNumber, "2989374615436852");//correct in database //stolen
	axx[4].terminalData.maxTransAmount = 80000;
	axx[4].terminalData.transAmount = 60000;//correct amount


	accountsDB[5].state = RUNNING;
	strcpy(accountsDB[5].primaryAccountNumber, "4989374615436804");
	accountsDB[5].balance = 2000.0;
	strcpy(axx[5].terminalData.transactionDate, "12/25/2025");
	strcpy(axx[5].cardHolderData.cardHolderName, "SamyMOhammed");
	strcpy(axx[5].cardHolderData.cardExpirationDate, "06/2029");


	strcpy(axx[5].transactionSequenceNumber , "7461366627");
	strcpy(axx[5].cardHolderData.primaryAccountNumber, "5807004076043875");//wrong not in database
	axx[5].terminalData.maxTransAmount = 1600;
	axx[5].terminalData.transAmount = 1900;//correct amount , but will exit



	accountsDB[6].state = RUNNING;
	strcpy(accountsDB[6].primaryAccountNumber, "5989374615430855");
	accountsDB[6].balance = 2000;
	strcpy(axx[6].terminalData.transactionDate, "01/20/2023");
	strcpy(axx[6].cardHolderData.cardHolderName, "SherifAshrafhussien");
	strcpy(axx[6].cardHolderData.cardExpirationDate, "06/2026");


	strcpy(axx[6].transactionSequenceNumber , "8461366628");
	strcpy(axx[6].cardHolderData.primaryAccountNumber, "5807007076083875");//wrong not in database
	axx[6].terminalData.maxTransAmount = 1900;
	axx[6].terminalData.transAmount = 1900;//correct amount , but will exit



	accountsDB[7].state = RUNNING;
	strcpy(accountsDB[7].primaryAccountNumber, "6989374605436856");
	accountsDB[7].balance = 2000;
	strcpy(axx[7].terminalData.transactionDate, "06/30/2023");
	strcpy(axx[7].cardHolderData.cardHolderName, "Ahmed");
	strcpy(axx[7].cardHolderData.cardExpirationDate, "01/2026");


	strcpy(axx[7].transactionSequenceNumber , "9461366629");
	strcpy(axx[7].cardHolderData.primaryAccountNumber, "9989074605436859");//correct in database
	axx[7].terminalData.maxTransAmount = 1800;
	axx[7].terminalData.transAmount = 50000;//wrong amount exceeds the whole balance


	accountsDB[8].state = RUNNING;
	strcpy(accountsDB[8].primaryAccountNumber, "7989370615436857");
	accountsDB[8].balance = 3000;
	strcpy(axx[8].terminalData.transactionDate, "07/28/2026");
	strcpy(axx[8].cardHolderData.cardHolderName, "Adhamhussienhamedayman");
	strcpy(axx[8].cardHolderData.cardExpirationDate, "07/2029");


	strcpy(axx[8].transactionSequenceNumber , "0461366620");
	strcpy(axx[8].cardHolderData.primaryAccountNumber, "5807007076043878");//wrong not in database
	axx[8].terminalData.maxTransAmount = 2000;
	axx[8].terminalData.transAmount = 1900;//correct amount, but will exit


	accountsDB[9].state = RUNNING;
	strcpy(accountsDB[9].primaryAccountNumber, "8989300615436858");
	accountsDB[9].balance = 2000;
	strcpy(axx[9].terminalData.transactionDate, "01/17/2024");
	strcpy(axx[9].cardHolderData.cardHolderName, "HussienAhmedMagedmohammed");
	strcpy(axx[9].cardHolderData.cardExpirationDate, "02/2028");


	strcpy(axx[9].transactionSequenceNumber , "4431346620");
	strcpy(axx[9].cardHolderData.primaryAccountNumber, "7989370615436857");//correct in database
	axx[9].terminalData.maxTransAmount = 1900;
	axx[9].terminalData.transAmount = 1900;//correct amount but equal to the maximum transaction


	accountsDB[10].state = RUNNING;
	strcpy(accountsDB[10].primaryAccountNumber, "9989074605436859");
	accountsDB[10].balance = 5000;
	strcpy(axx[10].terminalData.transactionDate, "01/16/2024");
	strcpy(axx[10].cardHolderData.cardHolderName, "HussienAhmedMaged");
	strcpy(axx[10].cardHolderData.cardExpirationDate,"03/2027");


	strcpy(axx[10].transactionSequenceNumber , "4431346620");
	strcpy(axx[10].cardHolderData.primaryAccountNumber, "7989370615436857");//correct in database
	axx[10].terminalData.maxTransAmount = 1900;
	axx[10].terminalData.transAmount = 3500;//amount exceeded


	recieveTransactionDataTest();
	isValidAccountTest();
	isBlockedAccountTest();
	isAmountAvailableTest();
	saveTransaction();
	listSavedTransactions();
	
}