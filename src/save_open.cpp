#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>
#include <fstream>

#include "../include/cube.h"
#include "../include/save_open.hpp"

using namespace std;

int sauvegarder(Cube stockCube[], unsigned int taille, string filepath, string filename){
    ofstream file;
    file.open(filepath + filename);
    if(file.bad()) return 1;
    file.seekp(0,ios::end);
    for(int i=0; i<taille; i++){
        if(stockCube[i].isVisible == true){
            file<<i<<" "<<stockCube[i].color.x<<" "<<stockCube[i].color.y<<" "<<stockCube[i].color.z<<endl;
        }
    }
    file.close();
    cout<<"Votre fichier est sauvegardé"<<endl;
    return 0;
}

void charger(Cube stockCube[], unsigned int taille, string filepath, string filename){
    ifstream file(filepath + filename, ios::in | ios::binary);
    string ligne;
    vector<string> texte;

    if(file.is_open()){
        cout<<"fichier ouvert"<<endl;
        while(getline(file, ligne)){
            texte.push_back(move(ligne));
        }

        for(int i=0; i<taille; i++){
            stockCube[i].isVisible = false;
        }

        int indice;
        for (int i=0; i<texte.size(); i++){
            sscanf(texte[i].c_str(), "%d %f %f %f", &indice, &stockCube[indice].color.x, &stockCube[indice].color.y, &stockCube[indice].color.z);
            stockCube[indice].isVisible=true;
        }
    }
    else cout<<"Ce fichier n'existe pas ou l'emplacement est incorrect"<<endl;
}