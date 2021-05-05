import java.util.Scanner;
import java.io.*;
class Remove_Replace_text{
	public static void main(String []args){
		if(args.length < 2){
			System.out.println("Usage: java Remove_Replace_text FileName OldStr NewStr");
			System.out.println("                      or                    ");
			System.out.println("Usage: java Remove_Replace_text FileName RemoveStr");
			System.exit(1);
		}
		File file = new File(args[0]);
		System.out.println(args[0]);
		if(!file.exists()){
			System.out.println("Source file "+args[0]+" does not exist");
			System.exit(2);
		}
		try{
			StringBuilder builder = new StringBuilder();
			Scanner scan = new Scanner(file);
			while(scan.hasNext()){
				String line = scan.nextLine();
				line+="\r\n";
				builder.append(line);
			}
			String builder_string = builder.toString();
			if(args.length==2)builder_string=builder_string.replaceAll(args[1],"");
			else	builder_string=builder_string.replaceAll(args[1],args[2]);
			scan.close();
			String File_name = file.getName();
			File write_file = new File(File_name);
			PrintWriter writer = new PrintWriter(write_file);
			writer.print(builder_string);
			writer.close(); 
		if(args.length==2)System.out.println("All occurance of "+args[1]+" Removed.");
		else System.out.println("All occurance of "+args[1]+" Replace with "+args[2]);
		}catch(Exception e){e.printStackTrace();}
	}
}