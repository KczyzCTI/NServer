//
// Created by Admin on 29.12.2022.
//
#include <gtest/gtest.h>
#include <api.h>
using std::string;

TEST(ApiLogin, TestValidLogin){
    crow::SimpleApp app;
    string url = "/test/login/";

    CROW_ROUTE(app, "/test/login/<int>")(api::login);
    app.validate();
    crow::request req;
    crow::response res;
    req.url = url+"161616";
    app.handle_full(req, res);
    ASSERT_NE(res.body,"")
        << "should get token";
}
TEST(ApiLogin, TestDoubleLogin){
    crow::SimpleApp app;
    string url = "/test/login/";

    CROW_ROUTE(app, "/test/login/<int>")(api::login);
    app.validate();
    crow::request req;
    crow::response res;
    req.url = url+"161616";
    app.handle_full(req, res);
    app.handle_full(req,res);
    ASSERT_EQ(res.body, "")
        << "If user_id already in use, return empty string";
}

TEST(ApiLogin, TestInvalidLogin){
    crow::SimpleApp app;
    string url = "/test/login/";

    CROW_ROUTE(app, "/test/login/<int>")(api::login);
    app.validate();
    crow::request req;
    crow::response res;
    req.url = url+"123456";
    app.handle_full(req, res);
    ASSERT_EQ(res.body,"")
        << "If login fails, return empty string";
}

TEST(ApiVerifyToken, TestInvalid_UserId){
    bool isTokenValid = api::verifyToken(111111,"token");
    ASSERT_FALSE(isTokenValid) << "never logged in using this id, should return false";
}
TEST(ApiVerifyToken, TestInvalid_Token){
    crow::SimpleApp app;
    string url = "/test/login/";

    CROW_ROUTE(app, "/test/login/<int>")(api::login);
    app.validate();
    crow::request req;
    crow::response res;
    req.url = url+"161616";
    app.handle_full(req, res);
    ASSERT_NE(res.body,"") << "valid login. should get token.";
    bool isTokenValid = api::verifyToken(161616,"invalid token");
    ASSERT_FALSE(isTokenValid) << "assigned token and given token do not match, should return false.";
}
TEST(ApiVerifyToken, TestValid){
    crow::SimpleApp app;
    string url = "/test/login/";

    CROW_ROUTE(app, "/test/login/<int>")(api::login);
    app.validate();
    crow::request req;
    crow::response res;
    req.url = url+"161616";
    app.handle_full(req, res);
    ASSERT_NE(res.body,"") << "valid login. should get token.";
    bool isTokenValid = api::verifyToken(161616,res.body);
    ASSERT_TRUE(isTokenValid) << "valid user_id and token, should return true";

}