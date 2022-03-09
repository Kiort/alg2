#include <iostream>
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
            else
                flag = false;
      
        if (flag) {
            cout << "\nподстрока найдена" << i-1;
            break;
        }
        i += j+1;
    }


}

int find(string stringline, string form)
{
    // i-с какого места строки  ищем
    // j-с какого места образца ищем
    for (int i = 0; i < stringline.length(); ++i) {
        for (int j = 0;; ++j) {
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
  //              cout <<"\n\n" <<form[j]<<" "<<stringline[i+j];
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
            cout << "\nПодстрока найдена  " << i+1<<"  "<<stringline[i]<< stringline[i+1];
        }
    }
    if (!flagToe)
        cout << "\n Подстрока не найдена";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    string stringline;
    string form;
    int size_string, size_form = 2;
    cout << "Введите колисчество элементов в строке: ";
    cin >> size_string;
    
    for (int i = 0; i < size_string; i++)
        stringline += char('a' + rand() % ('j' - 'a'));

    for (int i = 0; i < size_form; i++)
        form += char('a' + rand() % ('j' - 'a'));
    


    int point = (rand() % size_string)-3;

    form[0] = stringline[point];
    form[1] = stringline[point+1];


    cout << "\n Подстрока 1 " << stringline << "\n Подстрока 2 " << form;

    if (find(stringline, form) != -1) {
        cout << "\nНайдено на позиции " << find(stringline, form) + 1;
    }
    else {
        cout << "\nПодстрока не найдена";
    }

    cout << "\n\n\nBM";
    BM(stringline, form);

    cout << "\nПроверка\n";

    fildPow(stringline, form);
   


}