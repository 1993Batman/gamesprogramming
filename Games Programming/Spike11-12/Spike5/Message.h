#pragma once
#include "MessageTypes.h"
class Message
{
private:

	string _target;
	MessageTypes _action;
	string _sender;
public:
	Message(string target, string action, string sender);

	enum MessageTypes getAction() const;
	string getSender() const;
	string getTarget() const;


	static MessageTypes getAction(string action);

	~Message();
};
