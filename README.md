# 🦇 Super Shop Inventory Management System (C)

A **menu-driven C program** for managing a small shop’s inventory. The system supports **user authentication**, **file handling**, and full **CRUD operations** (Create, Read, Update, Delete) on shop items. It also includes a fun **ASCII Batman-style banner** displayed at startup.

---

## 📌 Features

* 🔐 **User Login System** (username & password validation)
* ➕ Add new items to inventory
* 📋 Display all items in a formatted table
* 🔍 Search items by name
* ✏️ Update item quantity and price
* ❌ Delete items from inventory
* 💾 Persistent storage using file handling (`items.txt`)
* 🛡️ Array boundary checking to prevent overflow
* 🎨 ASCII art banner at program start

---

## 🛠️ Technologies Used

* **Language:** C
* **Concepts Applied:**

  * Structures
  * Functions
  * File Handling (`fopen`, `fprintf`, `fscanf`)
  * Arrays
  * String handling (`strcmp`)
  * Loops & Conditional statements

---

## 📂 Project Structure

```
├── main.c        // Main source code
├── items.txt    // Inventory data file (auto-generated)
├── README.md    // Project documentation
```

---

## 🚀 How to Run the Program

1. **Clone the repository**

   ```bash
   git clone https://github.com/your-username/super-shop-inventory.git
   ```

2. **Compile the program**

   ```bash
   gcc main.c -o shop
   ```

3. **Run the executable**

   ```bash
   ./shop
   ```

---

## 🔑 Default Login Credentials

| Field    | Value   |
| -------- | ------- |
| Username | SOLOMAN |
| Password | 3492    |

> ⚠️ Credentials are hardcoded for learning/demo purposes.

---

## 📖 Program Menu

```
1. Add Item
2. Display Items
3. Search Item
4. Update Item
5. Delete Item
6. Exit
```

---

## 💾 File Handling Details

* Inventory is stored in **items.txt**
* Data is automatically:

  * Loaded at program start
  * Saved after add, update, delete, and exit

**File format:**

```
<number_of_items>
<item_name>
<quantity>
<price>
```

---

## 🧠 Key Learning Outcomes

* Designing modular programs using functions
* Using structures to model real-world entities
* Implementing file persistence in C
* Handling user input safely
* Implementing simple authentication logic

---

## 🖼️ Screenshots

![image alt](https://github.com/farhankhanchowdhury2003-commits/CSE-115-Project/blob/24f679db21fabe5f645ebc6fb4bbffa7fbc982bc/Screenshot%202025-12-12%20112047.png)
![image alt](https://github.com/farhankhanchowdhury2003-commits/CSE-115-Project/blob/24f679db21fabe5f645ebc6fb4bbffa7fbc982bc/Screenshot%202025-12-12%20112116.png)
![image alt](https://github.com/farhankhanchowdhury2003-commits/CSE-115-Project/blob/24f679db21fabe5f645ebc6fb4bbffa7fbc982bc/Screenshot%202025-12-12%20112215.png)

---

## 📌 Future Improvements

* Password masking
* Case-insensitive item search
* Dynamic memory allocation
* Sorting items by price or quantity
* Admin/User role separation

---

## 👤 Author

* **Name:** Farhan Khan Chowdhury
* **Project Type:** Academic / Learning Project
* **Language:** C Programming

---

## 📜 License

This project is for **educational purposes only**. You are free to modify and use it for learning.

---

⭐ *If you find this project helpful, consider giving it a star on GitHub!*
