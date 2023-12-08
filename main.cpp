#include<iostream>
#include<string>
#include "MH1.h"
#include "MH2.h"
#include "MH3.h"
#include "MH4.h"
#include "Shared_Fns.h"

using namespace std;

int main()
{
	int speed = 0;
	int MSCN_in_file[8], MSCN_inputted[8];
	int SD_in_file[3], SD_sorted[3];

	bool FirstTime = isFirstTime();

	if (FirstTime)
	{
		readDataFromFile(MSCN_in_file, MSCN_inputted, '1', FirstTime);
		readDataFromFile(SD_in_file, SD_sorted, '2', FirstTime);
	}
	else {
		if (display_MH1()) {
			display_MH2(SD_in_file);

			while (true) {
				int choice = choice_option();
				switch (choice) {
				case 1:
					gear_P(speed);
					break;

				case 2:
					gear_R(speed);
					break;

				case 3:
					gear_N(speed);
					break;

				case 4:
					gear_D(speed);
					break;

				case 5:
					system("cls");
					cout << "XE DA DUOC TAT. TAM BIET" << endl;
					return 0;

				default:
					system("cls");
					cin.clear(); // delete error cin status
					cin.ignore();
					cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
					system("pause");
					continue;
				}

				check_speed(speed, choice, SD_in_file);

				system("pause");  // Pause the screen for the user to read messages
			}
		}
	}

	system("pause");
	return 0;
}