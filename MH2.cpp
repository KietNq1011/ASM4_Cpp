#include "MH2.h"

void display_MH2(int* SD_in_file) {

    ifstream FileIn(FILE_PATH);

    bool first_time = isFirstTime();
    if (!first_time) {
        cout << "\nSD was setted in memory" << endl;

        readSafetyDistanceFromFile(SD_in_file, FileIn);

        for (int i = 0; i < 3; i++) {
            cout << SD_in_file[i] << " ";
        }

        cout << "\nDo you want update it? (Y/N): ";
        char choice;
        while (!(cin >> choice) || (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n')) {
            cin.clear();
            cin.ignore();
            cout << "PLEASE ENTER 'Y' or 'N'!" << endl;
        }

        if (choice == 'y' || choice == 'Y') {
            system("cls");
            cout << "Let's set your SD\n";

            writeDataToFile(SD_in_file, 3, "(SD): ");

            cout << "SD has been update successfully!\n";
        }
        system("pause");
        system("cls");
    }

    FileIn.close();
}

// setting safe distance
void safe_distance(int* SD_in_file, int& v)
{
    if (v <= SD_in_file[0])
    {
        cout << "BAN GIU KHOANG CACH TOI THIEU LA 20m" << endl;
    }
    else if (v > SD_in_file[0] && v <= SD_in_file[1])
    {
        cout << "BAN GIU KHOANG CACH TOI THIEU LA 55m" << endl;
    }
    else if (v > SD_in_file[1] && v <= SD_in_file[2])
    {
        cout << "BAN GIU KHOANG CACH TOI THIEU LA 70m" << endl;
    }
    else
    {
        cout << "BAN GIU KHOANG CACH TOI THIEU LA 100m" << endl;
    }
}