#include <stdio.h>
#include <curl/curl.h>
#ifndef __APPLE__
#include "openssl/md5.h"
#include "openssl/crypto.h"
#endif

int main(void)
{
  CURL *curl;
  int retval = 0;
 
  curl = curl_easy_init();
  if(curl) {
    char errbuf[CURL_ERROR_SIZE];

    /* provide a buffer to store errors in */
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  } else {
    printf("Failed to init curl\n");
    retval = 3;
  }
  
  return retval;
}
