#include <stdio.h>
#include <stdlib.h>
struct Movie{
    int movieDuration;
    char content[1000];
    char summary[120];
    char actors[20][20];
};
struct CinemaSchedule{
    int date;
    int startTime;
    int endTime;
    int remainingCapacity;
    char  movieName[30];
    struct Movie movieDet;
};
struct CinemaHall{
    //some add-on details
    char hallName[20];
    int hallCapacity;
    struct CinemaSchedule schedule[];
} cinemaHall[];

void reserveday(int reserveDate){
	int i = 0;
	printf("\nTime\t\tMovie\n");
	while(cinemaHall[1].schedule[i].date <= reserveDate){
		if(cinemaHall[1].schedule[i].date == reserveDate){
			printf("%d - %d\t\t%s\n", cinemaHall[1].schedule[i].startTime, cinemaHall[1].schedule[i].endTime, cinemaHall[1].schedule[i].movieName);
		}
		i++;
	}
}
void reservetime(int reserveTime, int reserveDate){
	int i = 0;
	while(cinemaHall[1].schedule[i].date <= reserveDate){
		if(cinemaHall[1].schedule[i].startTime == reserveTime){
			printf("\"%s\" reserved sucssesfully!\n", cinemaHall[1].schedule[i].movieName);
			cinemaHall[1].schedule[i].remainingCapacity--;
//			printf("%d", cinemaHall[1].schedule[i].remainingCapacity);
		}
		i++;
	}
}
int main()
{
    FILE *cinema, *hall;
    int hallNumber;
    char userType;

	printf("Type (u) if you\'re costumer and (a) if you\'re adminastrator.\n");
	scanf("%c", &userType);
	
	cinema = fopen("cinema-hall.txt", "r");
	//Hall list
	printf("Halls Lists are the following:\n");
	int hallNums;
	for(int i = 0; !feof(cinema); i++){
		fgets(cinemaHall[i].hallName, 100, cinema);
		fscanf(cinema, "%d", &cinemaHall[i].hallCapacity);
		cinemaHall[i].hallName[strlen(cinemaHall[i].hallName) - 1] = '\0';
		fscanf(cinema, "\n");
		printf("%d- %s (%d)\n", i + 1, cinemaHall[i].hallName, cinemaHall[i].hallCapacity);
		hallNums = i + 1;
	}
	fclose(cinema);
	//choos hall to open
	scanf("%d", &hallNumber);
	char hallName[100];
	if(hallNumber >= 1 && hallNumber <= hallNums){
		sprintf(hallName, "Halls/%s.txt", cinemaHall[hallNumber - 1].hallName);
		hall = fopen(hallName, "r");
	}
	else{
		while(hallNumber < 1 || hallNumber > hallNums){
			printf("Choose an exiting Hall:\n");
			scanf("%d", &hallNumber);
		}
	}
	int scheduleNums;
	for(int i = 0; !feof(hall); i++){
		scheduleNums = i + 1;
		fscanf(hall, "%d|%d|%d|%d|", &cinemaHall[hallNumber - 1].schedule[i].date, &cinemaHall[hallNumber - 1].schedule[i].startTime, &cinemaHall[hallNumber - 1].schedule[i].endTime, &cinemaHall[hallNumber - 1].schedule[i].remainingCapacity);
		fgets(cinemaHall[hallNumber - 1].schedule[i].movieName,100, hall);
		cinemaHall[hallNumber - 1].schedule[i].movieName[strlen(cinemaHall[hallNumber - 1].schedule[i].movieName) - 1] = '\0';
	}
	fclose(hall);
	if(userType == 'a'){
		hall = fopen(hallName, "a");
		scanf("%d", &cinemaHall[1].schedule[scheduleNums].date);
		scanf("%d", &cinemaHall[1].schedule[scheduleNums].startTime);
		scanf("%d",	&cinemaHall[1].schedule[scheduleNums].endTime);
		scanf("%d", &cinemaHall[1].schedule[scheduleNums].remainingCapacity);
		scanf("%s", cinemaHall[1].schedule[scheduleNums].movieName);
		fprintf(hall, "\n%d|%d|%d|%d|", cinemaHall[1].schedule[scheduleNums].date, cinemaHall[1].schedule[scheduleNums].startTime, cinemaHall[1].schedule[scheduleNums].endTime, cinemaHall[1].schedule[scheduleNums].remainingCapacity);
	    fprintf(hall, "%s", cinemaHall[1].schedule[scheduleNums].movieName);
	    fclose(hall);	
	}else{
		//choosen hall schual
		printf("\n%s Plan:\n", cinemaHall[hallNumber - 1].hallName);
		printf("Day\t\tTime\t\tRemaining\t\tMovie\n");
		int flag0 = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;
		for(int i = 0; i < scheduleNums; i++){
			if(cinemaHall[hallNumber - 1].schedule[i].date == 0 && flag0 == 0){
				printf("Shanbe\t\t");
				flag0 = 1;
			}
			else if(cinemaHall[hallNumber - 1].schedule[i].date == 1 && flag1 == 0){
				printf("\n1 Shanbe\t");
				flag1 = 1;
			}
			else if(cinemaHall[hallNumber - 1].schedule[i].date == 2 && flag2 == 0){
				printf("\n2 Shanbe\t");
				flag2 = 1;
			}
			else if(cinemaHall[hallNumber - 1].schedule[i].date == 3 && flag3 == 0){
				printf("\n3 Shanbe\t");
				flag3 = 1;
			}
			else if(cinemaHall[hallNumber - 1].schedule[i].date == 4 && flag4 == 0){
				printf("\n4 Shanbe\t");
				flag4 = 1;
			}
			else if(cinemaHall[hallNumber - 1].schedule[i].date == 5 && flag5 == 0){
				printf("\n5 Shanbe\t");
				flag5 = 1;
			}
			else if(cinemaHall[hallNumber - 1].schedule[i].date == 6 && flag6 == 0){
				printf("\nJome\t\t");
				flag6 = 1;
			}else{
				printf("\t\t");
			}
			printf("%d - %d\t\t", cinemaHall[hallNumber - 1].schedule[i].startTime, cinemaHall[hallNumber - 1].schedule[i].endTime);
			printf("%d\t\t\t", cinemaHall[hallNumber - 1].schedule[i].remainingCapacity);
			printf("%s\n", cinemaHall[hallNumber - 1].schedule[i].movieName);
//			printf("%d",i);
		}
//		fclose(hall);
		
		//Reservation
		printf("\nChoose Day to Reserve\n");
		char reserveDay[10];
		int reserveTime;
		scanf("%s", reserveDay);
		int reserveDayInt;
		switch(reserveDay[0]){
			case 's':
			case 'S':
				reserveDayInt = 0;
				reserveday(reserveDayInt);
				break;
			case '1':
				reserveDayInt = 1;
				reserveday(reserveDayInt);
				break;
			case '2':
				reserveDayInt = 2;
				reserveday(reserveDayInt);
				break;
			case '3':
				reserveDayInt = 3;
				reserveday(reserveDayInt);
				break;
			case '4':
				reserveDayInt = 4;
				reserveday(reserveDayInt);
				break;
			case '5':
				reserveDayInt = 5;
				reserveday(reserveDayInt);
				break;
			case 'j':
			case 'J':
				reserveDayInt = 6;
				reserveday(reserveDayInt);
				break;
		}
		printf("\nChoose Time to Reserve\n");
		scanf("%d", &reserveTime);
		reservetime(reserveTime, reserveDayInt);
		//print movie name and reserve detail
		//choose to reserve or see movie detail
		//if detail then to reserve
		hall = fopen(hallName, "w");
		for(int i = 0; i < scheduleNums; ++i){
			fprintf(hall, "%d|%d|%d|%d|", cinemaHall[1].schedule[i].date, cinemaHall[1].schedule[i].startTime, cinemaHall[1].schedule[i].endTime, cinemaHall[1].schedule[i].remainingCapacity);
	        fprintf(hall, "%s", cinemaHall[1].schedule[i].movieName);
	        if(i < scheduleNums - 1){
	        	fprintf(hall, "\n");
	        }
//	        fprintf(cinema, "Hall Capacity: %d\n\n", cinemaHall[i].hallCapacity);
	    }
	    fclose(hall);
		
		
//		printf("%d", reserveTime);
		//fseek
		//fscanf
	//	fprintf
	}
    return 0;
}
