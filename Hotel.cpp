#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100
#define MAX_COMPLAINTS 100
//Structure to hold hotel room information
struct Room 
{
int roomId;
char type[50];
float price;
bool isAvailable;
};
//Structure to hold customer information
struct Customer 
{
int customerId;
char name[50];
char email[50];
};
//Structure to hold gym membership information
struct GymMembership 
{
int customerId;
int months;
float price;
};
//Structure to hold complaint information
struct Complaint 
{
int complaintId;
int customerId;
char description[200];
char status[20]; // "Open" or "Resolved"
};
//Function to initialize hotel rooms
void initializeRooms(struct Room rooms[]) 
{
for(int i = 0; i < MAX_ROOMS; i++) 
	{
    rooms[i].roomId = -1;
    strcpy(rooms[i].type, "");
    rooms[i].price = 0.0;
    rooms[i].isAvailable = true;
    }
}
//Function to add a hotel room
void addRoom(struct Room rooms[], int *numRooms) 
{
if(*numRooms >= MAX_ROOMS) 
	{
    printf("Cannot add more rooms. Maximum capacity reached.\n");
    return;
    }
struct Room newRoom;
printf("Enter Room ID: ");
scanf("%d", &newRoom.roomId);
for(int i = 0; i < *numRooms; i++) 
	{
    if(rooms[i].roomId == newRoom.roomId) 
		{
        printf("Room with this ID already exists.\n");
        return;
        }
    }
printf("Enter room type: ");
scanf(" %[^\n]s", newRoom.type);
printf("Enter room price per night: ");
scanf("%f", &newRoom.price);
newRoom.isAvailable = true;
rooms[*numRooms] = newRoom;
(*numRooms)++;
printf("Room Added Successfully.\n");
}
//Function to display hotel room details
void displayRooms(struct Room rooms[], int numRooms) 
{
printf("Hotel Room Details:\n");
printf("=========================================================\n");
printf("ID\tType\t\tPrice (per night)\tAvailability\n");
printf("=========================================================\n");
for(int i = 0; i < numRooms; i++) 
	{
    printf("%d\t%-20s\t%.2f\t\t%s\n", rooms[i].roomId, rooms[i].type, rooms[i].price, rooms[i].isAvailable ? "Available" : "Occupied");
    }
printf("=========================================================\n");
}
//Function to initialize customers
void initializeCustomers(struct Customer customers[]) 
{
for(int i = 0; i < MAX_CUSTOMERS; i++) 
	{
    customers[i].customerId = -1;
    strcpy(customers[i].name, "");
    strcpy(customers[i].email, "");
    }
}
//Function to add a customer
void addCustomer(struct Customer customers[], int *numCustomers) 
{
if(*numCustomers >= MAX_CUSTOMERS) 
	{
    printf("Cannot add more customers. Maximum capacity reached.\n");
    return;
    }
struct Customer newCustomer;
printf("Enter Sustomer ID: ");
scanf("%d", &newCustomer.customerId);
for(int i = 0; i < *numCustomers; i++) 
	{
    if(customers[i].customerId == newCustomer.customerId) 
		{
        printf("Customer with this ID already exists.\n");
        return;
        }
    }
printf("Enter Customer Name: ");
scanf(" %[^\n]s", newCustomer.name);
printf("Enter Customer Email: ");
scanf(" %[^\n]s", newCustomer.email);
customers[*numCustomers] = newCustomer;
(*numCustomers)++;
printf("Customer Added Successfully.\n");
}
//Function to display customer details
void displayCustomers(struct Customer customers[], int numCustomers) 
{
printf("Customer Details:\n");
printf("=========================================================\n");
printf("ID\tName\t\tEmail\n");
printf("=========================================================\n");
for(int i = 0; i < numCustomers; i++) 
	{
    printf("%d\t%-20s\t%s\n", customers[i].customerId, customers[i].name, customers[i].email);
    }
printf("=========================================================\n");
}
//Function to initialize complaints
void initializeComplaints(struct Complaint complaints[]) 
{
for(int i = 0; i < MAX_COMPLAINTS; i++) 
	{
    complaints[i].complaintId = -1;
    complaints[i].customerId = -1;
    strcpy(complaints[i].description, "");
    strcpy(complaints[i].status, "");
    }
}
//Function to add a complaint
void addComplaint(struct Complaint complaints[], int *numComplaints, struct Customer customers[], int numCustomers) 
{
if(*numComplaints >= MAX_COMPLAINTS) 
	{
    printf("Cannot add more complaints. Maximum capacity reached.\n");
    return;
    }
struct Complaint newComplaint;
printf("Enter Complaint ID: ");
scanf("%d", &newComplaint.complaintId);
for(int i = 0; i < *numComplaints; i++) 
	{
    if(complaints[i].complaintId == newComplaint.complaintId) 
		{
        printf("Complaint with this ID already exists.\n");
        return;
        }
    }
printf("Enter Customer ID: ");
scanf("%d", &newComplaint.customerId);
int customerIndex = -1;
for(int i = 0; i < numCustomers; i++) 
	{
    if(customers[i].customerId == newComplaint.customerId) 
		{
        customerIndex = i;
        break;
        }
    }
if(customerIndex == -1) 
	{
    printf("Customer with this ID does not exist.\n");
    return;
    }
printf("Enter complaint description: ");
scanf(" %[^\n]s", newComplaint.description);
strcpy(newComplaint.status, "Open");
complaints[*numComplaints] = newComplaint;
(*numComplaints)++;
printf("Complaint added successfully.\n");
}
//Function to resolve a complaint
void resolveComplaint(struct Complaint complaints[], int numComplaints) 
{
int complaintId;
printf("Enter Complaint ID: ");
scanf("%d", &complaintId);
int complaintIndex = -1;
for(int i = 0; i < numComplaints; i++) 
	{
    if(complaints[i].complaintId == complaintId) 
		{
        complaintIndex = i;
        break;
        }
    }
if(complaintIndex == -1) 
	{
    printf("Complaint with this ID does not exist.\n");
    return;
    }
if(strcmp(complaints[complaintIndex].status, "Resolved") == 0) 
	{
    printf("Complaint is already resolved.\n");
    } 
	else {
        strcpy(complaints[complaintIndex].status, "Resolved");
        printf("Complaint resolved successfully.\n");
    	}
}
//Function to display all complaints
void displayComplaints(struct Complaint complaints[], int numComplaints, struct Customer customers[], int numCustomers) 
{
printf("Complaint Details:\n");
printf("=========================================================\n");
printf("ID\tCustomer ID\tStatus\tDescription\n");
printf("=========================================================\n");
for(int i = 0; i < numComplaints; i++) 
	{
    int customerIndex = -1;
    for(int j = 0; j < numCustomers; j++) 
		{
        if (customers[j].customerId == complaints[i].customerId) 
			{
            customerIndex = j;
            break;
            }
        }
    printf("%d\t%d\t\t%s\t%s\n", complaints[i].complaintId, complaints[i].customerId, complaints[i].status, complaints[i].description);
    }
printf("=========================================================\n");
}
//Function to add a gym membership
void addGymMembership(struct GymMembership gymMemberships[], int *numGymMemberships, struct Customer customers[], int numCustomers) 
{
if(*numGymMemberships >= MAX_CUSTOMERS) 
	{
    printf("Cannot add more gym memberships. Maximum capacity reached.\n");
    return;
    }
struct GymMembership newGymMembership;
printf("Enter Customer ID: ");
scanf("%d", &newGymMembership.customerId);
int customerIndex = -1;
for(int i = 0; i < numCustomers; i++) 
	{
    if(customers[i].customerId == newGymMembership.customerId) 
		{
        customerIndex = i;
        break;
        }
    }
if(customerIndex == -1) 
	{
    printf("Customer with this ID does not exist.\n");
    return;
    }
printf("Enter number of months for gym membership: ");
scanf("%d", &newGymMembership.months);
printf("Enter gym membership price: ");
scanf("%f", &newGymMembership.price);
gymMemberships[*numGymMemberships] = newGymMembership;
(*numGymMemberships)++;
printf("Gym membership added successfully.\n");
}
//Function to display gym membership details
void displayGymMemberships(struct GymMembership gymMemberships[], int numGymMemberships, struct Customer customers[], int numCustomers) 
{
printf("Gym Membership Details:\n");
printf("=========================================================\n");
printf("Customer ID\tMonths\tPrice\n");
printf("=========================================================\n");
for(int i = 0; i < numGymMemberships; i++) 
	{
    int customerIndex = -1;
    for(int j=0; j < numCustomers; j++) 
		{
        if (customers[j].customerId == gymMemberships[i].customerId) 
			{
            customerIndex = j;
            break;
            }
        }
    printf("%d\t\t%d\t%.2f\n", gymMemberships[i].customerId, gymMemberships[i].months, gymMemberships[i].price);
    }
printf("=========================================================\n");
}
int main() 
{
struct Room hotelRooms[MAX_ROOMS];
int numRooms = 0;
struct Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;
struct Complaint complaints[MAX_COMPLAINTS];
int numComplaints = 0;
struct GymMembership gymMemberships[MAX_CUSTOMERS];
int numGymMemberships = 0;
int choice;
initializeRooms(hotelRooms);
initializeCustomers(customers);
initializeComplaints(complaints);
do {
    //Display menu
    printf("\nHotel Management System - Online Hotel Reservation, Gym, Complaint, CRM\n");
    printf("1. Add Hotel Room\n");
    printf("2. Display All Hotel Rooms\n");
    printf("3. Add Customer\n");
    printf("4. Display All Customers\n");
    printf("5. Add Complaint\n");
    printf("6. Resolve Complaint\n");
    printf("7. Display All Complaints\n");
    printf("8. Add Gym Membership\n");
    printf("9. Display All Gym Memberships\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
            		case 1:
                	addRoom(hotelRooms, &numRooms);
                	break;
            		case 2:
                	displayRooms(hotelRooms, numRooms);
                	break;
            		case 3:
                	addCustomer(customers, &numCustomers);
                	break;
            		case 4:
                	displayCustomers(customers, numCustomers);
                	break;
            		case 5:
                	addComplaint(complaints, &numComplaints, customers, numCustomers);
                	break;
            		case 6:
               	 	resolveComplaint(complaints, numComplaints);
                	break;
            		case 7:
               	 	displayComplaints(complaints, numComplaints, customers, numCustomers);
                	break;
            		case 8:
                	addGymMembership(gymMemberships, &numGymMemberships, customers, numCustomers);
                	break;
            		case 9:
                	displayGymMemberships(gymMemberships, numGymMemberships, customers, numCustomers);
                	break;
            		case 10:
                	printf("Exiting Hotel Management System - Online Hotel Reservation, Gym, Complaint, CRM.\n");
            	    break;
            		default:
               		printf("Invalid choice. Please try again.\n");
                	break;
        			}

    } while (choice != 10);
return 0;
}
