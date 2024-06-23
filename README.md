# CS300 Project

This repository contains the work for my CS300 course at ABC University.

## Project Description

This project is a console application for managing course information for academic advisors. It includes functionalities to load course data from a file, print an alphanumerically ordered list of all courses, and display course information along with prerequisites.

## How to Use

1. Clone this repository:
   ```sh
   git clone https://github.com/YourUsername/CS300_Project.git
   
2. Navigate to the project directory:
   ```sh   
   cd CS300_Project

4. Compile the code:
   ```sh   
   g++ -o CS300_Project ProjectTwo.cpp

5. Run the application:
   ```sh   
   ./CS300_Project
   Interact with the application by following the menu options provided.

# Interface Description

The interface is a console-based menu that prompts the user to enter their choice by selecting a number corresponding to the desired action. The menu options are displayed each time the user completes an action or enters an invalid choice. The user interacts with the program by typing their choice and providing additional input when prompted.

# Menu Options

```sh
1. Load file data into the data structure
   - Enter the file path when prompted. You can use either a relative path (e.g., `CS 300 ABCU_Advising_Program_Input.csv` if the file is in the same directory) or an absolute path (e.g., `C:\Users\YourUsername\Documents\CS 300 ABCU_Advising_Program_Input.csv`).

2. Print an alphanumerically ordered list of all the courses
   - This option prints a list of all the courses loaded into the data structure, sorted in alphanumeric order.

3. Print the course title and the prerequisites for any individual course
   - Enter the course number when prompted to display the course title and its prerequisites.

9. Exit
   - Exits the program.

