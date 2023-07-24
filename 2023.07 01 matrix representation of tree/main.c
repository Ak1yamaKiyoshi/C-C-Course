#include <stdio.h>
#include <malloc.h>
#include <string.h>


char **createMatrix(int amountOfNodes) {
	char **matrix = (char**)calloc(sizeof(char*), amountOfNodes);
	for (int i = 0; i < amountOfNodes; i++)
		matrix[i] = (char*)calloc(sizeof(char), amountOfNodes);
	return matrix;
}

void printMatrix(char**matrix, int size, char*message) {
	printf("\n %s: \n", message);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++ ) 
			printf(" %d", matrix[i][j]);
		printf("\n");
	}
}

char** setZero (char **matrix, int size) {
	for (int i = 0; i < size; i++) 
		memset(matrix[i], 0, size*sizeof(char));
	return matrix;
}

char **setTreeMatrix(char**matrix, char loop, int matrixVar) {
	if (matrixVar == 0) {
		matrix[0][1] = 1;
		matrix[1][0] = 1;
		matrix[0][2] = 1;
		matrix[2][0] = 1;
		matrix[2][3] = 1;
		matrix[3][2] = 1;
	} else if (matrixVar == 1) {
		matrix[0][1] = 1;
		matrix[1][0] = 1;
		matrix[1][2] = 1;
		matrix[2][1] = 1;
		matrix[2][3] = 1;
		matrix[3][2] = 1;
	} else if (matrixVar == 2) {
		matrix[0][1] = 1;
		matrix[1][0] = 1;
		matrix[0][2] = 1;
		matrix[2][0] = 1;
		matrix[1][3] = 1;
		matrix[3][1] = 1;
	}
	
	// create loop
	if (loop == 1 && matrixVar == 0) {
		matrix[1][3] = 1;
		matrix[3][1] = 1;
	} else if (loop == 2 && matrixVar == 0) {
		matrix[0][3] = 1;
		matrix[3][0] = 1;
	} else if (matrixVar == 1 && loop == 1) {
		matrix[3][0] = 1;
		matrix[0][3] = 1;
	}
	
	return matrix;
}

int height(char**matrix, int size, int cur, int prev, int depth, int maxdepth) {
	printf("\nheight:  <cur:%d prev:%d depth:%d >  ", cur, prev, depth);
	int origindepth = depth;
	int tempdepth = depth;
	for (int i = 0; i < size; i++) {
		if (matrix[cur][i] != 0 && i != prev) {
			if ( depth >= maxdepth ) return -1;
			tempdepth = height(matrix, size, i, cur, origindepth+1, maxdepth);	
			
			depth = (tempdepth == -1) 
			? -1 
			: (tempdepth > depth) 
			? tempdepth 
			: depth;
		} 
	}
	
	return depth;
}


int main() {
	int nodes = 4;
	char **matrix = createMatrix(4);
	printMatrix(matrix, nodes, "empty matrix");
	printMatrix(setTreeMatrix(matrix, 2, 0), nodes, "set matrix");
	//printMatrix(setZero(matrix, nodes), nodes, "empty matrix");
	printf("\nheight: %d", 
		height(matrix, nodes, 0, 0, 0, nodes)
	);

	return 0;
}
