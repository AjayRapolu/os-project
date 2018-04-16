#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 
#define MAX_CUSTOMERS 25 

sem_t waiting_hall;

sem_t barber_seat;

sem_t barber_pillow;

sem_t seat_belt;

int allDone = 0;

void randwait(int secs) {
     int len = 1; 
     sleep(len);
}
void *customer(void *numbe){
	
     int num = *(int *)numbe;
     printf("Customer %d going to barber shop.\n", num);
     randwait(5);
     printf("Customer %d arrived at barber shop.\n", num); 
     sem_wait(&waiting_hall);
     printf("Customer %d entering waiting room.\n", num); 
     sem_wait(&barber_seat); 
     sem_post(&waiting_hall); 
     printf("Customer %d wakingup the barber.\n", num);
     sem_post(&barber_pillow); 
     sem_wait(&seat_belt); 
     sem_post(&barber_seat);
     printf("Customer %d leaving barber shop.\n", num);
}
void *barber(void *)

{
while (!allDone) {
    printf("The barber is sleeping\n");
    sem_wait(&barber_pillow); 
    if (!allDone)
    { 
     printf("The barber is cutting hair\n");
     randwait(3);
     printf("The barber has finished hair cut.\n"); 
     sem_post(&seat_belt);
    }
    else {
         printf("The barber is going home .\n");
    }
   }
}
int main(int argc, char *argv[])
{
    pthread_t btid;
    pthread_t tid[MAX_CUSTOMERS];
    int i, x, numCustomers, numChairs; int Number[MAX_CUSTOMERS];
    printf("Maximum number of customers can only be 25. Enter number of customers and chairs.\n");
    scanf("%d",&x);
    numCustomers = x;
    scanf("%d",&x);
    numChairs = x;
    if (numCustomers > MAX_CUSTOMERS) {
       printf("The maximum number of Customers is %d.\n", MAX_CUSTOMERS);
       system("PAUSE");   
       return 0;
    }
    printf("A solution to the sleeping barber problem using semaphores.\n");
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        Number[i] = i;
    }
    sem_init(&waiting_hall, 0, numChairs);
    sem_init(&barber_seat, 0, 1);
    sem_init(&barber_pillow, 0, 0);
    sem_init(&seat_belt, 0, 0);
    pthread_create(&btid, NULL, barber, NULL);
    for (i = 0; i < numCustomers; i++) {
        pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
    }
    for (i = 0; i < numCustomers; i++) {
        pthread_join(tid[i],NULL);
    }  
     allDone = 1;
    sem_post(&barber_pillow); 
    pthread_join(btid,NULL);
    system("PAUSE");   
    return 0;
}


