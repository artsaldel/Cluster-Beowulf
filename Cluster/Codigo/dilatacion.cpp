#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace cv;
using namespace std;

Mat imagenColor, imagenEntrada, imagenSalida, 
               imagenNodo1, imagenNodo2,  imagenNodo3,  imagenNodo4,
               imagenNodo5, imagenNodo6,  imagenNodo7,  imagenNodo8,
               imagenNodo9, imagenNodo10, imagenNodo11, imagenNodo12;


int AbrirImagen(char *direccion) 
{
	imagenColor = imread(direccion, 1);
  	imagenEntrada = imread(direccion, 0);
  	imagenSalida = imread(direccion, 0);

    if (imagenEntrada.empty()) 
	{
      	printf("No se encuentra imagen messi\n");
        printf(direccion);
    	return 0;
    } 
	else 
        return 1;
}

void EjecutaDilatacion(int nodo) 
{
  	Mat imagenInicio;
    if (nodo == 0) 
    	imagenInicio = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
	else if (nodo == 1) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
	else if (nodo == 2) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
    else if (nodo == 3) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
    else if (nodo == 4) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
    else if (nodo == 5) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
    else if (nodo == 6) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
    else if (nodo == 7) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo8.jpg", 0);
    else if (nodo == 8) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo9.jpg", 0);
    else if (nodo == 9) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo10.jpg", 0);
    else if (nodo == 10) 
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo11.jpg", 0);
	else
        imagenInicio = imread("/home/cesar/Resultado/imagenNodo12.jpg", 0);

    int row = imagenInicio.rows - 4;
    int col = imagenInicio.cols - 4;
    
    Mat imagenFinal(row, col, CV_8UC1, Scalar(0));

    int ctdrFila = 0;
    int ctdrColumna = 0;
    unsigned char *input = (unsigned char*) (imagenInicio.data);
    unsigned char *temp = (unsigned char*) (imagenFinal.data);
    int ctdrArreglo;

    for (int i = 0; i < row; i++) 
	{
    	ctdrArreglo = i;
    	int byte1, byte2, byte3, byte4, byte5;
    	for (int j = 0; j < 5; j++) 
		{
        	for (int k = 0; k < col;) 
			{
        		byte1 = input[imagenInicio.step * ctdrArreglo + k];
        		byte2 = input[imagenInicio.step * ctdrArreglo + k + 1];
        		byte3 = input[imagenInicio.step * ctdrArreglo + k + 2];
        		byte4 = input[imagenInicio.step * ctdrArreglo + k + 3];
        		byte5 = input[imagenInicio.step * ctdrArreglo + k + 4];
        		int list[5] = {byte1, byte2, byte3, byte4, byte5};
        		int max = 0;
        		for (int x = 0; x < 5; x++) 
				{
            		if (max < list[x]) 
            			max = list[x];
        		}
        		if (temp[imagenFinal.step * ctdrFila + ctdrColumna] < max) 
            		temp[imagenFinal.step * ctdrFila + ctdrColumna] = max;
        		ctdrColumna++;
        		k++;
        	}
        	ctdrArreglo++;
        	ctdrColumna = 0;
    	}
    	ctdrFila++;
    }

    if (nodo == 0) 
        imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenFinal);
	else if (nodo == 1) 
    	imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenFinal);
	else if (nodo == 2) 
    	imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenFinal);
    else if (nodo == 3) 
        imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenFinal);
    else if (nodo == 4) 
        imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenFinal);
    else if (nodo == 5) 
        imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenFinal);
    else if (nodo == 6) 
        imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenFinal);
    else if (nodo == 7) 
        imwrite("/home/cesar/Resultado/imagenNodo8.jpg", imagenFinal);
    else if (nodo == 8) 
        imwrite("/home/cesar/Resultado/imagenNodo9.jpg", imagenFinal);
    else if (nodo == 9) 
        imwrite("/home/cesar/Resultado/imagenNodo10.jpg", imagenFinal);
    else if (nodo == 10) 
        imwrite("/home/cesar/Resultado/imagenNodo11.jpg", imagenFinal);
	else
        imwrite("/home/cesar/Resultado/imagenNodo12.jpg", imagenFinal);
}

void DivideImagen(int nodos) 
{
	int filas = imagenEntrada.rows;
    int num_split;
    switch (nodos) 
	{
    	case 1:
    	{
        	imagenNodo1 = imagenEntrada.rowRange(0, filas);

        	imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);

        	break;
    	}
    	case 2:
    	{
        	num_split = filas / 2;

        	imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
        	imagenNodo2 = imagenEntrada.rowRange(num_split - 2, filas);

        	imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
        	imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);

        	break;
    	}
    	case 3:
    	{
        	num_split = filas / 3;

        	imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
        	imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
        	imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), filas);

        	imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
        	imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
        	imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);

        	break;
    	}
    	case 4:
    	{
        	num_split = filas / 4;

        	imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
        	imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
        	imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
        	imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), filas);

        	imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
        	imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
        	imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
        	imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);

        	break;
    	}
        case 5:
        {
            num_split = filas / 5;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);

            break;
        }
        case 6:
        {
            num_split = filas / 6;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);

            break;
        }
        case 7:
        {
            num_split = filas / 7;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), (num_split * 6 + 2));
            imagenNodo7 = imagenEntrada.rowRange((num_split * 6 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);
            imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenNodo7);

            break;
        }
        case 8:
        {
            num_split = filas / 8;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), (num_split * 6 + 2));
            imagenNodo7 = imagenEntrada.rowRange((num_split * 6 - 2), (num_split * 7 + 2));
            imagenNodo8 = imagenEntrada.rowRange((num_split * 7 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);
            imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenNodo7);
            imwrite("/home/cesar/Resultado/imagenNodo8.jpg", imagenNodo8);

            break;
        }
        case 9:
        {
            num_split = filas / 9;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), (num_split * 6 + 2));
            imagenNodo7 = imagenEntrada.rowRange((num_split * 6 - 2), (num_split * 7 + 2));
            imagenNodo8 = imagenEntrada.rowRange((num_split * 7 - 2), (num_split * 8 + 2));
            imagenNodo9 = imagenEntrada.rowRange((num_split * 8 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);
            imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenNodo7);
            imwrite("/home/cesar/Resultado/imagenNodo8.jpg", imagenNodo8);
            imwrite("/home/cesar/Resultado/imagenNodo9.jpg", imagenNodo9);

            break;
        }
        case 10:
        {
            num_split = filas / 10;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), (num_split * 6 + 2));
            imagenNodo7 = imagenEntrada.rowRange((num_split * 6 - 2), (num_split * 7 + 2));
            imagenNodo8 = imagenEntrada.rowRange((num_split * 7 - 2), (num_split * 8 + 2));
            imagenNodo9 = imagenEntrada.rowRange((num_split * 8 - 2), (num_split * 9 + 2));
            imagenNodo10 = imagenEntrada.rowRange((num_split * 9 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);
            imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenNodo7);
            imwrite("/home/cesar/Resultado/imagenNodo8.jpg", imagenNodo8);
            imwrite("/home/cesar/Resultado/imagenNodo9.jpg", imagenNodo9);
            imwrite("/home/cesar/Resultado/imagenNodo10.jpg", imagenNodo10);

            break;
        }
        case 11:
        {
            num_split = filas / 11;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), (num_split * 6 + 2));
            imagenNodo7 = imagenEntrada.rowRange((num_split * 6 - 2), (num_split * 7 + 2));
            imagenNodo8 = imagenEntrada.rowRange((num_split * 7 - 2), (num_split * 8 + 2));
            imagenNodo9 = imagenEntrada.rowRange((num_split * 8 - 2), (num_split * 9 + 2));
            imagenNodo10 = imagenEntrada.rowRange((num_split * 9 - 2), (num_split * 10 + 2));
            imagenNodo11 = imagenEntrada.rowRange((num_split * 10 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);
            imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenNodo7);
            imwrite("/home/cesar/Resultado/imagenNodo8.jpg", imagenNodo8);
            imwrite("/home/cesar/Resultado/imagenNodo9.jpg", imagenNodo9);
            imwrite("/home/cesar/Resultado/imagenNodo10.jpg", imagenNodo10);
            imwrite("/home/cesar/Resultado/imagenNodo11.jpg", imagenNodo11);

            break;
        }
        case 12:
        {
            num_split = filas / 12;

            imagenNodo1 = imagenEntrada.rowRange(0, num_split + 2);
            imagenNodo2 = imagenEntrada.rowRange(num_split - 2, (num_split * 2 + 2));
            imagenNodo3 = imagenEntrada.rowRange((num_split * 2 - 2), (num_split * 3 + 2));
            imagenNodo4 = imagenEntrada.rowRange((num_split * 3 - 2), (num_split * 4 + 2));
            imagenNodo5 = imagenEntrada.rowRange((num_split * 4 - 2), (num_split * 5 + 2));
            imagenNodo6 = imagenEntrada.rowRange((num_split * 5 - 2), (num_split * 6 + 2));
            imagenNodo7 = imagenEntrada.rowRange((num_split * 6 - 2), (num_split * 7 + 2));
            imagenNodo8 = imagenEntrada.rowRange((num_split * 7 - 2), (num_split * 8 + 2));
            imagenNodo9 = imagenEntrada.rowRange((num_split * 8 - 2), (num_split * 9 + 2));
            imagenNodo10 = imagenEntrada.rowRange((num_split * 9 - 2), (num_split * 10 + 2));
            imagenNodo11 = imagenEntrada.rowRange((num_split * 10 - 2), (num_split * 11 + 2));
            imagenNodo12 = imagenEntrada.rowRange((num_split * 11 - 2), filas);

            imwrite("/home/cesar/Resultado/imagenNodo1.jpg", imagenNodo1);
            imwrite("/home/cesar/Resultado/imagenNodo2.jpg", imagenNodo2);
            imwrite("/home/cesar/Resultado/imagenNodo3.jpg", imagenNodo3);
            imwrite("/home/cesar/Resultado/imagenNodo4.jpg", imagenNodo4);
            imwrite("/home/cesar/Resultado/imagenNodo5.jpg", imagenNodo5);
            imwrite("/home/cesar/Resultado/imagenNodo6.jpg", imagenNodo6);
            imwrite("/home/cesar/Resultado/imagenNodo7.jpg", imagenNodo7);
            imwrite("/home/cesar/Resultado/imagenNodo8.jpg", imagenNodo8);
            imwrite("/home/cesar/Resultado/imagenNodo9.jpg", imagenNodo9);
            imwrite("/home/cesar/Resultado/imagenNodo10.jpg", imagenNodo10);
            imwrite("/home/cesar/Resultado/imagenNodo11.jpg", imagenNodo11);
            imwrite("/home/cesar/Resultado/imagenNodo12.jpg", imagenNodo12);

            break;
        }
    	default:
        	break;
    }   
}


double AnchoBanda(int nodos, char *path, double time) 
{
	int bits = 0;
    if (nodos == 1) 
	 	return bits;
	else 
	{
    	FILE * f = fopen(path, "r");
    	fseek(f, 0, SEEK_END);
    	double tamanoImagen = (double) ftell(f);
    	tamanoImagen = tamanoImagen / (1000000);
    	fclose(f);
    	double fragmentoImagen = ((tamanoImagen / nodos) * (nodos - 1) * 2) + (((nodos - 1) * 2) / 1000000);
    	fragmentoImagen = fragmentoImagen / time;
    	return fragmentoImagen;
    }
}

void CombinaImagen(int nodos) 
{
   	switch (nodos) 
	{
    	case 1:
        {
        	imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
        	imagenSalida = imagenNodo1;
        	
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
        	break;
        }
    	case 2:
    	{
        	imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
        	imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
        	
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
        	imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
        	vconcat(imagenNodo1, imagenNodo2, imagenSalida);
        	
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
        	break;
    	}
    	case 3:
    	{
        	imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
        	imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
        	imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
        	
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
        	imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
        	vconcat(imagenNodo1, imagenNodo2, imagenSalida);
        	
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
        	vconcat(imagenSalida, imagenNodo3, imagenSalida);
        	
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
        	break;
    	}
    	case 4:
    	{
        	imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
        	imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
        	imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
        	imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
        	
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
        	imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
        	vconcat(imagenNodo1, imagenNodo2, imagenSalida);
        	
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
        	vconcat(imagenSalida, imagenNodo3, imagenSalida);
        	
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);
        	
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
        	break;
    	}
        case 5:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 6:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 7:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            imagenNodo7 = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);

            imagenNodo7 = imagenNodo7.rowRange(0, imagenNodo7.rows);
            vconcat(imagenSalida, imagenNodo7, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 8:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            imagenNodo7 = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
            imagenNodo8 = imread("/home/cesar/Resultado/imagenNodo8.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);

            imagenNodo7 = imagenNodo7.rowRange(0, imagenNodo7.rows);
            vconcat(imagenSalida, imagenNodo7, imagenSalida);

            imagenNodo8 = imagenNodo8.rowRange(0, imagenNodo8.rows);
            vconcat(imagenSalida, imagenNodo8, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 9:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            imagenNodo7 = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
            imagenNodo8 = imread("/home/cesar/Resultado/imagenNodo8.jpg", 0);
            imagenNodo9 = imread("/home/cesar/Resultado/imagenNodo9.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);

            imagenNodo7 = imagenNodo7.rowRange(0, imagenNodo7.rows);
            vconcat(imagenSalida, imagenNodo7, imagenSalida);

            imagenNodo8 = imagenNodo8.rowRange(0, imagenNodo8.rows);
            vconcat(imagenSalida, imagenNodo8, imagenSalida);

            imagenNodo9 = imagenNodo9.rowRange(0, imagenNodo9.rows);
            vconcat(imagenSalida, imagenNodo9, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 10:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            imagenNodo7 = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
            imagenNodo8 = imread("/home/cesar/Resultado/imagenNodo8.jpg", 0);
            imagenNodo9 = imread("/home/cesar/Resultado/imagenNodo9.jpg", 0);
            imagenNodo10 = imread("/home/cesar/Resultado/imagenNodo10.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);

            imagenNodo7 = imagenNodo7.rowRange(0, imagenNodo7.rows);
            vconcat(imagenSalida, imagenNodo7, imagenSalida);

            imagenNodo8 = imagenNodo8.rowRange(0, imagenNodo8.rows);
            vconcat(imagenSalida, imagenNodo8, imagenSalida);

            imagenNodo9 = imagenNodo9.rowRange(0, imagenNodo9.rows);
            vconcat(imagenSalida, imagenNodo9, imagenSalida);

            imagenNodo10 = imagenNodo10.rowRange(0, imagenNodo10.rows);
            vconcat(imagenSalida, imagenNodo10, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 11:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            imagenNodo7 = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
            imagenNodo8 = imread("/home/cesar/Resultado/imagenNodo8.jpg", 0);
            imagenNodo9 = imread("/home/cesar/Resultado/imagenNodo9.jpg", 0);
            imagenNodo10 = imread("/home/cesar/Resultado/imagenNodo10.jpg", 0);
            imagenNodo11 = imread("/home/cesar/Resultado/imagenNodo11.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);

            imagenNodo7 = imagenNodo7.rowRange(0, imagenNodo7.rows);
            vconcat(imagenSalida, imagenNodo7, imagenSalida);

            imagenNodo8 = imagenNodo8.rowRange(0, imagenNodo8.rows);
            vconcat(imagenSalida, imagenNodo8, imagenSalida);

            imagenNodo9 = imagenNodo9.rowRange(0, imagenNodo9.rows);
            vconcat(imagenSalida, imagenNodo9, imagenSalida);

            imagenNodo10 = imagenNodo10.rowRange(0, imagenNodo10.rows);
            vconcat(imagenSalida, imagenNodo10, imagenSalida);

            imagenNodo11 = imagenNodo11.rowRange(0, imagenNodo11.rows);
            vconcat(imagenSalida, imagenNodo11, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
        case 12:
        {
            imagenNodo1 = imread("/home/cesar/Resultado/imagenNodo1.jpg", 0);
            imagenNodo2 = imread("/home/cesar/Resultado/imagenNodo2.jpg", 0);
            imagenNodo3 = imread("/home/cesar/Resultado/imagenNodo3.jpg", 0);
            imagenNodo4 = imread("/home/cesar/Resultado/imagenNodo4.jpg", 0);
            imagenNodo5 = imread("/home/cesar/Resultado/imagenNodo5.jpg", 0);
            imagenNodo6 = imread("/home/cesar/Resultado/imagenNodo6.jpg", 0);
            imagenNodo7 = imread("/home/cesar/Resultado/imagenNodo7.jpg", 0);
            imagenNodo8 = imread("/home/cesar/Resultado/imagenNodo8.jpg", 0);
            imagenNodo9 = imread("/home/cesar/Resultado/imagenNodo9.jpg", 0);
            imagenNodo10 = imread("/home/cesar/Resultado/imagenNodo10.jpg", 0);
            imagenNodo11 = imread("/home/cesar/Resultado/imagenNodo11.jpg", 0);
            imagenNodo12 = imread("/home/cesar/Resultado/imagenNodo12.jpg", 0);
            
            imagenNodo1 = imagenNodo1.rowRange(0, imagenNodo1.rows);
            imagenNodo2 = imagenNodo2.rowRange(0, imagenNodo2.rows);
            vconcat(imagenNodo1, imagenNodo2, imagenSalida);
            
            imagenNodo3 = imagenNodo3.rowRange(0, imagenNodo3.rows);
            vconcat(imagenSalida, imagenNodo3, imagenSalida);
            
            imagenNodo4 = imagenNodo4.rowRange(0, imagenNodo4.rows);
            vconcat(imagenSalida, imagenNodo4, imagenSalida);

            imagenNodo5 = imagenNodo5.rowRange(0, imagenNodo5.rows);
            vconcat(imagenSalida, imagenNodo5, imagenSalida);

            imagenNodo6 = imagenNodo6.rowRange(0, imagenNodo6.rows);
            vconcat(imagenSalida, imagenNodo6, imagenSalida);

            imagenNodo7 = imagenNodo7.rowRange(0, imagenNodo7.rows);
            vconcat(imagenSalida, imagenNodo7, imagenSalida);

            imagenNodo8 = imagenNodo8.rowRange(0, imagenNodo8.rows);
            vconcat(imagenSalida, imagenNodo8, imagenSalida);

            imagenNodo9 = imagenNodo9.rowRange(0, imagenNodo9.rows);
            vconcat(imagenSalida, imagenNodo9, imagenSalida);

            imagenNodo10 = imagenNodo10.rowRange(0, imagenNodo10.rows);
            vconcat(imagenSalida, imagenNodo10, imagenSalida);

            imagenNodo11 = imagenNodo11.rowRange(0, imagenNodo11.rows);
            vconcat(imagenSalida, imagenNodo11, imagenSalida);

            imagenNodo12 = imagenNodo12.rowRange(0, imagenNodo12.rows);
            vconcat(imagenSalida, imagenNodo12, imagenSalida);
            
            imwrite("/home/cesar/Resultado/final.jpg", imagenSalida);
            break;
        }
    	default:
			break;
    }
}
