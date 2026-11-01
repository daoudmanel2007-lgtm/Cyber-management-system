# 🖥️ Cyber Café Management System

A console application developed as a beginner project in Computer Science. It is fully coded in C, with no external libraries required (only `stdio.h` and `string.h`).

## 🎮 Overview

Manage the computers of a cyber café from the terminal. Add computers, start a session for a customer, end it to print the bill, and check the statistics of the day. The program keeps running until you choose to exit.

## ✨ Features

- ➕ **Add computers**: register up to 20 computers, each with a unique ID
- 📋 **Display computers**: see which ones are available or occupied, with the customer name and hours
- ▶️ **Start a session**: give a computer to a customer for a number of hours
- ⏹️ **End a session**: print the bill and free the computer
- 🔍 **Search a computer**: find a computer by ID and see its status
- 📊 **Statistics**: total, available and occupied computers, plus the total revenue
- 🛡️ **Input checks**: wrong input (a letter instead of a number, an unknown ID, a duplicate ID, invalid hours) is refused without crashing
- 🔁 **Menu loop**: keep working without restarting the program

## 💰 Pricing

| Item | Value |
|------|-------|
| Maximum number of computers | 20 |
| Price per hour | 100 DA |

Bill = hours × price per hour. Example: 2 hours gives 2 × 100 = **200 DA**.

## 🕹️ Menu

| Option | Action | What it does |
|--------|--------|--------------|
| 1 | Add Computer | Asks for an ID and registers a new available computer |
| 2 | Display Computers | Lists all computers with their status |
| 3 | Start Session | Asks for the ID, the hours and the customer name |
| 4 | End Session | Prints the bill and adds the payment to the revenue |
| 5 | Search Computer | Shows if a computer exists and if it is free |
| 6 | Display Statistics | Shows the numbers and the total revenue |
| 7 | Exit | Closes the program |

## 🧠 Technologies & Concepts

- 🇨 C language (standard library only)
- 🧱 Structures (`struct Computer`) to group the data of one computer
- 🗃️ Global array of structures
- 🧩 Functions with parameters and return values
- 🔀 Conditions: `if` / `else` and `switch`
- 🔄 Loops: `for` and `do ... while`
- 🔡 Strings: `strcpy` and `scanf` with `%49[^\n]` to read a name with spaces
- 🔍 Linear search in an array

## 🗂️ Project Structure

| Component | Role |
|-----------|------|
| `struct Computer` | Stores the ID, the status, the customer name and the hours |
| `readInt()` | Reads a number safely and refuses wrong input |
| `searchComputer(id)` | Returns the position of a computer in the array, or -1 if not found |
| `addComputer()` | Adds a computer (checks the limit and duplicate IDs) |
| `displayComputers()` | Prints the list of computers |
| `startSession()` | Starts a session on a free computer |
| `endSession()` | Prints the bill and frees the computer |
| `searchAndDisplay()` | Searches a computer and prints its status |
| `displayStatistics()` | Prints the statistics and the revenue |
| `main()` | Shows the menu and calls the right function |

## 🚀 Installation & Launch

### 1️⃣ Prerequisites

Make sure a C compiler such as `gcc` is installed on your machine. No extra libraries are needed.

### 2️⃣ Clone the project

```bash
git clone https://github.com/<your-username>/<your-repo>.git
cd <your-repo>
```

### 3️⃣ Compile and run

```bash
gcc cyber.c -o cyber
./cyber
```

On Windows, run `cyber.exe` instead of `./cyber`. Replace `cyber.c` with the name of your file.

### 4️⃣ Use it 🎉

**Add a computer and start a session**

```
__________________________________
       CYBER MANAGEMENT SYSTEM
__________________________________
1. Add Computer
2. Display Computers
3. Start Session
4. End Session
5. Search Computer
6. Display Statistics
7. Exit
__________________________________
Enter your choice: 1
Enter computer ID: 10
Computer has been added.

Enter your choice: 3
Enter computer ID: 10
Enter expected hours: 2
Enter customer name: Ali
Session started successfully!
```

**End the session and see the bill**

```
Enter your choice: 4
Enter computer ID: 10

        SESSION BILL
Customer: Ali
Computer ID: 10
Hours used: 2
Price per hour: 100 DA
Total payment: 200.00 DA
Session ended successfully!
```

**Statistics**

```
Enter your choice: 6

        STATISTICS
Total computers: 1
Available computers: 1
Occupied computers: 0
Total revenue: 200.00 DA
```

## 🔮 Possible Improvements

- 💾 Save the computers and the revenue to a file so they last between runs
- 🕒 Count the real time of a session instead of asking for the hours
- 🗑️ Add options to remove or edit a computer
- 🧮 Use dynamic memory instead of a fixed limit of 20 computers
- 🖥️ Add a graphical interface
- ✅ Add unit tests

## 👨‍💻 Author

Project developed by a computer science student.
