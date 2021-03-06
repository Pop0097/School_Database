//
// Created by Dhruv Rawat on 2020-05-27.
//

#include "Classes.h"

Admin::Admin(){
    name = "d_name";
    username = "d_uname";
    encrypted_password = adminEncrypt("pass", "Axc4RDx3osYg"); //encrypts password
}

Admin::Admin(string u, string password){
    name = "d_name";
    username = u;
    encrypted_password = adminEncrypt(password, "Axc4RDx3osYg"); //encrypts password
}

Admin::Admin(string n, string u, string password){
    //for all fields it checks if the attribute is 0 (Used in UI to signal "cancel"). If it is, then the default is used.
    if(n != "0"){
        name = n;
    } else {
        name = "d_name";
    }

    if(u != "0"){
        username = u;
    } else {
        username = "d_uname";
    }

    if(password != "0") {
        encrypted_password = adminEncrypt(password, "Axc4RDx3osYg"); //encrypts password
    } else {
        encrypted_password = adminEncrypt("pass", "Axc4RDx3osYg"); //encrypts password
    }
}

Admin::~Admin(){}

string Admin::adminEncrypt(string password, string key){ //method encrypts the password
    //ensures the key is (at a minimum) as long as the message
    string tmp(key);
    while(key.size() < password.size()){
        key += tmp;
    }

    for(int i = 0; i < password.size(); ++i){
        password[i] ^= key[i];
    }
    return password;
}

string Admin::adminDecrypt(string entry, string key){ //method decrpyts the password
    return adminEncrypt(entry, key);
}

string Admin::getName(){
    return name;
}

string Admin::getUsername(){
    return username;
}

string Admin::getPassword(){
    return encrypted_password;
}

void Admin::setName(string n){
    name = n;
}

void Admin::setUsername(string u){
    username = u;
}

void Admin::setPassword(string pass){
    encrypted_password = adminEncrypt(pass, "Axc4RDx3osYg"); //encrypts password
}

string Admin::toString(){
    cout << "Administrator account information:" << endl;
    cout << "Name: " <<  name << endl;
    cout << "Username: " << username << endl;
    cout << endl;
    return "";
}
