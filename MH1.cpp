#include "MH1.h"

int display_MH1() {
	int MSCN_in_file[8], MSCN_inputted[8];

	bool first_time = isFirstTime();
	if (!first_time) {
		readDataFromFile(MSCN_in_file, MSCN_inputted, '1', first_time);

		/// sort và so sánh mảng gốc và mảng nhập vào
		cout << "Mang goc truoc khi sap xep:  ";
		for (int i = 0; i < 8; i++) {
			cout << MSCN_in_file[i] << " ";
		}
		cout << endl;

		selectionSort(MSCN_in_file, 8);
		cout << "-> Mang goc sau khi sap xep: ";
		for (int i = 0; i < 8; i++) {
			cout << MSCN_in_file[i] << " ";
		}
		cout << endl;

		cout << "MSCN truoc khi sap xep:      ";
		for (int i = 0; i < 8; i++) {
			cout << MSCN_inputted[i] << " ";
		}
		cout << endl;

		bubbleSort(MSCN_inputted, 8);
		cout << "--> MSCN sau khi sap xep:    ";
		for (int i = 0; i < 8; i++) {
			cout << MSCN_inputted[i] << " ";
		}
		cout << endl;

        if (compareArrays(MSCN_in_file, MSCN_inputted, 8)) {
            cout << "The entered number is the same as the original.\n" << endl;
            cout << "Do you want to reset your password? (Y/N): ";
            char choice;
            while (!(cin >> choice) || (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n')) {
                cin.clear();               // clear the fail state
                cin.ignore();  // discard invalid input
                cout << "PLEASE ENTER 'Y' or 'N'!" << endl;
            }
            system("pause");
            system("cls");

            switch (choice) {
            case 'y':
            case 'Y':
                cout << "Let's set your password\n";
                writeDataToFile(MSCN_in_file, 8, "MSCN: ");
                cout << "Password reset successfully!" << endl;
                system("pause");
                system("cls");
                break;
            case 'n':
            case 'N':
                break;
            default:
                cout << "Your choice is invalid!";
                break;
            }
            return 1;
        }
        else {
            cout << "The entered number isn't the same as the original." << endl;
            cout << "Goodbye!" << endl;
            return 0;
        }
	}
}
