#include <stdio.h>
#include <string.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

typedef struct {

	char make[MAX_STR];  //string
	char modle[MAX_STR];  //string
	char color[MAX_STR];   //string
	int year;    //int
	int mileage;    //int

	// ADD MEMBER VARIABLES

} VehicleType;

typedef struct {
	//CustomerType
	VehicleType vehicle_array[MAX_VEHICLES];//
	char firstname[MAX_STR];    // string
	char lastname[MAX_STR];    // string
	int vehicles;  // number of vehice

// ADD MEMBER VARIABLES

} CustomerType;

void print_vehicle(VehicleType *v) {
	printf("%d  %s  %s  %s  %d km\n",v->year,v->make,v->modle,v->color,v->mileage);

}

void print_customer(CustomerType *c) {

	printf("\nCustomer %s %s %d Vehicle(s)\n",c->firstname,c->lastname,c->vehicles);
	for(int i=0; i<c->vehicles;i++){
		print_vehicle(&(c->vehicle_array[i]));
	}

}

int add_vehicle(CustomerType *customer, VehicleType *vehicle) {
	if (customer->vehicles < MAX_VEHICLES ){
			customer-> vehicle_array[customer->vehicles]= *vehicle;
			customer->vehicles+=1;
			return 0;

	}
	else{
		return -1;

	}
}

CustomerType create_customer(char* fname, char* lname) {
	CustomerType c;
	strcpy(c.firstname, fname);
	strcpy(c.lastname, lname);
	c.vehicles = 0;
	return c;

}

VehicleType create_vehicle(int year, char* make, char* model, char* colour,
                             int mileage){
	VehicleType v;
	strcpy(v.make, make);
	strcpy(v.modle, model);
	strcpy(v.color, colour);
	v.year = year;
	v.mileage = mileage;
	return v;

}


int main() {

    CustomerType customers[MAX_CUSTOMERS];
    customers[0]= create_customer("Muarice","Mooney");
 		VehicleType v= create_vehicle(2007,"Ford","Fiesta","Red",100000);
	  add_vehicle(&(customers[0]),&(v));//(customers[0].vehicle_array[0]));
		customers[1]=create_customer("Abigail","Atwood");
		//customers[1].vehicle_array[0]
		v = create_vehicle(2016,"Subaru","Forester","Green",40000);
		add_vehicle(&(customers[1]),&(v));
		customers[2]=create_customer("Brook","Banding");
		//customers[2].vehicle_array[0]
		v = create_vehicle(2018,"Honda","Accord","White",5000);
		add_vehicle(&(customers[2]),&(v));
		//customers[2].vehicles+=1;
		//customers[2].vehicle_array[1]
		v = create_vehicle(1972,"Volkswagen","Beetle","White",5000);
		add_vehicle(&(customers[2]),&(v));
		customers[3]= create_customer("Ethan","Esser");
		//customers[3].vehicle_array[0]
		v =create_vehicle(2010,"Toyota","Camry","Black",50000);
		add_vehicle(&(customers[3]),&(v));
		customers[4]=create_customer("Eve","Engram");
		//customers[4].vehicle_array[0]
		v =create_vehicle(2013,"Toyota","Corolla","Green",80000);
		add_vehicle(&(customers[4]),&(v));
		//customers[4].vehicles+=1;
		//customers[4].vehicle_array[1]
		v =create_vehicle(2015,"Toyota","Rav4","Gold",20000);
		add_vehicle(&(customers[4]),&(v));
		//customers[4].vehicles+=1;
		//customers[4].vehicle_array[2]
		v=create_vehicle(2017,"Toyata","Prius","Bule",10000);
		add_vehicle(&(customers[4]),&(v));

		customers[5]=create_customer("Victor","Vanvalkenburg");
		//customers[5].vehicle_array[0]
		v =create_vehicle(2012,"GM","Envoy","Purple",60000);
		add_vehicle(&(customers[5]),&(v));
		//customers[5].vehicles+=1;
		//customers[5].vehicle_array[1]
		v =create_vehicle(2016,"GM","Escalade","Black",40000);
		add_vehicle(&(customers[5]),&(v));
		//customers[5].vehicles+=1;
		//customers[5].vehicle_array[2]
		v =create_vehicle(2015,"GM","Malibu","Red",20000);
		add_vehicle(&(customers[5]),&(v));
		//customers[5].vehicles+=1;
		//customers[5].vehicle_array[3]
		v =create_vehicle(2012,"GM","Trailblazer","Orange",90000);
		add_vehicle(&(customers[5]),&(v));
		for (int i=0;i<6;i++){
			print_customer(&(customers[i]));}
		//print_customer(&(customers[0]));
		//print_customer(&(customers[1]));
		//print_customer(&(customers[2]));
		//print_customer(&(customers[3]));
		//print_customer(&(customers[4]));
		//print_customer(&(customers[5]));
    return 0;
}
