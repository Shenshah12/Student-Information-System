#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main();
void show_data(int searchkey);             // shows data
void get_data(int i);                      // to obtain data
void search_student(int searchkey);        // To Search the data.
void add_student();                        // to add a record of a new student.
void edit_student(int idnumber);           // to edit existing record.  
int display_data();                        // To Display the Student Record.


int sn;                                   // Declaration of Varaible for Total No. of Students

struct student    //this is to add sttudent attributes
{
    int Roll;                //  Field for Student's Roll no.
    string Name;               // Declaration of string for Students Name
    string Papa_name;           // Declaration of string for Fathers Name          
    string cell;            // Declaration of string For Students Cell no.
    string dob;             // Declaration of string  for Birth Dates of Students.
    string address;         // Declaration of string for Students Address.
};
student rec[50];        // Use Array to Save the Record of Students upto 50.

int main()
{

    int choose;          // Declaration of varaible for the choice of Task User wants to perform.
    int idnumber;        // Declaration of variable for ID NO. of the Students.

    int search;       // Declaration of variable used in search operation.
    system("color E4");

    system("CLS");

    cout << "\n\n========================================================================================================\n";
    cout << "\n\n--------------------------------------  Assalam-ul-Alakium  ---------------------------------------------\n";
    cout << "\n----------------------------------  WELCOME- Student Record System  -------------------------------------\n";
    cout << "\n\n========================================================================================================\n";


    cout << "\n  Enter The Total Number of Student(s)- Max 50: ";  // Here User has to enter the total No. of Students HE/SHE wants to Add in Record. 
    cin >> sn;
    cout << endl << "  =======================MENU========================\n";

    for (int fp = sn; fp > 0; fp = fp - 1)
    {
        cout << "\n\t\tList of Options." << endl;       // Pragram Asks the User which Operation he Wants to perform.
        cout << "\t\t========================" << endl;
        cout << "\t\t1- Add Student Record.\n";                       // Choice to Add Student Record 
        cout << "\t\t2- Edit Student(s) Record.\n";                   // Edit the Record or Update the record or Delete any Entry
        cout << "\t\t3- Search Student Record.\n";                    // Search any Student record from the Total record.
        cout << "\t\t4- Display Record." << endl;                     // Display the whole Record Stored in File
        cout << "\t\t5- Close/Exist Program" << endl;                 // Choice to Close the Program
        cout << "\t\t=========================" << endl;

        cout << "\n  Choose the Operation you want to Perform : ";             // User User Enter the Number of Choice he Wants to perform.
        cin >> choose;

        switch (choose)
        {
        case 1:                                                          // Press one to add the Student Record.

            add_student();                                               // Progran Enters to the add_students Function


            break;
        case 2:                                                          // Press 2 to Edit Data.      
            if (rec[1].Roll == 0)
            {
                cout << "\n    No, Record Exist to Edit.\n     Kindly Enter the Record.\n     ==== THANKYOU ====\n" << endl;           // When there is No such Record Exist.
                system("pause");                                         // Aaystem has been Paused And Asks the User To type any KEY to contiue.
                main();
            }
            else
            {

                cout << endl;
                cout << " ------------------------------------------------------------------------------------------" << endl;
                cout << " ------------------------------- Student Record Table -------------------------------------" << endl;

                cout << " ------------------------------------------------------------------------------------------" << endl;

                cout << "  ID   " << "Roll    " << " Name        " << "   Father\tCell no.      " << "DOB           " << "  Address\n\n";
                cout << "  ------------------------------------------------------------------------------------------" << endl;

                for (int i = 1; i <= sn; i++)
                {
                    show_data(i);                                       // Program Enters to show data to data on console
                }

                cout << "------------------------------------------------------------------------------------------\n" << endl;
                cout << "   Enter the ID NO. you want to Edit : ";      // Give the ID NO. User wants to Edit.

                cin >> idnumber;

                if (idnumber > sn || idnumber < 1)
                {
                    cout << "\n  You have Entered a Invalid ID NO.\n  Please Enter Correct ID NO. to Edit." << endl;         // User Give the  ID NO. which not Exist. 
                    cout << "\n\n    Please Enter the Correct ID. No. = ";
                    cin >> idnumber;
                    edit_student(idnumber);

                }
                else                                                  // If the ID No. Exist the Function Enters to edit_student Funtion to Edit Data.
                {
                    edit_student(idnumber);
                }
            }
            break;

        case 3:                                                    // Press the 3 to Seacrh yhe Student Record 
            if (rec[1].Roll == 0)
            {
                cout << "  \n    No, Record Exist to Edit.\n     Kindly Enter the Record.\n     ==== THANKYOU ====\n" << endl;     // If there is no Record Exist then Program asks user to Furst ADD data.
                system("pause");                                   // Aaystem has been Paused And Asks the User To type any KEY to contiue.


                main();
            }
            else                           // If the Data Exist the Program Asks user to Roll no. of Student
            {

                cout << "\n  Enter Student Roll No.   : ";    // Here Entered the Roll No. of the Student , User wants to Search.
                cin >> search;
                cout << endl << " ---------------------------------------------------------------------------------------\n\n";
                search_student(search);       // The program Enters to the search_Student Function to Search Data.
                cout << " ---------------------------------------------------------------------------------------\n\n";
                system("pause");                 // Aaystem has been Paused And Asks the User To type any KEY to contiue.
                system("CLS");
                main();

            }

            break;

        case 4:             // Press 4 to Display  the Student Record
            display_data();
            break;

        case 5:             // Press 5 to Go out of the Program


            cout << "\n --------------------------------------------------------------------------------------------------------------------\n";
            cout << endl << "\n ===============================   Program is Closed Sucessfully.  ================================ \n";
            cout << endl << " =================================   THANK YOU FOR COMING.   ================================== \n";
            cout << endl << " =================================     HAVE A GOOD DAY.      ==================================\n";

            cout << "\n\n --------------------------------------------------------------------------------------------------------------------\n\n";
            return 0;
            break;
        default:                                           // When you Entered a Wrong Option.
            cout << "\n  Entered an Invalid Option." << endl;
            system("pause");                               // Aaystem has been Paused And Asks the User To type any KEY to contiue.
            main();
        }
    }
    return 0;
}


void get_data(int i)
{
    cout << "\n  Enter student roll number in  format(1XXX) : ";    // Entering of Roll No. of Dtudents.
    cin >> rec[i].Roll;
    cin.ignore();
    cout << "  Enter Student Name : ";                             // Entering of Students Names.
    getline(cin, rec[i].Name);
    cout << "  Enter Student's Father Name : ";                   // Entering of Students Father's Names.
    getline(cin, rec[i].Papa_name);
    cout << "  Enter Student's Cell Phone Number : ";             // Entering of Cell No. of Students.
    cin >> rec[i].cell;
    cin.ignore();
    cout << "  Enter Student's Date of Birth(dd/mm/yyyy) : ";     // Entering of Students Date of Birth.
    cin >> rec[i].dob;
    cin.ignore();
    cout << "  Enter Student's Address : ";                      // Write the Student's Address.
    getline(cin, rec[i].address);

}

void show_data(int searchkey)
{
    int i = searchkey;
    cout << "  " << i << "    ";                            // Displays the ID NO. of the Student.
    cout << rec[i].Roll << "   ";                         // Displays the Roll NO. of the Student.
    cout << rec[i].Name << "    ";                          // Displays the Name of the Student.
    cout << rec[i].Papa_name << "\t ";                          // Displays the Father's Name of the Student. 
    cout << rec[i].cell << "   ";                           // Displays the Cell NO. of the Student.
    cout << rec[i].dob << "    ";                           // Displays the Date of Birth. of the Student.
    cout << rec[i].address << "\n\n";                       // Displays the Address. of the Student.

}

void search_student(int search)
{

    for (int i = 1; i <= sn; i++)
    {
        if (rec[i].Roll == search)
        {
            cout << "  ID   " << "Roll   " << "  Name          " << " Father\t    Cell no.      " << "DOB          " << " Address\n\n";
            show_data(i);

        }
    }
}

void add_student()
{
    ofstream Student_Report;

    Student_Report.open("Student_Report.txt");
    for (int i = 1; i <= sn; i++)
    {
        get_data(i);
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------Student Record Table---------------------------------------" << endl;

    cout << "--------------------------------------------------------------------------------------------\n" << endl;
    cout << "  ID   " << "Roll   " << "Name         " << "   Father\t   Cell no.      " << "DOB          " << "Address\n\n";
    cout << "--------------------------------------------------------------------------------------------\n" << endl;
    Student_Report << endl;
    Student_Report << "-------------------------------------------------------------------------------------------" << endl;
    Student_Report << "--------------------------------Student Record Table---------------------------------------" << endl;

    Student_Report << "-------------------------------------------------------------------------------------------\n" << endl;
    Student_Report << "  ID   " << "Roll   " << "  Name      " << "   Father\t   Cell no.      " << " DOB          " << " Address\n\n";
    Student_Report << "--------------------------------------------------------------------------------------------\n" << endl;

    for (int i = 1; i <= sn; i++)
    {
        show_data(i);
        Student_Report << "  " << i << "    ";                   // Save the ID No. of Students in File
        Student_Report << rec[i].Roll << "   ";                // Save the Roll No. of Students in File
        Student_Report << rec[i].Name << "     ";                // Save the Students Name in File
        Student_Report << rec[i].Papa_name << "\t ";                 // Save the Students Father's Name in File
        Student_Report << rec[i].cell << "   ";                  // Save the Students CELL NO. in File
        Student_Report << rec[i].dob << "    ";                  // Save the Student's Birth Date in File
        Student_Report << rec[i].address << "\n\n";              // Save the Students Address in File

    }
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------FINISH-----------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    Student_Report << "--------------------------------------------------------------------------------------------" << endl;
    Student_Report << "---------------------------------------FINISH-----------------------------------------------" << endl;
    Student_Report << "--------------------------------------------------------------------------------------------" << endl;

    Student_Report.close();          // Close the file to stop the Data loss.
    system("pause");                 // Aaystem has been Paused And Asks the User To type any KEY to contiue.

    main();
}

void edit_student(int idnumber)
{
    for (int i = 1; i <= sn; i++)       // Using For loop
    {
        if (idnumber == i)
        {
            ofstream Student_Report;                                      // Declaration of ofstream
            Student_Report.open("Student_Report.txt");                    //  Opening of the file Student_Report.
            cout << "\n  Existed information about this record.\n\n";    //  Showin of Existed Information in File.
            cout << "----------------------------------------------------------------------------------------" << endl;
            cout << "  ID   " << "Roll   " << "  Name        " << "  Father\t   Cell no.      " << "DOB          " << "  Address\n\n";
            cout << "----------------------------------------------------------------------------------------\n" << endl;
            show_data(i);
            cout << "\n\n  Enter new data for above shown record.\n\n";        // Program Asks the User to Enter the New Data.
            get_data(i);
            cout << "\n\n    === Record updated successfully. ===" << endl;    // New Record is UPDATED and Saved Sucessfully.
            cout << "\n\n----------------------------------------------------------------------------------------\n" << endl;
            cout << "  ID   " << "Roll    " << "  Name        " << "  Father\t  Cell no.      " << "DOB           " << "  Address\n\n";
            cout << "----------------------------------------------------------------------------------------\n" << endl;
            Student_Report << endl;
            Student_Report << "  ----------------------------------------------------------------------------------------" << endl;
            Student_Report << "  -------------------------------Student Record Table-------------------------------------" << endl;

            Student_Report << "  ----------------------------------------------------------------------------------------" << endl;

            Student_Report << "  ID   " << "Roll    " << "Name            " << "Father\t    Cell no.      " << "DOB           " << "Address\n\n";
            Student_Report << "  ----------------------------------------------------------------------------------------" << endl;

            for (int i = 1; i <= sn; i++)
            {
                show_data(i);     //funtion is called with index value to show data.

                Student_Report << "  " << i << "    ";                  // Save the ID No. of Students in File
                Student_Report << rec[i].Roll << "   ";               // Save the Roll No. of Students in File
                Student_Report << rec[i].Name << "     ";               // Save the Students Name in File
                Student_Report << rec[i].Papa_name << "\t  ";               // Save the Students Father's Name in File
                Student_Report << rec[i].cell << "   ";                 // Save the Students CELL NO. in File
                Student_Report << rec[i].dob << "    ";                 // Save the Student's Birth Date in File
                Student_Report << rec[i].address << "\n\n";             // Save the Students Address in File

            }
            cout << "-------------------------------------------------------------------------------------------" << endl;
            cout << "---------------------------------------FINISH----------------------------------------------" << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;
            Student_Report << "----------------------------------------------------------------------------------------" << endl;
            Student_Report << "-------------------------------------FINISH---------------------------------------------" << endl;
            Student_Report << "----------------------------------------------------------------------------------------" << endl;
            Student_Report.close();
            system("pause");          // Aaystem has been Paused And Asks the User To type any KEY to contiue.
            main();                   //Return to main function.
        }
    }
}
int display_data()
{
    fstream Student_Report("Student_Report.txt", ios::in);// Function Decleration and stream.
    string intake; // String variable has been Declared
    if (Student_Report.is_open()) // If loop is used and file is Opened
    {
        cout << endl;

        while (getline(Student_Report, intake)) // Using While loop which reads the files contents
        {
            cout << intake << endl;  // Data from the console has been Displayed
        }

        Student_Report.close(); // Closing of the file to stop the loss of Data .
    }
    else                        // If there is No such Data Exists
        cout << "\n  ----- There is no such record Exist.----- \n"
        << "  ----- Kindly Enter the Record in file.-----\n "
        << "  == -- == THANK YOU == -- ==  \n";
    system("pause");        // System has been Paused And Asks the User To type any KEY to contiue.


    return main();
}

