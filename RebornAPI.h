#pragma once

#ifdef REBORNSECURITYFIXES_EXPORTS
//#define REBORNSECURITYFIXES_API __declspec(dllexport)
#include "dgamex86.h"
//#else
//#define REBORNSECURITYFIXES_API __declspec(dllimport)
#endif

class RebornImports
{
public:

	void*	(*MemoryMalloc)(int size);
	void	(*MemoryFree)(void* ptr);

	cvar_t* (*Cvar_Get)(const char* varName, const char* varValue, int varFlags);

	int (*Milliseconds)();

	void (*KickClient)(int client_num, const char* reason, const char* public_reason);

	void (*Printf)(const char* format, ...);
	void (*centerprintf)(gentityAA_t* ent, const char* format, ...);

	void (*Trace)(trace_t* results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentMask, qboolean cylinder, qboolean traceDeep);

	void(*AddCommand)(const char* cmdName, xcommand_t cmdFunction);

	bool (*HookFunction)(_Inout_ PVOID* ppPointerOriginal, _In_ PVOID pDetour);
	bool (*UnHookFunction)(_Inout_ PVOID* ppPointerOriginal, _In_ PVOID pDetour);
};

class RebornExports
{
public:
	//Reborn should return reason string to deny player or NULL to allow player.
	//Reason must live even out of RB_PreClientConnect's scope
	char*	(*RB_PreClientConnect)(int clientNum, qboolean firstTime);

	//Reborn should return false to stop executing ClientThink or true to allow execution.
	bool	(*RB_PreClientThink)(gentityAA_t* ent, userCmd_t* ucmd, userEyes_t* eyeInfo);

	//Nothing special here.
	void	(*RB_ClientUserinfoChanged)(gentityAA_t* ent, char* userInfo);

	//Nothing special here.
	void	(*RB_InitGame)(int startTime, int randomSeed);

	//Nothing special here.
	void	(*RB_ClientDisconnect)(gentityAA_t* ent);

};

RebornExports* GetRebornAPI(RebornImports* imports);