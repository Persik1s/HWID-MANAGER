#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include "utils/utils.hpp"
#include "utils/md5.h"
using namespace utils;
class HWIDManager {

private:
	std::string urlDownload;
	std::string newHWID;
	std::string hwid;

	char massHWID[200];
	char namePC[3000];
	DWORD size = 3000;

public:
	HWIDManager(std::string HWIDURL) {
		urlDownload = downloadeString(HWIDURL.c_str());
		for (int i = 0; i <= 200; i++) {
			massHWID[i] += urlDownload[i];
		}

		// PC NAME 
		if (GetUserNameA(namePC, &size));
	}

	HWIDManager() {
		if (GetUserNameA(namePC, &size));
	}




	inline std::string GetUserNameL() {
		return namePC;
	}

	//COMPUTERNAME
	inline std::string GetPCName() {
		std::string name = getenv("COMPUTERNAME");
		return name;
	}
	
	//PROCESSOR_ARCHITECTURE
	inline std::string GetPR_ARCHITECTURE() {
		std::string name = getenv("PROCESSOR_ARCHITECTURE");
		return name;
	}

	//PROCESSOR_REVISION
	inline std::string GetPR_REVISION() {
		std::string name = getenv("PROCESSOR_REVISION");
		return name;
	}

	//PROCESSOR_LEVEL
	inline std::string GetPR_LEVEL() {
		std::string name = getenv("PROCESSOR_LEVEL");
		return name;
	}


	inline std::string GetHWID() {
		std::string hwid = GetUserNameL() + GetPCName() + GetPR_ARCHITECTURE()  + GetPR_REVISION() + GetPR_LEVEL();
		return hwid;
	}


	void CheckHWID() {
		for (int i = 0; i < urlDownload.size(); i++)
		{
			if (massHWID[i] == '\r') {
				i += 1;
				if (massHWID[i] == '\n')
				{
					i += 1;
				
					if (newHWID == md5(GetHWID())) {
						std::cout << "[ SUCCESSFUL ]" << std::endl;
					}
					newHWID.clear();
				}
				
			}
			newHWID += massHWID[i];
		}
	}
	
};