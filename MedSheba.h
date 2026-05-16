#ifndef MEDSHEBA_H
#define MEDSHEBA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

// =====================================
// Patient Structure
// =====================================

struct Patient {

    string name;
    int age;
    string gender;

    double bp;
    double temp;
    double sugar;
    double oxygen;
    double heartRate;

    double weight;
    double height;

    string priority;
    string status;

    vector<string> medications;
    vector<string> reports;
};

// =====================================
// Global Variables
// =====================================

extern map<string, Patient> patientRegistry;
extern vector<string> activityLog;

// =====================================
// First 25 Functions
// =====================================

void ShebaShuru();
void ShebaShesh();
double Shuno();
void Dekhao(string msg);
void RogiNao(string name);
void RogiDao(string name);
void MoneKoro(string task);
void ShomoyNao();
void TarikhNao();
void Jodi(bool cond);
void Othoba();
void Barbar(int times);
void Kaj();
void Ferot();
void Thamo();
void Dhiro(int sec);
void MochePelo();
int GonnaKaj();
void Agrodhikaro(string name, string p);
void Sotorko(string msg);
void LipiBodho(string entry);
void Sesh();
void OushodhLekho(string n, string m);
double ObosthaDekho(string n);
void Jekono();

// =====================================
// Additional 25 Functions
// =====================================

void RoktoChap(string n);
void TapmatraMapo(string n);
void SugarMapo(string n);
void OksijenMapo(string n);
void NariDekho(string n);

void OjonNao(string n);
void UchotaNao(string n);

void ReportJog(string n, string report);
void ReportDekho(string n);

void BillBanano(string n);
void TakaNao(double amount);

void CabinDao(string n);
void AmbulanceDako();

void RogiBiday(string n);

void ByayamDao(string n);
void GhumDekho(string n);

void VaccineDao(string n);

void TestKoro(string n);

void ChokhDekho(string n);
void KanDekho(string n);
void DaatDekho(string n);

void OperationShuru();
void OperationShesh();

void StaffDekho();

void DatabaseSave();

#endif
