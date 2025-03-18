#include <bits/stdc++.h>
using namespace std;

int first_year(int year) {
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + 1) % 7;
    return day;
}

int main() { 
    int year, day, week;
    int days_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string months[12] = {"January", "February", "March", "April", "May", "June",  "July", "August", "September", "October", "November", "December"};

    cout << "\n\nEnter the year: ";
    cin >> year;

    // leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_months[1] = 29;
    }

    day = first_year(year);  

    for (int i = 0; i < 12; i++) {
        cout << "\n\n\t\t" << months[i] << ", " << year;
        cout << "\n\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        for (int j = 0; j < day; j++) {
            cout << "     ";
        }

        week = day;
        for (int m = 1; m <= days_months[i]; m++) {
            cout << setw(5) << m;  

            if (week == 6) {  
                cout << "\n";
                week = 0;
            } else {
                week++;
            }
            day = week;
        }
    }

    return 0;
}
