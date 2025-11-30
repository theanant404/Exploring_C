#ifndef MONGODB_SERVICE_H
#define MONGODB_SERVICE_H

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

class MongoDbService {
public:
    MongoDbService();
    mongocxx::database& getDatabase();

private:
    mongocxx::instance instance{}; // This should be constructed only once.
    mongocxx::client client;
    mongocxx::database db;
};

#endif // MONGODB_SERVICE_H