#include <iostream>
#include <time.h>  
using namespace std;


void BM(string stringline, string form) {
    int i = 0;
    int j = 0;
    bool flag = false;
    while (i < stringline.length()) {
        for (j = 0;j< form.length(); ++j)
            if (stringline[i+j] == form[j]) {
                flag = true;
            }
            else {
                flag = false;
                break;
            }
      
        if (flag) {
 //           cout << "\nподстрока найдена" << i+1;
            break;
        }
        i += j+1;
    }


}

int find(string stringline, string form) //RK
{
    // i-с какого места строки  ищем
    // j-с какого места образца ищем
    for (int i = 0; i < stringline.length(); i++) {
        for (int j = 0; j< form.length(); j++) {
            if (form[j] == stringline[i + j]) return i; // образец найден 
            if (form[j] != stringline[i + j]) break;
        }
        // пока не найден, продолжим внешний цикл
    }
    // образца нет
    return -1;
}


void fildPow(string stringline, string form) {
    bool flag = false;
    bool flagToe = false;

    for (int i=0; i<stringline.length()-1; i++) {

        for (int j=0; j<form.length(); j++) {
            if (form[j] == stringline[i+j]) {
//                cout <<"\n\n" <<form[j]<<" "<<stringline[i+j];
                flag = true;
                
            }
            else { 
                if(flag)
 //                   cout << "\n\n" << form[j] << " " << stringline[i];
                flag = false;
                
                break; 
            }
        }
        if (flag) {
            flagToe = true;
 //           cout << "\nПодстрока найдена  " << i+1<<"  "<<stringline[i]<< stringline[i+1];
            break;
        }
    }
//    if (!flagToe)
 //       cout << "\n Подстрока не найдена";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    string stringline;
    string form;
    int size_string, size_form = 2, longer=100;
    int colr = 1, step = 100;
    cout << "Введите максимальное колисчество элементов в строке: ";
    cin >> longer;
    cout << "\nВведите колисчество элементов в подстроке: ";
    cin >> size_form;
    cout << "\nВведите  колисчество пвторений: ";
    cin >>  colr;
    cout << "\nВведите шаг: ";
    cin >>  step;


    for (int m = 100; m < longer; m += step) {

        size_string = m;

        stringline.clear();
        form.clear();

        for (int i = 0; i < size_string; i++)
            stringline += char('a' + rand() % ('j' - 'a'));

        int point = (rand() % (size_string - size_form - 2));

        for (int i = 0; i < size_form; i++) {
            form += stringline[point + i];
        }



        cout << "\n Подстрока 1 " << stringline << "\n Подстрока 2 " << form;
        double time1 = clock();
        double tmm = 0;


        for (int k = 0; k < colr; k++) {
            for (int i = 0; i < size_string; i++)
                stringline += char('a' + rand() % ('j' - 'a'));

            int point = (rand() % (size_string - size_form - 2));

            for (int i = 0; i < size_form; i++) {
                form += stringline[point + i];
            }

            time1 = clock();
            if (find(stringline, form) != -1) {
                //  cout << "\nНайдено на позиции " << find(stringline, form) + 1;
            }
            else {
                // cout << "\nПодстрока не найдена";
            }
            tmm += clock() - time1;
        }

  //      cout << "\n\nВреме RK " << tmm / colr;

  //      cout << "\n\n\nBM";
        time1 = clock();
        tmm = 0;
        for (int k = 0; k < colr; k++) {
            for (int i = 0; i < size_string; i++)
                stringline += char('a' + rand() % ('j' - 'a'));

            int point = (rand() % (size_string - size_form - 2));

            for (int i = 0; i < size_form; i++) {
                form += stringline[point + i];
            }
            time1 = clock();
            BM(stringline, form);
            tmm += clock() - time1;
        }
        cout << "\nВреме BM " << tmm / colr;

        cout << "\n  KMP имени Слава ";
        tmm = 0;
        for (int k = 0; k < colr; k++) {
            for (int i = 0; i < size_string; i++)
                stringline += char('a' + rand() % ('j' - 'a'));

            int point = (rand() % (size_string - size_form - 2));

            for (int i = 0; i < size_form; i++) {
                form += stringline[point + i];
            }
            time1 = clock();
            fildPow(stringline, form);
            tmm += clock() - time1;
        }

        cout << "Време Sl " << tmm / colr;
        cout << "\n\n";
    }
}