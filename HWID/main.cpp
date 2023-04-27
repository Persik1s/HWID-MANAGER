#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

#include "hwid.hpp"
#include "utils/utils.hpp"


HWIDManager hwid("https://pastebin.com/raw/XtZm3d8D");


bool main() {

	std::cout << md5(hwid.GetHWID()) << std::endl;


	std::cout << "-----------------------" << std::endl;


	hwid.CheckHWID();
	getchar();


}