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
    struct Movie movieName;
};
struct CinemaHall{
    //some add-on details
    char hallName[20];
    int hallCapacity;
    struct CinemaSchedule schedule[5];
} cinemaHall[];

int main()
{
    FILE *cinema, *hall;
    int hallNumber;
    char userType;
    printf("Type (u) if you\'re costumer and (a) if you\'re adminastrator.\n");
	scanf("%c", &userType);
		
	if(userType == 'a'){
		scanf("%d", &hallNumber);
	    cinema = fopen("cinema-hall.txt", "w+");
	    cinemaHall[hallNumber];
	    printf("Add Halls\n\n");
	    for(int i = 0; i < hallNumber; i++){
	        printf("Hall no.%d:\n", i + 1);
	        printf("Hall Name: ");
	        scanf("%s", cinemaHall[i].hallName);
	        printf("Hall Capacity: ");
			scanf("%d", &cinemaHall[i].hallCapacity);
			printf("Schedule Details\n");
	//		cinemaHall.schedule[4] = "hi";
			printf(" ");
			printf("\n");
			
			fprintf(cinema, "Hall no.%d:\n", i + 1);
	        fprintf(cinema, "Hall Name: %s\n", cinemaHall[i].hallName);
	        fprintf(cinema, "Hall Capacity: %d\n\n", cinemaHall[i].hallCapacity);
	    }
	
	    fclose(cinema);
	}else{
		cinema = fopen("cinema-hall.txt", "r+");
		
		//Hall list
		printf("Halls Lists are the following:\n");
		int i;
		for(i = 0; !feof(cinema); i++){
			fgets(cinemaHall[i].hallName, 100, cinema);
			fscanf(cinema, "%d", &cinemaHall[i].hallCapacity);
			cinemaHall[i].hallName[strlen(cinemaHall[i].hallName) - 1] = '\0';
			fscanf(cinema, "\n");
			printf("%d- %s (%d)\n", i + 1, cinemaHall[i].hallName, cinemaHall[i].hallCapacity);
		}
		
		//choos hall to open
		scanf("%d", &hallNumber);
		if(hallNumber >= 1 && hallNumber <= i){
			char hallName[100];
			sprintf(hallName, "Halls/%s.txt", cinemaHall[hallNumber - 1].hallName);
			hall = fopen(hallName, "r");
		}
		else{
			while(hallNumber < 1 || hallNumber > i){
				printf("Choose an exiting Hall:\n");
				scanf("%d", &hallNumber);
			}
		}
		
		//choosen hall schual
		printf("\n%s Plan:\n", cinemaHall[hallNumber - 1].hallName);
		printf("Day\t\tTime\t\tRemaining Capacity\n");
		int flag0 = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;
		for(i = 0; !feof(hall); i++){
			fscanf(hall, "%d|%d|%d|%d", &cinemaHall[hallNumber - 1].schedule[i].date, &cinemaHall[hallNumber - 1].schedule[i].startTime, &cinemaHall[hallNumber - 1].schedule[i].endTime, &cinemaHall[hallNumber - 1].schedule[i].remainingCapacity);
//			printf("%d\n", cinemaHall[hallNumber - 1].schedule[i].date);
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
			printf("%d\n", cinemaHall[hallNumber - 1].schedule[i].remainingCapacity);
		}
		//fseek
		//fscanf
	//	fprintf
	}
    return 0;
}
