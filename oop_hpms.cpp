#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

// ===================== USER CLASS =====================
class User {
private:
    string username;
    string password;
    string role; // Admin, Doctor, Receptionist

public:
    User() {
        username = "";
        password = "";
        role = "";
    }

    User(string u, string p, string r) {
        username = u;
        password = p;
        role = r;
    }

    // Copy Constructor
    User(const User& u) {
        username = u.username;
        password = u.password;
        role = u.role;
    }

    ~User() {}

    string getUsername() const { return username; }
    string getRole() const { return role; }

    bool authenticate(string u, string p) const {
        return (u == username && p == password);
    }
};

// ===================== PATIENT CLASS =====================
class Patient {
private:
    string id;
    string name;
    int age;
    string contact;
    string medicalHistory;

public:
    // Default Constructor
    Patient() {
        id = "";
        name = "";
        age = 0;
        contact = "";
        medicalHistory = "";
    }

    // Parameterized Constructor
    Patient(string i, string n, int a, string c, string m) {
        id = i;
        name = n;
        setAge(a);
        contact = c;
        medicalHistory = m;
    }

    // Copy Constructor
    Patient(const Patient& p) {
        id = p.id;
        name = p.name;
        age = p.age;
        contact = p.contact;
        medicalHistory = p.medicalHistory;
    }

    // Destructor
    ~Patient() {}

    // Setters with Validation
    void setName(string n) {
        if (!n.empty()) name = n;
    }

    void setAge(int a) {
        if (a > 0 && a < 150) age = a;
        else age = 0;
    }

    void setContact(string c) {
        if (!c.empty() && c.length() >= 10) contact = c;
        else contact = "Invalid";
    }

    void setMedicalHistory(string m) {
        medicalHistory = m;
    }

    // Getters
    string getID() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getContact() const { return contact; }
    string getMedicalHistory() const { return medicalHistory; }

    // Display Function
    void display() const {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(8) << age
             << setw(15) << contact
             << medicalHistory << endl;
    }
};

// ===================== DOCTOR CLASS =====================
class Doctor {
private:
    string id;
    string name;
    string specialization;
    string contact;
    bool available;
    int appointmentCount;  // For performance reporting

public:
    // Default Constructor
    Doctor() {
        id = "";
        name = "";
        specialization = "";
        contact = "";
        available = true;
        appointmentCount = 0;
    }

    // Parameterized Constructor
    Doctor(string i, string n, string s, string c) {
        id = i;
        name = n;
        specialization = s;
        contact = c;
        available = true;
        appointmentCount = 0;
    }

    // Copy Constructor
    Doctor(const Doctor& d) {
        id = d.id;
        name = d.name;
        specialization = d.specialization;
        contact = d.contact;
        available = d.available;
        appointmentCount = d.appointmentCount;
    }

    // Destructor
    ~Doctor() {}

    // Setters with Validation
    void setName(string n) {
        if (!n.empty()) name = n;
    }

    void setSpecialization(string s) {
        if (!s.empty()) specialization = s;
    }

    void setContact(string c) {
        if (!c.empty() && c.length() >= 10) contact = c;
    }

    void setAvailability(bool a) {
        available = a;
    }

    void incrementAppointmentCount() {
        appointmentCount++;
    }

    void decrementAppointmentCount() {
        if (appointmentCount > 0) appointmentCount--;
    }

    // Getters
    string getID() const { return id; }
    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
    string getContact() const { return contact; }
    bool isAvailable() const { return available; }
    int getAppointmentCount() const { return appointmentCount; }

    // Display
    void display() const {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(20) << specialization
             << setw(15) << contact
             << (available ? "Available" : "Busy") << endl;
    }
};

// ===================== APPOINTMENT CLASS =====================
class Appointment {
private:
    string appointmentID;
    Patient* patient;
    Doctor* doctor;
    string date;
    string time;

public:
    // Default Constructor
    Appointment() {
        appointmentID = "";
        patient = NULL;
        doctor = NULL;
        date = "";
        time = "";
    }

    // Parameterized Constructor
    Appointment(string id, Patient* p, Doctor* d, string dt, string tm) {
        appointmentID = id;
        patient = p;
        doctor = d;
        date = dt;
        time = tm;
        if (doctor) {
            doctor->setAvailability(false);
            doctor->incrementAppointmentCount();
        }
    }

    // Copy Constructor
    Appointment(const Appointment& a) {
        appointmentID = a.appointmentID;
        patient = a.patient;
        doctor = a.doctor;
        date = a.date;
        time = a.time;
    }

    // Destructor
    ~Appointment() {
        if (doctor) {
            doctor->setAvailability(true);
            doctor->decrementAppointmentCount();
        }
    }

    string getID() const { return appointmentID; }
    Patient* getPatient() const { return patient; }
    Doctor* getDoctor() const { return doctor; }
    string getDate() const { return date; }
    string getTime() const { return time; }

    void setDate(string d) { 
        if (!d.empty()) date = d; 
    }
    
    void setTime(string t) { 
        if (!t.empty()) time = t; 
    }

    void display() const {
        cout << left << setw(10) << appointmentID
             << setw(20) << patient->getName()
             << setw(20) << doctor->getName()
             << setw(12) << date
             << time << endl;
    }
};

// ===================== MEDICAL RECORD CLASS =====================
class MedicalRecord {
private:
    string recordID;
    Patient* patient;
    string diagnosis;
    string treatment;
    string prescription;
    string date;

public:
    // Default Constructor
    MedicalRecord() {
        recordID = "";
        patient = NULL;
        diagnosis = "";
        treatment = "";
        prescription = "";
        date = "";
    }

    // Parameterized Constructor
    MedicalRecord(string id, Patient* p, string d, string t, string pr, string dt) {
        recordID = id;
        patient = p;
        diagnosis = d;
        treatment = t;
        prescription = pr;
        date = dt;
    }

    // Copy Constructor
    MedicalRecord(const MedicalRecord& m) {
        recordID = m.recordID;
        patient = m.patient;
        diagnosis = m.diagnosis;
        treatment = m.treatment;
        prescription = m.prescription;
        date = m.date;
    }

    // Destructor
    ~MedicalRecord() {}

    string getRecordID() const { return recordID; }
    Patient* getPatient() const { return patient; }
    string getDiagnosis() const { return diagnosis; }
    string getDate() const { return date; }

    void setDiagnosis(string d) { if (!d.empty()) diagnosis = d; }
    void setTreatment(string t) { if (!t.empty()) treatment = t; }
    void setPrescription(string p) { if (!p.empty()) prescription = p; }

    void display() const {
        cout << left << setw(10) << recordID
             << setw(20) << patient->getName()
             << setw(15) << diagnosis
             << setw(20) << treatment
             << setw(20) << prescription
             << date << endl;
    }
};

// ===================== BILL CLASS =====================
class Bill {
private:
    string billID;
    Patient* patient;
    double consultationFee;
    double medicineCost;
    double testCost;
    double totalAmount;
    double paidAmount;
    string paymentDate;

public:
    // Default Constructor
    Bill() {
        billID = "";
        patient = NULL;
        consultationFee = 0;
        medicineCost = 0;
        testCost = 0;
        totalAmount = 0;
        paidAmount = 0;
        paymentDate = "";
    }

    // Parameterized Constructor
    Bill(string id, Patient* p, double c, double m, double t) {
        billID = id;
        patient = p;
        consultationFee = (c >= 0) ? c : 0;
        medicineCost = (m >= 0) ? m : 0;
        testCost = (t >= 0) ? t : 0;
        totalAmount = consultationFee + medicineCost + testCost;
        paidAmount = 0;
        paymentDate = "";
    }

    // Copy Constructor
    Bill(const Bill& b) {
        billID = b.billID;
        patient = b.patient;
        consultationFee = b.consultationFee;
        medicineCost = b.medicineCost;
        testCost = b.testCost;
        totalAmount = b.totalAmount;
        paidAmount = b.paidAmount;
        paymentDate = b.paymentDate;
    }

    // Destructor
    ~Bill() {}

    string getBillID() const { return billID; }
    Patient* getPatient() const { return patient; }
    double getTotal() const { return totalAmount; }
    double getPaid() const { return paidAmount; }
    double getPending() const { return totalAmount - paidAmount; }
    string getPaymentDate() const { return paymentDate; }

    void processPayment(double amount, string date = "") {
        if (amount > 0 && paidAmount + amount <= totalAmount) {
            paidAmount += amount;
            paymentDate = date;
        }
    }

    void display() const {
        cout << left << setw(10) << billID
             << setw(20) << patient->getName()
             << setw(12) << consultationFee
             << setw(12) << medicineCost
             << setw(12) << testCost
             << setw(12) << totalAmount
             << setw(12) << paidAmount
             << getPending() << endl;
    }
};

// ===================== DEPARTMENT CLASS =====================
class Department {
private:
    string deptID;
    string deptName;
    Doctor** doctors;  // Dynamic array of doctor pointers
    int doctorCount;
    int maxDoctors;

public:
    // Default Constructor
    Department() {
        deptID = "";
        deptName = "";
        maxDoctors = 20;
        doctors = new Doctor*[maxDoctors];
        doctorCount = 0;
    }

    // Parameterized Constructor
    Department(string id, string name) {
        deptID = id;
        deptName = name;
        maxDoctors = 20;
        doctors = new Doctor*[maxDoctors];
        doctorCount = 0;
    }

    // Copy Constructor
    Department(const Department& d) {
        deptID = d.deptID;
        deptName = d.deptName;
        maxDoctors = d.maxDoctors;
        doctorCount = d.doctorCount;
        doctors = new Doctor*[maxDoctors];
        for (int i = 0; i < doctorCount; i++)
            doctors[i] = d.doctors[i];
    }

    // Destructor
    ~Department() {
        delete[] doctors;
    }

    string getDeptID() const { return deptID; }
    string getDeptName() const { return deptName; }
    int getDoctorCount() const { return doctorCount; }
    Doctor* getDoctor(int index) const { 
        if (index >= 0 && index < doctorCount) 
            return doctors[index]; 
        return NULL;
    }

    void assignDoctor(Doctor* d) {
        if (doctorCount < maxDoctors && d != NULL) {
            doctors[doctorCount++] = d;
            cout << "Doctor assigned successfully to " << deptName << " department!\n";
        } else {
            cout << "Cannot assign doctor. Department full or invalid doctor!\n";
        }
    }

    void display() const {
        cout << "Department ID: " << deptID << endl;
        cout << "Department Name: " << deptName << endl;
        cout << "Doctors in this Department:\n";

        if (doctorCount == 0) {
            cout << "  No doctors assigned.\n";
        } else {
            for (int i = 0; i < doctorCount; i++)
                cout << "  - " << doctors[i]->getName() 
                     << " (" << doctors[i]->getSpecialization() << ")\n";
        }
    }
};

// ===================== ACCESS CONTROL FUNCTION =====================
void showMenuByRole(string role) {
    cout << "\n" << string(50, '=') << endl;
    cout << "     HEALTHCARE PATIENT MANAGEMENT SYSTEM" << endl;
    cout << string(50, '=') << endl;
    
    if (role == "Admin") {
        cout << "\n--- ADMIN ACCESS (Full System Access) ---\n";
        cout << "1. Patient Management\n";
        cout << "2. Doctor Management\n";
        cout << "3. Appointment Management\n";
        cout << "4. Medical Records Management\n";
        cout << "5. Billing Management\n";
        cout << "6. Department Management\n";
        cout << "7. Reports & Analytics\n";
        cout << "8. Logout\n";
    }
    else if (role == "Doctor") {
        cout << "\n--- DOCTOR ACCESS ---\n";
        cout << "1. View My Appointments\n";
        cout << "2. View Patient Medical Records\n";
        cout << "3. Update Medical Records\n";
        cout << "4. Check My Availability\n";
        cout << "5. Logout\n";
    }
    else if (role == "Receptionist") {
        cout << "\n--- RECEPTIONIST ACCESS ---\n";
        cout << "1. Register New Patient\n";
        cout << "2. View Patient Details\n";
        cout << "3. Schedule Appointment\n";
        cout << "4. View Appointments\n";
        cout << "5. Generate Bill\n";
        cout << "6. View Bills\n";
        cout << "7. Process Payment\n";
        cout << "8. Logout\n";
    }
    cout << string(50, '-') << endl;
}

// ===================== VALIDATION FUNCTIONS =====================
bool validateAge(int age) {
    return (age > 0 && age < 150);
}

bool validateContact(string contact) {
    return (contact.length() >= 10 && contact.length() <= 15);
}

bool validateDate(string date) {
    if (date.length() != 10) return false;
    if (date[2] != '-' || date[5] != '-') return false;
    return true;
}

// ===================== MAIN FUNCTION =====================
int main() {
    // Predefined system users
    User users[4] = {
        User("admin", "admin123", "Admin"),
        User("dr_smith", "doc123", "Doctor"),
        User("dr_jones", "doc456", "Doctor"),
        User("reception", "rec123", "Receptionist")
    };

    // Login System
    string inputUser, inputPass;
    bool loggedIn = false;
    string loggedRole = "";
    int loginAttempts = 0;
    const int MAX_ATTEMPTS = 3;

    cout << "\n" << string(50, '=') << endl;
    cout << "     HEALTHCARE PATIENT MANAGEMENT SYSTEM" << endl;
    cout << "              LOGIN REQUIRED" << endl;
    cout << string(50, '=') << endl;

    while (!loggedIn && loginAttempts < MAX_ATTEMPTS) {
        cout << "\nUsername: ";
        cin >> inputUser;
        cout << "Password: ";
        cin >> inputPass;

        for (int i = 0; i < 4; i++) {
            if (users[i].authenticate(inputUser, inputPass)) {
                loggedIn = true;
                loggedRole = users[i].getRole();
                break;
            }
        }

        if (!loggedIn) {
            loginAttempts++;
            cout << "\nInvalid Username or Password! Attempts left: " 
                 << (MAX_ATTEMPTS - loginAttempts) << endl;
        }
    }

    if (!loggedIn) {
        cout << "\nToo many failed attempts. System locked!\n";
        return 1;
    }

    cout << "\nLogin Successful! Welcome " << inputUser << " (" << loggedRole << ")\n";

    // ===================== DYNAMIC MEMORY ALLOCATION =====================
    Patient* patients = new Patient[100];
    Doctor* doctors = new Doctor[50];
    Appointment* appointments = new Appointment[200];
    MedicalRecord* records = new MedicalRecord[200];
    Bill* bills = new Bill[200];
    Department* departments = new Department[20];

    int patientCount = 0, doctorCount = 0, appointmentCount = 0;
    int recordCount = 0, billCount = 0, deptCount = 0;
    double totalRevenue = 0;

   /// Add some sample data
    // Sample Patients
    patients[patientCount++] = Patient("P001", "Ayesha", 20, "03001234567", "Diabetes");
    patients[patientCount++] = Patient("P002", "Hamid", 24, "03007654321", "Asthma");
    patients[patientCount++] = Patient("P003", "Muneeb", 19, "03005555555", "Hypertension");

    // Sample Doctors
    doctors[doctorCount++] = Doctor("D001", "Dr. Smith", "Cardiology", "03001112222");
    doctors[doctorCount++] = Doctor("D002", "Dr. Jones", "Pediatrics", "03003334444");
    doctors[doctorCount++] = Doctor("D003", "Dr. Brown", "Orthopedics", "03005556666");

    // Sample Departments
    departments[deptCount++] = Department("DEP01", "Cardiology");
    departments[deptCount++] = Department("DEP02", "Pediatrics");
    departments[deptCount++] = Department("DEP03", "Orthopedics");

    // Assign doctors to departments
    departments[0].assignDoctor(&doctors[0]);
    departments[1].assignDoctor(&doctors[1]);
    departments[2].assignDoctor(&doctors[2]);

    // Main program loop based on role
    int mainChoice;
    bool running = true;

    while (running) {
        showMenuByRole(loggedRole);
        cout << "Enter your choice: ";
        cin >> mainChoice;

        // Role-based menu handling
        if (loggedRole == "Admin") {
            switch(mainChoice) {
                case 1: { // Patient Management
                    int choiceP;
                    do {
                        cout << "\n===== PATIENT MANAGEMENT MENU =====\n";
                        cout << "1. Add New Patient\n";
                        cout << "2. View Patient Details\n";
                        cout << "3. Update Patient Information\n";
                        cout << "4. Delete Patient Record\n";
                        cout << "5. Search Patient by Name\n";
                        cout << "6. List All Patients\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceP;

                        if (choiceP == 1) {
                            string id, name, contact, history;
                            int age;
                            cout << "Enter Patient ID: "; cin >> id;
                            cout << "Enter Name: "; cin >> name;
                            cout << "Enter Age: "; cin >> age;
                            
                            if (!validateAge(age)) {
                                cout << "Invalid age! Must be between 1-150.\n";
                                continue;
                            }
                            
                            cout << "Enter Contact (11 digits): "; cin >> contact;
                            if (!validateContact(contact)) {
                                cout << "Invalid contact number!\n";
                                continue;
                            }
                            
                            cout << "Enter Medical History: "; cin >> history;

                            patients[patientCount++] = Patient(id, name, age, contact, history);
                            cout << "Patient added successfully!\n";
                        }
                        else if (choiceP == 2) {
                            string id;
                            cout << "Enter Patient ID to view: "; cin >> id;
                            bool found = false;
                            cout << left << setw(10) << "ID"
                                 << setw(20) << "Name"
                                 << setw(8) << "Age"
                                 << setw(15) << "Contact"
                                 << "History" << endl;
                            cout << string(70, '-') << endl;
                            
                            for (int i = 0; i < patientCount; i++) {
                                if (patients[i].getID() == id) {
                                    patients[i].display();
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Patient not found!\n";
                        }
                        else if (choiceP == 3) {
                            string id;
                            cout << "Enter Patient ID to update: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < patientCount; i++) {
                                if (patients[i].getID() == id) {
                                    string name, contact, history;
                                    int age;
                                    cout << "Enter New Name: "; cin >> name;
                                    cout << "Enter New Age: "; cin >> age;
                                    cout << "Enter New Contact: "; cin >> contact;
                                    cout << "Enter New Medical History: "; cin >> history;

                                    patients[i].setName(name);
                                    patients[i].setAge(age);
                                    patients[i].setContact(contact);
                                    patients[i].setMedicalHistory(history);

                                    cout << "Patient updated successfully!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Patient not found!\n";
                        }
                        else if (choiceP == 4) {
                            string id;
                            cout << "Enter Patient ID to delete: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < patientCount; i++) {
                                if (patients[i].getID() == id) {
                                    for (int j = i; j < patientCount - 1; j++) {
                                        patients[j] = patients[j + 1];
                                    }
                                    patientCount--;
                                    cout << "Patient deleted successfully!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Patient not found!\n";
                        }
                        else if (choiceP == 5) {
                            string name;
                            cout << "Enter Name to search: "; cin >> name;
                            bool found = false;
                            for (int i = 0; i < patientCount; i++) {
                                if (patients[i].getName() == name) {
                                    patients[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No patient found with this name.\n";
                        }
                        else if (choiceP == 6) {
                            if (patientCount == 0) {
                                cout << "No patients registered.\n";
                            } else {
                                cout << left << setw(10) << "ID"
                                     << setw(20) << "Name"
                                     << setw(8) << "Age"
                                     << setw(15) << "Contact"
                                     << "History" << endl;
                                cout << string(70, '-') << endl;
                                for (int i = 0; i < patientCount; i++) {
                                    patients[i].display();
                                }
                            }
                        }
                    } while (choiceP != 0);
                    break;
                }
                
                case 2: { // Doctor Management
                    int choiceD;
                    do {
                        cout << "\n===== DOCTOR MANAGEMENT MENU =====\n";
                        cout << "1. Add New Doctor\n";
                        cout << "2. View Doctor Details\n";
                        cout << "3. Update Doctor Information\n";
                        cout << "4. Delete Doctor Record\n";
                        cout << "5. Search Doctor by Specialization\n";
                        cout << "6. List All Doctors\n";
                        cout << "7. Check Doctor Availability\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceD;

                        if (choiceD == 1) {
                            string id, name, spec, contact;
                            cout << "Enter Doctor ID: "; cin >> id;
                            cout << "Enter Name: "; cin >> name;
                            cout << "Enter Specialization: "; cin >> spec;
                            cout << "Enter Contact: "; cin >> contact;

                            if (!validateContact(contact)) {
                                cout << "Invalid contact number!\n";
                                continue;
                            }

                            doctors[doctorCount++] = Doctor(id, name, spec, contact);
                            cout << "Doctor added successfully!\n";
                        }
                        else if (choiceD == 2) {
                            string id;
                            cout << "Enter Doctor ID to view: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < doctorCount; i++) {
                                if (doctors[i].getID() == id) {
                                    doctors[i].display();
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Doctor not found!\n";
                        }
                        else if (choiceD == 3) {
                            string id;
                            cout << "Enter Doctor ID to update: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < doctorCount; i++) {
                                if (doctors[i].getID() == id) {
                                    string name, spec, contact;
                                    cout << "Enter New Name: "; cin >> name;
                                    cout << "Enter New Specialization: "; cin >> spec;
                                    cout << "Enter New Contact: "; cin >> contact;

                                    doctors[i].setName(name);
                                    doctors[i].setSpecialization(spec);
                                    doctors[i].setContact(contact);
                                    cout << "Doctor updated successfully!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Doctor not found!\n";
                        }
                        else if (choiceD == 4) {
                            string id;
                            cout << "Enter Doctor ID to delete: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < doctorCount; i++) {
                                if (doctors[i].getID() == id) {
                                    for (int j = i; j < doctorCount - 1; j++) {
                                        doctors[j] = doctors[j + 1];
                                    }
                                    doctorCount--;
                                    cout << "Doctor deleted successfully!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Doctor not found!\n";
                        }
                        else if (choiceD == 5) {
                            string spec;
                            cout << "Enter Specialization to search: "; cin >> spec;
                            bool found = false;
                            for (int i = 0; i < doctorCount; i++) {
                                if (doctors[i].getSpecialization() == spec) {
                                    doctors[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No doctors found with this specialization.\n";
                        }
                        else if (choiceD == 6) {
                            if (doctorCount == 0) {
                                cout << "No doctors registered.\n";
                            } else {
                                cout << left << setw(10) << "ID"
                                     << setw(20) << "Name"
                                     << setw(20) << "Specialization"
                                     << setw(15) << "Contact"
                                     << "Status" << endl;
                                cout << string(75, '-') << endl;
                                for (int i = 0; i < doctorCount; i++) {
                                    doctors[i].display();
                                }
                            }
                        }
                        else if (choiceD == 7) {
                            string id;
                            cout << "Enter Doctor ID: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < doctorCount; i++) {
                                if (doctors[i].getID() == id) {
                                    cout << "Doctor " << doctors[i].getName() << " is "
                                         << (doctors[i].isAvailable() ? "Available" : "Busy")
                                         << " (Appointments: " << doctors[i].getAppointmentCount() << ")" << endl;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Doctor not found!\n";
                        }
                    } while (choiceD != 0);
                    break;
                }
                
                case 3: { // Appointment Management
                    int choiceA;
                    do {
                        cout << "\n===== APPOINTMENT MANAGEMENT MENU =====\n";
                        cout << "1. Schedule Appointment\n";
                        cout << "2. View Appointment Details\n";
                        cout << "3. Reschedule Appointment\n";
                        cout << "4. Cancel Appointment\n";
                        cout << "5. List Patient Appointments\n";
                        cout << "6. List Doctor Appointments\n";
                        cout << "7. View Daily Schedule\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceA;

                        if (choiceA == 1) {
                            string id, pid, did, date, time;
                            cout << "Enter Appointment ID: "; cin >> id;
                            cout << "Enter Patient ID: "; cin >> pid;
                            cout << "Enter Doctor ID: "; cin >> did;
                            cout << "Enter Date (DD-MM-YYYY): "; cin >> date;
                            
                            if (!validateDate(date)) {
                                cout << "Invalid date format! Use DD-MM-YYYY\n";
                                continue;
                            }
                            
                            cout << "Enter Time: "; cin >> time;

                            Patient* p = NULL;
                            Doctor* d = NULL;

                            for (int i = 0; i < patientCount; i++)
                                if (patients[i].getID() == pid) p = &patients[i];

                            for (int i = 0; i < doctorCount; i++)
                                if (doctors[i].getID() == did) d = &doctors[i];

                            if (p && d && d->isAvailable()) {
                                appointments[appointmentCount++] = Appointment(id, p, d, date, time);
                                cout << "Appointment scheduled successfully!\n";
                            } else if (!p) {
                                cout << "Patient not found!\n";
                            } else if (!d) {
                                cout << "Doctor not found!\n";
                            } else {
                                cout << "Doctor is not available at this time!\n";
                            }
                        }
                        else if (choiceA == 2) {
                            string id;
                            cout << "Enter Appointment ID: "; cin >> id;
                            bool found = false;
                            cout << left << setw(10) << "ID"
                                 << setw(20) << "Patient"
                                 << setw(20) << "Doctor"
                                 << setw(12) << "Date"
                                 << "Time" << endl;
                            cout << string(72, '-') << endl;
                            
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getID() == id) {
                                    appointments[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "Appointment not found!\n";
                        }
                        else if (choiceA == 3) {
                            string id, newDate, newTime;
                            cout << "Enter Appointment ID: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getID() == id) {
                                    cout << "Enter New Date (DD-MM-YYYY): "; cin >> newDate;
                                    cout << "Enter New Time: "; cin >> newTime;
                                    appointments[i].setDate(newDate);
                                    appointments[i].setTime(newTime);
                                    cout << "Appointment rescheduled successfully!\n";
                                    found = true;
                                }
                            }
                            if (!found) cout << "Appointment not found!\n";
                        }
                        else if (choiceA == 4) {
                            string id;
                            cout << "Enter Appointment ID: "; cin >> id;
                            bool found = false;
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getID() == id) {
                                    for (int j = i; j < appointmentCount - 1; j++)
                                        appointments[j] = appointments[j + 1];
                                    appointmentCount--;
                                    cout << "Appointment cancelled successfully!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Appointment not found!\n";
                        }
                        else if (choiceA == 5) {
                            string pid;
                            cout << "Enter Patient ID: "; cin >> pid;
                            bool found = false;
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getPatient()->getID() == pid) {
                                    appointments[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No appointments found for this patient.\n";
                        }
                        else if (choiceA == 6) {
                            string did;
                            cout << "Enter Doctor ID: "; cin >> did;
                            bool found = false;
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getDoctor()->getID() == did) {
                                    appointments[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No appointments found for this doctor.\n";
                        }
                        else if (choiceA == 7) {
                            string date;
                            cout << "Enter Date (DD-MM-YYYY): "; cin >> date;
                            bool found = false;
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getDate() == date) {
                                    appointments[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No appointments found for this date.\n";
                        }
                    } while (choiceA != 0);
                    break;
                }
                
                case 4: { // Medical Records Management
                    int choiceMR;
                    do {
                        cout << "\n===== MEDICAL RECORDS MANAGEMENT MENU =====\n";
                        cout << "1. Add Medical Record\n";
                        cout << "2. View Medical History (by Patient)\n";
                        cout << "3. Update Medical Record\n";
                        cout << "4. Search Medical Records (by Diagnosis)\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceMR;

                        if (choiceMR == 1) {
                            string rid, pid, diagnosis, treatment, prescription, date;
                            cout << "Enter Record ID: "; cin >> rid;
                            cout << "Enter Patient ID: "; cin >> pid;
                            cout << "Enter Diagnosis: "; cin >> diagnosis;
                            cout << "Enter Treatment: "; cin >> treatment;
                            cout << "Enter Prescription: "; cin >> prescription;
                            cout << "Enter Date (DD-MM-YYYY): "; cin >> date;

                            Patient* p = NULL;
                            for (int i = 0; i < patientCount; i++) {
                                if (patients[i].getID() == pid) {
                                    p = &patients[i];
                                    break;
                                }
                            }

                            if (p) {
                                records[recordCount++] = MedicalRecord(rid, p, diagnosis, treatment, prescription, date);
                                cout << "Medical record added successfully!\n";
                            } else {
                                cout << "Patient not found!\n";
                            }
                        }
                        else if (choiceMR == 2) {
                            string pid;
                            cout << "Enter Patient ID: "; cin >> pid;
                            cout << left << setw(10) << "RecID"
                                 << setw(20) << "Patient"
                                 << setw(15) << "Diagnosis"
                                 << setw(20) << "Treatment"
                                 << setw(20) << "Prescription"
                                 << "Date" << endl;
                            cout << string(105, '-') << endl;

                            bool found = false;
                            for (int i = 0; i < recordCount; i++) {
                                if (records[i].getPatient()->getID() == pid) {
                                    records[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No records found for this patient.\n";
                        }
                        else if (choiceMR == 3) {
                            string rid;
                            cout << "Enter Record ID to update: "; cin >> rid;
                            bool found = false;
                            for (int i = 0; i < recordCount; i++) {
                                if (records[i].getRecordID() == rid) {
                                    string diagnosis, treatment, prescription;
                                    cout << "Enter New Diagnosis: "; cin >> diagnosis;
                                    cout << "Enter New Treatment: "; cin >> treatment;
                                    cout << "Enter New Prescription: "; cin >> prescription;

                                    records[i].setDiagnosis(diagnosis);
                                    records[i].setTreatment(treatment);
                                    records[i].setPrescription(prescription);

                                    cout << "Medical record updated successfully!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Record not found!\n";
                        }
                        else if (choiceMR == 4) {
                            string diagnosis;
                            cout << "Enter Diagnosis to search: "; cin >> diagnosis;
                            bool found = false;
                            for (int i = 0; i < recordCount; i++) {
                                if (records[i].getDiagnosis() == diagnosis) {
                                    records[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No records found with this diagnosis.\n";
                        }
                    } while (choiceMR != 0);
                    break;
                }
                
                case 5: { // Billing Management
                    int choiceB;
                    do {
                        cout << "\n===== BILLING MANAGEMENT MENU =====\n";
                        cout << "1. Generate Bill\n";
                        cout << "2. View Bill Details\n";
                        cout << "3. Process Payment\n";
                        cout << "4. View Payment History\n";
                        cout << "5. Calculate Total Revenue\n";
                        cout << "6. List Pending Bills\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceB;

                        if (choiceB == 1) {
                            string billID, pid;
                            double c, m, t;

                            cout << "Enter Bill ID: "; cin >> billID;
                            cout << "Enter Patient ID: "; cin >> pid;
                            cout << "Enter Consultation Fee: "; cin >> c;
                            cout << "Enter Medicine Cost: "; cin >> m;
                            cout << "Enter Test Cost: "; cin >> t;

                            if (c < 0 || m < 0 || t < 0) {
                                cout << "Costs cannot be negative!\n";
                                continue;
                            }

                            Patient* p = NULL;
                            for (int i = 0; i < patientCount; i++) {
                                if (patients[i].getID() == pid) {
                                    p = &patients[i];
                                    break;
                                }
                            }

                            if (p) {
                                bills[billCount++] = Bill(billID, p, c, m, t);
                                cout << "Bill generated successfully!\n";
                            } else {
                                cout << "Patient not found!\n";
                            }
                        }
                        else if (choiceB == 2) {
                            string id;
                            cout << "Enter Bill ID: "; cin >> id;
                            bool found = false;

                            cout << left << setw(10) << "BillID"
                                 << setw(20) << "Patient"
                                 << setw(12) << "Consult"
                                 << setw(12) << "Medicine"
                                 << setw(12) << "Test"
                                 << setw(12) << "Total"
                                 << setw(12) << "Paid"
                                 << "Pending" << endl;
                            cout << string(100, '-') << endl;

                            for (int i = 0; i < billCount; i++) {
                                if (bills[i].getBillID() == id) {
                                    bills[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "Bill not found!\n";
                        }
                        else if (choiceB == 3) {
                            string id, date;
                            double amount;
                            cout << "Enter Bill ID: "; cin >> id;
                            cout << "Enter Payment Amount: "; cin >> amount;
                            cout << "Enter Payment Date (DD-MM-YYYY): "; cin >> date;

                            if (amount <= 0) {
                                cout << "Payment amount must be positive!\n";
                                continue;
                            }

                            bool found = false;
                            for (int i = 0; i < billCount; i++) {
                                if (bills[i].getBillID() == id) {
                                    if (bills[i].getPending() >= amount) {
                                        bills[i].processPayment(amount, date);
                                        totalRevenue += amount;
                                        cout << "Payment processed successfully!\n";
                                    } else {
                                        cout << "Payment amount exceeds pending balance!\n";
                                    }
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "Bill not found!\n";
                        }
                        else if (choiceB == 4) {
                            string pid;
                            cout << "Enter Patient ID: "; cin >> pid;
                            bool found = false;
                            for (int i = 0; i < billCount; i++) {
                                if (bills[i].getPatient()->getID() == pid) {
                                    bills[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No bills found for this patient.\n";
                        }
                        else if (choiceB == 5) {
                            double totalPaid = 0;
                            double totalPending = 0;
                            
                            for (int i = 0; i < billCount; i++) {
                                totalPaid += bills[i].getPaid();
                                totalPending += bills[i].getPending();
                            }
                            
                            cout << "\n===== FINANCIAL SUMMARY =====\n";
                            cout << "Total Revenue Collected: Rs. " << totalPaid << endl;
                            cout << "Total Pending Amount: Rs. " << totalPending << endl;
                            cout << "Total Bills Generated: " << billCount << endl;
                        }
                        else if (choiceB == 6) {
                            cout << "\n===== PENDING BILLS =====\n";
                            bool found = false;
                            for (int i = 0; i < billCount; i++) {
                                if (bills[i].getPending() > 0) {
                                    bills[i].display();
                                    found = true;
                                }
                            }
                            if (!found) cout << "No pending bills.\n";
                        }
                    } while (choiceB != 0);
                    break;
                }
                
                case 6: { // Department Management
                    int choiceDept;
                    do {
                        cout << "\n===== DEPARTMENT MANAGEMENT MENU =====\n";
                        cout << "1. Add Department\n";
                        cout << "2. Assign Doctor to Department\n";
                        cout << "3. View Department Details\n";
                        cout << "4. List All Departments\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceDept;

                        if (choiceDept == 1) {
                            string id, name;
                            cout << "Enter Department ID: "; cin >> id;
                            cout << "Enter Department Name: "; cin >> name;

                            departments[deptCount++] = Department(id, name);
                            cout << "Department added successfully!\n";
                        }
                        else if (choiceDept == 2) {
                            string deptID, docID;
                            cout << "Enter Department ID: "; cin >> deptID;
                            cout << "Enter Doctor ID: "; cin >> docID;

                            Department* deptPtr = NULL;
                            Doctor* docPtr = NULL;

                            for (int i = 0; i < deptCount; i++)
                                if (departments[i].getDeptID() == deptID)
                                    deptPtr = &departments[i];

                            for (int i = 0; i < doctorCount; i++)
                                if (doctors[i].getID() == docID)
                                    docPtr = &doctors[i];

                            if (deptPtr && docPtr)
                                deptPtr->assignDoctor(docPtr);
                            else if (!deptPtr)
                                cout << "Department not found!\n";
                            else
                                cout << "Doctor not found!\n";
                        }
                        else if (choiceDept == 3) {
                            string deptID;
                            cout << "Enter Department ID: "; cin >> deptID;
                            bool found = false;

                            for (int i = 0; i < deptCount; i++) {
                                if (departments[i].getDeptID() == deptID) {
                                    departments[i].display();
                                    found = true;
                                    break;
                                }
                            }

                            if (!found) cout << "Department not found!\n";
                        }
                        else if (choiceDept == 4) {
                            if (deptCount == 0) {
                                cout << "No departments available.\n";
                            } else {
                                for (int i = 0; i < deptCount; i++) {
                                    cout << "\n-------------------------\n";
                                    departments[i].display();
                                }
                            }
                        }
                    } while (choiceDept != 0);
                    break;
                }
                
                case 7: { // Reports & Analytics
                    int choiceRA;
                    do {
                        cout << "\n===== REPORTING & ANALYTICS MENU =====\n";
                        cout << "1. Patient Summary Report\n";
                        cout << "2. Doctor Performance Report\n";
                        cout << "3. Financial Summary Report\n";
                        cout << "4. Appointment Statistics\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter choice: ";
                        cin >> choiceRA;

                        if (choiceRA == 1) {
                            cout << "\n===== PATIENT SUMMARY REPORT =====\n";
                            cout << "Total Patients: " << patientCount << endl;
                            cout << left << setw(10) << "ID"
                                 << setw(20) << "Name"
                                 << setw(8) << "Age"
                                 << "Contact" << endl;
                            cout << string(50, '-') << endl;
                            
                            for (int i = 0; i < patientCount; i++) {
                                cout << left << setw(10) << patients[i].getID()
                                     << setw(20) << patients[i].getName()
                                     << setw(8) << patients[i].getAge()
                                     << patients[i].getContact() << endl;
                            }
                        }
                        else if (choiceRA == 2) {
                            cout << "\n===== DOCTOR PERFORMANCE REPORT =====\n";
                            cout << left << setw(20) << "Doctor Name"
                                 << setw(20) << "Specialization"
                                 << "Appointments" << endl;
                            cout << string(50, '-') << endl;
                            
                            for (int i = 0; i < doctorCount; i++) {
                                cout << left << setw(20) << doctors[i].getName()
                                     << setw(20) << doctors[i].getSpecialization()
                                     << doctors[i].getAppointmentCount() << endl;
                            }
                        }
                        else if (choiceRA == 3) {
                            double totalPaid = 0;
                            double totalPending = 0;
                            int paidCount = 0, pendingCount = 0;
                            
                            for (int i = 0; i < billCount; i++) {
                                totalPaid += bills[i].getPaid();
                                totalPending += bills[i].getPending();
                                if (bills[i].getPaid() > 0) paidCount++;
                                if (bills[i].getPending() > 0) pendingCount++;
                            }
                            
                            cout << "\n===== FINANCIAL SUMMARY REPORT =====\n";
                            cout << "Total Revenue: Rs. " << totalPaid << endl;
                            cout << "Total Pending: Rs. " << totalPending << endl;
                            cout << "Paid Bills: " << paidCount << endl;
                            cout << "Pending Bills: " << pendingCount << endl;
                            cout << "Total Bills: " << billCount << endl;
                        }
                        else if (choiceRA == 4) {
                            string date;
                            cout << "Enter Date (DD-MM-YYYY): ";
                            cin >> date;

                            int count = 0;
                            for (int i = 0; i < appointmentCount; i++) {
                                if (appointments[i].getDate() == date)
                                    count++;
                            }

                            cout << "\n===== APPOINTMENT STATISTICS =====\n";
                            cout << "Date: " << date << endl;
                            cout << "Total Appointments: " << count << endl;
                            
                            if (count > 0) {
                                cout << "\nAppointment Details:\n";
                                for (int i = 0; i < appointmentCount; i++) {
                                    if (appointments[i].getDate() == date) {
                                        cout << "- " << appointments[i].getTime() 
                                             << " | Patient: " << appointments[i].getPatient()->getName()
                                             << " | Doctor: " << appointments[i].getDoctor()->getName() << endl;
                                    }
                                }
                            }
                        }
                    } while (choiceRA != 0);
                    break;
                }
                
                case 8: // Logout
                    running = false;
                    cout << "Logging out...\n";
                    break;
                    
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
        else if (loggedRole == "Doctor") {
            // Doctor menu implementation
            switch(mainChoice) {
                case 1: // View My Appointments
                    {
                        string doctorName;
                        cout << "Enter your name: ";
                        cin >> doctorName;
                        
                        cout << "\n===== MY APPOINTMENTS =====\n";
                        bool found = false;
                        for (int i = 0; i < appointmentCount; i++) {
                            if (appointments[i].getDoctor()->getName() == doctorName) {
                                appointments[i].display();
                                found = true;
                            }
                        }
                        if (!found) cout << "No appointments found.\n";
                    }
                    break;
                    
                case 2: // View Patient Medical Records
                    {
                        string pid;
                        cout << "Enter Patient ID: ";
                        cin >> pid;
                        
                        for (int i = 0; i < recordCount; i++) {
                            if (records[i].getPatient()->getID() == pid) {
                                records[i].display();
                            }
                        }
                    }
                    break;
                    
                case 3: // Update Medical Records
                    {
                        string rid;
                        cout << "Enter Record ID to update: ";
                        cin >> rid;
                        
                        for (int i = 0; i < recordCount; i++) {
                            if (records[i].getRecordID() == rid) {
                                string diagnosis, treatment, prescription;
                                cout << "Enter Diagnosis: "; cin >> diagnosis;
                                cout << "Enter Treatment: "; cin >> treatment;
                                cout << "Enter Prescription: "; cin >> prescription;
                                
                                records[i].setDiagnosis(diagnosis);
                                records[i].setTreatment(treatment);
                                records[i].setPrescription(prescription);
                                cout << "Record updated!\n";
                                break;
                            }
                        }
                    }
                    break;
                    
                case 4: // Check Availability
                    {
                        string did;
                        cout << "Enter Doctor ID: ";
                        cin >> did;
                        
                        for (int i = 0; i < doctorCount; i++) {
                            if (doctors[i].getID() == did) {
                                cout << "Status: " 
                                     << (doctors[i].isAvailable() ? "Available" : "Busy") << endl;
                                break;
                            }
                        }
                    }
                    break;
                    
                case 5:
                    running = false;
                    break;
            }
        }
        else if (loggedRole == "Receptionist") {
            // Receptionist menu implementation
            switch(mainChoice) {
                case 1: // Register Patient
                    {
                        string id, name, contact, history;
                        int age;
                        cout << "Enter Patient ID: "; cin >> id;
                        cout << "Enter Name: "; cin >> name;
                        cout << "Enter Age: "; cin >> age;
                        cout << "Enter Contact: "; cin >> contact;
                        cout << "Enter Medical History: "; cin >> history;
                        
                        patients[patientCount++] = Patient(id, name, age, contact, history);
                        cout << "Patient registered successfully!\n";
                    }
                    break;
                    
                case 2: // View Patient
                    {
                        string id;
                        cout << "Enter Patient ID: "; cin >> id;
                        for (int i = 0; i < patientCount; i++) {
                            if (patients[i].getID() == id) {
                                patients[i].display();
                                break;
                            }
                        }
                    }
                    break;
                    
                case 3: // Schedule Appointment
                    {
                        string id, pid, did, date, time;
                        cout << "Enter Appointment ID: "; cin >> id;
                        cout << "Enter Patient ID: "; cin >> pid;
                        cout << "Enter Doctor ID: "; cin >> did;
                        cout << "Enter Date: "; cin >> date;
                        cout << "Enter Time: "; cin >> time;

                        Patient* p = NULL;
                        Doctor* d = NULL;

                        for (int i = 0; i < patientCount; i++)
                            if (patients[i].getID() == pid) p = &patients[i];

                        for (int i = 0; i < doctorCount; i++)
                            if (doctors[i].getID() == did) d = &doctors[i];

                        if (p && d && d->isAvailable()) {
                            appointments[appointmentCount++] = Appointment(id, p, d, date, time);
                            cout << "Appointment scheduled!\n";
                        } else {
                            cout << "Cannot schedule appointment.\n";
                        }
                    }
                    break;
                    
                case 4: // View Appointments
                    {
                        string date;
                        cout << "Enter Date: "; cin >> date;
                        for (int i = 0; i < appointmentCount; i++) {
                            if (appointments[i].getDate() == date) {
                                appointments[i].display();
                            }
                        }
                    }
                    break;
                    
                case 5: // Generate Bill
                    {
                        string billID, pid;
                        double c, m, t;
                        cout << "Enter Bill ID: "; cin >> billID;
                        cout << "Enter Patient ID: "; cin >> pid;
                        cout << "Consultation Fee: "; cin >> c;
                        cout << "Medicine Cost: "; cin >> m;
                        cout << "Test Cost: "; cin >> t;

                        Patient* p = NULL;
                        for (int i = 0; i < patientCount; i++)
                            if (patients[i].getID() == pid) p = &patients[i];

                        if (p) {
                            bills[billCount++] = Bill(billID, p, c, m, t);
                            cout << "Bill generated!\n";
                        }
                    }
                    break;
                    
                case 6: // View Bills
                    {
                        string pid;
                        cout << "Enter Patient ID: "; cin >> pid;
                        for (int i = 0; i < billCount; i++) {
                            if (bills[i].getPatient()->getID() == pid) {
                                bills[i].display();
                            }
                        }
                    }
                    break;
                    
                case 7: // Process Payment
                    {
                        string id, date;
                        double amount;
                        cout << "Enter Bill ID: "; cin >> id;
                        cout << "Amount: "; cin >> amount;
                        cout << "Date: "; cin >> date;
                        
                        for (int i = 0; i < billCount; i++) {
                            if (bills[i].getBillID() == id) {
                                bills[i].processPayment(amount, date);
                                totalRevenue += amount;
                                cout << "Payment processed!\n";
                                break;
                            }
                        }
                    }
                    break;
                    
                case 8:
                    running = false;
                    break;
            }
        }
    }

    // ===================== CLEANUP: FREE DYNAMIC MEMORY =====================
    cout << "\nCleaning up resources...\n";
    
    delete[] patients;
    delete[] doctors;
    delete[] appointments;
    delete[] records;
    delete[] bills;
    delete[] departments;
    
    cout << "Memory freed successfully. System shutting down.\n";
    cout << "Thank you for using Healthcare Patient Management System!\n";

    return 0;
}
