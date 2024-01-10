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

// void searchMovies() THIS WILL ALLOW THE USER TO SEARCH FOR MOVIES

// void isLoggedin() ASSUMING THE USER HAS AN ACCOUNT IN THE DATABASE, THEY CAN LOGIN

// void signUp () NEW USERS WILL BE REDIRECTED TO THIS FUNCTION


int main()
{
    CURL* curl;
    CURLcode res;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc; // return code for SQL statements


    // Create a Movie database to store the information of the movies along with the given movie name

    // INSERT SQL CODE HERE

    // Create table code


    std::cout << "Enter the movie you'd like to search for...\n" << std::endl;


    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl)
    {
        // Set API for request handling


    }



}

