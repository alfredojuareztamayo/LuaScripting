#pragma once
#include <iostream>
#include <string>

extern "C"
{
#include "Lua542/include/lua.h"
#include "Lua542/include/lauxlib.h"
#include "Lua542/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Lua542/liblua54.a")
#endif

class LuaSystem
{
public:

	lua_State* L;

	LuaSystem()
	{
		L = luaL_newstate();
		luaL_openlibs(L);
	}

	void LoadLuaScript(const char *scriptPath)
	{
		if (IsValidLuaCommand(L, luaL_dofile(L, scriptPath)))
		{
			lua_getglobal(L, "player");
			if (lua_istable(L, -1))
			{
				float test = GetLuaNumber(L, "hp");
				std::cout << test << std::endl;
			}
		}
	}

	bool IsValidLuaCommand(lua_State* L, int command)
	{
		if (command != LUA_OK)
		{
			std::cout << "Error at executing command: " << command << std::endl;
			return false;
		}

		return true;
	}

	float GetLuaNumber(lua_State* L, const char* variable)
	{
		lua_pushstring(L, variable);
		lua_gettable(L, -2);
		float x = lua_tonumber(L, -1);
		lua_pop(L, 1);
		return x;
	}

	void Close()
	{
		lua_close(L);
	}
};