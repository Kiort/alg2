#include <iostream>
using namespace std;

/*
    void KMP()
{
    char* string;
    char* form;
    int size_string, size_form = 3;
    cin >> size_string;

    for (int i = 0; i < size_string; i++)
        string[i] = char('a' + rand() % ('j' - 'a'));

    for (int i = 0; i < size_form; i++)
        form[i] = char('a' + rand() % ('j' - 'a'));
    
    find(string; form)
    for (int i = 0; string[i];++i)
    {
        for (int i = 0;form[i]; i++)
        {

        }
    }
} 

*/


/*
int find_substring(char s[], char q[]) {
	int i, j, N, M;
	N = strlen(s);
	M = strlen(q);
	int* d = new int(M); /* динамический массив длины М*/
	/* Вычисление префикс-функции */  /*
	i = 0;
	j = -1;
	d[0] = -1;
	while ((i == 0) && (q[j] != q[i])){
	    j = d[j];
	    i++;
	    j++;
	    if (q[i] == q[j])
		    d[i] = d[j];
	    else
		    d[i] = j;
    }
    /* поиск */  /*
    while (i = 0, j = 0, (i = 0) && (q[j] != s[i]))
        j = d[j];
        delete(d); /* освобождение памяти массива d */ /*
        if (j == M)
        return i - j;
        else /* i==N */ /*
        return -1;
    }

*/

int find(string stringline, string form)
{
    // i-с какого места строки  ищем
    // j-с какого места образца ищем
    for (int i = 0; form[i]; ++i) {
        for (int j = 0;; ++j) {
            if (form[i + j] == stringline[j]) return i; // образец найден 
            if (form[i + j] != stringline[j]) break;
        }
        // пока не найден, продолжим внешний цикл
    }
    // образца нет
    return -1;
}


void fildPow(string stringline, string form) {
    bool flag = false;
    bool flagToe = false;

    for (int i=0; i<stringline.length(); i++) {

        for (int j=0; j<form.length(); j++) {
            if (form[j] == stringline[i]) {
                flag = true;
            }
            else { 
                flag = false;
                break; 
            }
        }
        if (flag) {
            flagToe = true;
            cout << "\nПодстрока найдена  " << i;
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

    cout << "\nПроверка\n";

    fildPow(stringline, form);
   


}