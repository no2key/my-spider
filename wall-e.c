#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <curl/curl.h>

int main(int argc, char *argv[]){
    char cfg_file[] = "config.txt", cfg_info[1024];
    char *url_list, *mongodb_host, *mongodb_port;
    int fp;

    fp = open(cfg_file, O_RDONLY);
    read(fp, cfg_info, 1024);

    str_replace(cfg_info, "url_list", "");
    str_replace(cfg_info, "mongodb_host", "");
    str_replace(cfg_info, "mongodb_port", "");
    str_replace(cfg_info, "\n", "");

    url_list = strtok(cfg_info, "=");
    mongodb_host = strtok(NULL, "=");
    mongodb_port = strtok(NULL, "=");

    printf("\n===================== loading config =========================\n\n", "");
    printf("URL list: %s\n", url_list);
    printf("mongoDB host: %s\n", mongodb_host);
    printf("mongoDB port: %s\n", mongodb_port);

    printf("\n============== start fetching page information ===============\n\n", "");
    fetch_data("http://www.baidu.com");

    return 0;
}

/**
 * 获得一个url的响应数据。
 */
int fetch_data(char* url){
    CURL *curl;
    CURLcode res;
    extern size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata);

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_data);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return 0;
}

/**
 * 字符串替换。
 * @param char* 待处理字符串。
 * @param char* 旧字符串。
 * @param char* 新字符串。
 */
int str_replace(char* str,char* str_src, char* str_des){
    char *ptr=NULL;
    char buff[256];
    char buff2[256];
    int i = 0;

    if(str != NULL){
        strcpy(buff2, str);
    }else{
        printf("str_replace err!\n");
        return -1;
    }

    memset(buff, 0x00, sizeof(buff));

    while((ptr = strstr( buff2, str_src)) !=0){
        if(ptr-buff2 != 0) memcpy(&buff[i], buff2, ptr - buff2);
        memcpy(&buff[i + ptr - buff2], str_des, strlen(str_des));
        i += ptr - buff2 + strlen(str_des);
        strcpy(buff2, ptr + strlen(str_src));
    }

    strcat(buff,buff2);
    strcpy(str,buff);

    return 0;
}

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata){
    printf("%s\n", ptr);

    return 0;
}

// end of this file
