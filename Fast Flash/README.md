```markdown
# Fast Flash Lang ⚡

**Fast Flash Lang** is a lightweight, instant, command-driven domain-specific interpreter implemented in pure C. It acts as a blazing-fast REPL (Read-Eval-Print Loop) environment that instantly parses, evaluates, and answers everyday commands. 

Rather than writing scripts, users type plain-text commands (like `add 200, 50` or `bmi 70, 1.75`) and the engine executes them on the spot. It ships with a core library of **100 day-to-day utilities** covering mathematics, unit conversions, finance, health, geometry, physics, and text manipulation.

---

## 📁 Project Structure

The project is intentionally minimalist, relying on a single header for all logic to keep deployment simple.

```text
FastFlashLang/
├── fastflash.h    # The Core Engine (Contains 100 functions, parser, and command registry)
└── main.c         # The Driver (Interactive REPL shell that handles user input)

```

---

## ⚙️ Step 1: Environment Setup (Configuring the C Compiler)

To compile this project, your PC needs a C compiler (like GCC via MinGW or MSYS2) installed and added to your Windows `PATH` environment variable.

### 1. Locate your Compiler

Find the `bin` folder where `gcc.exe` is installed. Common locations include:

* `C:\msys64\ucrt64\bin`
* `C:\msys64\mingw64\bin`
* `C:\MinGW\bin`

### 2. Add to System PATH

1. Press `Win + R`, type `sysdm.cpl`, and press **Enter**.
2. Go to the **Advanced** tab and click **Environment Variables...**.
3. Under **System variables** (or **User variables**), find and select `Path`, then click **Edit...**.
4. Click **New**, paste your `bin` folder path (e.g., `C:\msys64\ucrt64\bin`), and click **OK** on all windows.

### 3. Verify

Open a **new** Command Prompt (`Win + R` > `cmd`) and type:

```cmd
gcc --version

```

If it prints the version details, your environment is ready.

---

## 💻 Step 2: Opening the Terminal

You need to open a terminal exactly where your project files (`main.c` and `fastflash.h`) are saved.

**Method A (The fast way):**

1. Open the folder containing your files in Windows File Explorer.
2. Click on the address bar at the top, delete the folder path, type `cmd` (or `powershell`), and press **Enter**. The terminal will open directly in this folder.

**Method B (The manual way):**

1. Open PowerShell or Command Prompt.
2. Use the `cd` (change directory) command to navigate to your folder:
```powershell
cd C:\Users\User\Desktop\Compiler

```



---

## 🔨 Step 3: Compiling the Executable (`.exe`)

Once your terminal is open in the project directory, instruct the GCC compiler to build your project. Type the following command and press Enter:

```powershell
gcc main.c -o FastFlash.exe -lm

```

* `gcc`: Invokes the GNU C Compiler.
* `main.c`: The file to compile (which automatically pulls in `fastflash.h`).
* `-o FastFlash.exe`: Names your output executable.
* `-lm`: Links the C math library (required for functions like `sqrt` and `pow`).

If there are no syntax errors, the command will complete silently, and a new file named `FastFlash.exe` will appear in your folder.

---

## 🚀 Step 4: Running the Project

Because PowerShell has strict security rules, it does not allow you to run an executable just by typing its name. You must explicitly tell PowerShell that the file is in the *current directory* using `.\`.

Run the compiled executable by typing:

```powershell
.\FastFlash.exe

```

*(Note: If you are using standard Command Prompt (`cmd`) instead of PowerShell, you can just type `FastFlash.exe`).*

---

## 📖 Step 5: Using Fast Flash Lang (The Running Process)

Once started, the application will display a banner and a `Flash>` prompt. It continuously waits for your input.

### Syntax Rules

* Commands follow the format: `command arg1, arg2`
* Arguments can be separated by commas (`200, 50`) or spaces (`200 50`).
* Type `help` to see the full list of all 100 available functions.
* Type `exit` or `quit` to close the program.

### Example Session

```text
====================================================
        FAST FLASH LANG (Compiler / REPL)           
        Instant Task Execution Engine (100 Funcs)   
====================================================
Type commands directly (e.g., 'add 200, 50', 'c2f 37', 'bmi 70, 1.75')
Type 'help' to view all 100 functions | Type 'exit' to quit.

Flash> add 200, 50
= 250

Flash> bmi 68, 1.72
BMI: 22.99 (Normal)

Flash> uppercase hello world
= "HELLO WORLD"

Flash> discount 150, 20
Savings: $30.00 | Final Price: $120.00

Flash> tip 120, 18
Tip: $21.60 | Total: $141.60

Flash> c2f 37
= 98.60 °F

Flash> bmi 68, 1.72
BMI: 22.99 (Normal)

Flash> is_prime 97
= Prime

Flash> uppercase hello world
= "HELLO WORLD"

Flash> count_words this is fast flash lang
Word count: 5

Flash> coin_toss
= Heads

Flash> exit
Terminating Fast Flash Lang. Goodbye!

```

### Feature Categories Included

1. **Basic & Advanced Math:** `add`, `sub`, `pow`, `sqrt`, `factorial`, `gcd`, `lcm`
2. **Unit Conversions:** `c2f`, `km2mi`, `lb2kg`, `gb2mb`, `h2min`
3. **Finance & Budget:** `tip`, `discount`, `vat`, `split_bill`, `compound_interest`
4. **Health & Fitness:** `bmi`, `bmr`, `water_intake`, `calorie_burn`, `sleep_cycles`
5. **Geometry & Physics:** `area_circle`, `vol_cylinder`, `speed`, `force`, `kinetic_energy`
6. **Strings & Logic:** `strlen`, `reverse_str`, `is_palindrome`, `is_prime`, `random_range`

```

```
