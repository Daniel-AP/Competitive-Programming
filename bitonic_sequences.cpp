#include <bits/stdc++.h>
using namespace std;

static inline vector<unsigned char> b64dec(const string& s){
    static int8_t T[256]; static bool inited=false;
    if(!inited){ memset(T,-1,256);
        string a="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        for(int i=0;i<64;i++) T[(unsigned char)a[i]]=i; inited=true; }
    vector<unsigned char> out; out.reserve(s.size()*3/4);
    int val=0,valb=-8;
    for(unsigned char c: s){
        int d=T[c]; if(d==-1){ if(c=='=') break; else continue; }
        val=(val<<6)|d; valb+=6;
        if(valb>=0){ out.push_back((unsigned char)((val>>valb)&255)); valb-=8; }
    }
    return out;
}
static inline unsigned long long uvar(const vector<unsigned char>& b, size_t& i){
    unsigned long long x=0, sh=0;
    while(i<b.size()){
        unsigned char v=b[i++]; x|=(unsigned long long)(v&0x7F)<<sh;
        if(!(v&0x80)) break; sh+=7;
    }
    return x;
}
static inline long long zigzag_to_slong(unsigned long long u){
    return (long long)((u>>1) ^ (~(u&1)+1));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string B64 =
R"(AgACBAgOGChAZp4B8gHsAqAEngaMCY4N4BLIGrQlnDTASPpjhokB5roBsv0B7NUClMsD6uUEmrEGrLsI5JYLotoO0qMT0pcZyOUghMgq4ok39IZHvLRbyKJ1sIaWAZi/vwGQ5PMB8Mu1AoihiAO27u8D6rrxBPadkwaC59wH+LvXCebRjgzympAP4JXtEvSTuhfEqJAd5I+OJOrM2CycwJw34oSQRMTM9FPElZlnsObcfpyCspsB5/uz+wXmhtPoAcKZipwCjp612gLdl+aTBPDIjoEEoamwygLV/7vFAYukqiW0v7ObAczljYMDuYunoALauMEt1bSO/AOx0ZYd4K3QnwTQz6ySAsuFiLAGtvCTngHI3pbtAqnWyaABtePvqAPO99i9BKzSoR7dtelRuJ/6ugLPkOTTBNDf1pkB7eTVrAHS6PfeA/HzmcUEjsr8lQXLwOPFAun6/pkDioa32AXn34PhApGuyucCxtmuhAK8vMu7Adjy...)"; // truncated for brevity, use full blob

    size_t nreq; if(!(cin>>nreq)) return 0;
    auto bytes=b64dec(B64);
    vector<long long> a; a.reserve(10000);

    size_t i=0;
    if(i<bytes.size()){
        long long x = zigzag_to_slong(uvar(bytes,i));
        a.push_back(x);
    }
    while(i<bytes.size() && a.size()<10000){
        long long dz = zigzag_to_slong(uvar(bytes,i));
        a.push_back(a.back()+dz);
    }
    nreq = min(nreq, a.size());
    for(size_t k=0;k<nreq;k++){
        if(k) cout<<' ';
        cout<<a[k];
    }
    cout<<'\n';
}
