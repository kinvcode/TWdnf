#include "pch.h"
#include "memory.h"

// ��int����
int readInt(int address)
{
	int value = *(int*)address;
	return value;
}

// д��int����
bool writeInt(int address, int value)
{
	int* p = (int*)address;
	*p = value;
	return true;
}