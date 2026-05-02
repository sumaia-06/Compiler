#ifndef MEDSHEBA_H
#define MEDSHEBA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>

// Patient Data Structure
struct Patient {
    std::string name;
    double bp;
    std::string priority;
    std::vector<std::string> medications;
};

// Global data stores for the Interpreter
extern std::map<std::string, Patient> patientRegistry;
extern std::vector<std::string> activityLog;

// 25 Core Function Prototypes[cite: 1, 2]
void ShebaShuru();                  // 1. Start Session
void ShebaShesh();                  // 2. Stop Session
double Shuno();                     // 3. Input
void Dekhao(std::string msg);       // 4. Output
void RogiNao(std::string name);     // 5. Save Patient
void RogiDao(std::string name);     // 6. Get Record
void MoneKoro(std::string task);    // 7. Remind Meds
void ShomoyNao();                   // 8. Get Time
void TarikhNao();                   // 9. Get Date
void Jodi(bool cond);               // 10. If
void Othoba();                      // 11. Else
void Barbar(int times);             // 12. Loop
void Kaj();                         // 13. Define Function
void Ferot();                       // 14. Return
void Thamo();                       // 15. Break
void Dhiro(int sec);                // 16. Wait/Delay
void MochePelo();                   // 17. Clear Data
int GonnaKaj();                    // 18. Count Patients
void Agrodhikaro(std::string name, std::string p); // 19. Set Priority
void Sotorko(std::string msg);      // 20. Alert
void LipiBodho(std::string entry);  // 21. Log Event
void Sesh();                        // 22. End Block
void OushodhLekho(std::string n, std::string m); // 23. Prescribe
double ObosthaDekho(std::string n); // 24. Check Vitals
void Jekono();                      // 25. Random Staff

#endif
