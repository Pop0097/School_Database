#include "Classes.h"

void adminSession(School&, int);
void teacherSession(School&, int);

int main() {

    School sc(10, 5, 1, 3); //initially creates a school with two teachers and two students

    bool cancel = false, signedIn = false, programKill = false;
    string u_name = "", pass = "";
    int in = 0, userNumber = 0;

    while(!programKill) { //master program loop starts
        userNumber = -1;

        while (!signedIn && !programKill) { //signing in loop starts
            cout << "Sign in: Are you an administrator (1) or a teacher (2): (type \"0\" to kill the program)" << endl;
            cin >> in;
            if(in == 0){
               programKill = true;
            }
            if (in == 1 || in == 2) {
                cin.ignore();

                while (userNumber < 0 && !cancel) { //credential input loop starts
                    u_name = "", pass = "";
                    cout << "Enter your credentials. (Type 0 in both fields to cancel):" << endl;
                    cout << "Username: ";
                    getline(cin, u_name);
                    //cout << u_name << endl;
                    cout << "Password: ";
                    getline(cin, pass);
                    //cout << pass << endl;
                    if (u_name == "0" && pass == "0") { //if the user chooses to cancel the sign in process, they will return back to the top of the signing in loop
                        cancel = true;
                    } else {
                        //statements check the credentials depending on the chosen user type
                        if(in == 1){
                            userNumber = sc.adminLogin(u_name, pass);
                            if (userNumber != -1) {
                                signedIn = true; //variable changed so the signing in loop ends
                            }
                        }
                        else {
                            //cout << "here" << endl;
                            userNumber = sc.teacherLogin(u_name, pass);
                            if (userNumber != -1) {
                                //cout << "here1" << endl;
                                signedIn = true;
                            }
                        }
                    }
                } //credential input loop ends
            }
            cancel = false;
        } //signing in loop ends

        if(in == 1){
            adminSession(sc, userNumber);
        }
        else if (in == 2){
            //cout << "here2" << endl;
            teacherSession(sc, userNumber);
        }

        in = 0;
        u_name = "", pass = "";
        signedIn = false;
    } //master program loop ends


    cout << "Thank you for using this database" << endl;
    return 0;
}

void adminSession(School &sc, int userNumber){

    bool done = false; //this variable used when the user wants to stop updating the classes
    string confirmation = "", input = "";
    int object, choice, action;

    /*
     * (for people [administrators, teachers, and students])
     * object = 1 means teacher. object = 2 means student
     * action = 1 means view. action = 2 means edit. action = 3 means delete. action = 4 means mark student late.
     * action  = 5 means mark student absent.
     *
     * (for courses)
     * action = 1 means view. action = 2 means delete.
     * action = 3 means add student(s) to course. action = 4 means remove student from course.
     * action = 5 means change teacher of course. action = 6 means change time or classroom of a course)
     */

    while(!done) { //admin session loop starts
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "Actions for people:" << endl;
        cout << "1. View a teacher's information (Type \"1\")" << endl;
        cout << "2. View a student's information (Type \"2\")" << endl; //Instead, make the admin enter the person's name. The program will search for the person and then output the desired one. (reduces need to list so many!!!)
        cout << "3. Edit a teacher's information (Type \"3\")" << endl;
        cout << "4. Edit a student's information (Type \"4\")" << endl; //Instead, make the admin enter the person's name. The program will search for the person and then output the desired one. (reduces need to list so many!!!)
        cout << "5. Create a teacher (Type \"5\")" << endl;
        cout << "6. Create a student (Type \"6\")" << endl;
        cout << "7. Delete a teacher (Type \"7\")" << endl;
        cout << "8. Delete a student (Type \"8\")" << endl;
        cout << "9. Create an administrator (Type \"9\")" << endl;
        cout << "10. Delete an administrator (Type \"10\")" << endl;
        cout << "11. Mark a student late (Type \"11\")" << endl;
        cout << "12. Mark a student absent (Type \"12\")" << endl;
        cout << "Actions for your account: " << endl;
        cout << "13. View your account information (Type \"13\")" << endl;
        cout << "14. Edit your account information (Type \"14\")" << endl;
        cout << "Actions for courses:" << endl;
        cout << "15. View a course's information (Type \"15\")" << endl;
        cout << "16. Edit a course's information (Type \"16\")" << endl;
        cout << "17. Create a course (Type \"17\")" << endl;
        cout << "18. Delete a course (Type \"18\")" << endl;
        cout << endl;
        cout << "Log out (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;

        input = "";

        if (choice == 1) {
            cout << "Which teacher would you like to view? (search for teacher by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 1;
            action = 1;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if (choice == 2) {
            cout << "Which student would you like to view? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 1;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if (choice == 3) {
            cout << "Which teacher would you like to edit? (search for teacher by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 1;
            action = 2;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if (choice == 4) {
            cout << "Which student would you like to edit? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 2;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if (choice == 5) {
            cout << "Creating a teacher:" << endl;
            object = 1;
            sc.createPerson(object);
        } else if (choice == 6) {
            cout << "Creating a student:" << endl;
            object = 2;
            sc.createPerson(object);
        } else if (choice == 7) {
            cout << "Which teacher would you like to delete? (search for teacher by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 1;
            action = 3;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if (choice == 8) {
            cout << "Which student would you like to delete? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 3;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if(choice == 9){
            cout << "Creating an administrator:" << endl;
            object = 3;
            sc.createPerson(object);
        } else if(choice == 10){ //delete admin
            cout << "Which administrator would you like to edit? (search for teacher by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 3;
            action = 3;
            sc.findPeople(input, object, action, userNumber);
        } else if(choice == 11){ //mark student late
            cout << "Which student would you like to mark late? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 4;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if(choice == 12){ //mark student absent
            cout << "Which student would you like to mark absent? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 5;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if(choice == 13){ //view account
            object = 3;
            sc.displayPerson(userNumber, object);
        } else if (choice == 14){ //edit account
            object = 3;
            sc.editPerson(userNumber, object);
        } else if(choice == 15){ //view course
            cout << "Which course would you like to view? (search for course by entering course code)" << endl;
            cin.ignore();
            getline(cin, input);
            action = 1;
            sc.findCourse(input, action);
        } else if(choice == 16){ //edit course
            choice = 0;
            cout << "Would you like to:\n1. Add student(s) to a course (Type \"1\") \n2. Remove a student from a course (Type \"2\") \n3. Change the teacher of a course (Type \"3\") \n4. Change the time/room of a course (Type \"4\")" << endl;
            cin >> choice;
            cout << "Which course would you like to edit? (search for course by entering course code)" << endl;
            cin.ignore();
            getline(cin, input);
            if(choice == 1){ //add student(s) to course
                action = 3;
            } else if(choice == 2){ //remove a student
                action = 4;
            } else if(choice == 3){ //change the teacher
                action = 5;
            } else { //change the time/room of the course
                action = 6;
            }
            sc.findCourse(input, action);
        } else if(choice == 17){ //create course
            cout << "Creating a course:" << endl;
            sc.createCourse();
        } else if(choice == 18){ //delete course
            cout << "Which course would you like to delete? (search for course by entering course code)" << endl;
            cin.ignore();
            getline(cin, input);
            action = 2;
            sc.findCourse(input, action);
        } else { //log out
            done = true;
        }
    } //admin session loop ends
}

void teacherSession(School &sc, int userNumber){
    bool done = false; //this variable used when the user wants to stop updating the classes
    string confirmation = "", input = "";
    int object, choice, action;

    while(!done){ //teacher session loop starts
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "1. View a student's information (Type \"1\")" << endl; //Instead, make the admin enter the person's name. The program will search for the person and then output the desired one. (reduces need to list so many!!!)
        cout << "2. Mark a student late (Type \"2\")" << endl;
        cout << "3. Mark a student absent (Type \"3\")" << endl;
        cout << "4. View your course's information (Type \"4\")" << endl;
        cout << "5. View your account information (Type \"5\")" << endl;
        cout << "6. Edit your account information (Type \"6\")" << endl;
        cout << endl;
        cout << "Log out (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;

        input = "";

        if (choice == 1) { //view a student's information
            cout << "Which student would you like to view? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 1;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if(choice == 2){ //mark student late
            cout << "Which student would you like to mark late? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 4;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if(choice == 3){ //mark student absent
            cout << "Which student would you like to mark absent? (search for student by entering their name)" << endl;
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 5;
            userNumber = sc.findPeople(input, object, action, userNumber);
        } else if(choice == 4){ //view course information
            //add code later
        } else if(choice == 5){ //display user account information
            object = 1;
            sc.displayPerson(userNumber, object);
        } else if(choice == 6){ //edit user account information
            object = 1;
            sc.editPerson(userNumber, object);
        } else { //log out
            done = true;
        }
    } //admin session loop ends
}