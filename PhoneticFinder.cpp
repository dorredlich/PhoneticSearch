#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>
#include "PhoneticFinder.hpp"

using namespace std;

string phonetic::find(string text, string word){
    if(word == "")
        throw out_of_range{"This is empty word."};
    string originWord = word;
    string result;
    string result2;
    int count = 0;
    int i = 0;
    transform(word.begin(),word.end(),word.begin(),::tolower);
    while(i < text.length()) {
        if(text[i] != ' ') 
           result.append(1u,text[i]);
        if(text[i] == ' ' || i == text.length()-1){
            if(result.length() == word.length()){
                result2 = result;
                transform(result.begin(),result.end(),result.begin(),::tolower);
                for(int i = 0;i < word.length(); i++)
                   count += isEquals(result[i],word[i]);
               if(count == word.length())
                   return result2;
            }
            result.clear();
            count = 0;
        }
        i++;
    }
    throw out_of_range{"The word " + originWord + " wasn't found"};
    return "";
}

int isEquals(char a,char b){
    if( (b=='o' || b=='u') && (a=='o' || a=='u')) return 1;
    if( (b=='s' || b=='z') && (a=='s' || a=='z')) return 1;
    if( (b=='t' || b=='d') && (a=='t' || a=='d')) return 1;
    if( (b=='i' || b=='y') && (a=='i' || a=='y')) return 1;
    if( (b=='g' || b=='j') && (a=='g' || a=='j')) return 1;
    if( (b=='w' || b=='v') && (a=='w' || a=='v')) return 1;
    if( (b=='b' || b=='f'|| b=='p') && (a=='b' || a=='f' || a=='p')) return 1;
    if( (b=='c' || b=='k'|| b=='q') && (a=='c' || a=='k' || a=='q')) return 1;
    if(a == b) return 1;
    return 0;
}

