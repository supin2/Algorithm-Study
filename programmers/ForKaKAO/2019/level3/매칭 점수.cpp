#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Page {
    int idx, basic, link;
    double score;
};

bool comp(Page &a, Page &b) {
    if (a.score == b.score) {
        return a.idx < b.idx;
    }
    return a.score > b.score;
}

int solution(string word, vector<string> pages) {
    int wsize = word.size();
    map<string, int> pagehash;
    vector<Page> pageinfo;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for (int i = 0; i < pages.size(); i++) {
        string &s = pages[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int mid = 0, posl = 0, posr;
        while (mid <= posl) {
            posl = s.find("<meta", posl + 1);
            posr = s.find(">", posl);
            mid = s.find("https://", posl);
        }
        posr = s.find("\"", mid);
        string url = s.substr(mid, posr - mid);
        
        posl = s.find("<body>", posr);
        int basic = 0; // 기본점수
        for (int start = posl; ;) {
            start = s.find(word, start + 1);
            if (start == string::npos) {
                break;
            }
            if (!isalpha(s[start - 1]) && !isalpha(s[start + wsize])) {
                basic++;
                start += wsize;
            }
        }
        
        int link = 0; // 외부 링크 갯수
        for (int start = posl; ;) {
            start = s.find("<a href", start + 1);
            if (start == string::npos) {
                break;
            }
            link++;
        }
        pagehash[url] = i;
        pageinfo.push_back({ i, basic, link, (double)basic });
    }
        
    for (int i = 0; i < pages.size(); i++) {
        string &s = pages[i];
        for (int posl = 0, posr = 0; ;) {
            posl = s.find("<a href", posr);
            if (posl == string::npos) {
                break;
            }
            posl = s.find("https://", posl);
            posr = s.find("\"", posl);
            string linkurl = s.substr(posl, posr - posl);

            map<string, int>::iterator it = pagehash.find(linkurl);
            if (it != pagehash.end()) {
                pageinfo[it->second].score += (double)pageinfo[i].basic / pageinfo[i].link;
            }
        }
    }
    sort(pageinfo.begin(), pageinfo.end(), comp);
    return pageinfo.begin()->idx;
}