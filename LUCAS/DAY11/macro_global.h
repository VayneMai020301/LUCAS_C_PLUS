//#pragma once

#ifndef MACRO_GLOBAL_H

#define MACRO_GLOBAL_H  /* 4. Tranh dinh nghia lai*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* ---------------------------------- 1. Khai bao hang so*/
#define PI 3.14

/* ---------------------------------- 2. Macro thay the van ban */

#define MSG_ERROR "This is Error"
#define MSG_INFOR "This is Infor"

/* ---------------------------------- 3. Macro voi tham so */
/* Khai bao ra mot ham */
#define SQUARE(x) ((x)*(x))

/*---------------------------------- 5. Dieu kien bien dich */
#define DEBUG -1


/* ---------------------------------- 6. MACRO long nhau*/
#define MAX(a,b) ((a) > (b) ? (a): (b))
#define MAX4(a,b,c,d) (MAX(a, MAX(b,MAX(c,d))))

/* ---------------------------------- 7. Loai bo Feature */
#define ENABLE_FEATURE_1 0
#define ENABLE_FEATURE_2 1

/* ---------------------------------- 8. Ket hop ky tu */
#define CREATE_VARIABLE(name) int var_##name

/* ---------------------------------- 9. Chuyen token thanh string (Stringizing)*/
#define TO_STRING(x) #x

/* ---------------------------------- 10. Tuy chon platform*/
#ifdef _WIN32
	#define OS_NAME "Window System"

#elif __linux__
	#define OS_NAME "Linux System"

#else
	#define	OS_NAME "Unknow System"
#endif // _WIN32

/* ---------------------------------- 11. Dinh nghia class*/
#define ANIMAL_CLASS(class_name) \
class class_name { \
	public:\
		class_name(std::string _name, int _num_leg) : name(_name), num_leg(_num_leg){}\
		void showInfo(){\
			std::cout << "Name of " << name << " Num of leg: " << num_leg<< endl;\
		}\
		\
private:\
	std::string name;\
	int num_leg;\
};

/*	---------------------------------- 12. Logging */ 

#define LOG_HISTORY(msg) \
{ \
	std::ofstream logFile("log.txt", std::ios::app);\
	if(logFile.is_open()){\
			logFile << "HISTORY: " << msg << " | File: " << __FILE__ << " | Line: " << __LINE__ << endl;\
		logFile.close();\
	}\
}

/* ---------------------------------- Parameterzed Macro */
#define	 INCREASE(x)\
	x++;\


/* ---------------------------------- Mutiply defined */

static bool is_variable_defined = false;

inline void ShowInfo() {
	cout << "Calling ShowInfo function ";
}

#endif // !MACRO_GLOBAL_H
