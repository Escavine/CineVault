// CineVault: Movie Search and Collection App

#include <iostream>
#include <curl/curl.h> // API usage
#include <sqlite3.h> // Database usage
#include <chrono>


size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) // for cURL API usage
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}


// void addMovies() THIS WILL ADD MOVIES TO ONES COLLECTION
    // Utilise CURL code here
    // curl_global_init(CURL_GLOBAL_DEFAULT);
    // curl = curl_easy_init();
    // if (curl)

// void searchMovies() THIS WILL ALLOW THE USER TO SEARCH FOR MOVIES
    // Utilise CURL code here

// void isLoggedin() ASSUMING THE USER HAS AN ACCOUNT IN THE DATABASE, THEY CAN LOGIN

// void signUp () NEW USERS WILL BE REDIRECTED TO THIS FUNCTION
           // Append the signup details to the users database to allow for them to login         
          // Create a user movie watchlist database to store the information of the movie/movies along with the given movie name for signUp function
          // The user movie watchlist database has to consist of (userID as a foreign key, watchStatus as a TEXT which can only hold WATCHED, WATCHING, DROPPED ETC, movieInfo and movieName)


int main() {
    CURL* curl;
    CURLcode res;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Open or create SQLite database
    sqlite3* db;
    int rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK) 
    {
        std::cerr << "Database failed to open\n" << std::endl;
        return rc;
    }
    else 
    {
        std::cout << "Database opened successfully\n" << std::endl;
    }

    // Creates users table if it doesn't exist
    const char* createTable = "CREATE TABLE IF NOT EXISTS users (userID INTEGER PRIMARY KEY NOT NULL, individualName TEXT, individualSurname TEXT, individualAge INTEGER, username TEXT, password TEXT)";
    rc = sqlite3_exec(db, createTable, 0, 0, 0);

    if (rc != SQLITE_OK) 
    {
        std::cerr << "Failed to create users table. ERROR CODE: " << sqlite3_errcode(db) << " ERROR DETAILS: " << sqlite3_errmsg(db) << std::endl;
    }
    else 
    {
        std::cout << "Users table created successfully\n" << std::endl;
    }

    // Close the database connection
    sqlite3_close(db);

    // Handle user input
    int userChoice;
    std::cout << "CineVault - Movie Search and Collections App\n" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Sign-Up" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> userChoice;

    // Add logic to handle user choice (login or sign-up)

    // Cleanup libcurl
    curl_global_cleanup();

    return 0;
}


