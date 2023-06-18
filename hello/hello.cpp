#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

std::string say_hello() {
    return std::string("Hello!");
}

int main(int argc, char** argv) {
    std::cout << say_hello() << std::endl;

    return EXIT_SUCCESS;
}