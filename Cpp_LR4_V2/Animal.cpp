#include "Animal.h"

bool _flag_e = true;
std::string Animal::getType()
{
	switch (type)
	{
	case Cat_t:
		return "Cat";
	case Dog_t:
		return "Dog";
	case Wombat_t:
		return "Wombat";
	}
}

std::string Animal::getName()
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->getName();
	case Dog_t:
		return ((Dog*)animal)->getName();
	case Wombat_t:
		return ((Wombat*)animal)->getName();
	}
}
int Animal::getAge()
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->getAge();
	case Dog_t:
		return ((Dog*)animal)->getAge();
	case Wombat_t:
		return ((Wombat*)animal)->getAge();
	}
}
int Animal::getSatiety()
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->getSatiety();
	case Dog_t:
		return ((Dog*)animal)->getSatiety();
	case Wombat_t:
		return ((Wombat*)animal)->getSatiety();
	}
}

int Animal::getFatigue()
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->getFatigue();
	case Dog_t:
		return ((Dog*)animal)->getFatigue();
	case Wombat_t:
		return ((Wombat*)animal)->getFatigue();
	}
}

void Animal::decreaseSatiety(float visit)
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->decreaseSatiety(visit);
	case Dog_t:
		return ((Dog*)animal)->decreaseSatiety(visit);
	case Wombat_t:
		return ((Wombat*)animal)->decreaseSatiety(visit);
	}
}

void Animal::increaseFatigue(float visit)
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->increaseFatigue(visit);
	case Dog_t:
		return ((Dog*)animal)->increaseFatigue(visit);
	case Wombat_t:
		return ((Wombat*)animal)->increaseFatigue(visit);
	}
}
void Animal::eatingRoom()
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->eatingRoom();
	case Dog_t:
		return ((Dog*)animal)->eatingRoom();
	case Wombat_t:
		return ((Wombat*)animal)->eatingRoom();
	}
}
void Animal::restRoom()
{
	switch (type)
	{
	case Cat_t:
		return ((Cat*)animal)->restRoom();
	case Dog_t:
		return ((Dog*)animal)->restRoom();
	case Wombat_t:
		return ((Wombat*)animal)->restRoom();
	}
}