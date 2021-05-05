import java.util.*;
import java.io.*;

class Practice_derectory{
	public static void main(String []args) throws Exception{
		File file = new File("F:\\work of pro\\SEM6\\AJ\\hibernate-release-5.4.30.Final\\lib\\required");

		System.out.println("Is this file? "+file.isDirectory());
		System.out.println("Canonical Path: "+file.getCanonicalPath());
		System.out.println("Absolute Path: "+file.getAbsolutePath());
		System.out.println("Parent: "+file.getParent());
		File[] list_of_file = file.listFiles();
		for(int i=0;i<list_of_file.length;++i)
			System.out.print(list_of_file[i].getAbsolutePath()+"\\"+list_of_file[i].getName()+";");

		
	}
}