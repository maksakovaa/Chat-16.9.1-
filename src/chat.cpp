#include "chat.h"

Chat::Chat()
{
	try
	{
		msgBase = new std::vector<Message>;
	}
	catch (std::bad_alloc& ex)
	{
		cout << "ERROR: caught bad_alloc: " << ex.what() << endl;
	}
}

Chat::~Chat()
{
	delete msgBase;
}

int Chat::getMsgCount()
{
	return msgBase->size();
}

std::vector<int> Chat::getMsgToCount(string msgFrom = "ALL", string msgTo = "ALL")
{
	std::vector<int> msgFromTo;
	if (msgFrom == "ALL" && msgTo == "ALL")
	{
		for (int i = 0; i < getMsgCount(); i++)
		{
			msgFromTo.push_back(i);
		}
	}
	else
	{
		for (int i = 0; i < getMsgCount(); i++)
		{
			if (msgBase->at(i).msgTo == msgTo && msgBase->at(i).msgFrom == msgFrom || msgBase->at(i).msgTo == msgFrom && msgBase->at(i).msgFrom == msgTo)
			{
				msgFromTo.push_back(i);
			}
		}
	}
	return msgFromTo;
}

void Chat::emptyMsg()
{
	std::cout << "Пока здесь еще никто ничего не писал" << std::endl;
}

void Chat::printMsg(std::vector<int>& msgIndex)
{
	int j = 0;
	for (int i = 0; i < msgIndex.size(); i++)
	{
		j = msgIndex[i];
		cout << msgBase->at(j).msgFrom << "\t" << msgBase->at(j).msgDate << msgBase->at(j).msg << "\n" << endl;
	}
}

void Chat::showMain()
{
	if (msgBase->empty())
	{
		emptyMsg();
		return;
	}
	std::vector<int> msgToAll = getMsgToCount();
	if (msgToAll.empty())
	{
		emptyMsg();
		return;
	}
	else
	{
		printMsg(msgToAll);
		return;
	}
}

void Chat::showPersonal(string user1, string user2)
{
	if (msgBase->empty())
	{
		emptyMsg();
		return;
	}
	std::vector<int> msgPersonal = getMsgToCount(user1, user2);
	if (msgPersonal.empty())
	{
		emptyMsg();
		return;
	}
	else
	{
		printMsg(msgPersonal);
		return;
	}
}

void Chat::sendMsg(string msgTo, string msgFrom, string& msg)
{
	Message newMsg(msgTo, msgFrom, msg);
	msgBase->push_back(newMsg);
}