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
    FILE *cinema;
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
		printf("choose Hall\n");
		int i;
		for(i = 0; !feof(cinema);i++){
			fgets(cinemaHall[i].hallName, 100, cinema);
			fscanf(cinema, "%d", &cinemaHall[i].hallCapacity);
			fscanf(cinema, "\n");
			printf("%d- %s", i + 1, cinemaHall[i].hallName);
		}
		scanf("%d", &hallNumber);
		fseek
		fscanf
		fprintf
	}
    return 0;
}
