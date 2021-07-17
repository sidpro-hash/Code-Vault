/*
 *
 * @author SidPro
 * @version 1.0
 *
 */

import java.io.*;

class Testextension{
	public static void main(String[] args) throws IOException{
		File file = new File("yolov3-tiny.cfg");
		/*FileOutputStream out = new FileOutputStream(file);
		
		for(int i=0;i<10;++i)out.write(i);
		out.close();
		*/
		DataInputStream in = new DataInputStream(new FileInputStream(file));
		for(int i=0;i<10;++i){
			System.out.println(in.readLine());
		}
		/*int value;
		while((value=in.read())!=-1){
			System.out.print(value+" ");
		}*/
		String sp = "Sid";
		FindAllPermutation("",sp);
		in.close();
	}
	
	public static void FindAllPermutation(String S1,String S2){
		if(S2.length() == 0){
			System.out.print(S1+" ");
			return;
		}
		for(int i=0;i<S2.length();++i){
			char ch = S2.charAt(i);
			String tep = S2.substring(0,i)+S2.substring(i+1);
			FindAllPermutation(S1+ch,tep);
		}
	}
}