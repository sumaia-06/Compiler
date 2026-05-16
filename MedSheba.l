%option noyywrap c++

%{
#include "medsheba.h"
using namespace std;
%}

%%

"ShebaShuru"      { return 1; }
"ShebaShesh"      { return 2; }
"RogiNao"         { return 3; }
"RogiDao"         { return 4; }
"OushodhLekho"    { return 5; }
"RoktoChap"       { return 6; }
"TapmatraMapo"    { return 7; }
"SugarMapo"       { return 8; }
"OksijenMapo"     { return 9; }
"NariDekho"       { return 10; }

"BillBanano"      { return 11; }
"TakaNao"         { return 12; }
"CabinDao"        { return 13; }
"AmbulanceDako"   { return 14; }

"ReportJog"       { return 15; }
"ReportDekho"     { return 16; }

"OperationShuru"  { return 17; }
"OperationShesh"  { return 18; }

"RogiBiday"       { return 19; }

[a-zA-Z_][a-zA-Z0-9_]* { return 100; }

[0-9]+(\.[0-9]+)? { return 101; }

\"[^\"]*\"        { return 102; }

[ \t\n]+          ;

. {
    cout << "Unknown Token: " << yytext << endl;
}

%%
