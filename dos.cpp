#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
  userp->append((char*)contents, size * nmemb);
  return size * nmemb;
}

int main() {
  CURL* curl;
  CURLcode res;
  std::string readBuffer;
  std::string website;
  std::cout << "enter the website" << std::endl;
  std::cin >> website;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if(curl) {
    while (true) {
      
      curl_easy_setopt(curl, CURLOPT_URL, website.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);

      if(res!= CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      std::cout << "Response code: " << response_code << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

  return 0;
}
