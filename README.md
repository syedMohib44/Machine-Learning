# Machine-Learning
CPP Run Commands:

chflags -R nohidden /File path

clang++ -std=c++17 {CPP File} -o {Any Name}

 pkg-config --list-all 

For Opencv  g++ -ferror-limit=0 --std=c++11 ./main.cpp -c -o ./main.dll `pkg-config --cflags --libs opencv4`

// with arch x86_64 giving wierd values on writing in main func
g++ -arch x86_64 --std=c++17 ./main.cpp -o ./main


g++ --std=c++11 ./main.cpp -o main -I/opt/homebrew/Cellar/glad/include -I/Users/syedmohib/Ethermon/cpp-project/Mycraft/Mycraft/library -I/Users/syedmohib/Ethermon/cpp-project/Mycraft/Mycraft/src `pkg-config --cflags --libs glfw3 assimp`


Remove -c from above to build if building with main function.
https://stackoverflow.com/questions/23132047/g-cant-link-with-a-main-executable-file


if using windows:
x86_64-w64-mingw32-gcc -shared objectfile.o -o outputfile.dll


arch -arm64

if using mac or linux:
gcc -shared objectfile.o -o outputfile.dll


Online Compiler for Viewing assembly:
https://godbolt.org/


FOR smartContractCall.cpp
g++ --std=c++17 -I/opt/homebrew/Cellar/openssl@3/3.0.8/include/ smartContractCall.cpp -o smartContractCall