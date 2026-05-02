%{
#include "medsheba.h"
#include <iostream>
#include <string>
%}

%%
"ShebaShuru"    { return 1; }
"ShebaShesh"    { return 2; }
"Shuno"         { return 3; }
"Dekhao"        { return 4; }
"RogiNao"       { return 5; }
"RogiDao"       { return 6; }
"MoneKoro"      { return 7; }
"ShomoyNao"     { return 8; }
"TarikhNao"     { return 9; }
"Jodi"          { return 10; }
"Othoba"        { return 11; }
"Barbar"        { return 12; }
"Kaj"           { return 13; }
"Ferot"         { return 14; }
"Thamo"         { return 15; }
"Dhiro"         { return 16; }
"MochePelo"     { return 17; }
"GonnaKaj"      { return 18; }
"Agrodhikaro"   { return 19; }
"Sotorko"       { return 20; }
"LipiBodho"     { return 21; }
"Sesh"          { return 22; }
"OushodhLekho"  { return 23; }
"ObosthaDekho"  { return 24; }
"Jekono"        { return 25; }

[0-9]+(\.[0-9]+)? { return 100; } // Numbers
[a-zA-Z_][a-zA-Z0-9_]* { return 101; } // Identifiers
\"[^\"]*\"      { return 102; } // Strings
[ \t\n]+        { /* Skip whitespace */ }
.               { std::cout << "Unknown: " << yytext << "\n"; }
%%

int yywrap() { return 1; }
