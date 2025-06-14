#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_PATIENTS = 1000;
//declaring new type Doctor
struct Doctor{
   	string firstName;
    string middleName;
    string lastName;
    string department;
    string address;
    string nationalID;
    bool available=true;
};

//declaring new type patient 
struct patient { 
    string firstName; 
    string middleName; 
    string lastName; 
    int age; 
    string address; 
    string nationalID; 
    string Position; 
}; 

//declaring new type for the reserved appointment 
struct appointment{ 
    string DoctorID; 
    string patientID; 
};

Doctor doctorsList[1000];
string departmentsList[14]={" "," "," "," "," "," "," "," "," "," "," "," "," "," "};
int doctorsListSize = 0;
int departmentsListSize = 0;
int patientsListSize=0; 
patient patienstList[1000];
appointment appointmentsList[1000]; 
int appointmentsListSize=0;

// to check if a certain Doctor exist in the doctors list
bool checkDoctorExist(string ID){
    for(int i = 0; i < doctorsListSize; i++){
        if(doctorsList[i].nationalID == ID)
            return true;
    }
    return false;
}

// to check if a certain Patient exist in the doctors list
bool checkPatientExist(string CID){
    for(int i = 0; i < patientsListSize; i++){
        if(patienstList[i].nationalID == CID)
            return true;
    }
    return false;
}

// to check the input if it's a number
// if not a number repeat until it's a number
string repeatIfNotNumber(string x ){
    string noteNotNumber = "Please Enter only Numbers\n";
    string text;
    bool condition = true;
    while(condition)
    {
        cout << x;
        cin >> text;
        bool isNumber = true;
        for(int i = 0; i < text.length(); i++){
            if(text[i] > '9' || text[i] < '0'){
                isNumber = false;
                break;
            }
        }
       
        condition = !isNumber;
        if(!condition)
            continue;
        cout << noteNotNumber;
    }
    return text;
}

// View a table for all doctors in the system
void showAllDoctors(){
cout<<"firstName" << setw(20) << "\tlastName" << setw(20) << "\tStatus" << setw(20) << "\tSpecialization" << setw(20)<< "ID\n";
string status="available";
for(int i=0;i<doctorsListSize;i++){
	
	if(!doctorsList[i].available)
		status="not available";
	else
		status="available";
	
		cout<<doctorsList[i].firstName<<setw(20)<<"\t"+doctorsList[i].lastName+"\t"<<setw(20)<<status+"\t"<<setw(20)<<doctorsList[i].department+"\t"<<setw(20)<<doctorsList[i].nationalID<<"\n";	
	}	
}


// View a table for doctors available in the system
void showAllDoctorsAvailable(){
cout<<"firstName"<<setw(20)<<"\tlastName"<<setw(20)<<"\tStatus\t"<<setw(20)<<"Specialization\t"<<setw(20)<<"ID\n";
string status="available";
for(int i=0;i<doctorsListSize;i++){
	if(doctorsList[i].available)
		cout<<doctorsList[i].firstName<<setw(20)<<"\t"+doctorsList[i].lastName+"\t"<<setw(20)<<status+"\t"<<setw(20)<<doctorsList[i].department+"\t"<<setw(20)<<doctorsList[i].nationalID<<"\n";	
	}	
}

// deleting a reservation by index of the reservation in the reserved appointment list 
void deleteAlgo(int RRIndex){ 
    for(int i = RRIndex; i < appointmentsListSize - 1;i++){ 
        swap(appointmentsList[i],appointmentsList[i+1]); 
    } 
    appointmentsListSize--; 
} 
 
//Here we delete an appointment and change the doctor's status available 
void deleteAppointment(){ 
 string id; 
 cout<<"Enter the ID of the doctor you wish to cancel the reservation with : "; 
 cin>>id; 
 
    for(int i = 0; i < doctorsListSize ;i++){ 
     if(doctorsList[i].nationalID==id){ 
      doctorsList[i].available=true; 
      break; 
  }   
    } 
     for(int i=0;i<appointmentsListSize;i++){ 
      if(appointmentsList[i].DoctorID==id){ 
       deleteAlgo(i); 
       break; 
   } 
       
     } 
cout   << "Reservation Canceled Successfully , with" << " Doctor ID :  " << id << endl; 
} 
 
 
// add a new  Appointment 
// by adding new Appointment into Appointment list 
 
void addNewAppointment (){ 
 string CID; 
 string DID; 
  appointment newappointment; 
  cout << "Enter ID for patient ...." << endl; 
  cin>>CID; 
if(!checkPatientExist(CID)){ 
        cout << "this National ID does not belong to a Patient" << endl; 
        return; 
    } 
cout << "choose the ID of the doctor you want to book an appointment with:" << endl; 
cout<<"Name\t\t\t Specialization\t\t\t ID\n"; 
 for(int i=0;i<doctorsListSize;i++){   
 if(doctorsList[i].available){ 
  cout<<doctorsList[i].firstName+" "+doctorsList[i].lastName+"\t\t\t"+doctorsList[i].department+"\t\t\t"+doctorsList[i].nationalID<<"\n";  
 } 
          } 
 cin>>DID; 
if(!checkDoctorExist(DID)){ 
        cout << "this National ID does not belong to a Doctor...please choose from the last List " << endl; 
        return; 
    } 
   for(int i=0;i<doctorsListSize;i++){ 
  
 if(doctorsList[i].nationalID==DID){ 
  doctorsList[i].available=false; 
  cout << "Appointment has been booked successfully" << endl ;
  break; 
 } 
} 
 newappointment.patientID=CID; 
 newappointment.DoctorID=DID; 
 appointmentsList[appointmentsListSize] = newappointment; 
    appointmentsListSize++; 
 
}

// Define a struct to represent a patient
struct Patient {
    string firstName;
    string middleName;
    string lastName;
    int age;
    string address;
    string nationalID;
};

Patient patientsQueue[MAX_PATIENTS];
int frontIndex = 0;  // Front of the queue
int rearIndex = 0;   // Rear of the queue

// Function to check if the queue is empty
bool isQueueEmpty() {
    return frontIndex == rearIndex;
}

// Function to check if the queue is full
bool isQueueFull() {
    return (rearIndex + 1) % MAX_PATIENTS == frontIndex;
}

// Function to add a new patient to the queue
void addNewPatient() {
    if (isQueueFull()) {
        cout << "Patient queue is full. Cannot add more patients." << endl;
        return;
    }

    Patient newPatient;
    cout << "Enter new patient details..." << endl;

    cout << "First Name: ";
    cin >> newPatient.firstName;

    cout << "Middle Name: ";
    cin >> newPatient.middleName;

    cout << "Last Name: ";
    cin >> newPatient.lastName;

    cout << "Age: ";
    cin >> newPatient.age;

    cout << "Address: ";
    cin.ignore();
    getline(cin, newPatient.address);

    cout << "National ID: ";
    cin >> newPatient.nationalID;

    // Add the inserted patient to the patient queue
    patientsQueue[rearIndex] = newPatient;
    rearIndex = (rearIndex + 1) % MAX_PATIENTS;

    cout << "New Patient Added Successfully." << endl;
}
// Function to remove the front patient from the queue (dequeue)
void dequeuePatient() {
    if (isQueueEmpty()) {
        cout << "Patient queue is empty. Cannot dequeue." << endl;
        return;
    }

    cout << "Dequeueing the front patient..." << endl;
    frontIndex = (frontIndex + 1) % MAX_PATIENTS;
    cout << "Front patient removed from the queue." << endl;
}
//Adding new Doctor data to the system and giving him his own ID number
void addNewDoctor(){
    Doctor newDoctor;
    cout << "Enter new Doctor Details...." << endl;

    cout << "First Name: ";
    cin >> newDoctor.firstName;

    cout << "Middle Name: ";
    cin >> newDoctor.middleName;

    cout << "Last Name: ";
    cin >> newDoctor.lastName;
 	
	cout << "choose number the from List Department: \n";
	cout << "1- Epidemiologist\n";
	cout << "2- Podiatrist\n";
	cout << "3- Audiologist\n";
	cout << "4- General practitioner\n";
	cout << "5- Pediatrician\n";
	cout << "6- Obstetrics and gynecology physician\n";
	cout << "7- Otolaryngologist/ENT specialist\n";
	cout << "8- Dentist\n";
	cout << "9- Surgeon\n";
	cout << "10- Rheumatologist\n";
	cout << "11- Urologist\n";
	cout << "12- Psychiatrist\n";
	cout << "13- Radiologist\n";
	cout << "14- Cardiologist\n";
	int x;
	
	cin>>x;
	 switch(x){
        case 1:
        newDoctor.department="Epidemiologist";
        departmentsList[x-1]="Epidemiologist";
            break;
        case 2:
           newDoctor.department="Podiatrist";
           departmentsList[x-1]="Podiatrist";
            break;
        case 3:
           newDoctor.department="Audiologist";
        	departmentsList[x-1]="Audiologist";
            break;
        case 4:
           newDoctor.department="General practitioner";
           departmentsList[x-1]=="General practitioner";
            break;
        case 5:
           newDoctor.department="Pediatrician";
           departmentsList[x-1]="Pediatrician";
            break;
    	case 6:
           newDoctor.department="Obstetrics and gynecology physician";
           departmentsList[x-1]="Obstetrics and gynecology physician";
            break;

		case 7:
           newDoctor.department="Otolaryngologist/ENT specialist";
           departmentsList[x-1]="Otolaryngologist/ENT specialist";
            break;
        case 8:
           newDoctor.department="Dentist";
           departmentsList[x-1]="Dentist";
            break;
        case 9:
           newDoctor.department="Surgeon";
           departmentsList[x-1]="Surgeon";
            break;
        case 10:
           newDoctor.department="Rheumatologist";
           departmentsList[x-1]="Rheumatologist";
            break;
		case 11:
           newDoctor.department="Urologist";
           departmentsList[x-1]="Urologist";
            break;
        case 12:
           newDoctor.department="Psychiatrist";
           departmentsList[x-1]="Psychiatrist";
            break;
        case 13:
           newDoctor.department="Radiologist";
           departmentsList[x-1]="Radiologist";
            break;
        case 14:
           newDoctor.department="Cardiologist";
           departmentsList[x-1]="Cardiologist";
            break;
            default:
           cout<<"please choose number between 1 and 14\n";
            break;
        }
    cin.ignore();
	cout << "Address: ";
    getline(cin, newDoctor.address);

    newDoctor.nationalID =
        repeatIfNotNumber("National ID: ");
    while(checkDoctorExist(newDoctor.nationalID)){
        cout << "this ID is taken try Another One:" << endl;
        newDoctor.nationalID =
            repeatIfNotNumber("National ID: ");
    }
    // adding the inserted doctor to the doctors List
    doctorsList[doctorsListSize] = newDoctor;
    doctorsListSize++;

    cout << "New Doctor Added Successfully..." << endl;
}

//Print the data of a doctor present in the system.
// The user is required to first enter the doctor's ID number and verify his presence in the system
void printDoctorDetails(){
	
    cout << "Printing Doctor Details ..." << endl;
    cout << "Enter  National ID to show Details:" << endl;
    string DID;
    DID = repeatIfNotNumber("Doctor ID: ");
    if(!checkDoctorExist(DID)){
        cout << "this National ID does not belong to a Doctor" << endl;
 		return  ;
    }
    int index;
    for(int i = 0; i < doctorsListSize; i++){
        if(doctorsList[i].nationalID == DID){
            index = i;
        }
    }
    cout << "National ID: " << doctorsList[index].nationalID << endl;
    cout << "First Name: " << doctorsList[index].firstName << endl;
    cout << "Middle Name: " << doctorsList[index].middleName << endl;
    cout << "Last Name: " << doctorsList[index].lastName << endl;
    cout << "Department: " << doctorsList[index].department << endl;
    cout << "Address: " <<doctorsList[index].address << endl;
    cout << "End of Doctor Details." << endl;
}


//Print the data of a Patient present in the system.
// The user is required to first enter the Patient's ID number and verify his presence in the system
void printPatientDetails() {
    cout << "Printing Patient Details..." << endl;
    cout << "Enter National ID to show details: ";
    string CID;
    cin >> CID;

    bool found = false;

    int currentIndex = frontIndex;
    while (currentIndex != rearIndex) {
        if (patientsQueue[currentIndex].nationalID == CID) {
            found = true;
            cout << "National ID: " << patientsQueue[currentIndex].nationalID << endl;
            cout << "First Name: " << patientsQueue[currentIndex].firstName << endl;
            cout << "Middle Name: " << patientsQueue[currentIndex].middleName << endl;
            cout << "Last Name: " << patientsQueue[currentIndex].lastName << endl;
            cout << "Age: " << patientsQueue[currentIndex].age << endl;
            cout << "Address: " << patientsQueue[currentIndex].address << endl;
            cout << "End of Patient Details." << endl;
            break;
        }
        currentIndex = (currentIndex + 1) % MAX_PATIENTS;
    }

    if (!found) {
        cout << "This National ID does not belong to a Patient." << endl;
    }
}

//We use this function inside the function to modify an appointment with the doctor updateAppointments(),
// and this switches between the new doctor and the old doctor, and changes the status of each of them
swapDoctorAppointments(string oldID,string newID){
	for(int i=0;i<doctorsListSize;i++){
		if(doctorsList[i].nationalID==oldID){
			doctorsList[i].available=true;
		}
		else if(doctorsList[i].nationalID==newID){
			doctorsList[i].available=false;
		}
	}
	for(int i=0;i<appointmentsListSize;i++){
		if(appointmentsList[i].DoctorID==oldID){
		appointmentsList[i].DoctorID=newID;	
		}
	}
}

//Modify the details of booking an appointment with a doctor
void updateAppointments(){
	 int k;
	 string oldid;
	 string newid;
    // infinite loop for inserting the number of a certain operation
    do{
        cout << "-------------------------" << endl;
        cout << "Enter the Number of the Operation to Proceed:" << endl;
        cout << "Enter 1  to change DoctorID." << endl;
        cout << "Enter -1  to Exit." << endl;
        cin >> k;
        switch(k){
        case 1:
            cout << "Enter the ID of the doctor whose reservation you wish to cancel:" << endl;
            cin>>oldid;
            cout << "Enter the ID of the new doctor you wish to book:" << endl;
            cin>>newid;
            swapDoctorAppointments(oldid,newid);
            cout << "Your appointment has been successfully updated with doctor ID : " << newid << endl;
            break;
           
        }}while(k!=-1);
}

//A function that returns the Patient's name through his ID number
string getNamePatient(string id){
	for(int i=0;i<patientsListSize;i++)
	{
		if(patienstList[i].nationalID==id){
			return patienstList[i].firstName+"  "+patienstList[i].lastName;
		}
	}
}


//A function that returns the doctor's name through his ID number
string getNameDoctor(string id){
	for(int i=0;i<doctorsListSize;i++)
	{
		if(doctorsList[i].nationalID==id){
			return doctorsList[i].firstName+"  "+doctorsList[i].lastName;
		}
	}
}

//Print all appointments currently in the system
void printAppointments(){
    cout << "Printing Appointments Details ..." << endl;
    cout<<"Doctor ID"<<setw(25)<<"patient ID"<<setw(25)<<"Doctor Name"<<setw(25)<<"patient Name"<<endl;
    for(int i=0;i<appointmentsListSize;i++){
    	cout<<appointmentsList[i].DoctorID << "\t" << setw(20) << appointmentsList[i].patientID << "\t" << setw(32) << getNameDoctor(appointmentsList[i].DoctorID)  << setw(20) << getNamePatient(appointmentsList[i].patientID)<<endl;
											}
	}


//main function


int main()                                                                  
{                                                                     
    int k;
    // infinite loop for inserting the number of a certain operation
    do{
        cout << "-------------------------" << endl;
        cout << "Enter the Number of the Operation to Proceed:" << endl;
        cout << "Enter 1  to Add New Doctor." << endl;
        cout << "Enter 2  to Show Doctor Details." << endl;
        cout << "Enter 3  to Add New Patient." << endl;
        cout << "Enter 4  to delet a Patient." << endl;
        cout << "Enter 5  to Show Patient Details." << endl;
        cout << "Enter 6  to Reserve Appointment." << endl;
        cout << "Enter 7  to Show All Doctors Available." << endl;
        cout << "Enter 8  to Show All Doctors." << endl;
        cout << "Enter 9  to Delete Appointment." << endl;
        cout << "Enter 10 to Show All Appointments." << endl;
        cout << "Enter 11 to Update Appointments." << endl;
        cout << "Enter 12 to Exit." << endl;
        cin >> k;
        switch(k){
        case 1:
            addNewDoctor();
            break;
        case 2:
            printDoctorDetails();
            break;
        case 3:
            addNewPatient();
            break;
        case 4:
        	dequeuePatient();
        	break;
        case 5:
        	printPatientDetails();
            break;
        case 6:
            addNewAppointment();
            break;
        case 7:
            showAllDoctorsAvailable();
            break;
        case 8:
           showAllDoctors();
            break;
        case 9:
            deleteAppointment();
            break;
        case 10:
            printAppointments();
            break;
        case 11:
        	updateAppointments();
        	break;
        }
    } while(k != 11);
    return 0;
}

