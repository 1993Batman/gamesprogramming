#pragma once
#include "Message.h"

using namespace std;

class MessageHandler
{
private:
	vector<Message*> _messages;

public:
	MessageHandler();
	bool MessagesExist();


	Message* CheckMessage( string reciever);
	void MessageHandler::ClearMessage(Message * m);

	void CreateMessage(Message* message);


	~MessageHandler();
};
