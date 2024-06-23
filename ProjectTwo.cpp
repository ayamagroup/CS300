#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

// Struct to hold course information
struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;

    Course() {}

    Course(string number, string name, vector<string> prereqs)
        : courseNumber(number), courseName(name), prerequisites(prereqs) {}
};

// Function to load course data from a file into a hash table
unordered_map<string, Course> loadCoursesIntoHashTable(const string& filePath) {
    unordered_map<string, Course> courses;
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: File cannot be opened" << endl;
        return courses;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseName, prerequisite;
        getline(ss, courseNumber, ',');
        getline(ss, courseName, ',');
        vector<string> prerequisites;

        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        Course course(courseNumber, courseName, prerequisites);
        courses[courseNumber] = course;
    }

    file.close();

    // Validate prerequisites
    for (const auto& pair : courses) {
        const Course& course = pair.second;
        for (const string& prerequisite : course.prerequisites) {
            if (courses.find(prerequisite) == courses.end()) {
                cerr << "Error: Prerequisite " << prerequisite << " for course " << course.courseNumber << " does not exist." << endl;
            }
        }
    }

    return courses;
}

// Function to print all courses in alphanumeric order
void printAllCourses(const unordered_map<string, Course>& courses) {
    if (courses.empty()) {
        cout << "No courses loaded." << endl;
        return;
    }

    vector<string> sortedCourses;
    for (const auto& pair : courses) {
        sortedCourses.push_back(pair.first);
    }
    sort(sortedCourses.begin(), sortedCourses.end());

    for (const string& courseNumber : sortedCourses) {
        const Course& course = courses.at(courseNumber);
        cout << "Course Number: " << course.courseNumber << endl;
        cout << "Course Name: " << course.courseName << endl;
        if (!course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (const string& prerequisite : course.prerequisites) {
                cout << prerequisite << " ";
            }
            cout << endl;
        }
        else {
            cout << "No prerequisites" << endl;
        }
    }
}

// Function to search and print course information
void searchCourse(const unordered_map<string, Course>& courses, const string& courseNumber) {
    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        const Course& course = it->second;
        cout << "Course Number: " << course.courseNumber << endl;
        cout << "Course Name: " << course.courseName << endl;
        if (!course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (const string& prerequisite : course.prerequisites) {
                cout << prerequisite << " ";
            }
            cout << endl;
        }
        else {
            cout << "No prerequisites" << endl;
        }
    }
    else {
        cout << "Course not found" << endl;
    }
}

// Function to display the menu and handle user input
void menu() {
    unordered_map<string, Course> courses;
    int choice;
    string filePath;
    string courseNumber;

    do {
        cout << "Menu Options:" << endl;
        cout << "1. Load file data into the data structure" << endl;
        cout << "2. Print an alphanumerically ordered list of all the courses" << endl;
        cout << "3. Print the course title and the prerequisites for any individual course" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if input was successful
        if (cin.fail()) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter file path: ";
            cin.ignore();  // Clear the newline left by previous input
            getline(cin, filePath);  // Use getline to handle spaces in the file path
            courses = loadCoursesIntoHashTable(filePath);
            if (courses.empty()) {
                cout << "No courses loaded. Please check the file path and format." << endl;
            }
            else {
                cout << "Courses loaded successfully." << endl;
            }
            break;
        case 2:
            printAllCourses(courses);
            break;
        case 3:
            cout << "Enter course number: ";
            cin >> courseNumber;
            searchCourse(courses, courseNumber);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
}

int main() {
    menu();
    return 0;
}