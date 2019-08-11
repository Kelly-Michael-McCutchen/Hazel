## These are comments for compile.sh
## Project Compilation script for Hazel/Sandbox Engine and Linked,Static Libraries
## Hazel is compiled to linked/static libraries (.so, .a) 
## To be implemented in Sandbox Application.cpp and others 
## .so should be exported/imported symbols using __attribute__ ((dllimport)) or ((dllexport))
## http://man7.org/conf/lca2006/shared_libraries/slide4b.html --> this shit worked...

#use this page as reference: http://man7.org/conf/lca2006/shared_libraries/slide6.html

  rm libHazel.so* app
  cp /home/kelly/programming/cpp/GameEngine/Hazel/libHazel.so.1 /home/kelly/programming/cpp/GameEngine/Sandbox/
  ln libHazel.so.1 libHazel.so
 #gcc -g -Wall -o app Application.cpp libHazel.so.1.0
  #ln -s libHazel.so.1.0 libHazel.so.1
  g++ -g -Wall -o ./app SandboxApp.cpp -L. -lHazel
  LD_LIBRARY_PATH=. ./app
    #ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so.1
    #ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so
#gcc -Wall -L Application.cpp -lHazel -o app