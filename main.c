#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "racingarena.h"


void* raceCar(void* carNum){

	int* carPos = malloc(sizeof(int));
	*carPos = 0;
	int position = 0;

	while (position != 40){
		randNum = (rand() % 100)*1000; //*1000 b/c usleep operates in microseconds
		usleep(randNum);
		position++;
		*carPos = position; //++ increment would not increment carPos directly
	}
	free(carPos);
	pthread_exit(NULL);
}//end raceCar


void* draw(void* carNum){


	while (winState){


	}

}//end draw


int main(){

	printf("Welcome to CISC220 Racing Arena \nHit Enter to move forward");

	pthread_t AIThreads[4];
	for (int i = 2; i <=5; i++ ){

		rc = pthread_create(AIThreads + i, NULL, raceCar, (void*) i); //returns 0 on success
		if (rc){ //if not zero
					printf("ERROR; return code from pthread_create() is %d\n", rc);
					exit(-1);
				}
	}
	/* wait for all threads to complete */
	for (int i = 0; i <= 5; i++){
		pthread_join(AIThreads[i], NULL);
	}
	pthread_exit(NULL);

}//end main
