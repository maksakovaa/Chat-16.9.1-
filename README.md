# Chat
Модифицированный Chat, с использованием контейнеров STL и алгоритмом шифрования sha256. \
Реализована проверка успешного выделения памяти, оптимизирован код.

# Команда
Александр Максаков

# Классы
**class UserBase**\
//Функция выводящая список пользователей\
void showUsers()\
//Функия добавления пользователя\
void addUsers()\
//Функция изменяющая пароль\
void chgPwd()\
//Функция возвращающая количество пользователей в базе\
int getUserCount()\
//Функция возвращающая ID пользователя по логину\
int getUserId();
//Функция возвращающая имя пользователя по ID\
std::string getUserName()\
//Функция удаления пользователя\
void delUser()\
//Функция проверки существования в базе пользователя с данным логином\
bool loginCheck()\
//Функция проверки введенного пароля с sha256-хэшем хранящимя в базе\
bool pwdCheck(int userId, std::string pwd)\


**class Chat** \
//Функция ввозвращающая количество сообщений
int getMsgCount() \
//Функция возвращающая вектор с индексами сообщений соответствующим чату
 std::vector<int> getMsgToCount() \
//Функция выводящая сообщение в случае пустой базы сообщений
void emptyMsg() \
 //Функция вывода сообщения \
 void printMsg() \
//Функция выводящая общий чат
void showMain() \
//Функция выводящая личные сообщения
void showPersonal() \
//Функция отправки сообщения
void sendMsg() \

# Навигация
//Главное меню \
**void menu()** \
//Меню регистрации\
**void menuRegUser()** \
//Меню авторизации \
**void menuLogin()** \
//Меню со списком пользователей. Авторизованный пользователь может просматривать и отправлять личные сообщения\
**void menuUserList()** \
//Только для администратора чата. Меню управления базой пользователей \
**void menuUserMgmt()** \
//Функция являющаяся подменю menuUserMgmt(), служит для удаления пользователей \
**void menuDelUser()** \
//Функция проверяющая возможность изменения базы пользователей (для функции смены пароля и удаления пользователя) \
**void chkUsersAv()** \
//Меню являющаяся подменю menuUserMgmt(), служит для смены пароля пользователя
**void menuUsrMgmtSetPwd()**
//Меню для смены пароля пользователя \
**void menuChgPwd()** \
//Меню авторизованного пользователя \
**void menuAuth()** \
//Функция являющаяся подменю menuUserList(), служит для отправки личных сообщений \
**void menuPrivateSendMsg()** \
//Меню общего чата \
**void menuMainChat()** \

# Функции
//Функция выхода из учетной записи \
**void logOut()** \
//Функции обработки некорректного ввода \
**void inputCleaner()** \
**void incorrect()** \
//Функция проверки строки на наличие кириллицы \
**bool nonLatinChk()**
//Функция проверки строки на наличие пробела \
**bool noSpacesChk()**
//Функция проверки строки на длину \
**bool lengthChk()**
//Функция. Проверка логина при регистрации \
**bool regLoginChk()** \
//Функция. Проверка пароля при регистрации \
**bool regPwdChk()** \
//Функция. Проверка пароля при авторизации \
**bool authPwdChk(std::string &_login, std::string &_pwd)** \
//Проверка авторизован ли пользователь \
**bool authStatChk()**
//Проверка авторизован ли администратор \
**bool authAdminStatChk()**
//Завершение программы \
**bool exit()**

# Блок-схема работы программы
![alt text](https://github.com/maksakovaa/Chat-16.9.1-/blob/main/s%D1%81heme.png)
