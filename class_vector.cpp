#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student {
    private: 
        int id;
        string name;
        float gpa;
    
    public:
        void setData(int i, string n, float g) {
            id = i;
            name = n;
            gpa = g;


        }
        void displayData() {
            cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;

        }
        int getID() const {
            return id;
        }
        string getName() const {
            return name;
        }
        float getGPA() const {
            return gpa;
        }
        void setName(string& newName) {
            name = newName;
        }
        void setID(int& newID) {
            id = newID;
        }
        void setGPA(float& newGPA) {
            gpa = newGPA;
        }
};

void saveToFile(const vector<Student>& students, const string& filename) {
    //---Create an output file stream to write to the given file---
    ofstream outFile(filename);

    //Check if the file opened successfully---
    if (outFile.is_open()) {
        //---Loop through each student in the vecto---
        for (const Student& s : students) {
            //Write the student's ID, Name, and GPA with spaces
            outFile << s.getID() << " " << s.getName() << " " << s.getGPA() << endl;

        }
        outFile.close();
        cout << "Data saved successfully" << endl;
    }
    else {
        cout << "Error opening file for saving." << endl;
    }
}


void loadFromFile(vector<Student>& students, const string& filename) {
    //Create an input file stream to read from the given file
    ifstream inFile(filename);

    //Check if the file opened successfully
    if (inFile.is_open()) {
        //Clear the current student list before loading new data
        students.clear();

        int id;
        string name;
        float gpa;
        
        //Read ID, name, and GPA from the file line by line
        while (inFile >> id >> name >> gpa) {
            Student temp; //Create new object temp

            //Set data for the values read from the file
            temp.setData(id, name, gpa);

            //Add the student to vector
            students.push_back(temp);

            
        }

        inFile.close();
        cout << "Data loaded successfully";


    }
    else {
        //Show error if file is not opened
        cout << "Error opening file for loading";
    }
}

void modifyStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID: ";
    cin >> id;
    
    bool found = false;
    for(Student& s : students) {
        if (s.getID() == id) {
            found = true;
            s.displayData();

            //Ask which field to modify
            cout << "Which field would you like to modify?" << endl;
            cout << "1. ID" << endl;
            cout << "2. Name" << endl;
            cout << "3. GPA" << endl;
            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                int newID;
                cout << "Enter new ID: ";
                cin >> newID;
                s.setID(newID);
                cout << "ID successfully updated" << endl;

            }
            if (choice == 2) {
                string newName;
                cout << "Enter new Name: ";
                cin >> newName;
                s.setName(newName);
                cout << "Name successfully updated" << endl;
                
            }
            if (choice == 3) {
                int newGPA;
                cout << "Enter new GPA: ";
                cin >> newGPA;
                s.setID(newGPA);
                cout << "GPA successfully updated" << endl;
                
            }                        
        }
        else {
            cout << "Student ID not found" << endl;
        }
    }

}


void searchByID(vector<Student>& students) {
        int id;
        cout << "Enter ID: " << endl;
        cin >> id;
        bool found = false;
        for (Student& s : students) {
            if (s.getID() == id) {
                found = true;
                s.displayData();
                break;
            }
        }
        if (!found) { 
            cout << "Student ID not found" << endl;
        }

    }

void deleteByID(vector<Student>& students) {
    int id;
    cout << "Enter ID: " << endl;
    cin >> id;
    bool found = false;
    size_t index = 0;
    for (Student& s : students) {
        if (s.getID() == id) {
            students.erase(students.begin() + index);
            found = true;
            cout << "Student ID successfully removed" << endl;
            break;
            
        }
        index++;
    }
    if (!found) {
        cout << "Student with ID: " << id << " is not found" << endl;
    }
}



int main() {
    int choice;
    vector<Student> students; //Vector list of all students
    do {
        cout << "---Menu---" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Save to file" << endl;
        cout << "4. Load from file" << endl;
        cout << "5. Modify existing student data" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            //adding a student
            int id;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;

            Student temp;
            temp.setData(id, name, gpa);
            students.push_back(temp);
        }
        else if (choice == 2) {
            for (Student& s : students) {
                s.displayData();
            }
        }
        else if (choice == 3) {
            saveToFile(students, "students.txt");
        }
        else if (choice == 4) {
            loadFromFile(students, "students.txt");

        }
        else if (choice == 5) {
            modifyStudent(students); 

        }

    } while (choice != 6);


    return 0;
}

