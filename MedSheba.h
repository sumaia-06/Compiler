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

// 25 Core Function Prototypes
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

//Diagnostics
void BpMapo(string n);             //Specifically measures Blood Pressure.
void Tapmatra(string n);           //Measures body temperature.
void NariCholo(string n);          //Measures pulse/heart rate.
void OjonNao(string n);            //Records patient weight.
void UchotaNao(string n);          //Records patient height.
void OksijenNao(string n);         //Measures oxygen saturation (SpO2).
void ShashGoti(string n);          //Measures respiratory rate.
void SugarMapo(string n);          //Records blood glucose levels.
void RoktoNao(string n);           //Orders a blood sample collection.
void UrinePorikkha(string n);      //Orders a urinalysis.
void ChobiTolo(string n);            //Requests an X-ray or imaging scan.
void HridoyLekho(string n);          //Orders an ECG/EKG.
void BrainDekho(string n);            //Orders an MRI or CT scan.
void ReportDao(string n);            //Uploads a completed lab report.
void ReportDekho(string n);            //Views patient test results.
void ChokherPorikkha(string n);        //Records vision test results.
void DantDekho(string n);                //Records dental checkup data.
void KanDekho(string n);                //Records ENT assessment.
void ChamraDekho(string n);            //Records dermatology assessment.
void Porikkha(string t);                //Initiates a generic diagnostic test

//Cardiology
void PulseDekho(string n);            //Detailed analysis of pulse waves.
void EcoKoro(string n);                //Performs an Echocardiogram.
void BlockKhujo(string n);            //Checks for arterial blockages.
void StentBoshao(string n);            //Records a stent placement procedure.
void HeartGoti(string n);            //Monitors long-term heart rhythm.

//Pharmacy
void StockDekho();                    //Checks pharmacy inventory levels.
void StockBhoro();                    //Updates inventory with new supplies.
void OushodhDao(string n);            //Marks a medication dose as administered.
void OushodhBondho(string n);          //Cancels an active prescription.
void DoseThikKoro(string n);            //Calculates dosage based on weight.
void ParshoProtikkria(string n);        //Logs a medication side effect.
void MatherBoma(string n);                //Checks for drug-to-drug interactions.
void Dokantat(string n);                //Generates a pharmacy-specific bill.
void Tikadan(string n);                //Records a vaccination.
    
//Surgery & OT
void OperationShuru();                   //Marks the start of a surgical procedure.
void OperationShesh();                    //Marks the end of a surgery.
void OgyanKoro(string n);                //Records anesthesia administration.
void KataChera(string n);                //Records surgical incision details.
void RaktoDao(string n);                //Records a blood transfusion.
void SilaKoro(string n);                //Records surgical stitching/sutures.
void AngoBad(string n);                 //Records an amputation procedure.

//Admin & Billing
void ShomoyDao(string n);                //"Schedules a consultation[cite: 1, 2]."
void SitKhali();                        //"Returns available hospital beds[cite: 1, 2]."
void BillBanalo(string n);                //Calculates the total patient bill.
void TkNao(double a);                    //Records a payment transaction.
void CabinBook(string n);                //Assigns a specific room or cabin.
void WardDekho();                        //Checks ward occupancy.
void StaffHajira();                       //Records staff attendance.
void DutyChart();                         //Assigns staff shifts.
void AmbulanceDako();                    //Requests emergency transport.
void ReferKoro(string n);                //Transfers patient to another hospital.
void ChedKoro(string n);                    //Cancels an appointment.
void ChhapaKoro();                        //Prints a physical prescription or bill.

//Wellness
void KhabarDao(string n);                    //Records patient dietary intake.
void GhumDekho(string n);                    //Tracks patient sleep hours.
void Byayom(string n);                        //Recommends physical therapy tasks.
void MatherObostha(string n);                //Records a mental health assessment.
void RogiKhujo(string n);                    //Searches for a patient record.
void BidayDao(string n);                     //Discharges a patient from the system.

//System/Logic
void Chalao();                            //Skips current loop iteration.
void Gordao();                            //Calculates average of vitals.
void Boroda();                            //Finds the maximum value in a dataset.
void Chotoda();                            //Finds the minimum value in a dataset.
void MathaKulao();                        //Resets the interpreter state.
void PuronoData(string n);                //Retrieves historical patient logs.
void FileKhulo();                           //Imports data from an external file.
void FileBondho();                        //Saves and closes the current file.
void SignalDao();                            //Sends a signal to a nurse station.
void VulDhoro();                            //Debugs the current script for errors.
void SothikKoro();                            //Auto-corrects script formatting.
void Nirapotta();                            //Encrypts patient sensitive data.
void BackUp();                             //Creates a backup of the registry.
void Update();                            //Synchronizes data with a server.
void Bondhu();                            //Allows multi-user collaboration mode.
void Sikkha();                            //Displays help documentation.
void Bhasha();                            //Switches interface language.
void Gati();                                //Measures script processing speed.
#endif
