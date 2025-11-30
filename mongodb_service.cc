#include "mongodb_service.h"
#include <iostream>

MongoDbService::MongoDbService() {
    try {
        // Create a new client and connect to the server
        client = mongocxx::client{mongocxx::uri{"mongodb://localhost:27017"}};

        // Get a handle to the database
        db = client["user_db"];
        std::cout << "Connected to MongoDB" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "MongoDB connection error: " << e.what() << std::endl;
    }
}

mongocxx::database& MongoDbService::getDatabase() {
    return db;
}