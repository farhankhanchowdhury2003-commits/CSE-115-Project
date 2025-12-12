🏪 Super Shop Inventory Management System

A simple C-based inventory management system that allows users to add, update, delete, search, and display shop items.
The program includes user authentication, file saving/loading, and a fun ASCII Batman drawing shown on startup.

📌 Features
🔐 User Login

Requires correct username & password (SOLOMAN / 3492)

Allows 3 attempts before exiting

📦 Inventory Functions

Add Item – name, quantity, price

Display All Items – formatted table

Search Item – find by name

Update Item – change quantity & price

Delete Item – remove from inventory

Auto-Save – items store in items.txt

💾 File Handling

Inventory data persists between program runs using a text file.

🎨 ASCII Art

Draws a Batman-style ASCII character when the program starts.

🛠️ How to Compile and Run
Compile
gcc inventory.c -o inventory

Run
./inventory

📁 File Structure
/project-folder
│── inventory.c       # Main program
│── items.txt         # Auto-generated inventory storage
│── README.md         # You are here

📄 Sample items.txt Format

The program automatically writes/reads in this structure:

3
Shampoo
10
120.50
Bread
20
35.00
Milk
12
70.00

🧠 How It Works
⭐ Data Structure Used
struct Item {
    char name[50];
    int quantity;
    float price;
};

⭐ Maximum Items: 100
⭐ Storage

Items are stored in:

struct Item items[100];

🧪 Example Run
Enter username: SOLOMAN
Enter password: 3492
Login successful!

Super Shop Inventory Management System
1. Add Item
2. Display Items
3. Search Item
4. Update Item
5. Delete Item
6. Exit
Choose an option:

🤝 Contributions

Feel free to fork this repo and improve the project. Pull requests are welcome!

📜 License

This project is open-source and free to use.
