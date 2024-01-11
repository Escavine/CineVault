// CineVault: Movie Search and Collection App

#include <iostream>
#include <curl/curl.h> // API usage
#include <sqlite3.h> // Database usage
#include <chrono>
#include <string>

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

void isLoggedin() // Login for existing users 
{
    std::cout << "Hello silly chicken, we haven't developed this section yet :)\n" << std::endl;
    sqlite3_stmt* stmt;
    sqlite3* db;


}


// void createMovieWatchlistTable 
// once the user has successfully signed up, the algorithm will run this section of code enabling the creation of the unique movie watchlist table per user


// void forgotPassword() redirect the user should they forget their password


void signUp(int userChoice) // new users will be redirected to this function
{
    sqlite3_stmt* stmt;
    sqlite3* db;
    std::string firstName, lastName, email, un, pw;
    int age, rc;

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Error opening database " << "Error code: " << sqlite3_errcode(db) << "Error message: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Database has opened successfully! \n" << std::endl; // testing measure: will be removed soon
    }

    const char* query = "INSERT INTO users (individualName, individualSurname, email, individualAge, username, password) VALUES (?, ?, ?, ?, ?, ?)";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr); // initialize the statement

    if (rc != SQLITE_OK)
    {
        std::cerr << "Intialization of statement has failed! " << "Error code: " << sqlite3_errcode(db) << "Error message: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Statement initialization is a success! " << std::endl; // testing measure will be removed once confirmed
    }

    std::cout << "Sign-up form \n" << std::endl;

    std::cout << "What is your name?" << std::endl;
    std::cin >> firstName;

    std::cout << "What is your surname?" << std::endl;
    std::cin >> lastName;

    std::cout << "What is your email?" << std::endl;     // future reference: make some use cases to ensure the email is in correct format

    std::cin >> email;

    std::cout << "How old are you?" << std::endl;
    std::cin >> age;

    std::cout << "Enter a username" << std::endl;
    std::cin >> un;

    std::cout << "Enter a password" << std::endl;
    std::cin >> pw;

    rc = sqlite3_bind_text(stmt, 1, firstName.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 2, lastName.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_int(stmt, 4, age);
    rc = sqlite3_bind_text(stmt, 5, un.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 6, pw.c_str(), -1, SQLITE_STATIC);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Binding for one of the following parameters has failed " << "Error code: " << sqlite3_errcode(db) << "Error message: " << sqlite3_errmsg(db) << "\n" << std::endl;
    }
    else
    {
        std::cout << "Binding success\n"; // testing measure: will be removed soon
    }


    int result = sqlite3_step(stmt); // will insert the following information to the database

    if (result == SQLITE_DONE)
    {
        std::cout << "Sign up success!" << std::endl;
    }
    else
    {
        std::cerr << "Database integration for signing up has failed " << "Error code: " << sqlite3_errcode(db) << "Error message: " << sqlite3_errmsg(db) << std::endl;
    }

           // Append the signup details to the users database to allow for them to login         
          // Create a user movie watchlist database to store the information of the movie/movies along with the given movie name for signUp function
          // The user movie watchlist database has to consist of (userID as a foreign key, watchStatus as a TEXT which can only hold WATCHED, WATCHING, DROPPED ETC, movieInfo and movieName)
}


void choice() {
    // Handle user input
    int userChoice;
    int userAttempts = 3;
    std::cout << "CineVault - Movie Search and Collections App\n" << std::endl;
    std::cout << "1. Login (IN DEVELOPMENT)" << std::endl;
    std::cout << "2. Sign-Up" << std::endl;
    std::cout << "3. Forgot Password (NOT WORKING)" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> userChoice;

    switch (userChoice) {
    case 1: {
        std::cout << "You will be redirected to the login form... \n";
        break;
    }
    case 2: {
        std::cout << "You will be redirected to the sign-up form...\n";
        signUp(userChoice); // leads user to sign up form with the open database connection
        break;
    }
    case 3: {
        std::cout << "Communicating with API...\n";
        // insert API code to request for email and send a OTP to reset password
        break;
    }
    default: {
        std::cout << "No choice has been selected, please try again \n";
        userAttempts--; // decrement per wrong attempt
        choice(); // recurse until correct choice is inputted
        if (userAttempts == 0) {
            std::cout << "Too many incorrect attempts, console will now terminate...\n";
            exit(0);  // exit(0) indicates a successful exit
        }
    }
    }
}

int main() {
    CURL* curl;
    CURLcode res;
    sqlite3* db;
    std::string userChoice;

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
    const char* createTable = "CREATE TABLE IF NOT EXISTS users (userID INTEGER PRIMARY KEY NOT NULL, individualName TEXT, individualSurname TEXT, email TEXT, individualAge INTEGER, username TEXT, password TEXT)";
    rc = sqlite3_exec(db, createTable, 0, 0, 0);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to create users table. ERROR CODE: " << sqlite3_errcode(db) << " ERROR DETAILS: " << sqlite3_errmsg(db) << "\n" << std::endl;
    }
    else
    {
        std::cout << "Users table created successfully\n" << std::endl;
    }

    // Call the choice function with the open database connection
    choice();

    // Close the database connection after using it in the choice function
    sqlite3_close(db);

    return 0;
}






