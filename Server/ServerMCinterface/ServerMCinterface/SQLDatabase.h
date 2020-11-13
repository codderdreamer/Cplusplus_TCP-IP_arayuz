#pragma once
#pragma once
#include <iostream>
#ifdef SQLDATABASE_EXPORT
#define SQLDATABASE_API __declspec(dllexport)
#else 
#define SQLDATABASE_API __declspec(dllimport)
#endif

using namespace std;

namespace SQLDatabase
{
	class SQLDatabase
	{
	public:
		static SQLDATABASE_API int createDB(const char* s);
		static SQLDATABASE_API int createTable(const char* s);
		static SQLDATABASE_API int insertData(const char* s, string host, string service, string IpAddress, string OsName,
			string SystemMnaufacturer, string TotalPysicalMemory, string BiosVersion, string Ethernet, string Wifi);
		static SQLDATABASE_API int selectData(const char* s);
		static SQLDATABASE_API int updateData(const char* s);
		static SQLDATABASE_API int deleteData(const char* s);
	};
}