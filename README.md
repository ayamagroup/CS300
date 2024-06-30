# CS300 Project

This repository contains the work for my CS300 course at ABC University.

## Project Description

This project is a console application for managing course information for academic advisors. It includes functionalities to load course data from a file, print an alphanumerically ordered list of all courses, and display course information along with prerequisites.

## How to Use

1. Clone this repository:
    ```sh
    git clone https://github.com/YourUsername/CS300_Project.git
    ```

2. Navigate to the project directory:
    ```sh
    cd CS300_Project
    ```

3. Compile the code:
    ```sh
    g++ -o CS300_Project ProjectTwo.cpp
    ```

4. Run the application:
    ```sh
    ./CS300_Project
    ```
   Interact with the application by following the menu options provided.

## Interface Description

The interface is a console-based menu that prompts the user to enter their choice by selecting a number corresponding to the desired action. The menu options are displayed each time the user completes an action or enters an invalid choice. The user interacts with the program by typing their choice and providing additional input when prompted.

## Menu Options

1. Load file data into the data structure
   - Enter the file path when prompted. You can use either a relative path (e.g., `CS 300 ABCU_Advising_Program_Input.csv` if the file is in the same directory) or an absolute path (e.g., `C:\Users\YourUsername\Documents\CS 300 ABCU_Advising_Program_Input.csv`).

2. Print an alphanumerically ordered list of all the courses
   - This option prints a list of all the courses loaded into the data structure, sorted in alphanumeric order.

3. Print the course title and the prerequisites for any individual course
   - Enter the course number when prompted to display the course title and its prerequisites.

9. Exit
   - Exits the program.

## Reflection

### What was the problem you were solving in the projects for this course?
The main problem was to create an efficient and user-friendly console application to manage and retrieve course information for academic advisors.

### How did you approach the problem? Consider why data structures are important to understand.
I approached the problem by using various data structures to store and manage the course information, including hash tables for efficient retrieval. Understanding data structures is crucial because they determine the efficiency of data storage, retrieval, and manipulation.

### How did you overcome any roadblocks you encountered while going through the activities or project?
I overcame roadblocks by breaking down the problem into smaller tasks, referring to documentation, and using debugging techniques to identify and fix issues.

### How has your work on this project expanded your approach to designing software and developing programs?
This project has taught me to consider the efficiency and scalability of my code. It also reinforced the importance of writing modular and maintainable code.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
I have learned to write clearer and more organized code, with comments and documentation to make it easier to understand and maintain. I also focused on making the code adaptable to future changes or enhancements.

## Run-time Analysis Reference

### Operation Analysis

| Operation                   | Vector   | Hash Table | Binary Search Tree  |
|-----------------------------|----------|------------|---------------------|
| Load Data                   | O(n)     | O(n)       | O(n log n)          |
| Search for a Course         | O(n)     | O(1)       | O(log n)            |
| Print All Courses           | O(n log n) (for sorting) | O(n log n) (for sorting) | O(n)         |
| Memory Usage                | O(n)     | O(n)       | O(n)                |
| Insert Course               | O(1)     | O(1)       | O(log n)            |
| Validate Prerequisites      | O(n^2)   | O(n)       | O(n log n)          |

### Advantages and Disadvantages

**Vector**
- Advantages:
  - Simple to implement and use.
  - Provides dynamic resizing.
- Disadvantages:
  - Linear time complexity for search operations.
  - Inefficient for large datasets due to O(n) search time.

**Hash Table**
- Advantages:
  - Constant time complexity for search operations.
  - Efficient memory usage.
- Disadvantages:
  - Collisions can affect performance.
  - Does not maintain order of elements.

**Binary Search Tree**
- Advantages:
  - Maintains order of elements.
  - Logarithmic time complexity for search and insert operations.
- Disadvantages:
  - Can degrade to linear time complexity if not balanced.
  - More complex to implement than a vector or hash table.

### Recommendation
Based on the Big O analysis and the requirements of the program, I recommend using a Hash Table for storing course information. The constant time complexity for search operations and efficient memory usage make it the best choice for quickly retrieving course data and validating prerequisites.
