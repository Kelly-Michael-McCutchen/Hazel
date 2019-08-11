## https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index ## 
## for reference ^^ ##  develops both static and linked libraries (pretty detailed) 
    rm libHazel.so* *.o
    g++ -Wall -fPIC -c ./src/*.cpp
    g++ -shared -Wl,-soname,libHazel.so.1 -o libHazel.so.1.0 *.o 
    ln -s libHazel.so.1.0 libHazel.so.1

   