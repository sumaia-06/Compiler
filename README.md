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
   #### **C++ Compiler (`g++`) Verification & Setup Guide**
    This guide walks through verifying whether the GNU C++ compiler (`g++`) is active in your Windows environment and how to resolve the `'g++' is not recognized` error by configuring your system `PATH`.
    
    ---
    
    ## 1. Verify `g++` Installation
    
    ### **Step 1: Open Command Prompt**
    1. Press `Win + R` to open the **Run** dialog.
    2. Type `cmd` and press `Enter` (or click **OK**).
    * **Verification:** A terminal window opens displaying your user profile directory path (e.g., `C:\Users\<YourUsername>>`).
    
    ### Step 2: Check the Compiler Version
    In the terminal, run the following command:
    ```cmd
    g++ --version
    
    ```
    
    * **Success Output:** The terminal outputs version and build information:
    ```text
    g++ (MinGW-w64...) 13.2.0
    Copyright (C) 2023 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.
    
    ```
    
    
    * **Failure State:** If you receive:
    ```text
    'g++' is not recognized as an internal or external command, operable program or batch file.
    
    ```

    This indicates `g++` is either not installed or its `bin` directory is missing from your system's `PATH`. Proceed to [Section 2: Fix `PATH` Environment Variable](https://www.google.com/search?q=%232-fix-path-environment-variable).
    
    ### Step 3: Test Compiler Response
    
    In the terminal, run:
    
    ```cmd
    g++
    
    ```
    
    * **Success Verification:** The compiler should return:
    ```text
    g++: fatal error: no input files
    compilation terminated.
    
    ```
    This confirms the executable binary is recognized by Windows and is awaiting source code files to compile.
    
    ---
    ## 2. Fix `PATH` Environment Variable
    
    If Command Prompt does not recognize `g++`, the folder containing `g++.exe` must be added to your Windows environment variables.
    
    ### Step 1: Locate Your Compiler's `bin` Directory
    
    Navigate your file system to locate the `bin` folder containing `g++.exe`.
    
    Common default installation paths:
    
    * **MSYS2 (UCRT64):** `C:\msys64\ucrt64\bin`
    * **MSYS2 (MinGW64):** `C:\msys64\mingw64\bin`
    * **Standalone MinGW-w64:** `C:\mingw64\bin` or `C:\Program Files\mingw-w64\...\bin`
    * **Classic MinGW:** `C:\MinGW\bin`
    * **Code::Blocks bundled MinGW:** `C:\Program Files\CodeBlocks\MinGW\bin`
    * **Verification:** Open File Explorer, navigate to the directory, and ensure `g++.exe` is listed inside. Copy the entire folder path from the File Explorer address bar.
    
    ### Step 2: Open Environment Variables
    
    1. Press `Win + R`, type `sysdm.cpl`, and press `Enter` to open **System Properties**.
    2. Switch to the **Advanced** tab.
    3. Click the **Environment Variables...** button near the bottom.
    
    * **Verification:** The "Environment Variables" window opens with two sections: **User variables** (top) and **System variables** (bottom).
    
    ### Step 3: Add the Path
    
    1. Under **User variables** (for your account only) or **System variables** (for all user accounts on the machine), find and select the variable named `Path`.
    2. Click **Edit...**.
    3. In the edit window, click **New** on the right side.
    4. Paste the path you copied in Step 1 (e.g., `C:\msys64\ucrt64\bin`).
    5. Click **OK** to close the Path editor, **OK** on the Environment Variables window, and **OK** on System Properties to apply the changes.
    
    * **Verification:** Re-opening the `Path` edit window displays your pasted folder path as an active entry in the list.
    
    ### Step 4: Re-verify in a Fresh Terminal Session
    
    > **Note:** Existing Command Prompt instances will not detect environment changes made after they were launched.
    
    1. Close all active Command Prompt and PowerShell windows.
    2. Open a new Command Prompt (`Win + R` -> `cmd` -> `Enter`).
    3. Re-run:
    ```cmd
    g++ --version
    
    ```
    * **Verification:** The terminal now outputs the GCC version details rather than the `'g++' is not recognized` error.
    
    ```
    If you prefer a step-by-step visual demonstration of locating the folder and updating the environment variables dialog, watch this [How to Add MinGW to PATH in Windows](https://www.youtube.com/watch?v=0HD0pqVtsmw) tutorial.
    
    <ElicitationsGroup message="If you run into issues or need alternative methods:">
      <Elicitation label="Set PATH via PowerShell" query="How do I add g++ to the PATH environment variable using PowerShell commands?"/>
      <Elicitation label="Install MinGW via MSYS2" query="I don't have g++ installed yet. How do I install MinGW-w64 using MSYS2?"/>
      <Elicitation label="Still not recognized" query="I added the path to Environment Variables and restarted CMD, but g++ is still not recognized. How do I troubleshoot this?"/>
    </ElicitationsGroup>
    
    ```

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
