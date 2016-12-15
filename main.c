#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "racingarena.h"


void* raceCar(void* carPosition){

	int* carPos = ((int *)carPosition);
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

void* userCar(void* carPosition){
	int *carPos=((int *)carPosition);
	int i;
	for(i=0; i<42; i++){
		char c = fgetc(stdin);
		if (c == '\n'){
			++*(int*)carPos;
		}
	}
	free(carPos);
	pthread_exit(NULL);
}//end userCar

void drawLane(int position, int lane){
	ffor (i=0;i<position;i++){
		printf("~");
	}
	printf("|->");
	for (i = (position+3); i<(40+3); i++){
		printf(" ");
	}
	printf("# Lane %d #\n",lane);
	return;

}//end drawLane

void* draw(void* carNum){
	int* carPos = (int*)carNum;
	int notWinner;
	for (int i = 0; i < 5; i++)//check if the positon is above 40
		int laneWinner = i+1;
		if (carPos[i] >= 40) {
			notWinner = 1;
			break;
		}
	 while(!notWinner){
		
		system("clear"); //clear screen
		printf("Welcome to CISC220 Racing Arena \nHit Enter to move forward");
		
		for (int i = 0; i < 5; i++){
			
			int lane = i+1;
			pos = position[i];
			drawLane(pos,lane);
		
			printf("Player in lane %d WINS\n", laneWinner);
	}
		usleep(20*1000);}
	
	pthread_exit(NULL);

}// end draw
int main(){
	int rc;

	pthread_t AIThreads[5];
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
