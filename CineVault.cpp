// CineVault: Movie Search and Collection App

#include <iostream>
#include <curl/curl.h>
#include <sqlite3.h>


size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}


// void addMovies() THIS WILL ADD MOVIES TO ONES COLLECTION
    // Utilise CURL code here


// void searchMovies() THIS WILL ALLOW THE USER TO SEARCH FOR MOVIES
    // Utilise CURL code here

// void isLoggedin() ASSUMING THE USER HAS AN ACCOUNT IN THE DATABASE, THEY CAN LOGIN

// void signUp () NEW USERS WILL BE REDIRECTED TO THIS FUNCTION
           // Append the signup details to the users database to allow for them to login         
          // Create a user movie watchlist database to store the information of the movie/movies along with the given movie name for signUp function
          // The user movie watchlist database has to consist of (userID as a foreign key, watchStatus as a TEXT which can only hold WATCHED, WATCHING, DROPPED ETC, movieInfo and movieName)





int main()
{
    CURL* curl;
    CURLcode res;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc; // return code for SQL statements


    
    // Create a users database that'll consist of a username and password for individuals that already exist within the database
    // INSERT SQL CODE HERE

    const char* createTable = "CREATE TABLE IF NOT EXISTS users (userID INTEGER PRIMARY KEY NOT NULL, individualName TEXT, individualSurname TEXT, individualAge INTEGER, username TEXT, password TEXT)";

    rc = sqlite3_exec(db, createTable, 0, 0, 0);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Database has failed to be created " << "ERROR CODE: " << sqlite
    }

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Database does not exist\n" << std::endl;
    }
    else
    {
        std::cout << "Database has successfully been opened\n" << std::endl; // Testing measure will be removed soon
    }



    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl)
    {
        // Set API for request handling


    }



}

