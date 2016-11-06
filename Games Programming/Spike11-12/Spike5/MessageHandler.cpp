#include "stdafx.h"
#include "MessageHandler.h"

#include "Player.h"
#include "Bag.h"


MessageHandler::MessageHandler()
{
}

bool MessageHandler::MessagesExist()
{
	return !_messages.empty();
}



Message * MessageHandler::CheckMessage( string reciever)
{
	for each (Message* m in _messages)
	{
		string messageTarget = m->getTarget();
		if (messageTarget == "entity") {
			return m;
		}

		vector<string> ss;
		Utilities::Split(messageTarget, '-', ss);

		if (messageTarget == "node all") {
			return m;
		}

		if (ss[0] == "Node" && ss[1] == "1" || ss[1] == "2"|| ss[1] == "3"|| ss[1] == "4"|| ss[1] == "5") {
			return m;
		}


	}
	return nullptr;
}



void MessageHandler::ClearMessage(Message * mm)
{
	for (int i = 0; i < int(_messages.size()); i++) {
		if (mm == _messages.at(i)) {
			_messages.erase(_messages.begin() + i);
		}
	}

}

void MessageHandler::CreateMessage(Message * message)
{
	_messages.push_back(message);
}




MessageHandler::~MessageHandler()
{
}