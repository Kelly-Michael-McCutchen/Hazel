/*EntryPoint.h
  requires an extern Hazel::Application* Hazel::CreateApplication() 
  Defines entry point INTO engine 
   */
#pragma once 
#include <iostream> 

#ifdef HZ_PLATFORM_WINDOWS

#else //linux  

//function elsewise defined (defined in client)  //this case inside SandboxApp.cpp
/*Notes on extern: 
  define the EXISTENCE of this GLOBAL VARIABLE here (this header), but only need to 
  define it ONCE in one of our source files 
  to clarify:   extern int x; tells compiler an object of type int called x exists somewhere
  once all source files have compiled, linker will resolve all references to x to the ONE
  definition it finds in compiled source files. 
  To work, definition of x variable needs to have what's called 'external linkage' 
  ---> needs to be declared outside of a function (at 'file scope') and without 
  ---> 'static' keyword  */
extern Hazel::Application* Hazel::CreateApplication(); 

int main (int argc, char** argv) {
    
    auto app = Hazel::CreateApplication(); 
    app->Run(); 
    delete app; 
     
    puts("Welcome to Hazel Engine from EntryPoint.h!"); 
    return 0; 
}
#endif 