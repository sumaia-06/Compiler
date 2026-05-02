## README: MedShebaLang Compiler

### **Project Overview**
**MedShebaLang** (Bengali: মেড সেবা) is a domain-specific language (DSL) designed for healthcare automation and patient monitoring. Developed for the **CSE 352: Compiler LAB** course at the **University of Information Technology and Sciences (UITS)**, this project implements a full compiler pipeline—including a Lexer, Parser, and Interpreter—using C++17 and Flex.

The language simplifies medical scripting by mapping complex clinical operations to intuitive, Bengali-inspired keywords.

---

### **Technical Specifications**
*   **Language Name:** MedShebaLang
*   **File Extension:** `.msl`
*   **Implementation Language:** C++17
*   **Lexical Tool:** Flex (Fast Lexical Analyzer)
*   **Target Domain:** Hospital Management & Medical Automation

---

### **Features & Functions**
The compiler supports **25 unique functions** specifically modeled for the medical domain:

| Category | Functions |
| :--- | :--- |
| **System Control** | `ShebaShuru()` (Start), `ShebaShesh()` (Stop)|
| **Patient Management** | `RogiNao()` (Admit), `RogiDao()` (Get Record), `BidayDao()` (Discharge)|
| **Clinical Ops** | `OushodhLekho()` (Prescribe), `ObosthaDekho()` (Check Vitals), `Porikkha()` (Lab Test) |
| **Monitoring** | `Agrodhikaro()` (Set Priority), `Sotorko()` (Emergency Alert), `LipiBodho()` (Log)|
| **Logic & Flow** | `Jodi()` (If), `Othoba()` (Else), `Barbar()` (Loop), `Sesh()` (End Block) |

---

### **Installation & Compilation**

#### **Prerequisites**
1.  **Flex:** Install via `sudo apt-get install flex` (Linux) or download WinFlex for Windows.
2.  **G++ Compiler:** Ensure your GCC version supports C++17 standards.

#### **Building the Project**
1.  **Generate the Lexer:**
    ```bash
    flex lexer.l
    ```
    This produces the `lex.yy.c` file which contains the tokenization logic.

2.  **Compile the Source:**
    ```bash
    g++ -std=c++17 compiler.cpp lex.yy.c -o MedShebaCompiler
    ```
    This links the Flex-generated code with the medical logic in `compiler.cpp`.

3.  **Run a Program:**
    ```bash
    ./MedShebaCompiler
    ```

---

### **Example Code (.msl)**
```cpp
ShebaShuru()    
RogiNao "Patient_A"
bp = Shuno()    

Jodi bp Boro 140
    Agrodhikaro("Patient_A", "EMERGENCY")
    Sotorko "High BP Alert!"
Nahole
    Dekhao "Patient is stable"
Sesh

ShebaShesh()
```

---

### **Contributor Information**
*   **Student Name:** Sumaia Bintey Ismail
*   **Student ID:** 0432320005101103
*   **Institution:** University of Information Technology and Sciences (UITS)
*   **Submitted To:** Md. Tasnin Tanvir, Dept. of CSE, UITS
```
