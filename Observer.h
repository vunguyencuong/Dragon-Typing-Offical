#pragma once
#include <vector>

class Publisher; // forward declaration

class Subscriber
{
public:
	virtual void notify(Publisher* publisher);
};

class Publisher
{
	std::vector<Subscriber*> subscribers;
public:
	void addSubscriber(Subscriber* s);
	void callNotify();
};