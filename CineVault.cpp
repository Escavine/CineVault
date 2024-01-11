// CineVault: Movie Search and Collection App

#include <iostream>
#include <curl/curl.h> // API usage
#include <sqlite3.h> // Database usage
#include <chrono>
#include <string>

// Append the signup details to the users database to allow for them to login         
// Create a user movie watchlist database to store the information of the movie/movies along with the given movie name for signUp function
// The user movie watchlist database has to consist of (userID as a foreign key, watchStatus as a TEXT which can only hold WATCHED, WATCHING, DROPPED ETC, movieInfo and movieName)

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




void loginSession(int UID, std::string individualName, std::string individualSurname)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Error opening database \n" << "Error code: \n" << sqlite3_errcode(db) << "Error message: \n" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Database has successfully been opened!\n" << std::endl; // testing measure: will be removed soon
    }

    std::cout << "Welcome " << individualName << " " << individualSurname << std::endl;
    std::cout << "CineVault: Movie Search and Collection App" << std::endl;



}

void isLoggedin(int userChoice) // Login for existing users 
{
    sqlite3_stmt* stmt;
    sqlite3* db;
    int rc; // return code
    int userAttempts = 3; // user attempts for login to prevent brute force
    std::string un, pw; // username and password
    

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Error opening database \n" << "Error code: \n" << sqlite3_errcode(db) << "Error message: \n" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Database has successfully been opened!\n" << std::endl; // testing measure: will be removed soon
    }

    const char* login = "SELECT * FROM users WHERE username = ? AND password = ?";
    rc = sqlite3_prepare_v2(db, login, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cout << "Failed to prepare SQL statement" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }
    else
    {
        std::cout << "Statement successfully initialized!\n" << std::endl; // testing measure: will be removed soon
    }

    std::cout << "Enter your username" << std::endl;
    std::cin >> un;

    std::cout << "Enter your password" << std::endl;
    std::cin >> pw;

    rc = sqlite3_bind_text(stmt, 4, un.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 5, pw.c_str(), -1, SQLITE_STATIC);

    if (rc != SQLITE_OK)
    {
        std::cout << "Failed to prepare SQL statement" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }
    else
    {
        std::cout << "Statement successfully initialized!\n" << std::endl; // testing measure: will be removed soon
    }

    std::cout << "Logging in...\n";

    int result = sqlite3_step(stmt);

    if (result == SQLITE_ROW)
    {
        int UID = sqlite3_column_int(stmt, 0); // this will fetch the userID
        std::string individualName = (const char*)sqlite3_column_text(stmt, 1); // fetch individual name
        std::string individualSurname = (const char*)sqlite3_column_text(stmt, 2); // fetch individual password
        std::cout << "userID: " << UID << std::endl;
        std::cout << "User Authenticated" << std::endl;
        loginSession(UID, individualName, individualSurname); // lead user to their login session
    }
    else
    {
        std::cout << "Incorrect login details" << std::endl;
        userAttempts--;
        isLoggedin(userChoice); // recurse to allow user to input their details again until their 3 attempts are over
        if (userAttempts == 0)
        {
            std::cout << "Too many attempts, system will now terminate " << std::endl;
            exit(0);
        }

    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}



void menuAfterSignup()
{
    int userChoice;     // Handle user input
    int userAttempts = 3;
    std::cout << "CineVault - Movie Search and Collections App\n" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Forgot Password (NOT WORKING)" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> userChoice;

    switch (userChoice) {
    case 1: {
        std::cout << "You will be redirected to the login form... \n";
        isLoggedin(userChoice);
        break;
    }
    case 2: {
        std::cout << "Communicating with API...\n";
        // insert API code to request for email and send a OTP to reset password
        break;
    }
    default: {
        std::cout << "No choice has been selected, please try again \n";
        userAttempts--; // decrement per wrong attempt
        menuAfterSignup(); // recurse until correct choice is inputted
        if (userAttempts == 0) {
            std::cout << "Too many incorrect attempts, console will now terminate...\n";
            exit(0);  // exit(0) indicates a successful exit
        }
    }
    }
}

// void hashSaltAlgorithm will be used to encrypt the password



std::string generateWatchlistTable(int UID)
{
    return "userWatchlist_" + std::to_string(UID);

}

void createMovieWatchlistTable(int UID, std::string watchlistTableName) // once the user has successfully signed up, the algorithm will run this section of code enabling the creation of the unique movie watchlist table per user
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Error opening SQL database" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }
    else
    {
        std::cout << "Database has opened successfully! \n" << std::endl; // testing measure: will be removed soon
    }


    std::string query = "CREATE TABLE " + watchlistTableName + " ("
        "watchlistID INTEGER PRIMARY KEY NOT NULL, "
        "movieName TEXT, "
        "movieGenre TEXT, "
        "watchedStatus TEXT, "
        "userID INTEGER, "
        "FOREIGN KEY (userID) REFERENCES users(userID)"
        ")";   
    
    const char* createWatchList = query.c_str(); // characterized the query

    int result = sqlite3_exec(db, createWatchList, nullptr, nullptr, nullptr);

    if (result == SQLITE_OK)
    {
        std::cout << "User watchlist table has successfully been generated!" << std::endl;
    }
    else
    {
        std::cout << "Failed to generate user watchlist table" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }


}


bool doesUsernameExist(std::string un) { // this function will check if the username exists within the database, if so will prompt the user
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK) {
        std::cout << "Error opening SQL database" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";       
    }

    const char* userCheck = "SELECT username FROM users WHERE username = ?"; // query to specically look at usernames
    rc = sqlite3_prepare_v2(db, userCheck, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cout << "Failed to prepare SQL statement" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }

    rc = sqlite3_step(stmt);


    if (rc != SQLITE_OK)
    {
        std::cout << "Execution has failed!" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }

    if (rc == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        return true;
    }
    else
    {
        sqlite3_finalize(stmt);
        return false;
    }
}

void signUp(int userChoice) 
{
    sqlite3_stmt* stmt;
    sqlite3* db;
    std::string firstName, lastName, email, un, pw;
    int age, rc;
    int userAttempts = 3;

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK) 
    {
        std::cout << "Error opening SQL database" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";        
    }

    std::cout << "Sign-up form \n" << std::endl;

    const char* query = "INSERT INTO users (individualName, individualSurname, email, individualAge, username, password) VALUES (?, ?, ?, ?, ?, ?)";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Initialization of statement has failed! \n" << "Error code: \n" << sqlite3_errcode(db) << "Error message: \n" << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }

    std::cout << "What is your name?" << std::endl;
    std::cin >> firstName;

    std::cout << "What is your surname?" << std::endl;
    std::cin >> lastName;

    std::cout << "What is your email?" << std::endl;     // future reference: make some use cases to ensure the email is in correct format

    std::cin >> email;

    std::cout << "How old are you?" << std::endl; // future reference: based on the users age request for authentication via YOTI or any other authentic
    std::cin >> age;

    std::cout << "Enter a username" << std::endl;
    std::cin >> un;

    if (un == firstName)
    {
        std::cout << "Username cannot be the same as the first name" << std::endl;
        signUp(userChoice); // user has to reinput their details should they do this
    }

    if (doesUsernameExist(un))
    {
        std::cout << "Username already exists. Please choose a different username.\n";
        signUp(userChoice); // user has to reinput their details should they do this
    }

    std::cout << "Enter a password" << std::endl;
    std::cin >> pw;

    rc = sqlite3_bind_text(stmt, 1, firstName.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 2, lastName.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);  // bind all the following information
    rc = sqlite3_bind_int(stmt, 4, age);
    rc = sqlite3_bind_text(stmt, 5, un.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(stmt, 6, pw.c_str(), -1, SQLITE_STATIC);

    int result = sqlite3_step(stmt);

    if (result == SQLITE_DONE) 
    {
        std::cout << "Sign up success!" << std::endl;
        int UID = sqlite3_last_insert_rowid(db); // attain the last row ID to get a userID
        std::string watchlistTableName = generateWatchlistTable(UID);
        createMovieWatchlistTable(UID, watchlistTableName); // create a watchlist table for the user
        menuAfterSignup(); // user is redirected back to the menu
    }
    else 
    {
        std::cout << "Database integration has failed!" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


void choice()
{
    int userChoice; // Handle user input
    int userAttempts = 3;
    std::cout << "CineVault - Movie Search and Collections App\n" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Sign-Up" << std::endl;
    std::cout << "3. Forgot Password (NOT WORKING)" << std::endl;

    std::cout << "";
    std::cin >> userChoice;

    switch (userChoice) {
    case 1: 
    {
        std::cout << "You will be redirected to the login form... \n";
        isLoggedin(userChoice);
        break;
    }
    case 2: 
    {
        std::cout << "You will be redirected to the sign-up form...\n";
        signUp(userChoice); // leads user to sign up form with the open database connection
        break;
    }
    case 3: 
    {
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
        std::cout << "Failed to create SQL table" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
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






