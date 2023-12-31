#pragma once
#include "UserBase.h"
#include <time.h>

struct Message
{
	string msgTo;
	string msgFrom;
	string msgDate;
	string msg;
	Message(string msgTo_, string msgFrom_, string msg_) : msgTo(msgTo_), msgFrom(msgFrom_), msg(msg_)
	{
		time_t now = time(NULL);
		char str[26];
		ctime_s(str, 26, &now);
		msgDate = str;
	}
};

class Chat
{
public:
	Chat();
	~Chat();
	int getMsgCount();
	std::vector<int> getMsgToCount(string msgFrom, string msgTo);
	void emptyMsg();
	void printMsg(std::vector<int>& msgIndex);
	void showMain();
	void showPersonal(string user1, string user2);
	void sendMsg(string msgTo, string msgFrom, string& msg);
private:
	std::vector<Message>* msgBase;
};