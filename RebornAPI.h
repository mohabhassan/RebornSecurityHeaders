#pragma once

#ifdef REBORNSECURITYFIXES_EXPORTS
#define REBORNSECURITYFIXES_API __declspec(dllexport)
#else
#define REBORNSECURITYFIXES_API __declspec(dllimport)
#endif

class RebornImports
{
public:

};

class RebornExports
{
public:

};

REBORNSECURITYFIXES_API RebornExports* GetRebornAPI(RebornImports* import);