#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    int count = 0;
    std::string temp;
    for (int i = 1 ; i < argc ; i++){
        std::fstream file;
        file.open(argv[i]);
        while(std::getline(file, temp)){
            count++;
        }
    }
    std::cout << count << std::endl;
    
}