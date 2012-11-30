#include <stdio.h>
#include <curl/curl.h>
#include <json/json.h>

int main(void){
    //@todo
    get_config();
    get_urls();
    fetch_data();
    parse_data();
    add_queue();

    return 0;
}

// @todo 获得配置信息。
char* get_config(void){
    struct json_object *new_obj, *haha, *test;
    char filename[] = "config.json";
    char buf[1024];
    int rs;
    int fp;

    printf("test %s", filename);
    fp = open(filename, 'r');
    rs = read(fp, buf, 1024);
    printf("%s\n", buf);

    new_obj = json_tokener_parse(buf);
    printf("%s\n", json_object_to_json_string(new_obj));
    haha = json_object_object_get(new_obj, "haha");
    printf("%s\n", json_object_to_json_string(haha));
    test = json_object_object_get(new_obj, "test");
    printf("%s\n", json_object_to_json_string(test));

    return buf;
}

// @todo 获得一个url的响应数据。
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

//获得要请求的url列表
void get_urls(){
    //@todo
}

//解析请求的结果。
void parse_data(){
    //@todo
}

//将最终结果插入数据队列。
void add_queue(){
    //@todo
}

// end of this file
