//
// Created by Admin on 29.12.2022.
//

#ifndef MAIN_LOGIN_H
#define MAIN_LOGIN_H
#include "../api.h"
namespace api {
    /*!
     * Oauth2 verify user
     * @param user_id six digit user id
     * @return true if user verified
     */
    bool OauthVerifyUser(unsigned user_id);

} // api

#endif //MAIN_LOGIN_H
