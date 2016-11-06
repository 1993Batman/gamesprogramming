#include "stdafx.h"
#include "Message.h"

Message::Message(string target, string action, string sender)
{
	_target = target;

	_action = getAction(action);
	_sender = sender;
}

MessageTypes Message::getAction() const
{
	return _action;
}

string Message::getSender() const
{
	return _sender;
}

string Message::getTarget() const
{
	return _target;
}

Message::~Message()
{
}

MessageTypes Message::getAction(string action)
{

	if (action == "have a nice fall")
	{
		return MessageTypes::Attack;
	}
	else if (action == "move") {
		return MessageTypes::Move;
	}
	else {
		return MessageTypes::UnknownVal;
	}
}