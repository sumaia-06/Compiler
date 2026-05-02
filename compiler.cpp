#include "medsheba.h"
#include <thread>
#include <chrono>
#include <algorithm>

// Definitions
std::map<std::string, Patient> patientRegistry;
std::vector<std::string> activityLog;

void ShebaShuru() {
    std::cout << "--- MedShebaLang System v1.0 [Sumaia Bintey Ismail] ---\n";
    std::cout << "[INFO] Session Started.\n";
}

void ShebaShesh() {
    std::cout << "[INFO] Session Terminated. Data Saved.\n";
}

double Shuno() {
    double input;
    std::cout << "Input Required: ";
    std::cin >> input;
    return input;
}

void Dekhao(std::string msg) {
    std::cout << ">> OUTPUT: " << msg << "\n";
}

void RogiNao(std::string name) {
    patientRegistry[name] = {name, 0.0, "NORMAL", {}};
    std::cout << "[REGISTRY] Added patient: " << name << "\n";
}

void RogiDao(std::string name) {
    if (patientRegistry.count(name)) {
        std::cout << "[DATA] Patient: " << name << " | Status: " << patientRegistry[name].priority << "\n";
    }
}

void Agrodhikaro(std::string name, std::string p) {
    if (patientRegistry.count(name)) patientRegistry[name].priority = p;
}

void Sotorko(std::string msg) {
    std::cout << "!!! EMERGENCY ALERT: " << msg << " !!!\n";
}

void LipiBodho(std::string entry) {
    activityLog.push_back(entry);
}

void Dhiro(int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void TarikhNao() {
    time_t now = time(0);
    std::cout << "Current Date: " << ctime(&now);
}

void ShomoyNao() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << "\n";
}

void OushodhLekho(std::string n, std::string m) {
    if (patientRegistry.count(n)) patientRegistry[n].medications.push_back(m);
}

double ObosthaDekho(std::string n) {
    return patientRegistry.count(n) ? patientRegistry[n].bp : 0.0;
}

void MochePelo() {
    patientRegistry.clear();
    std::cout << "[CLEAN] All temporary logs cleared.\n";
}

int GonnaKaj() {
    return patientRegistry.size();
}

void Jekono() {
    std::vector<std::string> staff = {"Dr. Rahim", "Nurse Sumaia", "Dr. Karim"};
    std::cout << "On-Duty: " << staff[rand() % staff.size()] << "\n";
}

// Logic Blocks (Simulated for this implementation)
void Jodi(bool cond) { if(cond) std::cout << "[LOGIC] Condition Met.\n"; }
void Sesh() { /* End block */ }
void Thamo() { /* Break loop */ }

// --- MAIN RUNNER ---
int main() {
    srand(time(0));

    // Simulate a program execution based on the proposal sample
    ShebaShuru();

    RogiNao("Rogi_001");
    Dekhao("Enter Blood Pressure for Patient:");
    double bp = Shuno();

    LipiBodho("Recorded BP for Rogi_001");

    if (bp > 140) {
        Agrodhikaro("Rogi_001", "EMERGENCY");
        Sotorko("High Blood Pressure detected!");
    } else {
        Dekhao("Patient is stable.");
    }

    TarikhNao();
    ShebaShesh();

    return 0;
}
