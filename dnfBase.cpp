#include "pch.h"
#include "dnfBase.h"
#include "memory.h"

int decrypt(int address)
{

	//int eax, ecx, edi, ebx, esi, edx;
	//eax = readInt(address);
	//esi = readInt(0x1AF8D78);// 读解密基址
	//edx = eax;
	//edx = edx >> 0x10;
	//edx = readInt(esi + edx * 4 + 0x24);
	//eax = (__int16)eax;
	//eax = readInt(edx + eax * 4 + 0x2114);
	//eax = (__int16)eax;
	//edx = eax;
	//esi = edx;
	//esi = esi << 0x10;
	//esi = esi + edx;
	//edx = readInt(address + 8);
	//eax = esi ^ edx;
	//return eax;

	int result;
	int address2 = address + 8;
	int address_value = *(int*)address;
	//int address_value = readInt(address);
	int decrypt_address = *(int*)0x1AF8D78;
	//int decrypt_address = readInt(0x1AF8D78);
	//int eax, esi, edx;


	//eax = address_value;
	//esi = decrypt_address;
	//edx = eax;
	//edx = edx >> 0x10;
	//edx = *(int*)(esi + edx * 4 + 0x24);
	////edx = readInt(esi + edx * 4 + 0x24);
	//eax = eax & 0xFFFF;
	//eax = *(int*)(edx + eax * 4 + 0x2114);
	////eax = readInt(edx + eax * 4 + 0x2114);
	//edx = (__int16)eax;
	//esi = edx;
	//esi = esi << 0x10;
	//esi = esi | edx;
	//edx = address2;
	//esi = esi ^ *(int*)edx;
	////esi = esi ^ readInt(edx);
	//return esi;

	__asm {
		mov eax, address_value;
		mov esi, decrypt_address;
		mov edx, eax;
		shr edx, 0x10;
		mov edx, [esi + edx * 4 + 0x24];
		and eax, 0xffff;
		mov eax, [edx + eax * 4 + 0x2114];
		movzx edx, ax;
		mov esi, edx;
		shl esi, 0x10;
		or esi, edx;
		mov edx, address2;
		xor esi, [edx];
		mov result, esi;
	};
	return result;
}

void encrypt(int address, int value)
{
	int encrypt_address = 0x1AF8DB8;
	int address_offset = address + 8;
	int encrypt_value = *(int*)encrypt_address;
	int decrypt_address = 0x1AF8D78;
	int decrypt_value = *(int*)decrypt_address;
	int param1 = 0x1843F98;
	int param2 = 0x1844118;
	int* pValue = &value;

	__asm {
		mov ecx, address;
		mov eax, encrypt_value;
		inc eax;
		mov edx, eax;
		shr edx, 0x8;
		movzx edx, dl;
		movzx edx, [edx * 0x2 + 0x1843F98];
		mov[encrypt_address], eax;
		and eax, 0xFF;
		xor edx, [eax * 0x2 + 0x1844118];
		mov esi, pValue;
		movzx eax, dx;
		movzx edx, [esi + 0x2];
		add dx, [esi];
		xor dx, ax;
		movzx edi, dx;
		mov edx, eax;
		shl eax, 0x10;
		or eax, edx;
		xor eax, [esi];
		mov esi, address_offset; // 出现问题 
		mov[esi], eax;
		mov eax, [ecx];
		mov esi, decrypt_value;
		mov ecx, edi;
		shl ecx, 0x10;
		or ecx, edx;
		mov edx, eax;
		shr edx, 0x10;
		mov edx, [esi + edx * 0x4 + 0x24];
		and eax, 0xFFFF;
		mov[edx + eax * 0x4 + 0x2114], ecx;
	};
}