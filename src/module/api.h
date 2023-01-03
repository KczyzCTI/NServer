//
// Created by Admin on 29.12.2022.
//
#ifndef MAIN_API_H // declarations of all request handlers in api module
#define MAIN_API_H
#include <string>
#include <crow.h>
namespace api {
/*!
 * User authentication.
 * For now simple cleartext password will suffice.
 *
 * Oauth2 (wikamp or sth?) will handle everything in the future,
 * for now just check if id==password or sth
 *
 * @param user_id
 *     Six digit unique identifier
 *     For example 123456
 * @return
 *     Unique, dynamically assigned token.
 *
 */
void login(crow::response &res, unsigned user_id);
/*!
 * Check if token is valid & matches user_id
 * @param user_id six digit user id
 * @param token token
 * @return true if user_id exists and given token matches assigned
 */
bool verifyToken(unsigned user_id, std::string token);
}

#endif //MAIN_API_H
