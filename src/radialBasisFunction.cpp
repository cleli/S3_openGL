#include <iostream>
#include <Eigen/Dense>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <random>
#include <functional>
#include <chrono>

#include "../include/radialBasisFunction.hpp"
#include "../include/cube.h"

using namespace Eigen;

//calcul de la norme
const double norm(const glm::vec3 vec1){
    return( (double)sqrt(vec1.x*vec1.x + vec1.y*vec1.y + vec1.z*vec1.z ));
} 

//Déterminer les omega i
const VectorXd find_omega(unsigned int nbPointsControle, std::vector<Cube*> v_pointsControle){
    MatrixXd M_contrainte = MatrixXd::Zero(nbPointsControle, nbPointsControle);
    //VectorXd omega = VectorXd::Ones(nbPointsControle);
    VectorXd poids = VectorXd::Ones(nbPointsControle);

    //remplissage du vecteur de poids des points de controle
    for(int h=0; h<nbPointsControle; h++){
        poids[h]=v_pointsControle[h]->poids;
    }

    //remplissage de notre matrice 
    for(int i=0; i<nbPointsControle; i++){
        for(int j=0; j<nbPointsControle; j++){
            M_contrainte(i,j) = phi(norm(v_pointsControle[i]->position-v_pointsControle[j]->position));
        }
    }
    
    //méthode de résolution de M_contrainte*omega=poids
    //On choisit la méthode LU car elle est plus rapide
    PartialPivLU<MatrixXd> lu(M_contrainte);
    VectorXd omega = lu.solve(poids);

    return omega;
}

//création de notre fonction pour générer le terrain
void gener_terrain(unsigned int nbPointsControle, Cube* actualCube, const std::vector<Cube*> v_pointsControle){
    VectorXd omega = find_omega(nbPointsControle, v_pointsControle);
    for(int i=0; i<nbPointsControle; i++){

        if (actualCube->poids == 0) actualCube->poids += omega[i]*phi(norm((actualCube->position-v_pointsControle[i]->position)));
    }
}

void gener_terrainAleatoire(unsigned int l,unsigned int L, unsigned int H, Cube stockCube[]){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<float> uniformRealDistribution(-2,2);

    unsigned int nbPointsControle = 5;

    for(int i=0;i<l*L*H;i++){ 
        stockCube[i].isVisible=false;
    }
    
    std::uniform_int_distribution<int> uniformIntDistribution(0,l*L*H-1);

    std::vector<Cube*> v_pointsControle;

    for(int i=0;i<nbPointsControle;i++){
        int currentPtControle = uniformIntDistribution(generator);
        float currentPoids = uniformRealDistribution(generator);

        stockCube[currentPtControle].isVisible = true;
        stockCube[currentPtControle].poids = currentPoids;
        v_pointsControle.push_back(&stockCube[currentPtControle]);
    }
    
    
    for(int i=0;i<l*L*H;i++){
        gener_terrain(nbPointsControle, &stockCube[i], v_pointsControle);  
        if(stockCube[i].poids >0.5){
            stockCube[i].isVisible=true;
        }        
    }
}
