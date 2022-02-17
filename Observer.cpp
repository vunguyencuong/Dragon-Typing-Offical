#include "Observer.h"

void Subscriber::notify(Publisher* publisher)
{

}


void Publisher::addSubscriber(Subscriber* s)
{
	subscribers.push_back(s);
}

void Publisher::callNotify()
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->notify(this);
	}
}