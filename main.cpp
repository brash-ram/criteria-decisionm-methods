#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<long>>& M) {//выводит матрицу
	for (int i=0; i<M.size(); i++) {
		for (int j=0; j<M[0].size(); j++) {
			cout << M[i][j] << "\t";
		}
        cout << endl;
	}

	cout << '\n';
}

vector<vector<long>> enterMatrix(int numberParams) {//вводим матрицу
	vector<vector<long>> matrix(numberParams, vector<long>(numberParams));//инициалзируем матрицу через вектора
	string number;
	for (int i=0; i<numberParams; i++) {
		for (int j=0; j<numberParams; j++) {
			cin >> matrix[i][j];
		}
	}
	return matrix;
}

vector<vector<long>> createMatrixRisk(const vector<vector<long>>& matrix) {//считаем матрицу рисков
    int size = matrix.size();
    vector<vector<long>> newMatrix(size, vector<long>(size));
    for (int i=0; i<size; i++) {
        newMatrix[i][i] = matrix[i][i];
		for (int j=0; j<size; j++) {
			newMatrix[j][i] = matrix[i][i] - matrix[j][i];//вычитаем из всех элементов в столбце элемент на диагонали в этом столбце
		}
	}
    return newMatrix;
}

vector<int> getSolutions(const vector<vector<long>>& matrix) {
    vector<int> solutions;
    vector<long> maximums;
    for (int i=0; i<matrix.size(); i++) {
        maximums.push_back(*max_element(matrix[i].begin(), matrix[i].end()));//находим максимум в каждой строке
    }
    long min = *min_element(maximums.begin(), maximums.end());//находим минимальный элемент
    for (int i=0; i<maximums.size(); i++) {
        if (maximums[i] == min) {//находим альтернативы (строки) которым он соответствует
            solutions.push_back(i+1);//результаты выбора альтернатив
        }
    }
    return solutions;
}

int main() {
	cout << "Введите колчество альтернатив" << endl;
	int numberA; cin >> numberA;

    cout << "Введите матрицу альтернатив" << endl;
    vector<vector<long>> matrixAlternatives = enterMatrix(numberA);

    cout << "Матрица альтернатив:" << endl;
    printMatrix(matrixAlternatives);

    vector<vector<long>> matrixRisks = createMatrixRisk(matrixAlternatives);

    cout << "Матрица рисков" << endl;
    printMatrix(matrixRisks);

    vector<int> solutions = getSolutions(matrixRisks);
    for (int i=0; i<solutions.size(); i++) {
        cout << "Выбранная альтернатива - " << solutions[i] << endl;
    }


    return 0;
}