#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <google/cloud/functions/framework.h>
#include "nlohmann/json.hpp"

namespace gcf = ::google::cloud::functions;

class AuthService {
public:
    gcf::HttpResponse registerUser(const gcf::HttpRequest& request);
    gcf::HttpResponse loginUser(const gcf::HttpRequest& request);
    gcf::HttpResponse forgotPassword(const gcf::HttpRequest& request);
};

#endif  // AUTH_SERVICE_H
