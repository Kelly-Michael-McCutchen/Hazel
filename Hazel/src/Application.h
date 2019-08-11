#pragma once 

#include "Core.h" 


namespace Hazel {

    class  ATTRIB_FLAG Application {

    public: 
        Application(); 
        virtual ~Application(); 

        void Run(); 
    }; //end class: Application 

    //To be defined in CLIENT 
    Application* CreateApplication(); 
}


//#undef ATTRIB_FLAG