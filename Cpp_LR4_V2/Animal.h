#pragma once

enum Types
{
	Cat, Dog, Wombat
};

class Animal
{
	void* animal = nullptr;
	Types type;
};