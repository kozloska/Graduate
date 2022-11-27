#include <iostream>
#include <string>
#include <vector>
#include <iomanip>     
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <iomanip>
using namespace std;

struct graduate {
    string surname;//фамилия абиртуриента
    string name;//имя абиртуриента
    string patronymic;//отчетсво абиртуриента
    int year; // год рождения абиртуриента
    string averagescore; //ср балл атеста
    vector <int> rating;//оценки экзаменов
    string medal;//медаль
    string specialization;//специальность
    graduate(string _surname, string _name, string _patronymic, int _year, string _averagescore, vector <int> _rating, string _medal, string _specialization) {
        surname = _surname;
        name = _name;
        patronymic = _patronymic;
        year = _year;
        averagescore = _averagescore;
        rating = _rating;
        medal = _medal;
        specialization = _specialization;
    }
    graduate() {
       surname = name = patronymic = averagescore = medal = specialization = "";
        year = 0;
        rating.clear();
    }
    string ToString() {
        int summa = rating[0] + rating[1] + rating[2];
        return surname + " " + name + " " + patronymic + " " + to_string(year) + " " + averagescore + " " + to_string(rating[0]) + " " + to_string(rating[1]) + " " +  to_string(rating[2]) + " " + medal + " " + specialization;
    }
}; 
vector <graduate> vec1;
vector <graduate> vecIST;
vector <graduate> vecACY;
vector <graduate> vecIB;
vector <graduate> vecEVM;

string checkstring(string message) {
    bool flag = true;
    string answer;
    int count = 0;
    while (flag) {
        count = 0;
        cout << message;
        cin >> answer;
        for (int i = 0; i < answer.size(); i++) {
            for (int digit = '0'; digit <= '9'; digit++) {
                if (answer[i] == digit) {
                    count++;
                }
            }
        }
        if (count > 0) {
            flag = true;
            cout << "!/Ошибка ввода/!" << endl;
        }
        else {
            flag = false;
        }
    }
    return answer;
}

string checkstring2(string message) {
    bool flag = true;
    string answer;
    int count = 0;
    while (flag) {
        count = 0;
        cout << message;
        cin >> answer;
        for (int i = 0; i < answer.size(); i++) {
            for (int digit = '0'; digit <= '9'; digit++) {
                if (answer[i] == digit) {
                    count++;
                }
            }
        }
        if (count == answer.size()-1 || count == answer.size()) {
            flag = false;
        }
        else {
            flag = true;
            cout << "!/Ошибка ввода/!" << endl;
        }
    }
    return answer;
}

int checkint(string message) {
    bool flag = true;
    string number;
    int count = 0, answer = 0;
    while (flag) {
        count = 0;
        cout << message;
        cin >> number;
        for (int i = 0; i < number.size(); i++) {
            for (int digit = '0'; digit <= '9'; digit++) {
                if (number[i] == digit) {
                    count++;
                }
            }
        }
        if (count == number.size()) {
            flag = false;
            answer = stoi(number);
        }
        else {
            cout << "!/Ошибка ввода/!" << endl;
        }
    }
    return answer;
}

void addgraduate() {
    graduate graduate1;
    int number;
    string message;
    vector <int> vecrating;
    graduate1.surname = checkstring("Введите фамилию абитуриента: ");
    graduate1.name = checkstring("Введите имя абитуриента: ");
    graduate1.patronymic = checkstring("Введите отчество абитуриента: ");
    graduate1.year = checkint("Введите год рождения абитуриента: ");
    graduate1.averagescore = checkstring2("Введите средний балл аттестата абитуриента: ");
    cout << "Введите через пробел результаты трёх вступительных экзаменов" << endl;
    for (int i = 0; i < 3; i++) {
        number = i + 1;
        message = "Введите " + to_string(number) + "оценку: ";
        number = checkint(message);
        vecrating.push_back(number);
    }
    graduate1.rating = vecrating;
    graduate1.medal = checkstring("Введите какая медаль у абитуриента: ");
    graduate1.specialization = checkstring("Введите специальность, выбранную абитуриентом: ");
    vec1.push_back(graduate1);
}

string linerating(int k, vector <graduate> vec) {
    string _rating = "";
    for (int i = 0; i < 3; i++) {
        _rating = _rating + to_string(vec[k].rating[i]) + " ";
    }
    return _rating;
}

void printgraduate() {
    int size = vec1.size();
    cout << endl;
    for (int i = 0; i < size; i++) {
        string _rating = linerating(i, vec1);
        cout << left << setw(18) << vec1[i].surname
        << left << setw(18) << vec1[i].name
        << left << setw(18) << vec1[i].patronymic
        << left << setw(18) << vec1[i].year
        << left << setw(18) << vec1[i].averagescore
        << left << setw(18) << _rating
        << left << setw(18) << vec1[i].medal
        << left << setw(18) << vec1[i].specialization
        << endl;
    }
}

void printonegraduate(int i) {
    string _rating = linerating(i, vec1);
        cout << left << setw(12) << vec1[i].surname
        << left << setw(12) << vec1[i].name
        << left << setw(12) << vec1[i].patronymic
        << left << setw(12) << vec1[i].year
        << left << setw(12) << vec1[i].averagescore
        << left << setw(12) << _rating
        << left << setw(12) << vec1[i].medal
        << left << setw(12) << vec1[i].specialization
        << endl;
}

void removalsurname(string _surname) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_surname == vec1[i].surname) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void removalname(string _name) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_name == vec1[i].name) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}


void removalpatronymic(string _patronymic) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_patronymic == vec1[i].patronymic) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void removalyear(int _year) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_year == vec1[i].year) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void removalaveragescore(string _averagescore) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_averagescore == vec1[i].averagescore) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void removalmedal(string _medal) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_medal == vec1[i].medal) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void removalspecialization(string _specialization) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (_specialization == vec1[i].specialization) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void removalrating(vector <int> _rating) {
    int size = vec1.size(), count = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int k = 0; k < 3; k++) {
            if (_rating[k] == vec1[i].rating[k]) {
                count++;
            }
        }
        if (count == 3) {
            vec1.erase(vec1.cbegin() + i);
            size--;
        }
    }
}

void printyear() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].year > vec1[k].year) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printsurname() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].surname > vec1[k].surname) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printname() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].name > vec1[k].name) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printpatronymic() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].patronymic > vec1[k].patronymic) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printmedal() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].medal < vec1[k].medal) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printrating() {
    graduate graduate1;
    int summa1, number, a;
    int size = vec1.size();
    vector <int> summa;
    for (int i = 0; i < size; i++) { 
        summa1 = 0;
        for (int k = 0; k < 3; k++) {
            summa1 = summa1 + vec1[i].rating[k];
        }
        summa.push_back(summa1);
    }
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (summa[a] < summa[k]) {
                a = k;
            }
        }
        if (a != i) {
            number = summa[i];
            summa[i] = summa[a];
            summa[a] = number;
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printaveragescore() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].averagescore < vec1[k].averagescore) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void printspecialization() {
    graduate graduate1;
    int a;
    int size = vec1.size();
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (vec1[a].specialization > vec1[k].specialization) {
                a = k;
            }
        }
        if (a != i) {
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    printgraduate();
}

void searchyear(int _year) {
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (vec1[i].year == _year) {
            printonegraduate(i);
        }
    }
}

void searchsurname(string _surname) {
    bool flag;
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].surname == _surname == true) {
            printonegraduate(i);
        }
    }
}

void searchname(string _name) {
    bool flag;
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].name == _name == true) {
            printonegraduate(i);
        }
    }
}

void searchpatronymic(string _patronymic) {
    bool flag;
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].patronymic == _patronymic == true) {
            printonegraduate(i);
        }
    }
}

void searchrating(vector <int> _rating) {
    bool flag;
    int size = vec1.size(), count = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int k = 0; k < 3; k++) {
            if (_rating[k] == vec1[i].rating[k]) {
                count++;
            }
        }
        if (count == 3) {
            printonegraduate(i);
        }
    }
}

void searchmedal(string _medal) {
    bool flag;
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].medal == _medal == true) {
            printonegraduate(i);
        }
    }
}

void searchspecialization(string _specialization) {
    bool flag;
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].specialization == _specialization == true) {
            printonegraduate(i);
        }
    }
}

void searchaveragescore(string _averagescore) {
    bool flag;
    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].averagescore == _averagescore == true) {
            printonegraduate(i);
        }
    }
}

string namefile = ""; 

vector <string> ReadAllText(string namefile) {
    vector <string> output;
    ifstream reading(namefile);
    string line;
    while (getline(reading, line)) {
        output.push_back(line);
    }
    return output;
}

void WriteAllText(vector <graduate> graduates, string fileName) {
    ofstream fout;
    fout.open(fileName);
    if (fout.is_open() == false) {
        cout << "Не удалось открыть файл!" << endl;
    }
    else {
        for (int i = 0; i < graduates.size(); i++) {
            fout << graduates[i].ToString() + "\n";
        }
    }
    fout.close();
}

void addfail(vector <graduate> vec) {
    string name;
    cout << "Введите название файла, в который нужно сохранить: ";
    cin >> name;
    ofstream out;
    out.open(name, ofstream::app);
    if (out.is_open()) {
        for (int i = 0; i < vec.size(); i++) {
            out << vec1[i].ToString() << endl;
        }
    }
    out.close();
}

bool IsDataFileExists(string fileName) {
    ifstream iff;
    iff.open(fileName);
    bool isFileExists = iff.is_open();
    iff.close();
    return isFileExists;
}

vector<string> Split(string line, char delimiter) {
    vector<string> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;  
}

graduate* ParseVoucher(vector<string> properties) {
    int year = atoi(properties[3].c_str());
    vector <int> _rating;
    int summa = atoi(properties[5].c_str());
    _rating.push_back(summa);
    summa = atoi(properties[6].c_str());
    _rating.push_back(summa);
    summa = atoi(properties[7].c_str());
    _rating.push_back(summa);
    return new graduate(properties[0], properties[1], properties[2], year, properties[4], _rating, properties[8], properties[9]);
}

vector <graduate> ReadData(string dataFileName) {
    if (IsDataFileExists(dataFileName) == false) {
        cout << "Файл не существует!" << endl;
        return vector<graduate>();
    }
    auto data = vector<graduate>();
    ifstream reading(dataFileName);
    string line;
    while (getline(reading, line)) {
        data.push_back(*ParseVoucher(Split(line, ' ')));
    }
    return data;
}


void change() {
    vector <int> vecrating;
    int number;
    string message;
    int n, choice;
    cout << endl;
    cout << "Введите номер абитуриента, у которого надо изменить данные: ";
    cout << endl;
    cin >> n;
    n = n - 1;
    cout << "Что вы хотите изменить?     " << endl;
    cout << "1 - Фамилию абитуриента" << endl;
    cout << "2 - Имя абитуриента" << endl;
    cout << "3 - Отчество абитуриента" << endl;
    cout << "4 - Год рождения абитуриента" << endl;
    cout << "5 - Средний балл аттестата абитуриента" << endl;
    cout << "6 - Результаты трёх вступительных экзаменов" << endl;
    cout << "7 - Наличие медали у абитуриента" << endl;
    cout << "8 - Специальность, выбранную абитуриентом" << endl;
    cout << "Вы ввели -->  ";
    cin >> choice;
    cout << endl;
    if (choice == 1) {
        vec1[n].surname = checkstring("Введите фамилию абитуриента: ");
    }
    if (choice == 2) {
        vec1[n].name = checkstring("Введите имя абитуриента: ");
    }
    if (choice == 3) {
        vec1[n].patronymic = checkstring("Введите отчество абитуриента: ");
    }
    if (choice == 4) {
        vec1[n].year = checkint("Введите год рождения абитуриента: ");
    }
    if (choice == 5) {
        vec1[n].averagescore = checkstring2("Введите средний балл аттестата абитуриента: ");
    }
    if (choice == 6) {
        cout << "Введите через пробел результаты трёх вступительных экзаменов" << endl;
        for (int i = 0; i < 3; i++) {
            number = i + 1;
            message = "Введите " + to_string(number) + "оценку: ";
            number = checkint(message);
            vecrating.push_back(number);
        }
        vec1[n].rating = vecrating;
    }
    if (choice == 7) {
        vec1[n].medal = checkstring("Введите какая медаль у абитуриента: ");
    }
    if (choice == 8) {
        vec1[n].specialization = checkstring("Введите специальность, выбранную абитуриентом: ");
    }
}

string namevec() {
    string name = "";
    int size = vec1.size(), count = 0, maxdigit = 0, index;
    vector <int> vecname;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size; j++) {
            if (i != j) {
                if (vec1[i].name == vec1[j].name) {
                    count++;
                }
            }
        }
        vecname.push_back(count);
    }
    for (int i = 0; i < size; i++) {
        if (vecname[i] > maxdigit) {
            maxdigit = vecname[i];
            index = i;
        }
    }
    if (maxdigit > 0) {
        name = "Часто повторяющееся имя: " + vec1[index].name;
    }
    else {
       name = "Нет повторяющегося имени";
    }
    return name;
}

void vec() {
    bool flag;
    int size = vec1.size(), count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    graduate graduate1;
    int summa1, number, a;
    vector <int> summa;
    for (int i = 0; i < size; i++) {
        summa1 = 0;
        for (int k = 0; k < 3; k++) {
            summa1 = summa1 + vec1[i].rating[k];
        }
        summa.push_back(summa1);
    }
    for (int i = 0; i < size - 1; i++) {
        a = i;
        for (int k = i + 1; k < size; k++) {
            if (summa[a] < summa[k]) {
                a = k;
            }
        }
        if (a != i) {
            number = summa[i];
            summa[i] = summa[a];
            summa[a] = number;
            graduate1 = vec1[i];
            vec1[i] = vec1[a];
            vec1[a] = graduate1;
        }
    }
    for (int i = 0; i < size; i++) {
        if (flag = vec1[i].specialization == "АСУ" == true && count1 < 11) {
            vecACY.push_back(vec1[i]);
            count1++;
        }
        if (flag = vec1[i].specialization == "ЭВМ" == true && count2 < 11) {
            vecEVM.push_back(vec1[i]);
            count2++;
        }
        if (flag = vec1[i].specialization == "ИСТ" == true && count3 < 11) {
            vecIST.push_back(vec1[i]);
            count3++;
        }
        if (flag = vec1[i].specialization == "ИБ" == true && count4 < 11) {
            vecIB.push_back(vec1[i]);
            count4++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int _year, choice, choice5, choice52, choice6, choice7, choice14, choice16, number;
    string name, _surname, _name, _patronymic, _averagescore, _medal, _specialization, file, message;
    vector <string> lines;
    vector <graduate> vector2;
    vector <int> _rating;
    graduate x1;                                   
    x1.surname = "Кругликов"; x1.name = "Яков"; x1.patronymic = "Алексеевич"; x1.rating = { 75, 80, 56 };
    x1.year = 2003; x1.averagescore = "4.5"; x1.medal = "-"; x1.specialization = "ИБ";
    vec1.push_back(x1);
    graduate x2;
    x2.surname = "Романов"; x2.name = "Афанасий"; x2.patronymic = "Афанасьевич"; x2.rating = { 89, 71, 66 };
    x2.year = 2001; x2.averagescore = "5"; x2.medal = "золотая"; x2.specialization = "АСУ";
    vec1.push_back(x2); 
    graduate x3;
    x3.surname = "Якин"; x3.name = "Пётр"; x3.patronymic = "Вадимович"; x3.rating = { 45, 57, 53 };
    x3.year = 2003;  x3.averagescore = "3"; x3.medal = "-"; x3.specialization = "АСУ";
    vec1.push_back(x3);
    graduate x4;
    x4.surname = "Белова"; x4.name = "Екатерина"; x4.patronymic = "Александровна"; x4.rating = { 74, 55, 61 };
    x4.year = 2000; x4.averagescore = "4"; x4.medal = "-"; x4.specialization = "ИБ";
    vec1.push_back(x4);
    graduate x5;
    x5.surname = "Александрова"; x5.name = "Мария"; x5.patronymic = "Андреевна"; x5.rating = { 67, 66, 84 };
    x5.year = 2003; x5.averagescore = "5"; x5.medal = "золотая"; x5.specialization = "ИСТ";
    vec1.push_back(x5);
    graduate x6;
    x6.surname = "Ярославцев"; x6.name = "Никита"; x6.patronymic = "Артёмович"; x6.rating = { 74, 44, 40 };
    x6.year = 2003;  x6.averagescore = "4.25"; x6.medal = "-"; x6.specialization = "ЭВМ";
    vec1.push_back(x6);
    graduate x7;
    x7.surname = "Миронов"; x7.name = "Олег"; x7.patronymic = "Сергеевич"; x7.rating = { 48, 55, 56 };
    x7.year = 2003; x7.averagescore = "3.8"; x7.medal = "-"; x7.specialization = "ИБ";
    vec1.push_back(x7);
    graduate x8;
    x8.surname = "Ермилова"; x8.name = "Анастасия"; x8.patronymic = "Алексеевна"; x8.rating = { 54, 66, 69 };
    x8.year = 2003; x8.averagescore = "4"; x8.medal = "-"; x8.specialization = "АСУ";
    vec1.push_back(x8);
    graduate x9;
    x9.surname = "Бобров"; x9.name = "Константин"; x9.patronymic = "Викторович"; x9.rating = { 66, 78, 65 };
    x9.year = 2003;  x9.averagescore = "4.1"; x9.medal = "-"; x9.specialization = "ИСТ";
    vec1.push_back(x9);
    graduate x10;
    x10.surname = "Рьянов"; x10.name = "Сергей"; x10.patronymic = "Денисович"; x10.rating = { 68, 45, 45 };
    x10.year = 2001; x10.averagescore = "3.9"; x10.medal = "-"; x10.specialization = "ЭВМ";
    vec1.push_back(x10);
    graduate x11;
    x11.surname = "Пашкова"; x11.name = "Дарья"; x11.patronymic = "Олеговна"; x11.rating = { 78, 90, 55 };
    x11.year = 2003; x11.averagescore = "4.5"; x11.medal = "-"; x11.specialization = "ИСТ";
    vec1.push_back(x11);
    graduate x12;
    x12.surname = "Аистов"; x12.name = "Пётр"; x12.patronymic = "Александрович"; x12.rating = { 66, 45, 64 };
    x12.year = 2003;  x12.averagescore = "4"; x12.medal = "-"; x12.specialization = "ЭВМ";
    vec1.push_back(x12);
    for (;;) {
        cout << "1 - О программе" << endl;
        cout << "2 - Руководство пользователя" << endl;
        cout << "3 - Вывод задания" << endl;
        cout << "4 - Добавить нового абитуриента" << endl;
        cout << "5 - Вывод списка абитуриентов" << endl;
        cout << "6 - Удалить абитуриента" << endl;
        cout << "7 - Поиск по списку" << endl;
        cout << "8 - Изменение данных" << endl;
        cout << "9 - Вывод проходного балла и списка поступивших" << endl;
        cout << "10 - Вывод самого распространенного имени" << endl;
        cout << "11 - Выбрать файл" << endl;
        cout << "12 - Запись файла" << endl;
        cout << "13 - Чтение файла" << endl;
        cout << "14 - Сохранить файл как" << endl;
        cout << "15 - Сохранить" << endl;
        cout << "16 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cout << endl;
        if (choice == 1) {
            cout << "Версия программного продукта: 1" << endl;
            cout << "Автор: Панасенко Никита Михайлович" << endl;
            cout << "Дата внесения последних изменений: 27.11.2022" << endl;
            cout << endl;
        }
        if (choice == 2) {
            cout << "Введите название файла по руководству пользователя" << endl;
            cout << "Ваш выбор: ";
            cin >> name;
            lines = ReadAllText(name);
            for (int i = 0; i < lines.size(); i++) {
                cout << lines[i] << endl;
                cout << endl;
            }
        }
        if (choice == 3) {
            cout << endl;
           cout << "Задание:  Написать программу «Абитуриенты факультета кибернетики». Струк -" << endl;
           cout << "тура исходных данных: Ф.И.О., год рождения, средний балл аттестата, оценки" << endl;
           cout << "вступительных экзаменов, наличие медали (золотой, серебряной), специаль -" << endl;
           cout << "ность, выбранная абитуриентом. Программа должна вычислить проходной балл " << endl;
           cout << "на каждую из специальностей и выдать список, поступивших бесплатно, если" << endl;
           cout << "плановый набор на каждую специальность составляет 10 человек на бюджетной" << endl;
           cout << "основе. Определить самое распространенное имя." << endl;
           cout << endl;
        }
        if (choice == 4) {
            addgraduate();
            cout << endl;
        }
        if (choice == 5) {
            cout << "1 - Вывод полного неотсортированного списка" << endl;
            cout << "2 - Вывод отсортированного списка" << endl;
            cout << "Ваш выбор: ";
            cin >> choice5;
            cout << endl;
            if (choice5== 1) {
                printgraduate();
            }
            if (choice5 == 2) {
                cout << "По какому параметру вы хотите отсортировать?" << endl;
                cout << "1 - по фамилии абитуриента" << endl;
                cout << "2 - по имени абитуриента" << endl;
                cout << "3 - по отчеству абитуриента" << endl;
                cout << "4 - году рождения абитуриента" << endl;
                cout << "5 - по среднему баллу аттестата абитуриента" << endl;
                cout << "6 - по сумме вступительных экзаменов абитуриента" << endl;
                cout << "7 - по наличию медали у абитуриента" << endl;
                cout << "8 - по специальности, выбранной абитуриентом" << endl;
                cout << "Ваш выбор: ";
                cin >> choice52;
                if (choice52 == 1) {
                    printsurname();
                }
                if (choice52 == 2) {
                    printname();
                }
                if (choice52 == 3) {
                    printpatronymic();
                }
                if (choice52 == 4) {
                    printyear();
                }
                if (choice52 == 5) {
                    printaveragescore();
                }
                if (choice52 == 6) {
                    printrating();
                }
                if (choice52 == 7) {
                    printmedal();
                }
                if (choice52 == 8) {
                    printspecialization();
                }
            }
            cout << endl;
        }
        if (choice == 6) {
            cout << "По какому параметру вы хотите удалить?  " << endl;
            cout << "1 - по фамилии абитуриента" << endl;
            cout << "2 - по имени абитуриента" << endl;
            cout << "3 - по отчеству абитуриента" << endl;
            cout << "4 - году рождения абитуриента" << endl;
            cout << "5 - по среднему баллу аттестата абитуриента" << endl;
            cout << "6 - по оценкам за вступительные экзамены " << endl;
            cout << "7 - по наличию медали у абитуриента" << endl;
            cout << "8 - по специальности, выбранной абитуриентом" << endl;
            cout << "Ваш выбор: ";
            cin >> choice6;
            if (choice6 == 1) {
                cout << "Введите фамилию абитуриента, которого надо удалить: ";
                cin >> _surname;
                removalsurname(_surname);
            }
            if (choice6 == 2) {
                cout << "Введите имя абитуриента, которого надо удалить: ";
                cin >> _name;
                removalname(_name);
            }
            if (choice6 == 3) {
                cout << "Введите отчество абитуриента, которого надо удалить: ";
                cin >> _patronymic;
                removalpatronymic(_patronymic);
            }
            if (choice6 == 4) {
                cout << "Введите год рождения абитуриента, которого надо удалить: ";
                cin >> _year;
                removalyear(_year);
            }
            if (choice6 == 5) {
                cout << "Введите средний балл аттестата абитуриента, которого надо удалить: ";
                cin >> _averagescore;
                removalaveragescore(_averagescore);
            }
            if (choice6 == 6) {
                cout << "Введите через пробел результаты трёх вступительных экзаменов абитуриента, которого надо удалить" << endl;
                for (int i = 0; i < 3; i++) {
                    number = i + 1;
                    message = "Введите " + to_string(number) + "оценку: ";
                    number = checkint(message);
                    _rating.push_back(number);
                }
                removalrating(_rating);
            }
            if (choice6 == 7) {
                cout << "Введите какая медаль у абитуриента, которого надо удалить:: ";
                cin >> _medal;
                removalmedal(_medal);
            }
            if (choice6 == 8) {
                cout << "Введите специальность, выбранную абитуриентом, которого надо удалить: ";
                cin >> _specialization;
                removalspecialization(_specialization);
            }
            printgraduate();
        }
        if (choice == 7) {
            cout << "По какому параметру вы хотите найти?" << endl;
            cout << "1 - по фамилии абитуриента" << endl;
            cout << "2 - по имени абитуриента" << endl;
            cout << "3 - по отчеству абитуриента" << endl;
            cout << "4 - году рождения абитуриента" << endl;
            cout << "5 - по среднему баллу аттестата абитуриента" << endl;
            cout << "6 - по оценкам за вступительные экзамены " << endl;
            cout << "7 - по наличию медали у абитуриента" << endl;
            cout << "8 - по специальности, выбранной абитуриентом" << endl;
            cout << "Ваш выбор: ";
            cin >> choice7;
            if (choice7 == 1) {
                cout << "Введите фамилию абитуриента, которого надо найти: ";
                cin >> _surname;
                searchsurname(_surname);
            }
            if (choice7 == 2) {
                cout << "Введите имя абитуриента, которого надо найти: ";
                cin >> _name;
                searchname(_name);
            }
            if (choice7 == 3) {
                cout << "Введите отчество абитуриента, которого надо найти: ";
                cin >> _patronymic;
                searchpatronymic(_patronymic);
            }
            if (choice7 == 4) {
                cout << "Введите год рождения абитуриента, которого надо найти: ";
                cin >> _year;
                searchyear(_year);
            }
            if (choice7 == 5) {
                cout << "Введите средний балл аттестата абитуриента, которого надо найти: ";
                cin >> _averagescore;
                searchaveragescore(_averagescore);
            }
            if (choice7 == 6) {
                cout << "Введите через пробел результаты трёх вступительных экзаменов, абитуриента, которого надо найти: " << endl;
                for (int i = 0; i < 3; i++) {
                    message = "Введите " + to_string(number) + "оценку: ";
                    number = checkint(message);
                    _rating.push_back(number);
                }
                searchrating(_rating);
            }
            if (choice7 == 7) {
                cout << "Введите какая медаль у абитуриента, которого надо найти: ";
                cin >> _medal;
                searchmedal(_medal);
            }
            if (choice7 == 8) {
                cout << "Введите специальность, выбранную абитуриентом, которого надо найти: ";
                cin >> _specialization;
                searchspecialization(_specialization);
            }
        }
        if (choice == 8) {
            change();
        }
        if (choice == 9) {
            int ball = 0;
            vec();
            cout << "Списки абитуриентов, поступивших по специальности АСУ" << endl;
            cout << "Проходной балл по специальности АСУ: ";
            for (int i = 0; i < 3; i++) {
                ball = ball + vecACY[vecACY.size() - 1].rating[i];
            }
            cout << ball << endl;
            for (int i = 0; i < vecACY.size(); i++) {
                string _rating = linerating(i, vecACY);
                cout << left << setw(18) << vecACY[i].surname
                    << left << setw(18) << vecACY[i].name
                    << left << setw(18) << vecACY[i].patronymic
                    << left << setw(18) << vecACY[i].year
                    << left << setw(18) << vecACY[i].averagescore
                    << left << setw(18) << _rating
                    << left << setw(18) << vecACY[i].medal
                    << left << setw(18) << vecACY[i].specialization
                    << endl;
            }
            cout << endl;
            cout << "Списки абитуриентов, поступивших по специальности ИБ" << endl;
            cout << "Проходной балл по специальности ИБ: ";
            ball = 0;
            for (int i = 0; i < 3; i++) {
                ball = ball + vecIB[vecIB.size() - 1].rating[i];
            }
            cout << ball << endl;
            for (int i = 0; i < vecIB.size(); i++) {
                string _rating = linerating(i, vecIB);
                cout << left << setw(18) << vecIB[i].surname
                    << left << setw(18) << vecIB[i].name
                    << left << setw(18) << vecIB[i].patronymic
                    << left << setw(18) << vecIB[i].year
                    << left << setw(18) << vecIB[i].averagescore
                    << left << setw(18) << _rating
                    << left << setw(18) << vecIB[i].medal
                    << left << setw(18) << vecIB[i].specialization
                    << endl;
            }
            cout << endl;
            cout << "Списки абитуриентов, поступивших по специальности ИСТ" << endl;
            cout << "Проходной балл по специальности ИСТ: ";
            ball = 0;
            for (int i = 0; i < 3; i++) {
                ball = ball + vecIST[vecIST.size() - 1].rating[i];
            }
            cout << ball << endl;
            for (int i = 0; i < vecIST.size(); i++) {
                string _rating = linerating(i, vecIST);
                cout << left << setw(18) << vecIST[i].surname
                    << left << setw(18) << vecIST[i].name
                    << left << setw(18) << vecIST[i].patronymic
                    << left << setw(18) << vecIST[i].year
                    << left << setw(18) << vecIST[i].averagescore
                    << left << setw(18) << _rating
                    << left << setw(18) << vecIST[i].medal
                    << left << setw(18) << vecIST[i].specialization
                    << endl;
            }
            cout << endl;
            cout << "Списки абитуриентов, поступивших по специальности ЭВМ" << endl;
            cout << "Проходной балл по специальности ЭВМ: ";
            ball = 0;
            for (int i = 0; i < 3; i++) {
                ball = ball + vecEVM[vecEVM.size() - 1].rating[i];
            }
            cout << ball << endl;
            for (int i = 0; i < vecEVM.size(); i++) {
                string _rating = linerating(i, vecEVM);
                cout << left << setw(18) << vecEVM[i].surname
                    << left << setw(18) << vecEVM[i].name
                    << left << setw(18) << vecEVM[i].patronymic
                    << left << setw(18) << vecEVM[i].year
                    << left << setw(18) << vecEVM[i].averagescore
                    << left << setw(18) << _rating
                    << left << setw(18) << vecEVM[i].medal
                    << left << setw(18) << vecEVM[i].specialization
                    << endl;
            }
            cout << endl;
        }
        if (choice == 10) {
            message = namevec();
            cout << message << endl;
            cout << endl;
        }
        if (choice == 11) {
            cout << "Введите название файла: ";
            cin >> namefile;
            if (IsDataFileExists(namefile)) {
                cout << "Файл найден!" << endl;
            }
            else {
                cout << "!Файла не существует!" << endl;
            }
            cout << endl;
        }
        if (choice == 12) {
            addfail(vec1);
            cout << endl;
        }
        if (choice == 13) {
            vector2 = ReadData(namefile);
            for (int i = 0; i < vector2.size(); i++) {
                string _rating = linerating(i, vector2);
                cout << left << setw(18) << vector2[i].surname
                    << left << setw(18) << vector2[i].name
                    << left << setw(18) << vector2[i].patronymic
                    << left << setw(18) << vector2[i].year
                    << left << setw(18) << vector2[i].averagescore
                    << left << setw(18) << _rating 
                    << left << setw(18) << vector2[i].medal
                    << left << setw(18) << vector2[i].specialization
                    << endl;
            }
            cout << endl;
        }
        if (choice == 14) {
            cout << "Введите название файла, в который нужно сохранить: ";
            cin >> file;
            if (IsDataFileExists(file)) {
                cout << "Перезаписываем ли файл?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cout << "Ваш выбор: ";
                cin >> choice14;
                if (choice14 == 1) {
                    WriteAllText(vec1, file);
                }
            }
            cout << endl;
        }
        if (choice == 15) {
            if (namefile == "") {
                cout << "!Файл не открыт! !Ошибка!" << endl;
            }
            else {
               WriteAllText(vec1, namefile);
            }
            cout << endl;
        }
        if (choice == 16) {
            if (namefile != "") {
                cout << "Вы хотите сохранить файл? " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cout << "Ваш выбор: ";
                cin >> choice16;
                if (choice16 == 1) {
                    WriteAllText(vec1, namefile);
                }
            }
            break;
        }
    }
}
