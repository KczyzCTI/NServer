//
// Created by Admin on 29.12.2022.
//

#include "login.h"
namespace api {
bool OauthVerifyUser(unsigned user_id) { // to be implemented later
  return (user_id == 161616); // placeholder
}
void login(crow::response &res, unsigned user_id) {
  bool verified = OauthVerifyUser(user_id);
  // TODO ...
}
bool verifyToken(unsigned user_id, std::string token) {
  // TODO ...
}
} // api