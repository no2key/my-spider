#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char *argv[]){
    char cfg_file[] = "config.txt";
    char cfg_info[1024];
    char cfg_line[100];
    char cfg_key[50];
    char cfg_value[100];
    FILE *fp;

    fp = fopen(cfg_file, "r");

    while(fgets(cfg_line, 100, fp) != NULL){
        printf("%s\n", cfg_line);
    }

    fclose(fp);

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
