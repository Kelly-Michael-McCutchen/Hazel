#pragma once 

//define macros for build  

#ifdef HZ_PLATFORM_WINDOWS //define in preprocessor in visual studio solution configure
                            // 'preprocessor definitions' under c/c++ 
    #ifdef HZ_BUILD_DLL    //dito. 
        #define HAZEL_API __declspec(dllexport) 
    #else 
        #define HAZEL_API __declspec(dllimport) 
    #endif
#else 
    #define HAZEL_API 
    #define ATTRIB_FLAG
    //could use: #error hazel only supports windows (won't build using this) 

#endif