import java.util.*;
import java.io.*;


class Count_Word_Char_line_inFile{
	public static void main(String []args){
		if(args.length==0){
			System.out.println("Usages: java Count_Word_Char_line_inFile filename");
			System.exit(1);
		}
		File file = new File(args[0]);
		if(!file.exists()){
			System.out.println("File dosen't exists!");
			System.exit(1);
		}
		if(file.length()==0){
			System.out.println("File is Empty");
			System.exit(1);
		}
		try{
			int Line = 0,Word = 0,Char = 0,withSpace=0;
			//int withtoken=0,withSimple=0;
			Scanner reader = new Scanner(file);
			while(reader.hasNext()){
				String line = reader.nextLine();
				Line +=1;
				Word += countWordsUsingSplit(line);
				int[] a = countWords(line);
				Char += a[1];
				//withSimple +=a[0];
				withSpace += line.length();
				//withtoken += countWordsUsingStringTokenizer(line);
			}
			System.out.println("Total Lines: "+Line);
			//System.out.println("Total Words With split: "+Word);
			System.out.println("Total Words: "+Word);
			System.out.println("Total Characters(Without line endings & Spaces) :"+Char);
			System.out.println("Total Characters(Without line endings & With Spaces) :"+withSpace);
			//System.out.println("Total Words With StringTokenizer: "+withtoken);
			//System.out.println("Total Words With simapleloop: "+withSimple);
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	static int countWordsUsingSplit(String line){
		if(line.isEmpty())return 0;
		String[] words = line.split("\\s+");
		return words.length;
	}
	static int countWordsUsingStringTokenizer(String line){
		if(line.isEmpty())return 0;
		StringTokenizer token = new StringTokenizer(line);
		return token.countTokens();
	}
	static int[] countWords(String lines){
		int[] a=new int[2];
		a[0]=0;a[1]=0;
		if(lines.isEmpty())return a;
		int state = 0,Char=0;
		int words = 0;
		
		char[] line = lines.toCharArray();
		for(int i=0;i<line.length;++i){
			if(line[i] == ' '){
				state = 0;
				Char+=1;
			}
			else if(state==0){
				state =1;
				words+=1;
			}
		}
		a[0] = words;
		a[1] = lines.length() - Char;
		return a;
	}
}