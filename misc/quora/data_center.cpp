/*
This is a brute force method which took 13 seconds to complete solution
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
 
using namespace std;

/* Global variables */
int w;		/* width */
int h;		/* height */
char* matrix;	/* the inputed matrix */
int sx, sy, tx, ty;	/* coordinate for start and terminate */
int roomcount;	/* room count */
int pathcount;  /* path count */
char* visited;	/* matrix to work on */
char* v;	/* matrix for use in flooding */
 
/* Coordinate short-hand */
#define C(x,y) ((x)+(y)*w)
#define D(x,y) ((x+1)+(y+1)*(w+2))
 
/*
 * Print the duct map
 *
 * @input solution A string of directions (E, W, S, N) of how the duct moving
 */
void printsolution(char* solution)
{
#ifdef DEBUG
	char* m;
	int i,j,k;
	m = (char*) malloc((2*w-1)*(2*h-1)*sizeof(char));
	memset(m, ' ', (2*w)*(2*h)*sizeof(char));
	for (j=0; j<h; j++) {
		for (i=0; i<w; i++) {
			m[2*i+4*j*w] = '0'+matrix[C(i,j)];
		};
	};
	i = sx;
	j = sy;
	for (k=0; k<=roomcount; k++) {
		switch (solution[k]) {
			case 'E': ++i; m[i+j*2*w]='-'; ++i; break;
			case 'W': --i; m[i+j*2*w]='-'; --i; break;
			case 'S': ++j; m[i+j*2*w]='|'; ++j; break;
			case 'N': --j; m[i+j*2*w]='|'; --j;
		};
	};
	for (j=0; j<2*h; j++) {
		for (i=0; i<2*w; i++) {
			printf("%c",m[i+j*2*w]);
		};
		printf("\n");
	};
#endif
};
 
/* Flood s at coordinate i,j */
int flood(char* visited, int i, int j)
{
	if (visited[D(i,j)] != 0) {
		return 0;
	};
	visited[D(i,j)] = 2;
	return 1 +
		flood(visited, i-1, j) +
		flood(visited, i+1, j) +
		flood(visited, i, j-1) +
		flood(visited, i, j+1);
};
 
/* Flooding to check if we have cut the floor plan into two disconnected sections */
int connected(char* visited, int x, int y, int visitedcount)
{
	int j;
	int last, flip;
       	last = visited[D(x,y-1)];
	flip = 0;
	if (visited[D(x+1,y-1)] != last) { flip++; last = 1-last; }
	if (visited[D(x+1,y  )] != last) { flip++; last = 1-last; }
	if (visited[D(x+1,y+1)] != last) { flip++; last = 1-last; }
	if (visited[D(x  ,y+1)] != last) { flip++; last = 1-last; }
	if (visited[D(x-1,y+1)] != last) { flip++; last = 1-last; }
	if (visited[D(x-1,y  )] != last) { flip++; last = 1-last; }
	if (visited[D(x-1,y-1)] != last) { flip++; last = 1-last; }
 
	if (flip <= 2) return 1;
 
	memcpy(v, visited, (w+2)*(h+2)*sizeof(char));
	j = flood(v, x-1, y);
	if (j==0) j = flood(v, x+1, y);
	if (j==0) j = flood(v, x, y-1);
	if (j==0) j = flood(v, x, y+1);
	return (j+visitedcount == roomcount+1);
};
 
/* Depth first search: Returns the total number of solutions */
void dfs(char* visited, int x, int y, int visitedcount, char* solution)
{
	char* v;
	int i,j;
	/* Check for boundary condition */
	if (x == tx && y == ty) {	/* pipe t */
		if (visitedcount == roomcount) {
			++pathcount;
			printsolution(solution);
		};
		return;
	};
	/* I am now in a new position. Update data structures */
	++visitedcount;
	visited[D(x,y)] = 1;
 
	/* Look into the next step if we still possible to find a solution */
	if (connected(visited, x, y, visitedcount)) {
		/* Try go east */
		if (visited[D(x+1, y)] == 0) {
			solution[visitedcount] = 'E';
			dfs(visited, x+1, y, visitedcount, solution);
		};
		/* Try go west */
		if (visited[D(x-1, y)] == 0) {
			solution[visitedcount] = 'W';
			dfs(visited, x-1, y, visitedcount, solution);
		};
		/* Try go south */
		if (visited[D(x, y+1)] == 0) {
			solution[visitedcount] = 'S';
			dfs(visited, x, y+1, visitedcount, solution);
		};
		/* Try go north */
		if (visited[D(x, y-1)] == 0) {
			solution[visitedcount] = 'N';
			dfs(visited, x, y-1, visitedcount, solution);
		};
	};
	visited[D(x,y)] = 0;
	return;
};
 
int main(int argc, char** argv)
{

	clock_t start,end;
	start = clock();
	int i,j,k;
	char* solution;
 
	/* Collect input */
	scanf("%d %d",&w,&h);
	matrix = (char*)malloc(h*w*sizeof(char));
	visited = (char*)malloc((h+2)*(w+2)*sizeof(char));
	v = (char*)malloc((h+2)*(w+2)*sizeof(char));
	memset(visited, 0, (h+2)*(w+2)*sizeof(char));
	for (i=-1; i<w+1; i++) {	/* Setup sentenials */
		visited[D(i,-1)] = 1;
		visited[D(i,h)] = 1;
	};
	for (i=-1; i<h+1; i++) {
		visited[D(-1,i)] = 1;
		visited[D(w,i)] = 1;
	};
	roomcount = 0;
	for (j=0; j<h; j++) {
		for (i=0; i<w; i++) {
			scanf("%d",&k);
			matrix[C(i,j)] = k;
			switch (k) {
				case 0: roomcount++;
					break;
				case 1: visited[D(i,j)] = 1;
					break;
				case 2: sx = i;
					sy = j;
					break;
				case 3: tx = i;
					ty = j;
			};
		};
	};
 
	/* Depth-first search */
	solution = (char*)malloc((roomcount+1)*sizeof(char));
	pathcount = 0;
	dfs(visited, sx, sy, -1, solution);
 
	/* Output */
	printf("Number of solutions: %d\n",pathcount);
	end = clock() - start;
	cout<<end<<endl;
	printf("%.6f\n",(double(end)/CLOCKS_PER_SEC));
	return 0;
};
