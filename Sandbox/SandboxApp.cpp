/* SandboxApp.cpp 
   Client Application for dll Hazel  */

//#define ATTRIB_FLAG     // FOR WINDOWS:  __attribute__((dllimport)) 

#include </home/kelly/programming/cpp/GameEngine/Hazel/Hazel.h> 
#include <iostream>   //make sure to use g++ for compilation or else will throw errors during compilation (12AUG2019)

class Sandbox : public Hazel::Application {
    public: 
        Sandbox () {

        }   

        ~Sandbox () {

        }

};  //end class: Sandbox: public Hazel::Application 

//externally declared in 'Hazel/EntryPoint.h' 
Hazel::Application* Hazel::CreateApplication() {

    //Because 'Sandbox' is inheriting from Hazel::Application, 
    //when return new Sandbox(), we are giving an instance of a Hazel::Application from further down inheritance chain 
    //creates new Sandbox() instance as a Hazel::Application 
    //derives linkages from dll at compile/run time 
    return new Sandbox(); 
}