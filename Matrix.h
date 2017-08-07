/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: Nas
 *
 * Created on 30. Juli 2017, 11:55
 */

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    Matrix();
    Matrix(int reihen, int spalten);
    Matrix(int reihen, int spalten, int wert);
    Matrix(const Matrix& matrix);

    double& at(int reihe, int spalte) const;
    void matrixEingabe(Matrix &m);
    void printMatrix(Matrix m) const;

    int GetReihen() const;
    int GetSpalten() const;
 

    Matrix& operator=(const Matrix& matrix);
    Matrix& operator+=(const Matrix& matrix);
    Matrix& operator-(const Matrix& matrix);
    

    ~Matrix();
private:
    int m_reihen;
    int m_spalten;
    double** m_daten;
};

#endif /* MATRIX_H */

