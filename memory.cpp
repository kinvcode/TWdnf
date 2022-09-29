#include "pch.h"
#include "memory.h"

// 读int类型
int readInt(int address)
{
	int value = *(int*)address;
	return value;
}

// 写入int数据
bool writeInt(int address, int value)
{
	int* p = (int*)address;
	*p = value;
	return true;
}