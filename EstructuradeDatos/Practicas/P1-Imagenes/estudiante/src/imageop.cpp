/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

/*
Esta práctica ha sido realizada por:
    -> Alberto Cámara Ortiz.
    -> Hugo Béjar Murcia.
*/

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

using namespace std;


// Genera una subimagen.
    /**
     * @brief Función para generar una subimagen.
     * @param nrow Fila inicial para recortar
     * @param ncol Columna inicial para recortar
     * @param height Número de filas
     * @param width Número de columnas
     * @return Imagen con el recorte.
     * @post El objeto que llama a la función no se modifica
     */
Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image image(height,width);

    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            image.set_pixel(i,j, img[i+nrow][j+ncol]);
           
    return image;
} 


// Genera una imagen aumentada 2x.
    /**
     * @brief Función para hacer un aumento x2 en una imagen.
     * @param fila Fila de la esquina superior izquierda de la región a zoom.
     * @param col Columna de la esquina superior izquierda de la región a zoom.
     * @param lado Dimensión de la región a aumentar.
     * @return Devuelve la region aumentada 2 veces como una imagen nueva.
     * @post La imagen original no se modifica
     * @post La imagen resultante tendrá un tamaño (2*lado - 1) X (2*lado - 1), siempre y cuando lado mas col o fil sea menor que las dimensiones de la imagen original, sino se modificará.
    */
Image Image::Zoom2X(int fila, int col, int lado) const {
    int fila_lado;
    int col_lado;

    if (fila + lado >= this->get_rows())
        fila_lado = this->get_rows() - fila - 1;
    else 
        fila_lado = lado;

    if (col + lado >= this->get_cols())
        col_lado = this->get_cols() - col - 1;
    else 
        col_lado = lado;


    Image zoom(2*fila_lado - 1, 2*col_lado - 1);

    int fila_rec = 0;
    int col_rec;
    float pixel;

    //Añadimos los pixeles pares, los cuales ya están en la imagen
    for (int i = 0; i < 2*fila_lado - 1; i+=2){
        col_rec = 0;
        for (int j = 0; j < 2*col_lado - 1; j +=2){
            zoom.set_pixel(i,j,get_pixel(fila + fila_rec,col + col_rec));
            col_rec++;
        }
        fila_rec++;
    }

    //Añadimos los pixeles impares de las columnas
    fila_rec = 0;
    for (int i = 0; i < 2*fila_lado - 1; i+=2){ //+= porque estamos poniendo en las filas conocidas
        col_rec = 0;
        for (int j = 1; j < 2*col_lado - 1; j+=2){
            pixel = ((get_pixel(fila + fila_rec, col + col_rec)) + (get_pixel(fila + fila_rec, col + col_rec + 1))) / 2;
            zoom.set_pixel(i,j, roundf(pixel));
            col_rec++;
        }
        fila_rec++;
    }

    //Añadimos los pixeles en las filas impares
    fila_rec = 1;
    for (int i = 1; i < 2*fila_lado - 1; i+=2){
        col_rec = 0;
        for (int j = 0; j < 2*col_lado - 1; j++){
            if (j % 2 == 1){ 
                pixel = (zoom.get_pixel(i - 1,j) + zoom.get_pixel(i + 1, j)) / 2;
                
            }else {
                pixel = (zoom.get_pixel(i - 1, j - 1) + zoom.get_pixel(i - 1, j + 1) + zoom.get_pixel(i + 1, j - 1) + zoom.get_pixel(i + 1, j + 1)) / 4;
           }
            zoom.set_pixel(i,j, roundf(pixel));
            col_rec++;
        }
        fila_rec++;
    }
    
    return zoom;
}


// Crear una imagen de tamaño reducido a partir de una imagen original.

    /**
     * @brief Genera un icono como reducción de una imagen.
     * @param factor Factor de reducción de la imagen original con respecto al icono.
     * @pre factor > 0
     * @return La imagen iconizada.
     * @post La imagen no se modifica.
     * @post La imagen resultante tendrá un tamaño int(filas/factor) x int(columnas/factor).
    */
Image Image::Subsample(int factor) const{
    Image subsample(floor(get_rows() / factor), floor(get_cols() / factor));

    for (int i = 0; i < subsample.get_rows(); i++) {
        for (int j = 0; j < subsample.get_cols(); j++) {
            float media = 0;
            for (int h = 0; h < factor; h++) {
                for (int g = 0; g < factor; g++) {
                    media += (float)get_pixel(h + factor * i, g + factor * j);
                }
            }
            media /= (float)(factor * factor);
            subsample.set_pixel(i, j, (byte)roundf(media));
        }
    }
    return subsample;
}


// Genera una imagen de niveles de gris con más contraste que la original.

    /**
     * @brief Modifica el contraste de una imagen.
     * @param in1 Umbral inferior de la imagen de entrada.
     * @param in2 Umbral superior de la imagen de entrada.
     * @param out1 Umbral inferior de la imagen de salida.
     * @param out2 Umbral superior de la imagen de salida.
     * @pre 0 <= (in1, in2, out1, out2) <= 255
     * @pre in1 < in2
     * @pre out1 < out2
     * @post El objeto que llama a la función es modificado.
    */
void Image:: AdjustContrast(byte e1, byte e2, byte s1, byte s2){
    if(0 <= (e1, e2, s1, s2) <= 255 && e1 < e2 && s1 < s2){
        float minimo, maximo, a, b;
        for(int i=0; i<rows*cols; i++){
            byte pixel = get_pixel(i);
            byte pixel_nuevo;
            if(0 < pixel && pixel < e1){
                a = 0;
                b = (float)e1;
                minimo = 0;
                maximo = s1;
            } else if (e1 < pixel && pixel < e2){
                a = (float)e1;
                b = (float)e2;
                minimo = (float)s1;
                maximo = (float)s2;
            } else if (e2 < pixel && pixel < 255){
                a = (float)e2;
                b = 255;
                minimo = (float)s2;
                maximo = 255;
            }

            pixel_nuevo = (byte) roundf((minimo + ((maximo - minimo) / (b-a) * pixel-a)));
            set_pixel(i, pixel_nuevo);
        }
    }
}

void Image::ShuffleRows() {
    const int p = 9973;
    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p % rows;
        for (int c=0; c<cols;c++)
            temp.set_pixel(r,c,get_pixel(newr,c));
    }
    Copy(temp);
}