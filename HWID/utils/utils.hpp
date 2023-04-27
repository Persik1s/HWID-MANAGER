#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <Wininet.h>
#pragma comment(lib, "wininet.lib")

char massString[150];
namespace utils {
	static std::string downloadeString(std::string url) {
		HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
		HINTERNET urlFile;
		std::string rtn;
		if (interwebs) {
			urlFile = InternetOpenUrlA(interwebs, url.c_str(), NULL, NULL, NULL, NULL);
			if (urlFile) {
				char buffer[2000];
				DWORD bytesRead;

				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				return rtn;
			}
			
		}
	}
}