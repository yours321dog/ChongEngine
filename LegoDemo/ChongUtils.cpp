/*!
 * \file ChongUtils.cpp
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This is the implement of common functions of ChongUtils
 */

#include "ChongUtils.h"

#include <iostream>
#include <fstream>

bool ChongReadFile(const char* pFileName, string& strOut)
{
	ifstream f(pFileName);

	bool ret = false;

	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			strOut.append(line);
			strOut.append("\n");
		}

		f.close();

		ret = true;
	}
	else {
		printf("File %s open fails!!", pFileName);
	}

	return ret;
}

