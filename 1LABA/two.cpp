/* Задание 1 Возведение в степень
#include <iostream>
using namespace std;

int main() {
    double base;
    int exponent;

    cout << "Введите число: ";
    cin >> base;

    cout << "Введите степень (целое число): ";
    cin >> exponent;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    double result = 1;

    if (exponent > 0) {
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
    } else if (exponent < 0) {
        for (int i = 0; i < -exponent; ++i) {
            result *= base;
        }
        result = 1 / result;
    }

    cout << base << " в степени " << exponent << " = " << result << "\n";

    return 0;
} */

/*Задание 2 Дан диапазон от 0 до n
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите число правую границу диапазона (n): ";
    cin >> n;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    int sum = 0;

    if (n >= 0) {
        for (int i = 0; i <= n; i += 5) {
            sum += i;
        }
    } else {
        for (int i = 0; i >= n; i -= 5) {
            sum += i;
        }
    }

    cout << "Сумма: " << sum << "\n";
    return 0;
} */

/* Задание 3 Произвольный текст с порядковым номером буквы
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int k, m;

    cout << "Введите произвольный текст: ";
    getline(cin, text);

    cout << "Введите порядковый номер k: ";
    cin >> k;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    if (k < 1 || k > (int)text.length()) {
        cout << "Ошибка: номер k вне диапазона текста (1.."
             << text.length() << ").\n";
        return 1;
    }

    cout << "Символ под номером " << k << ": " << text[k - 1] << "\n";

    cout << "Введите порядковый номер m: ";
    cin >> m;

    if (cin.fail() || m < k || m > (int)text.length()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    cout << "Подстрока от " << k << " до " << m << ": ";
    for (int i = k - 1; i < m; i++) {
        cout << text[i];
    }
    cout << "\n";

    return 0;
} */

/*Задание 4 Калькулятор ИМТ
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight, height;

    cout << "Введите вес (кг): ";
    cin >> weight;

    cout << "Введите рост (м) через точку: ";
    cin >> height;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    if (height <= 0) {
        cout << "Ошибка: рост должен быть больше нуля.\n";
        return 1;
    }

    double bmi = weight / (height * height);

    cout << fixed << setprecision(1);
    cout << "Ваш ИМТ: " << bmi << "\n";

    return 0;
} */

/* Задание 5 Конвертер систем счисления
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string perevod_v_lyubuyu(long long chislo, int osnovanie) {
    if (chislo == 0) {
        return "0";
    }

    string cifry = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string znak = "";

    if (chislo < 0) {
        znak = "-";
        chislo = abs(chislo);
    }

    string resultat = "";

    while (chislo > 0) {
        int ostatok = chislo % osnovanie;
        resultat = cifry[ostatok] + resultat;
        chislo = chislo / osnovanie;
    }

    return znak + resultat;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int from_base, to_base;
    string number;

    cout << "Введите исходную систему счисления (2-36): ";
    cin >> from_base;

    cout << "Введите целевую систему счисления (2-36): ";
    cin >> to_base;

    cout << "Введите число в " << from_base << "-ричной системе: ";
    cin >> number;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    long long desyatichnoe = stoll(number, nullptr, from_base);

    string otvet = perevod_v_lyubuyu(desyatichnoe, to_base);

    cout << number << " (осн. " << from_base << ") = "
         << otvet << " (осн. " << to_base << ")" << endl;

    return 0;
} */

 /* Задание 6 Обработка строки
#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>   
using namespace std;

int main() {
    string text;

    cout << "Введите строку: ";
    getline(cin, text);

    if (cin.fail() || text.empty()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int puncts = 0;

    for (int i = 0; i < (int)text.length(); i++) {
        unsigned char c = text[i];

        if (isalpha(c)) {
            letters++;
        } else if (isdigit(c)) {
            digits++;
        } else if (c == ' ' || c == '\t') {
            spaces++;
        } else if (ispunct(c)) {
            puncts++;
        } else {
            letters++;
        }
    }

    cout << "\n--- Статистика ---\n";
    cout << "Букв:               " << letters << "\n";
    cout << "Цифр:               " << digits  << "\n";
    cout << "Пробелов:           " << spaces  << "\n";
    cout << "Знаков препинания:  " << puncts  << "\n";

    return 0;
} */

/* Задание 7 Работа с датой
#include <iostream>
using namespace std;

int main() {
    int day, month, year;
    int curDay, curMonth, curYear;

    cout << "Введите дату рождения числом (день месяц год через пробел): ";
    cin >> day >> month >> year;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    cout << "Введите текущую дату числом (день месяц год через пробел): ";
    cin >> curDay >> curMonth >> curYear;

    if (cin.fail()) {
        cout << "Ошибка: неправильно введены данные.\n";
        return 1;
    }

    int age = curYear - year;

    if (curMonth < month || (curMonth == month && curDay < day)) {
        age--;
    }

    cout << "Ваш возраст: " << age << " лет\n";

    return 0;
} */