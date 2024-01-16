// CineVault: Movie Search and Collection App

#include <iostream>
#include <curl/curl.h> // API usage
#include <sqlite3.h> // Database usage
#include <chrono>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <cryptopp/hmac.h>
#include <cryptopp/sha.h> // encryption usage
#include <cryptopp/base32.h>
#include <cryptopp/filters.h>



size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) // for cURL API usage
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}


void addMovies() // this function will allow for the insertion of new movies to a users watchlist
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    CURL* curl;
    CURLcode res; // inserting CURL libraries
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


    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl)
    {
        std::string data;
        std::string movieTitle;

        std::cout << "Enter the movie you'd like to search for" << std::endl;
        std::cin >> movieTitle;

        std::string apiKey = "1d9b5025";  // future reference: since you are uploading on a public repo, reference this from a file rather than expose the ID
        std::string apiUrl = "http://www.omdbapi.com/?apikey=" + apiKey + "&t=" + movieTitle;
        std::cout << apiUrl << std::endl; // testing measure: will be removed soon

        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            
        }
        else
        {
            std::cout << data << std::endl;
        }
        curl_easy_cleanup(curl);

    }

    curl_global_cleanup();
}






// void searchMovies() THIS WILL ALLOW THE USER TO SEARCH FOR MOVIES
    // Utilise CURL code here



bool userWatchlist(int UID)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc; // return code

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Error opening database \n" << "Error code: \n" << sqlite3_errcode(db) << "Error message: \n" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Database has successfully been opened!\n" << std::endl; // testing measure: will be removed soon
    }

    std::string query = "SELECT movieName, movieGenre, watchedStatus FROM userWatchlist_" + std::to_string(UID);
    const char* cQuery = query.c_str(); // concatenated query
    rc = sqlite3_prepare_v2(db, cQuery, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cout << "Error preparing query \n" << "Error code: \n" << sqlite3_errcode(db) << "Error message: \n" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Statement has been prepared!\n" << std::endl; // testing measure: will be removed soon
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const char* movieWatchlist = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)); // this statement loops through the SQL rows to find the given parameters from the query
        std::cout << "Movie Watchlist: " << movieWatchlist << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}


void loginSession(int UID, std::string individualName, std::string individualSurname, int switchChances)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc, choice;

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

    int result = userWatchlist(UID); // display the users current movie watchlist

    std::cout << "1. Add movies to watchlist (NOT WORKING)" << std::endl;
    std::cout << "2. Remove movies from watchlist (NOT WORKING)" << std::endl; // users are given options between the three
    std::cout << "3. Termiante session" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
    {
        std::cout << "You are now being redirected to the adding movies page..." << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "You are now being redirected to the removing movies page..." << std::endl;
        break;
    }
    case 3:
    {
        std::cout << "Your session is now going to be termianted..." << std::endl;
        exit(0);
        break;
    }
    default:
    {
        std::cout << "Invalid option, please enter a sensible value through the console" << std::endl;
        std::cout << "Attempts remaining: " << switchChances << std::endl; // will display the remaining attempts that the user has

        if (switchChances == 0)
        {
            std::cout << "Too many incorrect attempts, system will now terminate..." << std::endl; // if they use up all their chances, then the system terminates
            exit(0);
        }
        else
        {
            loginSession(UID, individualName, individualSurname, switchChances - 1); // if chances aren't zero then recurse
        }

    }
    }
}



void isLoggedin(int userChoice, int userAttempts) // user attempts for login to prevent brute force
{
    sqlite3_stmt* stmt;
    sqlite3* db;
    int rc; // return code
    std::string un, pw; // username and password
    int switchChances = 3; // this is for the switch statement referencing the above function (loginSession)


    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Error opening database \n" << "Error code: \n" << sqlite3_errcode(db) << "Error message: \n" << sqlite3_errmsg(db) << std::endl;
    }


    const char* login = "SELECT * FROM users WHERE username = ? AND password = ?";
    rc = sqlite3_prepare_v2(db, login, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cout << "Failed to prepare SQL statement" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }


    std::cout << "Enter your username" << std::endl;
    std::cin >> un;

    std::cout << "Enter your password" << std::endl;
    std::cin >> pw;

    rc = sqlite3_bind_text(stmt, 1, un.c_str(), -1, SQLITE_STATIC); // bind the following parameters (username and password)
    rc = sqlite3_bind_text(stmt, 2, pw.c_str(), -1, SQLITE_STATIC);

    if (rc != SQLITE_OK)
    {
        std::cout << "Failed to prepare SQL statement" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }


    std::cout << "Logging in...\n";

    int result = sqlite3_step(stmt);

    if (result == SQLITE_ROW)
    {
        int UID = sqlite3_column_int(stmt, 0); // this will fetch the userID
        std::string individualName = (const char*)sqlite3_column_text(stmt, 1); // fetch individual name
        std::string individualSurname = (const char*)sqlite3_column_text(stmt, 2); // fetch individual surname
        std::cout << "userID: " << UID << std::endl;
        std::cout << "User Authenticated" << std::endl;
        loginSession(UID, individualName, individualSurname, switchChances); // lead user to their login session
    }
    else
    {
        std::cout << "Incorrect login details" << std::endl;

        std::cout << "Attempts remaining: " << userAttempts << std::endl; // will display user attempts to ensure they stop making mistakes

        if (userAttempts == 0)
        {
            std::cout << "Too many attempts, system will now terminate " << std::endl;
            exit(0);
        }
        else
        {
            isLoggedin(userChoice, userAttempts - 1); // recurse to allow the user to input their details again until their 3 attempts are over
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
        isLoggedin(userChoice, userAttempts);
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

        if (userAttempts == 0) {
            std::cout << "Too many incorrect attempts, console will now terminate...\n";
            exit(0);  // exit(0) indicates a successful exit
        }
        else
        {
            menuAfterSignup(); // recurse until correct choice is inputted
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




// void hashSalt() future reference: this will encrypt the password to prevent any data from getting leaked 

bool validateEmailFormat(std::string email)
{
    size_t atPosition = email.find("@");
    size_t dotPosition = email.find(".");


    if (atPosition != std::string::npos && dotPosition != std::string::npos && atPosition < dotPosition)
    {
        return true;
        // redirect the user to an authentication system via their email after signup with the google API 
    }
    else
    {
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
        exit(0);
    }

    std::cout << "What is your name?" << std::endl;
    std::cin >> firstName;

    std::cout << "What is your surname?" << std::endl;
    std::cin >> lastName;

    std::cout << "What is your email?" << std::endl;     // future reference: make some use cases to ensure the email is in correct format

    std::cin >> email;

    if (validateEmailFormat(email))
    {
        std::cout << "Email format is valid" << std::endl;
    }
    else 
    {
        std::cerr << "Invalid email format" << std::endl;
        signUp(userChoice); // recurse and allow user to reinput their details
    }


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
        std::cerr << "Database integration has failed!" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


void newPassword(std::string email)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    std::string newPassword;
    int userID;

    rc = sqlite3_open("users.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Error opening SQL database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    const char* findUserIDQuery = "SELECT userID FROM users WHERE email = ?"; // Replace with a condition to identify the user, e.g., by email or username
    rc = sqlite3_prepare_v2(db, findUserIDQuery, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to prepare SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_bind_text(stmt, 1, email.c_str(), email.length(), SQLITE_STATIC);

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW)
    {
        userID = sqlite3_column_int(stmt, 0);
        std::cout << "User passsword reset authorized, confirming user ID: " << userID << std::endl;
    }
    else
    {
        std::cerr << "Failed to attain userID" << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    std::string updatePasswordQuery = "UPDATE users SET password = ? WHERE userID = ?";

    rc = sqlite3_prepare_v2(db, updatePasswordQuery.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    std::cout << "Enter a new password" << std::endl;
    std::getline(std::cin, newPassword);

    rc = sqlite3_bind_text(stmt, 1, newPassword.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_bind_int(stmt, 2, userID);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Error binding parameters: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Error updating password: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "User password has successfully been changed!" << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}



void verifyOTP(std::string inputtedOTP, std::string generatedOTP, int otpChances, std::string email)
{
    int userChoice;

    if (inputtedOTP == generatedOTP)
    {
        std::cout << "OTP is valid, success." << std::endl; // should both values be the same, the users identity will be successfully confirmed
        newPassword(email); // user will now be able to create a new password
    }
    else
    {
        std::cout << "OTP is invalid, please try again." << std::endl;
        std::cout << "Would you like to be sent another OTP via email? (1 for yes, 2 for no)" << std::endl;
        std::cin >> userChoice;

        if (userChoice == 1)
        {
            otpChances--; // decrement otp chances to prevent spam otp requests
            std::cout << "OTP requests remaining: " << otpChances << std::endl; // testing measure to ensure that the decrementation is working correctly, will be removed soon should it work fine
            std::cout << "As of present this feature is currently in development, please wait." << std::endl; // will need to start using .h files to properly utilise functions
        }
        else if (userChoice == 2)
        {
            std::cout << "You will be redirected back to the menu" << std::endl;
            menuAfterSignup();

        }
    }
}



void sendOTPByEmail(std::string& email, std::string generatedOTP)
{
    // Construct email content
    std::string emailContent = "{\"From\": \"thelollipopcreamytber@gmail.com\", \"To\": \"" + email +
        "\", \"Subject\": \"OTP Confirmation\", \"HtmlBody\": \"Your OTP: " +
        (generatedOTP) + "\"}";
}


std::string generateOTP(std::string email, uint64_t counter)
{

    // generating TOTP
    CryptoPP::HMAC<CryptoPP::SHA1> hmac((const byte*)email.data(), email.size());
    byte digest[CryptoPP::HMAC<CryptoPP::SHA1>::DIGESTSIZE];
    hmac.Update((const byte*)&counter, sizeof(counter));

    // truncating the HMAC value to 6 digits
    int offset = digest[CryptoPP::HMAC<CryptoPP::SHA1>::DIGESTSIZE - 10] & 0x0F;
    int32_t truncatedHash = (digest[offset] & 0x7F) << 24 | (digest[offset + 1] & 0xFF) << 16 | (digest[offset + 2] & 0xFF) << 8 | (digest[offset + 3] & 0xFF);
    
    int otp = truncatedHash % 1000000;
    std::ostringstream oss;
    oss << std::setw(6) << std::setfill('0') << otp;

    return oss.str(); // returns the OTP value generated

}



void OTP(std::string email) // should the users email exist in the database, they'll be redirected to this function to successfully reset their password
{
    CURL* curl;
    CURLcode res; // CURL libraries
    sqlite3* db; // SQL libraries
    sqlite3_stmt* stmt;
    std::string inputtedOTP; // users input when asked for OTP
    int otpChances = 3; // users will get 3 chances to input the correct OTP to prevent HTTP request spam

    // API code to request for email and send a OTP to reset password

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl)
    {
        std::string data;

        // headers and authentication
        curl_easy_setopt(curl, CURLOPT_URL, email.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);


        // headers for HTTP request 



        // current time in seconds for TOTP encryption
        time_t counter = time(0);

        std::string generatedOTP = generateOTP(email, counter); // function that will generate a random OTP number for the user
        std::cout << "OTP: " << generatedOTP << "(testing measure)" << std::endl;

        sendOTPByEmail(email, generatedOTP);

        res = curl_easy_perform(curl);


        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        }
        else
        {
            std::cout << "OTP sent successfully!" << std::endl;
            std::cout << "Enter your OTP" << std::endl; // user will receive the OTP via their email and be asked to enter it to confirm their identity 
            std::cin >> inputtedOTP;
            verifyOTP(inputtedOTP, generatedOTP, otpChances, email); // the inputted OTP will be compared against the generated OTP to ensure that it is correct

        }

    curl_easy_cleanup(curl);

    }

    curl_global_cleanup();
}

boolean isValidEmailAddress(std::string email)
{
    size_t atPosition = email.find("@"); // these characters will be searched for within the email variable to ensure that it is indeed in correct format
    size_t dotPosition = email.find(".");

    if (atPosition != std::string::npos && dotPosition != std::string::npos && atPosition < dotPosition)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void checkForUserEmail(int userChoice, int userAttempts)
{
    sqlite3* db; // sql libraries
    sqlite3_stmt* stmt;
    int rc; // return code
    std::string email; // email


    // firstly, we will check if the users email exists on the system

    rc = sqlite3_open("users.db", &db); // open the database

    if (rc != SQLITE_OK)
    {
        std::cerr << "Opening database has failed!" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }


    const char* query = "SELECT email FROM users WHERE email = ?"; // SQL prompt
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr); // prepare the given statement

    std::cout << "Forgot password" << "\n" << std::endl;
    std::cout << "Enter your email address" << std::endl;
    std::cin >> email;


    if (isValidEmailAddress(email))
    {
        std::cout << "User email format is valid." << std::endl;
        OTP(email); // direct the user to the forgot password function
    }
    else
    {
        std::cout << "Invalid email format, please ensure that it is in sensible format." << std::endl;
        std::cout << "Attempts remaining: " << userAttempts << std::endl; // display the users remaining input attempts
        checkForUserEmail(userChoice, userAttempts - 1); // decrement the user attempts that way they give the correct input the next round

        if (userAttempts == 0)
        {
            std::cout << "Too many incorrect attempts, system will now terminate..." << std::endl;
            exit(0); // successfully initiate the termination should the remaining attempts be at 0

        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}


void choice()
{
    int userChoice; // Handle user input
    int userAttempts = 3;
    std::cout << "CineVault - Movie Search and Collections App (CONSOLE)\n" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Sign-Up" << std::endl;
    std::cout << "3. Forgot Password (IN DEVELOPMENT)" << std::endl;

    std::cout << "";
    std::cin >> userChoice;

    switch (userChoice) {
    case 1:
    {
        std::cout << "You will be redirected to the login form... \n";
        isLoggedin(userChoice, userAttempts);
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
        checkForUserEmail(userChoice, userAttempts); // lead the user to the forgot password function
        break;
    }
    default: {
        std::cout << "No choice has been selected, please try again \n";
        choice(); // recurse until correct choice is inputted
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


    // Creates users table if it doesn't exist
    const char* createTable = "CREATE TABLE IF NOT EXISTS users (userID INTEGER PRIMARY KEY NOT NULL, individualName TEXT, individualSurname TEXT, email TEXT, individualAge INTEGER, username TEXT, password TEXT)";
    rc = sqlite3_exec(db, createTable, 0, 0, 0);

    if (rc != SQLITE_OK)
    {
        std::cout << "Failed to create SQL table" << "\n"
            << "Error code: " << sqlite3_errcode(db) << "\n"
            << "Error message: " << sqlite3_errmsg(db) << "\n";
    }

    // Call the choice function with the open database connection
    choice();

    // Close the database connection after using it in the choice function
    sqlite3_close(db);

    return 0;
}






