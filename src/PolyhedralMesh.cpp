#include "PolyhedralMesh.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace Eigen;


namespace PolyhedralLibrary {


void Tetraedro(PolyhedralMesh& pm){

    pm.NumCell0Ds = 4; // numero vertici tetraedro
	pm.Cell0DsId.resize(pm.NumCell0Ds);
	unsigned int i= 0;
    for (i = 0; i < 4; i++){
        pm.Cell0DsId[i] = i; // vettore degli id dei vertici
    }
	
	pm.Cell0DsCoordinates.resize(pm.NumCell0Ds,3);
	pm.Cell0DsCoordinates << 
		 0.577350269,  0.577350269,  0.577350269,
		 0.577350269, -0.577350269, -0.577350269,
		-0.577350269,  0.577350269, -0.577350269,
		-0.577350269, -0.577350269,  0.577350269;

                            
    pm.NumCell1Ds = 6;
	pm.Cell1DsId.resize(pm.NumCell1Ds);

    for (i = 0; i < 6; i++){
        pm.Cell1DsId[i] = i; // vettore degli id dei lati
    }
	
	pm.Cell1DsExtrema.resize(pm.NumCell1Ds, 2);

    pm.Cell1DsExtrema << 0, 1,
                        0, 2, 
                        0, 3, 
                        1, 2, 
                        1, 3, 
                        2, 3;
                        

    pm.NumCell2Ds = 4;
	pm.Cell2DsId.resize(pm.NumCell2Ds);
    for (i = 0; i < 4; i++){
        pm.Cell2DsId[i] = i; // vettore degli id delle facce
    }
	pm.Cell2DsVertices.resize(pm.NumCell2Ds, 3);

    pm.Cell2DsVertices <<
        0, 1, 2,
        0, 2, 3,
        1, 2, 3,
        0, 1, 3;
	
	pm.Cell2DsEdges.resize(pm.NumCell2Ds, 3);

    pm.Cell2DsEdges <<
        0, 1, 3,
        1, 2, 5,
        3, 4, 5,
        0, 2, 4;


    pm.Cell3DsId = 0; // id poliedro

	pm.Cell3DsVertices = pm.Cell0DsId;

    pm.Cell3DsEdges = pm.Cell1DsId;

    pm.Cell3DsFaces = pm.Cell2DsId;
}

void Cubo(PolyhedralMesh& pm){
    pm.NumCell0Ds = 8; //numero vertici cubo

	unsigned int i= 0;
	
	pm.Cell0DsId.resize(pm.NumCell0Ds);
	
    for (i = 0; i < 8; i++){
        pm.Cell0DsId[i] = i; // vettore degli id dei vertici
    }
	pm.Cell0DsCoordinates.resize(pm.NumCell0Ds,3);
	pm.Cell0DsCoordinates <<
		 0.577350269,  0.577350269,  0.577350269,
		 0.577350269, -0.577350269, -0.577350269,
		-0.577350269,  0.577350269, -0.577350269,
		-0.577350269, -0.577350269,  0.577350269,
		 0.577350269,  0.577350269, -0.577350269,
		 0.577350269, -0.577350269,  0.577350269,
		-0.577350269,  0.577350269,  0.577350269,
		-0.577350269, -0.577350269, -0.577350269;


                            
    pm.NumCell1Ds = 12; //numero lati cubo
	pm.Cell1DsId.resize(pm.NumCell1Ds);
    for (i = 0; i < 12; i++){
        pm.Cell1DsId[i] = i; // vettore degli id dei lati
    }
	pm.Cell1DsExtrema.resize(pm.NumCell1Ds, 2);
    pm.Cell1DsExtrema << 0, 4,
                         0, 5,
                         0, 6,
                         1, 4,
                         1, 5,
                         1, 7,
                         2, 4,
                         2, 6,
                         2, 7,
                         3, 5,
                         3, 6,
                         3, 7;
                        

    pm.NumCell2Ds = 6; // numero facce cubo
	pm.Cell2DsId.resize(pm.NumCell2Ds);
    for (i = 0; i < 6; i++){
        pm.Cell2DsId[i] = i; // vettore degli id delle facce
    }
	pm.Cell2DsVertices.resize(pm.NumCell2Ds, 4);
	
    pm.Cell2DsVertices << 
    
							0, 4, 1, 5,
							0, 4, 2, 6,
							0, 6, 3, 5,
							6, 2, 7, 3,
							3, 5, 1, 7,
							2, 7, 1, 4;
   
	pm.Cell2DsEdges.resize(pm.NumCell2Ds, 4);

    pm.Cell2DsEdges << 
    
							6, 9, 10, 7,
							6, 12, 13, 8,
							8, 16, 15, 7,
							13, 14, 17, 16,
							15, 10, 11, 17,
							14, 11, 9, 12;


    pm.Cell3DsId = 1;
    

    pm.Cell3DsVertices = pm.Cell0DsId;

	pm.Cell3DsEdges = pm.Cell1DsId;

	pm.Cell3DsFaces = pm.Cell2DsId;
   
}

void Ottaedro(PolyhedralMesh& pm){
    pm.NumCell0Ds = 6;
	
	unsigned int i= 0;
	pm.Cell0DsId.resize(pm.NumCell0Ds);
    for (i = 0; i < 6; i++){
        pm.Cell0DsId[i] = i; // vettore degli id dei vertici
    }
	pm.Cell0DsCoordinates.resize(pm.NumCell0Ds,3);
    pm.Cell0DsCoordinates << 1, 0, 0,
                            -1, 0, 0,
                            0, 1, 0,
                            0, -1, 0,
                            0, 0, 1,
                            0, 0, -1;


    pm.NumCell1Ds = 12; //numero lati ottaedro
	pm.Cell1DsId.resize(pm.NumCell1Ds);
    for (i = 0; i < 12; i++){
        pm.Cell1DsId[i] = i; // vettore degli id dei lati
    }
	
	pm.Cell1DsExtrema.resize(pm.NumCell1Ds, 2);
    pm.Cell1DsExtrema << 0, 2,
                         0, 3,
                         0, 4,
                         0, 5,
                         1, 2,
                         1, 3,
                         1, 4,
                         1, 5,
                         2, 4,
                         2, 5,
                         3, 4,
                         3, 5;

    pm.NumCell2Ds = 8; // numero facce ottaedro
	
	pm.Cell2DsId.resize(pm.NumCell2Ds);
    for (i = 0; i < 8; i++){
        pm.Cell2DsId[i] = i; // vettore degli id delle facce
    }
	pm.Cell2DsVertices.resize(pm.NumCell2Ds, 3);
	
    pm.Cell2DsVertices <<
							4, 2, 1,
							4, 3, 1,
							4, 3, 0,
							4, 0, 2,
							5, 0, 2,
							5, 2, 1,
							5, 1, 3,
							5, 3, 0;
		
	pm.Cell2DsEdges.resize(pm.NumCell2Ds, 3);

    pm.Cell2DsEdges <<
							8, 4, 6,
							10, 5, 6,
							10, 1, 2,
							2, 0, 8,
							3, 0, 9,
							9, 4, 7,
							7, 5, 11,
							11, 1, 3;


    pm.Cell3DsId = 2;

    pm.Cell3DsVertices = pm.Cell0DsId;

    pm.Cell3DsEdges = pm.Cell1DsId;

    pm.Cell3DsFaces = pm.Cell2DsId;

}


void Dodecaedro(PolyhedralMesh& pm){
    pm.NumCell0Ds = 20; // numero vertici dodecaedro
	
	unsigned int i = 0;
	pm.Cell0DsId.resize(pm.NumCell0Ds);
    for (i = 0; i < 20; i++){
        pm.Cell0DsId[i] = i; // vettore degli id dei vertici
    }
	
	pm.Cell0DsCoordinates.resize(pm.NumCell0Ds,3);
	pm.Cell0DsCoordinates <<
		 0.577350269,  0.577350269,  0.577350269,
		 0.577350269, -0.577350269, -0.577350269,
		-0.577350269,  0.577350269, -0.577350269,
		-0.577350269, -0.577350269,  0.577350269,
		 0.577350269,  0.577350269, -0.577350269,
		 0.577350269, -0.577350269,  0.577350269,
		-0.577350269,  0.577350269,  0.577350269,
		-0.577350269, -0.577350269, -0.577350269,
		 0.934172359,  0.35682209,   0,
		 0.934172359, -0.35682209,   0,
		-0.934172359,  0.35682209,   0,
		-0.934172359, -0.35682209,   0,
		 0.35682209,   0,  0.934172359,
		-0.35682209,   0,  0.934172359,
		 0.35682209,   0, -0.934172359,
		-0.35682209,   0, -0.934172359,
		 0,  0.934172359,  0.35682209,
		 0, -0.934172359,  0.35682209,
		 0,  0.934172359, -0.35682209,
		 0, -0.934172359, -0.35682209;



    pm.NumCell1Ds = 30; //numero lati dodecaedro
	
	pm.Cell1DsId.resize(pm.NumCell1Ds);
	
    for (i = 0; i < 30; i++){
        pm.Cell1DsId[i] = i; // vettore degli id dei lati
    }
	
	pm.Cell1DsExtrema.resize(pm.NumCell1Ds, 2);

    pm.Cell1DsExtrema << 	0, 16,
							0, 12,
							0, 8,
							6, 16,
							6, 13,
							6, 10,
							3, 17,
							3, 11,
							3, 13,
							5, 17,
							5, 9,
							5, 12,
							4, 8,
							4, 18,
							4, 14,
							2, 18,
							2, 10,
							2, 15,
							7, 11,
							7, 15,
							7, 19,
							1, 9,
							1, 14,
							1, 19,
							16, 11,
							14, 9,
							22, 18,
							23, 19,
							19, 12,
							21, 14;

    pm.NumCell2Ds = 12; // numero facce dodecaedro

	pm.Cell2DsId.resize(pm.NumCell2Ds);
	
    for (i = 0; i < 12; i++){
        pm.Cell2DsId[i] = i; // vettore degli id delle facce
    }

	pm.Cell2DsVertices.resize(pm.NumCell2Ds, 5);
	
    pm.Cell2DsVertices <<   13, 6, 16, 0, 12,
							3, 13, 12, 5, 17,
							3, 11, 10, 6, 13,
							5, 12, 0, 8, 9,
							15, 7, 19, 1, 14,
							2, 15, 14, 4, 18,
							2, 10, 11, 7, 15,
							4, 14, 1, 9, 8,
							4, 8, 0, 16, 18,
							2, 18, 16, 6, 10,
							7, 11, 3, 17, 19,
							1, 19, 17, 5, 9;
						
	pm.Cell2DsEdges.resize(pm.NumCell2Ds, 5);

    pm.Cell2DsEdges << 		4, 3, 0, 1, 28,
							8, 28, 11, 9, 6,
							7, 24, 5, 4, 8,
							11, 1, 2, 25, 10,
							19, 20, 23, 22, 29,
							17, 29, 14, 13, 15,
							16, 24, 18, 19, 17,
							14, 22, 21, 25, 12,
							12, 2, 0, 26, 13,
							15, 26, 3, 5, 16,
							18, 7, 6, 27, 20,
							23, 27, 9, 10, 21;
    

    pm.Cell3DsId = 3; // id ottaedro

    pm.Cell3DsVertices = pm.Cell0DsId;

    pm.Cell3DsEdges = pm.Cell1DsId;

    pm.Cell3DsFaces = pm.Cell2DsId;
}

void Icosaedro(PolyhedralMesh& pm){
	pm.NumCell0Ds = 12; // numero vertici icosaedro
	unsigned int i = 0;

	pm.Cell0DsId.resize(pm.NumCell0Ds);
    for (i = 0; i < 12; i++){
        pm.Cell0DsId[i] = i; // vettore degli id dei vertici
    }
  
	pm.Cell0DsCoordinates.resize(pm.NumCell0Ds,3);
	pm.Cell0DsCoordinates <<
		 0.850650808,  0.525731112,  0,
		 0.850650808, -0.525731112,  0,
		-0.850650808, -0.525731112,  0,
		-0.850650808,  0.525731112,  0,
		 0.525731112,  0,  0.850650808,
		-0.525731112,  0,  0.850650808,
		-0.525731112,  0, -0.850650808,
		 0.525731112,  0, -0.850650808,
		 0,  0.850650808,  0.525731112,
		 0,  0.850650808, -0.525731112,
		 0, -0.850650808, -0.525731112,
		 0, -0.850650808,  0.525731112;



    pm.NumCell1Ds = 30; //numero lati icosaedro
	pm.Cell1DsId.resize(pm.NumCell1Ds);

    for (i = 0; i < 30; i++){
        pm.Cell1DsId[i] = i; // vettore degli id dei lati
    }
	pm.Cell1DsExtrema.resize(pm.NumCell1Ds, 2);
    pm.Cell1DsExtrema <<    5, 8,
							5, 3,
							5, 2,
							5, 11,
							5, 4,
							4, 8,
							4, 0,
							4, 1,
							4, 11,
							7, 0,
							7, 1,
							7, 10,
							7, 9,
							7, 6,
							6, 9,
							6, 3,
							6, 2,
							6, 10,
							8, 0,
							8, 9,
							8, 3,
							9, 0,
							9, 3,
							11, 2,
							11, 10,
							11, 1,
							10, 2,
							10, 1,
							1, 0,
							2, 3;

    pm.NumCell2Ds = 20; // numero facce icosaedro
	pm.Cell2DsId.resize(pm.NumCell2Ds);

    for (i = 0; i < 20; i++){
        pm.Cell2DsId[i] = i; // vettore degli id delle facce
    }
	
	pm.Cell2DsVertices.resize(pm.NumCell2Ds, 3);

    pm.Cell2DsVertices <<   11, 5, 4,
							5, 8, 4,
							5, 3, 8,
							5, 2, 3,
							2, 5, 11,
							11, 4, 1,
							1, 4, 0,
							4, 8, 0,
							6, 10, 7,
							6, 9, 7,
							6, 2, 10,
							3, 2, 6,
							3, 6, 9,
							9, 7, 0,
							0, 7, 1,
							7, 10, 1,
							10, 2, 11,
							10, 11, 1,
							9, 8, 3,
							9, 0, 8;
      
   
	pm.Cell2DsEdges.resize(pm.NumCell2Ds, 3);

    pm.Cell2DsEdges <<  8, 3, 4,
						4, 5, 0,
						1, 0, 20,
						2, 29, 1,
						2, 3, 23,
						8, 7, 25,
						7, 6, 28,
						5, 18, 6,
						17, 11, 13,
						14, 12, 13,
						16, 26, 17,
						29, 16, 15,
						15, 14, 22,
						12, 9, 21,
						9, 10, 28,
						11, 27, 10,
						26, 23, 24,
						24, 25, 27,
						19, 20, 22,
						21, 18, 19;
							   

    pm.Cell3DsId = 4; // id icosaedro

    pm.Cell3DsVertices = pm.Cell0DsId;
    
	pm.Cell3DsEdges = pm.Cell1DsId;

	pm.Cell3DsFaces = pm.Cell2DsId;
    
}


}
