#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void calculate_total_marks(float lab_performance[][15], float lab_report[][15], float midterm[], float cea[], 
                        float final_term[], float total_marks[], float weights[], int num_students, int num_labs);
void assign_grades(float total_marks[], string grades[], int num_students);
void save_to_csv(string name[], string roll_no[], float lab_performance[][15], float lab_report[][15], float midterm[],
                float cea[],float final_term[], float total_marks[], string grades[], int num_students, int num_labs);
// Function to display menu of cafeteria                         
void displayMenu(){
    cout<<"Cafeteria Menu:\n";
    cout<<"1. Coffee - 250 Rupees\n";
    cout<<"2. Tea - 100 Rupees\n";
    cout<<"3. Sandwich - 150 Rupees\n";
    cout<<"4. Pizza Slice - 200 Rupees\n";
    cout<<"5. Beef Burger - 800 Rupees\n";
    cout<<"6. Zinger Burger - 400 Rupees\n";
    cout<<"7. Roll Paratha - 200 Rupees\n";
    cout<<"8. Fries - 100 Rupees\n";
    cout<<"9. Wrap - 250 Rupees\n";
    cout<<"10. Icecream - 300 Rupees\n";
}
int main() {
	while(true){
	cout<<"----------------------------------------------------------------------";
	 cout << endl << "\t       WELCOME TO UNIVERSITY MANAGEMENT SYSTEM " << endl ;
	 cout<<"----------------------------------------------------------------------"<<endl<<endl<<endl;
	 cout << "Press 1 to use Teacher Portal" << endl;
     cout << "Press 2 to enter University Cafe" << endl;
     cout << "Press 3 to close University Management System" << endl;
     int choice_1;
     cout << "\nPlease select an option to continue further: ";
     cin>>choice_1; 
     if (choice_1 == 1){
	 
     
    int choice;
    string total_classes[15];
    int num_classes = 0;
    int max_labs=15;
    while (1) {
        cout << endl << "============= WELCOME TO TEACHER PORTAL =============" << endl << endl;
        cout << "Press 1 to add classes" << endl;
        cout << "Press 2 to enter marks" << endl;
        cout << "Press 3 to close the Teacher Portal" << endl;
        cout << "\nPlease select an option to continue further: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Please enter how many classes you want to make: ";
            cin >> num_classes;
            cin.ignore();
            for (int i = 0; i < num_classes; i++) {
                cout << "Enter name of class "<<i+1<<": ";
                getline(cin, total_classes[i]);
            }
            cout << "Classes added successfully!" << endl;
        }
        else if (choice == 2) {
            if (num_classes == 0) {
                cout << endl << "No classes available. Please add classes first!" << endl;
                continue;
            }
            else {
			
                cout << "============= Select Class =============" << endl;
                for (int i = 0; i < num_classes; i++) {
                    cout << "Press " << i + 1 << " for " << total_classes[i] << endl;
                }
                int class_choice;    
                cout << "Enter your choice: ";
                cin >> class_choice;
                cin.ignore();
                if (class_choice < 1 || class_choice > num_classes) {
                    cout << "Error: Check your class selection!" << endl;
                    continue;
                }
                else {
                    cout << "Selected class: " << total_classes[class_choice - 1] << endl;
                    int num_students;
                   
				    cout<<endl << "Enter number of students in this class: ";
                    cin >> num_students;

                    string name[num_students];
                    string roll_no[num_students];
                    float lab_performance[num_students][15] = {0};
                    float lab_report[num_students][15] = {0};
                    float midterm[num_students] = {0};
                    float cea[num_students] = {0};
                    float final_term[num_students] = {0};
                    float total_marks[num_students] = {0};
                    string grades[num_students];

                    for (int i = 0; i < num_students; i++) {
                        cin.ignore();
                        cout << "Enter name of student " << i + 1 << ": ";
                        getline(cin, name[i]);
                        cout << "Enter rollno of student " << i + 1 << ": ";
                        getline(cin, roll_no[i]);}

                       cout<<endl << "------------- Select Assessment Type -------------" << endl;
                       cout << "Press 1 for Lab Performances" << endl;
                       cout << "Press 2 for Lab Reports" << endl;
                       cout << "Press 3 for Midterm" << endl;
                       cout << "Press 4 for CEA" << endl;
                       cout << "Press 5 for Final Term" << endl;
                       cout << "Press 0 to Finish Entering Marks" << endl;

int assessment_choice;
while (true) {
    cout << "\nEnter your choice: ";
    cin >> assessment_choice;

    if (assessment_choice == 0) {
        cout << "Marks entered successfully!" << endl;
        break;
    }
 int num_labs;
    switch (assessment_choice) {
        case 1: {
        	 cout << "How many lab performances/reports you want to record? ";
              cin >> num_labs;
            cout << "You chose Lab Performances." << endl;
            for (int i = 0; i < num_students; i++) {
                cout << "Enter marks for Lab Performances (OUT OF 15) of " << name[i]<<"."<<endl;
                for (int j = 0; j < num_labs; j++) {
                    cout<< "Lab Performance " << j + 1 << ": ";
                    cin >> lab_performance[i][j];
                }
            }
            break;
        }
        case 2: {
            cout << "You chose Lab Reports." << endl;
            for (int i = 0; i < num_students; i++) {
                cout << "Enter marks for Lab Reports (OUT OF 15) of " << name[i]<<"."<<endl;
                for (int j = 0; j < num_labs; j++) {
                    cout<< "Lab Report " << j + 1 << ": ";
                    cin >> lab_report[i][j];
                }
            }
            break;
        }
        case 3: {
            cout << "You chose Midterm." << endl;
            for (int i = 0; i < num_students; i++) {
                cout << "Enter marks for Midterm (OUT OF 50) of " << name[i]<<": ";
                cin >> midterm[i];
            }
            break;
        }
        case 4: {
            cout << "You chose CEA." << endl;
            for (int i = 0; i < num_students; i++) {
                cout << "Enter marks for CEA (OUT OF 15) of " << name[i]<<": ";
                cin >> cea[i];
            }
            break;
        }
        case 5: {
            cout << "You chose Final Term." << endl;
            for (int i = 0; i < num_students; i++) {
                cout << "Enter marks for Final Term (OUT OF 50) of " << name[i]<<": ";
                cin >> final_term[i];
            }
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}


                    // Ask for weightages
                    cout << "\nEnter Weightage for Assessments (e.g; 0.2 for 20%) !" << endl;
                    float weights[5];
                    cout << "Weightage for Lab Performances (Max 10%): ";
                    cin >> weights[0];
                    cout << "Weightage for Lab Reports (Max 10%): ";
                    cin >> weights[1];
                    cout << "Weightage for Midterm (Max 25%): ";
                    cin >> weights[2];
                    cout << "Weightage for CEA (Max 10%): ";
                    cin >> weights[3];
                    cout << "Weightage for Final Term (Max 45%): ";
                    cin >> weights[4];

                    // Function call to calculate total marks and assign grades
                    calculate_total_marks(lab_performance,lab_report,midterm,cea,final_term,total_marks,weights,num_students,15);
                    assign_grades(total_marks, grades, num_students);

                    // Display results
                    cout << "\n============= Results =============" << endl;
                    for (int i = 0; i < num_students; i++) {
                        cout << "Name: " << name[i];
                        cout << ", Roll No: " << roll_no[i];
                        cout << ", Total Marks: " << total_marks[i];
                        cout << ", Grade: " << grades[i] << endl;
                    }

                    // Function call to save CSV file with assessment marks
                    save_to_csv(name,roll_no,lab_performance,lab_report,midterm,cea,final_term,total_marks,grades,num_students,15);
                }
            }
        }
        else if (choice == 3) {
            cout << "\nExiting the portal... Goodbye!" << endl;
            break;
        }
        else {
            cout << "You had selected an invalid option. Please try again." << endl;
        }
        
    }}
	else if (choice_1 == 2){
    int totalBill=0;
    string choice_2;
    while (true){
    	cout << endl << "============= WELCOME TO UNIVERSITY CAFE =============" << endl << endl;
        displayMenu();
        cout<<endl<<"Enter item number you want to buy OR enter (bill) to display bill: ";
        cin>>choice_2;

        if (choice_2=="bill"||choice_2=="BILL"){
            cout<<"Total Bill: PKR "<<totalBill<<endl;
            break;
        }
        if (choice_2=="1") {
            totalBill+=250;
            cout<<"Coffee added to your bill.\n";
        } else if (choice_2=="2"){
            totalBill+=100;
            cout<<"Tea added to your bill.\n";
        } else if (choice_2=="3"){
            totalBill+=150;
            cout<<"Sandwich added to your bill.\n";
        } else if(choice_2=="4"){
            totalBill+=200;
            cout<<"Pizza Slice added to your bill.\n";
        } else if (choice_2=="5"){
            totalBill+=800;
            cout<<"Beef Burger added to your bill.\n";
        }
		else if (choice_2=="6"){
            totalBill+=400;
            cout<<"Zinger Burger added to your bill.\n";
        }else if(choice_2=="7"){
           	totalBill+=200;
            cout<<"Roll Paratha added to your bill.\n";
			}
			else if(choice_2=="8"){
            totalBill+=100;
            cout<<"Fries added to your bill.\n";
			}
			else if(choice_2=="9"){
            totalBill+=250;
            cout<<"Wrap added to your bill.\n";
			}
		else if (choice_2=="10"){
            totalBill+=800;
            cout<<"Icecream added to your bill.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";  
        }
       
    }
	}else if (choice_1 == 3){
	cout << "\nExiting the University Management System... Goodbye!" << endl;
	break;}
	else {
            cout << "You had selected an invalid option. Please try again." << endl;
        }		
		}
    return 0;
}

// Function to calculate total marks
void calculate_total_marks(float lab_performance[][15], float lab_report[][15], float midterm[], float cea[],
                          float final_term[], float total_marks[], float weights[], int num_students, int num_labs) {
    for (int i = 0; i < num_students; i++) {
        float lab_perf_total = 0;
        float lab_report_total = 0;

        // Sum up lab performance and report marks
        for (int j = 0; j < num_labs; j++) {
            lab_perf_total += lab_performance[i][j];
            lab_report_total += lab_report[i][j];
        }

        // Calculate total marks
        total_marks[i] = (lab_perf_total / num_labs) * weights[0]
                         + (lab_report_total / num_labs) * weights[1]
                         + midterm[i] * weights[2]
                         + cea[i] * weights[3]
                         + final_term[i] * weights[4];
    }
}

// Function to assign grades based on total marks
void assign_grades(float total_marks[], string grades[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        if (total_marks[i]==100||total_marks[i]>=90)
            grades[i] = 'A';
    else if (total_marks[i]<90&&total_marks[i]>=70)
            grades[i] = 'B';
       else if (total_marks[i]<70&&total_marks[i]>=50)
            grades[i] = 'C';
        else if (total_marks[i]<50&&total_marks[i]>=40)
            grades[i] = 'D';
        else
            grades[i] = 'F';
    }
}

// Function to save student data to a CSV file
void save_to_csv(string name[], string roll_no[], float lab_performance[][15], float lab_report[][15], float midterm[],
                 float cea[],float final_term[], float total_marks[], string grades[], int num_students, int num_labs) {
    ofstream file("student_results.csv");
    file << "Name,Roll Number,Lab Performances,Lab Reports,Midterm,CEA,Final Term,Total Marks,Grade\n";
    for (int i = 0; i < num_students; i++) {
        file << name[i] << "," << roll_no[i] << ",";
        
        // Print Lab Performances
        for (int j = 0; j < num_labs; j++) {
            file << lab_performance[i][j] << " ";
        }
        file << ",";

        // Print Lab Reports
        for (int j = 0; j < num_labs; j++) {
            file << lab_report[i][j] << " ";
        }
        file << ",";

        // Print Midterm, CEA, and Final Term
        file << midterm[i] << "," << cea[i] << "," << final_term[i] << ",";

        // Total Marks and Grade
        file << total_marks[i] << "," << grades[i] << "\n";
    }
    cout << "Data saved to student_results.csv" << endl;
}
 


