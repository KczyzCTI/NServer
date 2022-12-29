//
// Created by Admin on 21.12.2022.
//
#include <crow.h>
#include "module/api.h"

 namespace API{
     namespace Greeter{
         void greeter(const crow::request& req,crow::response& res, int id){
             if(id==16161616){
                 res.body = "All your base are belong to us!";
                 res.end();}
             else{
                 res.redirect("/redirect");
                 res.end();
             }
         }
         void greeterFail(crow::response& res) noexcept{
             res.redirect("/redirect");
             res.end();
         }
         void greeterObtainPassword(crow::response& res) noexcept{
             std::string password = "16161616";
             res.redirect_perm("/get/greet/"+password);
             res.end();
         }
     }

 }

int main(){
    crow::SimpleApp app;
     // unfortunately function overloading and default arguments
     // do not work well with our router.

     // maybe this approach could proove useful?
     // handlers grouped in namespaces,
     // scoped using for better readability
    {   using namespace API::Greeter;
        CROW_ROUTE(app, "/get/greet/<int>")(greeter);
        CROW_ROUTE(app, "/get/greet/")(greeterFail);
        CROW_ROUTE(app, "/redirect")(greeterObtainPassword);
        CROW_ROUTE(app, "/")([](){return "root";});
    }
    // two handler signatures worth noting:
    //
    // 1) optional structs crow::request/response "automagically" handled
    // T handler(T...)
    //
    // 2) because crow::request directly named, only void allowed
    // to return anything, modify res, then call res.end();
    //
    // allows for redirects and other fun stuff
    // void handler(crow::response& res, T...)
    //

    app.port(18080).run();
}