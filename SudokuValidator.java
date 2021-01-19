
/*
 *       **** CheckSudokuSolution class ****
 *
 * # The problem is to check whether a given Sudoku solution is correct.
 */

/*
Enter a Sudoku puzzle solution:
9 6 3 1 7 4 2 5 8
1 7 8 3 2 5 6 4 9
2 5 4 6 8 9 7 3 1
8 2 1 4 3 7 5 9 6
4 9 6 8 5 2 3 1 7
7 3 5 9 6 1 8 2 4
5 8 9 7 1 3 4 6 2
3 1 7 2 4 6 9 8 5
6 4 2 5 9 8 1 7 3
Valid solution */


import java.util.Scanner;
class SudokuValidator{
	public static void main(String [] args){
		Scanner scan = new Scanner(System.in);
		int[][] sudoku = new int[9][9];
		System.out.println("Enter sudoku puzzle solution:");
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
			 	sudoku[i][j] = scan.nextInt();	
			}
		}

		System.out.println(isValid(sudoku)?"Valid solution":"Invalid solution");
	}
	static boolean isValid(int[][] sudoku){
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
				if(sudoku[i][j]<1 || sudoku[i][j]>9 || !isValid(i,j,sudoku) )return false;
			}
		}
		return true;		
	}
	static boolean isValid(int i,int j,int[][] sudoku){
		// Check whether grid[i][j] is unique in i's row
		for(int col=0;col<9;++col)
			if(col !=j && sudoku[i][col]==sudoku[i][j])
				return false;
		// Check whether grid[i][j] is unique in j's column
		for(int row=0;row<9;++row)
			if(row !=i && sudoku[row][j]==sudoku[i][j])
				return false;
		// Check whether grid[i][j] is unique in the 3-by-3 box
		int rows = (i/3) *3;
		int cols = (j/3) *3;
		for(int row = rows;row<rows+3;++row){
			for(int col = cols;col<cols+3;++col){
				if(row !=i && col != j && sudoku[i][j] == sudoku[row][col])
					return false;
			}
		}
		return true;
	}
}