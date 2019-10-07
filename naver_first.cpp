/*
1. 이메일 유효성 검증 문제이다.
맨 먼저 id 명이오며 한글자 이상이고 알파벳 소문자들이다.
id뒤에는 @가 붙는다.
@이 뒤에는 도메인명이 오며 한글자 이상의 알파벳 소문자이다.
도메인 명 뒤에는 '.'이 나타난다.
그리고 탑레벨도메인으로 '.'뒤에는 'org', 'net', 'com' 중 하나가 온다.
"email@google.com"은 올바른 이메일이지만
"e@jk@.co.kr"은 올바른 이메일이 아니다.
입력이 주어졌을 때 올바른 이메일의 개수를 세어라

입력 : ["ya@ya.com", "abs", "goo@goo@le.com", "protoss.nexus.co.kr", "png@naver.com"]
답 : 2
*/
bool parsing(string mail){
    bool name = false;
    bool gol = false;
    bool domain1 = false;
    bool domain2 = false;

    int len = mail.length() - 1;

    string username = "";
    int idx = 0;
    for(idx = 0; mail[idx] != '@' && idx < len-3; idx++){
        if(mail[idx] != '@' && mail[idx] >= 'a' && mail[idx] <= 'z')
            username += mail[idx];
    }
    if(username != "")
        name = true;
    else return false;
    if(mail[idx++] == '@')
        gol = true;
    else
        return false;
    
    string p = "";
    for(int i = idx; mail[i] == '.' && i < len-3; i++){
        if(mail[i] >= 'a' && mail[i] <= 'z')
            p += mail[i];
        else
            return false;
    }
    if(p != "")
        domain1 = true;
    else
        return false;

    string domain = mail.substr(len-3, 4);
    if(domain == ".org" || domain == ".net" || domain == ".com")
        domain2 = true;
    else return false;

    if(name && gol && domain1 && domain2){
        return true;
    }
    else false;
}
