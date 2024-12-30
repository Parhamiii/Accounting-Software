#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Personnel{
    string fName;
    string lName;
    string pID;
    string age;
    string startWorking;
    string educationLevel;
    string positionInCompany;
    string leave;
    string totalWorkingHours;
};

struct WorkingHours{
    string date;
    bool leave;
    Personnel personnel;
    string arrivalTime;
    string exitTime;
    string totalWorkInDay;
};
void showFile(){
    ifstream myFile;
    myFile.open("working hours.txt");
    string temp;
    if (myFile.is_open()){
        while(getline(myFile,temp)){
            cout<<temp<<endl;
            temp.erase();
        }
    }
    else{
        cout<<"Error in opening file Work hour\n";
    }
    myFile.close();
}
int getLineOfFile(const string& fileName){
    ifstream myFile;
    string temp;
    int numberOfLine = 0;
    myFile.open(fileName);
    if (myFile.is_open()){
        while(getline(myFile,temp)){
            numberOfLine++;
        }
    }
    else{
        cout<<"Error in opening file: "<<fileName<<endl;
    }
    myFile.close();
    return numberOfLine;
}
Personnel* getPersonnel(){
    int numOfPersonnel = getLineOfFile("Personnel.txt");
    ifstream myFile;
    auto* personnel = new Personnel[numOfPersonnel];
    myFile.open("Personnel.txt");
    int i=0;
    if (myFile.is_open()) {
        while ( i < numOfPersonnel ) {
            myFile>>personnel[i].fName>>personnel[i].lName>>personnel[i].age>>personnel[i].positionInCompany>>
            personnel[i].startWorking>>personnel[i].educationLevel>>personnel[i].pID>>personnel[i].totalWorkingHours>>
            personnel[i].leave;
            i++;
        }
    }
    else{
        cout<<"Error opening Courses file\n";
    }
    myFile.close();
    return personnel;
}
Personnel personnelSearch(Personnel* personnel, const string& id){
    int i = 0;
    Personnel personnel1;
    int numOfPersonnel = getLineOfFile("Personnel.txt");
    while (i < numOfPersonnel){
        if (personnel[i].pID == id){
           personnel1 = personnel[i];
            break;
        }
        i++;
    }
    return personnel1;
}
//void cheak(string start, string end){
//    int temp;
//    for (int i=0; i<start.length(); i++){
//         if(i==0 || i==1){
//               char s = start[i];
//               if( s>= '0' && s<='9' ){
//                 temp = temp * 10 +( s-'0' );
//                }
//          }
//         if (i == 3 || i == 4){
//             char s = start[i];
//             if( s>= '0' && s<='9' ){
//                 temp = temp * 10 +( s-'0' );
//             }
//         }
//
//
//    }
//
//
//}
void showPersonnel(Personnel* personnel){
    int numOfPersonnel = getLineOfFile("Personnel.txt");
    for(int j=0; j < numOfPersonnel; j++){
        cout<<j+1<<"- "<<personnel[j].fName<<" "
        <<personnel[j].lName<<"  "<<personnel[j].pID
        <<"  "<<personnel[j].age<<"  "<<personnel[j].startWorking
        <<" "<<personnel[j].educationLevel<<"  "<<personnel[j].totalWorkingHours
        <<"  "<<personnel[j].leave<<endl;
    }
}
Personnel* newEmployee(){
    int numOfNewEmployee=0;
    cout<<"How many people do you want to hire?"<<endl;
    cin>>numOfNewEmployee;
    cin.ignore();
    auto* personnel = new Personnel[numOfNewEmployee];
    for(int i=0; i<numOfNewEmployee; i++) {
        cout << "test halghe\n";
        cout << "Please insert Date:" << endl;
        getline(cin, personnel[i].startWorking);
        cout << "Please insert your first name:" << endl;
        getline(cin, personnel[i].fName);

        cout << "Please insert your last name:" << endl;
        getline(cin, personnel[i].lName);
        cout << "Please insert your age:" << endl;
        getline(cin, personnel[i].age);

        cout << "Please insert your education level:" << endl;
        getline(cin, personnel[i].educationLevel);
        cout << "\n-------------------------------------\n\n";
    }
    /// test :
//    for (int i = 0; i < numOfNewEmployee; i++) {
//        cout << personnel[i].startWorking << endl;
//        cout << personnel[i].fName << endl;
//        cout << personnel[i].lName << endl;
//        cout << personnel[i].age << endl;
//        cout << personnel[i].educationLevel << endl;
//    }
    return personnel;
}
float record(){
    float  total = 0, convertStart = 0, convertEnd = 0;
    cout<<"Please record your check-in and check-out time according to the sample:\n";
    cout<<"Arrival Time : 08:00\n";
    cout<<"Exit Time : 19:30\n";
    cout<<"**********************************\n\n";

    string start, end;
    unsigned long int length;
    for (int j = 0; j < 2; j++) {
        if (j == 0){
            cout<<"Arrival Time: "<<endl;
            getline(cin, start);
            length = start.length();
        }
        else{
            cout<<"Exit Time: "<<endl;
            getline(cin, end);
            length = end.length();
        }

        float temp = 0, temp2 = 0;
        for (int i = 0; i < length; i++) {
            if (j == 0) {
                if (i == 0 || i == 1) {
                    char select = start[i];
                    if (select >= '0' && select <= '9') {
                        temp = temp * 10 + (select - '0');
                    }
                } else if (i == 3 || i == 4) {
                    char select = start[i];
                    if (select >= '0' && select <= '9') {
                        temp2 = temp2 * 10 + (select - '0');
                    }
                }
                convertStart = (temp * 60) + temp2;
            }
            else if ( j == 1) {
                if (i == 0 || i == 1) {
                    char select = start[i];
                    if (select >= '0' && select <= '9') {
                        temp = temp * 10 + (select - '0');
                    }
                }
                else if (i == 3 || i == 4) {
                    char select = start[i];
                    if (select >= '0' && select <= '9') {
                        temp2 = temp2 * 10 + (select - '0');
                    }
                }
                convertEnd = (temp * 60) + temp2;
            }
        }
    }
    total = (convertEnd - convertStart) / 60;
    return total;
}


bool returnToTheMenu(){
    int insertedNumber = -1;
    cout<<"To Return to the previous step insert 0...";
    cin>>insertedNumber;
    if(insertedNumber == 0){
        return true;
    }else
        return false;
}
void RegisterWorkingHours(){
    string id;
    cout<<"Welcome, Please insert your Personnel ID:\n";
    cin>>id;
    Personnel* personnel;
    personnel = getPersonnel();
    Personnel personnel1 = personnelSearch(personnel, id);
    cout<<"First Name: "<<personnel1.fName<<endl;
    cout<<"Last Name: "<<personnel1.lName<<endl;
    cout<<"Age: "<<personnel1.age<<endl;
    cout<<"level: "<<personnel1.positionInCompany<<endl;
    cout<<"Education Level: "<<personnel1.educationLevel<<endl;
    cout<<"Start In Company: "<<personnel1.startWorking<<endl;
}
void menu(){
    cout<<"1- View the number of personnel\n";
    cout<<"2- New employee\n";
    cout<<"3- View personnel information\n";
    cout<<"4- View the working hours of the collection\n";
    cout<<"5- Register working hours\n";
    cout<<"6- How to calculate salary\n";
    cout<<"7- Total salary\n";
    char select;
    cin>>select;
    switch (select) {
        case '1':{
            Personnel* personnel = getPersonnel();
            showPersonnel(personnel);
            delete[] personnel;
            if(returnToTheMenu()){
                menu();
            }
            break;
        }

        case '2':
            newEmployee();
            if(returnToTheMenu()){
                menu();
            }
            break;

        case '3':

            if(returnToTheMenu()){
                menu();
            }
            break;

        case '4':
            showFile();
            break;


        case '5':
            RegisterWorkingHours();
            record();
//            if(returnToTheMenu()){
//                menu();
//            }
            break;


        default:
            cout<<"Error\n";
            break;
    }
}

int main() {
//    string registrationTime;
////    cout<<"Enter s: ";
////    getline(cin, s);
////
////    cout<<"Enter e: ";
////    getline(cin, e);
//    record(registrationTime);
    menu();
    return 0;
}
