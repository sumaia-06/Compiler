#include "medsheba.h"

#include <thread>
#include <chrono>
#include <algorithm>
#include <cstdlib>

map<string, Patient> patientRegistry;
vector<string> activityLog;

// =====================================
// CORE FUNCTIONS
// =====================================

void ShebaShuru() {

    cout << "\n=====================================\n";
    cout << "   MedShebaLang Medical System\n";
    cout << "=====================================\n";
}

void ShebaShesh() {

    cout << "\n[INFO] Session Ended Successfully.\n";
}

double Shuno() {

    double x;
    cin >> x;
    return x;
}

void Dekhao(string msg) {

    cout << ">> " << msg << endl;
}

void RogiNao(string name) {

    Patient p;

    p.name = name;

    cout << "Enter Age: ";
    cin >> p.age;

    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, p.gender);

    p.priority = "NORMAL";
    p.status = "STABLE";

    patientRegistry[name] = p;

    cout << "[REGISTRY] Patient Added Successfully.\n";
}

void RogiDao(string name) {

    if(patientRegistry.count(name)) {

        Patient &p = patientRegistry[name];

        cout << "\n========== PATIENT INFO ==========\n";

        cout << "Name: " << p.name << endl;
        cout << "Age: " << p.age << endl;
        cout << "Gender: " << p.gender << endl;

        cout << "BP: " << p.bp << endl;
        cout << "Temp: " << p.temp << endl;
        cout << "Sugar: " << p.sugar << endl;
        cout << "Oxygen: " << p.oxygen << endl;
        cout << "Heart Rate: " << p.heartRate << endl;

        cout << "Priority: " << p.priority << endl;
        cout << "Status: " << p.status << endl;
    }
}

void MoneKoro(string task) {
    cout << "[REMINDER] " << task << endl;
}

void ShomoyNao() {

    time_t now = time(0);

    tm *ltm = localtime(&now);

    cout << "Time: "
         << ltm->tm_hour << ":"
         << ltm->tm_min << endl;
}

void TarikhNao() {

    time_t now = time(0);

    cout << ctime(&now);
}

void Jodi(bool cond) {

    if(cond)
        cout << "[LOGIC] Condition TRUE\n";
}

void Othoba() {
    cout << "[LOGIC] ELSE BLOCK\n";
}

void Barbar(int times) {

    for(int i=1;i<=times;i++)
        cout << "Loop: " << i << endl;
}

void Kaj() {
    cout << "[FUNCTION] New Function Block\n";
}

void Ferot() {
    cout << "[RETURN]\n";
}

void Thamo() {
    cout << "[BREAK]\n";
}

void Dhiro(int sec) {

    this_thread::sleep_for(chrono::seconds(sec));
}

void MochePelo() {

    patientRegistry.clear();

    cout << "[CLEAR] Database Cleared\n";
}

int GonnaKaj() {

    return patientRegistry.size();
}

void Agrodhikaro(string name, string p) {

    patientRegistry[name].priority = p;
}

void Sotorko(string msg) {

    cout << "!!! ALERT: " << msg << " !!!\n";
}

void LipiBodho(string entry) {

    activityLog.push_back(entry);
}

void Sesh() {
    cout << "[END BLOCK]\n";
}

void OushodhLekho(string n, string m) {

    patientRegistry[n].medications.push_back(m);

    cout << "[MEDICINE] Added.\n";
}

double ObosthaDekho(string n) {

    return patientRegistry[n].bp;
}

void Jekono() {

    vector<string> staff = {
        "Dr.Rahim",
        "Dr.Karim",
        "Nurse Sumaia"
    };

    cout << "Assigned Staff: "
         << staff[rand()%staff.size()]
         << endl;
}

// =====================================
// ADDITIONAL 25 FUNCTIONS
// =====================================

void RoktoChap(string n) {

    cout << "Enter BP: ";
    cin >> patientRegistry[n].bp;
}

void TapmatraMapo(string n) {

    cout << "Enter Temperature: ";
    cin >> patientRegistry[n].temp;
}

void SugarMapo(string n) {

    cout << "Enter Sugar Level: ";
    cin >> patientRegistry[n].sugar;
}

void OksijenMapo(string n) {

    cout << "Enter Oxygen Level: ";
    cin >> patientRegistry[n].oxygen;
}

void NariDekho(string n) {

    cout << "Enter Heart Rate: ";
    cin >> patientRegistry[n].heartRate;
}

void OjonNao(string n) {

    cout << "Enter Weight: ";
    cin >> patientRegistry[n].weight;
}

void UchotaNao(string n) {

    cout << "Enter Height: ";
    cin >> patientRegistry[n].height;
}

void ReportJog(string n, string report) {

    patientRegistry[n].reports.push_back(report);
}

void ReportDekho(string n) {

    for(string r : patientRegistry[n].reports)
        cout << "- " << r << endl;
}

void BillBanano(string n) {

    cout << "[BILL GENERATED] for "
         << n << endl;
}

void TakaNao(double amount) {

    cout << "Received: "
         << amount
         << " BDT\n";
}

void CabinDao(string n) {

    cout << n << " assigned to Cabin.\n";
}

void AmbulanceDako() {

    cout << "[EMS] Ambulance Called.\n";
}

void RogiBiday(string n) {

    patientRegistry[n].status = "DISCHARGED";

    cout << n << " discharged.\n";
}

void ByayamDao(string n) {

    cout << "Exercise Routine Assigned.\n";
}

void GhumDekho(string n) {

    cout << "Sleep monitored.\n";
}

void VaccineDao(string n) {

    cout << "Vaccination Completed.\n";
}

void TestKoro(string n) {

    cout << "Medical Test Completed.\n";
}

void ChokhDekho(string n) {

    cout << "Eye Checkup Complete.\n";
}

void KanDekho(string n) {

    cout << "Ear Checkup Complete.\n";
}

void DaatDekho(string n) {

    cout << "Dental Checkup Complete.\n";
}

void OperationShuru() {

    cout << "[OT] Operation Started.\n";
}

void OperationShesh() {

    cout << "[OT] Operation Finished.\n";
}

void StaffDekho() {

    cout << "Doctors Available: 5\n";
}

void DatabaseSave() {

    cout << "[DATABASE] Saved Successfully.\n";
}

// =====================================
// MAIN PROGRAM
// =====================================

int main() {

    srand(time(0));

    ShebaShuru();

    string patientName;

    cout << "\nEnter Patient Name: ";
    getline(cin, patientName);

    RogiNao(patientName);

    int choice;

    while(true) {

        cout << "\n========== MENU ==========\n";

        cout << "1. Input BP\n";
        cout << "2. Input Temperature\n";
        cout << "3. Input Sugar\n";
        cout << "4. Input Oxygen\n";
        cout << "5. Add Medicine\n";
        cout << "6. Add Report\n";
        cout << "7. Show Patient\n";
        cout << "8. Show Reports\n";
        cout << "9. Emergency Alert\n";
        cout << "10. Call Ambulance\n";
        cout << "11. Start Operation\n";
        cout << "12. Discharge Patient\n";
        cout << "13. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore();

        if(choice == 1) {

            RoktoChap(patientName);
        }

        else if(choice == 2) {

            TapmatraMapo(patientName);
        }

        else if(choice == 3) {

            SugarMapo(patientName);
        }

        else if(choice == 4) {

            OksijenMapo(patientName);
        }

        else if(choice == 5) {

            string med;

            cout << "Medicine Name: ";
            getline(cin, med);

            OushodhLekho(patientName, med);
        }

        else if(choice == 6) {

            string report;

            cout << "Report: ";
            getline(cin, report);

            ReportJog(patientName, report);
        }

        else if(choice == 7) {

            RogiDao(patientName);
        }

        else if(choice == 8) {

            ReportDekho(patientName);
        }

        else if(choice == 9) {

            Sotorko("Critical Condition");
        }

        else if(choice == 10) {

            AmbulanceDako();
        }

        else if(choice == 11) {

            OperationShuru();

            Dhiro(2);

            OperationShesh();
        }

        else if(choice == 12) {

            RogiBiday(patientName);
        }

        else if(choice == 13) {

            DatabaseSave();

            ShebaShesh();

            break;
        }

        else {

            cout << "Invalid Choice.\n";
        }
    }

    return 0;
}
