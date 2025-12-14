#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===================== FUNCTION PROTOTYPES =====================
void drawEars();
void drawFace();
void drawBody();
void drawBellyAndLegs();
void drawTail();

void userLogin();
void addItem();
void displayItems();
void searchItem();
void updateItem();
void deleteItem();
void loadItems();
void saveItems();
int arrayBoundCheck(int currentSize, int maxSize);

//Structure of shop items
struct Item
{
    char name[50];
    int quantity;
    float price;
};

// Global Variables
struct Item items[100]; // Inventory array
int itemCount = 0;      // Number of items
char username[20] = "SOLOMAN";
char password[20] = "3492";

// ===================== BATMAN DRAWING =====================

void drawEars() {
    printf("          _==/          i     i          \\==_\n");
    printf("        /XX/            |\\\\___//|            \\XX\\\n");
}

void drawFace() {
    printf("      /XXXX\\            |MMMMMMM|            /XXXX\\\n");
    printf("     |XXXXXX\\_         _|MMMMMMM|_         _/XXXXXX|\n");
}

void drawBody() {
    printf("    XXXXXXXXXXXxxxxxxxXXXXXXXXXXXXXxxxxxxxXXXXXXXXXXX\n");
    printf("    |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|\n");
}

void drawBellyAndLegs() {
    printf("    |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|\n");
    printf("     \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/\n");
}

void drawTail() {
    printf("       \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/\n");
    printf("         \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/\n");
    printf("           \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/\n");
    printf("             \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMM/\n");
    printf("                \\MMMMMMMMMMMMMMMMMMMMMMM/\n\n");
}




// ===================== MAIN PROGRAM =====================

int main()
{
    drawEars();
    drawFace();
    drawBody();
    drawBellyAndLegs();
    drawTail();

    int choice;

    userLogin(); // Authenticate user
    loadItems(); // Load data from file

    do
    {
        printf("\nSuper Shop Inventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                saveItems(); // Save data before exiting
                printf("Thank you for using the Super Shop Inventory Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 6);

    return 0;
}


// ===================== FUNCTION IMPLEMENTATIONS =====================

// Function for user login
void userLogin()
{
    char inputUsername[20], inputPassword[20];
    int attempts = 3;

    while (attempts > 0)
    {
        printf("Enter username: ");
        scanf("%s", inputUsername);
        printf("Enter password: ");
        scanf("%s", inputPassword);

        if (strcmp(inputUsername, username) == 0 && strcmp(inputPassword, password) == 0)
        {
            printf("Login successful!\n\n");
            return;
        }
        else
        {
            attempts--;
            printf("Incorrect username or password. Attempts left: %d\n", attempts);
        }
    }

    printf("Too many failed attempts. Exiting program.\n");
    exit(0);
}

// Function to add an item
void addItem()
{
    if (!arrayBoundCheck(itemCount, 100))
    {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf(" %[^\n]", items[itemCount].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[itemCount].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[itemCount].price);

    itemCount++;
    printf("Item added successfully!\n");
    saveItems(); // Save updated data to file
}

// Function to display all items
void displayItems()
{
    if (itemCount == 0)
    {
        printf("No items available.\n");
        return;
    }

    printf("\nItems in the inventory:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-10s | %-8s |\n", "Item Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("| %-20s | %-10d | %-8.2f |\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("-------------------------------------------------\n");
}

// Function to search for an item
void searchItem()
{
    char searchName[50];
    printf("Enter the name of the item to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Item found: %s, Quantity: %d, Price: %.2f\n",
                   items[i].name, items[i].quantity, items[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to update an item's quantity or price
void updateItem()
{
    char itemName[50];
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            saveItems();
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to delete an item
void deleteItem()
{
    char itemName[50];
    printf("Enter the name of the item to delete: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            saveItems();
            return;
        }
    }
    printf("Item not found.\n");
}

// Load items from file
void loadItems()
{
    FILE *file = fopen("items.txt", "r");
    if (file == NULL) {
        printf("No existing inventory found. Starting fresh.\n");
        return;
    }

    fscanf(file, "%d", &itemCount);
    for (int i = 0; i < itemCount; i++) {
        fscanf(file, " %[^\n] %d %f", items[i].name, &items[i].quantity, &items[i].price);
    }
    fclose(file);
    printf("Inventory loaded successfully.\n");
}

// Save items to file
void saveItems()
{
    FILE *file = fopen("items.txt", "w");
    if (file == NULL) {
        printf("Error saving inventory.\n");
        return;
    }

    fprintf(file, "%d\n", itemCount);
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s\n%d\n%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully.\n");
}

// Check array bounds
int arrayBoundCheck(int currentSize, int maxSize) {
    return currentSize < maxSize;
}

