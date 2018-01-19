
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define BUFFER_SIZE 10

typedef struct{
	int type; // O = chicken, 	1=Fries
	int amount; 
	int unit; // O=piece, 1 = gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	if((first + 1) % BUFFER_SIZE == last){
		printf("the conveyor belt is full, cannot produce more");
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first+1) % BUFFER_SIZE;
	printf("Produce\n");
	printf("first = %d\tlast = %d\n", first, last);
	
}
item* consume(){
	item *i = malloc(sizeof(item));
	if(first == last){
		printf("There are nothing to comsume\n");
		return NULL;
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	printf("consume\n");
	printf("first = %d\tlast = %d\n", first, last);
	return i;
}

int main(){
	item *i1 = malloc(sizeof(item));
	item *i2 = malloc(sizeof(item));
	i1->type = 0;
	i1->amount = 10;
	i1->unit = 0;
	
	i2->type = 1;
	i2->amount = 100;
	i2->unit = 1;
	produce(i1);	produce(i2);
	item *i3 = consume();
}
