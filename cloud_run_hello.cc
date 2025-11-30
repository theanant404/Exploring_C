#include <google/cloud/functions/framework.h>
#include <cstdlib>
#include <string>
#include "auth_service.h"

namespace gcf = ::google::cloud::functions;

auto hello_world_http() {
  static AuthService auth_service;

  return gcf::MakeFunction([](gcf::HttpRequest const& request) {
    if (request.target() == "/hello") {
        std::string greeting = "Hello ";
        auto const* target = std::getenv("TARGET");
        greeting += target == nullptr ? "World" : target;
        greeting += "\n";

        return gcf::HttpResponse{}
            .set_header("Content-Type", "text/plain")
            .set_payload(greeting);
    } else if (request.target() == "/register") {
        return auth_service.registerUser(request);
    } else if (request.target() == "/login") {
        return auth_service.loginUser(request);
    } else if (request.target() == "/forgot-password") {
        return auth_service.forgotPassword(request);
    }
    
    return gcf::HttpResponse{}
        .set_result(404)
        .set_payload("Not Found\n");
  });
}

int main(int argc, char* argv[]) {
  return gcf::Run(argc, argv, hello_world_http());
}
