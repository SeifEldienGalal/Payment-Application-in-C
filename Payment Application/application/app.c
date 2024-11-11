#include <stdio.h>
#include "app.h"
void appStart(void) {
	int *i=0;
	while (i != 10) {
		printf("##################################################\n");
		printf("1-Cards\n");
		printf("2-Terminal\n");
		printf("3-Server\n");
		printf("10-EXIT APPLICATION \n");
		printf("##################################################\n");
		printf("Choose one of the above options: ");
		scanf_s("%d", &i);
		if (i == 1) {
			cards();
		}
		else if (i == 2) {
			terminals();
		}
		else if (i == 3) {
			servers();
		}
		else if (i == 10) {
			printf("Exiting... :");
			break;
		}
		else {
			printf("Wrong Choice please try again :\n");
			continue;
		}


	}


	

}

int main() {

	appStart();
 }