

/* File to include for DLL_PUBLIC, DLL_LOCAL attributes 

    ========EDIT AS NECCESSARY (11AUG2019)=============== 
    check:: gcc.gnu.org/wiki/Visibility for examples of DLL export rules 

    export : GNU (linux) 
            #define DLL_PUBLIC __attribute__ ((dllexport)) --> 
    import : GNU (linux) 
            #define DLL_Local  __attribute__ ((dllimport))


    use: __declspec(dllexport)  for windows 
         __declspec(dllimport) 
    can also use #pragma GCC visibility push(hidden) 
                extern void someprivatefunc(int); 
                #pragma GCC visibility pop
                extern void foo (int); --> foo(public extern);  
                
                
     EXAMPLE USAGE:  (from gcc.gnu.org/wiki/Visibility) 

        // Generic helper definitions for shared library support
            #if defined _WIN32 || defined __CYGWIN__
            #define FOX_HELPER_DLL_IMPORT __declspec(dllimport)
            #define FOX_HELPER_DLL_EXPORT __declspec(dllexport)
            #define FOX_HELPER_DLL_LOCAL
            #else
            #if __GNUC__ >= 4
                #define FOX_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
                #define FOX_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
                #define FOX_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
            #else
                #define FOX_HELPER_DLL_IMPORT
                #define FOX_HELPER_DLL_EXPORT
                #define FOX_HELPER_DLL_LOCAL
            #endif
            #endif

            // Now we use the generic helper definitions above to define FOX_API and FOX_LOCAL.
            // FOX_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
            // FOX_LOCAL is used for non-api symbols.

            #ifdef FOX_DLL // defined if FOX is compiled as a DLL
            #ifdef FOX_DLL_EXPORTS // defined if we are building the FOX DLL (instead of using it)
                #define FOX_API FOX_HELPER_DLL_EXPORT
            #else
                #define FOX_API FOX_HELPER_DLL_IMPORT
            #endif // FOX_DLL_EXPORTS
            #define FOX_LOCAL FOX_HELPER_DLL_LOCAL
            #else // FOX_DLL is not defined: this means FOX is a static lib.
            #define FX_API
            #define FOX_LOCAL
            #endif // FOX_DLL

                */

  // LINUX_TESTING19: Built 2019, on Linux (...duh :) ) 
#define LINUX_TESTING19  //stand in for actual code (i.e __WIN32, __GNUC__>=4)

//should be able to use simple nomenclature --> i.e. #if LINUX_TESTING19, then define import/export
#if LINUX_TESTING19
    #define HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else 
    #define HELPER_DLL_IMPORT
    #define HELPER_DLL_EXPORT
    #define HELPER_DLL_LOCAL
#endif //LINUX_TESTING19

#ifdef _DLL //defined if defined as DLL 
    #ifdef _DLL_EXPORTS //defined if building the DLL (instead of using it) 
        #define _API HELPER_DLL_EXPORT
    #else  
        #define _API HELPER_DLL_IMPORT 
    #endif //_DLL_EXPORTS
    #define _LOCAL HELPER_DLL_LOCAL 
#else //_DLL is not defined : is a static lib 
    #define _API
    #define _LOCAL 
#endif //_DLL 
