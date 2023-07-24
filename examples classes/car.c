#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>

struct Automobile {
	char brand[20];
	char model[20];
	int year;
	int weight;
	int fuelTankCapacity;
	int accelerationSpeed;
	int maxSpeed;
	int passagerCapacity;
	int isDieselDriven;
};

void setBrand(struct Automobile *car, char *brand){
	memcpy(car->brand, brand, 20);
}

void setModel(struct Automobile *car, char *model){
	memcpy(car->model, model, 20);
}

void setYear(struct Automobile *car, int year) {
	car->year = year;
}

void setWeight(struct Automobile *car, int weight) {
	car->weight = weight;
}

void setFuelTankCapacity(struct Automobile *car, int capacity) {
	car->fuelTankCapacity = capacity;
}

void setAccelerationSpeed(struct Automobile *car, int speed) {
	car->accelerationSpeed = speed;
}

void setmaxSpeed(struct Automobile *car, int maxSpeed) {
	car->maxSpeed = maxSpeed;
}

void setPassagerCapacity(struct Automobile *car, int passagerCapacity) {
	car->passagerCapacity = passagerCapacity;
}

void setisDieselDriven(struct Automobile *car, int isDieselDriven) {
	car->isDieselDriven = isDieselDriven;
}

void enterBrand(struct Automobile *car){
	printf(" > enter brand: ");
	scanf("%s", car->brand);
}

void enterModel(struct Automobile *car){
	printf(" > enter model: ");
	scanf("%s", car->model);
}

void enterYear(struct Automobile *car){
	printf(" > enter year: ");
	scanf("%d", &car->year);
}

void enterWeight(struct Automobile *car){
	printf(" > enter weight: ");
	scanf("%d", &car->weight);
}

void enterFuelTankCapacity(struct Automobile *car){
	printf(" > enter fuel tank Capacity: ");
	scanf("%d", &car->fuelTankCapacity);
}

void enterAccelerationSpeed(struct Automobile *car){
	printf(" > enter acceleration speed: ");
	scanf("%d", &car->accelerationSpeed);
}

void entermaxSpeed(struct Automobile *car){
	printf(" > enter max speed: ");
	scanf("%d", &car->maxSpeed);
}

void enterPassagerCapacity(struct Automobile *car){
	printf(" > enter passager capacity: ");
	scanf("%d", &car->passagerCapacity);
}

void enterisDieselDriven(struct Automobile *car){
	printf(" > enter if car is diesel: ");
	scanf("%d", &car->isDieselDriven);
}

void enterCar(struct Automobile *car) {
	printf("\nenter car\n");
	enterBrand(car);
	enterModel(car);
	enterYear(car);
	enterWeight(car);
	enterFuelTankCapacity(car);
	enterAccelerationSpeed(car);
	entermaxSpeed(car);
	enterPassagerCapacity(car);
	enterisDieselDriven(car);
}

void printCar(struct Automobile *car) {
	printf(
		" <%s %s %d> \n weight: %d\n fuel tank capacity: %d\n acceleration: %d \n max speed: %d\n passager capacity: %d\n diesel: %s",
		car->brand, 
		car->model, 
		car->year,
		car->weight, 
		car->fuelTankCapacity, 
		car->accelerationSpeed,
		car->maxSpeed, 
		car->passagerCapacity,
		(car->isDieselDriven) ? "true" : "false"
	);
}

int main() {
	struct Automobile *car = (struct Automobile*)malloc(sizeof(struct Automobile));	
	setBrand(car, "Toyota");
	setModel(car, "Camry");
	setYear(car, 2014);
	setWeight(car, 2100);
	setFuelTankCapacity(car, 40);
	setAccelerationSpeed(car, 30);
	setmaxSpeed(car, 220);
	setPassagerCapacity(car, 4);
	setisDieselDriven(car, -1);
	printCar(car);

	printf(":");
	enterCar(car);
	printCar(car);
	
	return 0;
}
