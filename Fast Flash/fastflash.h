#ifndef FASTFLASH_H
#define FASTFLASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* -------------------------------------------------------------
 *  ARGUMENT PARSING HELPERS (Supports "200, 50" or "200 50")
 * ------------------------------------------------------------- */
static void sanitize_commas(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ',') str[i] = ' ';
    }
}

static int get_1_double(const char *args, double *a) {
    char buf[256];
    strncpy(buf, args, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    sanitize_commas(buf);
    return sscanf(buf, "%lf", a) == 1;
}

static int get_2_doubles(const char *args, double *a, double *b) {
    char buf[256];
    strncpy(buf, args, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    sanitize_commas(buf);
    return sscanf(buf, "%lf %lf", a, b) == 2;
}

static int get_3_doubles(const char *args, double *a, double *b, double *c) {
    char buf[256];
    strncpy(buf, args, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    sanitize_commas(buf);
    return sscanf(buf, "%lf %lf %lf", a, b, c) == 3;
}

static const char* skip_whitespace(const char *str) {
    while (*str && isspace((unsigned char)*str)) str++;
    return str;
}

/* -------------------------------------------------------------
 *  100 EXECUTABLE FUNCTIONS
 * ------------------------------------------------------------- */

// [1 - 10] Basic Math
void ff_add(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", x + y); else puts("Usage: add <num1>, <num2>"); }
void ff_sub(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", x - y); else puts("Usage: sub <num1>, <num2>"); }
void ff_mul(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", x * y); else puts("Usage: mul <num1>, <num2>"); }
void ff_div(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) { if(y!=0) printf("= %.4g\n", x / y); else puts("Error: Division by zero"); } else puts("Usage: div <num1>, <num2>"); }
void ff_mod(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) { if((long)y!=0) printf("= %ld\n", (long)x % (long)y); else puts("Error: Division by zero"); } else puts("Usage: mod <int1>, <int2>"); }
void ff_pow(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", pow(x, y)); else puts("Usage: pow <base>, <exp>"); }
void ff_sqrt(const char *a) { double x; if(get_1_double(a, &x)) { if(x>=0) printf("= %.4g\n", sqrt(x)); else puts("Error: Negative value"); } else puts("Usage: sqrt <num>"); }
void ff_abs(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4g\n", fabs(x)); else puts("Usage: abs <num>"); }
void ff_min(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", (x < y) ? x : y); else puts("Usage: min <num1>, <num2>"); }
void ff_max(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", (x > y) ? x : y); else puts("Usage: max <num1>, <num2>"); }

// [11 - 20] Advanced Arithmetic & Stats
void ff_avg(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4g\n", (x + y) / 2.0); else puts("Usage: avg <num1>, <num2>"); }
void ff_percent(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.2f%%\n", (x / y) * 100.0); else puts("Usage: percent <part>, <whole>"); }
void ff_factorial(const char *a) { double x; if(get_1_double(a, &x) && x >= 0 && x <= 20) { unsigned long long f = 1; for(int i=1;i<=(int)x;i++) f*=i; printf("= %llu\n", f); } else puts("Usage: factorial <int 0-20>"); }
void ff_gcd(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) { long n1 = labs((long)x), n2 = labs((long)y); while(n2 != 0){ long t = n2; n2 = n1 % n2; n1 = t; } printf("= %ld\n", n1); } else puts("Usage: gcd <int1>, <int2>"); }
void ff_lcm(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) { long n1 = labs((long)x), n2 = labs((long)y), a0 = n1, b0 = n2; while(n2 != 0){ long t = n2; n2 = n1 % n2; n1 = t; } printf("= %ld\n", (n1==0)?0:(a0*b0)/n1); } else puts("Usage: lcm <int1>, <int2>"); }
void ff_round(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f\n", round(x)); else puts("Usage: round <num>"); }
void ff_floor(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f\n", floor(x)); else puts("Usage: floor <num>"); }
void ff_ceil(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f\n", ceil(x)); else puts("Usage: ceil <num>"); }
void ff_log10(const char *a) { double x; if(get_1_double(a, &x) && x > 0) printf("= %.4g\n", log10(x)); else puts("Usage: log10 <num > 0>"); }
void ff_ln(const char *a) { double x; if(get_1_double(a, &x) && x > 0) printf("= %.4g\n", log(x)); else puts("Usage: ln <num > 0>"); }

// [21 - 30] Temperature & Distance
void ff_c2f(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.2f °F\n", (x * 9.0/5.0) + 32.0); else puts("Usage: c2f <celsius>"); }
void ff_f2c(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.2f °C\n", (x - 32.0) * 5.0/9.0); else puts("Usage: f2c <fahrenheit>"); }
void ff_c2k(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.2f K\n", x + 273.15); else puts("Usage: c2k <celsius>"); }
void ff_km2mi(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f miles\n", x * 0.621371); else puts("Usage: km2mi <km>"); }
void ff_mi2km(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f km\n", x * 1.60934); else puts("Usage: mi2km <miles>"); }
void ff_m2ft(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f ft\n", x * 3.28084); else puts("Usage: m2ft <meters>"); }
void ff_ft2m(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f m\n", x * 0.3048); else puts("Usage: ft2m <feet>"); }
void ff_cm2in(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f inches\n", x * 0.393701); else puts("Usage: cm2in <cm>"); }
void ff_in2cm(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f cm\n", x * 2.54); else puts("Usage: in2cm <inches>"); }
void ff_kg2lb(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f lbs\n", x * 2.20462); else puts("Usage: kg2lb <kg>"); }

// [31 - 40] Unit Conversions: Weight, Volume, Time, Data
void ff_lb2kg(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f kg\n", x * 0.453592); else puts("Usage: lb2kg <lbs>"); }
void ff_l2gal(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f gallons\n", x * 0.264172); else puts("Usage: l2gal <liters>"); }
void ff_gal2l(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f liters\n", x * 3.78541); else puts("Usage: gal2l <gallons>"); }
void ff_h2min(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f minutes\n", x * 60.0); else puts("Usage: h2min <hours>"); }
void ff_min2sec(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f seconds\n", x * 60.0); else puts("Usage: min2sec <minutes>"); }
void ff_sec2min(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.2f minutes\n", x / 60.0); else puts("Usage: sec2min <seconds>"); }
void ff_d2h(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f hours\n", x * 24.0); else puts("Usage: d2h <days>"); }
void ff_mb2gb(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f GB\n", x / 1024.0); else puts("Usage: mb2gb <megabytes>"); }
void ff_gb2mb(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.0f MB\n", x * 1024.0); else puts("Usage: gb2mb <gigabytes>"); }
void ff_kb2mb(const char *a) { double x; if(get_1_double(a, &x)) printf("= %.4f MB\n", x / 1024.0); else puts("Usage: kb2mb <kilobytes>"); }

// [41 - 50] Finance & Daily Budget
void ff_tip(const char *a) { double b, p; if(get_2_doubles(a, &b, &p)) printf("Tip: $%.2f | Total: $%.2f\n", b*(p/100.0), b*(1.0 + p/100.0)); else puts("Usage: tip <bill>, <tip_percent>"); }
void ff_discount(const char *a) { double p, d; if(get_2_doubles(a, &p, &d)) printf("Savings: $%.2f | Final Price: $%.2f\n", p*(d/100.0), p*(1.0 - d/100.0)); else puts("Usage: discount <price>, <discount_percent>"); }
void ff_vat(const char *a) { double p, t; if(get_2_doubles(a, &p, &t)) printf("Tax: $%.2f | Total: $%.2f\n", p*(t/100.0), p*(1.0 + t/100.0)); else puts("Usage: vat <price>, <tax_percent>"); }
void ff_split_bill(const char *a) { double b, n; if(get_2_doubles(a, &b, &n) && n > 0) printf("Each pays: $%.2f\n", b / n); else puts("Usage: split_bill <total_bill>, <num_people>"); }
void ff_simple_interest(const char *a) { double p, r, t; if(get_3_doubles(a, &p, &r, &t)) printf("Interest: $%.2f | Total: $%.2f\n", (p*r*t)/100.0, p + (p*r*t)/100.0); else puts("Usage: simple_interest <principal>, <rate_percent>, <time_years>"); }
void ff_compound_interest(const char *a) { double p, r, t; if(get_3_doubles(a, &p, &r, &t)) { double tot = p * pow(1.0 + (r/100.0), t); printf("Compound Total: $%.2f | Interest: $%.2f\n", tot, tot - p); } else puts("Usage: compound_interest <principal>, <rate_percent>, <time_years>"); }
void ff_hourly2annual(const char *a) { double w; if(get_1_double(a, &w)) printf("Annual Salary (40h/week): $%.2f\n", w * 2080.0); else puts("Usage: hourly2annual <hourly_wage>"); }
void ff_annual2monthly(const char *a) { double s; if(get_1_double(a, &s)) printf("Monthly Gross: $%.2f\n", s / 12.0); else puts("Usage: annual2monthly <annual_salary>"); }
void ff_markup(const char *a) { double c, m; if(get_2_doubles(a, &c, &m)) printf("Selling Price: $%.2f\n", c * (1.0 + m/100.0)); else puts("Usage: markup <cost>, <markup_percent>"); }
void ff_profit_loss(const char *a) { double c, s; if(get_2_doubles(a, &c, &s)) { double diff = s - c; printf("%s: $%.2f (%.2f%%)\n", (diff>=0)?"Profit":"Loss", fabs(diff), (fabs(diff)/c)*100.0); } else puts("Usage: profit_loss <cost_price>, <selling_price>"); }

// [51 - 60] Health & Fitness
void ff_bmi(const char *a) { double w, h; if(get_2_doubles(a, &w, &h) && h > 0) { double bmi = w / (h * h); const char *cat = (bmi < 18.5) ? "Underweight" : (bmi < 25.0) ? "Normal" : (bmi < 30.0) ? "Overweight" : "Obese"; printf("BMI: %.2f (%s)\n", bmi, cat); } else puts("Usage: bmi <weight_kg>, <height_meters>"); }
void ff_bmr(const char *a) { double w, h, age; if(get_3_doubles(a, &w, &h, &age)) printf("Estimated BMR: %.0f kcal/day\n", (10.0*w) + (6.25*h) - (5.0*age) + 5.0); else puts("Usage: bmr <weight_kg>, <height_cm>, <age>"); }
void ff_water_intake(const char *a) { double w; if(get_1_double(a, &w)) printf("Recommended Water: %.0f ml/day (%.2f L)\n", w * 35.0, (w * 35.0)/1000.0); else puts("Usage: water_intake <weight_kg>"); }
void ff_ideal_weight(const char *a) { double h; if(get_1_double(a, &h) && h > 152) printf("Ideal Weight (Devine): %.1f kg\n", 50.0 + 0.9 * (h - 152.0)); else puts("Usage: ideal_weight <height_cm > 152>"); }
void ff_calorie_burn(const char *a) { double met, w, hr; if(get_3_doubles(a, &met, &w, &hr)) printf("Calories Burned: %.0f kcal\n", met * w * hr); else puts("Usage: calorie_burn <MET_value>, <weight_kg>, <duration_hours>"); }
void ff_target_hr(const char *a) { double age, intn; if(get_2_doubles(a, &age, &intn)) printf("Target HR: %.0f bpm\n", (220.0 - age) * (intn / 100.0)); else puts("Usage: target_hr <age>, <intensity_percent>"); }
void ff_pace(const char *a) { double d, t; if(get_2_doubles(a, &d, &t) && d > 0) printf("Pace: %.2f min/km\n", t / d); else puts("Usage: pace <distance_km>, <time_minutes>"); }
void ff_step2km(const char *a) { double s; if(get_1_double(a, &s)) printf("= %.2f km\n", s * 0.00078); else puts("Usage: step2km <steps>"); }
void ff_km2step(const char *a) { double k; if(get_1_double(a, &k)) printf("= %.0f steps\n", k / 0.00078); else puts("Usage: km2step <km>"); }
void ff_sleep_cycles(const char *a) { double h; if(get_1_double(a, &h)) printf("= %.1f full sleep cycles (90 min each)\n", (h * 60.0) / 90.0); else puts("Usage: sleep_cycles <hours_of_sleep>"); }

// [61 - 70] 2D & 3D Geometry
void ff_area_circle(const char *a) { double r; if(get_1_double(a, &r)) printf("= %.4f\n", M_PI * r * r); else puts("Usage: area_circle <radius>"); }
void ff_area_rect(const char *a) { double w, h; if(get_2_doubles(a, &w, &h)) printf("= %.4f\n", w * h); else puts("Usage: area_rect <width>, <height>"); }
void ff_area_triangle(const char *a) { double b, h; if(get_2_doubles(a, &b, &h)) printf("= %.4f\n", 0.5 * b * h); else puts("Usage: area_triangle <base>, <height>"); }
void ff_perimeter_rect(const char *a) { double w, h; if(get_2_doubles(a, &w, &h)) printf("= %.4f\n", 2.0 * (w + h)); else puts("Usage: perimeter_rect <width>, <height>"); }
void ff_circumference(const char *a) { double r; if(get_1_double(a, &r)) printf("= %.4f\n", 2.0 * M_PI * r); else puts("Usage: circumference <radius>"); }
void ff_vol_cube(const char *a) { double s; if(get_1_double(a, &s)) printf("= %.4f\n", s * s * s); else puts("Usage: vol_cube <side>"); }
void ff_vol_cylinder(const char *a) { double r, h; if(get_2_doubles(a, &r, &h)) printf("= %.4f\n", M_PI * r * r * h); else puts("Usage: vol_cylinder <radius>, <height>"); }
void ff_vol_sphere(const char *a) { double r; if(get_1_double(a, &r)) printf("= %.4f\n", (4.0/3.0) * M_PI * pow(r, 3)); else puts("Usage: vol_sphere <radius>"); }
void ff_surface_cube(const char *a) { double s; if(get_1_double(a, &s)) printf("= %.4f\n", 6.0 * s * s); else puts("Usage: surface_cube <side>"); }
void ff_hypot(const char *a) { double x, y; if(get_2_doubles(a, &x, &y)) printf("= %.4f\n", hypot(x, y)); else puts("Usage: hypot <side_a>, <side_b>"); }

// [71 - 80] Daily Physics
void ff_speed(const char *a) { double d, t; if(get_2_doubles(a, &d, &t) && t != 0) printf("Speed: %.2f units/time\n", d / t); else puts("Usage: speed <distance>, <time>"); }
void ff_distance(const char *a) { double s, t; if(get_2_doubles(a, &s, &t)) printf("Distance: %.2f units\n", s * t); else puts("Usage: distance <speed>, <time>"); }
void ff_time_calc(const char *a) { double d, s; if(get_2_doubles(a, &d, &s) && s != 0) printf("Time: %.2f units\n", d / s); else puts("Usage: time_calc <distance>, <speed>"); }
void ff_force(const char *a) { double m, acc; if(get_2_doubles(a, &m, &acc)) printf("Force: %.2f N\n", m * acc); else puts("Usage: force <mass>, <acceleration>"); }
void ff_work(const char *a) { double f, d; if(get_2_doubles(a, &f, &d)) printf("Work: %.2f J\n", f * d); else puts("Usage: work <force>, <distance>"); }
void ff_power(const char *a) { double w, t; if(get_2_doubles(a, &w, &t) && t != 0) printf("Power: %.2f W\n", w / t); else puts("Usage: power <work>, <time>"); }
void ff_kinetic_energy(const char *a) { double m, v; if(get_2_doubles(a, &m, &v)) printf("KE: %.2f J\n", 0.5 * m * v * v); else puts("Usage: kinetic_energy <mass>, <velocity>"); }
void ff_potential_energy(const char *a) { double m, h; if(get_2_doubles(a, &m, &h)) printf("PE: %.2f J\n", m * 9.80665 * h); else puts("Usage: potential_energy <mass>, <height>"); }
void ff_density(const char *a) { double m, v; if(get_2_doubles(a, &m, &v) && v != 0) printf("Density: %.4f unit/vol\n", m / v); else puts("Usage: density <mass>, <volume>"); }
void ff_pressure(const char *a) { double f, ar; if(get_2_doubles(a, &f, &ar) && ar != 0) printf("Pressure: %.2f Pa\n", f / ar); else puts("Usage: pressure <force>, <area>"); }

// [81 - 90] Strings & Text
void ff_strlen(const char *a) { a = skip_whitespace(a); printf("Length: %zu characters\n", strlen(a)); }
void ff_count_words(const char *a) { a = skip_whitespace(a); int count = 0, in_word = 0; while(*a){ if(isspace((unsigned char)*a)) in_word = 0; else if(!in_word){ in_word = 1; count++; } a++; } printf("Word count: %d\n", count); }
void ff_reverse_str(const char *a) { a = skip_whitespace(a); int len = strlen(a); char *rev = malloc(len + 1); if(!rev) return; for(int i=0; i<len; i++) rev[i] = a[len - 1 - i]; rev[len] = '\0'; printf("= \"%s\"\n", rev); free(rev); }
void ff_uppercase(const char *a) { a = skip_whitespace(a); printf("= \""); while(*a){ putchar(toupper((unsigned char)*a)); a++; } printf("\"\n"); }
void ff_lowercase(const char *a) { a = skip_whitespace(a); printf("= \""); while(*a){ putchar(tolower((unsigned char)*a)); a++; } printf("\"\n"); }
void ff_is_palindrome(const char *a) { a = skip_whitespace(a); int i = 0, j = strlen(a) - 1, pal = 1; while(i < j){ while(i < j && !isalnum((unsigned char)a[i])) i++; while(i < j && !isalnum((unsigned char)a[j])) j--; if(tolower((unsigned char)a[i]) != tolower((unsigned char)a[j])) { pal = 0; break; } i++; j--; } printf("= %s\n", pal ? "Yes, it is a palindrome" : "No, not a palindrome"); }
void ff_repeat_str(const char *a) { char buf[128]; int times; if(sscanf(a, "%127s %d", buf, &times) == 2) { printf("= \""); for(int i=0; i<times; i++) printf("%s", buf); printf("\"\n"); } else puts("Usage: repeat_str <word> <times>"); }
void ff_char_code(const char *a) { a = skip_whitespace(a); if(*a) printf("ASCII('%c') = %d\n", *a, (int)*a); else puts("Usage: char_code <character>"); }
void ff_code_to_char(const char *a) { double x; if(get_1_double(a, &x) && x >= 32 && x <= 126) printf("= '%c'\n", (char)x); else puts("Usage: code_to_char <int 32-126>"); }
void ff_trim(const char *a) { while(*a && isspace((unsigned char)*a)) a++; char buf[256]; strncpy(buf, a, sizeof(buf)-1); buf[sizeof(buf)-1] = '\0'; int end = strlen(buf) - 1; while(end >= 0 && isspace((unsigned char)buf[end])) buf[end--] = '\0'; printf("= \"%s\"\n", buf); }

// [91 - 100] Everyday Utilities, Logic & Productivity
void ff_even_odd(const char *a) { double x; if(get_1_double(a, &x)) printf("= %s\n", ((long)x % 2 == 0) ? "Even" : "Odd"); else puts("Usage: even_odd <integer>"); }
void ff_is_prime(const char *a) { double x; if(get_1_double(a, &x) && x >= 2) { long n = (long)x, p = 1; for(long i=2; i*i<=n; i++) if(n%i==0){ p=0; break; } printf("= %s\n", p ? "Prime" : "Not Prime (Composite)"); } else puts("Usage: is_prime <int >= 2>"); }
void ff_random_range(const char *a) { double min, max; if(get_2_doubles(a, &min, &max) && max >= min) { int r = (int)min + rand() % ((int)max - (int)min + 1); printf("= %d\n", r); } else puts("Usage: random_range <min>, <max>"); }
void ff_coin_toss(const char *a) { (void)a; printf("= %s\n", (rand() % 2 == 0) ? "Heads" : "Tails"); }
void ff_dice_roll(const char *a) { (void)a; printf("= Rolled a %d\n", (rand() % 6) + 1); }
void ff_leap_year(const char *a) { double x; if(get_1_double(a, &x)) { int y = (int)x; int leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); printf("= %d is %s\n", y, leap ? "a Leap Year" : "NOT a Leap Year"); } else puts("Usage: leap_year <year>"); }
void ff_reading_time(const char *a) { double words; if(get_1_double(a, &words)) printf("Estimated Reading Time: %.1f minutes (at 200 WPM)\n", words / 200.0); else puts("Usage: reading_time <total_words>"); }
void ff_pomodoro(const char *a) { double c; if(get_1_double(a, &c)) printf("Pomodoro Plan: %.0f min work + %.0f min break (Total: %.0f min)\n", c * 25.0, c * 5.0, c * 30.0); else puts("Usage: pomodoro <number_of_cycles>"); }
void ff_battery_life(const char *a) { double cap, cur; if(get_2_doubles(a, &cap, &cur) && cur > 0) printf("Estimated Runtime: %.2f hours\n", cap / cur); else puts("Usage: battery_life <capacity_mAh>, <draw_mA>"); }
void ff_days2weeks(const char *a) { double d; if(get_1_double(a, &d)) { int days = (int)d; printf("= %d weeks and %d days\n", days / 7, days % 7); } else puts("Usage: days2weeks <days>"); }

/* -------------------------------------------------------------
 *  COMMAND LOOKUP TABLE REGISTRY (All 100 Commands)
 * ------------------------------------------------------------- */
typedef struct {
    const char *name;
    void (*func)(const char *args);
    const char *desc;
} FastFlashCommand;

static FastFlashCommand COMMAND_TABLE[] = {
    // Basic Math
    {"add", ff_add, "Add two numbers"},
    {"sub", ff_sub, "Subtract two numbers"},
    {"mul", ff_mul, "Multiply two numbers"},
    {"div", ff_div, "Divide two numbers"},
    {"mod", ff_mod, "Modulo of two integers"},
    {"pow", ff_pow, "Raise base to exponent"},
    {"sqrt", ff_sqrt, "Square root of a number"},
    {"abs", ff_abs, "Absolute value"},
    {"min", ff_min, "Minimum of two values"},
    {"max", ff_max, "Maximum of two values"},

    // Advanced Stats & Math
    {"avg", ff_avg, "Average of two numbers"},
    {"percent", ff_percent, "Percentage of a part over a whole"},
    {"factorial", ff_factorial, "Factorial of an integer"},
    {"gcd", ff_gcd, "Greatest common divisor"},
    {"lcm", ff_lcm, "Least common multiple"},
    {"round", ff_round, "Round to nearest integer"},
    {"floor", ff_floor, "Round down"},
    {"ceil", ff_ceil, "Round up"},
    {"log10", ff_log10, "Base-10 logarithm"},
    {"ln", ff_ln, "Natural logarithm"},

    // Unit Conversions
    {"c2f", ff_c2f, "Celsius to Fahrenheit"},
    {"f2c", ff_f2c, "Fahrenheit to Celsius"},
    {"c2k", ff_c2k, "Celsius to Kelvin"},
    {"km2mi", ff_km2mi, "Kilometers to miles"},
    {"mi2km", ff_mi2km, "Miles to kilometers"},
    {"m2ft", ff_m2ft, "Meters to feet"},
    {"ft2m", ff_ft2m, "Feet to meters"},
    {"cm2in", ff_cm2in, "Centimeters to inches"},
    {"in2cm", ff_in2cm, "Inches to centimeters"},
    {"kg2lb", ff_kg2lb, "Kilograms to pounds"},
    {"lb2kg", ff_lb2kg, "Pounds to kilograms"},
    {"l2gal", ff_l2gal, "Liters to US gallons"},
    {"gal2l", ff_gal2l, "US gallons to liters"},
    {"h2min", ff_h2min, "Hours to minutes"},
    {"min2sec", ff_min2sec, "Minutes to seconds"},
    {"sec2min", ff_sec2min, "Seconds to minutes"},
    {"d2h", ff_d2h, "Days to hours"},
    {"mb2gb", ff_mb2gb, "Megabytes to Gigabytes"},
    {"gb2mb", ff_gb2mb, "Gigabytes to Megabytes"},
    {"kb2mb", ff_kb2mb, "Kilobytes to Megabytes"},

    // Finance & Budget
    {"tip", ff_tip, "Calculate tip and total"},
    {"discount", ff_discount, "Calculate discount and final price"},
    {"vat", ff_vat, "Calculate sales tax/VAT"},
    {"split_bill", ff_split_bill, "Split a bill among people"},
    {"simple_interest", ff_simple_interest, "Simple interest calculator"},
    {"compound_interest", ff_compound_interest, "Compound interest calculator"},
    {"hourly2annual", ff_hourly2annual, "Convert hourly wage to annual salary"},
    {"annual2monthly", ff_annual2monthly, "Convert annual salary to monthly pay"},
    {"markup", ff_markup, "Cost markup calculation"},
    {"profit_loss", ff_profit_loss, "Profit and loss calculation"},

    // Health & Fitness
    {"bmi", ff_bmi, "Body Mass Index calculator"},
    {"bmr", ff_bmr, "Basal Metabolic Rate estimation"},
    {"water_intake", ff_water_intake, "Daily recommended water intake"},
    {"ideal_weight", ff_ideal_weight, "Ideal body weight estimation"},
    {"calorie_burn", ff_calorie_burn, "Calories burned based on MET"},
    {"target_hr", ff_target_hr, "Target training heart rate"},
    {"pace", ff_pace, "Running or walking pace"},
    {"step2km", ff_step2km, "Convert steps to km"},
    {"km2step", ff_km2step, "Convert km to steps"},
    {"sleep_cycles", ff_sleep_cycles, "Sleep cycle analyzer (90 min each)"},

    // Geometry
    {"area_circle", ff_area_circle, "Area of circle"},
    {"area_rect", ff_area_rect, "Area of rectangle"},
    {"area_triangle", ff_area_triangle, "Area of triangle"},
    {"perimeter_rect", ff_perimeter_rect, "Perimeter of rectangle"},
    {"circumference", ff_circumference, "Circumference of circle"},
    {"vol_cube", ff_vol_cube, "Volume of cube"},
    {"vol_cylinder", ff_vol_cylinder, "Volume of cylinder"},
    {"vol_sphere", ff_vol_sphere, "Volume of sphere"},
    {"surface_cube", ff_surface_cube, "Surface area of cube"},
    {"hypot", ff_hypot, "Right triangle hypotenuse"},

    // Physics
    {"speed", ff_speed, "Speed calculation"},
    {"distance", ff_distance, "Distance calculation"},
    {"time_calc", ff_time_calc, "Travel time calculation"},
    {"force", ff_force, "Force from mass and acceleration"},
    {"work", ff_work, "Work from force and distance"},
    {"power", ff_power, "Power from work and time"},
    {"kinetic_energy", ff_kinetic_energy, "Kinetic energy"},
    {"potential_energy", ff_potential_energy, "Gravitational potential energy"},
    {"density", ff_density, "Density from mass and volume"},
    {"pressure", ff_pressure, "Pressure from force and area"},

    // Strings & Text
    {"strlen", ff_strlen, "Count character length"},
    {"count_words", ff_count_words, "Count words in sentence"},
    {"reverse_str", ff_reverse_str, "Reverse characters in text"},
    {"uppercase", ff_uppercase, "Convert text to uppercase"},
    {"lowercase", ff_lowercase, "Convert text to lowercase"},
    {"is_palindrome", ff_is_palindrome, "Check if text is palindrome"},
    {"repeat_str", ff_repeat_str, "Repeat text N times"},
    {"char_code", ff_char_code, "Get ASCII numeric code"},
    {"code_to_char", ff_code_to_char, "Get character from ASCII code"},
    {"trim", ff_trim, "Trim leading and trailing spaces"},

    // Utilities & Logic
    {"even_odd", ff_even_odd, "Check even or odd integer"},
    {"is_prime", ff_is_prime, "Check if number is prime"},
    {"random_range", ff_random_range, "Generate random integer in range"},
    {"coin_toss", ff_coin_toss, "Flip a coin (Heads/Tails)"},
    {"dice_roll", ff_dice_roll, "Roll a 6-sided dice"},
    {"leap_year", ff_leap_year, "Check if a year is a leap year"},
    {"reading_time", ff_reading_time, "Estimate reading time in minutes"},
    {"pomodoro", ff_pomodoro, "Pomodoro study/work cycle planner"},
    {"battery_life", ff_battery_life, "Estimate battery runtime"},
    {"days2weeks", ff_days2weeks, "Convert days into weeks and remainder days"},
};

#define TOTAL_COMMANDS ((int)(sizeof(COMMAND_TABLE) / sizeof(COMMAND_TABLE[0])))

static void ff_help() {
    printf("\n=== Fast Flash Lang - 100 Available Functions ===\n");
    for (int i = 0; i < TOTAL_COMMANDS; i++) {
        printf("%-18s : %s\n", COMMAND_TABLE[i].name, COMMAND_TABLE[i].desc);
    }
    printf("=================================================\n\n");
}

static void ff_execute(char *input_line) {
    // Strip trailing newlines
    input_line[strcspn(input_line, "\r\n")] = '\0';

    // Skip leading spaces
    char *cmd_ptr = input_line;
    while (*cmd_ptr && isspace((unsigned char)*cmd_ptr)) cmd_ptr++;
    if (*cmd_ptr == '\0') return; // Empty command

    // Extract command name
    char cmd[64];
    int idx = 0;
    while (*cmd_ptr && !isspace((unsigned char)*cmd_ptr) && idx < 63) {
        cmd[idx++] = *cmd_ptr++;
    }
    cmd[idx] = '\0';

    // Argument starts after the command name
    const char *args = skip_whitespace(cmd_ptr);

    if (strcmp(cmd, "help") == 0) {
        ff_help();
        return;
    }

    // Search command table
    for (int i = 0; i < TOTAL_COMMANDS; i++) {
        if (strcmp(cmd, COMMAND_TABLE[i].name) == 0) {
            COMMAND_TABLE[i].func(args);
            return;
        }
    }

    printf("Error: Unknown command '%s'. Type 'help' to see all 100 commands.\n", cmd);
}

#endif // FASTFLASH_H