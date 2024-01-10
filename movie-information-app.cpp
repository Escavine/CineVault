// movie information app C++

#include <iostream>
#include <curl/curl.h>
#include <sqlite3.h>


size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main()
{
    CURL* curl;
    CURLcode res;
    sqlite3* db;
    sqlite3_stmt* stmt;



}

