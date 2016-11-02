#pragma once

#define DOG_DLL

//If we want the library to be a dll we define DOG_DLL
#ifdef DOG_DLL
#define DOG_EXPORT __declspec(dllexport)
#define DOG_IMPORT __declspec(dllimport)
#else	//When a static library
#define DOG_EXPORT
#define DOG_IMPORT
#endif