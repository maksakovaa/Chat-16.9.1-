#pragma once
#include "functions.h"

extern UserBase* Users;
extern Chat* mainChat;
extern int userId, choice;
extern bool auth;

void menu();
void menuRegUser();
void menuLogin();
void menuUserList();
void menuUserMgmt();
void menuDelUser();
void chkUsersAv();
void menuUsrMgmtSetPwd();
void menuChgPwd(int choice);
void menuAuth();
void menuPrivateSendMsg();
void menuMainChat();