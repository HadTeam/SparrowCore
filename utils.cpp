#include "utils.h"
using namespace Sparrow::utils;

nativesLibraryFile::nativesLibraryFile(const libraryFile&, const nativesLibrary& e) {
    libraryFile(a);
    this->classifiers = e;
}

fileInfo::fileInfo(const QUrl& fileUrl, const QString& filePath, const QString& hash, const qint8& size) : fileUrl(fileUrl), filePath(filePath), hash(hash), size(size)
{

}

LPWSTR ConvertCharToLPWSTR(const char* szString)

{

	int dwLen = strlen(szString) + 1;

	int nwLen = MultiByteToWideChar(CP_ACP, 0, szString, dwLen, NULL, 0);//算出合适的长度

	LPWSTR lpszPath = new WCHAR[dwLen];

	MultiByteToWideChar(CP_ACP, 0, szString, dwLen, lpszPath, nwLen);

	return lpszPath;

}

std::string Sparrow::utils::getSystemName()
{
	std::string vname;
	//先判断是否为win8.1或win10  
	typedef void(__stdcall* NTPROC)(DWORD*, DWORD*, DWORD*);
	HINSTANCE hinst = LoadLibrary(ConvertCharToLPWSTR("ntdll.dll"));
	DWORD dwMajor, dwMinor, dwBuildNumber;
	NTPROC proc = (NTPROC)GetProcAddress(hinst, "RtlGetNtVersionNumbers");
	proc(&dwMajor, &dwMinor, &dwBuildNumber);
	if (dwMajor == 6 && dwMinor == 3)   //win 8.1  
	{
		vname = "Windows 8.1";
		return vname;
	}
	if (dwMajor == 10 && dwMinor == 0)  //win 10  
	{
		vname = "Windows 10";
		return vname;
	}
	//判断win8.1以下的版本  
	SYSTEM_INFO info;                //用SYSTEM_INFO结构判断64位AMD处理器    
	GetSystemInfo(&info);            //调用GetSystemInfo函数填充结构    
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
#pragma warning(disable:4996)  
	if (GetVersionEx((OSVERSIONINFO*)&os))
	{
		//下面根据版本信息判断操作系统名称    
		switch (os.dwMajorVersion)
		{                        //判断主版本号    
		case 4:
			switch (os.dwMinorVersion)
			{                //判断次版本号    
			case 0:
				if (os.dwPlatformId == VER_PLATFORM_WIN32_NT)
					vname = "Windows NT 4.0";  //1996年7月发布    
				else if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
					vname = "Windows 95";
				break;
			case 10:
				vname = "Windows 98";
				break;
			case 90:
				vname = "Windows Me";
				break;
			}
			break;
		case 5:
			switch (os.dwMinorVersion)
			{               //再比较dwMinorVersion的值    
			case 0:
				vname = "Windows 2000";    //1999年12月发布    
				break;
			case 1:
				vname = "Windows XP";      //2001年8月发布    
				break;
			case 2:
				if (os.wProductType == VER_NT_WORKSTATION &&
					info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
					vname = "Windows XP Professional x64 Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0)
					vname = "Windows Server 2003";   //2003年3月发布    
				else if (GetSystemMetrics(SM_SERVERR2) != 0)
					vname = "Windows Server 2003 R2";
				break;
			}
			break;
		case 6:
			switch (os.dwMinorVersion)
			{
			case 0:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows Vista";
				else
					vname = "Windows Server 2008";   //服务器版本    
				break;
			case 1:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 7";
				else
					vname = "Windows Server 2008 R2";
				break;
			case 2:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 8";
				else
					vname = "Windows Server 2012";
				break;
			}
			break;
		default:
			return NULL;
		}
		return vname;
	}
	else
		return NULL;
	return vname;
}
