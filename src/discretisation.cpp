#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

#include "../include/cube.h"
#include "../include/discretisation.hpp"

void discretiser(Cube stockCube[], unsigned int l, unsigned int L, unsigned int H){
    std::cout<<"hey"<<std::endl;
    glm::vec4 current_color;
    unsigned int nbVisible=0;
    float r=0, v=0, b=0;
    for(unsigned int i=0; i<500; i+=2){
        for(unsigned int j=0; j<500; j+=l*2){
            for(unsigned int k=0; k<500; k+=l*L*2){
                //std::cout<<"i : "<<i<<" j : "<<j<<" k : "<<k<<std::endl;
                Cube* tempoStockMiniCube[8]={&stockCube[i+j+k], 
                                            &stockCube[i+j+k+1],
                                            &stockCube[i+j+k+l],
                                            &stockCube[i+j+k+l*L],
                                            &stockCube[i+j+k+1+l],
                                            &stockCube[i+j+k+1+l*L],
                                            &stockCube[i+j+k+1+l+l*L],
                                            &stockCube[i+j+k+l+l*L]
                                            };
                nbVisible=0;
                r=0; 
                v=0;
                b=0;
                for(unsigned int n=0; n<8; n++){
                    if(tempoStockMiniCube[n]->isVisible==true) nbVisible++;
                }
                if(nbVisible<3){
                    for(unsigned int n=0; n<8; n++){
                        tempoStockMiniCube[n]->isVisible=false;
                    } 
                }
                else{
                    for(unsigned int n=0; n<8; n++){
                        if(tempoStockMiniCube[n]->isVisible==true){
                            r+=tempoStockMiniCube[n]->color.x;
                            v+=tempoStockMiniCube[n]->color.y;
                            b+=tempoStockMiniCube[n]->color.z;
                        }
                    }
                    current_color=glm::vec4(r/8,v/8,b/8,0.8f);
                    for(unsigned int n=0; n<8; n++){
                        tempoStockMiniCube[n]->isVisible=true;
                        tempoStockMiniCube[n]->color=current_color;
                    } 
                }
            }
        }     
    }
    std::cout<<"j'ai fini !"<<std::endl;
}