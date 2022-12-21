//
// Created by Admin on 21.12.2022.
//
#include <crow.h>
std::string greeter(int id){
    if(id==16161616){return "All your base are belong to us!";}
    static int counter = 0;
    std::string result = "Hello User" + std::to_string(id);
    result += "\nLast user logged in was User"+std::to_string(counter);
    counter = id;
    return result;
}
int main(){
    crow::SimpleApp app;

    CROW_ROUTE(app, "/get/greet&<int>")(greeter);

    app.port(18080).run();
}