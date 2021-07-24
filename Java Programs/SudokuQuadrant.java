import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;

class Multi{
    int i;
    int j;
    Multi(int i,int j){
        this.i = i;
        this.j = j;
    }
    
}

class SudokuQuadrant{
	public static void main(String [] args) throws Exception{
		Scanner scan = new Scanner(System.in);
	
		//System.out.println("Enter sudoku puzzle solution:");
		//String[] sudoku = {"(1,2,3,4,5,6,7,8,1)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"};
        //String[] sudoku = {"(1,1,3,4,5,6,7,8,9)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,9)"};
        String[] sudoku = {"(1,2,3,4,5,6,7,8,9)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"};
        for(int i=0;i<9;++i){
            sudoku[i] = sudoku[i].replaceAll("[,()]","");
            //System.out.println(sudoku[i]);
        }
        // to store index of wrong number present in 9-by-9 grid
        ArrayList<Multi> list = new ArrayList<>();
        // to count Quadrant from indexes
        HashSet<Integer> set = new HashSet<>();
        // find indexes of wrong inputs
        isValid(sudoku,list);
        
        int n = list.size();
        //System.out.println("Size of list: "+n);
        // if n==0 than sudoku has no errors
        if(n==0)System.out.println("It's valid sudoku");
        else{
            for(int i=0;i<n;++i){
                int l = list.get(i).i;
                int m = list.get(i).j;
                //System.out.println("i:"+l+" j:"+m);
                // EX. l=3,i=0
                l=(l/3) * 3;  // l = 3
                m=m/3 + 1;    // m = 1
                set.add(l+m); // than Quadrant Four has Error            
            }
            Iterator it = set.iterator();
            System.out.println("Quadrant that contains Error: ");
            while(it.hasNext()){
                System.out.println(it.next());
            }
        }
        
	}
	static void isValid(String[] sudoku,ArrayList<Multi> list){
	    // check every cell in 9X9 sudoku
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
			    if(sudoku[i].charAt(j)=='x')continue;
			    isValid(i,j,sudoku,list);
			}
		}
	}
	static void isValid(int i,int j,String[] sudoku,ArrayList<Multi> list){
		// Check whether grid[i][j] is unique in i's row
		for(int col=0;col<9;++col)
			if(col !=j && sudoku[i].charAt(col)==sudoku[i].charAt(j))
				list.add(new Multi(i,col));
		// Check whether grid[i][j] is unique in j's column
		for(int row=0;row<9;++row)
			if(row !=i && sudoku[row].charAt(j)!='x' && sudoku[row].charAt(j)==sudoku[i].charAt(j))
				list.add(new Multi(row,j));
		// Check whether grid[i][j] is unique in the 3-by-3 box
		int rows = (i/3) *3;
		int cols = (j/3) *3;
		for(int row = rows;row<rows+3;++row){
			for(int col = cols;col<cols+3;++col){
				if(row !=i && col != j && sudoku[i].charAt(j)!='x' && sudoku[i].charAt(j) == sudoku[row].charAt(col))
				    list.add(new Multi(row,col));
			}
		}
	}
}