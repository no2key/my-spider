#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char *argv[]){
    char config_file[] = "config.txt";
    char config_info[1024];
    int fp;

    fp = open(config_file, 'r');
    read(fp, config_info, 1024);
    printf("%s\n", config_info);

    return 0;
}


// @todo 获得一个url的响应数据。
/*
int fetch_data(char[200] url){
       CURL *curl;
       CURLcode res;

       curl = curl_easy_init();

       if(curl){
           curl_easy_setopt(curl, CURLOPT_URL, url);
           res = curl_easy_perform(curl);

           if(res != CURLE_OK){
               fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
           }

           curl_easy_cleanup(curl);
       }
}
*/

// end of this file
