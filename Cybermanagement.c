#include <stdio.h>
#include <string.h>
#define MAX_COMPUTERS 20
#define PRICE_PER_HOUR 100

struct Computer {
    int id;
    int occupied;
    char customer[50];
    int hours;
};

struct Computer computers[MAX_COMPUTERS];
int computerCount = 0;
double totalRevenue = 0;
int readInt(int *value) {
    if (scanf("%d", value) != 1) {
        while (getchar() != '\n');   
        return 0;
    }
    return 1;
}

int searchComputer(int id) {
    for (int i = 0; i < computerCount; i++) {
        if (computers[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addComputer() {
    int id;

    if (computerCount >= MAX_COMPUTERS) {
        printf("Maximum number of computers reached, cannot add more.\n");
        return;
    }
    printf("Enter computer ID: ");
    if (!readInt(&id)) {
        printf("Invalid ID!\n");
        return;
    }
    if (searchComputer(id) != -1) {
        printf("This ID already exists!\n");
        return;
    }
    computers[computerCount].id = id;
    computers[computerCount].occupied = 0;
    computers[computerCount].hours = 0;
    strcpy(computers[computerCount].customer, "None");
    computerCount++;
    printf("Computer has been added.\n");
}

void displayComputers() {
    if (computerCount == 0) {
        printf("No computers registered.\n");
        return;
    }
    printf("\n       COMPUTER LIST       \n");
    for (int i = 0; i < computerCount; i++) {
        printf("Computer ID: %d\n", computers[i].id);

        if (computers[i].occupied == 0) {
            printf("Status: Available\n");
        } else {
            printf("Status: Occupied\n");
            printf("Customer: %s\n", computers[i].customer);
            printf("Hours: %d\n", computers[i].hours);
        }
        printf("-------------------------\n");
    }
}

void startSession() {
    int id;
    int index;
    int hours;

    printf("Enter computer ID: ");
    if (!readInt(&id)) {
        printf("Invalid ID!\n");
        return;
    }

    index = searchComputer(id);
    if (index == -1) {
        printf("Computer not found!\n");
        return;
    }
    if (computers[index].occupied == 1) {
        printf("This computer is already occupied!\n");
        return;
    }
    printf("Enter expected hours: ");
    if (!readInt(&hours) || hours <= 0) {
        printf("Invalid number of hours!\n");
        return;
    }
    printf("Enter customer name: ");
    scanf(" %49[^\n]", computers[index].customer);
    computers[index].hours = hours;
    computers[index].occupied = 1;
    printf("Session started successfully!\n");
}

void endSession() {
    int id;
    int index;
    double payment;
    printf("Enter computer ID: ");
    if (!readInt(&id)) {
        printf("Invalid ID!\n");
        return;
    }
    index = searchComputer(id);
    if (index == -1) {
        printf("Computer not found!\n");
        return;
    }
    if (computers[index].occupied == 0) {
        printf("This computer is not occupied!\n");
        return;
    }
    payment = computers[index].hours * PRICE_PER_HOUR;
    printf("\n        SESSION BILL          \n");
    printf("Customer: %s\n", computers[index].customer);
    printf("Computer ID: %d\n", computers[index].id);
    printf("Hours used: %d\n", computers[index].hours);
    printf("Price per hour: %d DA\n", PRICE_PER_HOUR);
    printf("Total payment: %.2f DA\n", payment);
    totalRevenue += payment;
    computers[index].occupied = 0;
    computers[index].hours = 0;
    strcpy(computers[index].customer, "None");

    printf("Session ended successfully!\n");
}

void searchAndDisplay() {
    int id;
    int index;

    printf("Enter computer ID: ");
    if (!readInt(&id)) {
        printf("Invalid ID!\n");
        return;
    }
    index = searchComputer(id);
    if (index == -1) {
        printf("Computer not found!\n");
    } else {
        printf("Computer %d found!\n", id);
        printf("Status: %s\n", computers[index].occupied ? "Occupied" : "Available");
    }
}
void displayStatistics() {
    int available = 0;
    int occupied = 0;
    for (int i = 0; i < computerCount; i++) {
        if (computers[i].occupied == 1) {
            occupied++;
        } else {
            available++;
        }
    }
    printf("\n        STATISTICS          \n");
    printf("Total computers: %d\n", computerCount);
    printf("Available computers: %d\n", available);
    printf("Occupied computers: %d\n", occupied);
    printf("Total revenue: %.2f DA\n", totalRevenue);
}

int main() {
    int choice;

    do {
        printf("\n__________________________________\n");
        printf("       CYBER MANAGEMENT SYSTEM     \n");
        printf("__________________________________\n");
        printf("1. Add Computer\n");
        printf("2. Display Computers\n");
        printf("3. Start Session\n");
        printf("4. End Session\n");
        printf("5. Search Computer\n");
        printf("6. Display Statistics\n");
        printf("7. Exit\n");
        printf("__________________________________\n");
        printf("Enter your choice: ");
        if (!readInt(&choice)) {
            printf("Invalid input! Please enter a number.\n");
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1: addComputer();      break;
            case 2: displayComputers(); break;
            case 3: startSession();     break;
            case 4: endSession();       break;
            case 5: searchAndDisplay(); break;
            case 6: displayStatistics(); break;
            case 7: printf("\nThank you for using the system!\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 7);
    return 0;
}