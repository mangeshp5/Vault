#include <iostream>
#include <string>
using namespace std;

// Class to store absence information (Sparse Element)
class Absence {
public:
    int student;       // student index
    int day;           // day index
    string name;       // student name
};

int main() {
    int students, days, absCount;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of days: ";
    cin >> days;

    cout << "Enter number of absences to record: ";
    cin >> absCount;

    Absence A[100];   // Sparse array storing only absentees

    cout << "\nEnter absence records as -> student_no  day_no  student_name\n";
    for(int i = 0; i < absCount; i++) {
        cout << "Record " << i+1 << ": ";
        cin >> A[i].student >> A[i].day >> A[i].name;
    }

    // ==================== Display Sparse Absence Records ====================
    cout << "\n===== Sparse Attendance (Only Absentees) =====\n";
    for(int i = 0; i < absCount; i++) {
        cout << "Student " << A[i].student 
             << " was absent on Day " << A[i].day
             << " -> Name: " << A[i].name << endl;
    }

    // ==================== Display Full Attendance Matrix ====================
    cout << "\n===== Full Attendance Matrix =====\n";
    cout << "0 = Present | 1 = Absent\n";

    for(int i = 0; i < students; i++) {
        for(int j = 0; j < days; j++) {
            bool absent = false;

            // Check if student i was absent on day j
            for(int k = 0; k < absCount; k++) {
                if(A[k].student == i && A[k].day == j) {
                    absent = true;
                    break;
                }
            }
            cout << (absent ? "1 " : "0 ");
        }
        cout << endl;
    }

    int count =0;
    for(int i=0;i<students;i++){

        if(A[i].day==1) count ++;

    }

    return 0;
}
