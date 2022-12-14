//#pragma once
//#include <iostream>
//#include <string>
//extern "C" {
//#include "Lua542/include/lua.h"
//#include "Lua542/include/lauxlib.h"
//#include "Lua542/include/lualib.h"
//
//
//}
//
//#ifdef _WIN32
//#pragma comment(lib,"Lua542/liblua54.a")
//#include <Windows.h>
//#else
//#include <unistd.h>
//#endif
//
//class LuaSystem
//{
//
//public:
//	lua_State* L;
//
//	LuaSystem() {
//		lua_State* L = luaL_newstate();
//		luaL_openlibs(L);
//
//		if (IsValidLuaCommand(L, luaL_dofile(L, "Space.lua"))) 
//		{
//			lua_getglobal(L, "player");
//			if (lua_istable(L, -1)) {
//				float x= GetLuaNumber(L, "x");
//					float y= GetLuaNumber(L, "y");
//					int Colorx1= GetLuaNumberint(L, "Colorx1");
//					int Colorx2 = GetLuaNumberint(L, "Colorx2");
//					int Colorx3 = GetLuaNumberint(L, "Colorx3");
//					int Colory1 = GetLuaNumberint(L, "Colory1");
//					int Colory2 = GetLuaNumberint(L, "Colory2");
//					int Colory3 = GetLuaNumberint(L, "Colory3");
//					int Colorz1 = GetLuaNumberint(L, "Colorz1");
//					int Colorz2 = GetLuaNumberint(L, "Colorz2");
//					int Colorz3 = GetLuaNumberint(L, "Colorz3");
//				//float x = GetLuaNumber(L, "x");
//				//float y = GetLuaNumber(L, "y");
//				//int c1 = GetLuaNumberint(L, "c1");
//				//int c2 = GetLuaNumberint(L, "c2");
//				//int c3 = GetLuaNumberint(L, "c3");
//				
//					/*space.x = x;
//					 space = Space( x,  y,  Colorx1,
//						 Colorx2,  Colorx3,
//						 Colory1,  Colory2,  Colory3,
//						 Colorz1,  Colorz2,  Colorz3);*/
//					//velTest = vel;
//					//regresarPosX = x;
//
//			}
//		}
//
//	}
//	bool IsValidLuaCommand(lua_State* L, int command) {
//		if (command != LUA_OK) {
//			//std::string error_message = lua_tostring(L, -1);
//			std::cout << "Error at executing command: " << command << std::endl;
//			return false;
//		}
//		return true;
//	}
//	float GetLuaNumber(lua_State* L, const char* variable) {
//		lua_pushstring(L, variable);
//		lua_gettable(L, -2);
//		float x = lua_tonumber(L, -1);
//		lua_pop(L, 1);
//		return x;
//	}
//	int GetLuaNumberint(lua_State* L, const char* variable) {
//		lua_pushstring(L, variable);
//		lua_gettable(L, -2);
//		int a = lua_tonumber(L, -1);
//		lua_pop(L, 1);
//		return a;
//	}
//	/*String GetLuaString(lua_State* L, const char* variable) {
//		lua_pushstring(L, variable);
//		lua_gettable(L, -2);
//		char b = lua_tolstring(L, -1);
//		lua_pop(L, 1);
//		return b;
//	}*/
//
//	void Close() {
//		lua_close(L);
//	}
//};
//
//
