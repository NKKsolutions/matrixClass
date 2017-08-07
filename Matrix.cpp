/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.cpp
 * Author: Nas
 * 
 * Created on 30. Juli 2017, 11:55
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() {
}

Matrix::Matrix(int reihen, int spalten) : m_reihen(reihen), m_spalten(spalten) {
    m_daten = new double*[m_reihen];
    for (int i = 0; i < m_reihen; i++) {
        m_daten[i] = new double[m_spalten];
    }

    for (int i = 0; i < m_reihen; i++) {
        for (int j = 0; j < m_spalten; j++) {
            m_daten[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(int reihen, int spalten, int wert) :
m_reihen(reihen), m_spalten(spalten) {
    m_daten = new double*[m_reihen];
    for (int i = 0; i < m_reihen; i++) {
        m_daten[i] = new double[m_spalten];
    }

    for (int i = 0; i < m_reihen; i++) {
        for (int j = 0; j < m_spalten; j++) {
            m_daten[i][j] = wert;
        }
    }
}

Matrix::Matrix(const Matrix& matrix) : m_reihen(matrix.m_reihen), m_spalten(matrix.m_spalten) {
    m_daten = new double*[m_reihen];
    for (int i = 0; i < m_reihen; i++) {
        m_daten[i] = new double[m_spalten];
    }

    for (int i = 0; i < m_reihen; i++) {
        for (int j = 0; j < m_spalten; j++) {
            m_daten[i][j] = matrix.m_daten[i][j];
        }
    }
}

int Matrix::GetReihen() const {
    return m_reihen;
}

int Matrix::GetSpalten() const {
    return m_spalten;
}



double& Matrix::at(int reihe, int spalte) const {
    return m_daten[reihe][spalte];
}

Matrix& Matrix::operator=(const Matrix& matrix) {
    if (this == &matrix) {
        return *this;
    }

    if (m_reihen != matrix.m_reihen || m_spalten != matrix.m_spalten) {
        for (int i = 0; i < m_reihen; ++i) {
            delete[] m_daten[i];
        }
        delete[] m_daten;

        m_reihen = matrix.m_reihen;
        m_spalten = matrix.m_spalten;

        m_daten = new double*[m_reihen];
        for (int i = 0; i < m_reihen; i++) {
            m_daten[i] = new double[m_spalten];
        }
    }

    for (int i = 0; i < m_reihen; ++i) {
        for (int j = 0; j < m_spalten; ++j) {
            m_daten[i][j] = matrix.m_daten[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& matrix) {
    for (int i = 0; i < m_reihen; ++i) {
        for (int j = 0; j < m_spalten; ++j) {
            m_daten[i][j] += matrix.m_daten[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-(const Matrix& matrix) {
    for (int i = 0; i < m_reihen; ++i) {
        for (int j = 0; j < m_spalten; ++j) {
            m_daten[i][j] -= matrix.m_daten[i][j];
        }
    }
    return *this;
}

void Matrix::matrixEingabe(Matrix &m) {
    for (int i = 0; i < m.GetReihen(); i++) {
        for (int j = 0; j < m.GetSpalten(); j++) {
            cout << "Bitte Wert an der Stelle: " << i << " " << j << " eingeben: ";
            int input;
            cin >> input;
            m.at(i,j) = input;           
        }
        cout << endl;
    }
}

void Matrix::printMatrix(Matrix m) const {
    for (int i = 0; i < m.GetReihen(); i++) {
        for (int j = 0; j < m.GetSpalten(); j++) {
            cout << m.at(i, j) << "\t";
        }
        cout << endl;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < m_reihen; ++i) {
        delete[] m_daten[i];
    }
    delete[] m_daten;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix temp(m1);
    return (temp += m2);
}
