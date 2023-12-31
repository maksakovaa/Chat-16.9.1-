#pragma once
#include "chat.h"

extern UserBase* Users;
extern Chat* mainChat;
extern int userId, choice;
extern bool auth;

void logOut();
void inputCleaner();
void incorrect();
bool nonLatinChk(string& text);
bool noSpacesChk(string& text);
bool lengthChk(string& text);
bool regLoginChk(string& _login);
bool regPwdChk(string& _pwd);
bool authPwdChk(string& _login, string& _pwd);
bool authStatChk();
bool authAdminStatChk();
bool exit();